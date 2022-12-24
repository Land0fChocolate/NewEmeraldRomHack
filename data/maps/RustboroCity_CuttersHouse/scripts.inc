RustboroCity_CuttersHouse_MapScripts::
	.byte 0

RustboroCity_CuttersHouse_EventScript_Cutter::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM64, RustboroCity_CuttersHouse_EventScript_ExplainFalseSwipe
	msgbox RustboroCity_CuttersHouse_Text_IHaveJustWhatYouNeed, MSGBOX_DEFAULT
	giveitem ITEM_TM64
	setflag FLAG_RECEIVED_TM64
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
	.string "No, wait, don't say a word.\n"
	.string "I can tell just by looking at you.\p"
	.string "I'm sure that you can put this\n"
	.string "Technical Machine to good use.\p"
	.string "No need to be modest or shy.\n"
	.string "Go on, take it!$"

RustboroCity_CuttersHouse_Text_ExplainCut:
	.string "That Technical Machine, or TM for\n"
	.string "short, is Cut.\p"
	.string "You can use it to teach a suitable\n"
	.string "Pokémon the Cut move.\p"
	.string "Cut always critically strikes, meaning\n"
	.string "it deals 50% bonus damage and ignores\l"
	.string "the opponent's defense boosts.$"

RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees:
	.string "When they were expanding the city of\n"
	.string "Rustboro, my dad helped out.\p"
	.string "He made his Pokémon cut down the\n"
	.string "land of trees.$"

