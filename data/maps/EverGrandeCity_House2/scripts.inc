EverGrandeCity_House2_MapScripts::
	.byte 0

EverGrandeCity_House2_EventScript_Man::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_EVER_GRANDE_RECEIVED_BERRY, EverGrandeCity_House2_EventScript_ReceivedBerryToday
	msgbox EverGrandeCity_House2_Text_ManGiveBerry, MSGBOX_DEFAULT
	call EverGrandeCity_House2_EventScript_GiveRandomBerry
	call EverGrandeCity_House2_EventScript_GiveRandomBerry
	setflag FLAG_DAILY_EVER_GRANDE_RECEIVED_BERRY
	msgbox EverGrandeCity_House2_Text_ManWooning, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_House2_EventScript_ReceivedBerryToday::
	msgbox EverGrandeCity_House2_Text_ReceivedBerryToday, MSGBOX_DEFAULT
	closemessage
	release
	end

EverGrandeCity_House2_EventScript_GiveRandomBerry::
	random NUM_EVER_GRANDE_BERRIES
	addvar VAR_RESULT, NUM_EVER_GRANDE_BERRIES_SKIPPED
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	return

EverGrandeCity_House2_Text_ManGiveBerry:
	.string "Those cold hard eyes…\n"
	.string "That chilling presence…\p"
	.string "How I long to be hers, yet she casts me\n"
	.string "aside like trash…\p"
	.string "In the meantime, I make a living growing\n"
	.string "berries. Here.$"

EverGrandeCity_House2_Text_ManWooning:
	.string "Oh, if only she were as appreciative of\n"
	.string "my berries as you are…$"

EverGrandeCity_House2_Text_ReceivedBerryToday:
	.string "Glacia, oh Glacia!\p"
	.string "One day, I will find a song that will\n"
	.string "warm up your icy heart!$"
