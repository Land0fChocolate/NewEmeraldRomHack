MagmaHideout_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MagmaHideout_1F_OnTransition
	.byte 0

MagmaHideout_1F_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0
	end

MagmaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_1, MagmaHideout_1F_Text_Grunt1Intro, MagmaHideout_1F_Text_Grunt1Defeat
	msgbox MagmaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_2, MagmaHideout_1F_Text_Grunt2Intro, MagmaHideout_1F_Text_Grunt2Defeat
	msgbox MagmaHideout_1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_Text_Grunt1Intro:
	.string "You!\p"
	.string "You're the brat who stopped us from\n"
	.string "erupting Mt Chimney!\p"
	.string "You've taken from humanity all that\n"
	.string "land and rare metals the volcano would\l"
	.string "have churned up!\p"
	.string "You're gonna pay!$"

MagmaHideout_1F_Text_Grunt1Defeat:
	.string "And now you've taken this victory from\n"
	.string "us as well…$"

MagmaHideout_1F_Text_Grunt1PostBattle:
	.string "There's only so much one kid can do.\n"
	.string "We'll reach our goals sooner or later.$"

MagmaHideout_1F_Text_Grunt2Intro:
	.string "Drat! Team Aqua found us!\p"
	.string "Wait, you're not Team Aqua.\n"
	.string "Who are you?$"

MagmaHideout_1F_Text_Grunt2Defeat:
	.string "Is it that easy to just walk in here?$"

MagmaHideout_1F_Text_Grunt2PostBattle:
	.string "It took a while getting the boss back\n"
	.string "to base.\p"
	.string "We were attacked by an Aqua hit squad.\n"
	.string "They somehow knew what we were up to.$"

