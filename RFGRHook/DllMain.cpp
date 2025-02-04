#include <MinHook.h>
#pragma comment(lib, "libMinHook.x86.lib")
#include "Utilities.h"
#include "RFGRHook.h"
#include "Console.h"

using namespace RFGRHook;
using namespace Console;

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved) {
	switch (dwReason) {
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hModule);
		SetupHook();
		RuntimePatches();
		SetupCommands();
		break;
	case DLL_PROCESS_DETACH:
		FreeLibraryAndExitThread(hModule, TRUE);
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
		break;
	default:
		break;
	}
	return TRUE;
}