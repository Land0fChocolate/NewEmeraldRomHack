FortreeJungle_Area1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeJungle_Area1_OnTransition
	.byte 0

FortreeJungle_Area1_OnTransition:
	setflag FLAG_LANDMARK_FORTREE_JUNGLE
	end

FortreeJungle_Area1_Eventscript_Zuko::
	trainerbattle_single TRAINER_ZUKO, FortreeJungle_Area1_Text_ZukoIntro, FortreeJungle_Area1_Text_ZukoDefeat
	msgbox FortreeJungle_Area1_Text_ZukoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeJungle_Area1_Eventscript_Gabrielle::
	trainerbattle_single TRAINER_GABRIELLE, FortreeJungle_Area1_Text_GabrielleIntro, FortreeJungle_Area1_Text_GabrielleDefeat
	msgbox FortreeJungle_Area1_Text_GabriellePostBattle, MSGBOX_AUTOCLOSE
	end

FortreeJungle_Area1_Text_GabrielleIntro:
	.string "Look, my children.\n"
	.string "A Trainer to play with!$"

FortreeJungle_Area1_Text_GabrielleDefeat:
	.string "You play hard!$"

FortreeJungle_Area1_Text_GabriellePostBattle:
	.string "Letting your Pokémon enjoy themselves\n"
	.string "is an integral part of their growth.$"

FortreeJungle_Area1_Eventscript_AquaMember::
	msgbox FortreeJungle_Area1_Text_AquaMember, MSGBOX_NPC
	end

FortreeJungle_Area1_Text_AquaMember:
	.string "This is one thick jungle.\n"
	.string "It's truly wild here.\p"
	.string "The others have cut their way through.\n"
	.string "I've moved back to the entrance to\l"
	.string "record the fauna in this area.$"
