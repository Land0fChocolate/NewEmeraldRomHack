MauvilleCity_GroomerHouse_MapScripts::
	.byte 0

MauvilleCity_GroomerHouse_EventScript_Girl::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_GROOM_DONE, MauvilleCity_GroomerHouse_EventScript_GirlOnceADayService
	msgbox MauvilleCity_GroomerHouse_Text_GirlAskToGroom, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_GroomerHouse_EventScript_GirlDeclined
	msgbox MauvilleCity_GroomerHouse_Text_GirlChoosePokemon, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq MauvilleCity_GroomerHouse_EventScript_GirlDeclined
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq MauvilleCity_GroomerHouse_EventScript_GirlCantGroomEgg
	msgbox MauvilleCity_GroomerHouse_Text_GirlMakeItLookNice, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special GroomPokemon
	fadescreen FADE_FROM_BLACK
	special BufferMonNickname
	msgbox MauvilleCity_GroomerHouse_Text_GirlDoneGrooming, MSGBOX_DEFAULT
	setflag FLAG_DAILY_GROOM_DONE
	release
	end

MauvilleCity_GroomerHouse_EventScript_GirlDeclined::
	msgbox MauvilleCity_GroomerHouse_Text_GirlDeclined, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GroomerHouse_EventScript_GirlCantGroomEgg::
	msgbox MauvilleCity_GroomerHouse_Text_GirlCantGroomEgg, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GroomerHouse_EventScript_GirlOnceADayService::
	msgbox MauvilleCity_GroomerHouse_Text_GirlOnceADayService, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GroomerHouse_Text_GirlAskToGroom:
	.string "Salutations, trainer!\p"
	.string "Have you come to let me massage and\n"
	.string "groom your Pokémon?$"

MauvilleCity_GroomerHouse_Text_GirlDeclined:
	.string "Oh, well. Come back another time.$"

MauvilleCity_GroomerHouse_Text_GirlChoosePokemon:
	.string "Which Pokémon shall I groom?$"

MauvilleCity_GroomerHouse_Text_GirlCantGroomEgg:
	.string "That's a lovely egg you have there,\n"
	.string "but I can't groom it!$"

MauvilleCity_GroomerHouse_Text_GirlMakeItLookNice:
	.string "Oh, yes. Let's make this fine specimen\n"
	.string "look splendiferous!$"

MauvilleCity_GroomerHouse_Text_GirlDoneGrooming:
	.string "There. All done!\p"
	.string "Your {STR_VAR_1}'s coat is\n"
	.string "looking nice and glossy!\l"
	.string "It's even liking you a little more.\p"
	.string "Come back tomorrow and I'll give your\n"
	.string "Pokémon more treatment.$"

MauvilleCity_GroomerHouse_Text_GirlOnceADayService:
	.string "Sorry, I can only perform my grooming\n"
	.string "services once a day.\l"
	.string "Come back tomorrow.$"
