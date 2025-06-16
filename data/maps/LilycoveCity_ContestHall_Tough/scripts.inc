LilycoveCity_ContestHall_Tough_MapScripts::
	.byte 0

LilycoveCity_ContestHall_Tough_EventScript_ToughStageSign::
	msgbox LilycoveCity_ContestHall_Tough_Text_ToughContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_Tough_EventScript_Girl::
	msgbox LilycoveCity_ContestHall_Tough_Text_ManWhoWonEarlierHadPokeblocks, MSGBOX_NPC
	end

LilycoveCity_ContestHall_Tough_EventScript_BugCatcher::
	msgbox LilycoveCity_ContestHall_Tough_Text_BugCatcher, MSGBOX_NPC
	end

LilycoveCity_ContestHall_Tough_EventScript_Triathlete::
	msgbox LilycoveCity_ContestHall_Tough_Text_Triathlete, MSGBOX_NPC
	end

LilycoveCity_ContestHall_Tough_Text_ToughContestStage:
	.string "TOUGH CONTEST STAGE\n"
	.string "WITNESS THE MIGHT OF TOUGH POKéMON!$"

LilycoveCity_ContestHall_Tough_Text_ManWhoWonEarlierHadPokeblocks:
	.string "That young man who won earlier had\n"
	.string "a whole bunch of different {POKEBLOCK}S.\p"
	.string "Can you win if you had that many\n"
	.string "of those things?$"

LilycoveCity_ContestHall_Tough_Text_BugCatcher:
	.string "A good way to win contests is to\n"
	.string "use moves that combo into other moves\l"
	.string "for bonus points.$"

LilycoveCity_ContestHall_Tough_Text_Triathlete:
	.string "I wonder when the next Toughness\n"
	.string "contest will be.\l"
	.string "Is there a schedule board somewhere?$"
