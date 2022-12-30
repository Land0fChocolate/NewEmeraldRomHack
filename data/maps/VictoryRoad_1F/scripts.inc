.set LOCALID_WALLY_EXIT, 4

VictoryRoad_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_1F_OnTransition
	.byte 0

VictoryRoad_1F_OnTransition:
	call_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VictoryRoad_1F_EventScript_SetUpPostDefeatWally
	end

VictoryRoad_1F_EventScript_SetUpPostDefeatWally::
	setflag FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY
	clearflag FLAG_HIDE_VICTORY_ROAD_EXIT_WALLY
	return

VictoryRoad_1F_EventScript_SetEntranceWallyPos1::
	setobjectxyperm LOCALID_WALLY_EXIT, 2, 24
	setobjectmovementtype LOCALID_WALLY_EXIT, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_SetEntranceWallyPos2::
	setobjectxyperm LOCALID_WALLY_EXIT, 3, 24
	setobjectmovementtype LOCALID_WALLY_EXIT, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_WallyBattleTrigger1::
	lockall
	addobject LOCALID_WALLY_EXIT
	applymovement LOCALID_WALLY_EXIT, VictoryRoad_1F_Movement_WallyApproachPlayer1
	waitmovement 0
	goto VictoryRoad_1F_EventScript_WallyExitBattle
	end

VictoryRoad_1F_EventScript_WallyBattleTrigger2::
	lockall
	addobject LOCALID_WALLY_EXIT
	applymovement LOCALID_WALLY_EXIT, VictoryRoad_1F_Movement_WallyApproachPlayer2
	waitmovement 0
	goto VictoryRoad_1F_EventScript_WallyExitBattle
	end

VictoryRoad_1F_EventScript_WallyBattleTrigger3::
	lockall
	addobject LOCALID_WALLY_EXIT
	applymovement LOCALID_WALLY_EXIT, VictoryRoad_1F_Movement_WallyApproachPlayer3
	waitmovement 0
	goto VictoryRoad_1F_EventScript_WallyExitBattle
	end

VictoryRoad_1F_EventScript_WallyExitBattle::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	msgbox VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_VR_1, VictoryRoad_1F_Text_WallyEntranceDefeat
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_DEFAULT
	copyobjectxytoperm LOCALID_WALLY_EXIT
	setflag FLAG_DEFEATED_WALLY_VICTORY_ROAD
	setvar VAR_VICTORY_ROAD_1F_STATE, 1
	releaseall
	end

VictoryRoad_1F_Movement_WallyApproachPlayer1:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_right
	step_end

VictoryRoad_1F_Movement_WallyApproachPlayer2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_right
	step_end

VictoryRoad_1F_Movement_WallyApproachPlayer3:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_right
	step_end

@ This Wally appears near the entrance once his battle is triggered and remains there until the Hall of Fame is entered
VictoryRoad_1F_EventScript_EntranceWally::
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_NPC
	end

@ This Wally appears and remains at the exit after the Hall of Fame is entered 
VictoryRoad_1F_EventScript_ExitWally::
	lock
	faceplayer
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq VictoryRoad_1F_EventScript_RematchWally
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
	release
	end

VictoryRoad_1F_EventScript_RematchWally::
	trainerbattle_rematch TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
	release
	end

VictoryRoad_1F_EventScript_Edgar::
	trainerbattle_single TRAINER_EDGAR, VictoryRoad_1F_Text_EdgarIntro, VictoryRoad_1F_Text_EdgarDefeat
	msgbox VictoryRoad_1F_Text_EdgarPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Albert::
	trainerbattle_single TRAINER_ALBERT, VictoryRoad_1F_Text_AlbertIntro, VictoryRoad_1F_Text_AlbertDefeat
	msgbox VictoryRoad_1F_Text_AlbertPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Hope::
	trainerbattle_single TRAINER_HOPE, VictoryRoad_1F_Text_HopeIntro, VictoryRoad_1F_Text_HopeDefeat
	msgbox VictoryRoad_1F_Text_HopePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Quincy::
	trainerbattle_single TRAINER_QUINCY, VictoryRoad_1F_Text_QuincyIntro, VictoryRoad_1F_Text_QuincyDefeat
	msgbox VictoryRoad_1F_Text_QuincyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Katelynn::
	trainerbattle_single TRAINER_KATELYNN, VictoryRoad_1F_Text_KatelynnIntro, VictoryRoad_1F_Text_KatelynnDefeat
	msgbox VictoryRoad_1F_Text_KatelynnPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore:
	.string "Wally: Hi! {PLAYER}!\p"
	.string "I bet you're surprised to see me here!\p"
	.string "I made it all the way here, and it's\n"
	.string "really all thanks to you that I made\l"
	.string "it all this way.\p"
	.string "{PLAYER}, it was only because I lost\n"
	.string "to you that I realized just how far my\l"
	.string "potential can reach.\p"
	.string "I'm sure you and your Pokémon have grown\n"
	.string "a lot since then, to make it all the way\l"
	.string "here but so have we!\p"
	.string "My Pokémon have given me the courage\n"
	.string "and the strength to fight!\p"
	.string "I have to win for them, and for me.\n"
	.string "Get ready. Here I come.$"

VictoryRoad_1F_Text_WallyEntranceDefeat:
	.string "…\p"
	.string "{PLAYER}, all this time you never\n"
	.string "skipped on your training, have you?$"

VictoryRoad_1F_Text_WallyPostEntranceBattle:
	.string "Wally: I couldn't beat you today,\n"
	.string "{PLAYER}, but I'm not sorry.\l"
	.string "It only shows that I have more\l"
	.string "mountains yet to climb!\p"
	.string "I will continue training.\n"
	.string "I will catch up to you one day!$"

VictoryRoad_1F_Text_WallyIntro:
	.string "Wally: Hi! {PLAYER}!\p"
	.string "I've gotten stronger since that last\n"
	.string "time! I wanted to show you, {PLAYER}!\p"
	.string "Okay… Here I come!$"

VictoryRoad_1F_Text_WallyDefeat:
	.string "Wow!\n"
	.string "{PLAYER}, you never let down, do you?$"

VictoryRoad_1F_Text_WallyPostBattle:
	.string "Wally: I couldn't beat you this time,\n"
	.string "too… But one of these days, {PLAYER},\l"
	.string "I'm going to catch up to you…\p"
	.string "And challenge the Pokémon League!$"

VictoryRoad_1F_Text_EdgarIntro:
	.string "I've made it this far a couple times,\n"
	.string "but the last stretch is so long…$"

VictoryRoad_1F_Text_EdgarDefeat:
	.string "My dream ends here again…$"

VictoryRoad_1F_Text_EdgarPostBattle:
	.string "You've made it this far. Keep the\n"
	.string "momentum going and become the\l"
	.string "Champion! If anyone can, it's you!$"

VictoryRoad_1F_Text_AlbertIntro:
	.string "I didn't come all this way to lose now.\n"
	.string "That possibility doesn't exist!$"

VictoryRoad_1F_Text_AlbertDefeat:
	.string "Impossible…\n"
	.string "I lost?$"

VictoryRoad_1F_Text_AlbertPostBattle:
	.string "I lost here…\p"
	.string "That means I lack the qualifications\n"
	.string "to become the Champion…$"

VictoryRoad_1F_Text_HopeIntro:
	.string "This seemingly infinite and harsh road\n"
	.string "lives up to its name of Victory.$"

VictoryRoad_1F_Text_HopeDefeat:
	.string "Your battle style is fantastic…$"

VictoryRoad_1F_Text_HopePostBattle:
	.string "You seem to have the potential for\n"
	.string "becoming the Champion.$"

VictoryRoad_1F_Text_QuincyIntro:
	.string "What is the Victory Road?\n"
	.string "I'll tell you if you win!$"

VictoryRoad_1F_Text_QuincyDefeat:
	.string "Okay!\n"
	.string "Well done!$"

VictoryRoad_1F_Text_QuincyPostBattle:
	.string "Getting through here safely--that's\n"
	.string "the final test for any Trainer aiming\l"
	.string "to become the Pokémon Champion.\p"
	.string "That's why it's called the Victory\n"
	.string "Road.$"

VictoryRoad_1F_Text_KatelynnIntro:
	.string "I have nothing to say to anyone\n"
	.string "that's come this far. Come on!$"

VictoryRoad_1F_Text_KatelynnDefeat:
	.string "This is a disgrace…$"

VictoryRoad_1F_Text_KatelynnPostBattle:
	.string "Humph, go right on ahead.\n"
	.string "See if I care.$"
