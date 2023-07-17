#ifndef GUARD_DAYCARE_H
#define GUARD_DAYCARE_H

#include "constants/daycare.h"

u8 *GetMonNickname2(struct Pokemon *mon, u8 *dest);
u8 *GetBoxMonNickname(struct BoxPokemon *mon, u8 *dest);
u8 CountPokemonInDaycare(struct DayCare *daycare);
void InitDaycareMailRecordMixing(struct DayCare *daycare, struct RecordMixingDaycareMail *daycareMail);
void StoreSelectedPokemonInDaycare(void);
u16 TakePokemonFromDaycare(void);
void GetDaycareCost(void);
u8 GetNumLevelsGainedFromDaycare(void);
void TriggerPendingDaycareEgg(void);
void RejectEggFromDayCare(void);
void CreateEgg(struct Pokemon *mon, u16 species, bool8 setHotSpringsLocation);
void GiveEggFromDaycare(void);
bool8 ShouldEggHatch(void);
u16 GetSelectedMonNicknameAndSpecies(void);
void GetDaycareMonNicknames(void);
u8 GetDaycareState(void);
void SetDaycareCompatibilityString(void);
bool8 NameHasGenderSymbol(const u8 *name, u8 genderRatio);
void ShowDaycareLevelMenu(void);
void ChooseSendDaycareMon(void);
u8 GetEggTutorMoves(struct Pokemon *mon, u16 *moves);
u16 GetEggMovesArraySize(void);
u16 GetEggSpecies(u16 species);
#endif // GUARD_DAYCARE_H
