OldaleFarm_House_MapScripts::
	.byte 0

OldaleFarm_House_Eventscript_Man::
	goto_if_set FLAG_SYS_GAME_CLEAR, OldaleFarm_House_Eventscript_Man_PlayerIsChampion
	msgbox OldaleFarm_House_Text_Man, MSGBOX_NPC
	end

OldaleFarm_House_Eventscript_Man_PlayerIsChampion::
	dotimebasedevents
	goto_if_set FLAG_DAILY_OLDALEFARM_POKEMON_GIVEN, OldaleFarm_House_Eventscript_Man_OnceADayService
	msgbox OldaleFarm_House_Text_Man_AskIfBuying, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq OldaleFarm_House_Eventscript_Man_Declined
	msgbox OldaleFarm_House_Text_Man_ChoosePokemon, MSGBOX_DEFAULT
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
	goto_if_ge OldaleFarm_House_Eventscript_Man_PickAllStarters
	checkflag FLAG_SYS_NATIONAL_DEX
	goto_if TRUE, OldaleFarm_House_Eventscript_Man_PickHoennKantoStarters
	end

OldaleFarm_House_Eventscript_Man_PickHoennKantoStarters:: @TODO:
	end

OldaleFarm_House_Eventscript_Man_PickAllStarters:: @TODO:
	end

OldaleFarm_House_Eventscript_Man_OnceADayService::
	msgbox OldaleFarm_House_Text_Man_OnceADayService, MSGBOX_NPC
	end

OldaleFarm_House_Eventscript_Man_Declined::
	msgbox OldaleFarm_House_Text_Man_Declined, MSGBOX_NPC
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
	.string "straight away for today.\p"
	.string "Are you here to buy?$"

OldaleFarm_House_Text_Man_ChoosePokemon:
	.string "Which Pokémon would you like?$"

OldaleFarm_House_Text_Man_Declined:
	.string "Come along again if you change your mind.$"
