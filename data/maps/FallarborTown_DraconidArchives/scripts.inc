.set LOCALID_WHISMUR, 3
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
	checkitem ITEM_CHILAN_BERRY, 1
	compare VAR_RESULT, FALSE
	call_if_eq DraconidArchives_EventScript_YouDoNotHaveThisBerry
	setvar VAR_0x8008, ITEM_CHILAN_BERRY
	goto DraconidArchives_EventScript_GiveBerry

DraconidArchives_EventScript_OccaBerry::
	checkitem ITEM_OCCA_BERRY, 1
	compare VAR_RESULT, FALSE
	call_if_eq DraconidArchives_EventScript_YouDoNotHaveThisBerry
	setvar VAR_0x8008, ITEM_OCCA_BERRY
	goto DraconidArchives_EventScript_GiveBerry

DraconidArchives_EventScript_PasshoBerry::
	checkitem ITEM_PASSHO_BERRY, 1
	compare VAR_RESULT, FALSE
	call_if_eq DraconidArchives_EventScript_YouDoNotHaveThisBerry
	setvar VAR_0x8008, ITEM_PASSHO_BERRY
	goto DraconidArchives_EventScript_GiveBerry

DraconidArchives_EventScript_WacanBerry::
	checkitem ITEM_WACAN_BERRY, 1
	compare VAR_RESULT, FALSE
	call_if_eq DraconidArchives_EventScript_YouDoNotHaveThisBerry
	setvar VAR_0x8008, ITEM_WACAN_BERRY
	goto DraconidArchives_EventScript_GiveBerry

DraconidArchives_EventScript_RindoBerry::
	checkitem ITEM_RINDO_BERRY, 1
	compare VAR_RESULT, FALSE
	call_if_eq DraconidArchives_EventScript_YouDoNotHaveThisBerry
	setvar VAR_0x8008, ITEM_RINDO_BERRY
	goto DraconidArchives_EventScript_GiveBerry

DraconidArchives_EventScript_YacheBerry::
	checkitem ITEM_YACHE_BERRY, 1
	compare VAR_RESULT, FALSE
	call_if_eq DraconidArchives_EventScript_YouDoNotHaveThisBerry
	setvar VAR_0x8008, ITEM_YACHE_BERRY
	goto DraconidArchives_EventScript_GiveBerry

DraconidArchives_EventScript_ChopleBerry::
	checkitem ITEM_CHOPLE_BERRY, 1
	compare VAR_RESULT, FALSE
	call_if_eq DraconidArchives_EventScript_YouDoNotHaveThisBerry
	setvar VAR_0x8008, ITEM_CHOPLE_BERRY
	goto DraconidArchives_EventScript_GiveBerry

DraconidArchives_EventScript_KebiaBerry::
	checkitem ITEM_KEBIA_BERRY, 1
	compare VAR_RESULT, FALSE
	call_if_eq DraconidArchives_EventScript_YouDoNotHaveThisBerry
	setvar VAR_0x8008, ITEM_KEBIA_BERRY
	goto DraconidArchives_EventScript_GiveBerry

DraconidArchives_EventScript_ShucaBerry::
	checkitem ITEM_SHUCA_BERRY, 1
	compare VAR_RESULT, FALSE
	call_if_eq DraconidArchives_EventScript_YouDoNotHaveThisBerry
	setvar VAR_0x8008, ITEM_SHUCA_BERRY
	goto DraconidArchives_EventScript_GiveBerry

DraconidArchives_EventScript_CobaBerry::
	checkitem ITEM_COBA_BERRY, 1
	compare VAR_RESULT, FALSE
	call_if_eq DraconidArchives_EventScript_YouDoNotHaveThisBerry
	setvar VAR_0x8008, ITEM_COBA_BERRY
	goto DraconidArchives_EventScript_GiveBerry

DraconidArchives_EventScript_PayapaBerry::
	checkitem ITEM_PAYAPA_BERRY, 1
	compare VAR_RESULT, FALSE
	call_if_eq DraconidArchives_EventScript_YouDoNotHaveThisBerry
	setvar VAR_0x8008, ITEM_PAYAPA_BERRY
	goto DraconidArchives_EventScript_GiveBerry

DraconidArchives_EventScript_TangaBerry::
	checkitem ITEM_TANGA_BERRY, 1
	compare VAR_RESULT, FALSE
	call_if_eq DraconidArchives_EventScript_YouDoNotHaveThisBerry
	setvar VAR_0x8008, ITEM_TANGA_BERRY
	goto DraconidArchives_EventScript_GiveBerry

DraconidArchives_EventScript_ChartiBerry::
	checkitem ITEM_CHARTI_BERRY, 1
	compare VAR_RESULT, FALSE
	call_if_eq DraconidArchives_EventScript_YouDoNotHaveThisBerry
	setvar VAR_0x8008, ITEM_CHARTI_BERRY
	goto DraconidArchives_EventScript_GiveBerry

DraconidArchives_EventScript_KasibBerry::
	checkitem ITEM_KASIB_BERRY, 1
	compare VAR_RESULT, FALSE
	call_if_eq DraconidArchives_EventScript_YouDoNotHaveThisBerry
	setvar VAR_0x8008, ITEM_KASIB_BERRY
	goto DraconidArchives_EventScript_GiveBerry

DraconidArchives_EventScript_HabanBerry::
	checkitem ITEM_HABAN_BERRY, 1
	compare VAR_RESULT, FALSE
	call_if_eq DraconidArchives_EventScript_YouDoNotHaveThisBerry
	setvar VAR_0x8008, ITEM_HABAN_BERRY
	goto DraconidArchives_EventScript_GiveBerry

DraconidArchives_EventScript_ColburBerry::
	checkitem ITEM_COLBUR_BERRY, 1
	compare VAR_RESULT, FALSE
	call_if_eq DraconidArchives_EventScript_YouDoNotHaveThisBerry
	setvar VAR_0x8008, ITEM_COLBUR_BERRY
	goto DraconidArchives_EventScript_GiveBerry

DraconidArchives_EventScript_BabiriBerry::
	checkitem ITEM_BABIRI_BERRY, 1
	compare VAR_RESULT, FALSE
	call_if_eq DraconidArchives_EventScript_YouDoNotHaveThisBerry
	setvar VAR_0x8008, ITEM_BABIRI_BERRY
	goto DraconidArchives_EventScript_GiveBerry

DraconidArchives_EventScript_RoseliBerry::
	checkitem ITEM_ROSELI_BERRY, 1
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
	removeitem VAR_0x8008, 1
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
	clearflag FLAG_DEFEATED_ZAPDOS
	clearflag FLAG_DEFEATED_MOLTRES
	clearflag FLAG_DEFEATED_MEW
	clearflag FLAG_DEFEATED_RAIKOU
	clearflag FLAG_DEFEATED_ENTEI
	clearflag FLAG_DEFEATED_SUICUNE
	clearflag FLAG_DEFEATED_LUGIA
	clearflag FLAG_DEFEATED_HO_OH
	clearflag FLAG_DEFEATED_CELEBI
	clearflag FLAG_DEFEATED_LATIAS
	clearflag FLAG_DEFEATED_LATIOS
	clearflag FLAG_DEFEATED_REGIROCK
	clearflag FLAG_DEFEATED_REGICE
	clearflag FLAG_DEFEATED_REGISTEEL
	clearflag FLAG_DEFEATED_KYOGRE
	clearflag FLAG_DEFEATED_GROUDON
	clearflag FLAG_DEFEATED_RAYQUAZA
	clearflag FLAG_DEFEATED_DEOXYS
	clearflag FLAG_BATTLED_DEOXYS
	call_if_set FLAG_PLACED_WISH_TAG, DraconidArchives_EventScript_ResetJirachi
	return

DraconidArchives_EventScript_ResetJirachi::
	clearflag FLAG_DEFEATED_JIRACHI
	clearflag FLAG_HIDE_SLATEPORT_CITY_JIRACHI
	return

DraconidArchives_EventScript_ZinniaDeoxysBeaten::
	msgbox DraconidArchives_Text_BeatingDeoxys, MSGBOX_DEFAULT
	release
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
	closemessage
	giveitem ITEM_OLD_SEA_MAP
	setflag FLAG_RECEIVED_OLD_SEA_MAP
	release
	end

DraconidArchives_Eventscript_ScientistAbsorbedInBooks::
	msgbox DraconidArchives_Text_TooAbsorbedInBooks, MSGBOX_DEFAULT
	closemessage
	release
	end

DraconidArchives_Eventscript_Sculpture::
	msgbox DraconidArchives_Text_Sculpture, MSGBOX_SIGN
	end

DraconidArchives_Eventscript_DisplayCase::
	msgbox DraconidArchives_Text_DisplayCase, MSGBOX_SIGN
	end

DraconidArchives_Eventscript_Scroll::
	msgbox DraconidArchives_Text_Scroll, MSGBOX_SIGN
	end

DraconidArchives_Eventscript_Book::
	msgbox DraconidArchives_Text_Book, MSGBOX_SIGN
	end

DraconidArchives_Text_BeatingDeoxys:
	.string "Zinnia: {PLAYER}!\p"
	.string "I can tell from the way you strode in\n"
	.string "here that you beat Deoxys.\p"
	.string "It looks like everything has finally\n"
	.string "been brought to an end.\l"
	.string "I thank you for that.\p"
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
	.string "If you can get me a tasty treat for my\n"
	.string "Aster here, I can call any and all\l"
	.string "legendary Pokémon back to their lairs.\p"
	.string "Aster has rather expensive taste.\n"
	.string "He'll only eat very rare berries, like\l"
	.string "the ones that reduce damage taken.$"

DraconidArchives_Text_HaveYouBroughtBerries:
	.string "Zinnia: Hey, {PLAYER}.\n"
	.string "It's good to see you.\p"
	.string "Did you bring a treat for Aster?$"

DraconidArchives_Text_SomeOtherTime:
	.string "Zinnia: Perhaps another time then.$"

DraconidArchives_Text_YouDoNotHaveThisBerry:
	.string "You do not have this berry.$"

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
	.string "… … … … … …\n"
	.string "This person is too absorbed in books\l"
	.string "to notice you.$"

DraconidArchives_Text_Sculpture:
	.string "A worn down looking statue.$"

DraconidArchives_Text_DisplayCase:
	.string "The display case contains a very\n"
	.string "elegant looking stringed instrument.$"

DraconidArchives_Text_Scroll:
	.string "A scroll written in a primitive language\n"
	.string "you don't understand. The illustration\l"
	.string "depicts some monstrous looking Pokémon\l"
	.string "engaged in an epic battle.$"

DraconidArchives_Text_Book:
	.string "A book on historical meteorite events.\n"
	.string "There's lots of metaphorical\l"
	.string "descriptions in here.$"
