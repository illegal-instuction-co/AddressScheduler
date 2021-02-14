#include <iostream>
#include <windows.h>
#include "AddressScheduler.hpp"

int main() {

	std::cout << "Address Scheduler Test" << std::endl;


	// Create a scheluder 
	auto scheduler = new AddressScheduler;


	// Add an address
	scheduler->AddPointer("KERNELBASE", (uint64_t)GetModuleHandleA("KERNELBASE.dll"));


	// Change address 
	bool result = scheduler->ChangePointer("KERNELBASE", 0xDEADBEEF);


	// Print change process result 
	result ? std::cout << "Address changed" << std::endl : std::cout << "Address couldnt change" << std::endl;


	// Get address 
	uint64_t KernelBase = scheduler->GetPointer("KERNELBASE");


	// Print address 
	std::cout << "KernelBase addr : " << std::endl;
	std::cout << std::hex << KernelBase << std::endl;


	// Get scheduler base 
	// AddressScheduler * schedulerG = scheduler->GetBase();


	// Add an address
	scheduler->AddPointer("kernel32", (uint64_t)GetModuleHandleA("kernel32"));


	// Print address 
	std::cout << "Kernel32 addr : " << std::endl;
	std::cout << std::hex << scheduler->GetPointer("kernel32") << std::endl;

	return 0; 
}