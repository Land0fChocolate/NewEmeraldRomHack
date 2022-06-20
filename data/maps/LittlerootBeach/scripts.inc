.set LOCALID_RIVAL, 1
.set LOCALID_ZINNIA, 2

LittlerootBeach_MapScripts::
	.byte 0

LittlerootBeach_OnTransition:
	setflag FLAG_LANDMARK_LITTLEROOT_BEACH
	end

LittlerootBeach_EventScript_Rival::
	lockall
	faceplayer
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq LittlerootBeach_EventScript_May
	compare VAR_RESULT, FEMALE
	goto_if_eq LittlerootBeach_EventScript_Brendan
	releaseall
	end

LittlerootBeach_EventScript_May::
	call LittlerootBeach_EventScript_PlayMayMusic
	msgbox LittlerootBeach_Text_MayIntro, MSGBOX_DEFAULT
	closemessage
	goto LittlerootBeach_EventScript_ZinniaEntry
	end

LittlerootBeach_EventScript_Brendan::
	call LittlerootBeach_EventScript_PlayBrendanMusic
	msgbox LittlerootBeach_Text_BrendanIntro, MSGBOX_DEFAULT
	closemessage
	goto LittlerootBeach_EventScript_ZinniaEntry
	end

LittlerootBeach_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

LittlerootBeach_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

LittlerootBeach_EventScript_ZinniaEntry::
	clearflag FLAG_HIDE_LITTLEROOT_BEACH_ZINNIA
	addobject LOCALID_ZINNIA
	getplayerxy VAR_0x8004, VAR_0x8005
	compare VAR_0x8004, 18
	goto_if_eq LittlerootBeach_EventScript_ZinniaMovesToPLayerLeft
	compare VAR_0x8004, 19
	goto_if_eq LittlerootBeach_EventScript_ZinniaMovesToPLayerTop
	compare VAR_0x8004, 20
	goto_if_eq LittlerootBeach_EventScript_ZinniaMovesToPLayerRight
	end

LittlerootBeach_EventScript_ZinniaMovesToPLayerLeft:
	applymovement LOCALID_ZINNIA, LittlerootBeach_Movement_ZinniaMovesToPlayerLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	applymovement LOCALID_RIVAL, Common_Movement_FaceUp
	waitmovement 0
	goto LittlerootBeach_EventScript_Zinnia
	end

LittlerootBeach_EventScript_ZinniaMovesToPLayerTop:
	applymovement LOCALID_ZINNIA, LittlerootBeach_Movement_ZinniaMovesToPlayerTop
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_RIVAL, Common_Movement_FaceRight
	waitmovement 0
	goto LittlerootBeach_EventScript_Zinnia
	end

LittlerootBeach_EventScript_ZinniaMovesToPLayerRight:
	applymovement LOCALID_ZINNIA, LittlerootBeach_Movement_ZinniaMovesToPlayerRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	applymovement LOCALID_RIVAL, Common_Movement_FaceUp
	waitmovement 0
	goto LittlerootBeach_EventScript_Zinnia
	end

LittlerootBeach_Movement_ZinniaMovesToPlayerLeft:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

LittlerootBeach_Movement_ZinniaMovesToPlayerTop:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

LittlerootBeach_Movement_ZinniaMovesToPlayerRight:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	step_end

LittlerootBeach_Movement_ZinniaLeaves:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LittlerootBeach_EventScript_Zinnia::
	msgbox LittlerootBeach_Text_ZinniaIntro, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, LittlerootBeach_Movement_WatchZinniaLeave
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootBeach_Movement_WatchZinniaLeave
	applymovement LOCALID_ZINNIA, LittlerootBeach_Movement_ZinniaLeaves
	waitmovement 0
	setflag FLAG_HIDE_LITTLEROOT_BEACH_ZINNIA
	removeobject LOCALID_ZINNIA
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq LittlerootBeach_EventScript_MayReport
	compare VAR_RESULT, FEMALE
	goto_if_eq LittlerootBeach_EventScript_BrendanReport
	end

LittlerootBeach_Movement_WatchZinniaLeave:
	delay_16
	delay_16
	face_left
	step_end

LittlerootBeach_EventScript_MayReport::
	msgbox LittlerootBeach_Text_MayComment, MSGBOX_DEFAULT
	closemessage
	delay 60
	compare VAR_0x8004, 18
	call_if_eq LittlerootBeach_EventScript_PlayerOnLeftFacingRival
	compare VAR_0x8004, 19
	call_if_eq LittlerootBeach_EventScript_PlayerOnTopFacingRival
	compare VAR_0x8004, 20
	call_if_eq LittlerootBeach_EventScript_RivalFacingPlayerOnRight
LittlerootBeach_EventScript_MayReportPart2::
	msgbox LittlerootBeach_Text_MayReport, MSGBOX_DEFAULT
	closemessage
	goto LittlerootBeach_EventScript_RivalLeaves
	end

LittlerootBeach_EventScript_BrendanReport::
	msgbox LittlerootBeach_Text_BrendanComment, MSGBOX_DEFAULT
	closemessage
	delay 60
	compare VAR_0x8004, 18
	goto_if_eq LittlerootBeach_EventScript_PlayerOnLeftFacingRival
	compare VAR_0x8004, 19
	goto_if_eq LittlerootBeach_EventScript_PlayerOnTopFacingRival
	compare VAR_0x8004, 20
	goto_if_eq LittlerootBeach_EventScript_RivalFacingPlayerOnRight
LittlerootBeach_EventScript_BrendanReportPart2::
	msgbox LittlerootBeach_Text_BrendanReport, MSGBOX_DEFAULT
	closemessage
	goto LittlerootBeach_EventScript_RivalLeaves
	end

LittlerootBeach_EventScript_PlayerOnLeftFacingRival::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq LittlerootBeach_EventScript_MayReportPart2
	compare VAR_RESULT, FEMALE
	goto_if_eq LittlerootBeach_EventScript_BrendanReportPart2
	end

LittlerootBeach_EventScript_PlayerOnTopFacingRival::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	applymovement LOCALID_RIVAL, Common_Movement_FaceUp
	waitmovement 0
	compare VAR_RESULT, MALE
	goto_if_eq LittlerootBeach_EventScript_MayReportPart2
	compare VAR_RESULT, FEMALE
	goto_if_eq LittlerootBeach_EventScript_BrendanReportPart2
	end

LittlerootBeach_EventScript_RivalFacingPlayerOnRight::
	applymovement LOCALID_RIVAL, Common_Movement_FaceRight
	waitmovement 0
	compare VAR_RESULT, MALE
	goto_if_eq LittlerootBeach_EventScript_MayReportPart2
	compare VAR_RESULT, FEMALE
	goto_if_eq LittlerootBeach_EventScript_BrendanReportPart2
	end

LittlerootBeach_EventScript_RivalLeaves::
	compare VAR_0x8004, 18
	goto_if_eq LittlerootBeach_EventScript_RivalLeavesPlayerLeftTop
	compare VAR_0x8004, 19
	goto_if_eq LittlerootBeach_EventScript_RivalLeavesPlayerLeftTop
	compare VAR_0x8004, 20
	goto_if_eq LittlerootBeach_EventScript_RivalLeavesPlayerRight
LittlerootBeach_EventScript_RivalLeavesPart2::
	removeobject LOCALID_RIVAL
	setflag FLAG_HIDE_LITTLEROOT_BEACH_RIVAL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
	fadedefaultbgm
	releaseall
	end

LittlerootBeach_EventScript_RivalLeavesPlayerLeftTop::
	applymovement LOCALID_RIVAL, LittlerootBeach_Movement_RivalLeavesPlayerLeftTop
	waitmovement 0
	goto LittlerootBeach_EventScript_RivalLeavesPart2

LittlerootBeach_EventScript_RivalLeavesPlayerRight::
	applymovement LOCALID_RIVAL, LittlerootBeach_Movement_RivalLeavesPlayerRight
	waitmovement 0
	goto LittlerootBeach_EventScript_RivalLeavesPart2

LittlerootBeach_Movement_RivalLeavesPlayerLeftTop:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootBeach_Movement_RivalLeavesPlayerRight:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

LittlerootBeach_Text_MayIntro:
	.string "May: {PLAYER}!\p"
	.string "Would you ever believe that a pretty\n"
	.string "place like this is just sitting right\l"
	.string "next to where we live?\p"
	.string "It's also entirely full of new Pokémon!\p"
	.string "Even in the water and the rocks.\n"
	.string "There are new species everywhere!$"

LittlerootBeach_Text_BrendanIntro:
	.string "Brendan: Hey, {PLAYER}.\p"
	.string "Who would have known that a place like\n"
	.string "this was sitting right by our doorsteps?\p"
	.string "It has new Pokémon everywhere.\n"
	.string "Not just the grass, but in the water and\l"
	.string "the rocks as well!$"

LittlerootBeach_Text_ZinniaIntro:
	.string "Whoa!\n"
	.string "It's great to meet you!\p"
	.string "…It is our first real meeting, right?\n"
	.string "Yeah. That's right. Of course it is!\p"
	.string "The name's Zinnia. And you…\n"
	.string "Well, I know ALL about you.\p"
	.string "You're {PLAYER}, of course.\n"
	.string "You're the new Pokémon League Champion!\p"
	.string "You're also the one that put a stop to\n"
	.string "that Legendary Pokémon clash back in\l"
	.string "Sootopolis, weren't you?\p"
	.string "Oh, this sure is a nice place, isn't it?\n"
	.string "Littleroot Town, and this beach.\p"
	.string "Oops! I'm going on too long.\n"
	.string "You're probably busy!\p"
	.string "Until next time, then. Buh-bye!$"

LittlerootBeach_Text_MayComment:
	.string "May: …well that was weird.$"

LittlerootBeach_Text_BrendanComment:
	.string "Brendan: Huh… was that a fan of yours,"
	.string "{PLAYER}?$"

LittlerootBeach_Text_MayReport:
	.string "May: Anyway, I've had a good look around\n"
	.string "and caught a bunch of Pokémon.\p"
	.string "You should have a good look around too.\n"
	.string "Some of these Pokémon might be good for\l"
	.string "battling.\p"
	.string "I'm going back to the lab to report back\n"
	.string "to my dad. See you there!$"

LittlerootBeach_Text_BrendanReport:
	.string "Brendan: As I was saying…\n"
	.string "I found a bunch of new Pokémon.\p"
	.string "I caught them for research, but some of\n"
	.string "them may be good for battling.\l"
	.string "Perhaps strong enough to defeat you?\p"
	.string "Anyway, I'm going back to the lab and\n"
	.string "give my dad a full report. See ya!$"
