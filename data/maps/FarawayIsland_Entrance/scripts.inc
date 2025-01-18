.set LOCALID_SAILOR, 1
.set LOCALID_SS_TIDAL, 2

FarawayIsland_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FarawayIsland_Entrance_OnTransition
	.byte 0

FarawayIsland_Entrance_OnTransition:
	setflag FLAG_ARRIVED_ON_FARAWAY_ISLAND
	end

FarawayIsland_Entrance_EventScript_SetCloudsWeather::
	setweather WEATHER_SUNNY_CLOUDS
	doweather
	end

FarawayIsland_Entrance_EventScript_ClearWeather::
	setweather WEATHER_NONE
	doweather
	end

FarawayIsland_EventScript_Brice::
	trainerbattle_single TRAINER_BRICE, FarawayIsland_Text_BriceIntro, FarawayIsland_Text_BriceDefeat
	msgbox FarawayIsland_Text_BricePostBattle, MSGBOX_AUTOCLOSE
	end

FarawayIsland_Entrance_EventScript_TMCheckTrigger::
	lock
	goto_if_unset FLAG_OBTAINED_ALL_TMS_FOR_FARAWAY_ISLAND, FarawayIsland_Entrance_EventScript_CheckForEveryTM
FarawayIsland_Entrance_EventScript_TMCheckFail::
	msgbox FarawayIsland_Entrance_Text_ObtainAllTMsToProceed, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	release
	end

FarawayIsland_Entrance_EventScript_CheckForEveryTM::
	setvar VAR_TEMP_1, 0
	checkitem ITEM_TM01, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM02, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM03, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM04, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM05, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM06, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM07, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM08, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM09, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM10, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM11, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM12, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM13, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM14, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM15, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM16, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM17, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM18, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM19, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM20, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM21, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM22, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM23, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM24, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM25, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM26, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM27, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM28, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM29, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM30, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM31, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM32, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM33, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM34, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM35, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM36, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM37, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM38, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM39, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM40, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM41, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM42, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM43, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM44, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM45, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM46, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM47, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM48, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM49, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM50, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM51, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM52, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM53, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM54, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM55, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM56, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM57, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM58, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM59, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM60, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM61, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM62, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM63, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM64, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM65, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM66, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM67, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM68, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM69, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM70, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM71, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM72, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM73, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM74, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM75, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM76, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM77, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM78, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM79, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM80, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM81, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM82, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM83, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM84, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM85, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM86, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM87, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM88, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM89, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM90, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM91, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM92, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM93, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM94, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM95, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM96, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM97, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM98, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	checkitem ITEM_TM99, 1
	compare VAR_RESULT, TRUE
	call_if_eq FarawayIsland_Entrance_EventScript_AddToTMCount
	compare VAR_TEMP_1, 99
	goto_if_ge FarawayIsland_Entrance_EventScript_TMCheckPass
	goto FarawayIsland_Entrance_EventScript_TMCheckFail
	end

FarawayIsland_Entrance_EventScript_AddToTMCount::
	addvar VAR_TEMP_1, 1
	return

FarawayIsland_Entrance_EventScript_TMCheckPass::
	setflag FLAG_OBTAINED_ALL_TMS_FOR_FARAWAY_ISLAND
	setvar VAR_FARAWAY_ISLAND_TRIGGER, 1
	release
	end

FarawayIsland_Entrance_EventScript_Sailor::
	lock
	faceplayer
	msgbox FarawayIsland_Entrance_Text_SailorReturn, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq FarawayIsland_Entrance_EventScript_AsYouLike
	msgbox EventTicket_Text_SailHome, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	delay 30
	hideobjectat LOCALID_SAILOR, MAP_FARAWAY_ISLAND_ENTRANCE
	setvar VAR_0x8004, LOCALID_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	warp MAP_LILYCOVE_CITY_HARBOR, 255, 8, 11
	waitstate
	release
	end

FarawayIsland_Entrance_EventScript_AsYouLike::
	msgbox EventTicket_Text_AsYouLike, MSGBOX_DEFAULT
	release
	end

FarawayIsland_Entrance_EventScript_Sign::
	msgbox FarawayIsland_Entrance_Text_Sign, MSGBOX_SIGN
	end

FarawayIsland_Entrance_Text_ObtainAllTMsToProceed:
	.string "Only those who are capable of\n"
	.string "teaching 99 moves, may proceed.$"
