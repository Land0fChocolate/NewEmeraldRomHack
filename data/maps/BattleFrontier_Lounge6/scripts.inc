BattleFrontier_Lounge6_MapScripts::
	.byte 0

BattleFrontier_Lounge6_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_BATTLE_FRONTIER_TRADE_DONE, BattleFrontier_Lounge6_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_HAPPINY
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox BattleFrontier_Lounge6_Text_WouldYouLikeToTrade, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge6_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	compare VAR_0x8004, 255
	goto_if_eq BattleFrontier_Lounge6_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	compare VAR_RESULT, VAR_0x8009
	goto_if_ne BattleFrontier_Lounge6_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt, MSGBOX_DEFAULT
	setflag FLAG_BATTLE_FRONTIER_TRADE_DONE
	release
	end

BattleFrontier_Lounge6_EventScript_DeclineTrade::
	msgbox BattleFrontier_Lounge6_Text_WellThatsFineToo, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_NotRequestedMon::
	bufferspeciesname 0, VAR_0x8009
	msgbox BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_TradeCompleted::
	msgbox BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_Psychic::
	lock
	faceplayer
	goto_if_set FLAG_GAVE_AWAY_GALARIAN_ARTICUNO, BattleFrontier_Lounge6_EventScript_PsychicGiveAwayCompleted
	msgbox BattleFrontier_Lounge6_Text_WouldLikeToSeeOriginalArticuno, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge6_EventScript_PsychicDeclineShowArticuno
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	compare VAR_RESULT, 255
	goto_if_eq BattleFrontier_Lounge6_EventScript_PsychicDeclineShowArticuno
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_ARTICUNO_GALARIAN
	goto_if_eq BattleFrontier_Lounge6_EventScript_PsychicAlreadySeenGalarian
	compare VAR_RESULT, SPECIES_ARTICUNO
	goto_if_ne BattleFrontier_Lounge6_EventScript_PsychicNotArticuno
BattleFrontier_Lounge6_EventScript_PsychicSeeArticuno::
	msgbox BattleFrontier_Lounge6_Text_PsychicHaveGalarianArticuno, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, SPECIES_ARTICUNO_GALARIAN
	givemon SPECIES_ARTICUNO_GALARIAN, 50, ITEM_NONE
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_Lounge6_EventScript_SendGalarianArticunoToParty
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_Lounge6_EventScript_SendGalarianArticunoToPC
	goto Common_EventScript_NoMoreRoomForPokemon
	release
	end

BattleFrontier_Lounge6_EventScript_PsychicDeclineShowArticuno::
	msgbox BattleFrontier_Lounge6_Text_PsychicDeclineShowArticuno, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_PsychicAlreadySeenGalarian::
	msgbox BattleFrontier_Lounge6_Text_PsychicAlreadySeenGalarian, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_PsychicNotArticuno::
	msgbox BattleFrontier_Lounge6_Text_PsychicThatsNotArticuno, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_SendGalarianArticunoToParty::
	call BattleFrontier_Lounge6_EventScript_ReceivedGalarianArticuno
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge6_EventScript_FinishGiftGalarianArticuno
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto BattleFrontier_Lounge6_EventScript_FinishGiftGalarianArticuno
	end

BattleFrontier_Lounge6_EventScript_SendGalarianArticunoToPC::
	call BattleFrontier_Lounge6_EventScript_ReceivedGalarianArticuno
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge6_EventScript_GalarianArticunoTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto BattleFrontier_Lounge6_EventScript_GalarianArticunoTransferredToPC
	end

BattleFrontier_Lounge6_EventScript_GalarianArticunoTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto BattleFrontier_Lounge6_EventScript_FinishGiftGalarianArticuno
	end

BattleFrontier_Lounge6_EventScript_FinishGiftGalarianArticuno::
	msgbox BattleFrontier_Lounge6_Text_PsychicTakeGoodCareOfIt, MSGBOX_DEFAULT
	setflag FLAG_GAVE_AWAY_GALARIAN_ARTICUNO
	releaseall
	end

BattleFrontier_Lounge6_EventScript_ReceivedGalarianArticuno::
	playfanfare MUS_OBTAIN_ITEM
	message BattleFrontier_Lounge6_Text_ReceivedGalarianArticuno
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_ARTICUNO_GALARIAN
	return

BattleFrontier_Lounge6_EventScript_PsychicGiveAwayCompleted::
	msgbox BattleFrontier_Lounge6_Text_ThanksForSeeingOriginalArticuno, MSGBOX_DEFAULT
	closemessage
	end

BattleFrontier_Lounge6_EventScript_BlackBelt::
	lock
	faceplayer
	goto_if_set FLAG_GAVE_AWAY_GALARIAN_ZAPDOS, BattleFrontier_Lounge6_EventScript_BlackBeltGiveAwayCompleted
	msgbox BattleFrontier_Lounge6_Text_WouldLikeToSeeOriginalZapdos, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge6_EventScript_BlackBeltDeclineShowZapdos
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	compare VAR_RESULT, 255
	goto_if_eq BattleFrontier_Lounge6_EventScript_BlackBeltDeclineShowZapdos
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_ZAPDOS_GALARIAN
	goto_if_eq BattleFrontier_Lounge6_EventScript_BlackBeltAlreadySeenGalarian
	compare VAR_RESULT, SPECIES_ZAPDOS
	goto_if_ne BattleFrontier_Lounge6_EventScript_BlackBeltNotZapdos
BattleFrontier_Lounge6_EventScript_BlackBeltSeeZapdos::
	msgbox BattleFrontier_Lounge6_Text_BlackBeltHaveGalarianZapdos, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, SPECIES_ZAPDOS_GALARIAN
	givemon SPECIES_ZAPDOS_GALARIAN, 50, ITEM_NONE
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_Lounge6_EventScript_SendGalarianZapdosToParty
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_Lounge6_EventScript_SendGalarianZapdosToPC
	goto Common_EventScript_NoMoreRoomForPokemon
	release
	end

BattleFrontier_Lounge6_EventScript_BlackBeltDeclineShowZapdos::
	msgbox BattleFrontier_Lounge6_Text_BlackBeltDeclineShowZapdos, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_BlackBeltAlreadySeenGalarian::
	msgbox BattleFrontier_Lounge6_Text_BlackBeltAlreadySeenGalarian, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_BlackBeltNotZapdos::
	msgbox BattleFrontier_Lounge6_Text_BlackBeltThatsNotZapdos, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_SendGalarianZapdosToParty::
	call BattleFrontier_Lounge6_EventScript_ReceivedGalarianZapdos
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge6_EventScript_FinishGiftGalarianZapdos
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto BattleFrontier_Lounge6_EventScript_FinishGiftGalarianZapdos
	end

BattleFrontier_Lounge6_EventScript_SendGalarianZapdosToPC::
	call BattleFrontier_Lounge6_EventScript_ReceivedGalarianZapdos
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge6_EventScript_GalarianZapdosTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto BattleFrontier_Lounge6_EventScript_GalarianZapdosTransferredToPC
	end

BattleFrontier_Lounge6_EventScript_GalarianZapdosTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto BattleFrontier_Lounge6_EventScript_FinishGiftGalarianZapdos
	end

BattleFrontier_Lounge6_EventScript_FinishGiftGalarianZapdos::
	msgbox BattleFrontier_Lounge6_Text_BlackBeltTakeGoodCareOfIt, MSGBOX_DEFAULT
	setflag FLAG_GAVE_AWAY_GALARIAN_ZAPDOS
	releaseall
	end

BattleFrontier_Lounge6_EventScript_ReceivedGalarianZapdos::
	playfanfare MUS_OBTAIN_ITEM
	message BattleFrontier_Lounge6_Text_ReceivedGalarianZapdos
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_ZAPDOS_GALARIAN
	return

BattleFrontier_Lounge6_EventScript_BlackBeltGiveAwayCompleted::
	msgbox BattleFrontier_Lounge6_Text_ThanksForSeeingOriginalZapdos, MSGBOX_DEFAULT
	closemessage
	end

BattleFrontier_Lounge6_EventScript_StreetThug::
	lock
	faceplayer
	goto_if_set FLAG_GAVE_AWAY_GALARIAN_MOLTRES, BattleFrontier_Lounge6_EventScript_StreetThugGiveAwayCompleted
	msgbox BattleFrontier_Lounge6_Text_WouldLikeToSeeOriginalMoltres, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge6_EventScript_StreetThugDeclineShowMoltres
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	compare VAR_RESULT, 255
	goto_if_eq BattleFrontier_Lounge6_EventScript_StreetThugDeclineShowMoltres
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_MOLTRES_GALARIAN
	goto_if_eq BattleFrontier_Lounge6_EventScript_StreetThugAlreadySeenGalarian
	compare VAR_RESULT, SPECIES_MOLTRES
	goto_if_ne BattleFrontier_Lounge6_EventScript_StreetThugNotMoltres
BattleFrontier_Lounge6_EventScript_StreetThugSeeMoltres::
	msgbox BattleFrontier_Lounge6_Text_StreetThugHaveGalarianMoltres, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, SPECIES_MOLTRES_GALARIAN
	givemon SPECIES_MOLTRES_GALARIAN, 50, ITEM_NONE
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_Lounge6_EventScript_SendGalarianMoltresToParty
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_Lounge6_EventScript_SendGalarianMoltresToPC
	goto Common_EventScript_NoMoreRoomForPokemon
	release
	end

BattleFrontier_Lounge6_EventScript_StreetThugDeclineShowMoltres::
	msgbox BattleFrontier_Lounge6_Text_StreetThugDeclineShowMoltres, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_StreetThugAlreadySeenGalarian::
	msgbox BattleFrontier_Lounge6_Text_StreetThugAlreadySeenGalarian, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_StreetThugNotMoltres::
	msgbox BattleFrontier_Lounge6_Text_StreetThugThatsNotMoltres, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_SendGalarianMoltresToParty::
	call BattleFrontier_Lounge6_EventScript_ReceivedGalarianMoltres
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge6_EventScript_FinishGiftGalarianMoltres
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto BattleFrontier_Lounge6_EventScript_FinishGiftGalarianMoltres
	end

BattleFrontier_Lounge6_EventScript_SendGalarianMoltresToPC::
	call BattleFrontier_Lounge6_EventScript_ReceivedGalarianMoltres
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge6_EventScript_GalarianMoltresTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto BattleFrontier_Lounge6_EventScript_GalarianMoltresTransferredToPC
	end

BattleFrontier_Lounge6_EventScript_GalarianMoltresTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto BattleFrontier_Lounge6_EventScript_FinishGiftGalarianMoltres
	end

BattleFrontier_Lounge6_EventScript_FinishGiftGalarianMoltres::
	msgbox BattleFrontier_Lounge6_Text_StreetThugTakeGoodCareOfIt, MSGBOX_DEFAULT
	setflag FLAG_GAVE_AWAY_GALARIAN_MOLTRES
	releaseall
	end

BattleFrontier_Lounge6_EventScript_ReceivedGalarianMoltres::
	playfanfare MUS_OBTAIN_ITEM
	message BattleFrontier_Lounge6_Text_ReceivedGalarianMoltres
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_MOLTRES_GALARIAN
	return

BattleFrontier_Lounge6_EventScript_StreetThugGiveAwayCompleted::
	msgbox BattleFrontier_Lounge6_Text_ThanksForSeeingOriginalMoltres, MSGBOX_DEFAULT
	closemessage
	end

BattleFrontier_Lounge6_Text_ReceivedGalarianArticuno:
	.string "{PLAYER} received\n"
	.string "Galarian Articuno!$"

BattleFrontier_Lounge6_Text_ReceivedGalarianZapdos:
	.string "{PLAYER} received\n"
	.string "Galarian Zapdos!$"

BattleFrontier_Lounge6_Text_ReceivedGalarianMoltres:
	.string "{PLAYER} received\n"
	.string "Galarian Moltres!$"

BattleFrontier_Lounge6_Text_WouldLikeToSeeOriginalArticuno:
	.string "I travel with my Articuno everywhere,\n"
	.string "but I heard that my Articuno is way\l"
	.string "different to the Articuno around this\l"
	.string "part of the world.\p"
	.string "I want to see one from here.\n"
	.string "You got an Articuno?$"

BattleFrontier_Lounge6_Text_PsychicDeclineShowArticuno:
	.string "Yeah, not many people have even\n"
	.string "seen one.$"

BattleFrontier_Lounge6_Text_PsychicAlreadySeenGalarian:
	.string "That's the kind of Articuno I have.\n"
	.string "You don't have the different kind?$"

BattleFrontier_Lounge6_Text_PsychicThatsNotArticuno:
	.string "That's one weird Articuno you have\n"
	.string "there, mate.$"

BattleFrontier_Lounge6_Text_PsychicHaveGalarianArticuno:
	.string "Yeah, that's an Articuno, alright.\n"
	.string "Real pretty, that one is.\p"
	.string "Thanks for showing me.\n"
	.string "Here, take one of my own.$"

BattleFrontier_Lounge6_Text_PsychicTakeGoodCareOfIt:
	.string "It has a mean streak, but if you can\n"
	.string "manage the icy Articuno then you can\l"
	.string "manage this one.$"

BattleFrontier_Lounge6_Text_ThanksForSeeingOriginalArticuno:
	.string "Thanks for showing me that Articuno.\n"
	.string "Me and my mates are going to hang\l"
	.string "around here.$"

BattleFrontier_Lounge6_Text_WouldLikeToSeeOriginalZapdos:
	.string "Me and Zapdos don't skip leg day.\n"
	.string "My boy is able to kick down walls!\p"
	.string "Apparently, the Zapdos here are a\n"
	.string "different kind than what I got.\p"
	.string "You see any Zapdos, kid?$"

BattleFrontier_Lounge6_Text_BlackBeltDeclineShowZapdos:
	.string "Yeah, I guess they're pretty rare.$"

BattleFrontier_Lounge6_Text_BlackBeltAlreadySeenGalarian:
	.string "Huh, Zapdos are actually the\n"
	.string "same here? Lame.$"

BattleFrontier_Lounge6_Text_BlackBeltThatsNotZapdos:
	.string "I said a Zapdos, you dunce.$"

BattleFrontier_Lounge6_Text_BlackBeltHaveGalarianZapdos:
	.string "Woah, what a strange Zapdos.\p"
	.string "It uses electricity and not kicking\n"
	.string "to attack.\l"
	.string "How weird is that?\p"
	.string "Cheers, mate. For showing me it.\n"
	.string "Here, have a fighting Zapdos on me.$"

BattleFrontier_Lounge6_Text_BlackBeltTakeGoodCareOfIt:
	.string "Take good care of my boy, now.$"

BattleFrontier_Lounge6_Text_ThanksForSeeingOriginalZapdos:
	.string "Us guys are from Galar.\n"
	.string "We're on holiday.\p"
	.string "I wonder if they got any good\n"
	.string "curry here.$"

BattleFrontier_Lounge6_Text_WouldLikeToSeeOriginalMoltres:
	.string "I'm pounding all the deadbeats here\n"
	.string "with my Moltres!\p"
	.string "Though people say my Moltres looks\n"
	.string "funny. Like, not fiery enough.\p"
	.string "What other kind of Moltres could\n"
	.string "there be?\p"
	.string "You got a Moltres?$"

BattleFrontier_Lounge6_Text_StreetThugDeclineShowMoltres:
	.string "Eh, figures.$"

BattleFrontier_Lounge6_Text_StreetThugAlreadySeenGalarian:
	.string "Looks just like mine.\n"
	.string "What do people have against my\l"
	.string "Moltres?$"

BattleFrontier_Lounge6_Text_StreetThugThatsNotMoltres:
	.string "You think you're funny, mate?$"

BattleFrontier_Lounge6_Text_StreetThugHaveGalarianMoltres:
	.string "So there are different kinds of\n"
	.string "Moltres. That's interesting.\p"
	.string "I might try catching one of the\n"
	.string "variants around here.\p"
	.string "Take my spare Moltres from Galar.\n"
	.string "It could do with a good home.$"

BattleFrontier_Lounge6_Text_StreetThugTakeGoodCareOfIt:
	.string "You seem like a strong trainer,\n"
	.string "I reckon both your Moltres now are\l"
	.string "in good hands.$"

BattleFrontier_Lounge6_Text_ThanksForSeeingOriginalMoltres:
	.string "Me and the boys are going to wipe\n"
	.string "some goons at the Battle Tower and\l"
	.string "then go find a pub.$"

BattleFrontier_Lounge6_Text_WouldYouLikeToTrade:
	.string "My Pokémon is a {STR_VAR_2}.\n"
	.string "Do you know it?\l"
	.string "It's quite cute and rather nice.\p"
	.string "This little one, I could trade with\n"
	.string "pride!\p"
	.string "Would you like to trade me a {STR_VAR_1}\n"
	.string "for my {STR_VAR_2}?$"

BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt:
	.string "Oh, it's adorable!\n"
	.string "Thank you!\l"
	.string "I promise I'll be good to it!\p"
	.string "Oh! I hope you'll be good to\n"
	.string "my {STR_VAR_2}, too!$"

BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon:
	.string "Oh, I'm sorry!\n"
	.string "I don't intend to trade for anything\l"
	.string "but a {STR_VAR_1}.$"

BattleFrontier_Lounge6_Text_WellThatsFineToo:
	.string "Oh, you won't?\n"
	.string "Well, that's fine, too.\l"
	.string "Please come visit us again.$"

BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined:
	.string "Giggle!\n"
	.string "A Skitty is so much cuter than I had\l"
	.string "imagined. I'm delighted!$"
