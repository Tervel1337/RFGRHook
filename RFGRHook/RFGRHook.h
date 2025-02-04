#pragma once
#include "Utilities.h"
#pragma comment(lib, "libMinHook.x86.lib")

namespace RFGRHook {
	void RuntimePatches();
	void StoreVehPointer();
	void Keybinds();
	bool Detour();
	void SetupHook();
	void ToggleSubs(const wchar_t* Subs, uintptr_t Toggle);
}