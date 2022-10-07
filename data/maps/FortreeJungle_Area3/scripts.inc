FortreeJungle_Area3_MapScripts::
	.byte 0

FortreeJungle_Area3_Eventscript_Matt::
	msgbox FortreeJungle_Area3_Text_Matt, MSGBOX_NPC
	call_if_unset FLAG_MET_MATT_FORTREE_JUNGLE, FortreeJungle_Area3_Eventscript_SetMeetFlag
	goto_if_unset FLAG_BIRCH_CALLED_PLAYER, Wildwoods_Area9_Eventscript_CheckForBirchReportCall
	end

FortreeJungle_Area3_Eventscript_SetMeetFlag::
	setflag FLAG_MET_MATT_FORTREE_JUNGLE
	addvar VAR_NEW_AREA_EXPLORE, 1
	return

FortreeJungle_Area3_Eventscript_AquaMemberF::
	msgbox FortreeJungle_Area3_Text_AquaMemberF, MSGBOX_NPC
	end

FortreeJungle_Area3_Eventscript_AquaMemberM::
	msgbox FortreeJungle_Area3_Text_AquaMemberM, MSGBOX_NPC
	end

FortreeJungle_Area3_Text_Matt:
	.string "Matt: Oh! Isn't that that kid I love?!\p"
	.string "Thanks to you, it looks like my bro and\n"
	.string "everyone else in Team Aqua now has real\l"
	.string "legit work that actually helps everyone!\p"
	.string "I just got done ripping through the\n"
	.string "trees. It was a good workout.\p"
	.string "My buddies are surveying the wildlife\n"
	.string "here. They seem pretty excited by what\l"
	.string "they found already.$"

FortreeJungle_Area3_Text_AquaMemberF:
	.string "Tropical forests are known to have a\n"
	.string "rich variety of species, and there is\l"
	.string "no exception here.\p"
	.string "Each area has different Pokémon to the\n"
	.string "previous area. Perhaps it depends on\l"
	.string "the amount of grass and water?$"

FortreeJungle_Area3_Text_AquaMemberM:
	.string "Some Pokémon seem to love this dense\n"
	.string "vegetation. For me, it feels cramped.\p"
	.string "I'm pretty sure I saw some of these\n"
	.string "plants move on their own as well…$"
