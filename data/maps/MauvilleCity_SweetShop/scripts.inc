MauvilleCity_SweetShop_MapScripts::
	.byte 0

MauvilleCity_SweetShop_EventScript_OldMan::
	lock
	faceplayer
	message MauvilleCity_SweetShop_Text_OldMan
	waitmessage
	pokemart MauvilleCity_SweetShop_Pokemart_OldMan
	msgbox gText_LookForwardToSeeingYouAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MauvilleCity_SweetShop_Pokemart_OldMan:
	.2byte ITEM_RAGE_CANDY_BAR
	.2byte ITEM_CASTELIACONE
	.2byte ITEM_OLD_GATEAU
	.2byte ITEM_PEWTER_CRUNCHIES
	.2byte ITEM_SHALOUR_SABLE
	@.2byte ITEM_JELLY_FILLED_DONUT @TODO:
	.2byte ITEM_NONE
	release
	end

MauvilleCity_SweetShop_EventScript_Woman::
	lock
	faceplayer
	message MauvilleCity_SweetShop_Text_Woman
	waitmessage
	pokemart MauvilleCity_SweetShop_Pokemart_Woman
	msgbox gText_LookForwardToSeeingYouAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MauvilleCity_SweetShop_Pokemart_Woman: @TODO: mints
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
	.string "A mint could buff up my Pokémon by\n"
	.string "giving it a different personality.$"
