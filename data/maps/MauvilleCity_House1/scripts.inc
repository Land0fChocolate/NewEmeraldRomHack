MauvilleCity_House1_MapScripts::
	.byte 0

MauvilleCity_House1_EventScript_RockSmashDude::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM66, MauvilleCity_House1_EventScript_ReceivedPayback
	msgbox MauvilleCity_House1_Text_ImPaybackDudeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM66
	setflag FLAG_RECEIVED_TM66
	setflag FLAG_HIDE_ROUTE_111_ROCK_SMASH_TIP_GUY
	msgbox MauvilleCity_House1_Text_ExplainRockSmash, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_EventScript_ReceivedPayback::
	msgbox MauvilleCity_House1_Text_FinishTheFight, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_Text_ImPaybackDudeTakeThis:
	.string "I hear people call me the Payback Guy,\n"
	.string "but I find that sort of degrading.\p"
	.string "I think I deserve a bit more respect,\n"
	.string "like maybe the Payback Dude.\p"
	.string "Anyways, your Pokémon look pretty\n"
	.string "strong.\p"
	.string "I like that!\n"
	.string "Here, take this Technical Machine!$"

MauvilleCity_House1_Text_ExplainRockSmash:
	.string "That TM contains Payback.\p"
	.string "If someone strikes you first,\n"
	.string "you can strike back with more power!\p"
	.string "Yes, sir! Smash the goons, I say!\n"
	.string "Woohoo!$"

MauvilleCity_House1_Text_FinishTheFight:
	.string "Oh yeah! Always be the one to\n"
	.string "finish the fight!\p"
	.string "Woohoo!$"
