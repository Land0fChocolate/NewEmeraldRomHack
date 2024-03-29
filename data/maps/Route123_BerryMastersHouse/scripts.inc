Route123_BerryMastersHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route123_BerryMastersHouse_OnTransition
	.byte 0

Route123_BerryMastersHouse_OnTransition:
	setflag FLAG_LANDMARK_BERRY_MASTERS_HOUSE
	end

Route123_BerryMastersHouse_EventScript_BerryMaster::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_BERRY_MASTER_RECEIVED_BERRY, Route123_BerryMastersHouse_EventScript_ReceivedBerryToday
	msgbox Route123_BerryMastersHouse_Text_YoureDeservingOfBerry, MSGBOX_DEFAULT
	random NUM_BERRY_MASTER_BERRIES
	addvar VAR_RESULT, NUM_BERRY_MASTER_BERRIES_SKIPPED
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_BERRY_MASTER_RECEIVED_BERRY
	msgbox Route123_BerryMastersHouse_Text_WhyBeStingyTakeAnother, MSGBOX_DEFAULT
	random NUM_BERRY_MASTER_BERRIES
	addvar VAR_RESULT, NUM_BERRY_MASTER_BERRIES_SKIPPED
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	msgbox Route123_BerryMastersHouse_Text_VisitPrettyPetalFlowerShop, MSGBOX_DEFAULT
	release
	end

Route123_BerryMastersHouse_EventScript_ReceivedBerryToday::
	msgbox Route123_BerryMastersHouse_Text_DoneForToday, MSGBOX_DEFAULT
	release
	end

@ GREAT BATTLE (Route 123 Bird Keeper), CHALLENGE CONTEST (Contest Hall Delinquent), OVERWHELMING LATIAS (Route 107 Swimmer), COOL LATIOS (Mossdeep Lass), SUPER HUSTLE (Route 115 Black Belt)
Route123_BerryMastersHouse_EventScript_BerryMastersWife::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_BERRY_MASTERS_WIFE, Route123_BerryMastersHouse_EventScript_ReceivedWifeBerryToday
	msgbox Route123_BerryMastersHouse_Text_HeardAGoodSayingLately, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_GOOD_SAYING
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	compare VAR_RESULT, TRUE
	goto_if_eq Route123_BerryMastersHouse_EventScript_GavePhrase
	compare VAR_RESULT, FALSE
	goto_if_eq Route123_BerryMastersHouse_EventScript_CancelPhrase
	end

Route123_BerryMastersHouse_EventScript_CancelPhrase::
	msgbox Route123_BerryMastersHouse_Text_Ah, MSGBOX_DEFAULT
	msgbox Route123_BerryMastersHouse_Text_JoyNeverGoesOutOfMyLife, MSGBOX_DEFAULT
	release
	end

Route123_BerryMastersHouse_EventScript_GavePhrase::
	compare VAR_0x8004, NOT_SPECIAL_PHRASE
	goto_if_eq Route123_BerryMastersHouse_EventScript_GiveNormalBerry
	compare VAR_0x8004, PHRASE_GREAT_BATTLE
	goto_if_eq Route123_BerryMastersHouse_EventScript_GiveSpelonBerry
	compare VAR_0x8004, PHRASE_CHALLENGE_CONTEST
	goto_if_eq Route123_BerryMastersHouse_EventScript_GivePamtreBerry
	compare VAR_0x8004, PHRASE_OVERWHELMING_LATIAS
	goto_if_eq Route123_BerryMastersHouse_EventScript_GiveWatmelBerry
	compare VAR_0x8004, PHRASE_COOL_LATIOS
	goto_if_eq Route123_BerryMastersHouse_EventScript_GiveDurinBerry
	compare VAR_0x8004, PHRASE_SUPER_HUSTLE
	goto_if_eq Route123_BerryMastersHouse_EventScript_GiveBelueBerry
	end

Route123_BerryMastersHouse_EventScript_GiveNormalBerry::
	msgbox Route123_BerryMastersHouse_Text_GoodSayingTakeThis, MSGBOX_DEFAULT
	random NUM_BERRY_MASTER_WIFE_BERRIES
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	goto Route123_BerryMastersHouse_EventScript_GaveBerry
	release
	end

Route123_BerryMastersHouse_EventScript_GiveSpelonBerry::
	msgbox Route123_BerryMastersHouse_Text_InspirationalTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_SPELON_BERRY
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	goto Route123_BerryMastersHouse_EventScript_GaveBerry
	end

Route123_BerryMastersHouse_EventScript_GivePamtreBerry::
	msgbox Route123_BerryMastersHouse_Text_InspirationalTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_PAMTRE_BERRY
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	goto Route123_BerryMastersHouse_EventScript_GaveBerry
	end

Route123_BerryMastersHouse_EventScript_GiveWatmelBerry::
	msgbox Route123_BerryMastersHouse_Text_InspirationalTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_WATMEL_BERRY
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	goto Route123_BerryMastersHouse_EventScript_GaveBerry
	end

Route123_BerryMastersHouse_EventScript_GiveDurinBerry::
	msgbox Route123_BerryMastersHouse_Text_InspirationalTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_DURIN_BERRY
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	goto Route123_BerryMastersHouse_EventScript_GaveBerry
	end

Route123_BerryMastersHouse_EventScript_GiveBelueBerry::
	msgbox Route123_BerryMastersHouse_Text_InspirationalTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_BELUE_BERRY
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	goto Route123_BerryMastersHouse_EventScript_GaveBerry
	end

Route123_BerryMastersHouse_EventScript_ReceivedWifeBerryToday::
	msgbox Route123_BerryMastersHouse_Text_JoyNeverGoesOutOfMyLife, MSGBOX_DEFAULT
	release
	end

Route123_BerryMastersHouse_EventScript_GaveBerry::
	setflag FLAG_DAILY_BERRY_MASTERS_WIFE
	msgbox Route123_BerryMastersHouse_Text_JoyNeverGoesOutOfMyLife, MSGBOX_DEFAULT
	release
	end

