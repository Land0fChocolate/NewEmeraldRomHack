SagesSanctuary_MapScripts::
	.byte 0

SagesSanctuary_OnTransition:
	setflag FLAG_LANDMARK_SAGES_SANCTUARY
	end

SagesSanctuary_Eventscript_Suicune::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SUICUNE, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_SUICUNE, 50, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq SagesSanctuary_EventScript_DefeatedSuicune
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq SagesSanctuary_EventScript_RanFromSuicune
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq SagesSanctuary_EventScript_RanFromSuicune
	setflag FLAG_DEFEATED_SUICUNE
	release

SagesSanctuary_EventScript_DefeatedSuicune::
	setflag FLAG_DEFEATED_SUICUNE
	goto Common_EventScript_RemoveStaticPokemon
	end

SagesSanctuary_EventScript_RanFromSuicune::
	setvar VAR_0x8004, SPECIES_SUICUNE
	goto Common_EventScript_LegendaryFlewAway
	end
