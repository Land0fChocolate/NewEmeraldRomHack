.set LOCALID_FOSSIL_1, 1
.set LOCALID_FOSSIL_2, 2
.set LOCALID_FOSSIL_3, 3
.set LOCALID_FOSSIL_4, 4
.set LOCALID_FOSSIL_5, 5
.set LOCALID_FOSSIL_6, 6
.set LOCALID_FOSSIL_7, 7

DesertUnderpass_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DesertUnderpass_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, DesertUnderpass_OnLoad
	.byte 0

DesertUnderpass_OnTransition:
	setflag FLAG_LANDMARK_DESERT_UNDERPASS
	end

DesertUnderpass_OnLoad:
	dotimebasedevents
	goto_if_set FLAG_DAILY_DESERT_UNDERPASS_FOSSIL, Common_EventScript_NopReturn
	random 7
	copyvar VAR_0x800A, VAR_RESULT
	switch VAR_RESULT
	case 0, DesertUnderpass_EventScript_LoadFossil1
	case 1, DesertUnderpass_EventScript_LoadFossil2
	case 2, DesertUnderpass_EventScript_LoadFossil3
	case 3, DesertUnderpass_EventScript_LoadFossil4
	case 4, DesertUnderpass_EventScript_LoadFossil5
	case 5, DesertUnderpass_EventScript_LoadFossil6
	case 6, DesertUnderpass_EventScript_LoadFossil7
	end

DesertUnderpass_EventScript_LoadFossil1::
	clearflag FLAG_HIDE_DAILY_DESERT_UNDERPASS_FOSSIL_1
	setflag FLAG_DAILY_DESERT_UNDERPASS_FOSSIL
	end

DesertUnderpass_EventScript_LoadFossil2::
	clearflag FLAG_HIDE_DAILY_DESERT_UNDERPASS_FOSSIL_2
	setflag FLAG_DAILY_DESERT_UNDERPASS_FOSSIL
	end

DesertUnderpass_EventScript_LoadFossil3::
	clearflag FLAG_HIDE_DAILY_DESERT_UNDERPASS_FOSSIL_3
	setflag FLAG_DAILY_DESERT_UNDERPASS_FOSSIL
	end

DesertUnderpass_EventScript_LoadFossil4::
	clearflag FLAG_HIDE_DAILY_DESERT_UNDERPASS_FOSSIL_4
	setflag FLAG_DAILY_DESERT_UNDERPASS_FOSSIL
	end

DesertUnderpass_EventScript_LoadFossil5::
	clearflag FLAG_HIDE_DAILY_DESERT_UNDERPASS_FOSSIL_5
	setflag FLAG_DAILY_DESERT_UNDERPASS_FOSSIL
	end

DesertUnderpass_EventScript_LoadFossil6::
	clearflag FLAG_HIDE_DAILY_DESERT_UNDERPASS_FOSSIL_6
	setflag FLAG_DAILY_DESERT_UNDERPASS_FOSSIL
	end

DesertUnderpass_EventScript_LoadFossil7::
	clearflag FLAG_HIDE_DAILY_DESERT_UNDERPASS_FOSSIL_7
	setflag FLAG_DAILY_DESERT_UNDERPASS_FOSSIL
	end

DesertUnderpass_EventScript_DailyFossil::
	random 5
	copyvar VAR_0x800A, VAR_RESULT
	switch VAR_RESULT
	case 0, DesertUnderpass_EventScript_ClaimDomeFossil
	case 1, DesertUnderpass_EventScript_ClaimHelixFossil
	case 2, DesertUnderpass_EventScript_ClaimOldAmber
	case 3, DesertUnderpass_EventScript_ClaimClawFossil
	case 4, DesertUnderpass_EventScript_ClaimRootFossil
	end

DesertUnderpass_EventScript_ClaimDomeFossil::
	lock
	faceplayer
	giveitem ITEM_DOME_FOSSIL
	goto DesertUnderpass_EventScript_RemoveFossils
	end

DesertUnderpass_EventScript_ClaimHelixFossil::
	lock
	faceplayer
	giveitem ITEM_HELIX_FOSSIL
	goto DesertUnderpass_EventScript_RemoveFossils
	end

DesertUnderpass_EventScript_ClaimOldAmber::
	lock
	faceplayer
	giveitem ITEM_OLD_AMBER
	goto DesertUnderpass_EventScript_RemoveFossils
	end

DesertUnderpass_EventScript_ClaimClawFossil::
	lock
	faceplayer
	giveitem ITEM_CLAW_FOSSIL
	goto DesertUnderpass_EventScript_RemoveFossils
	end

DesertUnderpass_EventScript_ClaimRootFossil::
	lock
	faceplayer
	giveitem ITEM_ROOT_FOSSIL
	goto DesertUnderpass_EventScript_RemoveFossils
	end

DesertUnderpass_EventScript_RemoveFossils::
	removeobject LOCALID_FOSSIL_1
	removeobject LOCALID_FOSSIL_2
	removeobject LOCALID_FOSSIL_3
	removeobject LOCALID_FOSSIL_4
	removeobject LOCALID_FOSSIL_5
	removeobject LOCALID_FOSSIL_6
	removeobject LOCALID_FOSSIL_7
	setflag FLAG_HIDE_DAILY_DESERT_UNDERPASS_FOSSIL_1
	setflag FLAG_HIDE_DAILY_DESERT_UNDERPASS_FOSSIL_2
	setflag FLAG_HIDE_DAILY_DESERT_UNDERPASS_FOSSIL_3
	setflag FLAG_HIDE_DAILY_DESERT_UNDERPASS_FOSSIL_4
	setflag FLAG_HIDE_DAILY_DESERT_UNDERPASS_FOSSIL_5
	setflag FLAG_HIDE_DAILY_DESERT_UNDERPASS_FOSSIL_6
	setflag FLAG_HIDE_DAILY_DESERT_UNDERPASS_FOSSIL_7
	release
	end
