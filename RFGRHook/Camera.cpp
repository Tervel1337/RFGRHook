#include "Camera.h"
#include "Game.h"

bool Camera::SlewEnabled;
float* Camera::Pos = (float*)(Addr(0x01DE3B88));
float* Camera::Orient = (float*)(Addr(0x01DE3BC4));

void Camera::SlewMode() {
	if (SlewEnabled) {
		Slew(Pos, Orient, DeltaTime, 0, false);

		if (Game::PauseC > 0) {
			Update();
		}
	}
}

void Camera::Update() {
	((void(__cdecl*)())Addr(0x006DFEC0))();
}

void Camera::ChangeMode(int Index) {
	((void(__cdecl*)(int))Addr(0x006C9240))(Index);
}

void Camera::ResetMode(int Index) {
	((void(__cdecl*)(int))Addr(0x006C92D0))(Index);
}

void Camera::Slew(float* Pos, float* Orient, float Frametime, int Idk1, bool Idk2) {
	((void(__cdecl*)(float*, float*, float, int, bool))Addr(0x005B77F0))(Pos, Orient, Frametime, Idk1, Idk2);
}