Wildwoods_Area9_MapScripts::
	.byte 0

Wildwoods_Area9_Eventscript_Courtney::
	msgbox Wildwoods_Area9_Text_Courtney, MSGBOX_NPC
	setflag FLAG_MET_COURTNEY_WILDWOODS
	end

Wildwoods_Area9_Eventscript_MagmaF::
	msgbox Wildwoods_Area9_Text_StudyingEnviroment, MSGBOX_NPC
	end

Wildwoods_Area9_Eventscript_MagmaM::
	msgbox Wildwoods_Area9_Text_MagmaM, MSGBOX_NPC
	end

Wildwoods_Area9_Text_Courtney:
	.string "Courtney: Observer hypothesis… wild\n"
	.string "Pokémon are distorting perception of\l"
	.string "the location to unsettle outsiders.\p"
	.string "Effect on observer… ineffective.\p"
	.string "Is the phenomenon introduced by the new\n"
	.string "Pokémon species?\l"
	.string "Requires further study…$"

Wildwoods_Area9_Text_StudyingEnviroment:
	.string "We're here just to study the\n"
	.string "environment.\p"
	.string "It's a little scary, but it's much more\n"
	.string "preferable to bullying the locals for\l"
	.string "technology or waking up dangerous\l"
	.string "legendary Pokémon.$"

Wildwoods_Area9_Text_MagmaM:
	.string "Every area in this forest has a unique\n"
	.string "distribution of Pokémon species,\p"
	.string "Some of the areas also have Pokémon\n"
	.string "that are not found in others.$"
