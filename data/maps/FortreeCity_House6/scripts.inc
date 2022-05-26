FortreeCity_House6_MapScripts::
	.byte 0

FortreeCity_EventScript_ShopLady::
	lock
	faceplayer
	message FortreeCity_Text_ShopLady
	waitmessage
	pokemart FortreeCity_Pokemart_ShopLady
	msgbox gText_LookForwardToSeeingYouAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FortreeCity_Pokemart_ShopLady:
	.2byte ITEM_MENTAL_HERB
	.2byte ITEM_WHITE_HERB
	.2byte ITEM_POWER_HERB
	.2byte ITEM_MISTY_SEED
	.2byte ITEM_PSYCHIC_SEED
	.2byte ITEM_ELECTRIC_SEED
	.2byte ITEM_GRASSY_SEED
	.2byte ITEM_ABSORB_BULB
	.2byte ITEM_LUMINOUS_MOSS
	.2byte ITEM_NONE
	release
	end

FortreeCity_Text_ShopLady:
	.string "Hello! Everything I have here is freshly\n"
	.string "picked from the wilds.$"
