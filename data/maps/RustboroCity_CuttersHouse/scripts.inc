RustboroCity_CuttersHouse_MapScripts::
	.byte 0

RustboroCity_CuttersHouse_EventScript_Cutter::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM54, RustboroCity_CuttersHouse_EventScript_ExplainFalseSwipe
	msgbox RustboroCity_CuttersHouse_Text_IHaveJustWhatYouNeed, MSGBOX_DEFAULT
	giveitem ITEM_TM54
	setflag FLAG_RECEIVED_TM54
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_ExplainFalseSwipe::
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_Lass::
	msgbox RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees, MSGBOX_NPC
	end

RustboroCity_CuttersHouse_Text_IHaveJustWhatYouNeed:
	.string "That determined expression…\n"
	.string "That limber way you move…\l"
	.string "And your well-trained Pokémon…\p"
	.string "You're obviously a skilled Trainer!\p"
	.string "However, you appear to lack\n"
	.string "restraint…\p"
	.string "Any trainer worth his salt knows\n"
	.string "that there are times where they'll\l"
	.string "need to hold back so that they\l"
	.string "can catch new Pokémon.\p"
	.string "I have just what you need!\p"
	.string "No need to be modest or shy.\n"
	.string "Go on, take it!$"

RustboroCity_CuttersHouse_Text_ExplainCut:
	.string "That Technical Machine, or TM for\n"
	.string "short, is False Swipe.\p"
	.string "You can use it to teach a suitable\n"
	.string "Pokémon the False Swipe move.\p"
	.string "False Swipe is a safe cutting,\n"
	.string "technique, making it safer to\l"
	.string "weaken Pokémon for capture.$"

RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees:
	.string "When they were expanding the city of\n"
	.string "Rustboro, my dad helped out.\p"
	.string "He made his Pokémon cut down the\n"
	.string "land of trees.$"

