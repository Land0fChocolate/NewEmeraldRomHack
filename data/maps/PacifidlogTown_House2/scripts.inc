PacifidlogTown_House2_MapScripts::
	.byte 0

PacifidlogTown_House2_EventScript_FanClubYoungerBrother::
	lock
	faceplayer
	call_if_set FLAG_MET_FANCLUB_YOUNGER_BROTHER, PacifidlogTown_House2_EventScript_MonAssessment
	call_if_unset FLAG_MET_FANCLUB_YOUNGER_BROTHER, PacifidlogTown_House2_EventScript_FirstMonAssessment
	setflag FLAG_MET_FANCLUB_YOUNGER_BROTHER
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	compare VAR_RESULT, 4
	goto_if_ge PacifidlogTown_House2_EventScript_GiveReturn
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	compare VAR_RESULT, 2
	goto_if_ge PacifidlogTown_House2_EventScript_PutInEffort
	goto PacifidlogTown_House2_EventScript_GiveFrustration
	end

PacifidlogTown_House2_EventScript_MonAssessment::
	msgbox PacifidlogTown_House2_Text_AhYourPokemon, MSGBOX_DEFAULT
	return

PacifidlogTown_House2_EventScript_FirstMonAssessment::
	msgbox PacifidlogTown_House2_Text_ChairmansYoungerBrotherOnVacation, MSGBOX_DEFAULT
	msgbox PacifidlogTown_House2_Text_AhYourPokemon, MSGBOX_DEFAULT
	return

PacifidlogTown_House2_EventScript_GiveReturn::
	goto_if_set FLAG_RECEIVED_TM_27_RETURN, PacifidlogTown_House2_EventScript_AdoringPokemon
	msgbox PacifidlogTown_House2_Text_AdoringPokemonTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM27
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_27_RETURN
	msgbox PacifidlogTown_House2_Text_ExplainReturnFrustration, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_AdoringPokemon::
	msgbox PacifidlogTown_House2_Text_AdoringPokemon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_PutInEffort::
	msgbox PacifidlogTown_House2_Text_PutInSomeMoreEffort, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_GiveFrustration::
	goto_if_set FLAG_RECEIVED_TM_21_FRUSTRATION, PacifidlogTown_House2_EventScript_ViciousPokemon
	msgbox PacifidlogTown_House2_Text_ViciousPokemonTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM21
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_21_FRUSTRATION
	msgbox PacifidlogTown_House2_Text_ExplainReturnFrustration, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_ViciousPokemon::
	msgbox PacifidlogTown_House2_Text_ViciousPokemon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_ComeBackInXDays::
	specialvar VAR_RESULT, GetDaysUntilPacifidlogTMAvailable
	buffernumberstring 0, VAR_RESULT
	msgbox PacifidlogTown_House2_Text_GetGoodTMInXDays, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_HappyAzurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, 0
	waitmoncry
	msgbox PacifidlogTown_House2_Text_VeryFriendlyWithTrainer, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_UnhappyAzurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, 2
	waitmoncry
	msgbox PacifidlogTown_House2_Text_DoesntLikeTrainerVeryMuch, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_Text_ChairmansYoungerBrotherOnVacation:
	.string "Er-hem!\p"
	.string "I am the Pokémon Fan Club's most\n"
	.string "important person, the Chairman's\l"
	.string "younger brother.\p"
	.string "I'm here enjoying my vacation with\n"
	.string "Pokémon, yes, indeed.$"

PacifidlogTown_House2_Text_AhYourPokemon:
	.string "Ah!\n"
	.string "Your Pokémon…$"

PacifidlogTown_House2_Text_AdoringPokemonTakeThis:
	.string "It clearly likes you very much.\p"
	.string "A Pokémon that adoring and adorable\n"
	.string "deserves a TM like this, no?$"

PacifidlogTown_House2_Text_AdoringPokemon:
	.string "It clearly likes you very much.\n"
	.string "You have taken great care in raising\l"
	.string "this Pokémon.$"

PacifidlogTown_House2_Text_PutInSomeMoreEffort:
	.string "Hmm…\n"
	.string "It's not bad, but it's also not good.\p"
	.string "You, as the Trainer, need to put in\n"
	.string "some more effort.$"

PacifidlogTown_House2_Text_ViciousPokemonTakeThis:
	.string "It has a vicious look to it.\p"
	.string "A frightening Pokémon like that\n"
	.string "deserves a TM like this.$"

PacifidlogTown_House2_Text_ViciousPokemon:
	.string "It has a vicious look to it.\n"
	.string "Your contempt in raising it has made\l"
	.string "it furious.$"

PacifidlogTown_House2_Text_ExplainReturnFrustration:
	.string "If a Pokémon likes you a lot, Return's\n"
	.string "power is enhanced.\p"
	.string "If it doesn't like you, Frustration's\n"
	.string "power goes up.$"

PacifidlogTown_House2_Text_GetGoodTMInXDays:
	.string "Oh, yes. In about {STR_VAR_1} or so days,\n"
	.string "I should be getting a good TM or two.\p"
	.string "You should come see me then.\n"
	.string "I'll give you a TM that's suitable for\l"
	.string "your Pokémon.$"

PacifidlogTown_House2_Text_VeryFriendlyWithTrainer:
	.string "It appears to be very friendly with the\n"
	.string "Trainer.$"

PacifidlogTown_House2_Text_DoesntLikeTrainerVeryMuch:
	.string "It doesn't appear to like the Trainer\n"
	.string "very much.$"

