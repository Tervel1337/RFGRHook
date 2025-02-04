#include "Utilities.h"


void* Addr(int Offset) { // the game uses ASLR, which is somewhat rare for a 32-bit title?
	Offset -= 0x400000;
	static int Handle = (int)GetModuleHandleA(NULL);
	return (void*)(Handle + Offset);
}

bool LastFrameStates[256];
bool WasPressedThisFrame[256];

void UpdateKeys() {
	for (int i = 0; i < 256; i++)
	{
		bool ThisFrameState = GetAsyncKeyState(i) < 0;
		WasPressedThisFrame[i] = ThisFrameState && !LastFrameStates[i];
		LastFrameStates[i] = ThisFrameState;
	}
}

bool IsRFGRFocused() {
	DWORD pid;
	GetWindowThreadProcessId(GetForegroundWindow(), &pid);
	return pid == GetCurrentProcessId();
}

bool IsKeyPressed(int Key, bool Hold) { // USE THIS FROM NOW ON
	if (IsRFGRFocused())
	{
		if (Hold)
		{
			return LastFrameStates[Key];
		}
		else
		{
			return WasPressedThisFrame[Key];
		}
	}
	return false;
}

float DeltaTime;

void GetDeltaTime() {
	static LARGE_INTEGER tpsFreq;
	static LARGE_INTEGER lastTickCount;
	LARGE_INTEGER currentTickCount;

	QueryPerformanceFrequency(&tpsFreq);
	QueryPerformanceCounter(&currentTickCount);
	float delta = (float)(currentTickCount.QuadPart - lastTickCount.QuadPart) / tpsFreq.QuadPart;
	lastTickCount = currentTickCount;
	DeltaTime = delta;
}