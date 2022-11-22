.set LOCALID_MATT, 1
.set LOCALID_SUBMARINE, 4

AquaHideout_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B2F_OnTransition
	.byte 0

AquaHideout_B2F_OnTransition:
	call_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, AquaHideout_B2F_EventScript_PreventMattNoticing
	end

AquaHideout_B2F_EventScript_PreventMattNoticing::
	setvar VAR_TEMP_1, 1
	return

AquaHideout_B2F_EventScript_MattNoticePlayer::
	lockall
	setvar VAR_0x8008, LOCALID_MATT
	playse SE_PIN
	applymovement VAR_0x8008, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	setvar VAR_TEMP_1, 1
	releaseall
	end

AquaHideout_B2F_EventScript_Matt::
	trainerbattle_single TRAINER_MATT, AquaHideout_B2F_Text_MattIntro, AquaHideout_B2F_Text_MattDefeat, AquaHideout_B2F_EventScript_SubmarineEscape
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_SubmarineEscape::
	setvar VAR_0x8008, LOCALID_MATT
	setvar VAR_0x8009, LOCALID_SUBMARINE
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_OurBossGotThroughHisPreparations, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFastestLeft
	applymovement VAR_0x8009, AquaHideout_B2F_Movement_SumbarineDepartLeft
	waitmovement 0
	removeobject VAR_0x8009
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	setflag FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE
	setflag FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS
	release
	end

AquaHideout_B2F_Movement_SumbarineDepartLeft:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

@ Unused
AquaHideout_B2F_Movement_SumbarineDepartRight:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

AquaHideout_B2F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_4, AquaHideout_B2F_Text_Grunt4Intro, AquaHideout_B2F_Text_Grunt4Defeat, AquaHideout_B2F_EventScript_Grunt4Defeated
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt4Defeated::
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_6, AquaHideout_B2F_Text_Grunt6Intro, AquaHideout_B2F_Text_Grunt6Defeat
	msgbox AquaHideout_B2F_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_8, AquaHideout_B2F_Text_Grunt8Intro, AquaHideout_B2F_Text_Grunt8Defeat
	msgbox AquaHideout_B2F_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_Text_MattIntro:
	.string "Woah!\p"
	.string "You're the first punk ever to sneak\n"
	.string "into this hideout and make it this far!\p"
	.string "But I've got some bad news for you!\p"
	.string "We already completely finished\n"
	.string "upgrading the sub!\p"
	.string "My bro Archie's in the sub!\n"
	.string "If you take me out fast, you might\l"
	.string "be able to catch up to him!\p"
	.string "That is, if your sorry Pokémon can beat\n"
	.string "my not-so-sorry Pokémon.\p"
	.string "Come at me!$"

AquaHideout_B2F_Text_MattDefeat:
	.string "Oho!\n"
	.string "That hurt!$"

AquaHideout_B2F_Text_OurBossGotThroughHisPreparations:
	.string "Hah… Hah… Hah… Bro!\n"
	.string "It's all…on you…now…\p"
	.string "While we were battling it out…\n"
	.string "My bro Archie finished getting ready…$"

AquaHideout_B2F_Text_MattPostBattle:
	.string "My bro is headed for the big blue sea\n"
	.string "that stretches out from Lilycove City.\p"
	.string "There's a cave out there deep under\n"
	.string "the water.\p"
	.string "I don't see how you can follow him,\n"
	.string "unless you have a sub.$"

AquaHideout_B2F_Text_Grunt4Intro:
	.string "There you are!\n"
	.string "The boss said you'll be coming!$"

AquaHideout_B2F_Text_Grunt4Defeat:
	.string "Well, whatever…$"

AquaHideout_B2F_Text_Grunt4PostBattle:
	.string "I already loaded the supplies and\n"
	.string "equipment onto the sub.\l"
	.string "My job is done.$"

AquaHideout_B2F_Text_Grunt6Intro:
	.string "Warp panels, the Hideout's pride\n"
	.string "and joy!\p"
	.string "You're clueless about where you are,\n"
	.string "aren't you?\p"
	.string "Fluster and tire out the enemy, then\n"
	.string "lower the boom! That's our plan!$"

AquaHideout_B2F_Text_Grunt6Defeat:
	.string "What's wrong with you?\n"
	.string "You're not tired at all!$"

AquaHideout_B2F_Text_Grunt6PostBattle:
	.string "Err… I can't remember how to get to the\n"
	.string "restroom…\l"
	.string "Dammit! I really need to go!$"

AquaHideout_B2F_Text_Grunt8Intro:
	.string "When I joined Team Aqua, the first\n"
	.string "thing I had to learn was how these\l"
	.string "warp panels connected.$"

AquaHideout_B2F_Text_Grunt8Defeat:
	.string "I was too occupied thinking about\n"
	.string "the warp panels…$"

AquaHideout_B2F_Text_Grunt8PostBattle:
	.string "I'll have to learn about how I can\n"
	.string "battle more effectively…$"
