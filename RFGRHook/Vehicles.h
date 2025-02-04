#pragma once
#include "Structs.h"

namespace Vehicles {
	
	extern void* SpawnedPointer;
	extern bool IsSpawning;
	extern bool* VehicleWarp;
	int Spawn(SpawnParams* Bruh);
	bool Enter(int NPCPointer, void* VehPointer, EnterParams* Params);
	void Spawner();
	void Delete(void* VehPointer);
	void WarpIntoVehicle();
	const int* GetID(const char* VehicleName);
}