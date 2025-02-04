#include "RFGRHook.h"
#include "Camera.h"
#include "Game.h"
#include "NPCs.h"
#include "Camera.h"
#include "Console.h"
#include "Vehicles.h"

using namespace Memory::VP;
using namespace Camera;
using namespace Vehicles;
using namespace Game;
using namespace NPCs;
using namespace Console;

typedef bool(__cdecl* OriginalCallT)();
OriginalCallT OriginalCall;

void RFGRHook::ToggleSubs(const wchar_t* Subtitles, uintptr_t Toggle) {
	std::wstring NewSubs = Subtitles;
	NewSubs += (Toggle ? L" ON" : L" OFF");
	AddSubs(NewSubs.c_str(), 0.5, 0, 0, 0);
}

void RFGRHook::Keybinds() {
	float AdjVal = 8096 * DeltaTime;

	if (IsKeyPressed(VK_F1, false)) {
		SlewEnabled = !SlewEnabled;
		ToggleSubs(L"SLEW MODE:", SlewEnabled);
		SlewEnabled ? ChangeMode(1) :ResetMode(1);
		*PlayerControls = (SlewEnabled ? true : false);
	}

	if (IsKeyPressed(VK_F2, false)) {
		HudHidden = !HudHidden;
		HudHide(HudHidden ? true : false);
	}

	if (IsKeyPressed(VK_F3, false)) {
		Paused = !Paused;
		Paused ? Pause(1) : Unpause();
	}
	if (IsKeyPressed(VK_F4, false)) {
		FogDisabled = !FogDisabled;
		ToggleSubs(L"FOG DISABLED:", FogDisabled);
		*FogEnabled = (FogDisabled ? false : true);
	}

	if (IsKeyPressed(VK_F5, false)) {
		TeleportHuman(GetPlayer(), Pos);
	}

	if (IsKeyPressed(VK_OEM_3, false)) {
		Enabled = !Enabled;
		FlushInput();
		*Width = 1024;
	}

	if (Enabled) { // horrible attempt at recreating the slide in/out anim because it's broken for some reason
		*Open = true;
		*Height = min(1920, *Height + AdjVal);
	}

	else {
		*Height = max(0, *Height - AdjVal);
		if (*Height == 0) {
			*Open = false;
		}
	}
}

void RFGRHook::RuntimePatches() {

	Patch<unsigned char>(Addr(0x00566E40), 0xC3);
	Patch<unsigned char>(Addr(0x00566E20), 0xC3);
	Patch<unsigned char>(Addr(0x00566E90), 0xC3);
	// slew-related initializers I need to avoid

	Patch<unsigned char>(Addr(0x012C208C), 0x05);
	Patch<unsigned char>(Addr(0x012C20A8), 0x04);
	Patch<unsigned char>(Addr(0x012C20C4), 0x07);
	Patch<unsigned char>(Addr(0x012C20E0), 0x06);
	// slew controller remaps

	Patch<unsigned char>(Addr(0x008CCCA0),0xC3); // skip intros and legal disclaimers
	Nop(Addr(0x005CD13F), 6); // prevent the game from changing the console mode when initializing
	Patch<unsigned char>(Addr(0x005CCFD4), 0x0C); // prevent the console from reading tilde
	InjectHook(Addr(0x00B48688), &StoreVehPointer, HookType::Jump); // patch to save the spawned vehicle's pointer so we can despawn/control it at any time
}

void __declspec(naked) RFGRHook::StoreVehPointer() {
	static int Continue = 0x00B4868D;
	__asm {
		mov eax, [edi + 88]
		test eax, eax
		mov cl, byte ptr[IsSpawning]
		cmp cl, 0
		jz Original
		mov SpawnedPointer, eax
		jmp Continue

		Original :
		jmp Continue
	}
}

void RFGRHook::SetupHook() {
	if (MH_Initialize() != MH_OK) {
		return;
	}

	if (MH_CreateHook((LPVOID)(Addr(0x005D2620)), &RFGRHook::Detour, (LPVOID*)&OriginalCall) != MH_OK) {
		return;
	}

	if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK) {
		return;
	}
}

bool RFGRHook::Detour() {
	UpdateKeys();
	Keybinds();
	SlewMode();
	GetDeltaTime();
	return OriginalCall();
}