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
		"__kernel void vectorAdd(__global const int* a, __global const int* b, __global int* c, __global const int* countOfElements) {	\n"\
			"// get index of each work item																				\n"\
			"int globalIndex = get_global_id(0);/*																		\n"\
			"// bound check (equivalent to the limit on a 'for' loop for standard/serial C code							\n"\
			"if (globalIndex >= countOfElements[0]) {																		\n"\
				"return;																								\n"\
			"}*/																											\n"\
			"// add the vector elements																					\n"\
			"c[globalIndex] = a[globalIndex] + b[globalIndex];															\n"\
			"return;																									\n"\
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
		cl::Buffer bufA(context, CL_MEM_READ_ONLY, io::arraySize * sizeof(int));
		cl::Buffer bufB(context, CL_MEM_READ_ONLY, io::arraySize * sizeof(int));
		cl::Buffer bufC(context, CL_MEM_WRITE_ONLY, io::arraySize * sizeof(int));
		cl::Buffer bufCount(context, CL_MEM_READ_ONLY, sizeof(int));

		//write arrays to OpenCL memory
		int blocking = CL_TRUE;
		int offset = 0;
		//int arrSize = io::arraySize;
		computeQueue.enqueueWriteBuffer(bufA, blocking, offset, io::arraySize * sizeof(int), a);
		computeQueue.enqueueWriteBuffer(bufB, blocking, offset, io::arraySize * sizeof(int), b);
		computeQueue.enqueueWriteBuffer(bufCount, blocking, offset, sizeof(int), &io::arraySize);

		//prepare kernel
		kernel.setArg(0, bufA);
		kernel.setArg(1, bufB);
		kernel.setArg(2, bufC);
		//kernel.setArg(3, bufCount);

		//enqueue the kernel for execution
		//cl::NDRange ndOffset = cl::NullRange;
		std::size_t ndOffset = NULL;
		std::size_t workGlobalSize = io::arraySize;
		std::size_t localDimension = 10;
		//gpu.getInfo(CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS, &localDimension);

		std::chrono::steady_clock::time_point beginExecution = std::chrono::high_resolution_clock::now();
		//computeQueue.enqueueNDRangeKernel(kernel, ndOffset, workGlobalSize, localDimension);
		computeQueue.enqueueTask(kernel);
		//synchronization point for completion of execution
		//computeQueue.flush();
		computeQueue.finish();
		std::chrono::steady_clock::time_point endExecution = std::chrono::high_resolution_clock::now();

		std::cout << "GPU ";
		double timeTaken = io::getComputeTime(beginExecution, endExecution);

		//read the results from OpenCL device to RAM
		computeQueue.enqueueReadBuffer(bufC, blocking, offset, io::arraySize, c);

		

		return timeTaken;
	}
}