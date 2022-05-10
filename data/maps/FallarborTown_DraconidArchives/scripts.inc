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
	.string "An old looking statue.$"

DraconidArchives_Text_DisplayCase:
	.string "The display case contains some kind of\n"
	.string "stringed instrument.$"
