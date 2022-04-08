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
	.string "Our leader told us to dig into\n"
	.string "Mt. Chimney, so we dug and dug.\p"
	.string "And in the course of digging, we came\n"
	.string "across something that blew our minds!\p"
	.string "What did we find?\p"
	.string "Fuhahaha!\n"
	.string "I'll tell you if you beat me!$"

MagmaHideout_1F_Text_Grunt1Defeat:
	.string "Arrgh!\n"
	.string "Taken down!$"

MagmaHideout_1F_Text_Grunt1PostBattle:
	.string "I won't tell you after all.\n"
	.string "You'll find out when you get there!\p"
	.string "It'd be better if you saved surprises\n"
	.string "to the end, don't you think?$"

MagmaHideout_1F_Text_Grunt2Intro:
	.string "Drat! Team Aqua followed us!\n"
	.string "Wait, you're not Team Aqua. who\n"
	.string "are you?$"

MagmaHideout_1F_Text_Grunt2Defeat:
	.string "Is it that easy to just walk in here?$"

MagmaHideout_1F_Text_Grunt2PostBattle:
	.string "It took a while getting the boss back\n"
	.string "to base, we were attacked by an Aqua\l"
	.string "hit squad. They somehow knew what we\l"
	.string "were up to.$"

