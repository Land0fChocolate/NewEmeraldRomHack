FallarborTown_DraconidArchives_MapScripts::
	.byte 0

DraconidArchives_Eventscript_OldMan::
	lock
	faceplayer
	msgbox DraconidArchives_Text_WelcomeToArchives, MSGBOX_DEFAULT
	release
	end

DraconidArchives_Eventscript_FairyTaleGirl::
	msgbox DraconidArchives_Text_FairyTales, MSGBOX_NPC
	end

DraconidArchives_Eventscript_Man::
	msgbox DraconidArchives_Text_CouldTextShowTreasures, MSGBOX_NPC
	end

DraconidArchives_Eventscript_Sculpture::
	msgbox DraconidArchives_Text_Sculpture, MSGBOX_SIGN
	end

DraconidArchives_Eventscript_DisplayCase::
	msgbox DraconidArchives_Text_DisplayCase, MSGBOX_SIGN
	end

DraconidArchives_Eventscript_Scroll::
	msgbox DraconidArchives_Text_Scroll, MSGBOX_SIGN
	end

DraconidArchives_Eventscript_Book::
	msgbox DraconidArchives_Text_Book, MSGBOX_SIGN
	end


DraconidArchives_Text_WelcomeToArchives:
	.string "Welcome to the Draconid Archives.\n"
	.string "It is good to see a new visitor.\p"
	.string "Feel free to look through our library of\n"
	.string "materials as you wish.\p"
	.string "However since our Lorekeeper has run\n"
	.string "off somewhere, other services are\l"
	.string "currently unavailable.$"

DraconidArchives_Text_FairyTales:
	.string "Hello, have you come here for the\n"
	.string "old stories too?\l"
	.string "The Galarian fairy tales are good ones.$"

DraconidArchives_Text_CouldTextShowTreasures:
	.string "I wonder if one of these dusty old tomes\n"
	.string "can lead me to treasure, or rare and\l"
	.string "powerful Pokémon.$"

DraconidArchives_Text_Sculpture:
	.string "A worn down looking statue.$"

DraconidArchives_Text_DisplayCase:
	.string "The display case contains some kind of\n"
	.string "stringed instrument.$"

DraconidArchives_Text_Scroll:
	.string "A scroll written in a primitive language\n"
	.string "you don't understand. The illustration\l"
	.string "depicts some monstrous looking Pokémon\l"
	.string "engaged in an epic battle.$"

DraconidArchives_Text_Book:
	.string "A book on historical meteorite events.\n"
	.string "There's lots of metaphorical\l"
	.string "descriptions in here.$"
