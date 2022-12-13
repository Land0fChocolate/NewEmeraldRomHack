.set LOCALID_ENTEI, 1

RoyalRest_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, RoyalRest_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, RoyalRest_OnTransition
	.byte 0

RoyalRest_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, RoyalRest_EventScript_TryRemoveEntei
	end

RoyalRest_OnTransition:
	setflag FLAG_LANDMARK_ROYAL_REST
	end

RoyalRest_EventScript_TryRemoveEntei::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject LOCALID_ENTEI
	return

RoyalRest_Eventscript_Entei::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ENTEI, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_ENTEI, 50, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq RoyalRest_EventScript_DefeatedEntei
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq RoyalRest_EventScript_RanFromEntei
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq RoyalRest_EventScript_RanFromEntei
	setflag FLAG_DEFEATED_ENTEI
	setflag FLAG_HIDE_ENTEI
	release
	end

RoyalRest_EventScript_DefeatedEntei::
	setflag FLAG_DEFEATED_ENTEI
	setflag FLAG_HIDE_ENTEI
	goto Common_EventScript_RemoveStaticPokemon
	end

RoyalRest_EventScript_RanFromEntei::
	setvar VAR_0x8004, SPECIES_ENTEI
	goto Common_EventScript_LegendaryFlewAway
	end
