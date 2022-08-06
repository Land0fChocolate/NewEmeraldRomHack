FortreeJungle_Area2_MapScripts::
	.byte 0

FortreeJungle_Area2_Eventscript_Ryu::
	trainerbattle_single TRAINER_RYU, FortreeJungle_Area2_Text_RyuIntro, FortreeJungle_Area2_Text_RyuDefeat
	msgbox FortreeJungle_Area2_Text_RyuPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeJungle_Area2_Eventscript_AquaMember::
	msgbox FortreeJungle_Area2_Text_AquaMember, MSGBOX_NPC
	end

FortreeJungle_Area2_Text_AquaMember:
	.string "This place is so humid and prickly!\n"
	.string "I much prefer being out on the ocean.\p"
	.string "Perhaps I should take a dip in that\n"
	.string "pond? The Pokémon in there probably\l"
	.string "won't mind too much…$"
