#include <CL/cl.hpp>	//OpenCl
#include <iostream>
#include <chrono>
#include "gpu.h"
#include "io.h"

using namespace cl;
//https://www.olcf.ornl.gov/tutorials/opencl-vector-addition/
//https://github.com/Dakkers/OpenCL-examples
namespace compute {
	double gpuCompute(int a[], int b[], int c[]) {
		std::string kernelCode =
			"__kernel void vectorAdd(__constant int* a, __constant int* b, __global int* c, __constant int* countOfElements) {	\n"\
			"	//get index of each work item																				\n"\
			"	int globalIndex = get_global_id(0);																			\n"\
			"	//bound check (equivalent to the limit on a 'for' loop for standard/serial C code, not needed				\n"\
			"	if(globalIndex >= *countOfElements) {																		\n"\
			"		return;																									\n"\
			"	}																											\n"\
			"	//add the vector elements																					\n"\
			"	//c[globalIndex] = a[globalIndex] % b[globalIndex];															\n"\
			"	c[globalIndex] = a[globalIndex] * b[globalIndex];															\n"\
			"	c[globalIndex] = a[globalIndex] + b[globalIndex];															\n"\
			"	c[globalIndex] = a[globalIndex] - b[globalIndex];															\n"\
			"	return;																										\n"\
			"}";

		//select a platform, i.e. a vendor
		std::vector<cl::Platform> allPlatforms;
		cl::Platform::get(&allPlatforms);
		if (allPlatforms.size() == 0) {
			std::cout << " No platforms found.\n";
			exit(1);
		}
		cl::Platform defaultPlatform = allPlatforms[0];

		//select a device, a platform may have multiple
		std::vector<cl::Device> allGPUs;
		defaultPlatform.getDevices(CL_DEVICE_TYPE_GPU, &allGPUs);
		if (allGPUs.size() == 0) {
			std::cout << " No GPUs found.\n";
			exit(1);
		}
		//prepare devic with it's context and program which will execute on it
		cl::Device gpu = allGPUs[0];
		cl::Context context(gpu);
		cl::Program::Sources source;
		//write kernel to OpenCL program
		source.push_back({ kernelCode.c_str(), kernelCode.length() });

		cl::Program program(context, source);
		if (program.build({ gpu }) != CL_SUCCESS) {
			std::cout << "Error building: " << program.getBuildInfo<CL_PROGRAM_BUILD_LOG>(gpu) << std::endl;
			exit(1);
		}

		cl::CommandQueue computeQueue(context, gpu);
		cl::Kernel kernel = cl::Kernel(program, "vectorAdd");

		//allocate space in OpenCL compute environment
		cl::Buffer bufA(context, CL_MEM_READ_ONLY, io::arraySize * sizeof(cl_int));
		cl::Buffer bufB(context, CL_MEM_READ_ONLY, io::arraySize * sizeof(cl_int));
		cl::Buffer bufC(context, CL_MEM_WRITE_ONLY, io::arraySize * sizeof(cl_int));
		cl::Buffer bufCount(context, CL_MEM_READ_ONLY, sizeof(cl_int));

		//write arrays to OpenCL memory
		cl_bool blockingTrue = CL_TRUE;
		std::size_t offsetNone = 0;
		//int arrSize = io::arraySize;
		computeQueue.enqueueWriteBuffer(bufA, blockingTrue, offsetNone, io::arraySize * sizeof(cl_int), a);
		computeQueue.enqueueWriteBuffer(bufB, blockingTrue, offsetNone, io::arraySize * sizeof(cl_int), b);
		computeQueue.enqueueWriteBuffer(bufCount, blockingTrue, offsetNone, sizeof(cl_int), &io::arraySize);
		computeQueue.finish(); //ensure writes are finished

		//prepare kernel
		kernel.setArg(0, bufA);
		kernel.setArg(1, bufB);
		kernel.setArg(2, bufC);
		kernel.setArg(3, bufCount);

		//enqueue the kernel for execution
		cl::NDRange workOffset = cl::NullRange;
		cl::NDRange globalWorkSize = io::arraySize;
		cl::NDRange localWorkGroupSize = io::workGroupSize;

		std::chrono::steady_clock::time_point beginExecution = std::chrono::high_resolution_clock::now();
		computeQueue.enqueueNDRangeKernel(kernel, workOffset, globalWorkSize, localWorkGroupSize);
		//computeQueue.enqueueTask(kernel); //deprecated, simpler version of enqueueNDRangeKernel()
		//synchronization point for completion of execution, finish();
		computeQueue.finish();
		std::chrono::steady_clock::time_point endExecution = std::chrono::high_resolution_clock::now();

		std::cout << "GPU ";
		double timeTaken = io::getComputeTime(beginExecution, endExecution);

		//read the results from OpenCL device to RAM
		computeQueue.enqueueReadBuffer(bufC, blockingTrue, offsetNone, io::arraySize * sizeof(cl_int), c);
		computeQueue.finish(); //ensure read is finished

		return timeTaken;
	}
}