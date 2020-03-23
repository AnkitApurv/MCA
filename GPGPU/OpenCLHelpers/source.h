#pragma once

// 4 is highest level, 1 is lowst level
#pragma warning(push, 1)
#include <vector>
#ifdef __APPLE__
#include <OpenCL/cl.hpp>
#else
#include <CL/cl.hpp>
#endif
#pragma warning(pop)

namespace OpenCLHelpers {

	enum class RequirementType {
		ComputeHeavy,
		MemoryHeavy
	};

	///<summary>queries, filters and return as vector of opencl devices</summary>
	///<param name="rType">enum class to represent requirement</param>
	///<param name="dType">opencl device type required</param>
	///<param name="countOfDevice">count of devices required</param>
	///<returns>vector of opencl devices, guaranteed to be of one platform</returns>
	std::vector<cl::Device> getDevices(const RequirementType rType, const cl_device_type dType, const uint16_t countOfDevices);

	///<summary>queries and returns all opencl devices of specified type</summary>
	///<param name="dType">opencl device type required</param>
	///<param name="allDevices">2D vector of opencl Device objects, NOTE: intented return variable</param>
	///<returns>2D vector of opencl Device objects, each array of devices belog to each separate platform</returns>
	std::vector<std::vector<cl::Device>> getAllDevices(const cl_device_type dType);
}