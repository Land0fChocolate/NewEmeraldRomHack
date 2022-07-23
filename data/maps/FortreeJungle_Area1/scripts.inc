FortreeJungle_Area1_MapScripts::
	.byte 0

FortreeJungle_Area1_OnTransition:
	setflag FLAG_LANDMARK_FORTREE_JUNGLE
	end

FortreeJungle_Area1_Eventscript_Zuko::
	trainerbattle_single TRAINER_ZUKO, FortreeJungle_Area1_Text_ZukoIntro, FortreeJungle_Area1_Text_ZukoDefeat
	msgbox FortreeJungle_Area1_Text_ZukoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeJungle_Area1_Eventscript_Joss::
	trainerbattle_single TRAINER_JOSS, FortreeJungle_Area1_Text_JossIntro, FortreeJungle_Area1_Text_JossDefeat
	msgbox FortreeJungle_Area1_Text_JossPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeJungle_Area1_Eventscript_AquaMember::
	msgbox FortreeJungle_Area1_Text_AquaMember, MSGBOX_NPC
	end

FortreeJungle_Area1_Text_AquaMember:
	.string "This is one thick jungle.\n"
	.string "It's truly wild here.\p"
	.string "The others have cut their way through.\n"
	.string "I've moved back to the entrance to\l"
	.string "record the fauna in this area.$"
