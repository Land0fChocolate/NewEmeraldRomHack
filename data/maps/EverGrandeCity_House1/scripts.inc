EverGrandeCity_House1_MapScripts::
	.byte 0

EverGrandeCity_House1_EventScript_Woman::
	lock
	faceplayer
	goto_if_unset FLAG_OBTAINED_EVER_GRANDE_CITY_LUCKY_EGG, EverGrandeCity_House1_EventScript_GiveLuckyEgg
	msgbox EverGrandeCity_House1_Text_Woman, MSGBOX_DEFAULT
	closemessage
	release
	end

EverGrandeCity_House1_EventScript_GiveLuckyEgg::
	msgbox EverGrandeCity_House1_Text_GiveLuckyEgg, MSGBOX_DEFAULT
	giveitem ITEM_LUCKY_EGG
	closemessage
	setflag FLAG_OBTAINED_EVER_GRANDE_CITY_LUCKY_EGG
	release
	end

EverGrandeCity_House1_Text_GiveLuckyEgg:
	.string "I can tell by the way you walk that\n"
	.string "you're not an average trainer, even in\l"
	.string "Ever Grande City.\p"
	.string "You should make good use of this.$"

EverGrandeCity_House1_Text_Woman:
	.string "For some reason, this island has a thick\n"
	.string "cover of flowers. I've always wondered\l"
	.string "why here of all places.\p"
	.string "Not that I'm complaining, the flowers\n"
	.string "are part of the reason I moved here!$"
