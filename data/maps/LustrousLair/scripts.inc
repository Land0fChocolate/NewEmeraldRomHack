LustrousLair_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LustrousLair_OnTransition
	.byte 0

LustrousLair_OnTransition:
	setflag FLAG_LANDMARK_LUSTROUS_LAIR
	end

LustrousLair_Eventscript_Articuno::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ARTICUNO, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_ARTICUNO, 50, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq LustrousLair_EventScript_DefeatedArticuno
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq LustrousLair_EventScript_RanFromArticuno
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq LustrousLair_EventScript_RanFromArticuno
	setflag FLAG_DEFEATED_ARTICUNO
	release

LustrousLair_EventScript_DefeatedArticuno::
	setflag FLAG_DEFEATED_ARTICUNO
	goto Common_EventScript_RemoveStaticPokemon
	end

LustrousLair_EventScript_RanFromArticuno::
	setvar VAR_0x8004, SPECIES_ARTICUNO
	goto Common_EventScript_LegendaryFlewAway
	end

