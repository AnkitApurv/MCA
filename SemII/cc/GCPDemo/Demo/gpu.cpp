#include <CL/cl.hpp>	//OpenCl
#include <iostream>		//cin, cout
#include <chrono>		//std::chrono::steady_clock::time_point
#include "gpu.h"		//impl
#include "io.h"			//getComputeTime()

using namespace cl;
//https://www.olcf.ornl.gov/tutorials/opencl-vector-addition/
//https://github.com/Dakkers/OpenCL-examples
namespace compute {
	double gpuCompute(int a[], int b[], int c[]) {
		std::string kernelCode =
			"__kernel void vectorAdd(__constant int* a, __constant int* b, __global int* c, __constant int* countOfElements) {	\n"\
			"	//get index of each work item, int get_global_id(int nthDimension);																				\n"\
			"	int globalIndex = get_global_id(0);																			\n"\
			"	//bound check (equivalent to the limit on a 'for' loop for standard/serial C code), not needed				\n"\
			"	if(globalIndex >= *countOfElements) {																		\n"\
			"		return;																									\n"\
			"	}																											\n"\
			"	//add the vector elements																					\n"\
			"	c[globalIndex] = a[globalIndex] * b[globalIndex];															\n"\
			"	c[globalIndex] += a[globalIndex] + b[globalIndex];															\n"\
			"	c[globalIndex] += a[globalIndex] - b[globalIndex];															\n"\
			"	//c[globalIndex] = c[globalIndex] % b[globalIndex];															\n"\
			"	return;																										\n"\
			"}";

		//select a platform, i.e. a vendor
		std::vector<cl::Platform> allPlatforms;
		cl::Platform::get(&allPlatforms);
		if (allPlatforms.size() == 0) {
			std::cout << " No platforms found.\n";
			exit(1);
		}
		//first platform of the system
		cl::Platform defaultPlatform = allPlatforms[0];

		//select a device, a platform may have multiple
		std::vector<cl::Device> allGPUs;
		defaultPlatform.getDevices(CL_DEVICE_TYPE_GPU, &allGPUs);
		if (allGPUs.size() == 0) {
			std::cout << " No GPUs found.\n";
			exit(1);
		}
		//first device of the selected platform
		cl::Device gpu = allGPUs[0];
		//https://stackoverflow.com/questions/38587810/what-do-opencl-contexts-mean-why-do-they-make-sense
		//Context allows handling multiple devices, constructor(vector<device>);
		cl::Context context(gpu);
		cl::Program::Sources source;
		//write kernel to OpenCL program, Program::Sources::push_back( vector<pair<charArray, charArray.length>> );
		//where charArray points to the string which is kernel source
		source.push_back({ kernelCode.c_str(), kernelCode.length() });

		//Program represents compile/d binary
		cl::Program program(context, source);
		//Program.build(vector<device>) builds the source on all devices in the vector
		if (program.build({ gpu }) != CL_SUCCESS) {
			std::cout << "Error building: " << program.getBuildInfo<CL_PROGRAM_BUILD_LOG>(gpu) << std::endl;
			exit(1);
		}

		//allows queueing up the tasks on the selected devices for the given context
		cl::CommandQueue computeQueue(context, gpu);
		//OpenCL function
		cl::Kernel kernel = cl::Kernel(program, "vectorAdd");

		//allocate space in OpenCL compute environment
		cl::Buffer bufA(context, CL_MEM_READ_ONLY, io::arraySize * sizeof(cl_int));
		cl::Buffer bufB(context, CL_MEM_READ_ONLY, io::arraySize * sizeof(cl_int));
		cl::Buffer bufC(context, CL_MEM_WRITE_ONLY, io::arraySize * sizeof(cl_int));
		cl::Buffer bufCount(context, CL_MEM_READ_ONLY, sizeof(cl_int));

		//should the function be synchronous?
		cl_bool blockingTrue = CL_TRUE;
		//skip some initial bytes from the memory?
		std::size_t offsetNone = 0;
		//write arrays to OpenCL memory
		computeQueue.enqueueWriteBuffer(bufA, blockingTrue, offsetNone, io::arraySize * sizeof(cl_int), a);
		computeQueue.enqueueWriteBuffer(bufB, blockingTrue, offsetNone, io::arraySize * sizeof(cl_int), b);
		computeQueue.enqueueWriteBuffer(bufCount, blockingTrue, offsetNone, sizeof(cl_int), &io::arraySize);

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
		//computeQueue.enqueueTask(kernel); //deprecated, simpler, one dimensional version of enqueueNDRangeKernel()
		//synchronization point for completion of execution, finish();
		computeQueue.finish();
		std::chrono::steady_clock::time_point endExecution = std::chrono::high_resolution_clock::now();

		double timeTaken = io::getComputeTime(beginExecution, endExecution);

		//read the results from OpenCL device to RAM
		computeQueue.enqueueReadBuffer(bufC, blockingTrue, offsetNone, io::arraySize * sizeof(cl_int), c);

		return timeTaken;
	}
}