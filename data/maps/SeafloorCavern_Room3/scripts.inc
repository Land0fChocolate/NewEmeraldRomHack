SeafloorCavern_Room3_MapScripts::
	.byte 0

SeafloorCavern_Room3_EventScript_Shelly::
	trainerbattle_single TRAINER_SHELLY_SEAFLOOR_CAVERN, SeafloorCavern_Room3_Text_ShellyIntro, SeafloorCavern_Room3_Text_ShellyDefeat
	msgbox SeafloorCavern_Room3_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_5, SeafloorCavern_Room3_Text_Grunt5Intro, SeafloorCavern_Room3_Text_Grunt5Defeat
	msgbox SeafloorCavern_Room3_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_EventScript_Zinnia::
	lock
	faceplayer
	msgbox SeafloorCavern_Room3_Text_Zinnia, MSGBOX_DEFAULT
	closemessage
	end

SeafloorCavern_Room3_Text_Zinnia:
	.string "Ah, you!\p"
	.string "Well, of course it's you!\p"
	.string "You don't know me.\n"
	.string "Nope!\p"
	.string "Archie is a little further up ahead.\n"
	.string "That's the place to go to if you want\l"
	.string "to stop him.$"

SeafloorCavern_Room3_Text_ShellyIntro:
	.string "Hahn?\p"
	.string "How did you manage to get here without\n"
	.string "a submarine? Well, it doesn't matter.\p"
	.string "The world Archie dreams of would be a\n"
	.string "utopia for Pokémon.\p"
	.string "I can't let you get in the way of\n"
	.string "someone who's pushing on toward a\l"
	.string "perfect world!$"

SeafloorCavern_Room3_Text_ShellyDefeat:
	.string "Wh-what was that!?$"

SeafloorCavern_Room3_Text_ShellyPostBattle:
	.string "Uh. Are you telling me you've upped your\n"
	.string "game even more since last time?\p" 
	.string "My Pokémon and I don't have any\n"
	.string "strength left to fight…\p"
	.string "Go on… Go and be destroyed by Archie.\n"
	.string "You don't have your friend to help you\l"
	.string "this time.$"

SeafloorCavern_Room3_Text_Grunt5Intro:
	.string "For our dream to become real, we need\n"
	.string "the power of Pokémon.\p"
	.string "But meddlers like you use the power of\n"
	.string "Pokémon to mess with us even at\l"
	.string "a place like this!\p"
	.string "Life just doesn't work the way we\n"
	.string "need it to!$"

SeafloorCavern_Room3_Text_Grunt5Defeat:
	.string "Gwah!$"

SeafloorCavern_Room3_Text_Grunt5PostBattle:
	.string "You know, we don't dare question\n"
	.string "the motives of our leader.\p"
	.string "But here you are, just some punk,\n"
	.string "going up against our boss.\p"
	.string "Maybe…\n"
	.string "You must be something…$"

