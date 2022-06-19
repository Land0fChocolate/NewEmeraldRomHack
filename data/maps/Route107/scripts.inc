Route107_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route107_OnLoad
	.byte 0

Route107_OnLoad:
	call_if_unset FLAG_SYS_GAME_CLEAR, Route107_EventScript_CloseLittlerootBeachPath
	end

Route107_EventScript_CloseLittlerootBeachPath::
	setmetatile 27, 9, METATILE_General_OceanRockTopLeft, 1
	setmetatile 28, 9, METATILE_General_OceanRockTopRight, 1
	setmetatile 27, 10, METATILE_General_OceanRockBotLeft, 1
	setmetatile 28, 10, METATILE_General_OceanRockBotRight, 1
	setmetatile 31, 8, METATILE_General_OceanRockTopLeft, 1
	setmetatile 32, 8, METATILE_General_OceanRockTopRight, 1
	setmetatile 31, 9, METATILE_General_OceanRockBotLeft, 1
	setmetatile 32, 9, METATILE_General_OceanRockBotRight, 1
	setmetatile 39, 6, METATILE_General_OceanRockTopLeft, 1
	setmetatile 40, 6, METATILE_General_OceanRockTopRight, 1
	setmetatile 39, 7, METATILE_General_OceanRockBotLeft, 1
	setmetatile 40, 7, METATILE_General_OceanRockBotRight, 1
	setmetatile 41, 5, METATILE_General_OceanRockTopLeft, 1
	setmetatile 42, 5, METATILE_General_OceanRockTopRight, 1
	setmetatile 41, 6, METATILE_General_OceanRockBotLeft, 1
	setmetatile 42, 6, METATILE_General_OceanRockBotRight, 1
	setmetatile 46, 5, METATILE_General_OceanRockTopLeft, 1
	setmetatile 47, 5, METATILE_General_OceanRockTopRight, 1
	setmetatile 46, 6, METATILE_General_OceanRockBotLeft, 1
	setmetatile 47, 6, METATILE_General_OceanRockBotRight, 1
	setmetatile 48, 6, METATILE_General_OceanRockTopLeft, 1
	setmetatile 49, 6, METATILE_General_OceanRockTopRight, 1
	setmetatile 48, 7, METATILE_General_OceanRockBotLeft, 1
	setmetatile 49, 7, METATILE_General_OceanRockBotRight, 1
	setmetatile 20, 5, METATILE_General_CalmWater, 0
	setmetatile 21, 5, METATILE_General_CalmWater, 0
	setmetatile 20, 6, METATILE_General_CalmWater, 0
	setmetatile 21, 6, METATILE_General_CalmWater, 0
	setmetatile 22, 7, METATILE_General_CalmWater, 0
	setmetatile 23, 7, METATILE_General_CalmWater, 0
	setmetatile 22, 8, METATILE_General_CalmWater, 0
	setmetatile 23, 8, METATILE_General_CalmWater, 0
	setmetatile 24, 5, METATILE_General_CalmWater, 0
	setmetatile 25, 5, METATILE_General_CalmWater, 0
	setmetatile 24, 6, METATILE_General_CalmWater, 0
	setmetatile 25, 6, METATILE_General_CalmWater, 0
	setmetatile 30, 2, METATILE_General_CalmWater, 0
	setmetatile 31, 2, METATILE_General_CalmWater, 0
	setmetatile 30, 3, METATILE_General_CalmWater, 0
	setmetatile 31, 3, METATILE_General_CalmWater, 0
	setmetatile 32, 4, METATILE_General_CalmWater, 0
	setmetatile 33, 4, METATILE_General_CalmWater, 0
	setmetatile 32, 5, METATILE_General_CalmWater, 0
	setmetatile 33, 5, METATILE_General_CalmWater, 0
	setmetatile 35, 3, METATILE_General_CalmWater, 0
	setmetatile 36, 3, METATILE_General_CalmWater, 0
	setmetatile 35, 4, METATILE_General_CalmWater, 0
	setmetatile 36, 4, METATILE_General_CalmWater, 0
	setmetatile 37, 1, METATILE_General_CalmWater, 0
	setmetatile 38, 1, METATILE_General_CalmWater, 0
	setmetatile 37, 2, METATILE_General_CalmWater, 0
	setmetatile 38, 2, METATILE_General_CalmWater, 0
	setmetatile 39, 2, METATILE_General_CalmWater, 0
	setmetatile 40, 2, METATILE_General_CalmWater, 0
	setmetatile 39, 3, METATILE_General_CalmWater, 0
	setmetatile 40, 3, METATILE_General_CalmWater, 0
	setmetatile 41, 3, METATILE_General_CalmWater, 0
	setmetatile 42, 3, METATILE_General_CalmWater, 0
	setmetatile 41, 4, METATILE_General_CalmWater, 0
	setmetatile 42, 4, METATILE_General_CalmWater, 0
	setmetatile 47, 1, METATILE_General_CalmWater, 0
	setmetatile 48, 1, METATILE_General_CalmWater, 0
	setmetatile 47, 2, METATILE_General_CalmWater, 0
	setmetatile 48, 2, METATILE_General_CalmWater, 0
	setmetatile 51, 1, METATILE_General_CalmWater, 0
	setmetatile 52, 1, METATILE_General_CalmWater, 0
	setmetatile 51, 2, METATILE_General_CalmWater, 0
	setmetatile 52, 2, METATILE_General_CalmWater, 0
	setmetatile 51, 5, METATILE_General_CalmWater, 0
	setmetatile 52, 5, METATILE_General_CalmWater, 0
	setmetatile 51, 6, METATILE_General_CalmWater, 0
	setmetatile 52, 6, METATILE_General_CalmWater, 0
	setmetatile 52, 3, METATILE_General_CalmWater, 0
	setmetatile 53, 3, METATILE_General_CalmWater, 0
	setmetatile 52, 4, METATILE_General_CalmWater, 0
	setmetatile 53, 4, METATILE_General_CalmWater, 0
	return

Route107_EventScript_Darrin::
	trainerbattle_single TRAINER_DARRIN, Route107_Text_DarrinIntro, Route107_Text_DarrinDefeated
	msgbox Route107_Text_DarrinPostBattle, MSGBOX_AUTOCLOSE
	end

Route107_EventScript_Tony::
	trainerbattle_single TRAINER_TONY_1, Route107_Text_TonyIntro, Route107_Text_TonyDefeated, Route107_EventScript_TonyRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route107_EventScript_TonyRematch
	msgbox Route107_Text_TonyPostBattle, MSGBOX_DEFAULT
	release
	end

Route107_EventScript_TonyRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route107_Text_TonyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TONY_1
	release
	end

Route107_EventScript_TonyRematch::
	trainerbattle_rematch TRAINER_TONY_1, Route107_Text_TonyRematchIntro, Route107_Text_TonyRematchDefeated
	msgbox Route107_Text_TonyRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route107_EventScript_Denise::
	trainerbattle_single TRAINER_DENISE, Route107_Text_DeniseIntro, Route107_Text_DeniseDefeated
	msgbox Route107_Text_DenisePostBattle, MSGBOX_AUTOCLOSE
	end

Route107_EventScript_Lisa::
	trainerbattle_double TRAINER_LISA_AND_RAY, Route107_Text_LisaIntro, Route107_Text_LisaDefeated, Route107_Text_LisaNotEnoughPokemon
	msgbox Route107_Text_LisaPostBattle, MSGBOX_AUTOCLOSE
	end

Route107_EventScript_Ray::
	trainerbattle_double TRAINER_LISA_AND_RAY, Route107_Text_RayIntro, Route107_Text_RayDefeated, Route107_Text_RayNotEnoughPokemon
	msgbox Route107_Text_RayPostBattle, MSGBOX_AUTOCLOSE
	end

Route107_EventScript_Camron::
	trainerbattle_single TRAINER_CAMRON, Route107_Text_CamronIntro, Route107_Text_CamronDefeated
	msgbox Route107_Text_CamronPostBattle, MSGBOX_AUTOCLOSE
	end

