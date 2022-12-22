OldaleFarm_House_MapScripts::
	.byte 0

	.set POKEMON_PRICE, 50000

OldaleFarm_House_Eventscript_Man::
	goto_if_set FLAG_SYS_NATIONAL_DEX, OldaleFarm_House_Eventscript_Man_PlayerHasNationalDex
	msgbox OldaleFarm_House_Text_Man, MSGBOX_NPC
	end

OldaleFarm_House_Eventscript_Man_PlayerHasNationalDex::
	lock
	dotimebasedevents
	faceplayer
	goto_if_set FLAG_DAILY_OLDALEFARM_POKEMON_GIVEN, OldaleFarm_House_Eventscript_Man_OnceADayService
	msgbox OldaleFarm_House_Text_Man_AskIfBuying, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq OldaleFarm_House_Eventscript_Man_Declined
	showmoneybox 0, 0, 0
	msgbox OldaleFarm_House_Text_Man_ChoosePokemon, MSGBOX_DEFAULT
	check3flags FLAG_SYS_NATIONAL_DEX, FLAG_JOHTO_STARTERS_AVAILABLE, FLAG_POST_GAME_COMPLETE
	goto_if TRUE, OldaleFarm_House_Eventscript_Man_PickAllStarters
	check2flags FLAG_SYS_NATIONAL_DEX, FLAG_JOHTO_STARTERS_AVAILABLE
	goto_if TRUE OldaleFarm_House_Eventscript_Man_PickHoennJohtoStarters
	check2flags FLAG_SYS_NATIONAL_DEX, FLAG_POST_GAME_COMPLETE
	goto_if TRUE OldaleFarm_House_Eventscript_Man_PickHoennKantoStarters
	checkflag FLAG_SYS_NATIONAL_DEX
	goto_if TRUE, OldaleFarm_House_Eventscript_Man_PickHoennStarters
	release
	end

OldaleFarm_House_Eventscript_Man_PickHoennStarters::
	multichoice 16, 0, MULTI_OLDALE_STARTERS_HOENN, FALSE
	switch VAR_RESULT
	case 0, OldaleFarm_House_Eventscript_PickTreecko
	case 1, OldaleFarm_House_Eventscript_PickTorchic
	case 2, OldaleFarm_House_Eventscript_PickMudkip
	case 3, OldaleFarm_House_Eventscript_Man_Declined
	goto OldaleFarm_House_Eventscript_Man_Declined
	end

OldaleFarm_House_Eventscript_Man_PickHoennKantoStarters::
	setvar VAR_0x8004, SCROLL_MULTI_OLDALE_STARTERS_HOENN_KANTO
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, OldaleFarm_House_Eventscript_PickTreecko
	case 1, OldaleFarm_House_Eventscript_PickTorchic
	case 2, OldaleFarm_House_Eventscript_PickMudkip
	case 3, OldaleFarm_House_Eventscript_PickBulbasaur
	case 4, OldaleFarm_House_Eventscript_PickCharmander
	case 5, OldaleFarm_House_Eventscript_PickSquirtle
	case 6, OldaleFarm_House_Eventscript_Man_Declined
	goto OldaleFarm_House_Eventscript_Man_Declined
	end

OldaleFarm_House_Eventscript_Man_PickHoennJohtoStarters::
	setvar VAR_0x8004, SCROLL_MULTI_OLDALE_STARTERS_HOENN_JOHTO
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, OldaleFarm_House_Eventscript_PickTreecko
	case 1, OldaleFarm_House_Eventscript_PickTorchic
	case 2, OldaleFarm_House_Eventscript_PickMudkip
	case 3, OldaleFarm_House_Eventscript_PickChikorita
	case 4, OldaleFarm_House_Eventscript_PickCyndaquil
	case 5, OldaleFarm_House_Eventscript_PickTotodile
	case 6, OldaleFarm_House_Eventscript_Man_Declined
	goto OldaleFarm_House_Eventscript_Man_Declined
	end

OldaleFarm_House_Eventscript_Man_PickAllStarters::
	setvar VAR_0x8004, SCROLL_MULTI_OLDALE_STARTERS_ALL
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, OldaleFarm_House_Eventscript_PickTreecko
	case 1, OldaleFarm_House_Eventscript_PickTorchic
	case 2, OldaleFarm_House_Eventscript_PickMudkip
	case 3, OldaleFarm_House_Eventscript_PickBulbasaur
	case 4, OldaleFarm_House_Eventscript_PickCharmander
	case 5, OldaleFarm_House_Eventscript_PickSquirtle
	case 6, OldaleFarm_House_Eventscript_PickChikorita
	case 7, OldaleFarm_House_Eventscript_PickCyndaquil
	case 8, OldaleFarm_House_Eventscript_PickTotodile
	case 9, OldaleFarm_House_Eventscript_Man_Declined
	goto OldaleFarm_House_Eventscript_Man_Declined
	end

OldaleFarm_House_Eventscript_PickTreecko::
	msgbox OldaleFarm_House_Text_AreYouSureYouWantTreecko, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq OldaleFarm_House_Eventscript_Man_Declined
	checkmoney POKEMON_PRICE, 0
	compare VAR_RESULT, FALSE
	goto_if_eq OldaleFarm_House_EventScript_NotEnoughMoney
	removemoney POKEMON_PRICE, 0
	updatemoneybox 0, 0
	setvar VAR_TEMP_1, SPECIES_TREECKO
	givemon SPECIES_TREECKO, 5, ITEM_NONE
	call OldaleFarm_House_EventScript_ReceivedTreeckoFanfare
	compare VAR_RESULT, 0
	goto_if_eq OldaleFarm_House_Eventscript_FinishReceivingPokemon
	compare VAR_RESULT, 1
	goto_if_eq OldaleFarm_House_EventScript_ReceivePokemonPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

OldaleFarm_House_Eventscript_PickTorchic::
	msgbox OldaleFarm_House_Text_AreYouSureYouWantTorchic, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq OldaleFarm_House_Eventscript_Man_Declined
	checkmoney POKEMON_PRICE, 0
	compare VAR_RESULT, FALSE
	goto_if_eq OldaleFarm_House_EventScript_NotEnoughMoney
	removemoney POKEMON_PRICE, 0
	updatemoneybox 0, 0
	setvar VAR_TEMP_1, SPECIES_TORCHIC
	givemon SPECIES_TORCHIC, 5, ITEM_NONE
	call OldaleFarm_House_EventScript_ReceivedTorchicFanfare
	compare VAR_RESULT, 0
	goto_if_eq OldaleFarm_House_Eventscript_FinishReceivingPokemon
	compare VAR_RESULT, 1
	goto_if_eq OldaleFarm_House_EventScript_ReceivePokemonPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

OldaleFarm_House_Eventscript_PickMudkip::
	msgbox OldaleFarm_House_Text_AreYouSureYouWantMudkip, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq OldaleFarm_House_Eventscript_Man_Declined
	checkmoney POKEMON_PRICE, 0
	compare VAR_RESULT, FALSE
	goto_if_eq OldaleFarm_House_EventScript_NotEnoughMoney
	removemoney POKEMON_PRICE, 0
	updatemoneybox 0, 0
	setvar VAR_TEMP_1, SPECIES_MUDKIP
	givemon SPECIES_MUDKIP, 5, ITEM_NONE
	call OldaleFarm_House_EventScript_ReceivedMudkipFanfare
	compare VAR_RESULT, 0
	goto_if_eq OldaleFarm_House_Eventscript_FinishReceivingPokemon
	compare VAR_RESULT, 1
	goto_if_eq OldaleFarm_House_EventScript_ReceivePokemonPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

OldaleFarm_House_Eventscript_PickBulbasaur::
	msgbox OldaleFarm_House_Text_AreYouSureYouWantBulbasaur, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq OldaleFarm_House_Eventscript_Man_Declined
	checkmoney POKEMON_PRICE, 0
	compare VAR_RESULT, FALSE
	goto_if_eq OldaleFarm_House_EventScript_NotEnoughMoney
	removemoney POKEMON_PRICE, 0
	updatemoneybox 0, 0
	setvar VAR_TEMP_1, SPECIES_BULBASAUR
	givemon SPECIES_BULBASAUR, 5, ITEM_NONE
	call OldaleFarm_House_EventScript_ReceivedBulbasaurFanfare
	compare VAR_RESULT, 0
	goto_if_eq OldaleFarm_House_Eventscript_FinishReceivingPokemon
	compare VAR_RESULT, 1
	goto_if_eq OldaleFarm_House_EventScript_ReceivePokemonPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

OldaleFarm_House_Eventscript_PickCharmander::
	msgbox OldaleFarm_House_Text_AreYouSureYouWantCharmander, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq OldaleFarm_House_Eventscript_Man_Declined
	checkmoney POKEMON_PRICE, 0
	compare VAR_RESULT, FALSE
	goto_if_eq OldaleFarm_House_EventScript_NotEnoughMoney
	removemoney POKEMON_PRICE, 0
	updatemoneybox 0, 0
	setvar VAR_TEMP_1, SPECIES_CHARMANDER
	givemon SPECIES_CHARMANDER, 5, ITEM_NONE
	call OldaleFarm_House_EventScript_ReceivedCharmanderFanfare
	compare VAR_RESULT, 0
	goto_if_eq OldaleFarm_House_Eventscript_FinishReceivingPokemon
	compare VAR_RESULT, 1
	goto_if_eq OldaleFarm_House_EventScript_ReceivePokemonPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

OldaleFarm_House_Eventscript_PickSquirtle::
	msgbox OldaleFarm_House_Text_AreYouSureYouWantSquirtle, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq OldaleFarm_House_Eventscript_Man_Declined
	checkmoney POKEMON_PRICE, 0
	compare VAR_RESULT, FALSE
	goto_if_eq OldaleFarm_House_EventScript_NotEnoughMoney
	removemoney POKEMON_PRICE, 0
	updatemoneybox 0, 0
	setvar VAR_TEMP_1, SPECIES_SQUIRTLE
	givemon SPECIES_SQUIRTLE, 5, ITEM_NONE
	call OldaleFarm_House_EventScript_ReceivedSquirtleFanfare
	compare VAR_RESULT, 0
	goto_if_eq OldaleFarm_House_Eventscript_FinishReceivingPokemon
	compare VAR_RESULT, 1
	goto_if_eq OldaleFarm_House_EventScript_ReceivePokemonPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

OldaleFarm_House_Eventscript_PickChikorita::
	msgbox OldaleFarm_House_Text_AreYouSureYouWantChikorita, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq OldaleFarm_House_Eventscript_Man_Declined
	checkmoney POKEMON_PRICE, 0
	compare VAR_RESULT, FALSE
	goto_if_eq OldaleFarm_House_EventScript_NotEnoughMoney
	removemoney POKEMON_PRICE, 0
	updatemoneybox 0, 0
	setvar VAR_TEMP_1, SPECIES_CHIKORITA
	givemon SPECIES_CHIKORITA, 5, ITEM_NONE
	call OldaleFarm_House_EventScript_ReceivedChikoritaFanfare
	compare VAR_RESULT, 0
	goto_if_eq OldaleFarm_House_Eventscript_FinishReceivingPokemon
	compare VAR_RESULT, 1
	goto_if_eq OldaleFarm_House_EventScript_ReceivePokemonPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

OldaleFarm_House_Eventscript_PickCyndaquil::
	msgbox OldaleFarm_House_Text_AreYouSureYouWantCyndaquil, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq OldaleFarm_House_Eventscript_Man_Declined
	checkmoney POKEMON_PRICE, 0
	compare VAR_RESULT, FALSE
	goto_if_eq OldaleFarm_House_EventScript_NotEnoughMoney
	removemoney POKEMON_PRICE, 0
	updatemoneybox 0, 0
	setvar VAR_TEMP_1, SPECIES_CYNDAQUIL
	givemon SPECIES_CYNDAQUIL, 5, ITEM_NONE
	call OldaleFarm_House_EventScript_ReceivedCyndaquilFanfare
	compare VAR_RESULT, 0
	goto_if_eq OldaleFarm_House_Eventscript_FinishReceivingPokemon
	compare VAR_RESULT, 1
	goto_if_eq OldaleFarm_House_EventScript_ReceivePokemonPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

OldaleFarm_House_Eventscript_PickTotodile::
	msgbox OldaleFarm_House_Text_AreYouSureYouWantTotodile, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq OldaleFarm_House_Eventscript_Man_Declined
	checkmoney POKEMON_PRICE, 0
	compare VAR_RESULT, FALSE
	goto_if_eq OldaleFarm_House_EventScript_NotEnoughMoney
	removemoney POKEMON_PRICE, 0
	updatemoneybox 0, 0
	setvar VAR_TEMP_1, SPECIES_TOTODILE
	givemon SPECIES_TOTODILE, 5, ITEM_NONE
	call OldaleFarm_House_EventScript_ReceivedTotodileFanfare
	compare VAR_RESULT, 0
	goto_if_eq OldaleFarm_House_Eventscript_FinishReceivingPokemon
	compare VAR_RESULT, 1
	goto_if_eq OldaleFarm_House_EventScript_ReceivePokemonPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

OldaleFarm_House_EventScript_ReceivedTreeckoFanfare::
	bufferspeciesname 1, SPECIES_TREECKO
	playfanfare MUS_OBTAIN_ITEM
	message OldaleFarm_House_Text_ReceivedMon
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_TREECKO
	return

OldaleFarm_House_EventScript_ReceivedTorchicFanfare::
	bufferspeciesname 1, SPECIES_TORCHIC
	playfanfare MUS_OBTAIN_ITEM
	message OldaleFarm_House_Text_ReceivedMon
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_TORCHIC
	return

OldaleFarm_House_EventScript_ReceivedMudkipFanfare::
	bufferspeciesname 1, SPECIES_MUDKIP
	playfanfare MUS_OBTAIN_ITEM
	message OldaleFarm_House_Text_ReceivedMon
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_MUDKIP
	return

OldaleFarm_House_EventScript_ReceivedBulbasaurFanfare::
	bufferspeciesname 1, SPECIES_BULBASAUR
	playfanfare MUS_OBTAIN_ITEM
	message OldaleFarm_House_Text_ReceivedMon
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_BULBASAUR
	return

OldaleFarm_House_EventScript_ReceivedCharmanderFanfare::
	bufferspeciesname 1, SPECIES_CHARMANDER
	playfanfare MUS_OBTAIN_ITEM
	message OldaleFarm_House_Text_ReceivedMon
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_CHARMANDER
	return

OldaleFarm_House_EventScript_ReceivedSquirtleFanfare::
	bufferspeciesname 1, SPECIES_SQUIRTLE
	playfanfare MUS_OBTAIN_ITEM
	message OldaleFarm_House_Text_ReceivedMon
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_SQUIRTLE
	return

OldaleFarm_House_EventScript_ReceivedChikoritaFanfare::
	bufferspeciesname 1, SPECIES_CHIKORITA
	playfanfare MUS_OBTAIN_ITEM
	message OldaleFarm_House_Text_ReceivedMon
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_CHIKORITA
	return

OldaleFarm_House_EventScript_ReceivedCyndaquilFanfare::
	bufferspeciesname 1, SPECIES_CYNDAQUIL
	playfanfare MUS_OBTAIN_ITEM
	message OldaleFarm_House_Text_ReceivedMon
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_CYNDAQUIL
	return

OldaleFarm_House_EventScript_ReceivedTotodileFanfare::
	bufferspeciesname 1, SPECIES_TOTODILE
	playfanfare MUS_OBTAIN_ITEM
	message OldaleFarm_House_Text_ReceivedMon
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_TOTODILE
	return

OldaleFarm_House_EventScript_ReceivePokemonPC::
	call Common_EventScript_TransferredToPC
	goto OldaleFarm_House_Eventscript_FinishReceivingPokemon

OldaleFarm_House_Eventscript_FinishReceivingPokemon::
	hidemoneybox
	msgbox OldaleFarm_House_Text_Man_EnjoyThePokemon, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_DAILY_OLDALEFARM_POKEMON_GIVEN
	release
	end

OldaleFarm_House_Eventscript_Man_OnceADayService::
	msgbox OldaleFarm_House_Text_Man_OnceADayService, MSGBOX_DEFAULT
	closemessage
	release
	end

OldaleFarm_House_Eventscript_Man_Declined::
	hidemoneybox
	msgbox OldaleFarm_House_Text_Man_Declined, MSGBOX_DEFAULT
	closemessage
	release
	end

OldaleFarm_House_EventScript_NotEnoughMoney::
	hidemoneybox
	msgbox OldaleFarm_House_Text_Man_NotEnoughMoney, MSGBOX_DEFAULT
	closemessage
	release
	end

OldaleFarm_House_Text_Man:
	.string "We breed and raise very particular kinds\n"
	.string "of Pokémon here.\p"
	.string "If you want one, our waiting list is\n"
	.string "long. It'll be some time before you get\l"
	.string "your hands on 'em.$"

OldaleFarm_House_Text_Man_OnceADayService:
	.string "Come back another day and I will have\n"
	.string "more Pokémon ready to offer you.$"

OldaleFarm_House_Text_Man_AskIfBuying:
	.string "Greetings, Champion.\p"
	.string "I can afford to sell you a Pokémon\n"
	.string "straight away for today at ¥50,000.\p"
	.string "Are you here to buy?$"

OldaleFarm_House_Text_Man_ChoosePokemon:
	.string "Which Pokémon would you like?$"

OldaleFarm_House_Text_AreYouSureYouWantTreecko:
	.string "Are you sure you want the grass type\n"
	.string "Pokémon, Treecko?$"

OldaleFarm_House_Text_AreYouSureYouWantTorchic:
	.string "Are you sure you want the fire type\n"
	.string "Pokémon, Torchic?$"

OldaleFarm_House_Text_AreYouSureYouWantMudkip:
	.string "Are you sure you want the water type\n"
	.string "Pokémon, Mudkip?$"

OldaleFarm_House_Text_AreYouSureYouWantBulbasaur:
	.string "Are you sure you want the grass type\n"
	.string "Pokémon, Bulbasaur?$"

OldaleFarm_House_Text_AreYouSureYouWantCharmander:
	.string "Are you sure you want the fire type\n"
	.string "Pokémon, Charmander?$"

OldaleFarm_House_Text_AreYouSureYouWantSquirtle:
	.string "Are you sure you want the water type\n"
	.string "Pokémon, Squirtle?$"

OldaleFarm_House_Text_AreYouSureYouWantChikorita:
	.string "Are you sure you want the grass type\n"
	.string "Pokémon, Chikorita?$"

OldaleFarm_House_Text_AreYouSureYouWantCyndaquil:
	.string "Are you sure you want the fire type\n"
	.string "Pokémon, Cyndaquil?$"

OldaleFarm_House_Text_AreYouSureYouWantTotodile:
	.string "Are you sure you want the water type\n"
	.string "Pokémon, Totodile?$"

OldaleFarm_House_Text_ReceivedMon:
	.string "{PLAYER} received {STR_VAR_2} from\n"
	.string "the farmer.$"

OldaleFarm_House_Text_Man_Declined:
	.string "Come along again if you change your mind.$"

OldaleFarm_House_Text_Man_NotEnoughMoney:
	.string "You don't have enough money.$"

OldaleFarm_House_Text_Man_EnjoyThePokemon:
	.string "Please take good care of it.$"
