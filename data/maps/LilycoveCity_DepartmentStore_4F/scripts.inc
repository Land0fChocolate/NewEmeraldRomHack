LilycoveCity_DepartmentStore_4F_MapScripts::
	.byte 0

LilycoveCity_DepartmentStore_4F_EventScript_Gentleman::
	msgbox LilycoveCity_DepartmentStore_4F_Text_AttackOrDefenseTM, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_4F_EventScript_Woman::
	msgbox LilycoveCity_DepartmentStore_4F_Text_HundredDifferentTMs, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_4F_EventScript_Youngster::
	msgbox LilycoveCity_DepartmentStore_4F_Text_PokemonOnlyHaveFourMoves, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_4F_EventScript_ClerkLeft::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_4F_Pokemart_AttackTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_4F_Pokemart_AttackTMs:
	.2byte ITEM_TM51  @ Leech Life
	.2byte ITEM_TM80  @ Rock Slide
	.2byte ITEM_TM84  @ Poison Jab
	.2byte ITEM_TM98  @ Waterfall
	.2byte ITEM_TM14  @ Blizzard
	.2byte ITEM_TM25  @ Thunder
	.2byte ITEM_TM38  @ Fire Blast
	.2byte ITEM_TM52  @ Focus Blast
	.2byte ITEM_TM15  @ Hyper Beam
	.2byte ITEM_TM68  @ Giga Impact
	.2byte ITEM_NONE
	release
	end

LilycoveCity_DepartmentStore_4F_EventScript_ClerkRight::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_4F_Pokemart_DefenseTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_4F_Pokemart_DefenseTMs:
	.2byte ITEM_TM16  @ Light Screen
	.2byte ITEM_TM17  @ Protect
	.2byte ITEM_TM20  @ Safeguard
	.2byte ITEM_TM33  @ Reflect
	.2byte ITEM_TM61  @ Will-O-Wisp
	.2byte ITEM_TM70  @ Aurora Veil
	.2byte ITEM_TM73  @ Thunder Wave
	.2byte ITEM_TM85  @ Electro Web
	.2byte ITEM_TM87  @ Topsy Turvy
	.2byte ITEM_TM92  @ Trick Room
	.2byte ITEM_NONE
	release
	end

LilycoveCity_DepartmentStore_4F_Text_AttackOrDefenseTM:
	.string "Hmm…\p"
	.string "An attacking move…\n"
	.string "Or a defensive move…\p"
	.string "It's no easy matter to decide which TM\n"
	.string "moves should be taught to Pokémon…$"

LilycoveCity_DepartmentStore_4F_Text_HundredDifferentTMs:
	.string "There are so many different kinds of\n"
	.string "TM moves.\p"
	.string "A catalog I read said there are a\n"
	.string "hundred different kinds.$"

LilycoveCity_DepartmentStore_4F_Text_PokemonOnlyHaveFourMoves:
	.string "I'd like to get all the different TMs,\n"
	.string "but a Pokémon learns only four moves.$"

