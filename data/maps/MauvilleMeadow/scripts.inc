MauvilleMeadow_MapScripts::
	.byte 0

MauvilleMeadow_OnTransition:
	setflag FLAG_LANDMARK_MAUVILLE_MEADOW
	end

MauvilleMeadow_Eventscript_Shelly::
	msgbox MauvilleMeadow_Text_Shelly, MSGBOX_NPC
	setflag FLAG_MET_SHELLY_MAUVILLE_MEADOW
	end

MauvilleMeadow_Eventscript_FlowerAqua::
	msgbox MauvilleMeadow_Text_FlowerAqua, MSGBOX_NPC
	end

MauvilleMeadow_Eventscript_ObserveAquaM::
	msgbox MauvilleMeadow_Text_ObserveAquaM, MSGBOX_NPC
	end

MauvilleMeadow_Eventscript_ObserveAquaF::
	msgbox MauvilleMeadow_Text_ObserveAquaF, MSGBOX_NPC
	end

MauvilleMeadow_Eventscript_WanderAqua::
	msgbox MauvilleMeadow_Text_WanderAqua, MSGBOX_NPC
	end

MauvilleMeadow_Text_Shelly:
	.string "Team Aqua has taken a step in a new\n"
	.string "direction. We're helping the natural\l"
	.string "world propagate, though not at the\l"
	.string "expense of human society or others.\p"
	.string "Our mission here is to analyze the\n"
	.string "ecosystem of this newly discovered\l"
	.string "habitat.\p"
	.string "This area and its Pokémon are very\n"
	.string "interesting. We'll be here for a while.$"

MauvilleMeadow_Text_FlowerAqua:
	.string "Huh?!\p"
	.string "I'm not goofing off!\p"
	.string "I'm err… analyzing the flowers here.\n"
	.string "All botanist-like. Yeah!$"

MauvilleMeadow_Text_ObserveAquaM:
	.string "Those fissures in the land are a feature\n"
	.string "not seen anywhere else in Hoenn.\l"
	.string "I wonder what caused them?$"

MauvilleMeadow_Text_ObserveAquaF:
	.string "It's crazy that such an untouched place\n"
	.string "is located right nearby Mauville.\p"
	.string "I guess there were no easy ways to get\n"
	.string "here before?$"

MauvilleMeadow_Text_WanderAqua:
	.string "A lot of our members quit after that\n"
	.string "Sootopolis fiasco.\p"
	.string "I don't blame 'em. We went too far and\n"
	.string "nearly wrecked everything.\p"
	.string "We have new ideals now, and we're even\n"
	.string "cooperating with Team Magma.$"
