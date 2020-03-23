#include "source.h"

int main(void) {
	cl_device_type dType = CL_DEVICE_TYPE_ALL;
	OpenCLHelpers::getAllDevices(dType);
	return 0;
}