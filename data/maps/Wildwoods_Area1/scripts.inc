Wildwoods_Area1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Wildwoods_Area1_OnTransition
	.byte 0

Wildwoods_Area1_OnTransition:
	setflag FLAG_LANDMARK_WILDWOODS
	end

Wildwoods_Area1_Eventscript_MagmaF::
	msgbox Wildwoods_Area1_Text_WildwoodsConfusing, MSGBOX_NPC
	end

Wildwoods_Area1_Text_WildwoodsConfusing:
	.string "Gah!\n"
	.string "This place makes no sense!\p"
	.string "I know I came this way from our camp,\n"
	.string "but now it doesn't seem to be nearby at\l"
	.string "all!\p"
	.string "I want out of this creepy forest, but I\n"
	.string "don't want to let down the team…$"
