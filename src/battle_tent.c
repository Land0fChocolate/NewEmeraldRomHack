#include "global.h"
#include "battle_tent.h"
#include "overworld.h"
#include "event_data.h"
#include "region_map.h"
#include "battle.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "random.h"
#include "item.h"
#include "battle_factory_screen.h"
#include "frontier_util.h"
#include "string_util.h"
#include "constants/battle_tent.h"
#include "constants/battle_tent_trainers.h"
#include "constants/battle_tent_mons.h"
#include "constants/items.h"
#include "constants/layouts.h"
#include "constants/region_map_sections.h"
#include "constants/trainers.h"

// This file's functions.
static void InitVerdanturfTentChallenge(void);
static void GetVerdanturfTentPrize(void);
static void SetVerdanturfTentPrize(void);
static void SetVerdanturfTentTrainerGfx(void);
static void BufferVerdanturfTentTrainerIntro(void);
static void SaveVerdanturfTentChallenge(void);
static void SetRandomVerdanturfTentPrize(void);
static void GiveVerdanturfTentPrize(void);
static void InitFallarborTentChallenge(void);
static void GetFallarborTentPrize(void);
static void SetFallarborTentPrize(void);
static void SaveFallarborTentChallenge(void);
static void SetRandomFallarborTentPrize(void);
static void GiveFallarborTentPrize(void);
static void BufferFallarborTentTrainerName(void);
static void InitSlateportTentChallenge(void);
static void GetSlateportTentPrize(void);
static void SetSlateportTentPrize(void);
static void SaveSlateportTentChallenge(void);
static void SetRandomSlateportTentPrize(void);
static void GiveSlateportTentPrize(void);
static void SelectInitialRentalMons(void);
static void SwapRentalMons(void);
static void GenerateOpponentMons(void);
static void GenerateInitialRentalMons(void);

/*
 * Battle Tents are mini versions of particular Battle Frontier facilities
 * As such they each share some scripts and functions with their counterpart
 *
 * Verdanturf Battle Tent: Battle Palace
 * Fallarbor Battle Tent:  Battle Arena
 * Slateport Battle Tent:  Battle Factory
 *
 */

// IWRAM bss
static u16 sRandMonSetId;

// const rom data
void static (*const sVerdanturfTentFuncs[])(void) =
{
    [VERDANTURF_TENT_FUNC_INIT]               = InitVerdanturfTentChallenge,
    [VERDANTURF_TENT_FUNC_GET_PRIZE]          = GetVerdanturfTentPrize,
    [VERDANTURF_TENT_FUNC_SET_PRIZE]          = SetVerdanturfTentPrize,
    [VERDANTURF_TENT_FUNC_SET_OPPONENT_GFX]   = SetVerdanturfTentTrainerGfx,
    [VERDANTURF_TENT_FUNC_GET_OPPONENT_INTRO] = BufferVerdanturfTentTrainerIntro,
    [VERDANTURF_TENT_FUNC_SAVE]               = SaveVerdanturfTentChallenge,
    [VERDANTURF_TENT_FUNC_SET_RANDOM_PRIZE]   = SetRandomVerdanturfTentPrize,
    [VERDANTURF_TENT_FUNC_GIVE_PRIZE]         = GiveVerdanturfTentPrize
};

static const u16 sVerdanturfTentRewards[] = {ITEM_NEST_BALL};

void static (*const sFallarborTentFuncs[])(void) =
{
    [FALLARBOR_TENT_FUNC_INIT]              = InitFallarborTentChallenge,
    [FALLARBOR_TENT_FUNC_GET_PRIZE]         = GetFallarborTentPrize,
    [FALLARBOR_TENT_FUNC_SET_PRIZE]         = SetFallarborTentPrize,
    [FALLARBOR_TENT_FUNC_SAVE]              = SaveFallarborTentChallenge,
    [FALLARBOR_TENT_FUNC_SET_RANDOM_PRIZE]  = SetRandomFallarborTentPrize,
    [FALLARBOR_TENT_FUNC_GIVE_PRIZE]        = GiveFallarborTentPrize,
    [FALLARBOR_TENT_FUNC_GET_OPPONENT_NAME] = BufferFallarborTentTrainerName
};

static const u16 sFallarborTentRewards[] = {ITEM_HYPER_POTION};

void static (*const sSlateportTentFuncs[])(void) =
{
    [SLATEPORT_TENT_FUNC_INIT]                   = InitSlateportTentChallenge,
    [SLATEPORT_TENT_FUNC_GET_PRIZE]              = GetSlateportTentPrize,
    [SLATEPORT_TENT_FUNC_SET_PRIZE]              = SetSlateportTentPrize,
    [SLATEPORT_TENT_FUNC_SAVE]                   = SaveSlateportTentChallenge,
    [SLATEPORT_TENT_FUNC_SET_RANDOM_PRIZE]       = SetRandomSlateportTentPrize,
    [SLATEPORT_TENT_FUNC_GIVE_PRIZE]             = GiveSlateportTentPrize,
    [SLATEPORT_TENT_FUNC_SELECT_RENT_MONS]       = SelectInitialRentalMons,
    [SLATEPORT_TENT_FUNC_SWAP_RENT_MONS]         = SwapRentalMons,
    [SLATEPORT_TENT_FUNC_GENERATE_OPPONENT_MONS] = GenerateOpponentMons,
    [SLATEPORT_TENT_FUNC_GENERATE_RENTAL_MONS]   = GenerateInitialRentalMons
};

static const u16 sSlateportTentRewards[] = {ITEM_FULL_HEAL};

// code
void CallVerdanturfTentFunction(void)
{
    sVerdanturfTentFuncs[gSpecialVar_0x8004]();
}

static void InitVerdanturfTentChallenge(void)
{
    gSaveBlock2Ptr->frontier.challengeStatus = 0;
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = 0;
    gSaveBlock2Ptr->frontier.challengePaused = FALSE;
    SetDynamicWarp(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1);
}

static void GetVerdanturfTentPrize(void)
{
}

static void SetVerdanturfTentPrize(void)
{
}

static void SetVerdanturfTentTrainerGfx(void)
{
    gTrainerBattleOpponent_A = (u32)((Random() % 255) * 5) / 64;
    SetBattleFacilityTrainerGfxId(gTrainerBattleOpponent_A, 0);
}

static void BufferVerdanturfTentTrainerIntro(void)
{
    if (gTrainerBattleOpponent_A < FRONTIER_TRAINERS_COUNT)
        FrontierSpeechToString(gFacilityTrainers[gTrainerBattleOpponent_A].speechBefore);
}

static void SaveVerdanturfTentChallenge(void)
{
    gSaveBlock2Ptr->frontier.challengeStatus = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_0, 0);
    gSaveBlock2Ptr->frontier.challengePaused = TRUE;
    SaveGameFrontier();
}

static void SetRandomVerdanturfTentPrize(void)
{
}

static void GiveVerdanturfTentPrize(void)
{
}

void CallFallarborTentFunction(void)
{
    sFallarborTentFuncs[gSpecialVar_0x8004]();
}

static void InitFallarborTentChallenge(void)
{
    gSaveBlock2Ptr->frontier.challengeStatus = 0;
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = 0;
    gSaveBlock2Ptr->frontier.challengePaused = FALSE;
    SetDynamicWarp(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1);
}

static void GetFallarborTentPrize(void)
{
}

static void SetFallarborTentPrize(void)
{
}

static void SaveFallarborTentChallenge(void)
{
    gSaveBlock2Ptr->frontier.challengeStatus = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_0, 0);
    gSaveBlock2Ptr->frontier.challengePaused = TRUE;
    SaveGameFrontier();
}

static void SetRandomFallarborTentPrize(void)
{
}

static void GiveFallarborTentPrize(void)
{
}

static void BufferFallarborTentTrainerName(void)
{
    GetFrontierTrainerName(gStringVar1, gTrainerBattleOpponent_A);
}

void CallSlateportTentFunction(void)
{
    sSlateportTentFuncs[gSpecialVar_0x8004]();
}

static void InitSlateportTentChallenge(void)
{
    gSaveBlock2Ptr->frontier.challengeStatus = 0;
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = 0;
    gSaveBlock2Ptr->frontier.challengePaused = FALSE;
    SetDynamicWarp(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1);
}

static void GetSlateportTentPrize(void)
{
}

static void SetSlateportTentPrize(void)
{
}

static void SaveSlateportTentChallenge(void)
{
    gSaveBlock2Ptr->frontier.challengeStatus = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_0, 0);
    gSaveBlock2Ptr->frontier.challengePaused = TRUE;
    SaveGameFrontier();
}

static void SetRandomSlateportTentPrize(void)
{
}

static void GiveSlateportTentPrize(void)
{
}

static void SelectInitialRentalMons(void)
{
    ZeroPlayerPartyMons();
    DoBattleFactorySelectScreen();
}

static void SwapRentalMons(void)
{
    DoBattleFactorySwapScreen();
}

bool8 InSlateportBattleTent(void)
{
    return gMapHeader.regionMapSectionId == MAPSEC_SLATEPORT_CITY
           && (gMapHeader.mapLayoutId == LAYOUT_BATTLE_TENT_CORRIDOR || gMapHeader.mapLayoutId == LAYOUT_BATTLE_TENT_BATTLE_ROOM);
}

static void GenerateInitialRentalMons(void)
{
    s32 i, j;
    u8 firstMonId;
    u16 monSetId;
    u16 currSpecies;
    u16 species[PARTY_SIZE];
    u16 monIds[PARTY_SIZE];
    u16 heldItems[PARTY_SIZE];

    firstMonId = 0;
    gFacilityTrainers = gSlateportBattleTentTrainers;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        species[i] = 0;
        monIds[i] = 0;
        heldItems[i] = 0;
    }
    gFacilityTrainerMons = gSlateportBattleTentMons;
    currSpecies = SPECIES_NONE;
    i = 0;
    while (i != PARTY_SIZE)
    {
        // Cannot have two pokemon of the same species.
        monSetId = Random() % NUM_SLATEPORT_TENT_MONS;
        for (j = firstMonId; j < firstMonId + i; j++)
        {
            u16 monId = monIds[j];
            if (monIds[j] == monSetId)
                break;
            if (species[j] == gFacilityTrainerMons[monSetId].species)
            {
                if (currSpecies == SPECIES_NONE)
                    currSpecies = gFacilityTrainerMons[monSetId].species;
                else
                    break;
            }
        }
        if (j != i + firstMonId)
            continue;

        // Cannot have two same held items.
        for (j = firstMonId; j < i + firstMonId; j++)
        {
            if (heldItems[j] != 0 && heldItems[j] == gFacilityTrainerMons[monSetId].item)
            {
                if (gFacilityTrainerMons[monSetId].species == currSpecies)
                    currSpecies = SPECIES_NONE;
                break;
            }
        }
        if (j != i + firstMonId)
            continue;

        gSaveBlock2Ptr->frontier.rentalMons[i].monId = monSetId;
        species[i] = gFacilityTrainerMons[monSetId].species;
        heldItems[i] = gFacilityTrainerMons[monSetId].item;
        monIds[i] = monSetId;
        i++;
    }
}

static void GenerateOpponentMons(void)
{
    u16 trainerId;
    s32 i, j, k;
    const u16 *monSet;
    u16 species[FRONTIER_PARTY_SIZE];
    u16 heldItems[FRONTIER_PARTY_SIZE];
    s32 monId = 0;

    gFacilityTrainers = gSlateportBattleTentTrainers;
    gFacilityTrainerMons = gSlateportBattleTentMons;

    while (1)
    {
        do
        {
            trainerId = Random() % NUM_BATTLE_TENT_TRAINERS;
            for (i = 0; i < gSaveBlock2Ptr->frontier.curChallengeBattleNum; i++)
            {
                if (gSaveBlock2Ptr->frontier.trainerIds[i] == trainerId)
                    break;
            }
        } while (i != gSaveBlock2Ptr->frontier.curChallengeBattleNum);

        gTrainerBattleOpponent_A = trainerId;
        monSet = gFacilityTrainers[gTrainerBattleOpponent_A].monSet;
        while (monSet[monId] != 0xFFFF)
            monId++;
        if (monId > 8)
            break;
        monId = 0;
    }

    if (gSaveBlock2Ptr->frontier.curChallengeBattleNum < 2)
        gSaveBlock2Ptr->frontier.trainerIds[gSaveBlock2Ptr->frontier.curChallengeBattleNum] = gTrainerBattleOpponent_A;

    monSet = gFacilityTrainers[gTrainerBattleOpponent_A].monSet;
    i = 0;
    while (i != FRONTIER_PARTY_SIZE)
    {
        sRandMonSetId = monSet[Random() % monId];
        for (j = 0; j < 6; j++)
        {
            if (gFacilityTrainerMons[sRandMonSetId].species == gFacilityTrainerMons[gSaveBlock2Ptr->frontier.rentalMons[j].monId].species)
                break;
        }
        if (j != 6)
            continue;

        for (k = 0; k < i; k++)
        {
            if (species[k] == gFacilityTrainerMons[sRandMonSetId].species)
                break;
        }
        if (k != i)
            continue;

        for (k = 0; k < i; k++)
        {
            if (heldItems[k] != 0 && heldItems[k] == gFacilityTrainerMons[sRandMonSetId].item)
                break;
        }
        if (k != i)
            continue;

        species[i] = gFacilityTrainerMons[sRandMonSetId].species;
        heldItems[i] = gFacilityTrainerMons[sRandMonSetId].item;
        gFrontierTempParty[i] = sRandMonSetId;
        i++;
    }
}
