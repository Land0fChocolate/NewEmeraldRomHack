.set LOCALID_GIRL, 1
.set LOCALID_MAGMA_GRUNT, 2

Mauville_Riverside_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Mauville_Riverside_OnTransition
	.byte 0

Mauville_Riverside_OnTransition:
	setflag FLAG_LANDMARK_MAUVILLE_RIVERSIDE
	end

Mauville_Riverside_Eventscript_MagmaGrunt::
	lock
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	applymovement LOCALID_MAGMA_GRUNT, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	applymovement LOCALID_MAGMA_GRUNT, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	applymovement LOCALID_MAGMA_GRUNT, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox Mauville_Riverside_Text_GetDown, MSGBOX_DEFAULT
	closemessage
	delay 30
	faceplayer
	msgbox Mauville_Riverside_Text_WhoAreYou, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_GRUNT_MAUVILLE_RIVERSIDE, Mauville_Riverside_Text_GruntLost
	msgbox Mauville_Riverside_Text_YouHaveMadeAnEnemy, MSGBOX_DEFAULT
	closemessage
	getplayerxy VAR_0x8004, VAR_0x8005
	compare VAR_0x8004, 12
	goto_if_eq Mauville_Riverside_Eventscript_MagmaGruntLeavesRight
	goto Mauville_Riverside_Eventscript_MagmaGruntLeavesDown
	end

Mauville_Riverside_Eventscript_MagmaGruntLeavesRight::
	applymovement LOCALID_MAGMA_GRUNT, Mauville_Riverside_Movement_GruntLeavesRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	goto Mauville_Riverside_Eventscript_GirlMove

Mauville_Riverside_Movement_GruntLeavesRight:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Mauville_Riverside_Eventscript_MagmaGruntLeavesDown::
	applymovement LOCALID_MAGMA_GRUNT, Mauville_Riverside_Movement_GruntLeavesDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	goto Mauville_Riverside_Eventscript_GirlMove

Mauville_Riverside_Movement_GruntLeavesDown:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Mauville_Riverside_Eventscript_GirlMove::
	delay 40
	applymovement LOCALID_GIRL, Mauville_Riverside_Movement_GirlMovesToPlayer
	delay 10
	playse SE_LEDGE
	waitmovement 0
	compare VAR_0x8004, 11
	goto_if_eq Mauville_Riverside_Eventscript_GirlFacePlayerLeft
	compare VAR_0x8004, 12
	goto_if_eq Mauville_Riverside_Eventscript_GirlFacePlayerDown
	compare VAR_0x8004, 13
	goto_if_eq Mauville_Riverside_Eventscript_GirlFacePlayerRight
	end

Mauville_Riverside_Movement_GirlMovesToPlayer:
	walk_down
	jump_2_down
	delay_16
	step_end

Mauville_Riverside_Eventscript_GirlFacePlayerLeft:
	applymovement LOCALID_GIRL, Common_Movement_FaceLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	goto Mauville_Riverside_Eventscript_GirlRescued
	end

Mauville_Riverside_Eventscript_GirlFacePlayerDown:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	goto Mauville_Riverside_Eventscript_GirlRescued
	end

Mauville_Riverside_Eventscript_GirlFacePlayerRight:
	applymovement LOCALID_GIRL, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	goto Mauville_Riverside_Eventscript_GirlRescued
	end

Mauville_Riverside_Eventscript_GirlRescued:
	msgbox Mauville_Riverside_Text_GratitudeForRescue, MSGBOX_DEFAULT
	giveitem ITEM_DUSK_BALL
	compare VAR_RESULT, FALSE
	goto_if_eq Mauville_Riverside_EventScript_BagFull
	goto Mauville_Riverside_EventScript_GirlLeaving
	end

Mauville_Riverside_EventScript_BagFull::
	msgbox Mauville_Riverside_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
	goto Mauville_Riverside_EventScript_GirlLeaving
	end

Mauville_Riverside_EventScript_GirlLeaving::
	msgbox Mauville_Riverside_Text_BeGoingNow, MSGBOX_DEFAULT
	closemessage
	compare VAR_0x8004, 12
	goto_if_eq Mauville_Riverside_Eventscript_GirlLeavesRight
	goto Mauville_Riverside_Eventscript_GirlLeavesDown
	end

Mauville_Riverside_Eventscript_GirlLeavesRight::
	applymovement LOCALID_GIRL, Mauville_Riverside_Movement_GirlLeavesRight
	waitmovement 0
	goto Mauville_Riverside_Eventscript_MagmaEventFinish
	end

Mauville_Riverside_Movement_GirlLeavesRight:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Mauville_Riverside_Eventscript_GirlLeavesDown:
	applymovement LOCALID_GIRL, Mauville_Riverside_Movement_GirlLeavesDown
	waitmovement 0
	goto Mauville_Riverside_Eventscript_MagmaEventFinish
	end

Mauville_Riverside_Movement_GirlLeavesDown:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Mauville_Riverside_Eventscript_MagmaEventFinish::
	removeobject LOCALID_MAGMA_GRUNT
	removeobject LOCALID_GIRL
	setflag FLAG_HIDE_MAUVILLE_RIVERSIDE_NPCS
	clearflag FLAG_HIDE_MAUVILLE_GROOMER
	release
	end

Mauville_Riverside_Text_GetDown:
	.string "Grr!\p"
	.string "GET DOWN, NOW!\p"
	.string "Look, I won't hurt you if you would just\n"
	.string "hand over that meteorite!$"

Mauville_Riverside_Text_WhoAreYou:
	.string "Who are you? I don't need another brat\n"
	.string "messing around here, get lost!\p"
	.string "If you won't go away then I will make\n"
	.string "you go away!$"

Mauville_Riverside_Text_GruntLost:
	.string "Arrgh!\p"
	.string "I hate kids!$"

Mauville_Riverside_Text_YouHaveMadeAnEnemy:
	.string "You…\p"
	.string "You made me fail my mission!\p"
	.string "I'll back off today, but Team Magma\n"
	.string "won't forget this.\l"
	.string "You have made an enemy of us!$"

Mauville_Riverside_Text_GratitudeForRescue:
	.string "Young trainer, you have my gratitude\n"
	.string "for chasing away that awful woman!\p"
	.string "Please accept this as a token of\n"
	.string "my appreciation.$"

Mauville_Riverside_Text_YoureLoadedWithItems:
	.string "Oh no, your bag can't hold this\n"
	.string "Dusk Ball.$"

Mauville_Riverside_Text_BeGoingNow:
	.string "The scoundrels that call themselves\n"
	.string "Team Magma have been instigating\l"
	.string "trouble everywhere!\p"
	.string "I shall be heading home immediately.\n"
	.string "You may visit me at your convenience\l"
	.string "by my residence in Mauville.\p"
	.string "I shall happily groom your Pokémon who\n"
	.string "fought for my safety.\p"
	.string "Once again, thank you.$"
