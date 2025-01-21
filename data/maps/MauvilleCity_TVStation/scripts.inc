MauvilleCity_TVStation_MapScripts::
	.byte 0

MauvilleCity_TVStation_EventScript_Receptionist::
	msgbox MauvilleCity_TVStation_Text_Receptionist, MSGBOX_NPC
	end

MauvilleCity_TVStation_EventScript_Man::
	msgbox MauvilleCity_TVStation_Text_Man, MSGBOX_NPC
	end

MauvilleCity_TVStation_EventScript_CameraMan::
	msgbox MauvilleCity_TVStation_Text_CameraMan, MSGBOX_NPC
	end

MauvilleCity_TVStation_EventScript_Beauty::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM75, MauvilleCity_TVStation_EventScript_BeautyPostTM
	msgbox MauvilleCity_TVStation_Text_Beauty, MSGBOX_DEFAULT
	giveitem ITEM_TM75
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM75
	goto MauvilleCity_TVStation_EventScript_BeautyPostTM
	end

MauvilleCity_TVStation_EventScript_BeautyPostTM::
	msgbox MauvilleCity_TVStation_Text_BeautyPostTM, MSGBOX_DEFAULT
	release
	end

MauvilleCity_TVStation_EventScript_Sidney::
	msgbox MauvilleCity_TVStation_Text_Sidney, MSGBOX_NPC
	end

MauvilleCity_TVStation_EventScript_Maniac::
	msgbox MauvilleCity_TVStation_Text_Maniac, MSGBOX_NPC
	end

MauvilleCity_TVStation_EventScript_Triathlete::
	msgbox MauvilleCity_TVStation_Text_Triathlete, MSGBOX_NPC
	end

MauvilleCity_TVStation_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_TV_STATION_TRADE_DONE, MauvilleCity_TVStation_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_GEODUDE_ALOLAN
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox MauvilleCity_TVStation_Text_WouldYouLikeToTrade, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_TVStation_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	compare VAR_0x8004, 255
	goto_if_eq MauvilleCity_TVStation_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	compare VAR_RESULT, VAR_0x8009
	goto_if_ne MauvilleCity_TVStation_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox MauvilleCity_TVStation_Text_PromiseIllBeGoodToIt, MSGBOX_DEFAULT
	setflag FLAG_TV_STATION_TRADE_DONE
	release
	end

MauvilleCity_TVStation_EventScript_DeclineTrade::
	msgbox MauvilleCity_TVStation_Text_WellThatsFineToo, MSGBOX_DEFAULT
	release
	end

MauvilleCity_TVStation_EventScript_NotRequestedMon::
	bufferspeciesname 0, VAR_0x8009
	msgbox MauvilleCity_TVStation_Text_DontTradeForAnythingButMon, MSGBOX_DEFAULT
	release
	end

MauvilleCity_TVStation_EventScript_TradeCompleted::
	msgbox MauvilleCity_TVStation_Text_AronWonderful, MSGBOX_DEFAULT
	release
	end

MauvilleCity_TVStation_Text_WouldYouLikeToTrade:
	.string "My work takes me chasing stories\n"
	.string "around the world.\p"
	.string "I visited Alola on my latest trip.\n"
	.string "I found an unusual variety of Geodude\l"
	.string "there.\p"
	.string "I can see you eyeing it…\p"
	.string "I'm willing to let it go, in exchange\n"
	.string "for an {STR_VAR_1}.\l"
	.string "Do you have one?$"

MauvilleCity_TVStation_Text_PromiseIllBeGoodToIt:
	.string "Oh, it's marvelous!\n"
	.string "Thank you!\l"
	.string "I promise I'll be good to it!\p"
	.string "Oh! I hope you'll be good to\n"
	.string "my {STR_VAR_2}, too!$"

MauvilleCity_TVStation_Text_DontTradeForAnythingButMon:
	.string "Oh, I'm sorry!\n"
	.string "I don't intend to trade for anything\l"
	.string "but a {STR_VAR_1}.$"

MauvilleCity_TVStation_Text_WellThatsFineToo:
	.string "Not for you, eh?\n"
	.string "Each to their own.$"

MauvilleCity_TVStation_Text_AronWonderful:
	.string "The Aron you have given me has been\n"
	.string "a wonderful companion.\l"
	.string "Thank you, again!$"

MauvilleCity_TVStation_Text_Receptionist:
	.string "Hello, welcome to TV Mauville.\p"
	.string "Many TV programs broadcast in the Hoenn\n"
	.string "region are filmed and edited in the\l"
	.string "studios here.\p"
	.string "Feel free to tour the studios.$"

MauvilleCity_TVStation_Text_Man:
	.string "Much of our content isn't filmed here.\n"
	.string "We have reporters across Hoenn to catch\l"
	.string "the latest action on scene.\p"
	.string "You may have come across them.\n"
	.string "Please do accept their interviews when\l"
	.string "you have the time!$"

MauvilleCity_TVStation_Text_CameraMan:
	.string "Are you touring the studios?\n"
	.string "Don't touch any of the equipment.\l"
	.string "That stuff is expensive.$"

MauvilleCity_TVStation_Text_Beauty:
	.string "Oh my!\n"
	.string "My fans just keep coming!\p"
	.string "I can't give you a kiss, sweetie, but\n"
	.string "perhaps this will make up for it?$"

MauvilleCity_TVStation_Text_BeautyPostTM:
	.string "We have a very special guest for our\n"
	.string "upcoming interview!\l"
	.string "Please keep this a secret, okay?$"

MauvilleCity_TVStation_Text_Sidney:
	.string "Some Pokémon get an undeserved bad rep.\n"
	.string "I'm here to try to change people's\l"
	.string "misconceptions of them.\p"
	.string "If I can change the minds of even just\n"
	.string "a few people through this interview,\l"
	.string "then it will be a success.\p"
	.string "However my work won't be done until I\n"
	.string "change all of public perception.$"

MauvilleCity_TVStation_Text_Maniac:
	.string "Coming up with new scripts is tough.\n"
	.string "I'm tempted to pinch ideas from older\l"
	.string "shows. Hehehe.$"

MauvilleCity_TVStation_Text_Triathlete:
	.string "Some people become TV stars through\n"
	.string "Pokémon battles.\p"
	.string "I'm not good with Pokémon, so I'll just\n"
	.string "have to find another way.$"
