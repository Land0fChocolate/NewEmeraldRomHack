FallarborWasteland_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborWasteland_OnTransition
	.byte 0

FallarborWasteland_OnTransition:
	setflag FLAG_LANDMARK_FALLARBOR_WASTELAND
	end

FallarborWasteland_EventScript_Kat::
	trainerbattle_double TRAINER_KAT_AND_ASHE, FallarborWasteland_Text_KatIntro, FallarborWasteland_Text_KatDefeat, FallarborWasteland_Text_KatNotEnoughMons
	msgbox FallarborWasteland_Text_KatPostBattle, MSGBOX_AUTOCLOSE
	end

FallarborWasteland_EventScript_Ashe::
	trainerbattle_double TRAINER_KAT_AND_ASHE, FallarborWasteland_Text_AsheIntro, FallarborWasteland_Text_AsheDefeat, FallarborWasteland_Text_AsheNotEnoughMons
	msgbox FallarborWasteland_Text_AshePostBattle, MSGBOX_AUTOCLOSE
	end

FallarborWasteland_EventScript_Geordi::
	trainerbattle_single TRAINER_GEORDI, FallarborWasteland_Text_GeordiIntro, FallarborWasteland_Text_GeordiDefeat
	msgbox FallarborWasteland_Text_GeordiPostBattle, MSGBOX_AUTOCLOSE
	end

FallarborWasteland_EventScript_Hayden::
	trainerbattle_single TRAINER_HAYDEN, FallarborWasteland_Text_HaydenIntro, FallarborWasteland_Text_HaydenDefeat
	msgbox FallarborWasteland_Text_HaydenPostBattle, MSGBOX_AUTOCLOSE
	end

FallarborWasteland_EventScript_Darius::
	trainerbattle_single TRAINER_DARIUS, FallarborWasteland_Text_DariusIntro, FallarborWasteland_Text_DariusDefeat
	msgbox FallarborWasteland_Text_DariusPostBattle, MSGBOX_AUTOCLOSE
	end

FallarborWasteland_EventScript_Ripley::
	trainerbattle_single TRAINER_RIPLEY, FallarborWasteland_Text_RipleyIntro, FallarborWasteland_Text_RipleyDefeat
	msgbox FallarborWasteland_Text_RipleyPostBattle, MSGBOX_AUTOCLOSE
	end

FallarborWasteland_Eventscript_Tabitha::
	msgbox FallarborWasteland_Text_TabithaFieldWork, MSGBOX_NPC
	call_if_unset FLAG_MET_TABITHA_FALLARBOR_WASTES, FallarborWasteland_Eventscript_SetMeetFlag
	goto_if_unset FLAG_MET_COURTNEY_WILDWOODS, FallarborWasteland_Eventscript_CheckOutWildwoods
	goto_if_unset FLAG_BIRCH_CALLED_PLAYER, Wildwoods_Area9_Eventscript_CheckForBirchReportCall
	end

FallarborWasteland_Eventscript_CheckOutWildwoods::
	msgbox FallarborWasteland_Text_TabithaCheckOutWildWoods, MSGBOX_NPC
	end

FallarborWasteland_Eventscript_SetMeetFlag::
	setflag FLAG_MET_TABITHA_FALLARBOR_WASTES
	addvar VAR_NEW_AREA_EXPLORE, 1
	return

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

FallarborWasteland_Text_TabithaCheckOutWildWoods:
	.string "Courtney, our other admin is\n"
	.string "investigating the Wildwoods just north\l"
	.string "of Oldale Town.\p"
	.string "You should go find her and see how\n"
	.string "she's doing.$"

FallarborWasteland_Text_BridgeMagma:
	.string "I was told that this area was recently\n"
	.string "discovered.\p"
	.string "If that's the case, how did this bridge\n"
	.string "get here then?$"

FallarborWasteland_Text_ObserveMagmaF:
	.string "The soil is too poor for most plants.\n"
	.string "This biome is very much a wasteland.\p"
	.string "These canyons cut into the land are\n"
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
