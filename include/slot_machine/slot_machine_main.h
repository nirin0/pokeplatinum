#ifndef POKEPLATINUM_SLOT_MACHINE_MAIN_H
#define POKEPLATINUM_SLOT_MACHINE_MAIN_H

#include "slot_machine/slot_machine_game_state_decl.h"

#include "enums.h"
#include "overlay_manager.h"

int ov101_021D0D80(ApplicationManager *appMan, int *param1);
int ov101_021D0E40(ApplicationManager *appMan, int *param1);
int ov101_021D0EE4(ApplicationManager *appMan, int *param1);
void ov101_021D13C8(SlotMachineGameState *gameState);
void ov101_021D148C(SlotMachineGameState *gameState, u32 param1);
void ov101_021D14E4(SlotMachineGameState *gameState);
void ov101_021D1894(SlotMachineGameState *gameState, UnkEnum_ov101_021D1894 param1);
void *ov101_021D1998(u32 param0);
void *ov101_021D19E4(SlotMachineGameState *gameState, u32 param1, int param2);

#endif // POKEPLATINUM_SLOT_MACHINE_MAIN_H
