#pragma once

namespace Camera {
	extern bool SlewEnabled;
	extern float* Pos;
	extern float* Orient;

	void ChangeMode(int Index);
	void ResetMode(int Index);
	void Slew(float* Pos, float* Orient, float Frametime, int Idk1, bool Idk2);
	void SlewMode();
	void Update();
	const int* GetID(const char* VehicleName);
}
