#include <iostream>
#include "memory/mem.h"
#include "offsets.hpp"

// if u dont understand anything here ur a noob go watch brocode tutorial bye
bool gameLoaded(uint64_t datamodel) { // pasted STRAIGHT from roblox offests oh yeah!!11
	int64_t result = Mem::Read<int64_t>(datamodel + offsets::GameLoaded);
	return result == 2; // had to fix cuz im pro
}

int main() {
	SetConsoleTitle(L"skid external base");
	std::cout << "starting ud external" << std::endl;
	if (Mem::getpid() == 0) {
		std::cout << "roblox isnt open" << std::endl;
		getchar();
		return -1;
	}

	Mem::openUDhandle();
	uint64_t base = Mem::base();

	std::cout << "roblox base: 0x" << std::hex << std::uppercase << base << std::endl;

	uint64_t visualEngine = Mem::Read<uint64_t>(base + offsets::VisualEnginePointer);
	uint64_t fakeDatamodel = Mem::Read<uint64_t>(visualEngine + offsets::VisualEngineToDataModel1);
	uint64_t datamodel = Mem::Read<uint64_t>(fakeDatamodel + offsets::VisualEngineToDataModel2);

	if (datamodel == NULL) {
		std::cout << "datamodel method no work stfu skid boy" << std::endl;
		return -1;
	}

	int creatorID = Mem::Read<int>(datamodel + offsets::CreatorId);
	std::cout << "datamodel: 0x" << std::hex << std::uppercase << datamodel << std::endl;
	bool gameisloaded = gameLoaded(datamodel);

	std::cout << "gameloaded: " << gameisloaded << std::endl;
	getchar();
	return 0;
}