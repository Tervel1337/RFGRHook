#include "Game.h"

bool Game::HudHidden;
bool Game::Paused;
bool Game::FogDisabled;

int* Game::PauseC = (int*)(Addr(0x02532880));
bool* Game::FogEnabled = (bool*)(Addr(0x0165BBEA));
bool* Game::PlayerControls = (bool*)(Addr(0x01E299B9));

void Game::FlushInput() {
	((void(__cdecl*)())Addr(0x00568870))();
}

int Game::AddSubs(const wchar_t* Text, float Duration, void* Idk1, void* Idk2, int* Idk3) {
	return ((int(__cdecl*)(const wchar_t*, float, void*, void*, int*))Addr(0x008D81E0))(Text, Duration, Idk1, Idk2, Idk3);
}

void Game::HudHide(bool Hide) {
	((void(__cdecl*)(bool))Addr(0x00841AE0))(Hide);
}

void Game::Pause(bool Enable) {
	((void(__cdecl*)(bool))Addr(0x007C1620))(Enable);
}

void Game::Unpause() {
	((void(__cdecl*)())Addr(0x007C1650))();
}
