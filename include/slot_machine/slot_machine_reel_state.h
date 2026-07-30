#ifndef POKEPLATINUM_SLOT_MACHINE_REEL_STATE_H
#define POKEPLATINUM_SLOT_MACHINE_REEL_STATE_H

#include "slot_machine/slot_machine_game_state_decl.h"

#include "enums.h"
#include "sys_task_manager.h"

typedef struct {
    u32 unk_00;
    int unk_04;
    fx32 unk_08;
    int unk_0C;
    UnkEnum_ov101_021D2BDC unk_10;
    int unk_14;
    int unk_18;
    SysTask *unk_1C;
    SlotMachineGameState *unk_20;
} SlotMachineReelState;

#endif // POKEPLATINUM_SLOT_MACHINE_REEL_STATE_H
