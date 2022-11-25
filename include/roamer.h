#ifndef GUARD_ROAMER_H
#define GUARD_ROAMER_H

void ClearRoamerData(void);
void ClearRoamerLatiasData(void);
void ClearRoamerLatiosData(void);
void ClearRoamerLocationData(void);
void ClearRoamerLatiasLocationData(void);
void ClearRoamerLatiosLocationData(void);
void CreateNewRoamerLatias(void);
void CreateNewRoamerLatios(void);
void UpdateLocationHistoryForRoamer(void);
void RoamerMoveToOtherLocationSet(void);
void RoamerMove(void);
bool8 IsRoamer1At(u8 mapGroup, u8 mapNum);
bool8 IsRoamer2At(u8 mapGroup, u8 mapNum);
void CreateRoamerMonInstance(struct Roamer *roamer, u16 species);
u8 TryStartRoamerEncounter(void);
void UpdateRoamerHPStatus(struct Roamer *roamer, struct Pokemon *mon);
void SetRoamerInactive(struct Roamer *roamer);
void GetRoamer1Location(u8 *mapGroup, u8 *mapNum);
void GetRoamer2Location(u8 *mapGroup, u8 *mapNum);

#endif // GUARD_ROAMER_H
