.set LOCALID_WHISMUR, 3
.set LOCALID_SCIENTIST, 6
.set LOCALID_ZINNIA, 7

FallarborTown_DraconidArchives_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_DraconidArchives_OnTransition
	.byte 0

FallarborTown_DraconidArchives_OnTransition:
	compare VAR_DRACONID_ARCHIVES_STATE, 1
	goto_if_ge FallarborTown_DraconidArchives_EventScript_SetPostDeoxysScene
	end

FallarborTown_DraconidArchives_EventScript_SetPostDeoxysScene:
	setobjectxyperm LOCALID_WHISMUR, 15, 4
	setobjectmovementtype LOCALID_WHISMUR, MOVEMENT_TYPE_FACE_DOWN
	return

DraconidArchives_Eventscript_Zinnia::
	lock
	faceplayer
	compare VAR_DRACONID_ARCHIVES_STATE, 2
	goto_if_ge DraconidArchives_EventScript_HaveYouBroughtSnacks
	compare VAR_DRACONID_ARCHIVES_STATE, 1
	goto_if_eq DraconidArchives_EventScript_ZinniaDeoxysBeaten
	release
	end

DraconidArchives_EventScript_HaveYouBroughtSnacks::
	msgbox DraconidArchives_Text_HaveYouBroughtBerries, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq DraconidArchives_EventScript_WhichBerryToGive
	msgbox DraconidArchives_Text_SomeOtherTime, MSGBOX_DEFAULT
	closemessage
	release
	end

DraconidArchives_EventScript_WhichBerryToGive::
	setvar VAR_0x8009, 0
	setvar VAR_0x8004, SCROLL_MULTI_ASTER_BERRY
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, DraconidArchives_EventScript_ChilanBerry
	case 1, DraconidArchives_EventScript_OccaBerry
	case 2, DraconidArchives_EventScript_PasshoBerry
	case 3, DraconidArchives_EventScript_WacanBerry
	case 4, DraconidArchives_EventScript_RindoBerry
	case 5, DraconidArchives_EventScript_YacheBerry
	case 6, DraconidArchives_EventScript_ChopleBerry
	case 7, DraconidArchives_EventScript_KebiaBerry
	case 8, DraconidArchives_EventScript_ShucaBerry
	case 9, DraconidArchives_EventScript_CobaBerry
	case 10, DraconidArchives_EventScript_PayapaBerry
	case 11, DraconidArchives_EventScript_TangaBerry
	case 12, DraconidArchives_EventScript_ChartiBerry
	case 13, DraconidArchives_EventScript_KasibBerry
	case 14, DraconidArchives_EventScript_HabanBerry
	case 15, DraconidArchives_EventScript_ColburBerry
	case 16, DraconidArchives_EventScript_BabiriBerry
	case 17, DraconidArchives_EventScript_RoseliBerry
	case 18, DraconidArchives_EventScript_CancelAsterBerrySelect
	case MULTI_B_PRESSED, DraconidArchives_EventScript_CancelAsterBerrySelect
	end

DraconidArchives_EventScript_ChilanBerry::
	checkitem ITEM_CHILAN_BERRY, 5
	compare VAR_RESULT, FALSE
	call_if_eq DraconidArchives_EventScript_YouDoNotHaveThisBerry
	setvar VAR_0x8008, ITEM_CHILAN_BERRY
	goto DraconidArchives_EventScript_GiveBerry

DraconidArchives_EventScript_OccaBerry::
	checkitem ITEM_OCCA_BERRY, 5
	compare VAR_RESULT, FALSE
	call_if_eq DraconidArchives_EventScript_YouDoNotHaveThisBerry
	setvar VAR_0x8008, ITEM_OCCA_BERRY
	goto DraconidArchives_EventScript_GiveBerry

DraconidArchives_EventScript_PasshoBerry::
	checkitem ITEM_PASSHO_BERRY, 5
	compare VAR_RESULT, FALSE
	call_if_eq DraconidArchives_EventScript_YouDoNotHaveThisBerry
	setvar VAR_0x8008, ITEM_PASSHO_BERRY
	goto DraconidArchives_EventScript_GiveBerry

DraconidArchives_EventScript_WacanBerry::
	checkitem ITEM_WACAN_BERRY, 5
	compare VAR_RESULT, FALSE
	call_if_eq DraconidArchives_EventScript_YouDoNotHaveThisBerry
	setvar VAR_0x8008, ITEM_WACAN_BERRY
	goto DraconidArchives_EventScript_GiveBerry

DraconidArchives_EventScript_RindoBerry::
	checkitem ITEM_RINDO_BERRY, 5
	compare VAR_RESULT, FALSE
	call_if_eq DraconidArchives_EventScript_YouDoNotHaveThisBerry
	setvar VAR_0x8008, ITEM_RINDO_BERRY
	goto DraconidArchives_EventScript_GiveBerry

DraconidArchives_EventScript_YacheBerry::
	checkitem ITEM_YACHE_BERRY, 5
	compare VAR_RESULT, FALSE
	call_if_eq DraconidArchives_EventScript_YouDoNotHaveThisBerry
	setvar VAR_0x8008, ITEM_YACHE_BERRY
	goto DraconidArchives_EventScript_GiveBerry

DraconidArchives_EventScript_ChopleBerry::
	checkitem ITEM_CHOPLE_BERRY, 5
	compare VAR_RESULT, FALSE
	call_if_eq DraconidArchives_EventScript_YouDoNotHaveThisBerry
	setvar VAR_0x8008, ITEM_CHOPLE_BERRY
	goto DraconidArchives_EventScript_GiveBerry

DraconidArchives_EventScript_KebiaBerry::
	checkitem ITEM_KEBIA_BERRY, 5
	compare VAR_RESULT, FALSE
	call_if_eq DraconidArchives_EventScript_YouDoNotHaveThisBerry
	setvar VAR_0x8008, ITEM_KEBIA_BERRY
	goto DraconidArchives_EventScript_GiveBerry

DraconidArchives_EventScript_ShucaBerry::
	checkitem ITEM_SHUCA_BERRY, 5
	compare VAR_RESULT, FALSE
	call_if_eq DraconidArchives_EventScript_YouDoNotHaveThisBerry
	setvar VAR_0x8008, ITEM_SHUCA_BERRY
	goto DraconidArchives_EventScript_GiveBerry

DraconidArchives_EventScript_CobaBerry::
	checkitem ITEM_COBA_BERRY, 5
	compare VAR_RESULT, FALSE
	call_if_eq DraconidArchives_EventScript_YouDoNotHaveThisBerry
	setvar VAR_0x8008, ITEM_COBA_BERRY
	goto DraconidArchives_EventScript_GiveBerry

DraconidArchives_EventScript_PayapaBerry::
	checkitem ITEM_PAYAPA_BERRY, 5
	compare VAR_RESULT, FALSE
	call_if_eq DraconidArchives_EventScript_YouDoNotHaveThisBerry
	setvar VAR_0x8008, ITEM_PAYAPA_BERRY
	goto DraconidArchives_EventScript_GiveBerry

DraconidArchives_EventScript_TangaBerry::
	checkitem ITEM_TANGA_BERRY, 5
	compare VAR_RESULT, FALSE
	call_if_eq DraconidArchives_EventScript_YouDoNotHaveThisBerry
	setvar VAR_0x8008, ITEM_TANGA_BERRY
	goto DraconidArchives_EventScript_GiveBerry

DraconidArchives_EventScript_ChartiBerry::
	checkitem ITEM_CHARTI_BERRY, 5
	compare VAR_RESULT, FALSE
	call_if_eq DraconidArchives_EventScript_YouDoNotHaveThisBerry
	setvar VAR_0x8008, ITEM_CHARTI_BERRY
	goto DraconidArchives_EventScript_GiveBerry

DraconidArchives_EventScript_KasibBerry::
	checkitem ITEM_KASIB_BERRY, 5
	compare VAR_RESULT, FALSE
	call_if_eq DraconidArchives_EventScript_YouDoNotHaveThisBerry
	setvar VAR_0x8008, ITEM_KASIB_BERRY
	goto DraconidArchives_EventScript_GiveBerry

DraconidArchives_EventScript_HabanBerry::
	checkitem ITEM_HABAN_BERRY, 5
	compare VAR_RESULT, FALSE
	call_if_eq DraconidArchives_EventScript_YouDoNotHaveThisBerry
	setvar VAR_0x8008, ITEM_HABAN_BERRY
	goto DraconidArchives_EventScript_GiveBerry

DraconidArchives_EventScript_ColburBerry::
	checkitem ITEM_COLBUR_BERRY, 5
	compare VAR_RESULT, FALSE
	call_if_eq DraconidArchives_EventScript_YouDoNotHaveThisBerry
	setvar VAR_0x8008, ITEM_COLBUR_BERRY
	goto DraconidArchives_EventScript_GiveBerry

DraconidArchives_EventScript_BabiriBerry::
	checkitem ITEM_BABIRI_BERRY, 5
	compare VAR_RESULT, FALSE
	call_if_eq DraconidArchives_EventScript_YouDoNotHaveThisBerry
	setvar VAR_0x8008, ITEM_BABIRI_BERRY
	goto DraconidArchives_EventScript_GiveBerry

DraconidArchives_EventScript_RoseliBerry::
	checkitem ITEM_ROSELI_BERRY, 5
	compare VAR_RESULT, FALSE
	call_if_eq DraconidArchives_EventScript_YouDoNotHaveThisBerry
	setvar VAR_0x8008, ITEM_ROSELI_BERRY
	goto DraconidArchives_EventScript_GiveBerry

DraconidArchives_EventScript_CancelAsterBerrySelect::
	msgbox DraconidArchives_Text_SomeOtherTime, MSGBOX_DEFAULT
	closemessage
	release
	end

DraconidArchives_EventScript_GiveBerry::
	bufferitemname 0, VAR_0x8008
	msgbox DraconidArchives_Text_YoullGiveXBerry, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq DraconidArchives_EventScript_WhichBerryToGive
	removeitem VAR_0x8008, 5
	goto DraconidArchives_EventScript_ZinniaResetsLegendaries
	end

DraconidArchives_EventScript_YouDoNotHaveThisBerry::
	msgbox DraconidArchives_Text_YouDoNotHaveThisBerry, MSGBOX_DEFAULT
	goto DraconidArchives_EventScript_WhichBerryToGive
	end

DraconidArchives_EventScript_ZinniaResetsLegendaries::
	msgbox DraconidArchives_Text_ManyThanksRespawningLegendaries, MSGBOX_DEFAULT
	closemessage
	call DraconidArchives_EventScript_ResetDefeatedLegendaries
	release
	end

DraconidArchives_EventScript_ResetDefeatedLegendaries::
	clearflag FLAG_DEFEATED_ARTICUNO
	clearflag FLAG_GAVE_AWAY_GALARIAN_ARTICUNO
	clearflag FLAG_DEFEATED_ZAPDOS
	clearflag FLAG_GAVE_AWAY_GALARIAN_ZAPDOS
	clearflag FLAG_DEFEATED_MOLTRES
	clearflag FLAG_GAVE_AWAY_GALARIAN_MOLTRES
	clearflag FLAG_DEFEATED_MEW
	clearflag FLAG_HIDE_MEW
	clearflag FLAG_DEFEATED_RAIKOU
	clearflag FLAG_DEFEATED_ENTEI
	clearflag FLAG_DEFEATED_SUICUNE
	clearflag FLAG_DEFEATED_LUGIA
	clearflag FLAG_HIDE_LUGIA
	clearflag FLAG_DEFEATED_HO_OH
	clearflag FLAG_HIDE_HO_OH
	call_if_set FLAG_OBTAINED_ALL_BERRIES_FOR_SHRINE, DraconidArchives_EventScript_ResetCelebi
	clearflag FLAG_DEFEATED_REGIROCK
	clearflag FLAG_HIDE_REGIROCK
	clearflag FLAG_DEFEATED_REGICE
	clearflag FLAG_HIDE_REGICE
	clearflag FLAG_DEFEATED_REGISTEEL
	clearflag FLAG_HIDE_REGISTEEL
	call_if_set FLAG_DEFEATED_LATIAS, DraconidArchives_EventScript_ResetLatias
	call_if_set FLAG_DEFEATED_LATIOS, DraconidArchives_EventScript_ResetLatios
	clearflag FLAG_DEFEATED_KYOGRE
	clearflag FLAG_HIDE_MARINE_CAVE_KYOGRE
	clearflag FLAG_DEFEATED_GROUDON
	clearflag FLAG_HIDE_TERRA_CAVE_GROUDON
	clearflag FLAG_DEFEATED_RAYQUAZA
	clearflag FLAG_HIDE_SKY_PILLAR_TOP_RAYQUAZA
	call_if_set FLAG_PLACED_WISH_TAG, DraconidArchives_EventScript_ResetJirachi
	clearflag FLAG_DEFEATED_DEOXYS
	clearflag FLAG_BATTLED_DEOXYS
	clearflag FLAG_HIDE_BIRTH_ISLAND_DEOXYS_TRIANGLE
	return

DraconidArchives_EventScript_ResetCelebi::
	clearflag FLAG_DEFEATED_CELEBI
	clearflag FLAG_HIDE_PETALBURG_CITY_CELEBI
	return

DraconidArchives_EventScript_ResetLatias::
	special InitNewRoamerLatias
	clearflag FLAG_DEFEATED_LATIAS
	return

DraconidArchives_EventScript_ResetLatios::
	special InitNewRoamerLatios
	clearflag FLAG_DEFEATED_LATIOS
	return

DraconidArchives_EventScript_ResetJirachi::
	clearflag FLAG_DEFEATED_JIRACHI
	clearflag FLAG_HIDE_SLATEPORT_CITY_JIRACHI
	return

DraconidArchives_EventScript_ZinniaDeoxysBeaten::
	msgbox DraconidArchives_Text_BeatenDeoxys, MSGBOX_DEFAULT
	release
	giveitem ITEM_MEGA_RING
	msgbox DraconidArchives_Text_MegaEvolutionDescription, MSGBOX_DEFAULT
	closemessage
	delay 5
	applymovement LOCALID_WHISMUR, Common_Movement_FaceLeft
	waitmovement 0
	playmoncry SPECIES_WHISMUR, 0
	waitmoncry
	delay 30
	applymovement LOCALID_ZINNIA, Common_Movement_FaceRight
	waitmovement 0
	msgbox DraconidArchives_Text_NoSnacksForAster, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_ZINNIA, Common_Movement_FaceDown
	waitmovement 0
	msgbox DraconidArchives_Text_BringSnacksForAster, MSGBOX_DEFAULT
	closemessage
	setvar VAR_DRACONID_ARCHIVES_STATE, 2
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_JUAN
	setflag FLAG_POST_GAME_COMPLETE
	setflag FLAG_TV_RARE_CANDY_ADVERT
	release
	end

DraconidArchives_Eventscript_OldMan::
	lock
	faceplayer
	compare VAR_DRACONID_ARCHIVES_STATE, 1
	goto_if_ge FallarborTown_DraconidArchives_EventScript_OldManPostDeoxys
	msgbox DraconidArchives_Text_WelcomeToArchives, MSGBOX_DEFAULT
	release
	end

FallarborTown_DraconidArchives_EventScript_OldManPostDeoxys::
	msgbox DraconidArchives_Text_LorekeeperReturned, MSGBOX_DEFAULT
	release
	end

DraconidArchives_Eventscript_FairyTaleGirl::
	msgbox DraconidArchives_Text_FairyTales, MSGBOX_NPC
	end

DraconidArchives_Eventscript_Man::
	msgbox DraconidArchives_Text_CouldTextShowTreasures, MSGBOX_NPC
	end

DraconidArchives_Eventscript_Scientist::
	lock
	goto_if_set FLAG_RECEIVED_OLD_SEA_MAP, DraconidArchives_Eventscript_ScientistAbsorbedInBooks
	faceplayer
	msgbox DraconidArchives_Text_MapFellOut, MSGBOX_DEFAULT
	giveitem ITEM_OLD_SEA_MAP
	setflag FLAG_RECEIVED_OLD_SEA_MAP
	applymovement LOCALID_SCIENTIST, Common_Movement_FaceUp
	release
	end

DraconidArchives_Eventscript_ScientistAbsorbedInBooks::
	msgbox DraconidArchives_Text_TooAbsorbedInBooks, MSGBOX_DEFAULT
	closemessage
	release
	end

DraconidArchives_Eventscript_DisplayCaseStonesTop::
	lock
	checkitem ITEM_MEGA_RING, 1
	compare VAR_RESULT, TRUE
	goto_if_eq DraconidArchives_Eventscript_PickMegaStoneTop
	msgbox DraconidArchives_Text_DisplayCaseStones, MSGBOX_SIGN
	release
	end

DraconidArchives_Eventscript_PickMegaStoneTop::
	message DraconidArchives_Text_TopHalfDisplayCase
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_ARCHIVES_MEGA_STONES_GEN_1_2
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, DraconidArchives_EventScript_Venusaurite
	case 1, DraconidArchives_EventScript_CharizarditeX
	case 2, DraconidArchives_EventScript_CharizarditeY
	case 3, DraconidArchives_EventScript_Blastoisinite
	case 4, DraconidArchives_EventScript_Beedrillite
	case 5, DraconidArchives_EventScript_Pidgeotite
	case 6, DraconidArchives_EventScript_Alakazite
	case 7, DraconidArchives_EventScript_Slowbronite
	case 8, DraconidArchives_EventScript_Gengarite
	case 9, DraconidArchives_EventScript_Kangaskhanite
	case 10, DraconidArchives_EventScript_Pinsirite
	case 11, DraconidArchives_EventScript_Gyaradosite
	case 12, DraconidArchives_EventScript_Aerodactylite
	case 13, DraconidArchives_EventScript_MewtwoniteX
	case 14, DraconidArchives_EventScript_MewtwoniteY
	case 15, DraconidArchives_EventScript_Ampharosite
	case 16, DraconidArchives_EventScript_Steelixite
	case 17, DraconidArchives_EventScript_Scizorite
	case 18, DraconidArchives_EventScript_Heracronite
	case 19, DraconidArchives_EventScript_Houndoominite
	case 20, DraconidArchives_EventScript_Tyranitarite
	case 21, DraconidArchives_EventScript_CancelMegaStoneSelect
	goto DraconidArchives_EventScript_CancelMegaStoneSelect
	end

DraconidArchives_Eventscript_DisplayCaseStonesBot::
	lock
	checkitem ITEM_MEGA_RING, 1
	compare VAR_RESULT, TRUE
	goto_if_eq DraconidArchives_Eventscript_PickMegaStoneBot
	msgbox DraconidArchives_Text_DisplayCaseStones, MSGBOX_SIGN
	release
	end

DraconidArchives_Eventscript_PickMegaStoneBot::
	message DraconidArchives_Text_BotHalfDisplayCase
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_ARCHIVES_MEGA_STONES_GEN_3
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, DraconidArchives_EventScript_Sceptilite
	case 1, DraconidArchives_EventScript_Blazikenite
	case 2, DraconidArchives_EventScript_Swampertite
	case 3, DraconidArchives_EventScript_Gardevoirite
	case 4, DraconidArchives_EventScript_Galladite
	case 5, DraconidArchives_EventScript_Sablenite
	case 6, DraconidArchives_EventScript_Mawilite
	case 7, DraconidArchives_EventScript_Aggronite
	case 8, DraconidArchives_EventScript_Medichamite
	case 9, DraconidArchives_EventScript_Manectite
	case 10, DraconidArchives_EventScript_Sharpedonite
	case 11, DraconidArchives_EventScript_Cameruptite
	case 12, DraconidArchives_EventScript_Altarianite
	case 13, DraconidArchives_EventScript_Banettite
	case 14, DraconidArchives_EventScript_Absolite
	case 15, DraconidArchives_EventScript_Glalitite
	case 16, DraconidArchives_EventScript_Salamencite
	case 17, DraconidArchives_EventScript_Metagrossite
	case 18, DraconidArchives_EventScript_Latiasite
	case 19, DraconidArchives_EventScript_Latiosite
	case 20, DraconidArchives_EventScript_CancelMegaStoneSelect
	goto DraconidArchives_EventScript_CancelMegaStoneSelect
	end

DraconidArchives_EventScript_Venusaurite::
	setvar VAR_TEMP_1, 0
	bufferitemname 0, ITEM_VENUSAURITE
	setvar VAR_0x8004, ITEM_VENUSAURITE
	goto DraconidArchives_EventScript_ConfirmTakeMegaStoneTop

DraconidArchives_EventScript_CharizarditeX::
	setvar VAR_TEMP_1, 1
	bufferitemname 0, ITEM_CHARIZARDITE_X
	setvar VAR_0x8004, ITEM_CHARIZARDITE_X
	goto DraconidArchives_EventScript_ConfirmTakeMegaStoneTop

DraconidArchives_EventScript_CharizarditeY::
	setvar VAR_TEMP_1, 2
	bufferitemname 0, ITEM_CHARIZARDITE_Y
	setvar VAR_0x8004, ITEM_CHARIZARDITE_Y
	goto DraconidArchives_EventScript_ConfirmTakeMegaStoneTop

DraconidArchives_EventScript_Blastoisinite::
	setvar VAR_TEMP_1, 3
	bufferitemname 0, ITEM_BLASTOISINITE
	setvar VAR_0x8004, ITEM_BLASTOISINITE
	goto DraconidArchives_EventScript_ConfirmTakeMegaStoneTop

DraconidArchives_EventScript_Beedrillite::
	setvar VAR_TEMP_1, 4
	bufferitemname 0, ITEM_BEEDRILLITE
	setvar VAR_0x8004, ITEM_BEEDRILLITE
	goto DraconidArchives_EventScript_ConfirmTakeMegaStoneTop

DraconidArchives_EventScript_Pidgeotite::
	setvar VAR_TEMP_1, 5
	bufferitemname 0, ITEM_PIDGEOTITE
	setvar VAR_0x8004, ITEM_PIDGEOTITE
	goto DraconidArchives_EventScript_ConfirmTakeMegaStoneTop

DraconidArchives_EventScript_Alakazite::
	setvar VAR_TEMP_1, 6
	bufferitemname 0, ITEM_ALAKAZITE
	setvar VAR_0x8004, ITEM_ALAKAZITE
	goto DraconidArchives_EventScript_ConfirmTakeMegaStoneTop

DraconidArchives_EventScript_Slowbronite::
	setvar VAR_TEMP_1, 7
	bufferitemname 0, ITEM_SLOWBRONITE
	setvar VAR_0x8004, ITEM_SLOWBRONITE
	goto DraconidArchives_EventScript_ConfirmTakeMegaStoneTop

DraconidArchives_EventScript_Gengarite::
	setvar VAR_TEMP_1, 8
	bufferitemname 0, ITEM_GENGARITE
	setvar VAR_0x8004, ITEM_GENGARITE
	goto DraconidArchives_EventScript_ConfirmTakeMegaStoneTop

DraconidArchives_EventScript_Kangaskhanite::
	setvar VAR_TEMP_1, 9
	bufferitemname 0, ITEM_KANGASKHANITE
	setvar VAR_0x8004, ITEM_KANGASKHANITE
	goto DraconidArchives_EventScript_ConfirmTakeMegaStoneTop

DraconidArchives_EventScript_Pinsirite::
	setvar VAR_TEMP_1, 10
	bufferitemname 0, ITEM_PINSIRITE
	setvar VAR_0x8004, ITEM_PINSIRITE
	goto DraconidArchives_EventScript_ConfirmTakeMegaStoneTop

DraconidArchives_EventScript_Gyaradosite::
	setvar VAR_TEMP_1, 11
	bufferitemname 0, ITEM_GYARADOSITE
	setvar VAR_0x8004, ITEM_GYARADOSITE
	goto DraconidArchives_EventScript_ConfirmTakeMegaStoneTop

DraconidArchives_EventScript_Aerodactylite::
	setvar VAR_TEMP_1, 12
	bufferitemname 0, ITEM_AERODACTYLITE
	setvar VAR_0x8004, ITEM_AERODACTYLITE
	goto DraconidArchives_EventScript_ConfirmTakeMegaStoneTop

DraconidArchives_EventScript_MewtwoniteX::
	setvar VAR_TEMP_1, 13
	bufferitemname 0, ITEM_MEWTWONITE_X
	setvar VAR_0x8004, ITEM_MEWTWONITE_X
	goto DraconidArchives_EventScript_ConfirmTakeMegaStoneTop

DraconidArchives_EventScript_MewtwoniteY::
	setvar VAR_TEMP_1, 14
	bufferitemname 0, ITEM_MEWTWONITE_Y
	setvar VAR_0x8004, ITEM_MEWTWONITE_Y
	goto DraconidArchives_EventScript_ConfirmTakeMegaStoneTop

DraconidArchives_EventScript_Ampharosite::
	setvar VAR_TEMP_1, 15
	bufferitemname 0, ITEM_AMPHAROSITE
	setvar VAR_0x8004, ITEM_AMPHAROSITE
	goto DraconidArchives_EventScript_ConfirmTakeMegaStoneTop

DraconidArchives_EventScript_Steelixite::
	setvar VAR_TEMP_1, 16
	bufferitemname 0, ITEM_STEELIXITE
	setvar VAR_0x8004, ITEM_STEELIXITE
	goto DraconidArchives_EventScript_ConfirmTakeMegaStoneTop

DraconidArchives_EventScript_Scizorite::
	setvar VAR_TEMP_1, 17
	bufferitemname 0, ITEM_SCIZORITE
	setvar VAR_0x8004, ITEM_SCIZORITE
	goto DraconidArchives_EventScript_ConfirmTakeMegaStoneTop

DraconidArchives_EventScript_Heracronite::
	setvar VAR_TEMP_1, 18
	bufferitemname 0, ITEM_HERACRONITE
	setvar VAR_0x8004, ITEM_HERACRONITE
	goto DraconidArchives_EventScript_ConfirmTakeMegaStoneTop

DraconidArchives_EventScript_Houndoominite::
	setvar VAR_TEMP_1, 19
	bufferitemname 0, ITEM_HOUNDOOMINITE
	setvar VAR_0x8004, ITEM_HOUNDOOMINITE
	goto DraconidArchives_EventScript_ConfirmTakeMegaStoneTop

DraconidArchives_EventScript_Tyranitarite::
	setvar VAR_TEMP_1, 20
	bufferitemname 0, ITEM_TYRANITARITE
	setvar VAR_0x8004, ITEM_TYRANITARITE
	goto DraconidArchives_EventScript_ConfirmTakeMegaStoneTop

DraconidArchives_EventScript_ConfirmTakeMegaStoneTop::
	msgbox DraconidArchives_Text_TakeTheMegaStone, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq DraconidArchives_EventScript_CancelMegaStoneSelect
	switch VAR_TEMP_1
	case 0, DraconidArchives_EventScript_TakeVenusaurite
	case 1, DraconidArchives_EventScript_TakeCharizarditeX
	case 2, DraconidArchives_EventScript_TakeCharizarditeY
	case 3, DraconidArchives_EventScript_TakeBlastoisinite
	case 4, DraconidArchives_EventScript_TakeBeedrillite
	case 5, DraconidArchives_EventScript_TakePidgeotite
	case 6, DraconidArchives_EventScript_TakeAlakazite
	case 7, DraconidArchives_EventScript_TakeSlowbronite
	case 8, DraconidArchives_EventScript_TakeGengarite
	case 9, DraconidArchives_EventScript_TakeKangaskhanite
	case 10, DraconidArchives_EventScript_TakePinsirite
	case 11, DraconidArchives_EventScript_TakeGyaradosite
	case 12, DraconidArchives_EventScript_TakeAerodactylite
	case 13, DraconidArchives_EventScript_TakeMewtwoniteX
	case 14, DraconidArchives_EventScript_TakeMewtwoniteY
	case 15, DraconidArchives_EventScript_TakeAmpharosite
	case 16, DraconidArchives_EventScript_TakeSteelixite
	case 17, DraconidArchives_EventScript_TakeScizorite
	case 18, DraconidArchives_EventScript_TakeHeracronite
	case 19, DraconidArchives_EventScript_TakeHoundoominite
	case 20, DraconidArchives_EventScript_TakeTyranitarite
	end

DraconidArchives_EventScript_Sceptilite::
	setvar VAR_TEMP_1, 0
	bufferitemname 0, ITEM_SCEPTILITE
	setvar VAR_0x8004, ITEM_SCEPTILITE
	goto DraconidArchives_EventScript_ConfirmTakeMegaStoneBot

DraconidArchives_EventScript_Blazikenite::
	setvar VAR_TEMP_1, 1
	bufferitemname 0, ITEM_BLAZIKENITE
	setvar VAR_0x8004, ITEM_BLAZIKENITE
	goto DraconidArchives_EventScript_ConfirmTakeMegaStoneBot

DraconidArchives_EventScript_Swampertite::
	setvar VAR_TEMP_1, 2
	bufferitemname 0, ITEM_SWAMPERTITE
	setvar VAR_0x8004, ITEM_SWAMPERTITE
	goto DraconidArchives_EventScript_ConfirmTakeMegaStoneBot

DraconidArchives_EventScript_Gardevoirite::
	setvar VAR_TEMP_1, 3
	bufferitemname 0, ITEM_GARDEVOIRITE
	setvar VAR_0x8004, ITEM_GARDEVOIRITE
	goto DraconidArchives_EventScript_ConfirmTakeMegaStoneBot

DraconidArchives_EventScript_Galladite::
	setvar VAR_TEMP_1, 4
	bufferitemname 0, ITEM_GALLADITE
	setvar VAR_0x8004, ITEM_GALLADITE
	goto DraconidArchives_EventScript_ConfirmTakeMegaStoneBot

DraconidArchives_EventScript_Sablenite::
	setvar VAR_TEMP_1, 5
	bufferitemname 0, ITEM_SABLENITE
	setvar VAR_0x8004, ITEM_SABLENITE
	goto DraconidArchives_EventScript_ConfirmTakeMegaStoneBot

DraconidArchives_EventScript_Mawilite::
	setvar VAR_TEMP_1, 6
	bufferitemname 0, ITEM_MAWILITE
	setvar VAR_0x8004, ITEM_MAWILITE
	goto DraconidArchives_EventScript_ConfirmTakeMegaStoneBot

DraconidArchives_EventScript_Aggronite::
	setvar VAR_TEMP_1, 7
	bufferitemname 0, ITEM_AGGRONITE
	setvar VAR_0x8004, ITEM_AGGRONITE
	goto DraconidArchives_EventScript_ConfirmTakeMegaStoneBot

DraconidArchives_EventScript_Medichamite::
	setvar VAR_TEMP_1, 8
	bufferitemname 0, ITEM_MEDICHAMITE
	setvar VAR_0x8004, ITEM_MEDICHAMITE
	goto DraconidArchives_EventScript_ConfirmTakeMegaStoneBot

DraconidArchives_EventScript_Manectite::
	setvar VAR_TEMP_1, 9
	bufferitemname 0, ITEM_MANECTITE
	setvar VAR_0x8004, ITEM_MANECTITE
	goto DraconidArchives_EventScript_ConfirmTakeMegaStoneBot

DraconidArchives_EventScript_Sharpedonite::
	setvar VAR_TEMP_1, 10
	bufferitemname 0, ITEM_SHARPEDONITE
	setvar VAR_0x8004, ITEM_SHARPEDONITE
	goto DraconidArchives_EventScript_ConfirmTakeMegaStoneBot

DraconidArchives_EventScript_Cameruptite::
	setvar VAR_TEMP_1, 11
	bufferitemname 0, ITEM_CAMERUPTITE
	setvar VAR_0x8004, ITEM_CAMERUPTITE
	goto DraconidArchives_EventScript_ConfirmTakeMegaStoneBot

DraconidArchives_EventScript_Altarianite::
	setvar VAR_TEMP_1, 12
	bufferitemname 0, ITEM_ALTARIANITE
	setvar VAR_0x8004, ITEM_ALTARIANITE
	goto DraconidArchives_EventScript_ConfirmTakeMegaStoneBot

DraconidArchives_EventScript_Banettite::
	setvar VAR_TEMP_1, 13
	bufferitemname 0, ITEM_BANETTITE
	setvar VAR_0x8004, ITEM_BANETTITE
	goto DraconidArchives_EventScript_ConfirmTakeMegaStoneBot

DraconidArchives_EventScript_Absolite::
	setvar VAR_TEMP_1, 14
	bufferitemname 0, ITEM_ABSOLITE
	setvar VAR_0x8004, ITEM_ABSOLITE
	goto DraconidArchives_EventScript_ConfirmTakeMegaStoneBot

DraconidArchives_EventScript_Glalitite::
	setvar VAR_TEMP_1, 15
	bufferitemname 0, ITEM_GLALITITE
	setvar VAR_0x8004, ITEM_GLALITITE
	goto DraconidArchives_EventScript_ConfirmTakeMegaStoneBot

DraconidArchives_EventScript_Salamencite::
	setvar VAR_TEMP_1, 16
	bufferitemname 0, ITEM_SALAMENCITE
	setvar VAR_0x8004, ITEM_SALAMENCITE
	goto DraconidArchives_EventScript_ConfirmTakeMegaStoneBot

DraconidArchives_EventScript_Metagrossite::
	setvar VAR_TEMP_1, 17
	bufferitemname 0, ITEM_METAGROSSITE
	setvar VAR_0x8004, ITEM_METAGROSSITE
	goto DraconidArchives_EventScript_ConfirmTakeMegaStoneBot

DraconidArchives_EventScript_Latiasite::
	setvar VAR_TEMP_1, 18
	bufferitemname 0, ITEM_LATIASITE
	setvar VAR_0x8004, ITEM_LATIASITE
	goto DraconidArchives_EventScript_ConfirmTakeMegaStoneBot

DraconidArchives_EventScript_Latiosite::
	setvar VAR_TEMP_1, 19
	bufferitemname 0, ITEM_LATIOSITE
	setvar VAR_0x8004, ITEM_LATIOSITE
	goto DraconidArchives_EventScript_ConfirmTakeMegaStoneBot

DraconidArchives_EventScript_ConfirmTakeMegaStoneBot::
	msgbox DraconidArchives_Text_TakeTheMegaStone, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq DraconidArchives_EventScript_CancelMegaStoneSelect
	switch VAR_TEMP_1
	case 0, DraconidArchives_EventScript_TakeSceptilite
	case 1, DraconidArchives_EventScript_TakeBlazikenite
	case 2, DraconidArchives_EventScript_TakeSwampertite
	case 3, DraconidArchives_EventScript_TakeGardevoirite
	case 4, DraconidArchives_EventScript_TakeGalladite
	case 5, DraconidArchives_EventScript_TakeSablenite
	case 6, DraconidArchives_EventScript_TakeMawilite
	case 7, DraconidArchives_EventScript_TakeAggronite
	case 8, DraconidArchives_EventScript_TakeMedichamite
	case 9, DraconidArchives_EventScript_TakeManectite
	case 10, DraconidArchives_EventScript_TakeSharpedonite
	case 11, DraconidArchives_EventScript_TakeCameruptite
	case 12, DraconidArchives_EventScript_TakeAltarianite
	case 13, DraconidArchives_EventScript_TakeBanettite
	case 14, DraconidArchives_EventScript_TakeAbsolite
	case 15, DraconidArchives_EventScript_TakeGlalitite
	case 16, DraconidArchives_EventScript_TakeSalamencite
	case 17, DraconidArchives_EventScript_TakeMetagrossite
	case 18, DraconidArchives_EventScript_TakeLatiasite
	case 19, DraconidArchives_EventScript_TakeLatiosite
	end

DraconidArchives_EventScript_TakeVenusaurite::
	giveitem ITEM_VENUSAURITE
	closemessage
	release
	end

DraconidArchives_EventScript_TakeCharizarditeX::
	giveitem ITEM_CHARIZARDITE_X
	closemessage
	release
	end

DraconidArchives_EventScript_TakeCharizarditeY::
	giveitem ITEM_CHARIZARDITE_Y
	closemessage
	release
	end

DraconidArchives_EventScript_TakeBlastoisinite::
	giveitem ITEM_BLASTOISINITE
	closemessage
	release
	end

DraconidArchives_EventScript_TakeBeedrillite::
	giveitem ITEM_BEEDRILLITE
	closemessage
	release
	end

DraconidArchives_EventScript_TakePidgeotite::
	giveitem ITEM_PIDGEOTITE
	closemessage
	release
	end

DraconidArchives_EventScript_TakeAlakazite::
	giveitem ITEM_ALAKAZITE
	closemessage
	release
	end

DraconidArchives_EventScript_TakeSlowbronite::
	giveitem ITEM_SLOWBRONITE
	closemessage
	release
	end

DraconidArchives_EventScript_TakeGengarite::
	giveitem ITEM_GENGARITE
	closemessage
	release
	end

DraconidArchives_EventScript_TakeKangaskhanite::
	giveitem ITEM_KANGASKHANITE
	closemessage
	release
	end

DraconidArchives_EventScript_TakePinsirite::
	giveitem ITEM_PINSIRITE
	closemessage
	release
	end

DraconidArchives_EventScript_TakeGyaradosite::
	giveitem ITEM_GYARADOSITE
	closemessage
	release
	end

DraconidArchives_EventScript_TakeAerodactylite::
	giveitem ITEM_AERODACTYLITE
	closemessage
	release
	end

DraconidArchives_EventScript_TakeMewtwoniteX::
	giveitem ITEM_MEWTWONITE_X
	closemessage
	release
	end

DraconidArchives_EventScript_TakeMewtwoniteY::
	giveitem ITEM_MEWTWONITE_Y
	closemessage
	release
	end

DraconidArchives_EventScript_TakeAmpharosite::
	giveitem ITEM_AMPHAROSITE
	closemessage
	release
	end

DraconidArchives_EventScript_TakeSteelixite::
	giveitem ITEM_STEELIXITE
	closemessage
	release
	end

DraconidArchives_EventScript_TakeScizorite::
	giveitem ITEM_SCIZORITE
	closemessage
	release
	end

DraconidArchives_EventScript_TakeHeracronite::
	giveitem ITEM_HERACRONITE
	closemessage
	release
	end

DraconidArchives_EventScript_TakeHoundoominite::
	giveitem ITEM_HOUNDOOMINITE
	closemessage
	release
	end

DraconidArchives_EventScript_TakeTyranitarite::
	giveitem ITEM_TYRANITARITE
	closemessage
	release
	end

DraconidArchives_EventScript_TakeSceptilite::
	giveitem ITEM_SCEPTILITE
	closemessage
	release
	end

DraconidArchives_EventScript_TakeBlazikenite::
	giveitem ITEM_BLAZIKENITE
	closemessage
	release
	end

DraconidArchives_EventScript_TakeSwampertite::
	giveitem ITEM_SWAMPERTITE
	closemessage
	release
	end

DraconidArchives_EventScript_TakeGardevoirite::
	giveitem ITEM_GARDEVOIRITE
	closemessage
	release
	end

DraconidArchives_EventScript_TakeGalladite::
	giveitem ITEM_GALLADITE
	closemessage
	release
	end

DraconidArchives_EventScript_TakeSablenite::
	giveitem ITEM_SABLENITE
	closemessage
	release
	end

DraconidArchives_EventScript_TakeMawilite::
	giveitem ITEM_MAWILITE
	closemessage
	release
	end

DraconidArchives_EventScript_TakeAggronite::
	giveitem ITEM_AGGRONITE
	closemessage
	release
	end

DraconidArchives_EventScript_TakeMedichamite::
	giveitem ITEM_MEDICHAMITE
	closemessage
	release
	end

DraconidArchives_EventScript_TakeManectite::
	giveitem ITEM_MANECTITE
	closemessage
	release
	end

DraconidArchives_EventScript_TakeSharpedonite::
	giveitem ITEM_SHARPEDONITE
	closemessage
	release
	end

DraconidArchives_EventScript_TakeCameruptite::
	giveitem ITEM_CAMERUPTITE
	closemessage
	release
	end

DraconidArchives_EventScript_TakeAltarianite::
	giveitem ITEM_ALTARIANITE
	closemessage
	release
	end

DraconidArchives_EventScript_TakeBanettite::
	giveitem ITEM_BANETTITE
	closemessage
	release
	end

DraconidArchives_EventScript_TakeAbsolite::
	giveitem ITEM_ABSOLITE
	closemessage
	release
	end

DraconidArchives_EventScript_TakeGlalitite::
	giveitem ITEM_GLALITITE
	closemessage
	release
	end

DraconidArchives_EventScript_TakeSalamencite::
	giveitem ITEM_SALAMENCITE
	closemessage
	release
	end

DraconidArchives_EventScript_TakeMetagrossite::
	giveitem ITEM_METAGROSSITE
	closemessage
	release
	end

DraconidArchives_EventScript_TakeLatiasite::
	giveitem ITEM_LATIASITE
	closemessage
	release
	end

DraconidArchives_EventScript_TakeLatiosite::
	giveitem ITEM_LATIOSITE
	closemessage
	release
	end

DraconidArchives_EventScript_CancelMegaStoneSelect::
	closemessage
	release
	end

DraconidArchives_Eventscript_DisplayCaseInstrument::
	msgbox DraconidArchives_Text_DisplayCaseInstrument, MSGBOX_SIGN
	end

DraconidArchives_Eventscript_Scroll::
	msgbox DraconidArchives_Text_Scroll, MSGBOX_SIGN
	end

DraconidArchives_Eventscript_Book::
	msgbox DraconidArchives_Text_Book, MSGBOX_SIGN
	end

DraconidArchives_Text_TopHalfDisplayCase:
	.string "The top half of the display case\n"
	.string "displays a wide variety of Mega Stones.\p"
	.string "They are labelled “Kanto” and “Johto”.\n"
	.string "Pick one?$"

DraconidArchives_Text_BotHalfDisplayCase:
	.string "The bottom half of the display case\n"
	.string "displays a wide variety of Mega Stones.\p"
	.string "They are labelled “Hoenn”.\n"
	.string "Pick one?$"

DraconidArchives_Text_TakeTheMegaStone:
	.string "Take the {STR_VAR_1}?$"

DraconidArchives_Text_BeatenDeoxys:
	.string "Zinnia: {PLAYER}!\p"
	.string "I can tell from the way you strode in\n"
	.string "here that you beat Deoxys.\p"
	.string "It looks like everything has finally\n"
	.string "been brought to an end.\l"
	.string "I thank you for that.\p"
	.string "As part of my appreciation, please\n"
	.string "be the proud owner of one of our\l"
	.string "treasured artifacts, the Mega Ring.$"

DraconidArchives_Text_MegaEvolutionDescription:
	.string "Certain species of Pokémon are able to\n"
	.string "temporarily transform into much\l"
	.string "stronger forms with the Mega Ring.\p"
	.string "They will also need to hold a\n"
	.string "Mega Stone to do it.\p"
	.string "You can find two sets of Mega Stones\n"
	.string "in those cases over there.\l"
	.string "Feel free to borrow them.\p"
	.string "I've returned to my duties as\n"
	.string "Lorekeeper, here in Fallarbor.\l"
	.string "You are welcome to see me anytime!$"

DraconidArchives_Text_NoSnacksForAster:
	.string "Zinnia: Oh, Aster!\n"
	.string "I don't have any snacks for you, and I\l"
	.string "just don't have the time to find them.$"

DraconidArchives_Text_BringSnacksForAster:
	.string "Zinnia: Actually, that gives me an\n"
	.string "idea.\p"
	.string "{PLAYER}, you have met many legendary\n"
	.string "Pokémon on your travels, haven't you?\p"
	.string "With my particular skills, I can give\n"
	.string "you the opportunity to meet them again.\p"
	.string "If you can get me some tasty treats for\n"
	.string "my Aster here, I can call any and all\l"
	.string "legendary Pokémon back to their lairs.\p"
	.string "Aster has rather expensive taste.\n"
	.string "She'll only eat very rare berries, like\l"
	.string "the ones that reduce damage taken.\p"
	.string "Come back when you have 5 of a kind.$"

DraconidArchives_Text_HaveYouBroughtBerries:
	.string "Zinnia: Hey, {PLAYER}.\n"
	.string "It's good to see you.\p"
	.string "Did you bring some treats for Aster?$"

DraconidArchives_Text_SomeOtherTime:
	.string "Zinnia: Perhaps another time then.$"

DraconidArchives_Text_YouDoNotHaveThisBerry:
	.string "You do not have enough of this berry.$"

DraconidArchives_Text_YoullGiveXBerry:
	.string "You'll give me your {STR_VAR_1}?$"

DraconidArchives_Text_ManyThanksRespawningLegendaries:
	.string "Zinnia: Thanks.\n"
	.string "Aster is going to love it!\p"
	.string "I'll call the legendary Pokémon back to\n"
	.string "their lairs right away.$"

DraconidArchives_Text_WelcomeToArchives:
	.string "Welcome to the Draconid Archives.\n"
	.string "It is good to see a new visitor.\p"
	.string "Feel free to look through our library of\n"
	.string "materials as you wish.\p"
	.string "However since our Lorekeeper has run\n"
	.string "off somewhere, other services are\l"
	.string "currently unavailable.$"

DraconidArchives_Text_LorekeeperReturned:
	.string "Welcome to the Draconid Archives.\n"
	.string "Feel free to look through our library of\l"
	.string "materials as you wish.$"

DraconidArchives_Text_FairyTales:
	.string "Hello, have you come here for the\n"
	.string "old stories too?\l"
	.string "The Galarian fairy tales are my\l"
	.string "favorites!$"

DraconidArchives_Text_CouldTextShowTreasures:
	.string "I wonder if one of these dusty old tomes\n"
	.string "can lead me to treasure, or rare and\l"
	.string "powerful Pokémon.$"

DraconidArchives_Text_MapFellOut:
	.string "I can't believe records of accounts\n"
	.string "and contracts from thousands of years\l"
	.string "ago still exist to this day!\l"
	.string "I'm going to enjoy spending time here.\p"
	.string "Huh? Some piece of parchment fell out of\n"
	.string "this ledger…\p"
	.string "…it's some kind of map?\p"
	.string "This doesn't seem to have anything to do\n"
	.string "with the accounts.\p"
	.string "This should be put elsewhere.\n"
	.string "Do you mind taking this?$"

DraconidArchives_Text_TooAbsorbedInBooks:
	.string "… … … … … …\p"
	.string "This person is too absorbed in books\n"
	.string "to notice you.$"

DraconidArchives_Text_DisplayCaseStones:
	.string "The display case contains numerous\n"
	.string "colorful spherical stones.$"

DraconidArchives_Text_DisplayCaseInstrument:
	.string "The display case contains a very\n"
	.string "elegant looking stringed instrument.$"

DraconidArchives_Text_Scroll:
	.string "A scroll written in an ancient\n"
	.string "language you don't understand.\p"
	.string "The illustration depicts some monstrous\n"
	.string "looking Pokémon engaged in an epic\l"
	.string "battle.$"

DraconidArchives_Text_Book:
	.string "A book on historical meteorite events.\n"
	.string "There's lots of metaphorical\l"
	.string "descriptions in here.$"
