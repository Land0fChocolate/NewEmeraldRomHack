.set LOCALID_ZINNIA, 2

CrumblingGorge_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CrumblingGorge_OnTransition
	.byte 0

CrumblingGorge_OnTransition:
	setflag FLAG_LANDMARK_CRUMBLING_GORGE
	end

CrumblingGorge_EventScript_Camina::
	trainerbattle_single TRAINER_CAMINA, CrumblingGorge_Text_CaminaIntro, CrumblingGorge_Text_CaminaDefeat
	msgbox CrumblingGorge_Text_CaminaPostBattle, MSGBOX_AUTOCLOSE
	end

CrumblingGorge_EventScript_Holden::
	trainerbattle_single TRAINER_HOLDEN, CrumblingGorge_Text_HoldenIntro, CrumblingGorge_Text_HoldenDefeat
	msgbox CrumblingGorge_Text_HoldenPostBattle, MSGBOX_AUTOCLOSE
	end

CrumblingGorge_EventScript_Nagata::
	trainerbattle_single TRAINER_NAGATA, CrumblingGorge_Text_NagataIntro, CrumblingGorge_Text_NagataDefeat
	msgbox CrumblingGorge_Text_NagataPostBattle, MSGBOX_AUTOCLOSE
	end

CrumblingGorge_EventScript_Amos::
	trainerbattle_single TRAINER_AMOS, CrumblingGorge_Text_AmosIntro, CrumblingGorge_Text_AmosDefeat
	msgbox CrumblingGorge_Text_AmosPostBattle, MSGBOX_AUTOCLOSE
	end

CrumblingGorge_EventScript_ZinniaTrigger::
	lockall
	setvar VAR_CRUMBLING_GORGE_TRIGGER_STATE, 1
	msgbox CrumblingGorge_Text_NotAppearing, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_ZINNIA, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_ZINNIA, Common_Movement_ExclamationMark
	waitmovement 0
	playse SE_PIN
	delay 60
	getplayerxy VAR_0x8004, VAR_0x8005
	compare VAR_0x8004, 10
	goto_if_eq CrumblingGorge_EventScript_ZinniaTriggerLeft
	goto CrumblingGorge_EventScript_ZinniaTriggerRight
	end

CrumblingGorge_EventScript_ZinniaTriggerLeft::
	applymovement LOCALID_ZINNIA, CrumblingGorge_Movement_ZinniaToPlayerLeft
	waitmovement 0
	goto CrumblingGorge_EventScript_ZinniaTalkToPlayer

CrumblingGorge_Movement_ZinniaToPlayerLeft:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

CrumblingGorge_EventScript_ZinniaTriggerRight::
	applymovement LOCALID_ZINNIA, CrumblingGorge_Movement_ZinniaToPlayerRight
	waitmovement 0
	goto CrumblingGorge_EventScript_ZinniaTalkToPlayer

CrumblingGorge_Movement_ZinniaToPlayerRight:
	walk_up
	walk_up
	walk_up
	step_end

CrumblingGorge_EventScript_ZinniaTalkToPlayer::
	msgbox CrumblingGorge_Text_GorgeHistory, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ZINNIA, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject LOCALID_ZINNIA
	waitfieldeffect FLDEFF_NPCFLY_OUT
	setflag FLAG_HIDE_ZINNIA_CRUMBLING_GORGE
	addvar VAR_NEW_AREA_EXPLORE, 1
	compare VAR_NEW_AREA_EXPLORE, 5
	goto_if_eq Wildwoods_Area9_Eventscript_SetBirchReportCall
	release
	end

CrumblingGorge_Text_NotAppearing:
	.string "Zinnia: …this is confounding!\n"
	.string "Why does it not respond to me?\p"
	.string "Hmm… … … … … … …$"

CrumblingGorge_Text_GorgeHistory:
	.string "Zinnia: Oh hello, {PLAYER}.\n"
	.string "It's good to see you again.\p"
	.string "This gorge we are standing in, was not\n"
	.string "made naturally.\p"
	.string "It's actually a battle wound from when\n"
	.string "two powerful Pokémon fought one\l"
	.string "another long ago.\p"
	.string "It must have been quite the spectacle.\p"
	.string "I'll be taking my leave, since I haven't\n"
	.string "found what I'm looking for.\p"
	.string "I hope you have more success with\n"
	.string "whatever business you have here.$"
