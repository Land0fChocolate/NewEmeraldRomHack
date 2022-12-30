EverGrandeCity_House3_MapScripts::
	.byte 0

EverGrandeCity_House3_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM54, EverGrandeCity_House3_EventScript_ReceivedFalseSwipe
	msgbox EverGrandeCity_House3_Text_GiveFalseSwipe, MSGBOX_DEFAULT
	giveitem ITEM_TM54
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM54
	msgbox EverGrandeCity_House3_Text_ExplainFalseSwipe, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_House3_EventScript_ReceivedFalseSwipe::
	msgbox EverGrandeCity_House3_Text_ExplainFalseSwipe, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_House3_EventScript_Girl::
	msgbox EverGrandeCity_House3_Text_Girl, MSGBOX_NPC
	end

EverGrandeCity_House3_Text_GiveFalseSwipe:
	.string "Oh wow, you're working on a Pokédex?\p"
	.string "I love reading the entries and learning\n"
	.string "about all sorts of Pokémon!\p"
	.string "Here, take this to make catching Pokémon\n"
	.string "easier.$"

EverGrandeCity_House3_Text_ExplainFalseSwipe:
	.string "That's False Swipe.\p"
	.string "It's a really smart move. It does damage\n"
	.string "but never lets the opponent faint.\p"
	.string "That way, Pokémon become much easier to\n"
	.string "catch!$"

EverGrandeCity_House3_Text_Girl:
	.string "I'm sceptical of a lot of entries in\n"
	.string "Pokédexes.\p"
	.string "How can a Magcargo be twice as hot as\n"
	.string "the surface of the sun?\p"
	.string "How can a Machamp punch a thousand\n"
	.string "times in two seconds?\p"
	.string "I should find the authors and demand\n"
	.string "answers!$"
