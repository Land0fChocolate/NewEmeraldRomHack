MauvilleCity_SweetShop_MapScripts::
	.byte 0

MauvilleCity_SweetShop_EventScript_OldMan::
	lock
	faceplayer
	message MauvilleCity_SweetShop_Text_OldMan
	waitmessage
	goto_if_unset FLAG_POST_GAME_COMPLETE, MauvilleCity_SweetShop_EventScript_StandardShop
	pokemart MauvilleCity_SweetShop_Pokemart_OldManFinalShop
MauvilleCity_SweetShop_EventScript_ExitShop::
	msgbox gText_LookForwardToSeeingYouAgain, MSGBOX_DEFAULT
	release
	end

MauvilleCity_SweetShop_EventScript_StandardShop::
	pokemart MauvilleCity_SweetShop_Pokemart_OldManStandardShop
	goto MauvilleCity_SweetShop_EventScript_ExitShop
	end

	.align 2
MauvilleCity_SweetShop_Pokemart_OldManStandardShop:
	.2byte ITEM_PEWTER_CRUNCHIES
	.2byte ITEM_RAGE_CANDY_BAR
	.2byte ITEM_JELLY_FILLED_DONUT
	.2byte ITEM_OLD_GATEAU
	.2byte ITEM_SHALOUR_SABLE
	.2byte ITEM_BIG_MALASADA
	.2byte ITEM_LUMIOSE_GALETTE
	.2byte ITEM_CASTELIACONE
	.2byte ITEM_NONE
	release
	end

MauvilleCity_SweetShop_Pokemart_OldManFinalShop:
	.2byte ITEM_RARE_CANDY
	.2byte ITEM_PEWTER_CRUNCHIES
	.2byte ITEM_RAGE_CANDY_BAR
	.2byte ITEM_JELLY_FILLED_DONUT
	.2byte ITEM_OLD_GATEAU
	.2byte ITEM_SHALOUR_SABLE
	.2byte ITEM_BIG_MALASADA
	.2byte ITEM_LUMIOSE_GALETTE
	.2byte ITEM_CASTELIACONE
	.2byte ITEM_NONE
	release
	end

MauvilleCity_SweetShop_EventScript_Woman::
	lock
	faceplayer
	message MauvilleCity_SweetShop_Text_Woman
	waitmessage
	pokemart MauvilleCity_SweetShop_Pokemart_Woman
	msgbox MauvilleCity_SweetShop_Text_WomanBye, MSGBOX_DEFAULT
	release
	end

	.align 2
MauvilleCity_SweetShop_Pokemart_Woman:
	.2byte ITEM_LONELY_MINT
	.2byte ITEM_ADAMANT_MINT
	.2byte ITEM_NAUGHTY_MINT
	.2byte ITEM_BRAVE_MINT
	.2byte ITEM_BOLD_MINT
	.2byte ITEM_IMPISH_MINT
	.2byte ITEM_LAX_MINT
	.2byte ITEM_RELAXED_MINT
	.2byte ITEM_MODEST_MINT
	.2byte ITEM_MILD_MINT
	.2byte ITEM_RASH_MINT
	.2byte ITEM_QUIET_MINT
	.2byte ITEM_CALM_MINT
	.2byte ITEM_GENTLE_MINT
	.2byte ITEM_CAREFUL_MINT
	.2byte ITEM_SASSY_MINT
	.2byte ITEM_TIMID_MINT
	.2byte ITEM_HASTY_MINT
	.2byte ITEM_JOLLY_MINT
	.2byte ITEM_NAIVE_MINT
	.2byte ITEM_SERIOUS_MINT
	.2byte ITEM_NONE
	release
	end

MauvilleCity_SweetShop_EventScript_Hiker::
	msgbox MauvilleCity_SweetShop_Text_Hiker, MSGBOX_NPC
	end

MauvilleCity_SweetShop_EventScript_Twin::
	msgbox MauvilleCity_SweetShop_Text_Twin, MSGBOX_NPC
	end

MauvilleCity_SweetShop_EventScript_FairyTaleGirl::
	msgbox MauvilleCity_SweetShop_Text_FairyTaleGirl, MSGBOX_NPC
	end

MauvilleCity_SweetShop_EventScript_Boy::
	msgbox MauvilleCity_SweetShop_Text_Boy, MSGBOX_NPC
	end

MauvilleCity_SweetShop_Text_OldMan:
	.string "What sugary filled delights can I\n"
	.string "interest you for today?$"

MauvilleCity_SweetShop_Text_Woman:
	.string "We have mints so strong, your\n"
	.string "Pokémon won't feel the same again!$"

MauvilleCity_SweetShop_Text_WomanBye:
	.string "Come stop by again!$"

MauvilleCity_SweetShop_Text_Hiker:
	.string "These donuts are great!\n"
	.string "Jelly filled are my favourite!\l"
	.string "Nothing beats a jelly filled donut!$"

MauvilleCity_SweetShop_Text_Twin:
	.string "You can give candy to Pokémon!\n"
	.string "It can sometimes make them feel better\l"
	.string "if they're sick!$"

MauvilleCity_SweetShop_Text_FairyTaleGirl:
	.string "This store sells sweets from all\n"
	.string "around the world!$"

MauvilleCity_SweetShop_Text_Boy:
	.string "I wanna get one of those mints the lady\n"
	.string "sells, but they're super expensive.\p"
	.string "A mint could make my Pokémon stronger\n"
	.string "by giving it a different nature.$"
