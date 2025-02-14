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

EverGrandeCity_DevelopersHouse_Text_Man:
	.string "Hey there, player! I hope you're having\n"
	.string "a good time with Energized Emerald.\p"
	.string "I wanted to make an ultimate Pokémon\n"
	.string "Emerald game that I would love,\l"
	.string "and I hope you would love, too.\p"
	.string "It may feel like you're approaching the\n"
	.string "endgame, but there is a load of cool\l"
	.string "new post game content after beating\l"
	.string "the Pokémon League.\p"
	.string "Have fun!$"
