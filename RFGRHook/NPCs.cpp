#include "NPCs.h"

char NPCs::StopRagdoll(int NPCPointer, bool HoldPos) {
	return ((char(__cdecl*)(int, bool))Addr(0x00AC1460))(NPCPointer, HoldPos);
}

void NPCs::TeleportHuman(int Pointer, float* XYZ) {
	((void(__cdecl*)(int, float*))Addr(0x00A2E0A0))(Pointer, XYZ);
}

int NPCs::GetPlayer() {
	return ((int(__cdecl*)())Addr(0x00A10540))();
}