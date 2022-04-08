MagmaHideout_3F_2R_MapScripts::
	.byte 0

MagmaHideout_3F_2R_EventScript_Grunt10::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_10, MagmaHideout_3F_2R_Text_Grunt10Intro, MagmaHideout_3F_2R_Text_Grunt10Defeat
	msgbox MagmaHideout_3F_2R_Text_Grunt10PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_2R_Text_Grunt10Intro:
	.string "I told you nitwits time and time again.\n"
	.string "If you want a drill, you need to fill\l"
	.string "out a drill request form from logistics.$"

MagmaHideout_3F_2R_Text_Grunt10Defeat:
	.string "Somehow, I don't think you're here for\n"
	.string "the drills.$"

MagmaHideout_3F_2R_Text_Grunt10PostBattle:
	.string "These drills are some wicked cool tech,\n"
	.string "though we have spent an awful lot of\l"
	.string "our budget on them.\p"
	.string "It may have been easier and cheaper to\n"
	.string "use Pokémon, though the average Magma\l"
	.string "members are pretty mediocre Trainers.$"

