ConquerorsCamp_MapScripts::
	.byte 0

ConquerorsCamp_OnTransition:
	setflag FLAG_LANDMARK_CONQUERORS_CAMP
	end

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
	release

ConquerorsCamp_EventScript_DefeatedRaikou::
	setflag FLAG_DEFEATED_RAIKOU
	goto Common_EventScript_RemoveStaticPokemon
	end

ConquerorsCamp_EventScript_RanFromRaikou::
	setvar VAR_0x8004, SPECIES_RAIKOU
	goto Common_EventScript_LegendaryFlewAway
	end
