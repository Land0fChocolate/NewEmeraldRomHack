#include "global.h"
#include "event_data.h"
#include "pokemon.h"
#include "random.h"
#include "roamer.h"
#include "constants/maps.h"

enum
{
    MAP_GRP = 0, // map group
    MAP_NUM = 1, // map number
};

#define ROAMER1 (&gSaveBlock1Ptr->roamer1)
#define ROAMER2 (&gSaveBlock1Ptr->roamer2)

EWRAM_DATA static u8 sLocation1History[3][2] = {0};
EWRAM_DATA static u8 sLocation2History[3][2] = {0};
EWRAM_DATA static u8 sRoamer1Location[2] = {0};
EWRAM_DATA static u8 sRoamer2Location[2] = {0};

static const u8 sRoamerLocations[][6] =
{
    { MAP_NUM(ROUTE110), MAP_NUM(ROUTE111), MAP_NUM(ROUTE117), MAP_NUM(ROUTE118), MAP_NUM(ROUTE134), 0xFF },
    { MAP_NUM(ROUTE111), MAP_NUM(ROUTE110), MAP_NUM(ROUTE117), MAP_NUM(ROUTE118), 0xFF, 0xFF },
    { MAP_NUM(ROUTE117), MAP_NUM(ROUTE111), MAP_NUM(ROUTE110), MAP_NUM(ROUTE118), 0xFF, 0xFF },
    { MAP_NUM(ROUTE118), MAP_NUM(ROUTE117), MAP_NUM(ROUTE110), MAP_NUM(ROUTE111), MAP_NUM(ROUTE119), MAP_NUM(ROUTE123) },
    { MAP_NUM(ROUTE119), MAP_NUM(ROUTE118), MAP_NUM(ROUTE120), 0xFF, 0xFF, 0xFF },
    { MAP_NUM(ROUTE120), MAP_NUM(ROUTE119), MAP_NUM(ROUTE121), 0xFF, 0xFF, 0xFF },
    { MAP_NUM(ROUTE121), MAP_NUM(ROUTE120), MAP_NUM(ROUTE122), MAP_NUM(ROUTE123), 0xFF, 0xFF },
    { MAP_NUM(ROUTE122), MAP_NUM(ROUTE121), MAP_NUM(ROUTE123), 0xFF, 0xFF, 0xFF },
    { MAP_NUM(ROUTE123), MAP_NUM(ROUTE122), MAP_NUM(ROUTE118), 0xFF, 0xFF, 0xFF },
    { MAP_NUM(ROUTE124), MAP_NUM(ROUTE121), MAP_NUM(ROUTE125), MAP_NUM(ROUTE126), 0xFF, 0xFF },
    { MAP_NUM(ROUTE125), MAP_NUM(ROUTE124), MAP_NUM(ROUTE127), 0xFF, 0xFF, 0xFF },
    { MAP_NUM(ROUTE126), MAP_NUM(ROUTE124), MAP_NUM(ROUTE127), 0xFF, 0xFF, 0xFF },
    { MAP_NUM(ROUTE127), MAP_NUM(ROUTE125), MAP_NUM(ROUTE126), MAP_NUM(ROUTE128), 0xFF, 0xFF },
    { MAP_NUM(ROUTE128), MAP_NUM(ROUTE127), MAP_NUM(ROUTE129), 0xFF, 0xFF, 0xFF },
    { MAP_NUM(ROUTE129), MAP_NUM(ROUTE128), MAP_NUM(ROUTE130), 0xFF, 0xFF, 0xFF },
    { MAP_NUM(ROUTE130), MAP_NUM(ROUTE129), MAP_NUM(ROUTE131), 0xFF, 0xFF, 0xFF },
    { MAP_NUM(ROUTE131), MAP_NUM(ROUTE130), MAP_NUM(ROUTE132), 0xFF, 0xFF, 0xFF },
    { MAP_NUM(ROUTE132), MAP_NUM(ROUTE131), MAP_NUM(ROUTE133), 0xFF, 0xFF, 0xFF },
    { MAP_NUM(ROUTE133), MAP_NUM(ROUTE132), MAP_NUM(ROUTE134), 0xFF, 0xFF, 0xFF },
    { MAP_NUM(ROUTE134), MAP_NUM(ROUTE133), MAP_NUM(ROUTE110), 0xFF, 0xFF, 0xFF },
    { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },
};

void ClearRoamerLatiasData(void)
{
    memset(ROAMER1, 0, sizeof(*ROAMER1));
}

void ClearRoamerLatiosData(void)
{
    memset(ROAMER2, 0, sizeof(*ROAMER2));
}

void ClearRoamerLatiasLocationData(void)
{
    u8 i;

    for (i = 0; i < 3; i++)
    {
        sLocation1History[i][MAP_GRP] = 0;
        sLocation1History[i][MAP_NUM] = 0;
    }

    sRoamer1Location[MAP_GRP] = 0;
    sRoamer1Location[MAP_NUM] = 0;
}

void ClearRoamerLatiosLocationData(void)
{
    u8 i;

    for (i = 0; i < 3; i++)
    {
        sLocation2History[i][MAP_GRP] = 0;
        sLocation2History[i][MAP_NUM] = 0;
    }

    sRoamer2Location[MAP_GRP] = 0;
    sRoamer2Location[MAP_NUM] = 0;
}

void CreateNewRoamerLatias(void)
{
    CreateMon(&gEnemyParty[0], SPECIES_LATIAS, 40, 0x20, 0, 0, OT_ID_PLAYER_ID, 0);
    ROAMER1->level = 40;
    ROAMER1->status = 0;
    ROAMER1->active = TRUE;
    ROAMER1->ivs = GetMonData(&gEnemyParty[0], MON_DATA_IVS);
    ROAMER1->personality = GetMonData(&gEnemyParty[0], MON_DATA_PERSONALITY);
    ROAMER1->hp = GetMonData(&gEnemyParty[0], MON_DATA_MAX_HP);
    sRoamer1Location[MAP_GRP] = 0;
    sRoamer1Location[MAP_NUM] = sRoamerLocations[Random() % (ARRAY_COUNT(sRoamerLocations) - 1)][0];
}

void CreateNewRoamerLatios(void)
{
    CreateMon(&gEnemyParty[0], SPECIES_LATIOS, 40, 0x20, 0, 0, OT_ID_PLAYER_ID, 0);
    ROAMER2->level = 40;
    ROAMER2->status = 0;
    ROAMER2->active = TRUE;
    ROAMER2->ivs = GetMonData(&gEnemyParty[0], MON_DATA_IVS);
    ROAMER2->personality = GetMonData(&gEnemyParty[0], MON_DATA_PERSONALITY);
    ROAMER2->hp = GetMonData(&gEnemyParty[0], MON_DATA_MAX_HP);
    sRoamer2Location[MAP_GRP] = 0;
    sRoamer2Location[MAP_NUM] = sRoamerLocations[Random() % (ARRAY_COUNT(sRoamerLocations) - 1)][0];
}

void InitNewRoamerLatias(void)
{
    ClearRoamerLatiasData();
    ClearRoamerLatiasLocationData();
    CreateNewRoamerLatias();
}

void InitNewRoamerLatios(void)
{
    ClearRoamerLatiosData();
    ClearRoamerLatiosLocationData();
    CreateNewRoamerLatios();
}

void UpdateLocationHistoryForRoamer(void)
{
    sLocation1History[2][MAP_GRP] = sLocation1History[1][MAP_GRP];
    sLocation1History[2][MAP_NUM] = sLocation1History[1][MAP_NUM];

    sLocation1History[1][MAP_GRP] = sLocation1History[0][MAP_GRP];
    sLocation1History[1][MAP_NUM] = sLocation1History[0][MAP_NUM];

    sLocation1History[0][MAP_GRP] = gSaveBlock1Ptr->location.mapGroup;
    sLocation1History[0][MAP_NUM] = gSaveBlock1Ptr->location.mapNum;

    sLocation2History[2][MAP_GRP] = sLocation2History[1][MAP_GRP];
    sLocation2History[2][MAP_NUM] = sLocation2History[1][MAP_NUM];

    sLocation2History[1][MAP_GRP] = sLocation2History[0][MAP_GRP];
    sLocation2History[1][MAP_NUM] = sLocation2History[0][MAP_NUM];

    sLocation2History[0][MAP_GRP] = gSaveBlock1Ptr->location.mapGroup;
    sLocation2History[0][MAP_NUM] = gSaveBlock1Ptr->location.mapNum;
}

void RoamerMoveToOtherLocationSet(void)
{
    u8 mapNum = 0;

    if (!ROAMER1->active && !ROAMER2->active)
        return;

    sRoamer1Location[MAP_GRP] = 0;
    sRoamer2Location[MAP_GRP] = 0;

    while (1)
    {
        mapNum = sRoamerLocations[Random() % (ARRAY_COUNT(sRoamerLocations) - 1)][0];
        if (sRoamer1Location[MAP_NUM] != mapNum)
        {
            sRoamer1Location[MAP_NUM] = mapNum;
            break;
        }
    }

    while (1)
    {
        mapNum = sRoamerLocations[Random() % (ARRAY_COUNT(sRoamerLocations) - 1)][0];
        if (sRoamer2Location[MAP_NUM] != mapNum)
        {
            sRoamer2Location[MAP_NUM] = mapNum;
            break;
        }
    }

    return;
}

void RoamerMove(void)
{
    u8 locSet = 0;

    if ((Random() % 3) == 0)
    {
        return;
    }

    if ((Random() % 16) == 0)
    {
        RoamerMoveToOtherLocationSet();
    }
    else
    {
        if (ROAMER1->active)
        {
            while (locSet < (ARRAY_COUNT(sRoamerLocations) - 1))
            {
                if (sRoamer1Location[MAP_NUM] == sRoamerLocations[locSet][0])
                {
                    u8 mapNum;
                    while (1)
                    {
                        mapNum = sRoamerLocations[locSet][(Random() % 5) + 1];
                        if (!(sLocation1History[2][MAP_GRP] == 0 
                            && sLocation1History[2][MAP_NUM] == mapNum) 
                            && mapNum != 0xFF)
                            break;
                    }
                    sRoamer1Location[MAP_NUM] = mapNum;
                    break;
                }
                locSet++;
            }
        }

        if (ROAMER2->active)
        {
            locSet = 0;

            while (locSet < (ARRAY_COUNT(sRoamerLocations) - 1))
            {
                if (sRoamer2Location[MAP_NUM] == sRoamerLocations[locSet][0])
                {
                    u8 mapNum;
                    while (1)
                    {
                        mapNum = sRoamerLocations[locSet][(Random() % 5) + 1];
                        if (!(sLocation2History[2][MAP_GRP] == 0 
                            && sLocation2History[2][MAP_NUM] == mapNum) 
                            && mapNum != 0xFF)
                            break;
                    }
                    sRoamer2Location[MAP_NUM] = mapNum;
                    break;;
                }
                locSet++;
            }
        }
    }

    return;
}

bool8 IsRoamer1At(u8 mapGroup, u8 mapNum)
{
    if (ROAMER1->active 
        && mapGroup == sRoamer1Location[MAP_GRP] 
        && mapNum == sRoamer1Location[MAP_NUM])
        return TRUE;
    else
        return FALSE;
}

bool8 IsRoamer2At(u8 mapGroup, u8 mapNum)
{
    if (ROAMER2->active 
        && mapGroup == sRoamer2Location[MAP_GRP] 
        && mapNum == sRoamer2Location[MAP_NUM])
        return TRUE;
    else
        return FALSE;
}

void CreateRoamerMonInstance(struct Roamer *roamer, u16 species)
{
    struct Pokemon *mon;
    u32 status;

    mon = &gEnemyParty[0];
    ZeroEnemyPartyMons();
    CreateMonWithIVsPersonality(mon, species, roamer->level, roamer->ivs, roamer->personality);
    status = roamer->status;
    SetMonData(mon, MON_DATA_STATUS, &status);
    SetMonData(mon, MON_DATA_HP, &roamer->hp);
}

u8 TryStartRoamerEncounter(void)
{
    if (IsRoamer1At(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum) == TRUE && (Random() % 4) == 0)
    {
        CreateRoamerMonInstance(ROAMER1, SPECIES_LATIAS);
        return 1;
    }
    else if (IsRoamer2At(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum) == TRUE && (Random() % 4) == 0)
    {
        CreateRoamerMonInstance(ROAMER2, SPECIES_LATIOS);
        return 2;
    }
    else
    {
        return 0;
    }
}

void UpdateRoamerHPStatus(struct Roamer *roamer, struct Pokemon *mon)
{
    roamer->hp = GetMonData(mon, MON_DATA_HP);
    roamer->status = GetMonData(mon, MON_DATA_STATUS);

    RoamerMoveToOtherLocationSet();
}

void SetRoamerInactive(struct Roamer *roamer)
{
    roamer->active = FALSE;
}

void GetRoamer1Location(u8 *mapGroup, u8 *mapNum)
{
    *mapGroup = sRoamer1Location[MAP_GRP];
    *mapNum = sRoamer1Location[MAP_NUM];
}

void GetRoamer2Location(u8 *mapGroup, u8 *mapNum)
{
    *mapGroup = sRoamer2Location[MAP_GRP];
    *mapNum = sRoamer2Location[MAP_NUM];
}
