FallarborWasteland_MapScripts::
	.byte 0

FallarborWasteland_OnTransition:
	setflag FLAG_LANDMARK_FALLARBOR_WASTELAND
	end

FallarborWasteland_Eventscript_Tabitha::
	msgbox FallarborWasteland_Text_TabithaFieldWork, MSGBOX_NPC
	setflag FLAG_MET_TABITHA_FALLARBOR_WASTES
	end

FallarborWasteland_Eventscript_MagmaPostBridge::
	msgbox FallarborWasteland_Text_BridgeMagma, MSGBOX_NPC
	end

FallarborWasteland_Eventscript_ObserveMagmaF::
	msgbox FallarborWasteland_Text_ObserveMagmaF, MSGBOX_NPC
	end

FallarborWasteland_Eventscript_ObserveMagmaM::
	msgbox FallarborWasteland_Text_ObserveMagmaM, MSGBOX_NPC
	end

FallarborWasteland_Eventscript_WanderMagma::
	msgbox FallarborWasteland_Text_WanderMagma, MSGBOX_NPC
	end

FallarborWasteland_Text_TabithaFieldWork:
	.string "Tabitha: Team Magma turned over a new\n"
	.string "leaf. We're starting over.\p"
	.string "We're now looking for other ways to help\n"
	.string "humanity's progress, whilst also\l"
	.string "preserving the natural world.\p"
	.string "We're even collaborating with Team Aqua.\p"
	.string "Here, we're performing an inspection\n"
	.string "on a newly discovered area. We already\l"
	.string "have some interesting findings.$"

FallarborWasteland_Text_BridgeMagma:
	.string "The soil is too poor for most plants.\n"
	.string "This place is very much a wasteland.\p"
	.string "These caverns cut into the land are\n"
	.string "promising though, it could expose some\l"
	.string "useful minerals.$"

FallarborWasteland_Text_ObserveMagmaF:
	.string "We've spotted a minor legendary Pokémon\n"
	.string "flying in the area. It probably has\l"
	.string "a lair somewhere around here.$"

FallarborWasteland_Text_ObserveMagmaM:
	.string "We're here to inspect the land of the\n"
	.string "area, to see if there are any good\l"
	.string "natural resources to be found.\p"
	.string "We've also found a lot of unusual\n"
	.string "Pokémon. We'll be studying them as well.$"

FallarborWasteland_Text_WanderMagma:
	.string "I've seen a bunch of fiery horse Pokémon\n"
	.string "run around. They're so pretty!\l"
	.string "I have to get one of them!$"
