.set LOCALID_RAIKOU, 1

ConquerorsCamp_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, ConquerorsCamp_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, ConquerorsCamp_OnTransition
	.byte 0

ConquerorsCamp_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, ConquerorsCamp_EventScript_TryRemoveRaikou
	end

ConquerorsCamp_OnTransition:
	setflag FLAG_LANDMARK_CONQUERORS_CAMP
	end

ConquerorsCamp_EventScript_TryRemoveRaikou::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject LOCALID_RAIKOU
	return

ConquerorsCamp_Eventscript_Raikou::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_RAIKOU, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_RAIKOU, 50, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq ConquerorsCamp_EventScript_DefeatedRaikou
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq ConquerorsCamp_EventScript_RanFromRaikou
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq ConquerorsCamp_EventScript_RanFromRaikou
	setflag FLAG_DEFEATED_RAIKOU
	setflag FLAG_HIDE_RAIKOU
	release
	end

ConquerorsCamp_EventScript_DefeatedRaikou::
	setflag FLAG_DEFEATED_RAIKOU
	setflag FLAG_HIDE_RAIKOU
	goto Common_EventScript_RemoveStaticPokemon
	end

ConquerorsCamp_EventScript_RanFromRaikou::
	setvar VAR_0x8004, SPECIES_RAIKOU
	goto Common_EventScript_LegendaryFlewAway
	end
