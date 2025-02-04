#pragma once
#include "Utilities.h"

namespace NPCs {
	void TeleportHuman(int Pointer, float* XYZ);
	int GetPlayer();
	char StopRagdoll(int NPCPointer, bool HoldPos);
}