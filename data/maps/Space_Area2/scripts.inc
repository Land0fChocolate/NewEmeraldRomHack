.set LOCALID_TRIANGLE, 1
.set LOCALID_DEOXYS, 2

@ Note: LOCALID_BIRTH_ISLAND_EXTERIOR_ROCK is a local id for this map used elsewhere. It's defined in event_objects.h

Space_Area2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Space_Area2_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Space_Area2_OnResume
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, Space_Area2_OnReturnToField
	.byte 0

Space_Area2_OnReturnToField:
	special SetDeoxysRockPalette
	end

Space_Area2_OnTransition:
	setflag FLAG_MAP_SCRIPT_CHECKED_DEOXYS
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
	setvar VAR_DEOXYS_ROCK_STEP_COUNT, 0
	setvar VAR_DEOXYS_ROCK_LEVEL, 0
	call_if_set FLAG_BATTLED_DEOXYS, Space_Area2_EventScript_HideDeoxysAndPuzzle
	call_if_unset FLAG_BATTLED_DEOXYS, Space_Area2_EventScript_TryShowDeoxysPuzzle
	end

Space_Area2_EventScript_HideDeoxysAndPuzzle::
	setflag FLAG_HIDE_DEOXYS
	setflag FLAG_HIDE_BIRTH_ISLAND_DEOXYS_TRIANGLE
	return

Space_Area2_EventScript_TryShowDeoxysPuzzle::
	goto_if_set FLAG_DEFEATED_DEOXYS, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_BIRTH_ISLAND_DEOXYS_TRIANGLE
	clearflag FLAG_DEOXYS_ROCK_COMPLETE
	return

Space_Area2_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Space_Area2_EventScript_TryRemoveDeoxys
	end

Space_Area2_EventScript_TryRemoveDeoxys::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject LOCALID_DEOXYS
	return

Space_Area2_EventScript_Triangle::
	lock
	faceplayer
	special DoDeoxysRockInteraction
	waitstate
	switch VAR_RESULT
	case 0, Space_Area2_EventScript_NotSolved1
	case 1, Space_Area2_EventScript_NotSolved2
	case 2, Space_Area2_EventScript_Deoxys
	case 3, Space_Area2_EventScript_NotSolved3
	end

Space_Area2_EventScript_NotSolved1::
	release
	end

Space_Area2_EventScript_NotSolved2::
	release
	end

Space_Area2_EventScript_NotSolved3::
	release
	end

Space_Area2_EventScript_Deoxys::
	waitse
	setfieldeffectargument 0, LOCALID_BIRTH_ISLAND_EXTERIOR_ROCK
	setfieldeffectargument 1, MAP_NUM(SPACE_AREA2)
	setfieldeffectargument 2, MAP_GROUP(SPACE_AREA2)
	dofieldeffect FLDEFF_DESTROY_DEOXYS_ROCK
	playbgm MUS_RG_ENCOUNTER_DEOXYS, FALSE
	waitfieldeffect FLDEFF_DESTROY_DEOXYS_ROCK
	addobject LOCALID_DEOXYS
	applymovement LOCALID_DEOXYS, Space_Area2_Movement_DeoxysApproach
	waitmovement 0
	waitse
	playmoncry SPECIES_DEOXYS, 2
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_DEOXYS
	setvar VAR_0x8004, SPECIES_DEOXYS
	setvar VAR_0x8005, 75 @ level
	setvar VAR_0x8006, ITEM_NONE
	special CreateEventLegalEnemyMon
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_DEOXYS_BOSS_BATTLE_STATE, 1
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 2, 0, 0, 2, 0, 0
	setflag FLAG_SMART_WILD_AI
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_DEOXYS_BOSS_BATTLE_STATE, 0
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_DISABLE_CATCHING
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Space_Area2_EventScript_DefeatedDeoxys
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq Space_Area2_EventScript_CaughtDeoxys
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq Space_Area2_EventScript_RanFromDeoxys
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq Space_Area2_EventScript_RanFromDeoxys
	setflag FLAG_BATTLED_DEOXYS
	release
	end

Space_Area2_EventScript_DefeatedDeoxys::
	setvar VAR_DEOXYS_BOSS_BATTLE_STATE, 0 @safety net, since apparently this wasn't set after Deoxys battle
	setflag FLAG_DEFEATED_DEOXYS
	compare VAR_DRACONID_ARCHIVES_STATE, 0
	call_if_eq Space_Area2_EventScript_DraconidArchivesState
	setvar VAR_0x8004, SPECIES_DEOXYS
	goto Common_EventScript_LegendaryFlewAway
	end

Space_Area2_EventScript_CaughtDeoxys::
	setvar VAR_DEOXYS_BOSS_BATTLE_STATE, 0 @safety net, since apparently this wasn't set after Deoxys battle
	setflag FLAG_DEFEATED_DEOXYS
	compare VAR_DRACONID_ARCHIVES_STATE, 0
	call_if_eq Space_Area2_EventScript_DraconidArchivesState
	end

Space_Area2_EventScript_RanFromDeoxys::
	setvar VAR_DEOXYS_BOSS_BATTLE_STATE, 0 @safety net, since apparently this wasn't set after Deoxys battle
	setvar VAR_0x8004, SPECIES_DEOXYS
	goto Common_EventScript_LegendaryFlewAway
	end

Space_Area2_Movement_DeoxysApproach:
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	step_end

Space_Area2_EventScript_DraconidArchivesState:
	setvar VAR_DRACONID_ARCHIVES_STATE, 1
	setflag FLAG_HIDE_ZINNIA_SKY_PILLAR_TOP
	clearflag FLAG_HIDE_ZINNIA_DRACONID_ARCHIVES
	return
