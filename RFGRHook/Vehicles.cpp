#include "Vehicles.h"
#include "Console.h"
#include "Camera.h"
#include "NPCs.h"

using namespace NPCs;
using namespace Console;

void* Vehicles::SpawnedPointer;
bool Vehicles::IsSpawning;
bool* Vehicles::VehicleWarp = (bool*)(Addr(0x0376F033));
int Vehicles::SpawnFAddr = (int)(Addr(0x00B48570));
int Vehicles::PointerJAddr = (int)(Addr(0x00B4868D));

int __declspec(naked) Vehicles::Spawn(SpawnParams* Params) {
	__asm {
		push ebp
		mov ebp, esp
		sub esp, __LOCAL_SIZE


		mov eax, Params
		push eax

		mov edx, SpawnFAddr
		call edx

		mov esp, ebp
		pop ebp
		ret
	}
}

bool Vehicles::Enter(int NPCPointer, void* VehPointer, EnterParams* Params) {
	return ((bool(__cdecl*)(int, void*, EnterParams*))Addr(0x00BB7880))(NPCPointer, VehPointer, Params);
}

const int* Vehicles::GetID(const char* VehicleName)
{
	return ((const int* (__cdecl*)(const char*))Addr(0x00B84680))(VehicleName);
}

void Vehicles::Delete(void* VehPointer)
{
	((void(__thiscall*)(void*))Addr(0x00B47EC0))(VehPointer);
}

void Vehicles::WarpIntoVehicle() {
	*VehicleWarp = true;
	StopRagdoll(GetPlayer(), false);
	EnterParams Params = {};
	Params.Seat = 0;
	Enter(GetPlayer(), SpawnedPointer, &Params);
	*VehicleWarp = false;
}

void Vehicles::Spawner() {
	if (*CommandRunning) {
		GetArg(2, 0);
		const int* Vehicle = GetID(String);

		if (SpawnedPointer && Vehicle) {
			Delete(SpawnedPointer);
		}

		if (Vehicle) {
			SpawnParams Params = {};
			Params.Info = Vehicle;
			Params.SpawnPos[0] = Camera::Pos[0];
			Params.SpawnPos[1] = Camera::Pos[1] + 2.0;
			Params.SpawnPos[2] = Camera::Pos[2];
			memcpy(Params.SpawnOrient, Camera::Orient, sizeof(Params.SpawnOrient));
			Params.Priority = 5;
			IsSpawning = true;
			Spawn(&Params);
			IsSpawning = false;
			WarpIntoVehicle();
		}
	}
}