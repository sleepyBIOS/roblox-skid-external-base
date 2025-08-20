#include "mem.h"

// UD = ULTRA DETECTED
// https://www.youtube.com/watch?v=RSxmEglT44I
namespace Mem
{
	uint64_t basead;
	HANDLE UDhandle;
	DWORD getpid() {
		HWND hwnd = FindWindowA(NULL, "Roblox");
		if (hwnd) {
			DWORD pid;
			GetWindowThreadProcessId(hwnd, &pid);
			return pid;
		}
		return 0;
	}
	uint64_t base() {
		HANDLE SnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, getpid());
		MODULEENTRY32 module{};
		module.dwSize = sizeof(module);
		if (Module32First(SnapShot, &module)) {
			if (module.szModule, "RobloxPlayerBeta.exe") {
				return (uintptr_t)module.modBaseAddr;
			}
		}
		return 0;
	}
	void openUDhandle() { // undetected.
		Mem::UDhandle = OpenProcess(PROCESS_VM_READ, FALSE, getpid()); // change to PROCESS_ALL_ACCESS to get even MORE undetected.
		Mem::basead = base();
	}
}
