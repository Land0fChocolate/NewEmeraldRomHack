MauvilleCity_ToolShop_MapScripts::
	.byte 0

MauvilleCity_ToolShop_EventScript_ShopKeeper::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, MauvilleCity_ToolShop_EventScript_ShopKeeperNotSelling
	message MauvilleCity_ToolShop_Text_ShopKeeper
	waitmessage
	pokemart MauvilleCity_ToolShop_Pokemart_ShopKeeper
	msgbox gText_LookForwardToSeeingYouAgain, MSGBOX_DEFAULT
	release
	end

MauvilleCity_ToolShop_EventScript_ShopKeeperNotSelling::
	msgbox MauvilleCity_ToolShop_Text_ShopKeeperNotSelling, MSGBOX_DEFAULT
	release
	end

	.align 2
MauvilleCity_ToolShop_Pokemart_ShopKeeper:
	.2byte ITEM_CELL_BATTERY
	.2byte ITEM_UTILITY_UMBRELLA
	.2byte ITEM_SAFETY_GOGGLES
	.2byte ITEM_ROCKY_HELMET
	.2byte ITEM_ZOOM_LENS
	.2byte ITEM_WIDE_LENS
	.2byte ITEM_METRONOME
	.2byte ITEM_HEAVY_DUTY_BOOTS
	.2byte ITEM_EJECT_PACK
	.2byte ITEM_PROTECTIVE_PADS
	.2byte ITEM_IRON_BALL
	.2byte ITEM_NONE
	release
	end

MauvilleCity_ToolShop_EventScript_Man::
	msgbox MauvilleCity_ToolShop_Text_Man, MSGBOX_NPC
	end

MauvilleCity_ToolShop_Text_ShopKeeper:
	.string "I got tools for Pokémon right here.$"

MauvilleCity_ToolShop_Text_ShopKeeperNotSelling:
	.string "Sorry, kid. All of our stock is\n"
	.string "currently booked for orders.\l"
	.string "Come back another time.$"

MauvilleCity_ToolShop_Text_Man:
	.string "Pokémon can be very intuitive. I never\n"
	.string "thought that they could use man-made\l"
	.string "equipment.$"
