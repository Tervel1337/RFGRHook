#pragma once
#include "Utilities.h"

namespace Game {
	extern bool HudHidden;
	extern bool Paused;
	extern bool FogDisabled;
	extern int* PauseC;
	extern bool* FogEnabled;
	extern bool* PlayerControls;

	void FlushInput();
	int AddSubs(const wchar_t* Text, float Duration, void* Idk1, void* Idk2, int* Idk3);
	void HudHide(bool Hide);
	void Pause(bool Enable);
	void Unpause();
}