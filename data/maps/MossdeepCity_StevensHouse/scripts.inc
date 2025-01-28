.set LOCALID_STEVEN, 1
.set LOCALID_BELDUM_BALL, 2

MossdeepCity_StevensHouse_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_StevensHouse_OnLoad
	.byte 0

MossdeepCity_StevensHouse_OnLoad:
	call_if_unset FLAG_SYS_GAME_CLEAR, MossdeepCity_StevensHouse_EventScript_HideStevensNote
	end

MossdeepCity_StevensHouse_EventScript_HideStevensNote::
	setmetatile 6, 4, METATILE_GenericBuilding_TableEdge, 1
	return

MossdeepCity_StevensHouse_EventScript_BeldumPokeball::
	lockall
	msgbox MossdeepCity_StevensHouse_Text_TakeBallContainingBeldum, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MossdeepCity_StevensHouse_EventScript_LeaveBeldum
	goto MossdeepCity_StevensHouse_EventScript_GiveBeldum
	end

MossdeepCity_StevensHouse_EventScript_LeaveBeldum::
	msgbox MossdeepCity_StevensHouse_Text_LeftPokeBallWhereItWas, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_StevensHouse_EventScript_GiveBeldum::
	setvar VAR_TEMP_1, SPECIES_BELDUM
	givemon SPECIES_BELDUM, 5, ITEM_NONE
	compare VAR_RESULT, 0
	goto_if_eq MossdeepCity_StevensHouse_EventScript_SendBeldumParty
	compare VAR_RESULT, 1
	goto_if_eq MossdeepCity_StevensHouse_EventScript_SendBeldumPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

MossdeepCity_StevensHouse_EventScript_SendBeldumParty::
	call MossdeepCity_StevensHouse_EventScript_ReceivedBeldumFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MossdeepCity_StevensHouse_EventScript_ReceivedBeldum
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto MossdeepCity_StevensHouse_EventScript_ReceivedBeldum
	end

MossdeepCity_StevensHouse_EventScript_SendBeldumPC::
	call MossdeepCity_StevensHouse_EventScript_ReceivedBeldumFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MossdeepCity_StevensHouse_EventScript_BeldumTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto MossdeepCity_StevensHouse_EventScript_BeldumTransferredToPC
	end

MossdeepCity_StevensHouse_EventScript_BeldumTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto MossdeepCity_StevensHouse_EventScript_ReceivedBeldum
	end

MossdeepCity_StevensHouse_EventScript_ReceivedBeldumFanfare::
	bufferspeciesname 1, SPECIES_BELDUM
	removeobject LOCALID_BELDUM_BALL
	playfanfare MUS_OBTAIN_ITEM
	message MossdeepCity_StevensHouse_Text_ObtainedBeldum
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_BELDUM
	return

MossdeepCity_StevensHouse_EventScript_ReceivedBeldum::
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_BELDUM_POKEBALL
	setflag FLAG_RECEIVED_BELDUM
	releaseall
	end

MossdeepCity_StevensHouse_EventScript_RockDisplay::
	msgbox MossdeepCity_StevensHouse_Text_CollectionOfRareRocks, MSGBOX_SIGN
	end

MossdeepCity_StevensHouse_EventScript_Steven::
	lockall
	faceplayer
	checkflag FLAG_MOSSDEEP_CITY_STEVEN
	goto_if FALSE, MossdeepCity_StevensHouse_EventScript_StevenGreetingPlayer
	msgbox MossdeepCity_StevensHouse_Text_UnderwateCavernBetweenMossdeepSootopolis, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

MossdeepCity_StevensHouse_EventScript_StevenGreetingPlayer::
	setflag FLAG_MOSSDEEP_CITY_STEVEN
	msgbox MossdeepCity_StevensHouse_Text_GreetingPlayer, MSGBOX_DEFAULT
	giveitem ITEM_TM91
	setflag FLAG_RECEIVED_TM91
	releaseall
	end

MossdeepCity_StevensHouse_EventScript_Letter::
	lockall
	msgbox MossdeepCity_StevensHouse_Text_LetterFromSteven, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_StevensHouse_Text_GreetingPlayer:
	.string "Steven: Greetings, {PLAYER}{KUN}.\p"
	.string "As you can see, there's not much here,\n"
	.string "but this is my home.\p"
	.string "Thank you for all that you've done\n"
	.string "in helping the people of Hoenn.\p"
	.string "This is my token of appreciation.\n"
	.string "It's Technical Machine number 91:\l"
	.string "Flash Cannon.\p"
	.string "No need to be shy--you've earned\n"
	.string "this TM.$"

MossdeepCity_StevensHouse_Text_UnderwateCavernBetweenMossdeepSootopolis:
	.string "Steven: Apparently, there's an\n"
	.string "underwater cavern between\l"
	.string "Mossdeep and Sootopolis.\p"
	.string "You know, the one that Capt. Stern\n"
	.string "found in his submarine.\p"
	.string "I may pay a visit to check out the\n"
	.string "minerals it may have there.$"

MossdeepCity_StevensHouse_Text_TakeBallContainingBeldum:
	.string "{PLAYER} checked the Poké Ball.\p"
	.string "It contained the Pokémon\n"
	.string "Beldum.\p"
	.string "Take the Poké Ball?$"

MossdeepCity_StevensHouse_Text_ObtainedBeldum:
	.string "{PLAYER} obtained a Beldum.$"

@ Unused
MossdeepCity_StevensHouse_Text_NoSpaceForAnotherMon:
	.string "There is no space for another Pokémon.$"

MossdeepCity_StevensHouse_Text_LeftPokeBallWhereItWas:
	.string "{PLAYER} left the Poké Ball where\n"
	.string "it was.$"

MossdeepCity_StevensHouse_Text_LetterFromSteven:
	.string "It's a letter.\p"
	.string "… … … … … …\p"
	.string "To {PLAYER}{KUN}…\p"
	.string "I've decided to do a little soul-\n"
	.string "searching and train on the road.\p"
	.string "I don't plan to return home for some\n"
	.string "time.\p"
	.string "I have a favor to ask of you.\p"
	.string "I want you to take the Poké Ball on\n"
	.string "the desk.\p"
	.string "Inside it is a Beldum, one of my\n"
	.string "favorite Pokémon.\p"
	.string "I'm counting on you.\p"
	.string "May our paths cross again someday.\p"
	.string "Steven Stone$"

MossdeepCity_StevensHouse_Text_CollectionOfRareRocks:
	.string "It's a collection of rare rocks and\n"
	.string "stones assembled by Steven.$"

