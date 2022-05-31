OldaleFarm_MapScripts::
	.byte 0

OldaleFarm_Eventscript_Girl::
	msgbox OldaleFarm_Text_Girl, MSGBOX_NPC
	end

OldaleFarm_Eventscript_Boy::
	msgbox OldaleFarm_Text_Boy, MSGBOX_NPC
	end

OldaleFarm_Eventscript_Sign::
	msgbox OldaleFarm_Text_Sign, MSGBOX_SIGN
	end

OldaleFarm_Text_Girl:
	.string "We have rare and cute Pokémon here\n"
	.string "that are found nowhere else.\l"
	.string "I love playing with them every day!$"

OldaleFarm_Text_Boy:
	.string "A short time ago, a rock from space\n"
	.string "fell down and crashed next to the barn\l"
	.string "right here.\p"
	.string "Luckily, nobody was hurt, but something\n"
	.string "about that rock gave me weird vibes.\p"
	.string "The professor from Littleroot took it.\n"
	.string "I wonder what anyone could do with a\l"
	.string "rock like that?$"

OldaleFarm_Text_Sign:
	.string "OLDALE FARM$"
