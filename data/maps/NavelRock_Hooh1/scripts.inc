NavelRock_Hooh1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, NavelRock_Hooh1_OnLoad
	.byte 0

NavelRock_Hooh1_OnLoad::
	compare VAR_NAVEL_ROCK_BOULDER_BUTTON_1, 100
	call_if_eq NavelRock_Hooh1_Eventscript_OpenDoor
	call_if_set FLAG_NAVEL_ROCK_HOOH_HIDE_BOULDER2, NavelRock_Hooh1_Eventscript_ShowBoulder
	end

NavelRock_Hooh1_Eventscript_OpenDoor::
	setmetatile 7, 4, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 8, 4, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 7, 5, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 8, 5, METATILE_NavelRock_GoldCave_Floor, 0
	return

NavelRock_Hooh1_Eventscript_ShowBoulder::
	clearflag FLAG_NAVEL_ROCK_HOOH_HIDE_BOULDER1
	return

NavelRock_Hooh1_Eventscript_BoulderSwitch1::
	lockall
	compare VAR_NAVEL_ROCK_BOULDER_BUTTON_1, 100
	goto_if_eq NavelRock_Hooh1_Eventscript_BoulderSwitch1_AlreadyPressed
	setmetatile 7, 4, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 8, 4, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 7, 5, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 8, 5, METATILE_NavelRock_GoldCave_Floor, 0
	playse SE_BANG
	special DrawWholeMapView
	waitse
	setvar VAR_NAVEL_ROCK_BOULDER_BUTTON_1, 100
NavelRock_Hooh1_Eventscript_BoulderSwitch1_AlreadyPressed::
	releaseall
	end

NavelRock_Hooh1_Eventscript_BoulderSwitch2::
	lockall
	compare VAR_NAVEL_ROCK_BOULDER_BUTTON_2, 100
	goto_if_eq NavelRock_Hooh1_Eventscript_BoulderSwitch2_AlreadyPressed
	playse SE_BANG
	waitse
	setvar VAR_NAVEL_ROCK_BOULDER_BUTTON_2, 100
NavelRock_Hooh1_Eventscript_BoulderSwitch2_AlreadyPressed::
	releaseall
	end
