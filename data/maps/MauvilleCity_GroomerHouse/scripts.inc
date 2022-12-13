MauvilleCity_GroomerHouse_MapScripts::
	.byte 0

MauvilleCity_GroomerHouse_EventScript_Meteorite::
	msgbox MauvilleCity_GroomerHouse_Text_ItsAMeteorite, MSGBOX_SIGN
	closemessage
	checkformoninparty SPECIES_DEOXYS_ATTACK
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_GroomerHouse_EventScript_ChangeDeoxysForm
	checkformoninparty SPECIES_DEOXYS_DEFENSE
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_GroomerHouse_EventScript_ChangeDeoxysForm
	checkformoninparty SPECIES_DEOXYS_SPEED
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_GroomerHouse_EventScript_ChangeDeoxysForm
	end

MauvilleCity_GroomerHouse_EventScript_ChangeDeoxysForm::
	changedeoxysform 0
	playmoncry SPECIES_DEOXYS, 0
	waitse
	msgbox MauvilleCity_GroomerHouse_Text_DeoxysChangedForm, MSGBOX_SIGN
	end

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
	.string "looking gorgeous and glossy!\l"
	.string "It's even become more fond of you.\p"
	.string "Return tomorrow and I shall give your\n"
	.string "Pokémon additional treatment.$"

MauvilleCity_GroomerHouse_Text_GirlOnceADayService:
	.string "It is my regret to inform you that I\n"
	.string "can only perform my grooming services\l"
	.string "once a day.\p"
	.string "Please, come back tomorrow.$"

MauvilleCity_GroomerHouse_Text_ItsAMeteorite:
	.string "It's the meteorite that the Pokémon\n"
	.string "groomer picked up. You feel a\l"
	.string "radiating warmth coming from it.$"

MauvilleCity_GroomerHouse_Text_DeoxysChangedForm:
	.string "The Deoxys in your party changed into\n"
	.string "a more balanced form!$"
