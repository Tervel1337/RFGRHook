#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <MinHook.h>
#include <MemoryMgr.h>

extern void* Addr(int offset);
extern bool IsKeyPressed(int Key, bool Hold);
extern bool IsRFGRFocused();
extern void UpdateKeys();
extern void GetDeltaTime();
extern float DeltaTime;