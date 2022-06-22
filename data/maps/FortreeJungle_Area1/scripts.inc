FortreeJungle_Area1_MapScripts::
	.byte 0

FortreeJungle_Area1_OnTransition:
	setflag FLAG_LANDMARK_FORTREE_JUNGLE
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
