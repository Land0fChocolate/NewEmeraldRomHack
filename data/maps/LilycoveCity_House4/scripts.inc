LilycoveCity_House4_MapScripts::
	.byte 0

LilycoveCity_EventScript_GameboyKid::
	lock
	faceplayer
	msgbox LilycoveCity_EventScript_SelfTrade_Text_IllTradeIfYouWant, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LilycoveCity_EventScript_SelfTrade_DeclineTrade
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq LilycoveCity_EventScript_SelfTrade_DeclineTrade
	copyvar VAR_0x8005, VAR_0x8004
	setvar VAR_0x8004, 6
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox LilycoveCity_EventScript_SelfTrade_Text_ComeBack, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_SelfTrade_DeclineTrade::
	msgbox LilycoveCity_EventScript_SelfTrade_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_SelfTrade_Text_IllTradeIfYouWant:
	.string "Heyo! I'm the Tradeback Guy!\p"
	.string "I can help you trade a Pokémon with\n"
	.string "yourself! Are you here to do that?$"

LilycoveCity_EventScript_SelfTrade_Text_ComeBack:
	.string "Happy to help! Come back anytime.$"

LilycoveCity_EventScript_SelfTrade_Text_YouDontWantToThatsOkay:
	.string "You dont want to?\n"
	.string "Okay, come back anytime.$"
