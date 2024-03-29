.set LOCALID_GROUDON, 1

TerraCave_End_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TerraCave_End_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, TerraCave_End_OnTransition
	.byte 0

TerraCave_End_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, TerraCave_End_EventScript_TryRemoveGroudon
	end

TerraCave_End_EventScript_TryRemoveGroudon::
	checkitem ITEM_RAINBOW_WING, 1
	compare VAR_RESULT, FALSE
	goto_if_eq TerraCave_End_EventScript_RemoveGroudon
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
TerraCave_End_EventScript_RemoveGroudon::
	removeobject LOCALID_GROUDON
	return

TerraCave_End_OnTransition:
	call_if_unset FLAG_DEFEATED_GROUDON, TerraCave_End_EventScript_ShowGroudon
	end

TerraCave_End_EventScript_ShowGroudon::
	checkitem ITEM_RAINBOW_WING, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_NopReturn
	clearflag FLAG_HIDE_TERRA_CAVE_GROUDON
	setvar VAR_TEMP_1, 1
	return

TerraCave_End_EventScript_Groudon::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_GROUDON, TerraCave_End_Movement_GroudonApproach
	waitmovement 0
	waitse
	playmoncry SPECIES_GROUDON, 2
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_GROUDON
	setwildbattle SPECIES_GROUDON, 70, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_TEMP_1, 0
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq TerraCave_End_EventScript_DefeatedGroudon
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq TerraCave_End_EventScript_RanFromGroudon
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq TerraCave_End_EventScript_RanFromGroudon
	setvar VAR_SHOULD_END_ABNORMAL_WEATHER, 1
	setflag FLAG_DEFEATED_GROUDON
	call_if_set FLAG_DEFEATED_KYOGRE, TerraCave_End_EventScript_GroudonKyogreDefeated
	releaseall
	end

TerraCave_End_EventScript_GroudonKyogreDefeated::
	compare VAR_BIRCH_LAB_POSTGAME_STATE, 7
	goto_if_ge Common_EventScript_NopReturn
	setvar VAR_BIRCH_LAB_POSTGAME_STATE, 6
	return

TerraCave_End_EventScript_DefeatedGroudon::
	setvar VAR_SHOULD_END_ABNORMAL_WEATHER, 1
	setflag FLAG_DEFEATED_GROUDON
	call_if_set FLAG_DEFEATED_KYOGRE, TerraCave_End_EventScript_GroudonKyogreDefeated
	goto Common_EventScript_RemoveStaticPokemon
	end

TerraCave_End_EventScript_RanFromGroudon::
	setvar VAR_0x8004, SPECIES_GROUDON
	goto Common_EventScript_LegendaryFlewAway
	end

TerraCave_End_Movement_GroudonApproach:
	init_affine_anim
	walk_down_start_affine
	delay_16
	delay_16
	walk_down_affine
	delay_16
	delay_16
	walk_down_affine
	step_end

