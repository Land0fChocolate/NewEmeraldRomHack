.set LOCALID_ZINNIA, 3

MagmaHideout_3F_1R_MapScripts::
	.byte 0

MagmaHideout_3F_1R_EventScript_Zinnia_Trigger::
	lock
	msgbox MagmaHideout_3F_1R_Text_ZinniaPreIntro, MSGBOX_DEFAULT
	closemessage
	faceplayer
	applymovement LOCALID_ZINNIA, Common_Movement_FaceRight
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_ZINNIA, Common_Movement_ExclamationMark
	waitmovement 0
	delay 60
	getplayerxy VAR_0x8004, VAR_0x8005
	compare VAR_0x8005, 4
	goto_if_eq MagmaHideout_3F_1R_EventScript_ZinniaWalkX4
	compare VAR_0x8005, 5
	goto_if_eq MagmaHideout_3F_1R_EventScript_ZinniaWalkX5
	compare VAR_0x8005, 6
	goto_if_eq MagmaHideout_3F_1R_EventScript_ZinniaWalkX6
	compare VAR_0x8005, 7
	goto_if_eq MagmaHideout_3F_1R_EventScript_ZinniaWalkX7
	release
	end

MagmaHideout_3F_1R_EventScript_ZinniaWalkX4::
	applymovement LOCALID_ZINNIA, MagmaHideout_3F_1R_Movement_ZinniaWalkX4
	waitmovement 0
	goto MagmaHideout_3F_1R_EventScript_ZinniaMeetsPlayer

MagmaHideout_3F_1R_EventScript_ZinniaWalkX5::
	applymovement LOCALID_ZINNIA, MagmaHideout_3F_1R_Movement_ZinniaWalkX5
	waitmovement 0
	goto MagmaHideout_3F_1R_EventScript_ZinniaMeetsPlayer

MagmaHideout_3F_1R_EventScript_ZinniaWalkX6::
	applymovement LOCALID_ZINNIA, MagmaHideout_3F_1R_Movement_ZinniaWalkX6
	waitmovement 0
	goto MagmaHideout_3F_1R_EventScript_ZinniaMeetsPlayer

MagmaHideout_3F_1R_EventScript_ZinniaWalkX7::
	applymovement LOCALID_ZINNIA, MagmaHideout_3F_1R_Movement_ZinniaWalkX7
	waitmovement 0
	goto MagmaHideout_3F_1R_EventScript_ZinniaMeetsPlayer

MagmaHideout_3F_1R_Movement_ZinniaWalkX4:
	walk_right
	walk_right
	walk_right
	step_end

MagmaHideout_3F_1R_Movement_ZinniaWalkX5:
	walk_right
	walk_down
	walk_right
	walk_right
	step_end

MagmaHideout_3F_1R_Movement_ZinniaWalkX6:
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

MagmaHideout_3F_1R_Movement_ZinniaWalkX7:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	step_end

MagmaHideout_3F_1R_EventScript_ZinniaMeetsPlayer::
	msgbox MagmaHideout_3F_1R_Text_ZinniaMeetsPlayer, MSGBOX_DEFAULT
	closemessage
	setvar VAR_MAGMA_HIDEOUT_ZINNIA_TRIGGER_STATE, 1
	release
	end

MagmaHideout_3F_1R_EventScript_Zinnia::
	msgbox MagmaHideout_3F_1R_Text_ZinniaIdle, MSGBOX_NPC
	end

MagmaHideout_3F_1R_EventScript_Grunt9::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_9, MagmaHideout_3F_1R_Text_Grunt9Intro, MagmaHideout_3F_1R_Text_Grunt9Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt9PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_EventScript_Grunt16::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_16, MagmaHideout_3F_1R_Text_Grunt16Intro, MagmaHideout_3F_1R_Text_Grunt16Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt16PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_Text_ZinniaPreIntro:
	.string "…Stern has found it. The location is\n"
	.string "likely to remain in his vessel's logs…$"

MagmaHideout_3F_1R_Text_ZinniaMeetsPlayer:
	.string "Oh my, an intruder?\p"
	.string "Aha, you're the Trainer that has been\n"
	.string "interfering with Team Magma and Team\l"
	.string "Aqua since the Petalburg Woods\l"
	.string "incident.\p"
	.string "You have business with Maxie, that's\n"
	.string "why you've come all the way here?\p"
	.string "Hmm…\p"
	.string "Yeah, this can work out.\p"
	.string "It's an unscheduled meeting, but you\n"
	.string "can go on through.$"

MagmaHideout_3F_1R_Text_ZinniaIdle:
	.string "Oh don't mind me. Just do whatever it\n"
	.string "is you came here to do.$"

MagmaHideout_3F_1R_Text_Grunt9Intro:
	.string "What did I do to deserve this guard\n"
	.string "posting?\p"
	.string "My left ear is burning up!$"

MagmaHideout_3F_1R_Text_Grunt9Defeat:
	.string "I'm getting heat exhaustion…$"

MagmaHideout_3F_1R_Text_Grunt9PostBattle:
	.string "Our outfits are supposed to be heat\n"
	.string "resistant, but there is only so much\l"
	.string "heat they can take.$"

MagmaHideout_3F_1R_Text_Grunt16Intro:
	.string "We joined so we can help our leader\n"
	.string "achieve his fantastic vision.\p"
	.string "I don't care if you're with Team Aqua\n"
	.string "or if you're just some kid passing by.\p"
	.string "No one interferes with us and gets\n"
	.string "away with it!$"

MagmaHideout_3F_1R_Text_Grunt16Defeat:
	.string "Oh, no!\n"
	.string "You're not to be trusted at all!$"

MagmaHideout_3F_1R_Text_Grunt16PostBattle:
	.string "Listen to me.\n"
	.string "Team Magma is right!\p"
	.string "Don't listen to Team Aqua.\n"
	.string "Don't believe their lies!$"

