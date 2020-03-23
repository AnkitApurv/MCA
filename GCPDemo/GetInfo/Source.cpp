#include <CL/cl.hpp>
#include <iostream>

int main(void) {
	std::vector<cl::Platform> allPlatforms;
	cl::Platform::get(&allPlatforms);
	if (allPlatforms.size() == 0) {
		std::cout << " No platforms found.\n";
		exit(1);
	}
	
	//https://stackoverflow.com/questions/10036248/opencl-simple-vector-addition-but-wrong-output-for-large-input
	for (std::size_t j = 0; j < allPlatforms.size(); j++) {
		std::cout << "\nOpenCL Platform :\n\t Platform : " << allPlatforms[j].getInfo<CL_PLATFORM_NAME>() << std::endl;
		std::cout << "\t Vendor: " << allPlatforms[j].getInfo<CL_PLATFORM_VENDOR>() << std::endl;
		std::cout << "\t Version : " << allPlatforms[j].getInfo<CL_PLATFORM_VERSION>() << std::endl;
		//std::cout << "\t Extensions : " << allPlatforms[j].getInfo<CL_PLATFORM_EXTENSIONS>() << std::endl;

		cl::Platform defaultPlatform = allPlatforms[j];
		std::vector<cl::Device> allGPUs;
		defaultPlatform.getDevices(CL_DEVICE_TYPE_ALL, &allGPUs);
		if (allGPUs.size() == 0) {
			std::cout << " No GPUs found.\n";
			break;
		}
		cl::Device gpu = allGPUs[0];
		for (std::size_t i = 0; i < allGPUs.size(); i++) {
			std::cout << "\t OpenCL Device :\n\t\t Device : " << allGPUs[i].getInfo<CL_DEVICE_NAME>() << std::endl;
			std::cout << "\t\t Type : " << allGPUs[i].getInfo<CL_DEVICE_TYPE>() << std::endl;
			std::cout << "\t\t Vendor : " << allGPUs[i].getInfo<CL_DEVICE_VENDOR>() << std::endl;
			std::cout << "\t\t Driver : " << allGPUs[i].getInfo<CL_DRIVER_VERSION>() << std::endl;
			std::cout << "\t\t Global Mem : " << allGPUs[i].getInfo<CL_DEVICE_GLOBAL_MEM_SIZE>() / (1024 * 1024) << " MBytes" << std::endl;
			std::cout << "\t\t Local Mem : " << allGPUs[i].getInfo<CL_DEVICE_LOCAL_MEM_SIZE>() / 1024 << " KBbytes" << std::endl;
			std::cout << "\t\t Compute Unit : " << allGPUs[i].getInfo<CL_DEVICE_MAX_COMPUTE_UNITS>() << std::endl;
			std::cout << "\t\t Clock Rate : " << allGPUs[i].getInfo<CL_DEVICE_MAX_CLOCK_FREQUENCY>() << " MHz" << std::endl;
		}
	}
	std::cout << "\n\nFinished, Press any key to continue......";
	char k;
	std::cin >> k;
	return 0;
}