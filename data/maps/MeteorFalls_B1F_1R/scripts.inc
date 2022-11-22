MeteorFalls_B1F_1R_MapScripts::
	.byte 0

MeteorFalls_B1F_1R_EventScript_Jayce::
	trainerbattle_single TRAINER_JAYCE, MeteorFalls_B1F_1R_Text_JayceIntro, MeteorFalls_B1F_1R_Text_JayceDefeat
	msgbox MeteorFalls_B1F_1R_Text_JaycePostBattle, MSGBOX_AUTOCLOSE
	end

MeteorFalls_B1F_1R_EventScript_Wilson::
	trainerbattle_single TRAINER_WILSON, MeteorFalls_B1F_1R_Text_WilsonIntro, MeteorFalls_B1F_1R_Text_WilsonDefeat
	msgbox MeteorFalls_B1F_1R_Text_WilsonPostBattle, MSGBOX_AUTOCLOSE
	end

MeteorFalls_B1F_1R_Text_JayceIntro:
	.string "Huh?\n"
	.string "What is this peasant doing in our\l"
	.string "domain?$"

MeteorFalls_B1F_1R_Text_JayceDefeat:
	.string "That's some power!$"

MeteorFalls_B1F_1R_Text_JaycePostBattle:
	.string "I suppose there's nothing wrong with\n"
	.string "you wandering around, as long as\l"
	.string "you treat Meteor Falls with respect.$"

MeteorFalls_B1F_1R_Text_WilsonIntro:
	.string "Hi! Have you seen any of the rare\n"
	.string "dragon Pokémon?$"

MeteorFalls_B1F_1R_Text_WilsonDefeat:
	.string "Could I be looking in the wrong place?$"

MeteorFalls_B1F_1R_Text_WilsonPostBattle:
	.string "I know there's rare dragon Pokémon\n"
	.string "in this cave. Where could they be?$"
