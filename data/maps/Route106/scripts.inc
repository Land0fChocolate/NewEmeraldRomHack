Route106_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route106_OnTransition
	.byte 0

Route106_OnTransition:
	call Route106_Eventscript_SetUpBrawly
	end

Route106_Eventscript_SetUpBrawly::
	setorcopyvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_BRAWLY_1
    specialvar VAR_RESULT, IsTrainerReadyForRematch
    compare VAR_RESULT, TRUE
    goto_if_eq Route106_Eventscript_BrawlyRematch
    compare VAR_RESULT, FALSE
    goto_if_eq Route106_Eventscript_BrawlyBeach
    return

Route106_Eventscript_BrawlyRematch::
	setflag FLAG_HIDE_ROUTE106_BRAWLY
	clearflag FLAG_HIDE_DEWFORD_GYM_BRAWLY
	return

Route106_Eventscript_BrawlyBeach::
	clearflag FLAG_HIDE_ROUTE106_BRAWLY
	setflag FLAG_HIDE_DEWFORD_GYM_BRAWLY
	return

Route106_EventScript_TrainerTipsSign::
	msgbox Route106_Text_TrainerTips, MSGBOX_SIGN
	end

Route106_EventScript_Douglas::
	trainerbattle_single TRAINER_DOUGLAS, Route106_Text_DouglasIntro, Route106_Text_DouglasDefeated
	msgbox Route106_Text_DouglasPostBattle, MSGBOX_AUTOCLOSE
	end

Route106_EventScript_Kyla::
	trainerbattle_single TRAINER_KYLA, Route106_Text_KylaIntro, Route106_Text_KylaDefeated
	msgbox Route106_Text_KylaPostBattle, MSGBOX_AUTOCLOSE
	end

Route106_EventScript_Elliot::
	trainerbattle_single TRAINER_ELLIOT_1, Route106_Text_ElliotIntro, Route106_Text_ElliotDefeated, Route106_EventScript_ElliotRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route106_EventScript_ElliotRematch
	msgbox Route106_Text_ElliotPostBattle, MSGBOX_DEFAULT
	release
	end

Route106_EventScript_ElliotRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route106_Text_ElliotRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ELLIOT_1
	release
	end

Route106_EventScript_ElliotRematch::
	trainerbattle_rematch TRAINER_ELLIOT_1, Route106_Text_ElliotRematchIntro, Route106_Text_ElliotRematchDefeated
	msgbox Route106_Text_ElliotRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route106_EventScript_Ned::
	trainerbattle_single TRAINER_NED, Route106_Text_NedIntro, Route106_Text_NedDefeated
	msgbox Route106_Text_NedPostBattle, MSGBOX_AUTOCLOSE
	end

Route106_EventScript_Brawly::
	faceplayer
	dotimebasedevents
	goto_if_unset FLAG_DAILY_BRAWLY_SHARD, Route106_EventScript_BrawlyGivesShard
	msgbox Route106_Text_Brawly, MSGBOX_DEFAULT
	release
	end

Route106_EventScript_BrawlyGivesShard::
	msgbox Route106_Text_BrawlyGivesShard, MSGBOX_DEFAULT
	random 4
	copyvar VAR_0x800A, VAR_RESULT
	switch VAR_RESULT
	case 0, Route106_EventScript_BrawlyGivesRedShard
	case 1, Route106_EventScript_BrawlyGivesBlueShard
	case 2, Route106_EventScript_BrawlyGivesYellowShard
	case 3, Route106_EventScript_BrawlyGivesGreenShard
	release
	end

Route106_EventScript_BrawlyGivesRedShard::
	giveitem ITEM_RED_SHARD, 1
	setflag FLAG_DAILY_BRAWLY_SHARD
	release
	end

Route106_EventScript_BrawlyGivesBlueShard::
	giveitem ITEM_BLUE_SHARD, 1
	setflag FLAG_DAILY_BRAWLY_SHARD
	release
	end

Route106_EventScript_BrawlyGivesYellowShard::
	giveitem ITEM_YELLOW_SHARD, 1
	setflag FLAG_DAILY_BRAWLY_SHARD
	release
	end

Route106_EventScript_BrawlyGivesGreenShard::
	giveitem ITEM_GREEN_SHARD, 1
	setflag FLAG_DAILY_BRAWLY_SHARD
	release
	end

Route106_Text_Brawly:
	.string "Brawly: I love to go surfing!\n"
	.string "I've trained my body so I can enjoy\l"
	.string "riding the rough waves!$"

Route106_Text_BrawlyGivesShard:
	.string "Brawly: Hey, {PLAYER}!\n"
	.string "Riding a wave today, too?\p"
	.string "I found something pretty neat in the\n"
	.string "sand. I don't want to break it, so\l"
	.string "here you go.$"

Route106_Text_TrainerTips:
	.string "TRAINER TIPS\p"
	.string "Advice on catching Pokémon with a rod:\n"
	.string "Press the A Button if you get a bite.$"
