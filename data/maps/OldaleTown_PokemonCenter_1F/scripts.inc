.set LOCALID_NURSE, 1

OldaleTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

OldaleTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_OLDALE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

OldaleTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Boy::
	msgbox OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable
	msgbox OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable::
	msgbox OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_ChooseOriginSlot::
	setvar VAR_0x8006, 0
	goto OldaleTown_PokemonCenter_1F_EventScript_ChooseMonMoveForOrigin
	end

OldaleTown_PokemonCenter_1F_EventScript_ChooseMonMoveForOrigin::
	msgbox OldaleTown_PokemonCenter_1F_Text_WhichMonForMove, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq OldaleTown_PokemonCenter_1F_EventScript_AnotherTimeThen
	special IsSelectedMonEgg
	compare VAR_RESULT, TRUE
	goto_if_eq OldaleTown_PokemonCenter_1F_EventScript_CantUseEgg
	msgbox OldaleTown_PokemonCenter_1F_Text_WhichMoveForOrigin, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special OriginChooseMove @moveslot set to VAR_0x8005?
	fadescreen FADE_FROM_BLACK
	special BufferMoveDeleterNicknameAndMove
	msgbox OldaleTown_PokemonCenter_1F_Text_SetThisAsOriginMove, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, OldaleTown_PokemonCenter_1F_EventScript_TrySetOriginMove
	case NO, OldaleTown_PokemonCenter_1F_EventScript_AnotherTimeThen
	releaseall
	end

OldaleTown_PokemonCenter_1F_EventScript_TrySetOriginMove::
	special SetOriginMove
	playfanfare MUS_OBTAIN_TMHM
	waitfanfare
	msgbox OldaleTown_PokemonCenter_1F_Text_MoveHasBeenSetForOrigin, MSGBOX_DEFAULT
	releaseall
	end

OldaleTown_PokemonCenter_1F_EventScript_CantUseEgg::
	msgbox OldaleTown_PokemonCenter_1F_Text_CantUseEgg, MSGBOX_DEFAULT
	releaseall
	end

OldaleTown_PokemonCenter_1F_EventScript_AnotherTimeThen::
	msgbox OldaleTown_PokemonCenter_1F_Text_AnotherTimeThen, MSGBOX_DEFAULT
	releaseall
	end

OldaleTown_PokemonCenter_1F_Text_WhichMonForMove:
	.string "Choose a Pokémon for an Origin move.$"

OldaleTown_PokemonCenter_1F_Text_WhichMoveForOrigin:
	.string "Which move to assign to Origin?$"

OldaleTown_PokemonCenter_1F_Text_SetThisAsOriginMove:
	.string "Assign {STR_VAR_2} to Origin?$"

OldaleTown_PokemonCenter_1F_Text_MoveHasBeenSetForOrigin:
	.string "{STR_VAR_2} has been set for Origin.$"

OldaleTown_PokemonCenter_1F_Text_CantUseEgg:
	.string "Egg has no moves. Cannot assign a\n"
	.string "move from an egg.$"

OldaleTown_PokemonCenter_1F_Text_AnotherTimeThen:
	.string "Another time then.$"

OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC:
	.string "That PC in the corner there is\n"
	.string "for any Pokémon Trainer to use.\p"
	.string "Naturally, that means you're welcome\n"
	.string "to use it, too.$"

OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat:
	.string "Pokémon Centers are great!\p"
	.string "You can use their services as much\n"
	.string "as you like, and it's all for free.\l"
	.string "You never have to worry!$"

OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable:
	.string "The Pokémon Wireless Club on\n"
	.string "the second floor was built recently.\p"
	.string "But they say they're still making\n"
	.string "adjustments.$"

OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub:
	.string "The Pokémon Wireless Club on\n"
	.string "the second floor was built recently.\p"
	.string "I traded Pokémon right away.$"

