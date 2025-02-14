.set LOCALID_RIVAL, 1
.set LOCALID_ZINNIA, 2

LittlerootBeach_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootBeach_OnTransition
	.byte 0

LittlerootBeach_OnTransition:
	setflag FLAG_LANDMARK_LITTLEROOT_BEACH
	compare VAR_LIITLEROOT_BEACH_STATE, 2
	goto_if_eq LittlerootBeach_EventScript_SetRivalBattleScene
	end

LittlerootBeach_EventScript_SetRivalBattleScene:
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_LOOK_AROUND
	setobjectxyperm LOCALID_RIVAL, 19, 25
	end

LittlerootBeach_EventScript_Mathew::
	trainerbattle_single TRAINER_MATTHEW, LittlerootBeach_Text_MathewIntro, LittlerootBeach_Text_MathewDefeat
	msgbox LittlerootBeach_Text_MathewPostBattle, MSGBOX_AUTOCLOSE
	end

LittlerootBeach_EventScript_Angelina::
	trainerbattle_single TRAINER_ANGELINA, LittlerootBeach_Text_AngelinaIntro, LittlerootBeach_Text_AngelinaDefeat
	msgbox LittlerootBeach_Text_AngelinaPostBattle, MSGBOX_AUTOCLOSE
	end

LittlerootBeach_EventScript_Jeff::
	trainerbattle_single TRAINER_JEFF, LittlerootBeach_Text_JeffIntro, LittlerootBeach_Text_JeffDefeat
	msgbox LittlerootBeach_Text_JeffPostBattle, MSGBOX_AUTOCLOSE
	end

LittlerootBeach_EventScript_RivalBattle::
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq LittlerootBeach_EventScript_MayBattle
	compare VAR_RESULT, FEMALE
	goto_if_eq LittlerootBeach_EventScript_BrendanBattle
	end

LittlerootBeach_EventScript_MayBattle:
	call LittlerootBeach_EventScript_PlayMayMusic
	msgbox LittlerootBeach_Text_MayLetsBattle, MSGBOX_DEFAULT
	closemessage
	switch VAR_STARTER_MON
	case 0, LittlerootBeach_EventScript_MayBattleTreecko
	case 1, LittlerootBeach_EventScript_MayBattleTorchic
	case 2, LittlerootBeach_EventScript_MayBattleMudkip
	end

LittlerootBeach_EventScript_MayBattleTreecko::
	trainerbattle_no_intro TRAINER_MAY_POST_GAME_TREECKO, LittlerootBeach_Text_MayDefeated
	goto LittlerootBeach_EventScript_MayDefeated
	end

LittlerootBeach_EventScript_MayBattleTorchic::
	trainerbattle_no_intro TRAINER_MAY_POST_GAME_TORCHIC, LittlerootBeach_Text_MayDefeated
	goto LittlerootBeach_EventScript_MayDefeated
	end

LittlerootBeach_EventScript_MayBattleMudkip::
	trainerbattle_no_intro TRAINER_MAY_POST_GAME_MUDKIP, LittlerootBeach_Text_MayDefeated
	goto LittlerootBeach_EventScript_MayDefeated
	end

LittlerootBeach_EventScript_MayDefeated::
	msgbox LittlerootBeach_Text_MayExit, MSGBOX_DEFAULT
	closemessage
	goto LittlerootBeach_EventScript_RivalExit
	end

LittlerootBeach_EventScript_BrendanBattle:
	call LittlerootBeach_EventScript_PlayBrendanMusic
	msgbox LittlerootBeach_Text_BrendanLetsBattle, MSGBOX_DEFAULT
	closemessage
	switch VAR_STARTER_MON
	case 0, LittlerootBeach_EventScript_BrendanBattleTreecko
	case 1, LittlerootBeach_EventScript_BrendanBattleTorchic
	case 2, LittlerootBeach_EventScript_BrendanBattleMudkip
	end

LittlerootBeach_EventScript_BrendanBattleTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_POST_GAME_TREECKO, LittlerootBeach_Text_BrendanDefeated
	goto LittlerootBeach_EventScript_BrendanDefeated
	end

LittlerootBeach_EventScript_BrendanBattleTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_POST_GAME_TORCHIC, LittlerootBeach_Text_BrendanDefeated
	goto LittlerootBeach_EventScript_BrendanDefeated
	end

LittlerootBeach_EventScript_BrendanBattleMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_POST_GAME_MUDKIP, LittlerootBeach_Text_BrendanDefeated
	goto LittlerootBeach_EventScript_BrendanDefeated
	end

LittlerootBeach_EventScript_BrendanDefeated::
	msgbox LittlerootBeach_Text_BrendanExit, MSGBOX_DEFAULT
	closemessage
	goto LittlerootBeach_EventScript_RivalExit
	end

LittlerootBeach_EventScript_RivalExit::
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject LOCALID_RIVAL
	waitfieldeffect FLDEFF_NPCFLY_OUT
	fadedefaultbgm
	delay 20
	pokenavcall LittlerootBeach_Text_SpaceCenterCall
	waitmessage
	delay 30
	setvar VAR_LIITLEROOT_BEACH_STATE, 3
	setflag FLAG_HIDE_LITTLEROOT_BEACH_RIVAL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 1
	setvar VAR_SPACE_CENTER_TRIGGER_STATE, 0
	clearflag FLAG_HIDE_ZINNIA_SPACE_CENTER
	clearflag FLAG_HIDE_STEVEN_SPACE_CENTER
	releaseall
	end

LittlerootBeach_EventScript_Rival::
	lockall
	faceplayer
	compare VAR_LIITLEROOT_BEACH_STATE, 2
	goto_if_eq LittlerootBeach_EventScript_RivalBattle
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
	goto_if_unset FLAG_RECEIVED_TM76, LittlerootBeach_EventScript_MayGivesTM76
	goto LittlerootBeach_EventScript_RivalLeaves
	end

LittlerootBeach_EventScript_MayGivesTM76::
	msgbox LittlerootBeach_Text_MayGivesTM76, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_TM76
	setflag FLAG_RECEIVED_TM76
	return

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
	goto_if_unset FLAG_RECEIVED_TM76, LittlerootBeach_EventScript_BrendanGivesTM76
	goto LittlerootBeach_EventScript_RivalLeaves
	end

LittlerootBeach_EventScript_BrendanGivesTM76::
	msgbox LittlerootBeach_Text_BrendanGivesTM76, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_TM76
	setflag FLAG_RECEIVED_TM76
	return

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
	setvar VAR_BIRCH_LAB_POSTGAME_STATE, 2
	savebgm MUS_DUMMY
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
	.string "This would be a great place to chill out\n"
	.string "with a cold drink.\p"
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
	.string "???: Whoa!\n"
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
	.string "Brendan: Huh… was that a fan of yours,\n"
	.string "{PLAYER}?$"

LittlerootBeach_Text_MayReport:
	.string "May: Anyway, I've had a good look around\n"
	.string "and caught a bunch of Pokémon.\p"
	.string "You should have a good look around too.\n"
	.string "Some of these Pokémon might make good\l"
	.string "battle partners.\p"
	.string "I'm going back to the lab to report back\n"
	.string "to my dad. See you there!$"

LittlerootBeach_Text_MayGivesTM76:
	.string "May: Oh by the way, I've been meaning to\n"
	.string "give you this earlier.$"

LittlerootBeach_Text_BrendanReport:
	.string "Brendan: As I was saying…\n"
	.string "I found a bunch of new Pokémon.\p"
	.string "I caught them for research, but some of\n"
	.string "them may be good for battling.\l"
	.string "Perhaps strong enough to defeat you?\p"
	.string "Anyway, I'm going back to the lab and\n"
	.string "give my dad a full report. See ya!$"

LittlerootBeach_Text_BrendanGivesTM76:
	.string "Brendan: Oh, and before I forget,\n"
	.string "I got this a while ago. I don't need\l"
	.string "it so you can have it.$"

LittlerootBeach_Text_MayLetsBattle:
	.string "May: Okay, {PLAYER}.\n"
	.string "I'm giving it one more try.\p"
	.string "I've trained up a bunch of new\n"
	.string "Pokémon just to face you.\p"
	.string "I'm ready. Give it all you've got!$"

LittlerootBeach_Text_MayDefeated:
	.string "May: Well, that wasn't unexpected.$"

LittlerootBeach_Text_MayExit:
	.string "May: I can't believe it wasn't that long\n"
	.string "ago when you moved into Littleroot.\p"
	.string "You know, I'm glad you did.\p"
	.string "I don't think I would have ever pushed\n"
	.string "myself this hard if I hadn't met you.\p"
	.string "Even though I still can't beat you,\n"
	.string "I've grown so much stronger as a person.\p"
	.string "I've also had so much enjoyment\n"
	.string "travelling, raising and catching\l"
	.string "Pokémon.\p"
	.string "So thank you for coming here,\n"
	.string "{PLAYER}.\p"
	.string "Well then, see ya!$"

LittlerootBeach_Text_BrendanLetsBattle:
	.string "Brendan: Alright, {PLAYER}.\p"
	.string "I've trained some new Pokémon I've\n"
	.string "found just to see if I can beat you.\p"
	.string "Lets go!$"

LittlerootBeach_Text_BrendanDefeated:
	.string "Brendan: Yeah, you're still the best\n"
	.string "around.$"

LittlerootBeach_Text_BrendanExit:
	.string "Brendan: It feels like an age ago that\n"
	.string "you moved into our town. Though it\l"
	.string "actually wasn't that long.\p"
	.string "So much has happened since then.\n"
	.string "I travelled across Hoenn, trained and\l"
	.string "caught many Pokémon.\p"
	.string "If I hadn't met you, then I would have\n"
	.string "probably stayed in Littleroot and never\l"
	.string "challenged myself like that.\p"
	.string "So what I'm saying is, thanks for\n"
	.string "coming into my life, {PLAYER}.\p"
	.string "That's all I wanted to say.\n"
	.string "Bye!$"

LittlerootBeach_Text_SpaceCenterCall:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "Steven: Hey, {PLAYER}.\n"
	.string "It's Steven.\p"
	.string "Sorry for interupting you but this is\n"
	.string "quite urgent.\p"
	.string "There seems to be trouble brewing\n"
	.string "at the Space Center.\p"
	.string "Could you come over and back me up?\p"
	.string "See you there!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"
