Wildwoods_Area9_MapScripts::
	.byte 0

Wildwoods_Area9_Eventscript_Courtney::
	msgbox Wildwoods_Area9_Text_Courtney, MSGBOX_NPC
	call_if_unset FLAG_MET_COURTNEY_WILDWOODS, Wildwoods_Area9_Eventscript_SetMeetFlag
	goto_if_unset FLAG_MET_TABITHA_FALLARBOR_WASTES, Wildwoods_Area9_Eventscript_CheckOutWasteland
	goto_if_unset FLAG_BIRCH_CALLED_PLAYER, Wildwoods_Area9_Eventscript_CheckForBirchReportCall
	end

Wildwoods_Area9_Eventscript_CheckOutWasteland::
	msgbox Wildwoods_Area9_Text_CourtneyCheckOutWastes, MSGBOX_NPC
	end

Wildwoods_Area9_Eventscript_SetMeetFlag::
	setflag FLAG_MET_COURTNEY_WILDWOODS
	addvar VAR_NEW_AREA_EXPLORE, 1
	return

Wildwoods_Area9_Eventscript_CheckForBirchReportCall::
	compare VAR_NEW_AREA_EXPLORE, 5
	goto_if_eq Wildwoods_Area9_Eventscript_SetBirchReportCall
	end

Wildwoods_Area9_Eventscript_SetBirchReportCall::
	setflag FLAG_BIRCH_CALL_NEW_AREAS_REPORT
	release
	end

Wildwoods_Area9_EventScript_BirchNewAreasCall::
	lockall
	pokenavcall Wildwoods_Area9_Text_BirchNewAreasCall
	waitmessage
	clearflag FLAG_BIRCH_CALL_NEW_AREAS_REPORT
	setflag FLAG_BIRCH_CALLED_PLAYER
	setvar VAR_BIRCH_LAB_POSTGAME_STATE, 4
	clearflag FLAG_HIDE_MAXIE_ARCHIE_BIRCH_LAB
	releaseall
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

Wildwoods_Area9_Text_CourtneyCheckOutWastes:
	.string "Data suggests that you, trainer, have\n"
	.string "not visited the wasteland located\l"
	.string "west of Fallarbor Town.\p"
	.string "I would recommend you produce your\n"
	.string "own analysis of the area.$"

Wildwoods_Area9_Text_StudyingEnviroment:
	.string "We're just here to study the strange\n"
	.string "environment.\p"
	.string "It's a little scary, but it's much more\n"
	.string "preferable to bullying the locals for\l"
	.string "technology or waking up dangerous\l"
	.string "legendary Pokémon.$"

Wildwoods_Area9_Text_MagmaM:
	.string "Every area in this forest has a unique\n"
	.string "distribution of Pokémon species.\p"
	.string "Some of the areas also have Pokémon\n"
	.string "that are not found in others.$"

Wildwoods_Area9_Text_BirchNewAreasCall:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "Prof. Birch: Hey {PLAYER}!\n"
	.string "How goes the expedition?\p"
	.string "We've made significant progress\n"
	.string "on the Pokémon in the new areas.\p"
	.string "When you have finished your trip\n"
	.string "could you come back to the lab?\l"
	.string "It would be great to compare our\l"
	.string "notes!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"
