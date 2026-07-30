#include "slot_machine/slot_machine_lib.h"

#include <nitro.h>
#include <string.h>

#include "constants/species.h"

#include "slot_machine/const_ov101_021D94D8.h"
#include "slot_machine/const_ov101_021D94F0.h"
#include "slot_machine/const_ov101_021D9508.h"
#include "slot_machine/const_ov101_021D9520.h"
#include "slot_machine/const_ov101_021D9538.h"
#include "slot_machine/const_ov101_021D9550.h"
#include "slot_machine/const_ov101_021D9568.h"
#include "slot_machine/const_ov101_021D9580.h"
#include "slot_machine/const_ov101_021D9598.h"
#include "slot_machine/const_ov101_021D95C8.h"
#include "slot_machine/const_ov101_021D9628.h"
#include "slot_machine/const_ov101_021D9688.h"
#include "slot_machine/const_ov101_021D9784.h"
#include "slot_machine/const_ov101_021D9934.h"
#include "slot_machine/const_ov101_021D9AE4.h"
#include "slot_machine/slot_machine_main.h"
#include "slot_machine/slot_machine_anim.h"
#include "slot_machine/slot_machine_game_state.h"
#include "slot_machine/slot_machine_reel_state.h"
#include "slot_machine/struct_ov101_021D4714.h"
#include "slot_machine/struct_ov101_021D4764.h"
#include "slot_machine/struct_ov101_021D4F58.h"
#include "slot_machine/struct_ov101_021D95C8.h"
#include "slot_machine/struct_ov101_021D9784.h"
#include "slot_machine/struct_ov101_021D9934.h"
#include "slot_machine/struct_ov101_021D9AE4.h"

#include "bg_window.h"
#include "enums.h"
#include "heap.h"
#include "math_util.h"
#include "overworld_anim_manager.h"
#include "sound_playback.h"
#include "sys_task.h"
#include "sys_task_manager.h"
#include "system.h"

typedef struct {
    u16 unk_00_0 : 5;
    u16 unk_00_5 : 5;
    u16 unk_00_10 : 5;
    u16 unk_00_15 : 1;
} UnkStruct_ov101_021D4EC0;

typedef struct {
    u32 unk_00[3];
    UnkEnum_ov101_021D679C unk_0C[3];
} UnkStruct_ov101_021D87A8;

typedef struct {
    UnkEnum_ov101_021D4F58 unk_00;
    u32 unk_04;
    SlotMachineGameState *unk_08;
} UnkStruct_ov101_021D5068;

typedef struct {
    int unk_00;
    int unk_04;
    int unk_08;
    int unk_0C;
    UnkEnum_ov101_021D4F58 unk_10;
    u32 unk_14;
    fx32 unk_18;
    SlotMachineGameState *unk_1C;
    UnkStruct_ov101_021D4F58 *unk_20;
} UnkStruct_ov101_021D505C;

typedef struct {
    int unk_00;
    int unk_04;
    int unk_08;
    fx32 unk_0C;
    UnkEnum_ov101_021D4F58 unk_10;
    fx32 unk_14[5];
    SlotMachineGameState *unk_28;
    UnkStruct_ov101_021D4F58 *unk_2C;
} UnkStruct_ov101_021D5388;

typedef struct {
    u32 unk_00;
    fx32 unk_04;
    fx32 unk_08;
    fx32 unk_0C;
} UnkStruct_ov101_021D8938;

typedef struct {
    int unk_00;
    fx32 unk_04;
    int unk_08;
    SlotMachineGameState *unk_0C;
} UnkStruct_ov101_021D53B0;

static void ov101_021D1A68(SlotMachineGameState *gameState);
static void ov101_021D2B8C(SlotMachineGameState *gameState);
static void ov101_021D2BC0(SlotMachineGameState *gameState);
static void ov101_021D2BDC(SlotMachineGameState *gameState, UnkEnum_ov101_021D2BDC param1);
static void ov101_021D2BF4(SlotMachineGameState *gameState, UnkEnum_ov101_021D2BDC param1);
static int ov101_021D2C04(SlotMachineGameState *gameState, UnkEnum_ov101_021D2BDC param1);
static void ov101_021D2C10(SysTask *param0, void *param1);
static int ov101_021D2D88(SlotMachineReelState *reelState, SlotMachineGameState *gameState);
static int ov101_021D2DC0(SlotMachineReelState *reelState, SlotMachineGameState *gameState);
static int ov101_021D2DE0(SlotMachineReelState *reelState, SlotMachineGameState *gameState);
static int ov101_021D2E1C(SlotMachineReelState *reelState, SlotMachineGameState *gameState);
static int ov101_021D2E58(SlotMachineReelState *reelState, SlotMachineGameState *gameState);
static int ov101_021D2E94(SlotMachineReelState *reelState, SlotMachineGameState *gameState, UnkEnum_ov101_021D9688 param2);
static int ov101_021D2FAC(SlotMachineReelState *reelState, SlotMachineGameState *gameState, UnkEnum_ov101_021D9688 param2);
static int ov101_021D32EC(SlotMachineReelState *reelState, SlotMachineGameState *gameState, UnkEnum_ov101_021D9688 param2);
static int ov101_021D3394(SlotMachineReelState *reelState, SlotMachineGameState *gameState, UnkEnum_ov101_021D9688 param2);
static int ov101_021D3738(SlotMachineReelState *reelState, SlotMachineGameState *gameState, UnkEnum_ov101_021D9688 param2);
static void ov101_021D3780(SlotMachineReelState *reelState, SlotMachineGameState *gameState);
static void ov101_021D3830(SlotMachineReelState *reelState, SlotMachineGameState *gameState);
static int ov101_021D3AF0(SlotMachineGameState *gameState, int param1);
static int ov101_021D3B34(SlotMachineGameState *gameState, int param1, UnkEnum_ov101_021D9688 param2);
static int ov101_021D3B50(SlotMachineReelState *reelState, SlotMachineGameState *gameState, int param2);
static int ov101_021D3C9C(SlotMachineReelState *reelState, SlotMachineGameState *gameState, int param2);
static int ov101_021D3DD4(SlotMachineReelState *reelState, SlotMachineGameState *gameState, int param2);
static int ov101_021D3F0C(SlotMachineReelState *reelState, SlotMachineGameState *gameState, int param2);
static int ov101_021D3F58(SlotMachineReelState *reelState, SlotMachineGameState *gameState, int param2);
static int ov101_021D3FA0(SlotMachineReelState *reelState, SlotMachineGameState *gameState, int param2);
static int ov101_021D38E4(SlotMachineGameState *gameState);
static int ov101_021D38FC(SlotMachineReelState *reelState, SlotMachineGameState *gameState);
static int ov101_021D394C(SlotMachineReelState *paramReelState, SlotMachineGameState *gameState, int *param2, int *param3, int *param4);
static void ov101_021D3FE8(SlotMachineGameState *gameState, UnkEnum_ov101_021D2BDC param1, fx32 param2);
static fx32 ov101_021D4024(SlotMachineGameState *gameState, UnkEnum_ov101_021D2BDC param1, fx32 param2);
static u32 ov101_021D405C(SlotMachineGameState *gameState);
static int ov101_021D406C(u32 param0, u32 *param1);
static int ov101_021D4084(SlotMachineGameState *gameState);
static int ov101_021D40A8(SlotMachineGameState *gameState);
static int ov101_021D41EC(SlotMachineGameState *gameState);
static void ov101_021D4210(SlotMachineGameState *gameState);
static void ov101_021D42D0(SlotMachineGameState *gameState);
static int ov101_021D4370(SlotMachineGameState *gameState);
static void ov101_021D4394(SlotMachineGameState *gameState);
static int ov101_021D44C4(SlotMachineGameState *gameState);
static int ov101_021D44A0(SlotMachineGameState *gameState);
static int ov101_021D44E8(SlotMachineGameState *gameState);
static void ov101_021D44FC(SlotMachineGameState *gameState);
static UnkEnum_ov101_021D4550 ov101_021D4550(SlotMachineGameState *gameState);
static void ov101_021D45B0(SlotMachineGameState *gameState);
static void ov101_021D45C4(SlotMachineGameState *gameState);
static void ov101_021D45E8(SlotMachineGameState *gameState);
static void ov101_021D45F8(SlotMachineGameState *gameState);
static int ov101_021D460C(SlotMachineGameState *gameState);
static void ov101_021D4614(SysTask *param0, void *param1);
static void ov101_021D4714(UnkStruct_ov101_021D4714 *param0);
static void ov101_021D4764(SlotMachineGameState *gameState);
static void ov101_021D4788(SlotMachineGameState *gameState);
static void ov101_021D4798(SlotMachineGameState *gameState, u32 param1);
static int ov101_021D47AC(SlotMachineGameState *gameState);
static void ov101_021D47B4(SlotMachineGameState *gameState);
static void ov101_021D47F0(SlotMachineGameState *gameState);
static void ov101_021D4D38(SlotMachineGameState *gameState);
static void ov101_021D4EA4(SlotMachineGameState *gameState);
static void ov101_021D4EA8(NNSG2dPaletteData *param0, int param1, u16 *param2);
static void ov101_021D4EC0(u16 param0, u16 param1, u16 param2, u16 *param3);
static void ov101_021D4F18(const u16 *param0, const u16 *param1, u16 param2, u16 *param3);
static void ov101_021D4F40(SlotMachineGameState *gameState, u32 param1, int param2, u16 *param3);
static void ov101_021D4F58(SlotMachineGameState *gameState, UnkEnum_ov101_021D4F58 param1);
static void ov101_021D4F78(SlotMachineGameState *gameState, UnkEnum_ov101_021D4F58 param1);
static void ov101_021D4FB8(SlotMachineGameState *gameState, UnkEnum_ov101_021D4F58 param1);
static void ov101_021D4FF8(SlotMachineGameState *gameState);
static void ov101_021D5010(SlotMachineGameState *gameState);
static OverworldAnimManager *ov101_021D5028(SlotMachineGameState *gameState, UnkEnum_ov101_021D4F58 param1, u32 param2);
static int ov101_021D505C(OverworldAnimManager *param0);
static void ov101_021D5200(SlotMachineGameState *gameState);
static void ov101_021D5244(SlotMachineGameState *gameState);
static void ov101_021D53B0(SlotMachineGameState *gameState);
static void ov101_021D53D4(SlotMachineGameState *gameState);
static void ov101_021D53F8(SlotMachineGameState *gameState, int param1);
static int ov101_021D55F8(u32 param0);
static UnkEnum_ov101_021D9688 ov101_021D5618(u32 param0);
static UnkEnum_ov101_021D9688 ov101_021D5660(SlotMachineGameState *gameState);
static UnkEnum_ov101_021D9688 ov101_021D5698(SlotMachineGameState *gameState);
static UnkEnum_ov101_021D9688 ov101_021D56D0(SlotMachineGameState *gameState);
static UnkEnum_ov101_021D9688 ov101_021D5708(SlotMachineGameState *gameState);
static UnkEnum_ov101_021D9688 ov101_021D5740(SlotMachineGameState *gameState);
static UnkEnum_ov101_021D9688 ov101_021D5778(SlotMachineGameState *gameState, u32 param1, u32 *param2);
static UnkEnum_ov101_021D9688 ov101_021D57EC(SlotMachineGameState *gameState, u32 param1, u32 *param2);
static UnkEnum_ov101_021D5814 ov101_021D5814(u32 param0);
static void ov101_021D5848(SlotMachineGameState *gameState);
static void ov101_021D5858(SlotMachineGameState *gameState, u32 param1);
static int ov101_021D5880(SlotMachineGameState *gameState);
static int ov101_021D58C0(SlotMachineGameState *gameState);
static void ov101_021D58F4(SlotMachineGameState *gameState, UnkEnum_ov101_021D2BDC param1);
static void ov101_021D5938(SlotMachineGameState *gameState, UnkEnum_ov101_021D2BDC param1);
static u32 ov101_021D597C(SlotMachineGameState *gameState);
static void ov101_021D4824(SysTask *param0, void *param1);
static void ov101_021D542C(SysTask *param0, void *param1);
static void ov101_021D548C(SysTask *param0, void *param1);
static void ov101_021D54EC(SysTask *param0, void *param1);

static const UnkStruct_ov101_021D87A8 Unk_ov101_021D87A8[6];
static const int Unk_ov101_021D8740[3][2];
static int (*const Unk_ov101_021D8838[64])(SlotMachineGameState *);
static int (*const Unk_ov101_021D86C4[5])(SlotMachineReelState *, SlotMachineGameState *);
static int (*const *const Unk_ov101_021D8774[13])(UnkStruct_ov101_021D4764 *);

void ov101_021D1A28(SlotMachineGameState *gameState)
{
    ov101_021D1A68(gameState);
    ov101_021D2B8C(gameState);
    ov101_021D45C4(gameState);
    ov101_021D4764(gameState);
    ov101_021D4D38(gameState);
}

void ov101_021D1A4C(SlotMachineGameState *gameState)
{
    ov101_021D2BC0(gameState);
    ov101_021D45E8(gameState);
    ov101_021D4788(gameState);
    ov101_021D4EA4(gameState);
}

static void ov101_021D1A68(SlotMachineGameState *gameState)
{
    int v0, v1;
    fx32 v2;

    for (v0 = 0; v0 < 3; v0++) {
        v1 = (int)LCRNG_Next() % 21;
        gameState->unk_A8[v0] = v1;
        gameState->unk_90[v0] = (FX32_ONE * (21 * 32)) - (FX32_ONE * ((v1) * 32));
        gameState->unk_90[v0] %= (FX32_ONE * (21 * 32));
    }
}

int ov101_021D1AAC(SlotMachineGameState *gameState)
{
    int v0;

    do {
        v0 = Unk_ov101_021D8838[gameState->unk_00](gameState);
    } while (v0 == 1);

    if (v0 == 2) {
        return 1;
    }

    return 0;
}

static int GS00RoundInit(SlotMachineGameState *gameState)
{
    gameState->unk_64 = 0;
    gameState->unk_68 = 0;
    gameState->unk_8C = (FX32_ONE * 16);
    gameState->unk_74 = 0;
    gameState->unk_08 = 0;
    gameState->unk_00 = 1;

    ov101_021D5938(gameState, 0);
    ov101_021D5938(gameState, 1);
    ov101_021D5938(gameState, 2);
    ov101_021D4FF8(gameState);
    ov101_021D5200(gameState);

    if (gameState->unk_60 == 0) {
        gameState->unk_00 = 60;
        gameState->unk_04 = 63;
    } else if (gameState->unk_60 < 3) {
        gameState->unk_00 = 59;
        gameState->unk_04 = 63;
    } else if (gameState->unk_60 >= 50000) {
        gameState->unk_00 = 61;
        gameState->unk_04 = 1;
    }

    return 1;
}

static int GS01IdleButton(SlotMachineGameState *gameState)
{
    if (ov101_021D55F8(PAD_BUTTON_START) != 0) {
        ov101_021D5244(gameState);
        gameState->unk_00 = 63;
        return 0;
    }

    if (ov101_021D55F8(PAD_BUTTON_X) != 0) {
        gameState->unk_60 -= 3;
        gameState->unk_45C += 3;
        gameState->unk_00 = 2;

        Sound_PlayEffect(SEQ_SE_DP_ZUKAN02);
        ov101_021D5244(gameState);
        ov101_021D5010(gameState);

        return 0;
    }

    return 0;
}

static int GS02PaidButton(SlotMachineGameState *gameState)
{
    if (ov101_021D55F8(PAD_BUTTON_START) != 0) {
        gameState->unk_60 += 3;
        gameState->unk_00 = 63;
        return 0;
    }

    if (ov101_021D55F8(PAD_KEY_DOWN | PAD_BUTTON_X) != 0) {
        gameState->unk_00 = 3;
        return 1;
    }

    return 0;
}

static int GS03RollReels(SlotMachineGameState *gameState)
{
    ov101_021D40A8(gameState);

    gameState->unk_460++;
    gameState->unk_464++;
    gameState->unk_70 = 0;

    if (gameState->unk_74 & ((1 << 0) | (1 << 1) | (1 << 4) | (1 << 5))) {
        gameState->unk_70 = 1;
    }

    gameState->unk_30 = 0;

    if (gameState->unk_74 != 0) {
        if (ov101_021D41EC(gameState) == 0) {
            gameState->unk_13C.unk_18 = UnkEnum_ov101_021D5814_04;
        } else {
            gameState->unk_13C.unk_18 = ov101_021D5814(gameState->unk_74);
            gameState->unk_490++;
        }

        gameState->unk_30 = 1;
        ov101_021D4798(gameState, 1);
    }

    ov101_021D5938(gameState, 0);
    ov101_021D5938(gameState, 1);
    ov101_021D5938(gameState, 2);
    ov101_021D5010(gameState);

    ov101_021D2BDC(gameState, 0);
    ov101_021D2BDC(gameState, 1);
    ov101_021D2BDC(gameState, 2);
    ov101_021D5848(gameState);

    gameState->unk_7C[0] = 1;
    gameState->unk_7C[1] = 1;
    gameState->unk_7C[2] = 1;
    gameState->unk_6C = 0;
    gameState->unk_00 = 4;

    Sound_PlayEffect(SEQ_SE_DP_OPEN2);

    return 1;
}

static int GS04ReelStartedWait(SlotMachineGameState *gameState)
{
    gameState->unk_6C += FX32_ONE;

    if (gameState->unk_6C >= (FX32_ONE * 8)) {
        gameState->unk_6C = 0;
        gameState->unk_00 = 5;
        return 1;
    }

    return 0;
}

static int GS05ReelButton(SlotMachineGameState *gameState)
{
    u32 v0 = gSystem.pressedKeys;

    if ((gameState->unk_7C[0] == 1) && (v0 & PAD_BUTTON_Y)) {
        gameState->unk_7C[0] = 2;
        ov101_021D5858(gameState, PAD_BUTTON_Y);

        if (ov101_021D5880(gameState) == 0) {
            gameState->unk_70 = 0;
        }

        ov101_021D58F4(gameState, 0);
        ov101_021D2BF4(gameState, 0);
        Sound_PlayEffect(SEQ_SE_DP_UG_022);
    } else if ((gameState->unk_7C[1] == 1) && (v0 & PAD_BUTTON_B)) {
        gameState->unk_7C[1] = 2;

        ov101_021D5858(gameState, PAD_BUTTON_B);

        if (ov101_021D5880(gameState) == 0) {
            gameState->unk_70 = 0;
        }

        ov101_021D58F4(gameState, 1);
        ov101_021D2BF4(gameState, 1);
        Sound_PlayEffect(SEQ_SE_DP_UG_022);
    } else if ((gameState->unk_7C[2] == 1) && (v0 & PAD_BUTTON_A)) {
        gameState->unk_7C[2] = 2;
        ov101_021D5858(gameState, PAD_BUTTON_A);

        if (ov101_021D5880(gameState) == 0) {
            gameState->unk_70 = 0;
        }

        ov101_021D58F4(gameState, 2);
        ov101_021D2BF4(gameState, 2);
        Sound_PlayEffect(SEQ_SE_DP_UG_022);
    }

    if ((gameState->unk_7C[0] == 2) && (gameState->unk_7C[1] == 2) && (gameState->unk_7C[2] == 2)) {
        gameState->unk_00 = 6;
    }

    return 0;
}

static int GS06WaitForFullStopIGuess(SlotMachineGameState *gameState)
{
    if ((ov101_021D2C04(gameState, 0) == 1) || (ov101_021D2C04(gameState, 1) == 1) || (ov101_021D2C04(gameState, 2) == 1)) {
        return 0;
    }

    ov101_021D4FF8(gameState);
    gameState->unk_00 = 7;
    return 1;
}

static int GS07ResultCalc(SlotMachineGameState *gameState)
{
    UnkEnum_ov101_021D9688 v0 = ov101_021D5778(gameState, gameState->unk_74, &gameState->unk_48);

    gameState->unk_44 = v0;

    if (v0 == 6) {
        if (gameState->unk_74 & ((1 << 1) | (1 << 3) | (1 << 5) | (1 << 7))) {
            gameState->unk_00 = 16;
            return 1;
        }

        if (gameState->unk_74 != 0) {
            gameState->unk_00 = 10;
            return 1;
        }

        gameState->unk_00 = 8;
        return 1;
    }

    if (gameState->unk_74 & ((1 << 1) | (1 << 3) | (1 << 5) | (1 << 7))) {
        if (gameState->unk_74 & (1 << 1)) {
            gameState->unk_00 = 21;
        } else {
            gameState->unk_00 = 19;
        }

        return 1;
    }

    if (v0 == 2) {
        gameState->unk_00 = 14;
        return 1;
    }

    gameState->unk_00 = 12;
    return 1;
}

static int GS08NoWinReset(SlotMachineGameState *gameState)
{
    ov101_021D4FF8(gameState);

    gameState->unk_6C = 0;
    gameState->unk_00 = 9;

    return 1;
}

static int GS09NowWinWait(SlotMachineGameState *gameState)
{
    gameState->unk_6C += FX32_ONE;

    if (gameState->unk_6C >= (FX32_ONE * 8)) {
        gameState->unk_6C = 0;
        gameState->unk_00 = 0;
    }

    return 0;
}

static int GS10AlsoNoWinIGuess(SlotMachineGameState *gameState)
{
    ov101_021D4FF8(gameState);
    ov101_021D4798(gameState, 2);
    gameState->unk_00 = 11;

    return 0;
}

static int GS11AlsoNoWinIGuess2(SlotMachineGameState *gameState)
{
    if (ov101_021D47AC(gameState) == 1) {
        ov101_021D4798(gameState, 0);
        gameState->unk_00 = 0;
        return 1;
    }

    return 0;
}

static int GS12Payout(SlotMachineGameState *gameState)
{
    gameState->unk_64 = ov101_021D597C(gameState);
    gameState->unk_458 += gameState->unk_64;
    gameState->unk_6C = 0;
    gameState->unk_00 = 13;

    ov101_021D45F8(gameState);
    ov101_021D4798(gameState, 11);

    return 0;
}

static int GS13PayoutWait(SlotMachineGameState *gameState)
{
    gameState->unk_6C += FX32_ONE;

    if (gameState->unk_6C == (FX32_ONE * 30)) {
        ov101_021D4798(gameState, 2);
    } else if (gameState->unk_6C > (FX32_ONE * 30)) {
        if ((ov101_021D460C(gameState) == 1) && (ov101_021D47AC(gameState) == 1)) {
            ov101_021D4798(gameState, 0);
            gameState->unk_6C = 0;
            gameState->unk_00 = 0;
            return 1;
        }
    }

    return 0;
}

static int GS14Replay(SlotMachineGameState *gameState)
{
    gameState->unk_64 = 0;
    gameState->unk_6C = 0;
    gameState->unk_00 = 15;

    ov101_021D45F8(gameState);
    ov101_021D4798(gameState, 11);

    return 0;
}

static int GS15ReplayWait(SlotMachineGameState *gameState)
{
    gameState->unk_6C += FX32_ONE;

    if (gameState->unk_6C == (FX32_ONE * 15)) {
        ov101_021D4798(gameState, 2);
    } else if (gameState->unk_6C > (FX32_ONE * 15)) {
        if ((ov101_021D460C(gameState) == 1) && (ov101_021D47AC(gameState) == 1)) {
            ov101_021D4798(gameState, 0);
            gameState->unk_6C = 0;
            gameState->unk_00 = 3;
            return 1;
        }
    }

    return 0;
}

static int GS16NoWinButSetLuckVarsThen17(SlotMachineGameState *gameState)
{
    ov101_021D4FF8(gameState);
    ov101_021D4210(gameState);
    ov101_021D42D0(gameState);
    ov101_021D4798(gameState, 11);

    gameState->unk_6C = 0;
    gameState->unk_00 = 17;

    return 0;
}

static int GS17Wait(SlotMachineGameState *gameState)
{
    gameState->unk_6C += FX32_ONE;

    if (gameState->unk_6C >= (FX32_ONE * 8)) {
        ov101_021D4798(gameState, 3);
        ov101_021D1894(gameState, UnkEnum_ov101_021D1894_01);
        gameState->unk_00 = 18;
    }

    return 0;
}

static int GS18To23(SlotMachineGameState *gameState)
{
    if (ov101_021D47AC(gameState) == 1) {
        gameState->unk_00 = 23;
        return 1;
    }

    return 0;
}

static int GS19PayoutAndSetLuckVars(SlotMachineGameState *gameState)
{
    gameState->unk_64 = ov101_021D597C(gameState);
    gameState->unk_6C = 0;
    gameState->unk_00 = 20;

    ov101_021D45F8(gameState);
    ov101_021D4210(gameState);
    ov101_021D42D0(gameState);
    ov101_021D4798(gameState, 11);

    return 0;
}

static int GS20WaitFor23(SlotMachineGameState *gameState)
{
    gameState->unk_6C += FX32_ONE;

    if (gameState->unk_6C == (FX32_ONE * 30)) {
        ov101_021D1894(gameState, UnkEnum_ov101_021D1894_01);
        ov101_021D4798(gameState, 3);
    } else if (gameState->unk_6C >= (FX32_ONE * 30)) {
        if ((ov101_021D460C(gameState) == 1) && (ov101_021D47AC(gameState) == 1)) {
            gameState->unk_6C = 0;
            gameState->unk_00 = 23;
            return 1;
        }
    }

    return 0;
}

static int GS21SetLuckVars(SlotMachineGameState *gameState)
{
    gameState->unk_6C = 0;
    gameState->unk_00 = 22;

    ov101_021D45F8(gameState);
    ov101_021D4798(gameState, 11);
    ov101_021D4210(gameState);
    ov101_021D42D0(gameState);

    return 0;
}

static int GS22WaitFor24(SlotMachineGameState *gameState)
{
    gameState->unk_6C += FX32_ONE;

    if (gameState->unk_6C == (FX32_ONE * 8)) {
        ov101_021D4798(gameState, 3);
        ov101_021D1894(gameState, UnkEnum_ov101_021D1894_01);
    } else if (gameState->unk_6C >= (FX32_ONE * 8)) {
        if ((ov101_021D460C(gameState) == 1) && (ov101_021D47AC(gameState) == 1)) {
            gameState->unk_6C = 0;
            gameState->unk_00 = 24;
            return 1;
        }
    }

    return 0;
}

static int GS23To25(SlotMachineGameState *gameState)
{
    GF_ASSERT(gameState->unk_50 < UnkEnum_ov101_021D9934_06);
    gameState->unk_00 = 25;
    return 1;
}

static int GS24To28(SlotMachineGameState *gameState)
{
    GF_ASSERT(gameState->unk_50 < UnkEnum_ov101_021D9934_06);
    gameState->unk_00 = 28;

    return 1;
}

static int GS25RoundInit2(SlotMachineGameState *gameState)
{
    gameState->unk_64 = 0;
    gameState->unk_68 = 0;
    gameState->unk_00 = 26;
    gameState->unk_74 = 0;

    ov101_021D5938(gameState, 0);
    ov101_021D5938(gameState, 1);
    ov101_021D5938(gameState, 2);
    ov101_021D4FF8(gameState);
    ov101_021D5200(gameState);
    ov101_021D4798(gameState, 7);

    if (gameState->unk_60 == 0) {
        gameState->unk_00 = 60;
        gameState->unk_04 = 63;
    } else if (gameState->unk_60 < 3) {
        gameState->unk_00 = 59;
        gameState->unk_04 = 63;
    } else if (gameState->unk_60 >= 50000) {
        gameState->unk_00 = 61;
        gameState->unk_04 = 26;
    }

    return 1;
}

static int GS26IdleButton2(SlotMachineGameState *gameState)
{
    if (ov101_021D55F8(PAD_BUTTON_START) != 0) {
        gameState->unk_00 = 63;
        ov101_021D5244(gameState);
        return 0;
    }

    if (ov101_021D55F8(PAD_BUTTON_X) != 0) {
        gameState->unk_60 -= 3;
        gameState->unk_45C += 3;
        gameState->unk_00 = 27;

        Sound_PlayEffect(SEQ_SE_DP_ZUKAN02);
        ov101_021D5244(gameState);
        ov101_021D5010(gameState);

        return 0;
    }

    return 0;
}

static int GS27PaidButton2(SlotMachineGameState *gameState)
{
    if (ov101_021D55F8(PAD_BUTTON_START) != 0) {
        gameState->unk_60 += 3;
        gameState->unk_00 = 63;
        return 0;
    }

    if (ov101_021D55F8(PAD_KEY_DOWN | PAD_BUTTON_X) != 0) {
        gameState->unk_00 = 28;
        return 1;
    }

    return 0;
}

static int GS28RollReels2(SlotMachineGameState *gameState)
{
    ov101_021D4394(gameState);

    gameState->unk_460++;
    gameState->unk_468++;
    gameState->unk_70 = 0;

    if (gameState->unk_74 & ((1 << 0) | (1 << 1) | (1 << 4) | (1 << 5))) {
        gameState->unk_70 = 1;
    }

    gameState->unk_30 = 0;

    if (gameState->unk_74 != 0) {
        gameState->unk_30 = 1;
    }

    ov101_021D5938(gameState, 0);
    ov101_021D5938(gameState, 1);
    ov101_021D5938(gameState, 2);
    ov101_021D5010(gameState);

    ov101_021D2BDC(gameState, 0);
    ov101_021D2BDC(gameState, 1);
    ov101_021D2BDC(gameState, 2);
    ov101_021D5848(gameState);

    ov101_021D4798(gameState, 9);

    gameState->unk_7C[0] = 1;
    gameState->unk_7C[1] = 1;
    gameState->unk_7C[2] = 1;
    gameState->unk_6C = 0;
    gameState->unk_00 = 29;

    Sound_PlayEffect(SEQ_SE_DP_OPEN2);

    return 1;
}

static int GS29Wait8(SlotMachineGameState *gameState)
{
    gameState->unk_6C += FX32_ONE;

    if (gameState->unk_6C >= (FX32_ONE * 8)) {
        gameState->unk_6C = 0;
        gameState->unk_00 = 30;

        return 1;
    }

    return 0;
}

static int GS30ReelButton2(SlotMachineGameState *gameState)
{
    u32 v0 = gSystem.pressedKeys;

    if ((gameState->unk_7C[0] == 1) && (v0 & PAD_BUTTON_Y)) {
        gameState->unk_7C[0] = 2;

        ov101_021D5858(gameState, PAD_BUTTON_Y);

        if (ov101_021D5880(gameState) == 0) {
            gameState->unk_70 = 0;
        }

        ov101_021D58F4(gameState, 0);
        ov101_021D2BF4(gameState, 0);
        Sound_PlayEffect(SEQ_SE_DP_UG_022);
    } else if ((gameState->unk_7C[1] == 1) && (v0 & PAD_BUTTON_B)) {
        gameState->unk_7C[1] = 2;
        ov101_021D5858(gameState, PAD_BUTTON_B);

        if (ov101_021D5880(gameState) == 0) {
            gameState->unk_70 = 0;
        }

        ov101_021D58F4(gameState, 1);
        ov101_021D2BF4(gameState, 1);
        Sound_PlayEffect(SEQ_SE_DP_UG_022);
    } else if ((gameState->unk_7C[2] == 1) && (v0 & PAD_BUTTON_A)) {
        gameState->unk_7C[2] = 2;
        ov101_021D5858(gameState, PAD_BUTTON_A);

        if (ov101_021D5880(gameState) == 0) {
            gameState->unk_70 = 0;
        }

        ov101_021D58F4(gameState, 2);
        ov101_021D2BF4(gameState, 2);
        Sound_PlayEffect(SEQ_SE_DP_UG_022);
    }

    if ((gameState->unk_7C[0] == 2) && (gameState->unk_7C[1] == 2) && (gameState->unk_7C[2] == 2)) {
        gameState->unk_00 = 31;
    }

    return 0;
}

static int GS31WaitForFullStop(SlotMachineGameState *gameState)
{
    if ((ov101_021D2C04(gameState, 0) == 1) || (ov101_021D2C04(gameState, 1) == 1) || (ov101_021D2C04(gameState, 2) == 1)) {
        return 0;
    }

    ov101_021D4FF8(gameState);
    gameState->unk_00 = 32;
    return 1;
}

static int GS32ResultCalc(SlotMachineGameState *gameState)
{
    UnkEnum_ov101_021D9688 v0 = ov101_021D5778(gameState, gameState->unk_74, &gameState->unk_48);

    gameState->unk_44 = v0;

    if (v0 == 6) {
        gameState->unk_00 = 33;
        return 1;
    }

    if (gameState->unk_74 & ((1 << 8) | (1 << 9))) {
        gameState->unk_00 = 39;
        return 1;
    }

    if (v0 == 2) {
        gameState->unk_00 = 37;
        return 1;
    }

    gameState->unk_00 = 35;
    return 1;
}

static int GS33NoWin(SlotMachineGameState *gameState)
{
    ov101_021D4FF8(gameState);
    ov101_021D4798(gameState, 7);

    gameState->unk_6C = 0;
    gameState->unk_00 = 34;

    return 1;
}

static int GS34NoWinWaitFor25(SlotMachineGameState *gameState)
{
    gameState->unk_6C += FX32_ONE;

    if (gameState->unk_6C >= (FX32_ONE * 8)) {
        gameState->unk_6C = 0;
        gameState->unk_00 = 25;

        return 1;
    }

    return 0;
}

static int GS35Payout(SlotMachineGameState *gameState)
{
    gameState->unk_64 = ov101_021D597C(gameState);
    gameState->unk_458 += gameState->unk_64;
    gameState->unk_6C = 0;
    gameState->unk_00 = 36;

    ov101_021D45F8(gameState);
    ov101_021D4798(gameState, 10);

    return 0;
}

static int GS36PayoutWaitFor25(SlotMachineGameState *gameState)
{
    if (ov101_021D460C(gameState) == 1) {
        ov101_021D4798(gameState, 7);
        gameState->unk_00 = 25;
        return 1;
    }

    return 0;
}

static int GS37Replay(SlotMachineGameState *gameState)
{
    gameState->unk_64 = 0;
    gameState->unk_6C = 0;
    gameState->unk_00 = 38;

    ov101_021D45F8(gameState);
    ov101_021D4798(gameState, 10);

    return 0;
}

static int GS38ReplayWaitFor28(SlotMachineGameState *gameState)
{
    gameState->unk_6C += FX32_ONE;

    if (gameState->unk_6C > (FX32_ONE * 15)) {
        if (ov101_021D460C(gameState) == 1) {
            ov101_021D4798(gameState, 7);
            ov101_021D4FF8(gameState);

            gameState->unk_6C = 0;
            gameState->unk_00 = 28;

            return 1;
        }
    }

    return 0;
}

static int GS39Payout(SlotMachineGameState *gameState)
{
    gameState->unk_64 = ov101_021D597C(gameState);
    gameState->unk_458 += gameState->unk_64;
    gameState->unk_6C = 0;
    gameState->unk_00 = 40;

    ov101_021D45F8(gameState);
    ov101_021D4798(gameState, 10);
    ov101_021D53B0(gameState);
    ov101_021D1894(gameState, UnkEnum_ov101_021D1894_02);

    gameState->unk_454 = ov101_021D7B08(gameState);

    return 0;
}

static int GS40WaitForAnim(SlotMachineGameState *gameState)
{
    if (ov101_021D460C(gameState) == 1) {
        OverworldAnimManager_Finish(gameState->unk_454);
        ov101_021D4798(gameState, 7);
        gameState->unk_00 = 41;
        return 1;
    }

    return 0;
}

static int GS41Init8x12x20(SlotMachineGameState *gameState)
{
    ov101_021D47B4(gameState);

    gameState->unk_1C = 0;
    gameState->unk_14 = 0;
    gameState->unk_08 = 1;
    gameState->unk_00 = 42;

    return 1;
}

static int GS42InitBonusRound(SlotMachineGameState *gameState)
{
    gameState->unk_0C++;
    gameState->unk_1C++;

    if (gameState->unk_1C > 999) {
        gameState->unk_1C = 999;
    }

    ov101_021D79BC(gameState, gameState->unk_1C);

    gameState->unk_10 = 15 + 1;
    gameState->unk_08 = 1;
    gameState->unk_24 = 0;
    gameState->unk_28 = 0;
    gameState->unk_2C = 0;

    if (ov101_021D44E8(gameState) == 0) {
        gameState->unk_2C = 1;
    }

    gameState->unk_00 = 43;
    return 1;
}

static int GS43BonusPreCheckCoinsEtc(SlotMachineGameState *gameState)
{
    gameState->unk_10--;
    GF_ASSERT((int)gameState->unk_10 >= 1);

    ov101_021D5938(gameState, 0);
    ov101_021D5938(gameState, 1);
    ov101_021D5938(gameState, 2);
    ov101_021D4FF8(gameState);
    ov101_021D5200(gameState);
    ov101_021D4798(gameState, 7);

    gameState->unk_00 = 44;

    if (gameState->unk_60 == 0) {
        gameState->unk_00 = 60;
        gameState->unk_04 = 63;
    } else if (gameState->unk_60 < 1) {
        gameState->unk_00 = 60;
        gameState->unk_04 = 63;
    } else if (gameState->unk_60 >= 50000) {
        gameState->unk_00 = 61;
        gameState->unk_04 = 44;
    }

    return 1;
}

static int GS44BonusIdleButton(SlotMachineGameState *gameState)
{
    if (ov101_021D55F8(PAD_BUTTON_START) != 0) {
        gameState->unk_00 = 63;
        return 0;
    }

    if (ov101_021D55F8(PAD_BUTTON_X) != 0) {
        gameState->unk_60 -= 1;
        gameState->unk_14 -= 1;
        gameState->unk_45C += 1;

        if ((int)gameState->unk_14 < 0) {
            gameState->unk_14 = 0;
        }

        gameState->unk_00 = 45;

        Sound_PlayEffect(SEQ_SE_DP_ZUKAN02);
        ov101_021D5244(gameState);
        ov101_021D4FB8(gameState, UnkEnum_ov101_021D4F58_00);

        return 0;
    }

    return 0;
}

static int GS45BonusPaidButton(SlotMachineGameState *gameState)
{
    if (ov101_021D55F8(PAD_BUTTON_START) != 0) {
        gameState->unk_60 += 1;
        gameState->unk_00 = 63;
        return 0;
    }

    if (ov101_021D55F8(PAD_KEY_DOWN | PAD_BUTTON_X) != 0) {
        gameState->unk_00 = 46;
        return 1;
    }

    return 0;
}

static int GS46BonusRollReels(SlotMachineGameState *gameState)
{
    gameState->unk_460++;
    gameState->unk_46C++;
    gameState->unk_74 = (1 << 0);
    gameState->unk_30 = 1;
    gameState->unk_70 = 1;

    ov101_021D5938(gameState, 0);
    ov101_021D5938(gameState, 1);
    ov101_021D5938(gameState, 2);
    ov101_021D4FB8(gameState, UnkEnum_ov101_021D4F58_00);

    ov101_021D2BDC(gameState, 0);
    ov101_021D2BDC(gameState, 1);
    ov101_021D2BDC(gameState, 2);
    ov101_021D5848(gameState);
    ov101_021D45B0(gameState);

    gameState->unk_7C[0] = 1;
    gameState->unk_7C[1] = 1;
    gameState->unk_7C[2] = 1;
    gameState->unk_6C = 0;
    gameState->unk_00 = 47;

    Sound_PlayEffect(SEQ_SE_DP_OPEN2);

    if ((gameState->unk_24 == 0) && (gameState->unk_28 == 0)) {
        if (ov101_021D44C4(gameState) == 1) {
            gameState->unk_28 = 1;
            gameState->unk_4C0++;
        }

        if (gameState->unk_28 == 1) {
            ov101_021D53F8(gameState, 1);
        }
    }

    if ((gameState->unk_24 == 0) && (gameState->unk_28 == 0)) {
        if (ov101_021D44A0(gameState) == 1) {
            gameState->unk_24 = 1;
            gameState->unk_4BC++;
        }

        if (gameState->unk_24 == 1) {
            ov101_021D53F8(gameState, 0);
        }
    }

    return 1;
}

static int GS47BonusWait(SlotMachineGameState *gameState)
{
    gameState->unk_6C += FX32_ONE;

    if (gameState->unk_6C >= (FX32_ONE * 8)) {
        gameState->unk_6C = 0;
        gameState->unk_00 = 48;
        ov101_021D4798(gameState, 6);
        return 1;
    }

    return 0;
}

static int GS48BonusReelButton(SlotMachineGameState *gameState)
{
    u32 v0 = gSystem.pressedKeys;

    if ((gameState->unk_7C[0] == 1) && (v0 & PAD_BUTTON_Y)) {
        gameState->unk_7C[0] = 2;
        ov101_021D5858(gameState, PAD_BUTTON_Y);

        if (ov101_021D58C0(gameState) == 0) {
            gameState->unk_70 = 0;
            gameState->unk_30 = 0;
        }

        ov101_021D58F4(gameState, 0);
        ov101_021D2BF4(gameState, 0);
        Sound_PlayEffect(SEQ_SE_DP_SELECT_SLOT);
    } else if ((gameState->unk_7C[1] == 1) && (v0 & PAD_BUTTON_B)) {
        gameState->unk_7C[1] = 2;
        ov101_021D5858(gameState, PAD_BUTTON_B);

        if (ov101_021D58C0(gameState) == 0) {
            gameState->unk_70 = 0;
            gameState->unk_30 = 0;
        }

        ov101_021D58F4(gameState, 1);
        ov101_021D2BF4(gameState, 1);
        Sound_PlayEffect(SEQ_SE_DP_SELECT_SLOT);
    } else if ((gameState->unk_7C[2] == 1) && (v0 & PAD_BUTTON_A)) {
        gameState->unk_7C[2] = 2;
        ov101_021D5858(gameState, PAD_BUTTON_A);

        if (ov101_021D58C0(gameState) == 0) {
            gameState->unk_70 = 0;
            gameState->unk_30 = 0;
        }

        ov101_021D58F4(gameState, 2);
        ov101_021D2BF4(gameState, 2);
        Sound_PlayEffect(SEQ_SE_DP_SELECT_SLOT);
    }

    if ((gameState->unk_7C[0] == 2) && (gameState->unk_7C[1] == 2) && (gameState->unk_7C[2] == 2)) {
        gameState->unk_00 = 49;
    }

    return 0;
}

static int GS49BonusWaitForFullStop(SlotMachineGameState *gameState)
{
    if ((ov101_021D2C04(gameState, 0) == 1) || (ov101_021D2C04(gameState, 1) == 1) || (ov101_021D2C04(gameState, 2) == 1)) {
        return 0;
    }

    ov101_021D4FF8(gameState);
    gameState->unk_00 = 50;
    return 1;
}

static int GS50BonusResultCalc(SlotMachineGameState *gameState)
{
    UnkEnum_ov101_021D9688 v0 = ov101_021D57EC(gameState, gameState->unk_74, &gameState->unk_48);

    gameState->unk_44 = v0;

    if (v0 == 6) {
        if (gameState->unk_28 == 1) {
            gameState->unk_28 = 3;
        }

        gameState->unk_00 = 51;
        return 1;
    }

    if (gameState->unk_28 == 1) {
        gameState->unk_28 = 2;
    }

    gameState->unk_00 = 52;

    return 1;
}

static int GS51BonusLoseTo43or54(SlotMachineGameState *gameState)
{
    ov101_021D4FF8(gameState);
    ov101_021D4798(gameState, 7);

    if ((int)gameState->unk_10 <= 1) {
        gameState->unk_00 = 54;
    } else {
        gameState->unk_00 = 43;
    }

    return 0;
}

static int GS52BonusWin(SlotMachineGameState *gameState)
{
    gameState->unk_64 = Unk_ov101_021D94F0[gameState->unk_44];
    gameState->unk_458 += gameState->unk_64;

    ov101_021D45F8(gameState);
    ov101_021D4798(gameState, 10);

    gameState->unk_6C = 0;
    gameState->unk_00 = 53;

    return 0;
}

static int GS53BonusWinTo43or54(SlotMachineGameState *gameState)
{
    if (ov101_021D460C(gameState) == 0) {
        return 0;
    }

    ov101_021D4798(gameState, 7);

    if ((int)gameState->unk_10 <= 1) {
        gameState->unk_00 = 54;
    } else {
        gameState->unk_00 = 43;
    }

    return 1;
}

static int GS54BonusRoundEndTo55or58(SlotMachineGameState *gameState)
{
    gameState->unk_10--;
    GF_ASSERT(gameState->unk_10 == 0);

    if ((gameState->unk_2C == 1) && (gameState->unk_24 == 0)) {
        ov101_021D4798(gameState, 8);
        gameState->unk_00 = 58;
        return 0;
    }

    gameState->unk_00 = 55;
    return 1;
}

static int GS55AnotherBonusRoundMaybeAnimation(SlotMachineGameState *gameState)
{
    UnkEnum_ov101_021D4550 v0;

    ov101_021D44FC(gameState);
    v0 = ov101_021D4550(gameState);

    if (gameState->unk_24 == 1) {
        v0 = UnkEnum_ov101_021D4550_02;
    }

    if (v0 == UnkEnum_ov101_021D4550_02) {
        ov101_021D4798(gameState, 5);
        gameState->unk_00 = 56;
        return 0;
    }

    if (v0 == UnkEnum_ov101_021D4550_01) {
        ov101_021D4798(gameState, 12);
        gameState->unk_00 = 57;
        return 0;
    }

    Sound_PlayPokemonCry(SPECIES_CLEFAIRY, 0);
    gameState->unk_00 = 42;
    return 0;
}

static int GS56AnimAnotherBonusRoundTo42(SlotMachineGameState *gameState)
{
    if (ov101_021D47AC(gameState) == 0) {
        return 0;
    }

    gameState->unk_00 = 42;
    return 1;
}

static int GS57AnimAnotherBonusRoundTo42(SlotMachineGameState *gameState)
{
    if (ov101_021D47AC(gameState) == 0) {
        return 0;
    }

    gameState->unk_00 = 42;
    return 1;
}

static int GS58EndClefairyTo0(SlotMachineGameState *gameState)
{
    if (ov101_021D47AC(gameState) == 0) {
        return 0;
    }

    if (gameState->unk_1C > gameState->unk_20) {
        gameState->unk_20 = gameState->unk_1C;
    }

    ov101_021D1894(gameState, UnkEnum_ov101_021D1894_00);
    ov101_021D53D4(gameState);
    gameState->unk_00 = 0;

    return 1;
}

static int GS59LessThen3CoinsMessageTo62(SlotMachineGameState *gameState)
{
    ov101_021D148C(gameState, 0);
    gameState->unk_00 = 62;
    return 0;
}

static int GS60NoCoinsMessageTo62(SlotMachineGameState *gameState)
{
    ov101_021D148C(gameState, 2);
    gameState->unk_00 = 62;
    return 0;
}

static int GS61FullCoinsMessageTo62(SlotMachineGameState *gameState)
{
    ov101_021D148C(gameState, 1);
    gameState->unk_00 = 62;
    return 0;
}

static int GS62GoTo63OrAppropriateRoundInit(SlotMachineGameState *gameState)
{
    if (ov101_021D55F8(PAD_BUTTON_A | PAD_BUTTON_B)) {
        ov101_021D14E4(gameState);
        gameState->unk_00 = gameState->unk_04;
    }

    return 0;
}

static int GS63End(SlotMachineGameState *gameState)
{
    ov101_021D5244(gameState);
    return 2;
}

static int (*const Unk_ov101_021D8838[64])(SlotMachineGameState *) = {
    GS00RoundInit,
    GS01IdleButton,
    GS02PaidButton,
    GS03RollReels,
    GS04ReelStartedWait,
    GS05ReelButton,
    GS06WaitForFullStopIGuess,
    GS07ResultCalc,
    GS08NoWinReset,
    GS09NowWinWait,
    GS10AlsoNoWinIGuess,
    GS11AlsoNoWinIGuess2,
    GS12Payout,
    GS13PayoutWait,
    GS14Replay,
    GS15ReplayWait,
    GS16NoWinButSetLuckVarsThen17,
    GS17Wait,
    GS18To23,
    GS19PayoutAndSetLuckVars,
    GS20WaitFor23,
    GS21SetLuckVars,
    GS22WaitFor24,
    GS23To25,
    GS24To28,
    GS25RoundInit2,
    GS26IdleButton2,
    GS27PaidButton2,
    GS28RollReels2,
    GS29Wait8,
    GS30ReelButton2,
    GS31WaitForFullStop,
    GS32ResultCalc,
    GS33NoWin,
    GS34NoWinWaitFor25,
    GS35Payout,
    GS36PayoutWaitFor25,
    GS37Replay,
    GS38ReplayWaitFor28,
    GS39Payout,
    GS40WaitForAnim,
    GS41Init8x12x20,
    GS42InitBonusRound,
    GS43BonusPreCheckCoinsEtc,
    GS44BonusIdleButton,
    GS45BonusPaidButton,
    GS46BonusRollReels,
    GS47BonusWait,
    GS48BonusReelButton,
    GS49BonusWaitForFullStop,
    GS50BonusResultCalc,
    GS51BonusLoseTo43or54,
    GS52BonusWin,
    GS53BonusWinTo43or54,
    GS54BonusRoundEndTo55or58,
    GS55AnotherBonusRoundMaybeAnimation,
    GS56AnimAnotherBonusRoundTo42,
    GS57AnimAnotherBonusRoundTo42,
    GS58EndClefairyTo0,
    GS59LessThen3CoinsMessageTo62,
    GS60NoCoinsMessageTo62,
    GS61FullCoinsMessageTo62,
    GS62GoTo63OrAppropriateRoundInit,
    GS63End
};

static void ov101_021D2B8C(SlotMachineGameState *gameState)
{
    u32 v0 = 0;
    SlotMachineReelState *reelState = gameState->unk_B4;

    do {
        reelState->unk_00 = 0;
        reelState->unk_10 = v0;
        reelState->unk_20 = gameState;
        reelState->unk_1C = SysTask_Start(ov101_021D2C10, &gameState->unk_B4[v0], 129 + v0);
        reelState++;
        v0++;
    } while (v0 < 3);
}

static void ov101_021D2BC0(SlotMachineGameState *gameState)
{
    u32 v0 = 0;

    do {
        SysTask_Done(gameState->unk_B4[v0].unk_1C);
        v0++;
    } while (v0 < 3);
}

static void ov101_021D2BDC(SlotMachineGameState *gameState, UnkEnum_ov101_021D2BDC param1)
{
    gameState->unk_B4[param1].unk_00 = 1;
    gameState->unk_B4[param1].unk_04 = 1;
}

static void ov101_021D2BF4(SlotMachineGameState *gameState, UnkEnum_ov101_021D2BDC param1)
{
    gameState->unk_B4[param1].unk_00 = 2;
}

static int ov101_021D2C04(SlotMachineGameState *gameState, UnkEnum_ov101_021D2BDC param1)
{
    return gameState->unk_B4[param1].unk_04;
}

static void ov101_021D2C10(SysTask *param0, void *param1)
{
    SlotMachineReelState *reelState = param1;
    SlotMachineGameState *gameState = reelState->unk_20;

    while (Unk_ov101_021D86C4[reelState->unk_00](reelState, gameState) == 1) {
        (void)0;
    }
}

static int ov101_021D2C30(SlotMachineReelState *reelState, SlotMachineGameState *gameState)
{
    return 0;
}

static int ov101_021D2C34(SlotMachineReelState *reelState, SlotMachineGameState *gameState)
{
    ov101_021D3FE8(gameState, reelState->unk_10, gameState->unk_8C);
    return 0;
}

static int ov101_021D2C4C(SlotMachineReelState *reelState, SlotMachineGameState *gameState)
{
    reelState->unk_00++;
    reelState->unk_14 = 0;
    reelState->unk_18 = 0;

    if (gameState->unk_30 == 1) {
        if (gameState->unk_08 == 0) {
            if (ov101_021D2D88(reelState, gameState) == 0) {
                ov101_021D3780(reelState, gameState);
                gameState->unk_30 = 0;
            }
        } else {
            if (ov101_021D2DC0(reelState, gameState) == 0) {
                ov101_021D3830(reelState, gameState);
                gameState->unk_30 = 0;
            }
        }
    } else {
        if (gameState->unk_08 == 0) {
            ov101_021D3780(reelState, gameState);
        } else {
            ov101_021D3830(reelState, gameState);
        }
    }

    return 1;
}

static int ov101_021D2CA8(SlotMachineReelState *reelState, SlotMachineGameState *gameState)
{
    fx32 v0, v1;
    int v2 = reelState->unk_10;
    int v3 = 0;

    v0 = gameState->unk_90[v2] % (FX32_ONE * 32);

    if (v0) {
        v3 = 1;
        v1 = gameState->unk_8C;

        if (v0 < v1) {
            v1 = v0;
        }

        v0 = ov101_021D4024(gameState, v2, v1);
    } else if (reelState->unk_18) {
        v3 = 1;
        reelState->unk_18--;
        ov101_021D3FE8(gameState, v2, gameState->unk_8C);
        v0 = gameState->unk_90[v2] % (FX32_ONE * 32);
    }

    if ((v0 == 0) && (reelState->unk_18 == 0)) {
        fx32 v4[5] = { (FX32_ONE * 4), (FX32_ONE * 8), (FX32_ONE * 8), (FX32_ONE * 8), (FX32_ONE * 16) };
        s32 v5 = reelState->unk_18;

        if (v5 > 4) {
            v5 = 4;
        }

        reelState->unk_08 = v4[v5];
        reelState->unk_0C = 0;
        reelState->unk_00++;

        if (v3 == 0) {
            return 1;
        }
    }

    return 0;
}

static int ov101_021D2D50(SlotMachineReelState *reelState, SlotMachineGameState *gameState)
{
    int v0 = reelState->unk_10;

    gameState->unk_9C[v0] = reelState->unk_08;
    reelState->unk_08 = -reelState->unk_08;
    reelState->unk_0C++;

    if ((reelState->unk_0C & 0x1) == 0) {
        reelState->unk_08 >>= 2;
    }

    if (reelState->unk_08 == 0) {
        reelState->unk_00 = 0;
        reelState->unk_04 = 0;
        gameState->unk_9C[v0] = 0;
    }

    return 0;
}

static int (*const Unk_ov101_021D86C4[5])(SlotMachineReelState *, SlotMachineGameState *) = {
    ov101_021D2C30,
    ov101_021D2C34,
    ov101_021D2C4C,
    ov101_021D2CA8,
    ov101_021D2D50,
};

static int ov101_021D2D88(SlotMachineReelState *reelState, SlotMachineGameState *gameState)
{
    if (gameState->unk_74 == 0) {
        return 0;
    }

    switch (reelState->unk_10) {
    case 0:
        return ov101_021D2DE0(reelState, gameState);
    case 1:
        return ov101_021D2E1C(reelState, gameState);
    case 2:
        return ov101_021D2E58(reelState, gameState);
    }

    GF_ASSERT(FALSE);
    return 0;
}

static int ov101_021D2DC0(SlotMachineReelState *reelState, SlotMachineGameState *gameState)
{
    if (gameState->unk_74 == 0) {
        return 0;
    }

    {
        UnkEnum_ov101_021D9688 v0 = ov101_021D5618(gameState->unk_74);
        return ov101_021D3738(reelState, gameState, v0);
    }
}

static int ov101_021D2DE0(SlotMachineReelState *reelState, SlotMachineGameState *gameState)
{
    UnkEnum_ov101_021D9688 v0 = ov101_021D5618(gameState->unk_74);

    if (v0 == 6) {
        return 0;
    }

    if (ov101_021D38FC(reelState, gameState) == 1) {
        return ov101_021D2E94(reelState, gameState, v0);
    }

    return ov101_021D2FAC(reelState, gameState, v0);
}

static int ov101_021D2E1C(SlotMachineReelState *reelState, SlotMachineGameState *gameState)
{
    UnkEnum_ov101_021D9688 v0 = ov101_021D5618(gameState->unk_74);

    if (v0 == 6) {
        return 0;
    }

    if (ov101_021D38FC(reelState, gameState) == 1) {
        return ov101_021D32EC(reelState, gameState, v0);
    }

    return ov101_021D3394(reelState, gameState, v0);
}

static int ov101_021D2E58(SlotMachineReelState *reelState, SlotMachineGameState *gameState)
{
    UnkEnum_ov101_021D9688 v0 = ov101_021D5618(gameState->unk_74);

    if (v0 == 6) {
        return 0;
    }

    if (ov101_021D38FC(reelState, gameState) == 1) {
        return ov101_021D32EC(reelState, gameState, v0);
    }

    return ov101_021D3394(reelState, gameState, v0);
}

static int ov101_021D2E94(SlotMachineReelState *reelState, SlotMachineGameState *gameState, UnkEnum_ov101_021D9688 param2)
{
    int v0, v1, v2, v3, v4;
    int v5 = reelState->unk_10;

    for (v0 = 1; v0 <= 3; v0++) {
        if (ov101_021D55D4(gameState, v5, v0) == param2) {
            for (v1 = 0; (v0 + v1) <= 3; v1++) {
                if (ov101_021D3B34(gameState, v1, param2) == 1) {
                    reelState->unk_14 = v0 + v1;
                    reelState->unk_18 = v1;
                    return 1;
                }
            }
        }
    }

    v2 = 4;

    if (gameState->unk_70 == 1) {
        v2 = 21;
    }

    v4 = (int)gameState->unk_A8[0];

    for (v0 = 1; v0 <= v2; v0++) {
        if (ov101_021D55D4(gameState, v5, 1 - v0) == param2) {
            for (v1 = 0; v1 < 3; v1++) {
                if (ov101_021D3B34(gameState, v0 + v1, param2) == 1) {
                    if (v1 == 0) {
                        v3 = v4 % 4;

                        if ((v3 == 0) && (ov101_021D3B34(gameState, v0 + 2, param2) == 1)) {
                            reelState->unk_14 = 3;
                            reelState->unk_18 = v0 + 2;
                            return 1;
                        }
                    } else if (v1 == 1) {
                        v3 = v4 % 6;

                        if ((v3 < 2) && (ov101_021D3B34(gameState, v0 + 2, param2) == 1)) {
                            reelState->unk_14 = 3;
                            reelState->unk_18 = v0 + 2;
                            return 1;
                        }
                    }

                    reelState->unk_14 = 1 + v1;
                    reelState->unk_18 = v0 + v1;
                    return 1;
                }
            }
        }
    }

    return 0;
}

static int ov101_021D2FAC(SlotMachineReelState *reelState, SlotMachineGameState *gameState, UnkEnum_ov101_021D9688 param2)
{
    int v0, v1, v2, v3, v4, v5;
    int v6 = reelState->unk_10;

    if (ov101_021D394C(reelState, gameState, &v2, &v3, &v4) == 0) {
        return 0;
    }

    if (ov101_021D3B34(gameState, 0, param2) == 1) {
        if (ov101_021D55D4(gameState, v6, v2) == param2) {
            reelState->unk_14 = v2;
            reelState->unk_18 = 0;
            return 1;
        }

        if ((v3 != 0) && (ov101_021D55D4(gameState, v6, v3) == param2)) {
            reelState->unk_14 = v3;
            reelState->unk_18 = 0;
            return 1;
        }

        if ((v4 != 0) && (ov101_021D55D4(gameState, v6, v4) == param2)) {
            reelState->unk_14 = v4;
            reelState->unk_18 = 0;
            return 1;
        }
    }

    v5 = 4;

    if (gameState->unk_70 == 1) {
        v5 = 21;
    }

    if (v3 == 0) {
        for (v0 = 1; v0 <= v5; v0++) {
            if (ov101_021D55D4(gameState, v6, v2 - v0) == param2) {
                if (ov101_021D3B34(gameState, v0, param2) == 1) {
                    reelState->unk_14 = v2;
                    reelState->unk_18 = v0;
                    return 1;
                }
            }
        }

        return 0;
    }

    if (v4 == 0) {
        for (v0 = 1; v0 <= v5; v0++) {
            if (v0 & 0x1) {
                if (ov101_021D55D4(gameState, v6, v2 - v0) == param2) {
                    if (ov101_021D3B34(gameState, v0, param2) == 1) {
                        reelState->unk_14 = v2;
                        reelState->unk_18 = v0;
                        return 1;
                    }
                }

                if (ov101_021D55D4(gameState, v6, v3 - v0) == param2) {
                    if (ov101_021D3B34(gameState, v0, param2) == 1) {
                        reelState->unk_14 = v3;
                        reelState->unk_18 = v0;
                        return 1;
                    }
                }
            } else {
                if (ov101_021D55D4(gameState, v6, v3 - v0) == param2) {
                    if (ov101_021D3B34(gameState, v0, param2) == 1) {
                        reelState->unk_14 = v3;
                        reelState->unk_18 = v0;
                        return 1;
                    }
                }

                if (ov101_021D55D4(gameState, v6, v2 - v0) == param2) {
                    if (ov101_021D3B34(gameState, v0, param2) == 1) {
                        reelState->unk_14 = v2;
                        reelState->unk_18 = v0;
                        return 1;
                    }
                }
            }
        }

        return 0;
    }

    for (v0 = 1; v0 <= v5; v0++) {
        int v7 = v0 & 0x3;

        if (v7 == 0) {
            if (ov101_021D55D4(gameState, v6, v2 - v0) == param2) {
                if (ov101_021D3B34(gameState, v0, param2) == 1) {
                    reelState->unk_14 = v2;
                    reelState->unk_18 = v0;
                    return 1;
                }
            }

            if (ov101_021D55D4(gameState, v6, v3 - v0) == param2) {
                if (ov101_021D3B34(gameState, v0, param2) == 1) {
                    reelState->unk_14 = v3;
                    reelState->unk_18 = v0;
                    return 1;
                }
            }

            if (ov101_021D55D4(gameState, v6, v4 - v0) == param2) {
                if (ov101_021D3B34(gameState, v0, param2) == 1) {
                    reelState->unk_14 = v4;
                    reelState->unk_18 = v0;
                    return 1;
                }
            }
        } else if (v7 == 1) {
            if (ov101_021D55D4(gameState, v6, v3 - v0) == param2) {
                if (ov101_021D3B34(gameState, v0, param2) == 1) {
                    reelState->unk_14 = v3;
                    reelState->unk_18 = v0;
                    return 1;
                }
            }

            if (ov101_021D55D4(gameState, v6, v2 - v0) == param2) {
                if (ov101_021D3B34(gameState, v0, param2) == 1) {
                    reelState->unk_14 = v2;
                    reelState->unk_18 = v0;
                    return 1;
                }
            }
        } else {
            if (ov101_021D55D4(gameState, v6, v4 - v0) == param2) {
                if (ov101_021D3B34(gameState, v0, param2) == 1) {
                    reelState->unk_14 = v4;
                    reelState->unk_18 = v0;
                    return 1;
                }
            }

            if (ov101_021D55D4(gameState, v6, v2 - v0) == param2) {
                if (ov101_021D3B34(gameState, v0, param2) == 1) {
                    reelState->unk_14 = v2;
                    reelState->unk_18 = v0;
                    return 1;
                }
            }

            if (ov101_021D55D4(gameState, v6, v3 - v0) == param2) {
                if (ov101_021D3B34(gameState, v0, param2) == 1) {
                    reelState->unk_14 = v3;
                    reelState->unk_18 = v0;
                    return 1;
                }
            }
        }
    }

    return 0;
}

static int ov101_021D32EC(SlotMachineReelState *reelState, SlotMachineGameState *gameState, UnkEnum_ov101_021D9688 param2)
{
    int v0, v1, v2;
    int v3 = reelState->unk_10;

    for (v0 = 1; v0 <= 3; v0++) {
        if (ov101_021D55D4(gameState, v3, v0) == param2) {
            reelState->unk_14 = v0;
            reelState->unk_18 = 0;
            return 1;
        }
    }

    v2 = 4;

    if (gameState->unk_70 == 1) {
        v2 = 21;
    }

    for (v0 = 1; v0 <= v2; v0++) {
        if (ov101_021D55D4(gameState, v3, 1 - v0) == param2) {
            v1 = v0 % 4;

            if (v1 == 1) {
                reelState->unk_14 = 3;
                reelState->unk_18 = v0 + 2;
                return 1;
            }

            if ((v1 == 2) || (v1 == 3)) {
                reelState->unk_14 = 2;
                reelState->unk_18 = v0 + 1;
                return 1;
            }

            reelState->unk_14 = 1;
            reelState->unk_18 = v0;
            return 1;
        }
    }

    return 0;
}

static int ov101_021D3394(SlotMachineReelState *reelState, SlotMachineGameState *gameState, UnkEnum_ov101_021D9688 param2)
{
    int v0, v1, v2, v3, v4, v5, v6 = 4, v7 = reelState->unk_10;

    if (ov101_021D394C(reelState, gameState, &v3, &v4, &v5) == 0) {
        return 0;
    }

    if (ov101_021D55D4(gameState, v7, v3) == param2) {
        reelState->unk_14 = v3;
        reelState->unk_18 = 0;
        return 1;
    }

    if ((v4 != 0) && (ov101_021D55D4(gameState, v7, v4) == param2)) {
        reelState->unk_14 = v4;
        reelState->unk_18 = 0;
        return 1;
    }

    if ((v5 != 0) && (ov101_021D55D4(gameState, v7, v5) == param2)) {
        reelState->unk_14 = v5;
        reelState->unk_18 = 0;
        return 1;
    }

    v6 = 4;

    if (gameState->unk_70 == 1) {
        v6 = 21;
    }

    if (v4 == 0) {
        for (v0 = 1; v0 <= v6; v0++) {
            if (ov101_021D55D4(gameState, v7, v3 - v0) == param2) {
                reelState->unk_14 = v3;
                reelState->unk_18 = v0;
                return 1;
            }
        }

        return 0;
    }

    v2 = (int)gameState->unk_A8[v7];

    if (v5 == 0) {
        if (v2 & 0x1) {
            for (v0 = 1; v0 <= v6; v0++) {
                if (ov101_021D55D4(gameState, v7, v3 - v0) == param2) {
                    reelState->unk_14 = v3;
                    reelState->unk_18 = v0;
                    return 1;
                }
            }

            for (v0 = 1; v0 <= v6; v0++) {
                if (ov101_021D55D4(gameState, v7, v4 - v0) == param2) {
                    reelState->unk_14 = v4;
                    reelState->unk_18 = v0;
                    return 1;
                }
            }
        } else {
            for (v0 = 1; v0 <= v6; v0++) {
                if (ov101_021D55D4(gameState, v7, v4 - v0) == param2) {
                    reelState->unk_14 = v4;
                    reelState->unk_18 = v0;
                    return 1;
                }
            }

            for (v0 = 1; v0 <= v6; v0++) {
                if (ov101_021D55D4(gameState, v7, v3 - v0) == param2) {
                    reelState->unk_14 = v3;
                    reelState->unk_18 = v0;
                    return 1;
                }
            }
        }

        return 0;
    }

    v2 %= 3;

    if (v2 == 0) {
        for (v0 = 1; v0 <= v6; v0++) {
            if (ov101_021D55D4(gameState, v7, v3 - v0) == param2) {
                reelState->unk_14 = v3;
                reelState->unk_18 = v0;
                return 1;
            }
        }

        for (v0 = 1; v0 <= v6; v0++) {
            if (ov101_021D55D4(gameState, v7, v4 - v0) == param2) {
                reelState->unk_14 = v4;
                reelState->unk_18 = v0;
                return 1;
            }
        }

        for (v0 = 1; v0 <= v6; v0++) {
            if (ov101_021D55D4(gameState, v7, v5 - v0) == param2) {
                reelState->unk_14 = v5;
                reelState->unk_18 = v0;
                return 1;
            }
        }
    } else if (v2 == 1) {
        for (v0 = 1; v0 <= v6; v0++) {
            if (ov101_021D55D4(gameState, v7, v4 - v0) == param2) {
                reelState->unk_14 = v4;
                reelState->unk_18 = v0;
                return 1;
            }
        }

        for (v0 = 1; v0 <= v6; v0++) {
            if (ov101_021D55D4(gameState, v7, v5 - v0) == param2) {
                reelState->unk_14 = v5;
                reelState->unk_18 = v0;
                return 1;
            }
        }

        for (v0 = 1; v0 <= v6; v0++) {
            if (ov101_021D55D4(gameState, v7, v3 - v0) == param2) {
                reelState->unk_14 = v3;
                reelState->unk_18 = v0;
                return 1;
            }
        }
    } else {
        for (v0 = 1; v0 <= v6; v0++) {
            if (ov101_021D55D4(gameState, v7, v5 - v0) == param2) {
                reelState->unk_14 = v5;
                reelState->unk_18 = v0;
                return 1;
            }
        }

        for (v0 = 1; v0 <= v6; v0++) {
            if (ov101_021D55D4(gameState, v7, v3 - v0) == param2) {
                reelState->unk_14 = v3;
                reelState->unk_18 = v0;
                return 1;
            }
        }

        for (v0 = 1; v0 <= v6; v0++) {
            if (ov101_021D55D4(gameState, v7, v4 - v0) == param2) {
                reelState->unk_14 = v4;
                reelState->unk_18 = v0;
                return 1;
            }
        }
    }

    return 0;
}

static int ov101_021D3738(SlotMachineReelState *reelState, SlotMachineGameState *gameState, UnkEnum_ov101_021D9688 param2)
{
    int v0, v1, v2;
    int v3 = reelState->unk_10;

    v2 = 4;

    if (gameState->unk_70 == 1) {
        v2 = 21;
    }

    for (v0 = 0; v0 <= v2; v0++) {
        if (ov101_021D55D4(gameState, v3, 2 - v0) == param2) {
            reelState->unk_14 = 2;
            reelState->unk_18 = v0;
            return 1;
        }
    }

    return 0;
}

static void ov101_021D3780(SlotMachineReelState *reelState, SlotMachineGameState *gameState)
{
    int v0, v1;

    v1 = ov101_021D38E4(gameState);

    if ((reelState->unk_10 != 0) && (v1 < 2)) {
        return;
    }

    if ((reelState->unk_10 == 0) && (v1 < 2)) {
        for (v0 = 0; v0 <= 21; v0++) {
            if (ov101_021D3AF0(gameState, v0) == 0) {
                reelState->unk_18 = v0;
                return;
            }
        }

        GF_ASSERT(FALSE);
        return;
    }

    switch (reelState->unk_10) {
    case 0:
        for (v0 = 1; v0 <= 21; v0++) {
            if (ov101_021D3B50(reelState, gameState, v0) == 0) {
                reelState->unk_18 = v0;
                return;
            }
        }

        GF_ASSERT(FALSE);
        return;
    case 1:
        for (v0 = 1; v0 <= 21; v0++) {
            if (ov101_021D3C9C(reelState, gameState, v0) == 0) {
                reelState->unk_18 = v0;
                return;
            }
        }

        GF_ASSERT(FALSE);

        break;
    case 2:
        for (v0 = 1; v0 <= 21; v0++) {
            if (ov101_021D3DD4(reelState, gameState, v0) == 0) {
                reelState->unk_18 = v0;
                return;
            }
        }

        GF_ASSERT(FALSE);
        break;
    }

    GF_ASSERT(FALSE);
}

static void ov101_021D3830(SlotMachineReelState *reelState, SlotMachineGameState *gameState)
{
    int v0, v1;

    v1 = ov101_021D38E4(gameState);

    if ((reelState->unk_10 != 0) && (v1 < 2)) {
        return;
    }

    if ((reelState->unk_10 == 0) && (v1 < 2)) {
        for (v0 = 0; v0 < 21; v0++) {
            if (ov101_021D55D4(gameState, 0, 2 - v0) != 3) {
                reelState->unk_18 = v0;
                return;
            }
        }

        GF_ASSERT(FALSE);
    }

    switch (reelState->unk_10) {
    case 0:
        for (v0 = 0; v0 < 21; v0++) {
            if (ov101_021D3F0C(reelState, gameState, v0) == 0) {
                reelState->unk_18 = v0;
                return;
            }
        }

        GF_ASSERT(FALSE);
        return;
    case 1:
        for (v0 = 0; v0 <= 21; v0++) {
            if (ov101_021D3F58(reelState, gameState, v0) == 0) {
                reelState->unk_18 = v0;
                return;
            }
        }

        GF_ASSERT(FALSE);
        return;
    case 2:
        for (v0 = 0; v0 <= 21; v0++) {
            if (ov101_021D3FA0(reelState, gameState, v0) == 0) {
                reelState->unk_18 = v0;
                return;
            }
        }

        GF_ASSERT(FALSE);
    }

    GF_ASSERT(FALSE);
}

static int ov101_021D38E4(SlotMachineGameState *gameState)
{
    int v0 = 0, v1 = 0;

    do {
        if (gameState->unk_7C[v0] != 1) {
            v1++;
        }

        v0++;
    } while (v0 < 3);

    return v1;
}

static int ov101_021D38FC(SlotMachineReelState *reelState, SlotMachineGameState *gameState)
{
    switch (reelState->unk_10) {
    case 0:
        if ((gameState->unk_7C[1] != 1) || (gameState->unk_7C[2] != 1)) {
            return 0;
        }

        break;
    case 1:
        if ((gameState->unk_7C[0] != 1) || (gameState->unk_7C[2] != 1)) {
            return 0;
        }

        break;
    case 2:
        if ((gameState->unk_7C[0] != 1) || (gameState->unk_7C[1] != 1)) {
            return 0;
        }

        break;
    }

    return 1;
}

static int ov101_021D394C(SlotMachineReelState *paramReelState, SlotMachineGameState *gameState, int *param2, int *param3, int *param4)
{
    UnkEnum_ov101_021D394C v0 = gameState->unk_7C[0];
    UnkEnum_ov101_021D394C v1 = gameState->unk_7C[1];
    UnkEnum_ov101_021D394C v2 = gameState->unk_7C[2];
    SlotMachineReelState *reel0State = &gameState->unk_B4[0];
    SlotMachineReelState *reel1State = &gameState->unk_B4[1];
    SlotMachineReelState *reel2State = &gameState->unk_B4[2];
    int v6 = reel0State->unk_14;
    int v7 = reel1State->unk_14;
    int v8 = reel2State->unk_14;

    *param2 = 0;
    *param3 = 0;
    *param4 = 0;

    switch (paramReelState->unk_10) {
    case 0:
        if ((v1 != 1) && (v2 != 1)) {
            if (v7 == v8) {
                *param2 = v7;
                return 1;
            }

            if (v8 == 1) {
                *param2 = 3;
                return 1;
            }

            *param2 = 1;
            return 1;
        }

        if (v1 != 1) {
            if (v7 == 2) {
                *param2 = 1;
                *param3 = 2;
                *param4 = 3;
                return 1;
            }

            *param2 = v7;
            return 1;
        }

        if (v8 == 2) {
            *param2 = v8;
            return 1;
        }

        *param2 = 1;
        *param3 = 3;
        return 1;
    case 1:
        if ((v0 != 1) && (v2 != 1)) {
            if (v6 == v8) {
                *param2 = v6;
                return 1;
            }

            *param2 = 2;
            return 1;
        }

        if (v0 != 1) {
            if (v6 == 2) {
                *param2 = 2;
                return 1;
            }

            if (v6 == 1) {
                *param2 = 1;
                *param3 = 2;
                return 1;
            }

            *param2 = 2;
            *param3 = 3;
            return 1;
        }

        if (v8 == 2) {
            *param2 = 2;
            return 1;
        }

        if (v8 == 1) {
            *param2 = 1;
            *param3 = 2;
            return 1;
        }

        *param2 = 2;
        *param3 = 3;
        return 1;
    case 2:
        if ((v0 != 1) && (v1 != 1)) {
            if (v6 == v7) {
                *param2 = v6;
                return 1;
            }

            if (v6 == 1) {
                *param2 = 3;
            } else {
                *param2 = 1;
            }

            return 1;
        }

        if (v0 != 1) {
            if (v6 == 2) {
                *param2 = 2;
                return 1;
            }

            *param2 = 1;
            *param3 = 3;
            return 1;
        }

        if (v7 == 2) {
            *param2 = 1;
            *param3 = 2;
            *param4 = 3;
            return 1;
        }

        *param2 = v7;
        return 1;
    }

    GF_ASSERT(FALSE);
    return 0;
}

static int ov101_021D3AF0(SlotMachineGameState *gameState, int param1)
{
    u32 v0 = ov101_021D55D4(gameState, 0, 1 - param1);

    if (v0 == 3) {
        return 1;
    }

    v0 = ov101_021D55D4(gameState, 0, 2 - param1);

    if (v0 == 3) {
        return 1;
    }

    v0 = ov101_021D55D4(gameState, 0, 3 - param1);

    if (v0 == 3) {
        return 1;
    }

    return 0;
}

static int ov101_021D3B34(SlotMachineGameState *gameState, int param1, UnkEnum_ov101_021D9688 param2)
{
    if (param2 == 3) {
        return 1;
    }

    if (ov101_021D3AF0(gameState, param1) == 0) {
        return 1;
    }

    return 0;
}

static int ov101_021D3B50(SlotMachineReelState *reelState, SlotMachineGameState *gameState, int param2)
{
    u32 v0, v1, v2;
    int v3 = gameState->unk_B4[1].unk_18;
    int v4 = gameState->unk_B4[2].unk_18;

    v0 = ov101_021D55D4(gameState, 0, 1 - param2);
    v1 = ov101_021D55D4(gameState, 1, 1 - v3);
    v2 = ov101_021D55D4(gameState, 2, 1 - v4);

    if ((v0 == 3) || ((v0 == v1) && (v0 == v2))) {
        return 1;
    }

    v0 = ov101_021D55D4(gameState, 0, 2 - param2);
    v1 = ov101_021D55D4(gameState, 1, 2 - v3);
    v2 = ov101_021D55D4(gameState, 2, 2 - v4);

    if ((v0 == 3) || ((v0 == v1) && (v0 == v2))) {
        return 1;
    }

    v0 = ov101_021D55D4(gameState, 0, 3 - param2);
    v1 = ov101_021D55D4(gameState, 1, 3 - v3);
    v2 = ov101_021D55D4(gameState, 2, 3 - v4);

    if ((v0 == 3) || ((v0 == v1) && (v0 == v2))) {
        return 1;
    }

    v0 = ov101_021D55D4(gameState, 0, 1 - param2);
    v1 = ov101_021D55D4(gameState, 1, 2 - v3);
    v2 = ov101_021D55D4(gameState, 2, 3 - v4);

    if ((v0 == 3) || ((v0 == v1) && (v0 == v2))) {
        return 1;
    }

    v0 = ov101_021D55D4(gameState, 0, 3 - param2);
    v1 = ov101_021D55D4(gameState, 1, 2 - v3);
    v2 = ov101_021D55D4(gameState, 2, 1 - v4);

    if ((v0 == 3) || ((v0 == v1) && (v0 == v2))) {
        return 1;
    }

    return 0;
}

static int ov101_021D3C9C(SlotMachineReelState *reelState, SlotMachineGameState *gameState, int param2)
{
    u32 v0, v1, v2;
    int v3 = gameState->unk_B4[0].unk_18;
    int v4 = gameState->unk_B4[2].unk_18;

    v0 = ov101_021D55D4(gameState, 0, 1 - v3);
    v1 = ov101_021D55D4(gameState, 1, 1 - param2);
    v2 = ov101_021D55D4(gameState, 2, 1 - v4);

    if ((v0 == v1) && (v0 == v2)) {
        return 1;
    }

    v0 = ov101_021D55D4(gameState, 0, 2 - v3);
    v1 = ov101_021D55D4(gameState, 1, 2 - param2);
    v2 = ov101_021D55D4(gameState, 2, 2 - v4);

    if ((v0 == v1) && (v0 == v2)) {
        return 1;
    }

    v0 = ov101_021D55D4(gameState, 0, 3 - v3);
    v1 = ov101_021D55D4(gameState, 1, 3 - param2);
    v2 = ov101_021D55D4(gameState, 2, 3 - v4);

    if ((v0 == v1) && (v0 == v2)) {
        return 1;
    }

    v0 = ov101_021D55D4(gameState, 0, 1 - v3);
    v1 = ov101_021D55D4(gameState, 1, 2 - param2);
    v2 = ov101_021D55D4(gameState, 2, 3 - v4);

    if ((v0 == v1) && (v0 == v2)) {
        return 1;
    }

    v0 = ov101_021D55D4(gameState, 0, 3 - v3);
    v1 = ov101_021D55D4(gameState, 1, 2 - param2);
    v2 = ov101_021D55D4(gameState, 2, 1 - v4);

    if ((v0 == v1) && (v0 == v2)) {
        return 1;
    }

    return 0;
}

static int ov101_021D3DD4(SlotMachineReelState *reelState, SlotMachineGameState *gameState, int param2)
{
    u32 v0, v1, v2;
    int v3 = gameState->unk_B4[0].unk_18;
    int v4 = gameState->unk_B4[1].unk_18;

    v0 = ov101_021D55D4(gameState, 0, 1 - v3);
    v1 = ov101_021D55D4(gameState, 1, 1 - v4);
    v2 = ov101_021D55D4(gameState, 2, 1 - param2);

    if ((v0 == v1) && (v0 == v2)) {
        return 1;
    }

    v0 = ov101_021D55D4(gameState, 0, 2 - v3);
    v1 = ov101_021D55D4(gameState, 1, 2 - v4);
    v2 = ov101_021D55D4(gameState, 2, 2 - param2);

    if ((v0 == v1) && (v0 == v2)) {
        return 1;
    }

    v0 = ov101_021D55D4(gameState, 0, 3 - v3);
    v1 = ov101_021D55D4(gameState, 1, 3 - v4);
    v2 = ov101_021D55D4(gameState, 2, 3 - param2);

    if ((v0 == v1) && (v0 == v2)) {
        return 1;
    }

    v0 = ov101_021D55D4(gameState, 0, 1 - v3);
    v1 = ov101_021D55D4(gameState, 1, 2 - v4);
    v2 = ov101_021D55D4(gameState, 2, 3 - param2);

    if ((v0 == v1) && (v0 == v2)) {
        return 1;
    }

    v0 = ov101_021D55D4(gameState, 0, 3 - v3);
    v1 = ov101_021D55D4(gameState, 1, 2 - v4);
    v2 = ov101_021D55D4(gameState, 2, 1 - param2);

    if ((v0 == v1) && (v0 == v2)) {
        return 1;
    }

    return 0;
}

static int ov101_021D3F0C(SlotMachineReelState *reelState, SlotMachineGameState *gameState, int param2)
{
    u32 v0, v1, v2;
    int v3 = gameState->unk_B4[1].unk_18;
    int v4 = gameState->unk_B4[2].unk_18;

    v0 = ov101_021D55D4(gameState, 0, 2 - param2);
    v1 = ov101_021D55D4(gameState, 1, 2 - v3);
    v2 = ov101_021D55D4(gameState, 2, 2 - v4);

    if ((v0 == 3) || (v0 == v1) && (v0 == v2)) {
        return 1;
    }

    return 0;
}

static int ov101_021D3F58(SlotMachineReelState *reelState, SlotMachineGameState *gameState, int param2)
{
    u32 v0, v1, v2;
    int v3 = gameState->unk_B4[0].unk_18;
    int v4 = gameState->unk_B4[2].unk_18;

    v0 = ov101_021D55D4(gameState, 0, 2 - v3);
    v1 = ov101_021D55D4(gameState, 1, 2 - param2);
    v2 = ov101_021D55D4(gameState, 2, 2 - v4);

    if ((v0 == v1) && (v0 == v2)) {
        return 1;
    }

    return 0;
}

static int ov101_021D3FA0(SlotMachineReelState *reelState, SlotMachineGameState *gameState, int param2)
{
    u32 v0, v1, v2;
    int v3 = gameState->unk_B4[0].unk_18;
    int v4 = gameState->unk_B4[1].unk_18;

    v0 = ov101_021D55D4(gameState, 0, 2 - v3);
    v1 = ov101_021D55D4(gameState, 1, 2 - v4);
    v2 = ov101_021D55D4(gameState, 2, 2 - param2);

    if ((v0 == v1) && (v0 == v2)) {
        return 1;
    }

    return 0;
}

static void ov101_021D3FE8(SlotMachineGameState *gameState, UnkEnum_ov101_021D2BDC param1, fx32 param2)
{
    gameState->unk_90[param1] += param2;
    gameState->unk_90[param1] %= (FX32_ONE * (21 * 32));
    gameState->unk_A8[param1] = 21 - (((gameState->unk_90[param1]) / FX32_ONE) / 32);
}

static fx32 ov101_021D4024(SlotMachineGameState *gameState, UnkEnum_ov101_021D2BDC param1, fx32 param2)
{
    fx32 v0;

    v0 = gameState->unk_90[param1] % (FX32_ONE * 32);

    if (v0) {
        if (v0 < param2) {
            param2 = v0;
        }

        ov101_021D3FE8(gameState, param1, param2);
        v0 = gameState->unk_90[param1] % (FX32_ONE * 32);
    }

    return v0;
}

static u32 ov101_021D405C(SlotMachineGameState *gameState)
{
    u32 v0 = ((u32)LCRNG_Next()) % 100;
    return v0;
}

static int ov101_021D406C(u32 param0, u32 *param1)
{
    u32 v0 = *param1;

    (*param1) -= param0;

    if ((int)(*param1) < 0) {
        (*param1) = 0;
    }

    if (v0 < param0) {
        return 1;
    }

    return 0;
}

static int ov101_021D4084(SlotMachineGameState *gameState)
{
    u32 v0 = ov101_021D405C(gameState);
    u32 v1 = Unk_ov101_021D9520[gameState->unk_88];

    if (v1 > v0) {
        return 1;
    }

    return 0;
}

static int ov101_021D40A8(SlotMachineGameState *gameState)
{
    gameState->unk_74 = 0;

    if (ov101_021D4084(gameState) == 1) {
        u32 v0 = ov101_021D405C(gameState);
        const UnkStruct_ov101_021D95C8 *v1 = &Unk_ov101_021D95C8[gameState->unk_88];

        gameState->unk_470++;

        if (ov101_021D406C(v1->unk_00.unk_00, &v0)) {
            gameState->unk_74 |= (1 << 3);
            gameState->unk_4A0++;
            return 1;
        }

        if (ov101_021D406C(v1->unk_00.unk_02, &v0)) {
            gameState->unk_74 |= (1 << 2);
            gameState->unk_49C++;
            return 1;
        }

        if (ov101_021D406C(v1->unk_04.unk_00, &v0)) {
            gameState->unk_74 |= (1 << 7);
            gameState->unk_4B0++;
            return 1;
        }

        if (ov101_021D406C(v1->unk_04.unk_02, &v0)) {
            gameState->unk_74 |= (1 << 6);
            gameState->unk_4AC++;
            return 1;
        }

        if (ov101_021D406C(v1->unk_08.unk_00, &v0)) {
            gameState->unk_74 |= (1 << 5);
            gameState->unk_4A8++;
            return 1;
        }

        if (ov101_021D406C(v1->unk_08.unk_02, &v0)) {
            gameState->unk_74 |= (1 << 4);
            gameState->unk_4A4++;
            return 1;
        }

        if (ov101_021D406C(v1->unk_0C.unk_00, &v0)) {
            gameState->unk_74 |= (1 << 1);
            gameState->unk_498++;
            return 1;
        }

        gameState->unk_74 |= (1 << 0);
        gameState->unk_494++;

        return 1;
    }

    return 0;
}

static int ov101_021D41EC(SlotMachineGameState *gameState)
{
    u32 v0 = ov101_021D405C(gameState);
    u32 v1 = Unk_ov101_021D94D8[gameState->unk_88];

    if (v0 < v1) {
        return 1;
    }

    return 0;
}

static void ov101_021D4210(SlotMachineGameState *gameState)
{
    int v0;
    u32 v1 = ov101_021D405C(gameState);
    const UnkStruct_ov101_021D9934 *v2 = Unk_ov101_021D9934[gameState->unk_88];

    for (v0 = 0; v0 < UnkEnum_ov101_021D9934_06; v0++) {
        if (ov101_021D406C(v2[v0].unk_00, &v1) == 1) {
            gameState->unk_50 = v2[v0].unk_04;
            gameState->unk_4C = v2[v0].unk_08;
            gameState->unk_18 = Unk_ov101_021D9568[gameState->unk_50];

            switch (gameState->unk_4C) {
            case UnkEnum_ov101_021D9934_1_00:
                gameState->unk_478++;
                break;
            case UnkEnum_ov101_021D9934_1_01:
                gameState->unk_47C++;
                break;
            case UnkEnum_ov101_021D9934_1_02:
                gameState->unk_480++;
                break;
            }

            return;
        }
    }

    v0--;

    gameState->unk_50 = v2[v0].unk_04;
    gameState->unk_4C = v2[v0].unk_08;
    gameState->unk_18 = Unk_ov101_021D9568[gameState->unk_50];

    GF_ASSERT(FALSE);
}

static void ov101_021D42D0(SlotMachineGameState *gameState)
{
    u32 v0 = 0, v1 = ov101_021D405C(gameState);
    const UnkStruct_ov101_021D9784 *v2 = Unk_ov101_021D9784[gameState->unk_88][gameState->unk_4C];

    do {
        if (ov101_021D406C(v2[v0].unk_00, &v1) == 1) {
            gameState->unk_13C.unk_1C = v2[v0].unk_04;

            switch (gameState->unk_13C.unk_1C) {
            case UnkEnum_ov101_021D6764_00:
                gameState->unk_488++;
                break;
            case UnkEnum_ov101_021D6764_01:
                gameState->unk_484++;
                break;
            case UnkEnum_ov101_021D6764_02:
                gameState->unk_48C++;
                break;
            }

            return;
        }

        v0++;
    } while (v0 < UnkEnum_ov101_021D6764_03);

    gameState->unk_13C.unk_1C = UnkEnum_ov101_021D6764_01;
    GF_ASSERT(FALSE);
}

static int ov101_021D4370(SlotMachineGameState *gameState)
{
    u32 v0 = Unk_ov101_021D9538[gameState->unk_88];
    u32 v1 = ov101_021D405C(gameState);

    if (v1 < v0) {
        return 1;
    }

    return 0;
}

static void ov101_021D4394(SlotMachineGameState *gameState)
{
    u32 v0;
    const u32 *v1 = Unk_ov101_021D9628[gameState->unk_88];
    u32 v2 = ov101_021D405C(gameState);

    gameState->unk_74 = 0;

    if (ov101_021D4370(gameState) == 0) {
        gameState->unk_474++;

        switch (gameState->unk_50) {
        case UnkEnum_ov101_021D9934_00:
        case UnkEnum_ov101_021D9934_01:
        case UnkEnum_ov101_021D9934_02:
            gameState->unk_74 |= (1 << 9);
            gameState->unk_4B8++;
            return;
        case UnkEnum_ov101_021D9934_03:
        case UnkEnum_ov101_021D9934_04:
        case UnkEnum_ov101_021D9934_05:
            gameState->unk_74 |= (1 << 8);
            gameState->unk_4B4++;
            return;
        }

        GF_ASSERT(FALSE);
        gameState->unk_74 |= (1 << 9);
        return;
    }

    if (ov101_021D406C(v1[0], &v2) == 1) {
        gameState->unk_74 |= (1 << 2);
        gameState->unk_49C++;
        return;
    }

    if (ov101_021D406C(v1[1], &v2) == 1) {
        gameState->unk_74 |= (1 << 6);
        gameState->unk_4AC++;
        return;
    }

    if (ov101_021D406C(v1[1], &v2) == 1) {
        gameState->unk_74 |= (1 << 4);
        gameState->unk_4A4++;
        return;
    }

    gameState->unk_74 = (1 << 0);
    gameState->unk_494++;
}

static int ov101_021D44A0(SlotMachineGameState *gameState)
{
    u32 v0 = ov101_021D405C(gameState);
    u32 v1 = Unk_ov101_021D9580[gameState->unk_88];

    if (v0 < v1) {
        return 1;
    }

    return 0;
}

static int ov101_021D44C4(SlotMachineGameState *gameState)
{
    u32 v0 = ov101_021D405C(gameState);
    u32 v1 = Unk_ov101_021D9508[gameState->unk_88];

    if (v0 < v1) {
        return 1;
    }

    return 0;
}

static int ov101_021D44E8(SlotMachineGameState *gameState)
{
    u32 v0 = gameState->unk_18;
    u32 v1 = ov101_021D405C(gameState);

    if (v1 < v0) {
        return 1;
    }

    return 0;
}

static void ov101_021D44FC(SlotMachineGameState *gameState)
{
    u32 v0 = gameState->unk_18;
    u32 v1 = ov101_021D405C(gameState);
    const u32 *v2 = Unk_ov101_021D9598[gameState->unk_88];

    if (gameState->unk_28 == 2) {
        v0 -= 10;
    } else {
        if (ov101_021D406C(v2[0], &v1) == 1) {
            v0 -= 10;
        } else if (ov101_021D406C(v2[1], &v1) == 1) {
            v0 -= 5;
        }
    }

    if ((int)v0 < 0) {
        v0 = 0;
    }

    gameState->unk_18 = v0;
}

static UnkEnum_ov101_021D4550 ov101_021D4550(SlotMachineGameState *gameState)
{
    int v0;
    u32 v1 = gameState->unk_18;
    u32 v2 = ov101_021D405C(gameState);
    const UnkStruct_ov101_021D9AE4 *v3 = Unk_ov101_021D9AE4[gameState->unk_88];

    for (v0 = 0; v0 < UnkEnum_ov101_021D9AE4_09; v0++) {
        if (v1 >= v3[v0].unk_00) {
            if (ov101_021D406C(v3[v0].unk_04, &v2) == 1) {
                return UnkEnum_ov101_021D4550_01;
            }

            if (ov101_021D406C(v3[v0].unk_08, &v2) == 1) {
                return UnkEnum_ov101_021D4550_00;
            }

            return UnkEnum_ov101_021D4550_02;
        }
    }

    GF_ASSERT(FALSE);
    return UnkEnum_ov101_021D4550_00;
}

static void ov101_021D45B0(SlotMachineGameState *gameState)
{
    gameState->unk_34 = LCRNG_Next() % 6;
}

static void ov101_021D45C4(SlotMachineGameState *gameState)
{
    UnkStruct_ov101_021D4714 *v0 = &gameState->unk_120;

    v0->unk_00 = 0;
    v0->unk_04 = 0;
    v0->unk_0C = gameState;
    v0->unk_10 = SysTask_Start(ov101_021D4614, v0, 138);
}

static void ov101_021D45E8(SlotMachineGameState *gameState)
{
    SysTask_Done(gameState->unk_120.unk_10);
}

static void ov101_021D45F8(SlotMachineGameState *gameState)
{
    gameState->unk_120.unk_04 = 0;
    gameState->unk_120.unk_08 = 0;
    gameState->unk_120.unk_00 = 1;
}

static int ov101_021D460C(SlotMachineGameState *gameState)
{
    return gameState->unk_120.unk_04;
}

static void ov101_021D4614(SysTask *param0, void *param1)
{
    int v0;
    UnkStruct_ov101_021D4714 *v1 = param1;
    SlotMachineGameState *gameState = v1->unk_0C;

    switch (v1->unk_00) {
    case 0:
        break;
    case 1:
        ov101_021D4714(v1);
        v1->unk_00++;
        break;
    case 2:
        if (((v1->unk_14 != NULL) && (ov101_021D505C(v1->unk_14) != 1)) || ((v1->unk_18 != NULL) && (ov101_021D505C(v1->unk_18) != 1))) {
            break;
        }

        v1->unk_00++;
    case 3:
        if (ov101_021D55F8(PAD_BUTTON_X) || (gameState->unk_64 == 0)) {
            Sound_PlayEffect(SEQ_SE_DP_DENSI16);
            gameState->unk_60 += gameState->unk_64;

            if (gameState->unk_60 >= 50000) {
                gameState->unk_60 = 50000;
            }

            if (gameState->unk_08 == 1) {
                gameState->unk_14 += gameState->unk_64;
            }

            gameState->unk_64 = 0;

            if (v1->unk_14 != NULL) {
                OverworldAnimManager_Finish(v1->unk_14);
                v1->unk_14 = NULL;
            }

            if (v1->unk_18 != NULL) {
                OverworldAnimManager_Finish(v1->unk_18);
                v1->unk_18 = NULL;
            }

            v1->unk_04 = 1;
            v1->unk_00 = 0;

            return;
        }

        v0 = 0x3;

        if (gSystem.heldKeys & (PAD_BUTTON_A | PAD_BUTTON_B | PAD_BUTTON_X | PAD_BUTTON_Y)) {
            v0 = 0x1;
        }

        v1->unk_08++;

        if ((v1->unk_08 & v0) == 0) {
            gameState->unk_64--;
            gameState->unk_60++;

            if (gameState->unk_60 >= 50000) {
                gameState->unk_60 = 50000;
            }

            Sound_PlayEffect(SEQ_SE_DP_DENSI16);

            if (gameState->unk_08 == 1) {
                gameState->unk_14++;
            }
        }
    }
}

static void ov101_021D4714(UnkStruct_ov101_021D4714 *param0)
{
    int v0;
    SlotMachineGameState *gameState = param0->unk_0C;
    u32 v2 = gameState->unk_48;

    GF_ASSERT(v2 != 0);

    for (v0 = 0; v0 < UnkEnum_ov101_021D4F58_05; v0++, v2 >>= 1) {
        if (v2 & 0x1) {
            if (param0->unk_14 == NULL) {
                param0->unk_14 = ov101_021D5028(gameState, v0, gameState->unk_64);
            } else if (param0->unk_18 == NULL) {
                param0->unk_18 = ov101_021D5028(gameState, v0, gameState->unk_64);
            } else {
                GF_ASSERT(FALSE);
            }
        }
    }
}

static void ov101_021D4764(SlotMachineGameState *gameState)
{
    UnkStruct_ov101_021D4764 *v0 = &gameState->unk_13C;

    v0->unk_00 = 0;
    v0->unk_04 = 0;
    v0->unk_20 = gameState;
    v0->unk_24 = SysTask_Start(ov101_021D4824, v0, 132);
}

static void ov101_021D4788(SlotMachineGameState *gameState)
{
    UnkStruct_ov101_021D4764 *v0 = &gameState->unk_13C;
    SysTask_Done(v0->unk_24);
}

static void ov101_021D4798(SlotMachineGameState *gameState, u32 param1)
{
    UnkStruct_ov101_021D4764 *v0 = &gameState->unk_13C;

    v0->unk_00 = param1;
    v0->unk_04 = 0;
    v0->unk_08 = 0;
    v0->unk_10 = 0;
}

static int ov101_021D47AC(SlotMachineGameState *gameState)
{
    UnkStruct_ov101_021D4764 *v0 = &gameState->unk_13C;
    return v0->unk_08;
}

static void ov101_021D47B4(SlotMachineGameState *gameState)
{
    gameState->unk_13C.unk_0C = 0;
    gameState->unk_13C.unk_38 = ov101_021D7228(gameState);
    gameState->unk_13C.unk_3C = ov101_021D73B4(gameState);
    gameState->unk_13C.unk_40 = ov101_021D7550(gameState);
    gameState->unk_13C.unk_44 = ov101_021D76B4(gameState);
}

static void ov101_021D47F0(SlotMachineGameState *gameState)
{
    gameState->unk_13C.unk_0C = 1;

    OverworldAnimManager_Finish(gameState->unk_13C.unk_38);
    OverworldAnimManager_Finish(gameState->unk_13C.unk_3C);
    OverworldAnimManager_Finish(gameState->unk_13C.unk_40);
    OverworldAnimManager_Finish(gameState->unk_13C.unk_44);
}

static void ov101_021D4824(SysTask *param0, void *param1)
{
    int v0;
    UnkStruct_ov101_021D4764 *v1 = param1;

    int (*const *v2)(UnkStruct_ov101_021D4764 *);

    do {
        v2 = Unk_ov101_021D8774[v1->unk_00];
        v0 = v2[v1->unk_04](v1);
    } while (v0 == 1);
}

static int ov101_021D4844(UnkStruct_ov101_021D4764 *param0)
{
    param0->unk_28 = ov101_021D5D58(param0->unk_20, param0->unk_18);
    param0->unk_04++;

    return 0;
}

static int ov101_021D485C(UnkStruct_ov101_021D4764 *param0)
{
    if (ov101_021D5DC4(param0->unk_28) == 0) {
        return 0;
    }

    ov101_021D5D90(param0->unk_28, UnkEnum_ov101_021D5D90_01);
    param0->unk_04++;

    return 0;
}

static int ov101_021D4880(UnkStruct_ov101_021D4764 *param0)
{
    if (ov101_021D5DC4(param0->unk_28) == 0) {
        return 0;
    }

    ov101_021D5D90(param0->unk_28, UnkEnum_ov101_021D5D90_05);
    param0->unk_08 = 1;
    param0->unk_04++;

    return 0;
}

static int ov101_021D48A8(UnkStruct_ov101_021D4764 *param0)
{
    return 0;
}

static int (*const Unk_ov101_021D8648[])(UnkStruct_ov101_021D4764 *) = {
    ov101_021D48A8,
};

static int (*const Unk_ov101_021D8690[])(UnkStruct_ov101_021D4764 *) = {
    ov101_021D4844,
    ov101_021D485C,
    ov101_021D4880,
    ov101_021D48A8,
};

static int ov101_021D48AC(UnkStruct_ov101_021D4764 *param0)
{
    ov101_021D5D90(param0->unk_28, UnkEnum_ov101_021D5D90_04);
    param0->unk_04++;
    return 0;
}

static int ov101_021D48C4(UnkStruct_ov101_021D4764 *param0)
{
    if (ov101_021D5DC4(param0->unk_28) == 1) {
        OverworldAnimManager_Finish(param0->unk_28);
        param0->unk_08 = 1;
        param0->unk_04++;
    }

    return 0;
}

static int (*const Unk_ov101_021D8678[])(UnkStruct_ov101_021D4764 *work) = {
    ov101_021D48AC,
    ov101_021D48C4,
    ov101_021D48A8,
};

static int ov101_021D48E8(UnkStruct_ov101_021D4764 *param0)
{
    ov101_021D5D90(param0->unk_28, UnkEnum_ov101_021D5D90_02);
    param0->unk_04++;
    return 0;
}

static int ov101_021D4900(UnkStruct_ov101_021D4764 *param0)
{
    if (ov101_021D5DC4(param0->unk_28) == 1) {
        param0->unk_2C = ov101_021D6484(param0->unk_20);
        param0->unk_30 = ov101_021D6764(param0->unk_20, param0->unk_1C);
        param0->unk_04++;
    }

    return 0;
}

static int ov101_021D492C(UnkStruct_ov101_021D4764 *param0)
{
    if (ov101_021D67B0(param0->unk_30) == 1) {
        ov101_021D679C(param0->unk_30, UnkEnum_ov101_021D679C_01);
        ov101_021D5DA4(param0->unk_28, 1);
        param0->unk_04++;
    }

    return 0;
}

static int ov101_021D4954(UnkStruct_ov101_021D4764 *param0)
{
    if (ov101_021D67B0(param0->unk_30) == 1) {
        OverworldAnimManager_Finish(param0->unk_2C);
        param0->unk_08 = 1;
        param0->unk_04++;
    }

    return 0;
}

static int (*const Unk_ov101_021D8714[])(UnkStruct_ov101_021D4764 *) = {
    ov101_021D48E8,
    ov101_021D4900,
    ov101_021D492C,
    ov101_021D4954,
    ov101_021D48A8,
};

static int ov101_021D4978(UnkStruct_ov101_021D4764 *param0)
{
    param0->unk_2C = ov101_021D6484(param0->unk_20);
    ov101_021D679C(param0->unk_30, UnkEnum_ov101_021D679C_02);
    param0->unk_04++;
    return 0;
}

static int ov101_021D4998(UnkStruct_ov101_021D4764 *param0)
{
    if (ov101_021D67B0(param0->unk_30) == 1) {
        OverworldAnimManager_Finish(param0->unk_30);
        OverworldAnimManager_Finish(param0->unk_2C);
        ov101_021D5DA4(param0->unk_28, 0);
        ov101_021D5D90(param0->unk_28, UnkEnum_ov101_021D5D90_03);
        param0->unk_04++;
    }

    return 0;
}

static int ov101_021D49CC(UnkStruct_ov101_021D4764 *param0)
{
    if (ov101_021D5DC4(param0->unk_28) == 1) {
        ov101_021D5D90(param0->unk_28, UnkEnum_ov101_021D5D90_04);
        param0->unk_04++;
    }

    return 0;
}

static int ov101_021D49EC(UnkStruct_ov101_021D4764 *param0)
{
    if (ov101_021D5DC4(param0->unk_28) == 1) {
        OverworldAnimManager_Finish(param0->unk_28);
        param0->unk_08 = 1;
        param0->unk_04++;
    }

    return 0;
}

static int (*const Unk_ov101_021D86EC[])(UnkStruct_ov101_021D4764 *) = {
    ov101_021D4978,
    ov101_021D4998,
    ov101_021D49CC,
    ov101_021D49EC,
    ov101_021D48A8,
};

static int ov101_021D4A10(UnkStruct_ov101_021D4764 *param0)
{
    ov101_021D679C(param0->unk_30, UnkEnum_ov101_021D679C_03);
    param0->unk_34 = ov101_021D6DF0(param0->unk_20);
    param0->unk_10 = 0;
    param0->unk_04++;
    return 0;
}

static int ov101_021D4A30(UnkStruct_ov101_021D4764 *param0)
{
    param0->unk_10++;

    if (param0->unk_10 >= 48) {
        param0->unk_10 = 0;
        param0->unk_04++;
        Sound_PlayPokemonCry(SPECIES_CLEFAIRY, 0);
        ov101_021D679C(param0->unk_30, UnkEnum_ov101_021D679C_04);
    }

    return 0;
}

static int ov101_021D4A5C(UnkStruct_ov101_021D4764 *param0)
{
    if (ov101_021D6E1C(param0->unk_34) == 1) {
        ov101_021D679C(param0->unk_30, UnkEnum_ov101_021D679C_03);
        OverworldAnimManager_Finish(param0->unk_34);
        param0->unk_04++;
        param0->unk_10 = 0;
        param0->unk_08 = 1;
    }

    return 0;
}

static int (*const Unk_ov101_021D86A0[])(UnkStruct_ov101_021D4764 *) = {
    ov101_021D4A10,
    ov101_021D4A30,
    ov101_021D4A5C,
    ov101_021D48A8,
};

static int ov101_021D4A8C(UnkStruct_ov101_021D4764 *param0)
{
    const UnkStruct_ov101_021D87A8 *v0 = &Unk_ov101_021D87A8[param0->unk_20->unk_34];

    param0->unk_04++;
    param0->unk_14 = 0;

    ov101_021D679C(param0->unk_30, v0->unk_0C[param0->unk_14]);

    return 0;
}

static int ov101_021D4AB8(UnkStruct_ov101_021D4764 *param0)
{
    int v0, v1 = 0;

    for (v0 = 0; v0 < 3; v0++) {
        if (param0->unk_20->unk_7C[v0] != 1) {
            v1++;
        }
    }

    if ((param0->unk_14 < 2) && (param0->unk_14 != v1)) {
        const UnkStruct_ov101_021D87A8 *v2 = &Unk_ov101_021D87A8[param0->unk_20->unk_34];

        param0->unk_14 = v1;
        ov101_021D679C(param0->unk_30, v2->unk_0C[param0->unk_14]);
    }

    return 0;
}

static int (*const Unk_ov101_021D8684[])(UnkStruct_ov101_021D4764 *) = {
    ov101_021D4A8C,
    ov101_021D4AB8,
    ov101_021D48A8,
};

static int ov101_021D4AFC(UnkStruct_ov101_021D4764 *param0)
{
    ov101_021D679C(param0->unk_30, UnkEnum_ov101_021D679C_03);
    param0->unk_04++;
    return 0;
}

static int (*const Unk_ov101_021D8654[])(UnkStruct_ov101_021D4764 *) = {
    ov101_021D4AFC,
    ov101_021D48A8
};

static int ov101_021D4B14(UnkStruct_ov101_021D4764 *param0)
{
    ov101_021D47F0(param0->unk_20);
    param0->unk_2C = ov101_021D6484(param0->unk_20);
    ov101_021D679C(param0->unk_30, UnkEnum_ov101_021D679C_02);
    param0->unk_04++;
    return 0;
}

static int ov101_021D4B38(UnkStruct_ov101_021D4764 *param0)
{
    if (ov101_021D67B0(param0->unk_30) == 1) {
        OverworldAnimManager_Finish(param0->unk_30);
        OverworldAnimManager_Finish(param0->unk_2C);
        ov101_021D5DA4(param0->unk_28, 0);
        ov101_021D5D90(param0->unk_28, UnkEnum_ov101_021D5D90_03);
        param0->unk_04++;
    }

    return 0;
}

static int ov101_021D4B6C(UnkStruct_ov101_021D4764 *param0)
{
    if (ov101_021D5DC4(param0->unk_28) == 1) {
        ov101_021D72D4(param0->unk_20);
        ov101_021D7460(param0->unk_20);
        ov101_021D77E4(param0->unk_20, UnkEnum_ov101_021D77E4_00);
        ov101_021D77E4(param0->unk_20, UnkEnum_ov101_021D77E4_01);
        param0->unk_04++;
    }

    return 0;
}

static int ov101_021D4BA0(UnkStruct_ov101_021D4764 *param0)
{
    param0->unk_10++;

    if (param0->unk_10 >= 45) {
        param0->unk_10 = 0;
        ov101_021D5D90(param0->unk_28, UnkEnum_ov101_021D5D90_04);
        param0->unk_04++;
    }

    return 0;
}

static int ov101_021D4BC4(UnkStruct_ov101_021D4764 *param0)
{
    if (ov101_021D5DC4(param0->unk_28) == 1) {
        OverworldAnimManager_Finish(param0->unk_28);
        param0->unk_08 = 1;
        param0->unk_04++;
    }

    return 0;
}

static int (*const Unk_ov101_021D8728[])(UnkStruct_ov101_021D4764 *) = {
    ov101_021D4B14,
    ov101_021D4B38,
    ov101_021D4B6C,
    ov101_021D4BA0,
    ov101_021D4BC4,
    ov101_021D48A8,
};

static int ov101_021D4BE8(UnkStruct_ov101_021D4764 *param0)
{
    ov101_021D679C(param0->unk_30, UnkEnum_ov101_021D679C_04);
    param0->unk_08 = 1;
    param0->unk_04++;
    return 0;
}

static int (*const Unk_ov101_021D8664[])(UnkStruct_ov101_021D4764 *) = {
    ov101_021D4BE8,
    ov101_021D48A8
};

static int ov101_021D4C04(UnkStruct_ov101_021D4764 *param0)
{
    ov101_021D679C(param0->unk_30, UnkEnum_ov101_021D679C_08);
    param0->unk_08 = 1;
    param0->unk_04++;
    return 0;
}

static int (*const Unk_ov101_021D865C[])(UnkStruct_ov101_021D4764 *) = {
    ov101_021D4C04,
    ov101_021D48A8,
};

static int ov101_021D4C20(UnkStruct_ov101_021D4764 *param0)
{
    ov101_021D5D90(param0->unk_28, UnkEnum_ov101_021D5D90_06);
    param0->unk_04++;
    param0->unk_08 = 1;
    return 0;
}

static int (*const Unk_ov101_021D864C[])(UnkStruct_ov101_021D4764 *) = {
    ov101_021D4C20,
    ov101_021D48A8
};

static int ov101_021D4C3C(UnkStruct_ov101_021D4764 *param0)
{
    param0->unk_2C = ov101_021D6484(param0->unk_20);
    ov101_021D679C(param0->unk_30, UnkEnum_ov101_021D679C_02);
    param0->unk_0C = 1;
    param0->unk_04++;
    return 0;
}

static int ov101_021D4C60(UnkStruct_ov101_021D4764 *param0)
{
    if (ov101_021D67B0(param0->unk_30) == 1) {
        OverworldAnimManager_Finish(param0->unk_2C);
        OverworldAnimManager_Finish(param0->unk_30);
        ov101_021D5DA4(param0->unk_28, 0);
        ov101_021D5D90(param0->unk_28, UnkEnum_ov101_021D5D90_03);
        param0->unk_10 = 0;
        param0->unk_04++;
    }

    return 0;
}

static int ov101_021D4C98(UnkStruct_ov101_021D4764 *param0)
{
    param0->unk_10++;

    if (param0->unk_10 >= 30) {
        param0->unk_10 = 0;
        param0->unk_04++;
        ov101_021D5D90(param0->unk_28, UnkEnum_ov101_021D5D90_02);
    }

    return 0;
}

static int ov101_021D4CBC(UnkStruct_ov101_021D4764 *param0)
{
    if (ov101_021D5DC4(param0->unk_28) == 1) {
        param0->unk_2C = ov101_021D6484(param0->unk_20);
        param0->unk_30 = ov101_021D6764(param0->unk_20, param0->unk_1C);
        param0->unk_0C = 0;
        param0->unk_04++;
    }

    return 0;
}

static int ov101_021D4CEC(UnkStruct_ov101_021D4764 *param0)
{
    if (ov101_021D67B0(param0->unk_30) == 1) {
        ov101_021D679C(param0->unk_30, UnkEnum_ov101_021D679C_01);
        ov101_021D5DA4(param0->unk_28, 1);
        param0->unk_04++;
    }

    return 0;
}

static int ov101_021D4D14(UnkStruct_ov101_021D4764 *param0)
{
    if (ov101_021D67B0(param0->unk_30) == 1) {
        OverworldAnimManager_Finish(param0->unk_2C);
        param0->unk_08 = 1;
        param0->unk_04++;
    }

    return 0;
}

static int (*const Unk_ov101_021D8758[])(UnkStruct_ov101_021D4764 *) = {
    ov101_021D4C3C,
    ov101_021D4C60,
    ov101_021D4C98,
    ov101_021D4CBC,
    ov101_021D4CEC,
    ov101_021D4D14,
    ov101_021D48A8
};

static int (*const *const Unk_ov101_021D8774[13])(UnkStruct_ov101_021D4764 *) = {
    Unk_ov101_021D8648,
    Unk_ov101_021D8690,
    Unk_ov101_021D8678,
    Unk_ov101_021D8714,
    Unk_ov101_021D86EC,
    Unk_ov101_021D86A0,
    Unk_ov101_021D8684,
    Unk_ov101_021D8654,
    Unk_ov101_021D8728,
    Unk_ov101_021D8664,
    Unk_ov101_021D865C,
    Unk_ov101_021D864C,
    Unk_ov101_021D8758,
};

static void ov101_021D4D38(SlotMachineGameState *gameState)
{
    void *v0;
    NNSG2dPaletteData *v1;
    UnkStruct_ov101_021D4F58 *v2 = &gameState->unk_184;

    v2->unk_00 = gameState;
    v0 = ov101_021D19E4(gameState, 3, 0);

    NNS_G2dGetUnpackedPaletteData(v0, &v1);

    ov101_021D4EA8(v1, 0x1, v2->unk_04);
    ov101_021D4EA8(v1, 0x2, v2->unk_A4[UnkEnum_ov101_021D4F58_00]);
    ov101_021D4EA8(v1, 0x3, v2->unk_A4[UnkEnum_ov101_021D4F58_01]);
    ov101_021D4EA8(v1, 0x3, v2->unk_A4[UnkEnum_ov101_021D4F58_02]);
    ov101_021D4EA8(v1, 0x4, v2->unk_A4[UnkEnum_ov101_021D4F58_03]);
    ov101_021D4EA8(v1, 0x4, v2->unk_A4[UnkEnum_ov101_021D4F58_04]);

    Heap_Free(v0);

    v0 = ov101_021D19E4(gameState, 5, 0);
    NNS_G2dGetUnpackedPaletteData(v0, &v1);
    ov101_021D4EA8(v1, 0, v2->unk_24);
    Heap_Free(v0);

    v0 = ov101_021D19E4(gameState, 6, 0);
    NNS_G2dGetUnpackedPaletteData(v0, &v1);
    ov101_021D4EA8(v1, 0, v2->unk_44);
    Heap_Free(v0);

    v0 = ov101_021D19E4(gameState, 7, 0);
    NNS_G2dGetUnpackedPaletteData(v0, &v1);
    ov101_021D4EA8(v1, 0, v2->unk_64);
    Heap_Free(v0);

    v0 = ov101_021D19E4(gameState, 74, 0);
    NNS_G2dGetUnpackedPaletteData(v0, &v1);
    ov101_021D4EA8(v1, 0, v2->unk_144[UnkEnum_ov101_021D4F58_00]);
    Heap_Free(v0);

    v0 = ov101_021D19E4(gameState, 75, 0);
    NNS_G2dGetUnpackedPaletteData(v0, &v1);
    ov101_021D4EA8(v1, 0, v2->unk_144[UnkEnum_ov101_021D4F58_01]);
    ov101_021D4EA8(v1, 0, v2->unk_144[UnkEnum_ov101_021D4F58_02]);
    Heap_Free(v0);

    v0 = ov101_021D19E4(gameState, 76, 0);
    NNS_G2dGetUnpackedPaletteData(v0, &v1);
    ov101_021D4EA8(v1, 0, v2->unk_144[UnkEnum_ov101_021D4F58_03]);
    ov101_021D4EA8(v1, 0, v2->unk_144[UnkEnum_ov101_021D4F58_04]);
    Heap_Free(v0);
}

static void ov101_021D4EA4(SlotMachineGameState *gameState)
{
    return;
}

static void ov101_021D4EA8(NNSG2dPaletteData *param0, int param1, u16 *param2)
{
    int v0;
    u16 *v1 = param0->pRawData;

    v1 = &v1[param1 * 16];

    for (v0 = 0; v0 < 16; v0++) {
        param2[v0] = v1[v0];
    }
}

static void ov101_021D4EC0(u16 param0, u16 param1, u16 param2, u16 *param3)
{
    const UnkStruct_ov101_021D4EC0 *v0 = (UnkStruct_ov101_021D4EC0 *)&param0;
    const UnkStruct_ov101_021D4EC0 *v1 = (UnkStruct_ov101_021D4EC0 *)&param1;

    if (param2 > 16) {
        param2 = 16;
    }

    (*param3) = (v0->unk_00_0 + ((v1->unk_00_0 - v0->unk_00_0) * param2 >> 4)) | ((v0->unk_00_5 + ((v1->unk_00_5 - v0->unk_00_5) * param2 >> 4)) << 5) | ((v0->unk_00_10 + ((v1->unk_00_10 - v0->unk_00_10) * param2 >> 4)) << 10);
}

static void ov101_021D4F18(const u16 *param0, const u16 *param1, u16 param2, u16 *param3)
{
    int v0 = 0;

    do {
        ov101_021D4EC0(param0[v0], param1[v0], param2, &param3[v0]);
        v0++;
    } while (v0 < 16);
}

static void ov101_021D4F40(SlotMachineGameState *gameState, u32 param1, int param2, u16 *param3)
{
    Bg_LoadPalette(param1, param3, 32, 32 * param2);
}

static int Unk_ov101_021D9E60[UnkEnum_ov101_021D4F58_05] = {
    0x2,
    0x3,
    0xc,
    0x4,
    0xb,
};

static void ov101_021D4F58(SlotMachineGameState *gameState, UnkEnum_ov101_021D4F58 param1)
{
    UnkStruct_ov101_021D4F58 *v0 = &gameState->unk_184;
    int v1 = Unk_ov101_021D9E60[param1];

    ov101_021D4F40(gameState, 1, v1, v0->unk_A4[param1]);
}

static void ov101_021D4F78(SlotMachineGameState *gameState, UnkEnum_ov101_021D4F58 param1)
{
    UnkStruct_ov101_021D4F58 *v0 = &gameState->unk_184;
    int v1 = Unk_ov101_021D9E60[param1];
    const u16 *v2 = v0->unk_A4[param1];
    const u16 *v3 = v0->unk_144[param1];
    u16 *v4 = v0->unk_1E4[param1];

    ov101_021D4F18(v2, v3, 10, v4);
    ov101_021D4F40(gameState, 1, v1, v4);
}

static void ov101_021D4FB8(SlotMachineGameState *gameState, UnkEnum_ov101_021D4F58 param1)
{
    UnkStruct_ov101_021D4F58 *v0 = &gameState->unk_184;
    int v1 = Unk_ov101_021D9E60[param1];
    const u16 *v2 = v0->unk_A4[param1];
    const u16 *v3 = v0->unk_144[param1];
    u16 *v4 = v0->unk_1E4[param1];

    ov101_021D4F18(v2, v3, 12, v4);
    ov101_021D4F40(gameState, 1, v1, v4);
}

static void ov101_021D4FF8(SlotMachineGameState *gameState)
{
    int v0 = UnkEnum_ov101_021D4F58_00;

    do {
        ov101_021D4F58(gameState, v0);
        v0++;
    } while (v0 < UnkEnum_ov101_021D4F58_05);
}

static void ov101_021D5010(SlotMachineGameState *gameState)
{
    int v0 = UnkEnum_ov101_021D4F58_00;

    do {
        ov101_021D4F78(gameState, v0);
        v0++;
    } while (v0 < UnkEnum_ov101_021D4F58_05);
}

static const OverworldAnimManagerFuncs Unk_ov101_021D86B0;

static OverworldAnimManager *ov101_021D5028(SlotMachineGameState *gameState, UnkEnum_ov101_021D4F58 param1, u32 param2)
{
    OverworldAnimManager *v0;
    VecFx32 v1 = { 0, 0, 0 };
    UnkStruct_ov101_021D5068 v2;

    v2.unk_00 = param1;
    v2.unk_04 = param2;
    v2.unk_08 = gameState;

    v0 = OverworldAnimManagerList_InitManager(gameState->unk_44C, &Unk_ov101_021D86B0, &v1, 0, &v2, 143);

    return v0;
}

static int ov101_021D505C(OverworldAnimManager *param0)
{
    UnkStruct_ov101_021D505C *v0 = OverworldAnimManager_GetFuncsContext(param0);
    return v0->unk_0C;
}

static int ov101_021D5068(OverworldAnimManager *param0, void *param1)
{
    const UnkStruct_ov101_021D5068 *v0;
    UnkStruct_ov101_021D505C *v1 = param1;

    v0 = (const UnkStruct_ov101_021D5068 *)OverworldAnimManager_GetUserData(param0);
    v1->unk_1C = v0->unk_08;
    v1->unk_10 = v0->unk_00;
    v1->unk_14 = v0->unk_04;
    v1->unk_20 = &v1->unk_1C->unk_184;

    return 1;
}

static void ov101_021D508C(OverworldAnimManager *param0, void *param1)
{
    UnkStruct_ov101_021D505C *v0 = param1;
    ov101_021D4F58(v0->unk_1C, v0->unk_10);
}

static void ov101_021D5098(OverworldAnimManager *param0, void *param1)
{
    int v0;
    UnkStruct_ov101_021D505C *v1 = param1;
    int v2 = Unk_ov101_021D9E60[v1->unk_10];
    u16 *v3 = v1->unk_20->unk_1E4[v1->unk_10];
    const u16 *v4 = v1->unk_20->unk_A4[v1->unk_10];
    const u16 *v5 = v1->unk_20->unk_144[v1->unk_10];

    switch (v1->unk_00) {
    case 0:
        v1->unk_18 += 0x4000;

        if (v1->unk_18 > (FX32_ONE * 16)) {
            v1->unk_18 = (FX32_ONE * 16);
        }

        v0 = ((v1->unk_18) / FX32_ONE);

        if (v0 == 16) {
            v1->unk_00++;
        }

        ov101_021D4F18(v4, v5, v0, v3);
        ov101_021D4F40(v1->unk_1C, 1, v2, v3);
        break;
    case 1:
        v1->unk_18 -= 0x4000;

        if (v1->unk_18 < (FX32_ONE * 0)) {
            v1->unk_18 = (FX32_ONE * 0);
        }

        v0 = ((v1->unk_18) / FX32_ONE);

        if (v0 == 0) {
            v1->unk_04++;

            if (v1->unk_04 >= 4) {
                if (v1->unk_14) {
                    v1->unk_00++;
                    v1->unk_0C = 1;
                } else {
                    v1->unk_00 = 4;
                    v1->unk_0C = 1;
                }
            } else {
                v1->unk_00--;
            }
        }

        ov101_021D4F18(v4, v5, v0, v3);
        ov101_021D4F40(v1->unk_1C, 1, v2, v3);
        break;
    case 2:
        v1->unk_18 += 0x8000;

        if (v1->unk_18 > (FX32_ONE * 16)) {
            v1->unk_18 = (FX32_ONE * 16);
        }

        v0 = ((v1->unk_18) / FX32_ONE);

        if (v0 == 16) {
            v1->unk_00++;
        }

        ov101_021D4F18(v4, v5, v0, v3);
        ov101_021D4F40(v1->unk_1C, 1, v2, v3);
        break;
    case 3:
        v1->unk_18 -= 0x8000;

        if (v1->unk_18 < (FX32_ONE * 0)) {
            v1->unk_18 = (FX32_ONE * 0);
        }

        v0 = ((v1->unk_18) / FX32_ONE);

        if (v0 == 0) {
            v1->unk_00--;
        }

        ov101_021D4F18(v4, v5, v0, v3);
        ov101_021D4F40(v1->unk_1C, 1, v2, v3);
        break;
    case 4:
        break;
    }
}

static const OverworldAnimManagerFuncs Unk_ov101_021D86B0 = {
    sizeof(UnkStruct_ov101_021D505C),
    ov101_021D5068,
    ov101_021D508C,
    ov101_021D5098,
    OverworldAnimManager_DummyRenderFunc
};

static const OverworldAnimManagerFuncs Unk_ov101_021D8700;

static void ov101_021D5200(SlotMachineGameState *gameState)
{
    VecFx32 v0 = { 0, 0, 0 };

    GF_ASSERT(gameState->unk_120.unk_14 == NULL);
    gameState->unk_120.unk_14 = OverworldAnimManagerList_InitManager(gameState->unk_44C, &Unk_ov101_021D8700, &v0, 0, gameState, 143);
}

static void ov101_021D5244(SlotMachineGameState *gameState)
{
    if (gameState->unk_120.unk_14 != NULL) {
        OverworldAnimManager_Finish(gameState->unk_120.unk_14);
        gameState->unk_120.unk_14 = NULL;
    }

    ov101_021D4FF8(gameState);
}

#define LB_WAIT_DATA(wait) (1 << 5), (FX32_ONE * (wait)), 0, 0

static const UnkStruct_ov101_021D8938 Unk_ov101_021D8938[] = {
    { LB_WAIT_DATA(30) },
    { (1 << 0), (FX32_ONE * 0), (FX32_ONE * 14), 0x4000 },
    { LB_WAIT_DATA(2) },
    { (1 << 0), (FX32_ONE * 14), (FX32_ONE * 0), 0x4000 },
    { LB_WAIT_DATA(8) },
    { (1 << 1) | (1 << 2), (FX32_ONE * 0), (FX32_ONE * 14), 0x4000 },
    { LB_WAIT_DATA(2) },
    { (1 << 1) | (1 << 2), (FX32_ONE * 14), (FX32_ONE * 0), 0x4000 },
    { LB_WAIT_DATA(8) },
    { (1 << 3) | (1 << 4), (FX32_ONE * 0), (FX32_ONE * 14), 0x4000 },
    { LB_WAIT_DATA(2) },
    { (1 << 3) | (1 << 4), (FX32_ONE * 14), (FX32_ONE * 0), 0x4000 },
    { LB_WAIT_DATA(16) },
    { (1 << 3) | (1 << 4), (FX32_ONE * 0), (FX32_ONE * 14), 0x4000 },
    { LB_WAIT_DATA(2) },
    { (1 << 3) | (1 << 4), (FX32_ONE * 14), (FX32_ONE * 0), 0x4000 },
    { LB_WAIT_DATA(8) },
    { (1 << 1) | (1 << 2), (FX32_ONE * 0), (FX32_ONE * 14), 0x4000 },
    { LB_WAIT_DATA(2) },
    { (1 << 1) | (1 << 2), (FX32_ONE * 14), (FX32_ONE * 0), 0x4000 },
    { LB_WAIT_DATA(8) },
    { (1 << 0), (FX32_ONE * 0), (FX32_ONE * 14), 0x4000 },
    { LB_WAIT_DATA(2) },
    { (1 << 0), (FX32_ONE * 14), (FX32_ONE * 0), 0x4000 },
    { LB_WAIT_DATA(16) },
    { (1 << 1), (FX32_ONE * 0), (FX32_ONE * 14), 0x4000 },
    { LB_WAIT_DATA(2) },
    { (1 << 1), (FX32_ONE * 14), (FX32_ONE * 0), 0x4000 },
    { LB_WAIT_DATA(8) },
    { (1 << 4), (FX32_ONE * 0), (FX32_ONE * 14), 0x4000 },
    { LB_WAIT_DATA(2) },
    { (1 << 4), (FX32_ONE * 14), (FX32_ONE * 0), 0x4000 },
    { LB_WAIT_DATA(8) },
    { (1 << 2), (FX32_ONE * 0), (FX32_ONE * 14), 0x4000 },
    { LB_WAIT_DATA(2) },
    { (1 << 2), (FX32_ONE * 14), (FX32_ONE * 0), 0x4000 },
    { LB_WAIT_DATA(8) },
    { (1 << 3), (FX32_ONE * 0), (FX32_ONE * 14), 0x4000 },
    { LB_WAIT_DATA(2) },
    { (1 << 3), (FX32_ONE * 14), (FX32_ONE * 0), 0x4000 },
    { LB_WAIT_DATA(8) },
    { (1 << 0), (FX32_ONE * 0), (FX32_ONE * 14), 0x4000 },
    { LB_WAIT_DATA(2) },
    { (1 << 0), (FX32_ONE * 14), (FX32_ONE * 0), 0x4000 },
    { LB_WAIT_DATA(16) },
    { (1 << 3), (FX32_ONE * 0), (FX32_ONE * 14), 0x4000 },
    { LB_WAIT_DATA(1) },
    { (1 << 3), (FX32_ONE * 14), (FX32_ONE * 0), 0x4000 },
    { LB_WAIT_DATA(2) },
    { (1 << 1), (FX32_ONE * 0), (FX32_ONE * 14), 0x4000 },
    { LB_WAIT_DATA(1) },
    { (1 << 1), (FX32_ONE * 14), (FX32_ONE * 0), 0x4000 },
    { LB_WAIT_DATA(2) },
    { (1 << 0), (FX32_ONE * 0), (FX32_ONE * 14), 0x4000 },
    { LB_WAIT_DATA(1) },
    { (1 << 0), (FX32_ONE * 14), (FX32_ONE * 0), 0x4000 },
    { LB_WAIT_DATA(2) },
    { (1 << 2), (FX32_ONE * 0), (FX32_ONE * 14), 0x4000 },
    { LB_WAIT_DATA(1) },
    { (1 << 2), (FX32_ONE * 14), (FX32_ONE * 0), 0x4000 },
    { LB_WAIT_DATA(2) },
    { (1 << 4), (FX32_ONE * 0), (FX32_ONE * 14), 0x4000 },
    { LB_WAIT_DATA(1) },
    { (1 << 4), (FX32_ONE * 14), (FX32_ONE * 0), 0x4000 },
    { LB_WAIT_DATA(8) },
    { (1 << 2), (FX32_ONE * 0), (FX32_ONE * 14), 0x4000 },
    { LB_WAIT_DATA(1) },
    { (1 << 2), (FX32_ONE * 14), (FX32_ONE * 0), 0x4000 },
    { LB_WAIT_DATA(2) },
    { (1 << 0), (FX32_ONE * 0), (FX32_ONE * 14), 0x4000 },
    { LB_WAIT_DATA(1) },
    { (1 << 0), (FX32_ONE * 14), (FX32_ONE * 0), 0x4000 },
    { LB_WAIT_DATA(2) },
    { (1 << 1), (FX32_ONE * 0), (FX32_ONE * 14), 0x4000 },
    { LB_WAIT_DATA(1) },
    { (1 << 1), (FX32_ONE * 14), (FX32_ONE * 0), 0x4000 },
    { LB_WAIT_DATA(2) },
    { (1 << 3), (FX32_ONE * 0), (FX32_ONE * 14), 0x4000 },
    { LB_WAIT_DATA(1) },
    { (1 << 3), (FX32_ONE * 14), (FX32_ONE * 0), 0x4000 },
    { LB_WAIT_DATA(16) },
    { (1 << 6), 1, 0, 0 },
};

static void ov101_021D5268(UnkStruct_ov101_021D5388 *param0)
{
    u32 v0;
    int v1, v2, v3;
    u16 *v4;
    const u16 *v5, *v6;
    const UnkStruct_ov101_021D8938 *v7 = &Unk_ov101_021D8938[param0->unk_04];

    for (v1 = 0, v2 = 1, v0 = (1 << 0); v0 <= (1 << 4); v1++, v0 <<= 1) {
        if (v7->unk_00 & v0) {
            if (param0->unk_08 == 0) {
                param0->unk_14[v1] = v7->unk_04;
                v2 = 0;
            } else {
                if (v7->unk_04 < v7->unk_08) {
                    param0->unk_14[v1] += v7->unk_0C;

                    if (param0->unk_14[v1] >= v7->unk_08) {
                        param0->unk_14[v1] = v7->unk_08;
                    } else {
                        v2 = 0;
                    }
                } else {
                    param0->unk_14[v1] -= v7->unk_0C;

                    if (param0->unk_14[v1] <= v7->unk_08) {
                        param0->unk_14[v1] = v7->unk_08;
                    } else {
                        v2 = 0;
                    }
                }
            }

            v3 = Unk_ov101_021D9E60[v1];
            v5 = param0->unk_2C->unk_A4[v1];
            v6 = param0->unk_2C->unk_144[v1];
            v4 = param0->unk_2C->unk_1E4[v1];

            ov101_021D4F18(v5, v6, ((param0->unk_14[v1]) / FX32_ONE), v4);
            ov101_021D4F40(param0->unk_28, 1, v3, v4);
        }
    }

    for (; v0 <= (1 << 5); v0 <<= 1) {
        if (v7->unk_00 & (1 << 5)) {
            param0->unk_0C += FX32_ONE;

            if (param0->unk_0C >= v7->unk_04) {
                param0->unk_0C = 0;
            } else {
                v2 = 0;
            }
        }
    }

    param0->unk_08 = 1;

    if (v2 == 1) {
        param0->unk_08 = 0;
        param0->unk_04++;
        v7 = &Unk_ov101_021D8938[param0->unk_04];

        if (v7->unk_00 == (1 << 6)) {
            param0->unk_04 = (int)v7->unk_04;
            param0->unk_04 = 0;
        }
    }
}

static int ov101_021D5388(OverworldAnimManager *param0, void *param1)
{
    UnkStruct_ov101_021D5388 *v0 = param1;

    v0->unk_28 = (SlotMachineGameState *)OverworldAnimManager_GetUserData(param0);
    v0->unk_2C = &v0->unk_28->unk_184;

    return 1;
}

static void ov101_021D53A0(OverworldAnimManager *param0, void *param1)
{
    return;
}

static void ov101_021D53A4(OverworldAnimManager *param0, void *param1)
{
    UnkStruct_ov101_021D5388 *v0 = param1;
    ov101_021D5268(v0);
}

static const OverworldAnimManagerFuncs Unk_ov101_021D8700 = {
    sizeof(UnkStruct_ov101_021D5388),
    ov101_021D5388,
    ov101_021D53A0,
    ov101_021D53A4,
    OverworldAnimManager_DummyRenderFunc
};

static void ov101_021D53B0(SlotMachineGameState *gameState)
{
    UnkStruct_ov101_021D53B0 *v0 = Heap_AllocAtEnd(HEAP_ID_79, sizeof(UnkStruct_ov101_021D53B0));

    v0->unk_00 = 0;
    v0->unk_04 = 0;
    v0->unk_0C = gameState;

    SysTask_Start(ov101_021D542C, v0, 143);
}

static void ov101_021D53D4(SlotMachineGameState *gameState)
{
    UnkStruct_ov101_021D53B0 *v0 = Heap_AllocAtEnd(HEAP_ID_79, sizeof(UnkStruct_ov101_021D53B0));

    v0->unk_00 = 0;
    v0->unk_04 = 0;
    v0->unk_0C = gameState;

    SysTask_Start(ov101_021D548C, v0, 143);
}

static void ov101_021D53F8(SlotMachineGameState *gameState, int param1)
{
    UnkStruct_ov101_021D53B0 *v0 = Heap_AllocAtEnd(HEAP_ID_79, sizeof(UnkStruct_ov101_021D53B0));

    v0->unk_00 = 0;
    v0->unk_08 = param1;
    v0->unk_04 = (FX32_ONE * 8);
    v0->unk_0C = gameState;

    SysTask_Start(ov101_021D54EC, v0, 143);
    Sound_PlayEffect(SEQ_SE_DP_025);
}

static void ov101_021D542C(SysTask *param0, void *param1)
{
    UnkStruct_ov101_021D53B0 *v0 = param1;
    UnkStruct_ov101_021D4F58 *v1 = &v0->unk_0C->unk_184;
    const u16 *v2 = v1->unk_04;
    const u16 *v3 = v1->unk_24;
    u16 *v4 = v1->unk_84;
    u16 v5;

    v0->unk_04 += 0x800;
    v5 = ((v0->unk_04) / FX32_ONE);

    if (v5 > 16) {
        v5 = 16;
    }

    ov101_021D4F18(v2, v3, v5, v4);
    ov101_021D4F40(v0->unk_0C, 7, 0x1, v4);

    if ((v5 == 16) || (v0->unk_0C->unk_00 == 63)) {
        Heap_Free(v0);
        SysTask_Done(param0);
    }
}

static void ov101_021D548C(SysTask *param0, void *param1)
{
    UnkStruct_ov101_021D53B0 *v0 = param1;
    UnkStruct_ov101_021D4F58 *v1 = &v0->unk_0C->unk_184;
    const u16 *v2 = v1->unk_24;
    const u16 *v3 = v1->unk_04;
    u16 *v4 = v1->unk_84;
    u16 v5;

    v0->unk_04 += 0x800;
    v5 = ((v0->unk_04) / FX32_ONE);

    if (v5 > 16) {
        v5 = 16;
    }

    ov101_021D4F18(v2, v3, v5, v4);
    ov101_021D4F40(v0->unk_0C, 7, 0x1, v4);

    if ((v5 == 16) || (v0->unk_0C->unk_00 == 63)) {
        Heap_Free(v0);
        SysTask_Done(param0);
    }
}

static void ov101_021D54EC(SysTask *param0, void *param1)
{
    UnkStruct_ov101_021D53B0 *v0 = param1;
    UnkStruct_ov101_021D4F58 *v1 = &v0->unk_0C->unk_184;
    const u16 *v2, *v3 = v1->unk_24;
    u16 *v4 = v1->unk_84;
    int v5;

    if (v0->unk_0C->unk_00 == 63) {
        Heap_Free(v0);
        SysTask_Done(param0);
        return;
    }

    if (v0->unk_08 == 0) {
        v2 = v1->unk_44;
    } else {
        v2 = v1->unk_64;
    }

    switch (v0->unk_00) {
    case 0:
        v0->unk_04 += 0x1000;
        v5 = ((v0->unk_04) / FX32_ONE);

        if (v5 > 16) {
            v5 = 16;
            v0->unk_00++;
        }

        ov101_021D4F18(v3, v2, v5, v4);
        ov101_021D4F40(v0->unk_0C, 7, 0x1, v4);
        break;
    case 1:
        v0->unk_04 -= 0x400;
        v5 = ((v0->unk_04) / FX32_ONE);

        if (v5 < 0) {
            v5 = 0;
        }

        ov101_021D4F18(v3, v2, v5, v4);
        ov101_021D4F40(v0->unk_0C, 7, 0x1, v4);

        if (v5 == 0) {
            Heap_Free(v0);
            SysTask_Done(param0);
        }
    }
}

UnkEnum_ov101_021D9688 ov101_021D55A4(SlotMachineGameState *gameState, UnkEnum_ov101_021D2BDC param1, int param2)
{
    int v0 = (gameState->unk_A8[param1] + param2) % 21;

    if (v0 < 0) {
        v0 = 21 + v0;
    }

    return Unk_ov101_021D9688[param1][v0];
}

UnkEnum_ov101_021D9688 ov101_021D55D4(SlotMachineGameState *gameState, UnkEnum_ov101_021D2BDC param1, int param2)
{
    int v0 = 0;

    if (gameState->unk_90[param1] % (FX32_ONE * 32)) {
        v0--;
    }

    return ov101_021D55A4(gameState, param1, param2 + v0);
}

static int ov101_021D55F8(u32 gameState)
{
    u32 v0 = gSystem.pressedKeys & gameState;

    if (v0 == gameState) {
        return 2;
    }

    if (v0 & gameState) {
        return 1;
    }

    return 0;
}

static UnkEnum_ov101_021D9688 ov101_021D5618(u32 param0)
{
    if (param0 & ((1 << 0) | (1 << 1))) {
        return 2;
    }

    if (param0 & ((1 << 2) | (1 << 3))) {
        return 3;
    }

    if (param0 & ((1 << 4) | (1 << 5))) {
        return 4;
    }

    if (param0 & ((1 << 6) | (1 << 7))) {
        return 5;
    }

    if (param0 & (1 << 8)) {
        return 1;
    }

    if (param0 & (1 << 9)) {
        return 0;
    }

    return 6;
}

static UnkEnum_ov101_021D9688 ov101_021D5660(SlotMachineGameState *gameState)
{
    u32 v0 = ov101_021D55D4(gameState, 0, 1);
    u32 v1 = ov101_021D55D4(gameState, 1, 1);
    u32 v2 = ov101_021D55D4(gameState, 2, 1);

    if ((v0 == 3) || ((v0 == v1) && (v0 == v2))) {
        return v0;
    }

    return 6;
}

static UnkEnum_ov101_021D9688 ov101_021D5698(SlotMachineGameState *gameState)
{
    u32 v0 = ov101_021D55D4(gameState, 0, 2);
    u32 v1 = ov101_021D55D4(gameState, 1, 2);
    u32 v2 = ov101_021D55D4(gameState, 2, 2);

    if ((v0 == 3) || ((v0 == v1) && (v0 == v2))) {
        return v0;
    }

    return 6;
}

static UnkEnum_ov101_021D9688 ov101_021D56D0(SlotMachineGameState *gameState)
{
    u32 v0 = ov101_021D55D4(gameState, 0, 3);
    u32 v1 = ov101_021D55D4(gameState, 1, 3);
    u32 v2 = ov101_021D55D4(gameState, 2, 3);

    if ((v0 == 3) || ((v0 == v1) && (v0 == v2))) {
        return v0;
    }

    return 6;
}

static UnkEnum_ov101_021D9688 ov101_021D5708(SlotMachineGameState *gameState)
{
    u32 v0 = ov101_021D55D4(gameState, 0, 1);
    u32 v1 = ov101_021D55D4(gameState, 1, 2);
    u32 v2 = ov101_021D55D4(gameState, 2, 3);

    if ((v0 == 3) || ((v0 == v1) && (v0 == v2))) {
        return v0;
    }

    return 6;
}

static UnkEnum_ov101_021D9688 ov101_021D5740(SlotMachineGameState *gameState)
{
    u32 v0 = ov101_021D55D4(gameState, 0, 3);
    u32 v1 = ov101_021D55D4(gameState, 1, 2);
    u32 v2 = ov101_021D55D4(gameState, 2, 1);

    if ((v0 == 3) || ((v0 == v1) && (v0 == v2))) {
        return v0;
    }

    return 6;
}

static UnkEnum_ov101_021D9688 ov101_021D5778(SlotMachineGameState *gameState, u32 param1, u32 *param2)
{
    u32 v0, v1;

    *param2 = 0;

    v1 = 6;
    v0 = ov101_021D5660(gameState);

    if (v0 != 6) {
        v1 = v0;
        *param2 |= (1 << 1);
    }

    v0 = ov101_021D5698(gameState);

    if (v0 != 6) {
        v1 = v0;
        *param2 |= (1 << 0);
    }

    v0 = ov101_021D56D0(gameState);

    if (v0 != 6) {
        v1 = v0;
        *param2 |= (1 << 2);
    }

    v0 = ov101_021D5708(gameState);

    if (v0 != 6) {
        v1 = v0;
        *param2 |= (1 << 3);
    }

    v0 = ov101_021D5740(gameState);

    if (v0 != 6) {
        v1 = v0;
        *param2 |= (1 << 4);
    }

    return v1;
}

static UnkEnum_ov101_021D9688 ov101_021D57EC(SlotMachineGameState *gameState, u32 param1, u32 *param2)
{
    u32 v0;

    *param2 = 0;
    v0 = ov101_021D5698(gameState);

    if (v0 != 6) {
        GF_ASSERT(v0 == 2);
        *param2 |= (1 << 0);
    }

    return v0;
}

static UnkEnum_ov101_021D5814 ov101_021D5814(u32 param0)
{
    if (param0 & ((1 << 0) | (1 << 1))) {
        return UnkEnum_ov101_021D5814_01;
    }

    if (param0 & ((1 << 2) | (1 << 3))) {
        return UnkEnum_ov101_021D5814_00;
    }

    if (param0 & ((1 << 4) | (1 << 5))) {
        return UnkEnum_ov101_021D5814_02;
    }

    if (param0 & ((1 << 6) | (1 << 7))) {
        return UnkEnum_ov101_021D5814_03;
    }

    GF_ASSERT(FALSE);
    return UnkEnum_ov101_021D5814_04;
}

static void ov101_021D5848(SlotMachineGameState *gameState)
{
    int v0 = 0;

    do {
        gameState->unk_54[v0] = 0;
        v0++;
    } while (v0 < 3);
}

static void ov101_021D5858(SlotMachineGameState *gameState, u32 param1)
{
    int v0 = 0;

    do {
        if (gameState->unk_54[v0] == 0) {
            break;
        }

        v0++;
    } while (v0 < 3);

    GF_ASSERT(v0 < 3);
    gameState->unk_54[v0] = param1;
}

static int ov101_021D5880(SlotMachineGameState *gameState)
{
    int v0 = 0;
    u32 v1[3] = { PAD_BUTTON_Y, PAD_BUTTON_B, PAD_BUTTON_A };

    do {
        if ((gameState->unk_54[v0] != 0) && (gameState->unk_54[v0] != v1[v0])) {
            return 0;
        }

        v0++;
    } while (v0 < 3);

    return 1;
}

static int ov101_021D58C0(SlotMachineGameState *gameState)
{
    int v0 = 0;
    const UnkStruct_ov101_021D87A8 *v1 = &Unk_ov101_021D87A8[gameState->unk_34];

    do {
        if ((gameState->unk_54[v0] != 0) && (gameState->unk_54[v0] != v1->unk_00[v0])) {
            return 0;
        }

        v0++;
    } while (v0 < 3);

    return 1;
}

static void ov101_021D58F4(SlotMachineGameState *gameState, UnkEnum_ov101_021D2BDC param1)
{
    const int *v0 = Unk_ov101_021D8740[param1];

    Bg_ChangeTilemapRectPalette(gameState->unk_43C, 1, v0[0], v0[1], 3, 2, 6);
    Bg_ScheduleTilemapTransfer(gameState->unk_43C, 1);
}

static void ov101_021D5938(SlotMachineGameState *gameState, UnkEnum_ov101_021D2BDC param1)
{
    const int *v0 = Unk_ov101_021D8740[param1];

    Bg_ChangeTilemapRectPalette(gameState->unk_43C, 1, v0[0], v0[1], 3, 2, 5);
    Bg_ScheduleTilemapTransfer(gameState->unk_43C, 1);
}

static u32 ov101_021D597C(SlotMachineGameState *gameState)
{
    int v0, v1;
    UnkEnum_ov101_021D9688 v2 = gameState->unk_44;
    u32 v3 = gameState->unk_48;

    GF_ASSERT(v2 != 6);

    for (v0 = 0, v1 = 0; v0 < UnkEnum_ov101_021D4F58_05; v0++, v3 >>= 1) {
        if (v3 & 0x1) {
            v1 += Unk_ov101_021D9550[v2];
        }
    }

    return v1;
}

static const UnkStruct_ov101_021D87A8 Unk_ov101_021D87A8[6] = {
    {
        { PAD_BUTTON_Y, PAD_BUTTON_B, PAD_BUTTON_A },
        { UnkEnum_ov101_021D679C_06, UnkEnum_ov101_021D679C_05, UnkEnum_ov101_021D679C_07 },
    },
    {
        { PAD_BUTTON_Y, PAD_BUTTON_A, PAD_BUTTON_B },
        { UnkEnum_ov101_021D679C_06, UnkEnum_ov101_021D679C_07, UnkEnum_ov101_021D679C_05 },
    },
    {
        { PAD_BUTTON_B, PAD_BUTTON_Y, PAD_BUTTON_A },
        { UnkEnum_ov101_021D679C_05, UnkEnum_ov101_021D679C_06, UnkEnum_ov101_021D679C_07 },
    },
    {
        { PAD_BUTTON_B, PAD_BUTTON_A, PAD_BUTTON_Y },
        { UnkEnum_ov101_021D679C_05, UnkEnum_ov101_021D679C_07, UnkEnum_ov101_021D679C_06 },
    },
    {
        { PAD_BUTTON_A, PAD_BUTTON_Y, PAD_BUTTON_B },
        { UnkEnum_ov101_021D679C_07, UnkEnum_ov101_021D679C_06, UnkEnum_ov101_021D679C_05 },
    },
    {
        { PAD_BUTTON_A, PAD_BUTTON_B, PAD_BUTTON_Y },
        { UnkEnum_ov101_021D679C_07, UnkEnum_ov101_021D679C_05, UnkEnum_ov101_021D679C_06 },
    },
};

static const int Unk_ov101_021D8740[3][2] = {
    { 0x7, 0x11 },
    { 0xf, 0x11 },
    { 0x16, 0x11 },
};
