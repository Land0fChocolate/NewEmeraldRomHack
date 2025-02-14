MauvilleMeadow_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleMeadow_OnTransition
	.byte 0

MauvilleMeadow_OnTransition:
	setflag FLAG_LANDMARK_MAUVILLE_MEADOW
	end

MauvilleMeadow_EventScript_Alistair::
	trainerbattle_single TRAINER_ALISTAIR, MauvilleMeadow_Text_AlistairIntro, MauvilleMeadow_Text_AlistairDefeat
	msgbox MauvilleMeadow_Text_AlistairPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleMeadow_EventScript_Natasha::
	trainerbattle_single TRAINER_NATASHA, MauvilleMeadow_Text_NatashaIntro, MauvilleMeadow_Text_NatashaDefeat
	msgbox MauvilleMeadow_Text_NatashaPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleMeadow_EventScript_Rita::
	trainerbattle_double TRAINER_RITA_AND_SAM, MauvilleMeadow_Text_RitaIntro, MauvilleMeadow_Text_RitaDefeat, MauvilleMeadow_Text_RitaNotEnoughMons
	msgbox MauvilleMeadow_Text_RitaPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleMeadow_EventScript_Sam::
	trainerbattle_double TRAINER_RITA_AND_SAM, MauvilleMeadow_Text_SamIntro, MauvilleMeadow_Text_SamDefeat, MauvilleMeadow_Text_SamNotEnoughMons
	msgbox MauvilleMeadow_Text_SamPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleMeadow_EventScript_Jace::
	trainerbattle_single TRAINER_JACE, MauvilleMeadow_Text_JaceIntro, MauvilleMeadow_Text_JaceDefeat
	msgbox MauvilleMeadow_Text_JacePostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleMeadow_EventScript_Cobain::
	trainerbattle_single TRAINER_COBAIN, MauvilleMeadow_Text_CobainIntro, MauvilleMeadow_Text_CobainDefeat
	msgbox MauvilleMeadow_Text_CobainPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleMeadow_Eventscript_Shelly::
	msgbox MauvilleMeadow_Text_Shelly, MSGBOX_NPC
	call_if_unset FLAG_MET_SHELLY_MAUVILLE_MEADOW, MauvilleMeadow_Eventscript_SetMeetFlag
	goto_if_unset FLAG_MET_MATT_FORTREE_JUNGLE, MauvilleMeadow_Eventscript_CheckOutJungle
	goto_if_unset FLAG_BIRCH_CALLED_PLAYER, Wildwoods_Area9_Eventscript_CheckForBirchReportCall
	end

MauvilleMeadow_Eventscript_CheckOutJungle::
	msgbox MauvilleMeadow_Text_ShellyCheckOutJungle, MSGBOX_NPC
	end

MauvilleMeadow_Eventscript_SetMeetFlag::
	setflag FLAG_MET_SHELLY_MAUVILLE_MEADOW
	addvar VAR_NEW_AREA_EXPLORE, 1
	return

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
	.string "Shelly: Team Aqua has taken a step in a\n"
	.string "new direction.\p"
	.string "We're helping the natural world\n"
	.string "propagate, though not at the expense\l"
	.string "of human society or others.\p"
	.string "Our mission here is to analyze the\n"
	.string "ecosystem of this newly discovered\l"
	.string "habitat.\p"
	.string "This area and its Pokémon are very\n"
	.string "interesting. We'll be here for a while.$"

MauvilleMeadow_Text_ShellyCheckOutJungle:
	.string "There's a dense jungle that was just\n"
	.string "discovered too, south of Fortree City.\p"
	.string "Matt is leading the discovery team for\n"
	.string "that area.\l"
	.string "You should go say hello to him, too.$"

MauvilleMeadow_Text_FlowerAqua:
	.string "Huh?!\p"
	.string "I'm not goofing off!\p"
	.string "I'm err… analyzing the flowers here.\n"
	.string "All botanist-like.\l"
	.string "Yeah!$"

MauvilleMeadow_Text_ObserveAquaM:
	.string "Those fissures in the land are a feature\n"
	.string "not seen anywhere else in Hoenn.\l"
	.string "I wonder what caused them?$"

MauvilleMeadow_Text_ObserveAquaF:
	.string "It's crazy that such an untouched place\n"
	.string "is located right near by Mauville.\p"
	.string "I guess there were no easy ways to get\n"
	.string "here before?$"

MauvilleMeadow_Text_WanderAqua:
	.string "A lot of our members quit after that\n"
	.string "Sootopolis fiasco.\p"
	.string "I don't blame 'em. We went too far and\n"
	.string "nearly wrecked everything.\p"
	.string "We have new ideals now, and we're even\n"
	.string "cooperating with Team Magma.$"
