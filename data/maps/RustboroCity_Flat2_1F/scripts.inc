RustboroCity_Flat2_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, RustboroCity_Flat2_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_Flat2_1F_OnTransition
	.byte 0

RustboroCity_Flat2_1F_OnLoad::
	compare VAR_BOULDER_SWITCH_1, 1
	call_if_eq RustboroCity_Flat2_1F_Eventscript_SetTrickHouseDoorTest
	end

RustboroCity_Flat2_1F_Eventscript_SetTrickHouseDoorTest::
	setmetatile 5, 2, METATILE_GenericBuilding_TrickHouse_Door_Closed, 1
	return

RustboroCity_Flat2_1F_OnTransition::
	call_if_set FLAG_HIDE_BOULDER2, RustboroCity_Flat2_1F_Eventscript_ShowBoulder
	end

RustboroCity_Flat2_1F_Eventscript_BoulderSwitch::
	compare VAR_BOULDER_SWITCH_1, 1
	goto_if_eq RustboroCity_Flat2_1F_Eventscript_BoulderSwitchAlreadyPressed
	setmetatile 5, 2, METATILE_GenericBuilding_TrickHouse_Stairs_Down, 0
	playse SE_ICE_BREAK
	special DrawWholeMapView
	waitse
	setvar VAR_BOULDER_SWITCH_1, 1
RustboroCity_Flat2_1F_Eventscript_BoulderSwitchAlreadyPressed::
	releaseall
	end

RustboroCity_Flat2_1F_Eventscript_ShowBoulder::
	clearflag FLAG_HIDE_BOULDER1
	end

RustboroCity_Flat2_1F_EventScript_OldWoman::
	msgbox RustboroCity_Flat2_1F_Text_DevonWorkersLiveHere, MSGBOX_NPC
	end

RustboroCity_Flat2_1F_Text_DevonWorkersLiveHere:
	.string "Devon Corporation's workers live in\n"
	.string "this building.$"
