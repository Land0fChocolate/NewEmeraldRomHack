FallarborWasteland_MapScripts::
	.byte 0

FallarborWasteland_OnTransition:
	setflag FLAG_LANDMARK_FALLARBOR_WASTELAND
	end

FallarborWasteland_Eventscript_Tabitha::
	msgbox FallarborWasteland_Text_TabithaFieldWork, MSGBOX_NPC
	setflag FLAG_MET_TABITHA_FALLARBOR_WASTES
	goto_if_unset FLAG_BIRCH_CALLED_PLAYER, FallarborWasteland_Eventscript_CheckForBirchReportCall
	end

FallarborWasteland_Eventscript_CheckForBirchReportCall::
	checkmultiflags FLAG_MET_COURTNEY_WILDWOODS, FLAG_MET_SHELLY_MAUVILLE_MEADOW, FLAG_MET_MATT_FORTREE_JUNGLE 
	goto_if TRUE, Wildwoods_Area9_Eventscript_SetBirchReportCall
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
	.string "We even have a collaboration with\n"
	.string "Team Aqua.\p"
	.string "Here, we're performing an inspection\n"
	.string "on a newly discovered area.\l"
	.string "We already have some good findings.$"

FallarborWasteland_Text_BridgeMagma:
	.string "The fact that this bridge exists, means\n"
	.string "that humans have been here before a long\l"
	.string "time ago.\p"
	.string "We should be careful when digging. There\n"
	.string "could be ancient artefects hidden in the\l"
	.string "dirt.$"

FallarborWasteland_Text_ObserveMagmaF:
	.string "The soil is too poor for most plants.\n"
	.string "This place is very much a wasteland.\p"
	.string "These caverns cut into the land are\n"
	.string "promising though, it could expose some\l"
	.string "useful minerals.$"

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
