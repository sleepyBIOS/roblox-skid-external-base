#pragma once
#include <cstdint>
#include <Windows.h>
#include <TlHelp32.h>

namespace Mem {
    extern uint64_t basead;
    extern HANDLE UDhandle;

	DWORD getpid();
	uint64_t base();
	void openUDhandle(); // UNDETEK!111
    template<typename Typeshit>
    Typeshit Read(uint64_t address) {
        Typeshit buffer{};
        ReadProcessMemory(Mem::UDhandle, reinterpret_cast<LPCVOID>(address), &buffer, sizeof(buffer), nullptr);
        return buffer;
    }
}
