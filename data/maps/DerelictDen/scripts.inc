.set LOCALID_ZAPDOS, 1

DerelictDen_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, DerelictDen_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, DerelictDen_OnTransition
	.byte 0

DerelictDen_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, DerelictDen_EventScript_TryRemoveZapdos
	end

DerelictDen_OnTransition:
	setflag FLAG_LANDMARK_DERELICT_DEN
	end

DerelictDen_EventScript_TryRemoveZapdos::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject LOCALID_ZAPDOS
	return

DerelictDen_Eventscript_Zapdos::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZAPDOS, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_ZAPDOS, 50, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq DerelictDen_EventScript_DefeatedZapdos
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq DerelictDen_EventScript_RanFromZapdos
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq DerelictDen_EventScript_RanFromZapdos
	setflag FLAG_DEFEATED_ZAPDOS
	setflag FLAG_HIDE_ZAPDOS
	release
	end

DerelictDen_EventScript_DefeatedZapdos::
	setflag FLAG_DEFEATED_ZAPDOS
	setflag FLAG_HIDE_ZAPDOS
	goto Common_EventScript_RemoveStaticPokemon
	end

DerelictDen_EventScript_RanFromZapdos::
	setvar VAR_0x8004, SPECIES_ZAPDOS
	goto Common_EventScript_LegendaryFlewAway
	end
