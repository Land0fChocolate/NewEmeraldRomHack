MossdeepCity_SpaceCenter_2F_MapScripts::
	.byte 0

MossdeepCity_SpaceCenter_2F_EventScript_Scientist1::
	lock
	msgbox MossdeepCity_SpaceCenter_2F_Text_PokemonInSpace, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_Scientist2::
	lock
	msgbox MossdeepCity_SpaceCenter_2F_Text_StrangeReadings, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_Gentleman::
	lock
	faceplayer
	msgbox MossdeepCity_SpaceCenter_2F_Text_WouldveLikedToBeAstronaut, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_RichBoy::
	lock
	faceplayer
	msgbox MossdeepCity_SpaceCenter_2F_Text_WishOrdinaryPeopleCouldGoIntoSpace, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_Text_PokemonInSpace:
	.string "Gamma ray pulse? Solar flare?\n"
	.string "Maybe some kind of incredibly powerful\l"
	.string "Pokémon up there in space?\p"
	.string "That couldn't be it, could it?$"

MossdeepCity_SpaceCenter_2F_Text_StrangeReadings:
	.string "These readings are beyond strange.\n"
	.string "What in the world could expel that\l"
	.string "amount of energy?$"

MossdeepCity_SpaceCenter_2F_Text_WouldveLikedToBeAstronaut:
	.string "If only I was a little younger, I would\n"
	.string "have liked being an astronaut…\p"
	.string "No… It's not too late!\n"
	.string "I can and will try!$"

MossdeepCity_SpaceCenter_2F_Text_WishOrdinaryPeopleCouldGoIntoSpace:
	.string "I wish ordinary people could go into\n"
	.string "space one day…$"
