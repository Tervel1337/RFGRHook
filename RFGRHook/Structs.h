#pragma once

struct Command {
	char Padding[0x14];
};

struct Dict {
	Dict* Prev;
	Command* Def;
	const char* Word;
};

struct SpawnParams
{
	const int* Info;
	float SpawnPos[3];
	const int* OSRP;
	unsigned int ZoneID;
	float SpawnOrient[9];
	float InitialSpeed;
	unsigned int Parent;
	unsigned int Building;
	int Priority;
	__int64 VehicleFlags;
	int SpawnFlags;
	int Pointer;
};

struct EnterData
{
	unsigned int Teleport : 1;
	unsigned int Walk : 1;
	unsigned int MinimalProcessing : 1;
	unsigned int ReserveSeatOnly : 1;
	unsigned int UsePFPath : 1;
	unsigned int TeleportToDoor : 1;
	unsigned int Padding : 1;
	unsigned int Padding2 : 1;
};

struct EnterParams
{
	int Seat;
	int Selection;
	EnterData Params;
	char Padding[3];
};