PetalburgCity_WallysHouse_MapScripts::
	.byte 0

PetalburgCity_WallysHouse_EventScript_GiveTM55::
	lockall
	msgbox PetalburgCity_WallysHouse_Text_PleaseExcuseUs, MSGBOX_DEFAULT
	giveitem ITEM_TM55
	setflag FLAG_RECEIVED_TM55
	msgbox PetalburgCity_WallysHouse_Text_FathersBadgeTravel, MSGBOX_DEFAULT
	setvar VAR_PETALBURG_CITY_STATE, 5
	releaseall
	end

PetalburgCity_WallysHouse_EventScript_WallysDad::
	lock
	faceplayer
	goto_if_set FLAG_BADGE05_GET, PetalburgCity_WallysHouse_EventScript_WallysDadGiveTMCheck
PetalburgCity_WallysHouse_EventScript_WallysDadPart2::
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad
	goto_if_set FLAG_RECEIVED_TM55, PetalburgCity_WallysHouse_EventScript_ReceievedTM55Scald
	goto_if_set FLAG_THANKED_FOR_PLAYING_WITH_WALLY, PetalburgCity_WallysHouse_EventScript_PlayedWithWally
	msgbox PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally, MSGBOX_DEFAULT
	setflag FLAG_THANKED_FOR_PLAYING_WITH_WALLY
	release
	end

PetalburgCity_WallysHouse_EventScript_WallysDadGiveTMCheck::
	goto_if_unset FLAG_RECEIVED_TM55, PetalburgCity_WallysHouse_EventScript_GiveTM55
	goto PetalburgCity_WallysHouse_EventScript_WallysDadPart2
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceievedTM55Scald::
	msgbox PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad::
	msgbox PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_PlayedWithWally::
	msgbox PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_WallysMom::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM55, PetalburgCity_WallysHouse_EventScript_ReceivedTM55Surf
	msgbox PetalburgCity_WallysHouse_Text_WallyWasReallyHappy, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceivedTM55Surf::
	msgbox PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally:
	.string "You're…\n"
	.string "Ah, you must be {PLAYER}{KUN}, right?\p"
	.string "Thank you for playing with Wally a\n"
	.string "little while ago.\p"
	.string "He's been frail and sickly ever\n"
	.string "since he was a baby.\p"
	.string "We've sent him to stay with my relatives\n"
	.string "in Verdanturf Town for a while.\p"
	.string "The air is a lot cleaner there\n"
	.string "than it is here.\p"
	.string "What's that? Where's Wally?\n"
	.string "He's already left, our Wally.\p"
	.string "I wonder where he could have\n"
	.string "gotten by now?$"

PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing:
	.string "I wonder how our Wally is doing?$"

PetalburgCity_WallysHouse_Text_PleaseExcuseUs:
	.string "{PLAYER}{KUN}! Welcome!\p"
	.string "Our Wally's become very healthy\n"
	.string "since he went to Verdanturf Town.\p"
	.string "We owe it all to you!\p"
	.string "When Wally left town, you helped\n"
	.string "him catch a Pokémon, right?\p"
	.string "I think that made Wally really\n"
	.string "happy.\p"
	.string "Actually, not just Wally.\n"
	.string "It made me, his father, happy too.\p"
	.string "Happy that he's gained such a great\n"
	.string "friend as you.\p"
	.string "This isn't a bribe or anything, but\n"
	.string "I'd really like you to have this.$"

PetalburgCity_WallysHouse_Text_FathersBadgeTravel:
	.string "I see you have your father's Badge.\n"
	.string "You will be able to travel across the\l"
	.string "water as you please.\p"
	.string "I've always wanted to explore the seas\n"
	.string "around Dewford.\l"
	.string "I've heard of a shipwreck there.$"

PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon:
	.string "Wally's coming home soon.\n"
	.string "I'm looking forward to that.$"

PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity:
	.string "Oh? You met Wally in\n"
	.string "Ever Grande City?\p"
	.string "Oh, {PLAYER}{KUN}, don't be silly.\p"
	.string "He may have gotten healthy, but he\n"
	.string "can't go somewhere far away like\l"
	.string "that all by himself.$"

PetalburgCity_WallysHouse_Text_WallyWasReallyHappy:
	.string "Wally was really happy when he told\n"
	.string "us that he caught a Pokémon.\p"
	.string "It's been ages since I've seen him\n"
	.string "smile like that.$"

PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling:
	.string "I want you to keep this a secret\n"
	.string "from my husband…\p"
	.string "But our Wally left Verdanturf Town\n"
	.string "without telling anyone.\p"
	.string "You know, Wally is frail, but\n"
	.string "he's surprisingly strong-willed.\p"
	.string "I'm sure that he'll come back safe\n"
	.string "and sound one day!$"

