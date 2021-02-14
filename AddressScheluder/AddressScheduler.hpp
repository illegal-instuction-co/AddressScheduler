#ifndef __ADDRESS_SCHEDULER_H__
#define __ADDRESS_SCHEDULER_H__

#include <iostream>
#include <vector>
#include <string>
#include <map>

class AddressScheduler {

	public:

	// static AddressScheduler g_Base;

	// Pointers 
	std::map<std::string, uint64_t> pointers;

	void AddPointer(const char* name, uint64_t addr) {
		pointers.insert(std::pair<std::string, uint64_t>(name, addr));
	}

	uint64_t GetPointer(const char* name) {
		return pointers[name];
	}

	bool ChangePointer(const char* name, uint64_t addr) {
		try {
			pointers.at(name) = addr;
		}
		catch (...) {
			return false;
		}
		return true;
	}

	// AddressScheduler* GetBase() {

		// return &g_Base;
	// }
};

#endif