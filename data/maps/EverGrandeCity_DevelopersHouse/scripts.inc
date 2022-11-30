EverGrandeCity_DevelopersHouse_MapScripts::
	.byte 0

EverGrandeCity_DevelopersHouse_EventScript_Man::
	goto_if_set FLAG_POST_GAME_COMPLETE, EverGrandeCity_DevelopersHouse_EventScript_ManCongrats
	goto_if_set FLAG_SYS_GAME_CLEAR, EverGrandeCity_DevelopersHouse_EventScript_ManPostGame
	msgbox EverGrandeCity_DevelopersHouse_Text_Man, MSGBOX_NPC
	end

EverGrandeCity_DevelopersHouse_EventScript_ManCongrats::
	msgbox EverGrandeCity_DevelopersHouse_Text_ManCongrats, MSGBOX_NPC
	end

EverGrandeCity_DevelopersHouse_EventScript_ManPostGame::
	msgbox EverGrandeCity_DevelopersHouse_Text_ManPostGame, MSGBOX_NPC
	end

EverGrandeCity_DevelopersHouse_Text_ManCongrats:
	.string "Congrats on beating the post game!\n"
	.string "I hope you enjoyed it.\p"
	.string "Be sure to leave feedback.\n"
	.string "I'll still be making some adjustments\l"
	.string "to Energized Emerald after release.$"

EverGrandeCity_DevelopersHouse_Text_ManPostGame:
	.string "You're in the post game now!\p"
	.string "I hope you are enjoying the new areas\n"
	.string "I added and the updates to the\l"
	.string "Battle Frontier.$"

@TODO: this text will likely require updating.
EverGrandeCity_DevelopersHouse_Text_Man:
	.string "Hey there, player! I hope you're having\n"
	.string "a good time with Energized Emerald.\p"
	.string "My aim with this romhack was to spice\n"
	.string "things up and make it fun and exciting,\l"
	.string "whilst also enhancing the character of\l"
	.string "the region.\p"
	.string "It may feel like you're approaching the\n"
	.string "endgame, but there is a load of cool\l"
	.string "new content after beating the Pokémon\l"
	.string "League.\p"
	.string "Have fun!$"
