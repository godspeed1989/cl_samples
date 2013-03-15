#include "simpleCL.h"

int main()
{
	char buf[] = "Hello, 12345!";
	size_t global_size[2], local_size[2];
	int n_found, found;
	const int worksize = sizeof(buf);
	sclHard* all_hardwares;
	sclHard hardware;
	sclSoft software;
	
	// Target buffer just so we show we got the data from OpenCL
	char buf2[worksize];
	buf2[0] = '?';
	buf2[worksize-1] = 0;
	
	// print all of availiable hardware information
	printf("****Print all the hardwares\n");
	all_hardwares = sclGetAllHardware(&n_found);
	sclPrintDeviceNamePlatforms(all_hardwares, n_found);
	
	printf("****Get the hardware\n"); // CPU or GPU
	hardware = sclGetCPUHardware( 0, &found );
	if(!found)
		return -1;
	printf("****Get the software\n");
	software = sclGetCLSoftware( "example.cl", "example", hardware );
	printf("****Set NDRange dimensions\n");
	global_size[0] = worksize;
	global_size[1] = 1;
	local_size[0] = global_size[0];
	local_size[1] = 1;
	printf("****Start to run progam\n");
	sclManageArgsLaunchKernel( hardware, software, global_size, local_size, 
							" %r %w ", worksize, buf, worksize, buf2 );
	printf("****Output results\n");
	puts(buf2);
	printf("****Release software\n");
	sclReleaseClSoft(software);
	printf("****Release hardware\n");
	sclReleaseClHard(hardware);
	sclRetainAllHardware(all_hardwares, n_found);
	return 0;
}

