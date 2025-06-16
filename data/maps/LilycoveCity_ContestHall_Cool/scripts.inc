LilycoveCity_ContestHall_Cool_MapScripts::
	.byte 0

LilycoveCity_ContestHall_Cool_EventScript_CoolStageSign::
	msgbox LilycoveCity_ContestHall_Cool_Text_CoolContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_Cool_EventScript_Lisia::
	msgbox LilycoveCity_ContestHall_Cool_Text_Lisia, MSGBOX_NPC
	applymovement VAR_LAST_TALKED, Common_Movement_FaceDown
	end

LilycoveCity_ContestHall_Cool_EventScript_Camper::
	msgbox LilycoveCity_ContestHall_Cool_Text_Camper, MSGBOX_NPC
	end

LilycoveCity_ContestHall_Cool_EventScript_Girl::
	msgbox LilycoveCity_ContestHall_Cool_Text_Girl, MSGBOX_NPC
	end

LilycoveCity_ContestHall_Cool_EventScript_Boy2::
	msgbox LilycoveCity_ContestHall_Cool_Text_EnteredBunchOfContests, MSGBOX_NPC
	end

LilycoveCity_ContestHall_Cool_Text_CoolContestStage:
	.string "COOL CONTEST STAGE\n"
	.string "BE AWED BY STYLISH POKéMON!$"

LilycoveCity_ContestHall_Cool_Text_Camper:
	.string "Increasing a Pokémon's condition in\n"
	.string "a particular stat helps it perform\l"
	.string "better in the first round for that\l"
	.string "respective contest.\p"
	.string "Increasing its neighbouring condition\n"
	.string "stats also gets marks, though not as\l"
	.string "much.\p"
	.string "So for a Cool contest Pokémon,\n"
	.string "I should prioritize increasing the\l"
	.string "Cool condition, whilst also trying to\l"
	.string "increase Beauty and Tough.$"

LilycoveCity_ContestHall_Cool_Text_Girl:
	.string "I only entered contests so I could\n"
	.string "meet Lisia.\p"
	.string "But I quickly found out that I really\n"
	.string "like contests, and I'm good at them!$"

LilycoveCity_ContestHall_Cool_Text_Lisia:
	.string "Lisia: Hiiiiii, trainer!\n"
	.string "You're that trainer I just scouted,\l"
	.string "{PLAYER}, right?\p"
	.string "If you enter a master rank contest,\n"
	.string "there's a chance you'll get to face\l"
	.string "off against me.\l"
	.string "Good luck, {PLAYER}!$"

LilycoveCity_ContestHall_Cool_Text_EnteredBunchOfContests:
	.string "I've entered a bunch of Contests,\n"
	.string "so I'm seeing how things work.\p"
	.string "If you're in a Coolness Contest,\n"
	.string "cool moves go over as appeals.\p"
	.string "But smart moves and cute moves\n"
	.string "don't go over well, for instance.$"
