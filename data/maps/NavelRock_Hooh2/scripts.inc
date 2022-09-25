NavelRock_Hooh2_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, NavelRock_Hooh2_OnLoad
	.byte 0

NavelRock_Hooh2_OnLoad::
	compare VAR_NAVEL_ROCK_BOULDER_BUTTON_2, 100
	call_if_eq NavelRock_Hooh2_Eventscript_OpenDoor1
	compare VAR_NAVEL_ROCK_BOULDER_BUTTON_3, 100
	call_if_eq NavelRock_Hooh2_Eventscript_OpenDoor2
	compare VAR_NAVEL_ROCK_BOULDER_BUTTON_4, 100
	call_if_eq NavelRock_Hooh2_Eventscript_OpenDoor3
	end

NavelRock_Hooh2_Eventscript_OpenDoor1::
	setmetatile 23, 22, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 24, 22, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 23, 23, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 24, 23, METATILE_NavelRock_GoldCave_Floor, 0
	return

NavelRock_Hooh2_Eventscript_OpenDoor2::
	setmetatile 23, 19, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 24, 19, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 23, 20, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 24, 20, METATILE_NavelRock_GoldCave_Floor, 0
	return

NavelRock_Hooh2_Eventscript_OpenDoor3::
	setmetatile 23, 16, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 24, 16, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 23, 17, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 24, 17, METATILE_NavelRock_GoldCave_Floor, 0
	return

NavelRock_Hooh2_Eventscript_BoulderSwitch3::
	lockall
	compare VAR_NAVEL_ROCK_BOULDER_BUTTON_3, 100
	goto_if_eq NavelRock_Hooh2_Eventscript_BoulderSwitch3_AlreadyPressed
	setmetatile 23, 19, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 24, 19, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 23, 20, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 24, 20, METATILE_NavelRock_GoldCave_Floor, 0
	playse SE_BANG
	special DrawWholeMapView
	waitse
	setvar VAR_NAVEL_ROCK_BOULDER_BUTTON_3, 100
NavelRock_Hooh2_Eventscript_BoulderSwitch3_AlreadyPressed::
	releaseall
	end

@TODO: remove
NavelRock_Hooh2_Eventscript_TestAbra::
	clearflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_1
	clearflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_2
	clearflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_3
	clearflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_4
	clearflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_5
	clearflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_6
	clearflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_7
	clearflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_8
	clearflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_9
	clearflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_10
	clearflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_11
	clearflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_12
	clearflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_13
	clearflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_14
	clearflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_15
	clearflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_16
	clearflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_17
	clearflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_18
	clearflag FLAG_NAVEL_ROCK_HOOH_PUZZLE_EXIT_1
	clearflag FLAG_NAVEL_ROCK_HOOH_PUZZLE_EXIT_2
	end
