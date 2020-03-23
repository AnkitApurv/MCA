#include "source.h"

namespace OpenCLHelpers {

	std::vector<std::vector<cl::Device>> getAllDevices(const cl_device_type dType) {
		//get all platforms
		std::vector<cl::Platform> allPlatforms;
		cl::Platform::get(&allPlatforms);

		//get all devices
		std::vector<std::vector<cl::Device>> allDevices;
		std::vector<cl::Device> tempDeviceList;
		for (cl::Platform p : allPlatforms) {
			p.getDevices(dType, &tempDeviceList);
			tempDeviceList.shrink_to_fit();
			allDevices.push_back(tempDeviceList);
		}
		allDevices.shrink_to_fit();
		return allDevices;
	}

	void createMetrics(const RequirementType rType, std::vector<std::vector<cl::Device>>& allDevices, std::vector<std::vector<int>>& metrics) {
		(void)metrics; //temporary mitigation for CS4100 warning till implementation is complete
		//create metric based on requirement
		for (std::vector<cl::Device> deviceListByPlatform : allDevices) {
			for (cl::Device d : deviceListByPlatform) {
				switch (rType) {
				case RequirementType::ComputeHeavy:
					//metrics.push_back(d.getInfo<CL_DEVICE_MAX_COMPUTE_UNITS>() * d.getInfo<CL_DEVICE_MAX_CLOCK_FREQUENCY>());
					break;
				case RequirementType::MemoryHeavy:
					//metrics.push_back(d.getInfo<CL_DEVICE_MAX_MEM_ALLOC_SIZE>());
					break;
				}
			}
		}
	}

	void filterDevicesByMetrics(std::vector<std::vector<cl::Device>>& allDevices, std::vector<std::vector<int>> metrics, const uint16_t countOfDevices, std::vector<cl::Device>& filteredDevices) {
		(void)countOfDevices; //temporary mitigation for CS4100 warning till implementation is complete
		//sort by metrics, highest to lowest

		//select device with most favourable metric
		for (std::vector<cl::Device> deviceListByPlatform : allDevices) {
			for (cl::Device d : deviceListByPlatform) {
				filteredDevices.push_back(d);
			}
		}
		return;
	}

	std::vector<cl::Device> getDevices(const RequirementType rType, const cl_device_type dType, const uint16_t countOfDevices)
	{
		std::vector<std::vector<cl::Device>> allDevices = getAllDevices(dType);

		std::vector<std::vector<int>> metrics;
		createMetrics(rType, allDevices, metrics);

		std::vector<cl::Device> filteredDevices;

		filterDevicesByMetrics(allDevices, metrics, countOfDevices, filteredDevices);

		return filteredDevices;
	}
}