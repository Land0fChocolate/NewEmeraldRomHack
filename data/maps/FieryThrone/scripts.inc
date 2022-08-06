FieryThrone_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FieryThrone_OnTransition
	.byte 0

FieryThrone_OnTransition:
	setflag FLAG_LANDMARK_FIERY_THRONE
	end

FieryThrone_Eventscript_Moltres::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MOLTRES, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_MOLTRES, 50, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq FieryThrone_EventScript_DefeatedMoltres
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq FieryThrone_EventScript_RanFromMoltres
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq FieryThrone_EventScript_RanFromMoltres
	setflag FLAG_DEFEATED_MOLTRES
	release

FieryThrone_EventScript_DefeatedMoltres::
	setflag FLAG_DEFEATED_MOLTRES
	goto Common_EventScript_RemoveStaticPokemon
	end

FieryThrone_EventScript_RanFromMoltres::
	setvar VAR_0x8004, SPECIES_MOLTRES
	goto Common_EventScript_LegendaryFlewAway
	end
