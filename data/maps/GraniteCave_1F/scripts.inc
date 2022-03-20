GraniteCave_1F_MapScripts::
	.byte 0

GraniteCave_1F_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_BADGE02_GET, GraniteCave_1F_EventScript_GotBadge
	msgbox GraniteCave_1F_Text_GetsDarkAheadNoBadge, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_GotBadge::
	msgbox GraniteCave_1F_Text_GetsDarkYouHaveBadge, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_Text_GetsDarkAheadNoBadge:
	.string "Hey, you.\n"
	.string "It gets awfully dark ahead.\l"
	.string "It'll be tough trying to explore.\p"
	.string "That guy who came by earlier…\n"
	.string "Steven, I think it was.\p"
	.string "His Pokémon were able to make light,\n"
	.string "so he ought to be all right, but…\p"
	.string "if you don't have the Badge from the\n"
	.string "Dewford Gym then you're gonna have\l"
	.string "a hard time.$"

GraniteCave_1F_Text_GetsDarkYouHaveBadge:
	.string "Hey, you.\n"
	.string "It gets awfully dark ahead.\p"
	.string "Though since you have the Dewford Gym\n"
	.string "Badge, your Pokémon will be able to\l"
	.string "create light. You should be OK.$"

