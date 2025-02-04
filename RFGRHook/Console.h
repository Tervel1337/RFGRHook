#pragma once
#pragma once
#include "Utilities.h"
#include "Structs.h"

namespace Console {

	extern bool Enabled;
	extern int* CommandRunning;
	extern bool CommandsInitialized;
	extern bool* Open;
	extern int* Width;
	extern int* Height;
	extern const char* String;

	void NewCommand(const char* Name, const char* Description, int Type, uintptr_t Addr);
	void CommandAdd(Command* Command, const char* CommandName, const char* HelpInfo, int Type, void* Addr);
	void CommandInsert(Dict* Entry);
	char GetArg(unsigned int Type, int Optional);
	void CreateCommand(const char* Name, const char* Description, int Type, uintptr_t Addr);
	void SetupCommands();
}
