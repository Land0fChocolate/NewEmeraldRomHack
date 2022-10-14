#ifndef GUARD_ROAMER_H
#define GUARD_ROAMER_H

void ClearRoamerData(void);
void ClearRoamerLocationData(void);
void InitRoamers(void);
void UpdateLocationHistoryForRoamer(void);
void RoamerMoveToOtherLocationSet(void);
void RoamerMove(void);
bool8 IsRoamerAt(struct Roamer *roamer, u8 mapGroup, u8 mapNum);
void CreateRoamerMonInstance(struct Roamer *roamer, u16 species);
u8 TryStartRoamerEncounter(void);
void UpdateRoamerHPStatus(struct Roamer *roamer, struct Pokemon *mon);
void SetRoamerInactive(struct Roamer *roamer);
void GetRoamerLocation(u8 *mapGroup, u8 *mapNum);

#endif // GUARD_ROAMER_H
