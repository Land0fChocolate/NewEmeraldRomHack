.set LOCALID_NURSE, 1

SootopolisCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SootopolisCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_SOOTOPOLIS_CITY
	end

SootopolisCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_Gentleman::
	lock
	faceplayer
	compare VAR_SKY_PILLAR_STATE, 2
	goto_if_ge SootopolisCity_PokemonCenter_1F_EventScript_GentlemanNoLegendaries
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_PokemonCenter_1F_EventScript_GentlemanNoLegendaries
	msgbox SootopolisCity_PokemonCenter_1F_Text_EveryoneTakenRefuge, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_GentlemanNoLegendaries::
	msgbox SootopolisCity_PokemonCenter_1F_Text_WallaceMentor, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_Woman::
	lock
	faceplayer
	compare VAR_SKY_PILLAR_STATE, 2
	goto_if_ge SootopolisCity_PokemonCenter_1F_EventScript_WomanNoLegendaries
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_PokemonCenter_1F_EventScript_WomanNoLegendaries
	msgbox SootopolisCity_PokemonCenter_1F_Text_ArentPokemonOurFriends, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_WomanNoLegendaries::
	msgbox SootopolisCity_PokemonCenter_1F_Text_AlwaysBeFriendsWithPokemon, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_MauvilleOldManTrader::
	setvar VAR_MAUVILLE_MAN_VARIANT, 2
	goto MauvilleCity_PokemonCenter_1F_EventScript_MauvilleOldMan
	end

SootopolisCity_PokemonCenter_1F_Text_WallaceMentor:
	.string "Wallace was taught by a man named Juan.\p"
	.string "Juan is somewhat like the mayor of this\n"
	.string "city, and a respectable Trainer and\l"
	.string "contest coordinator.$"

SootopolisCity_PokemonCenter_1F_Text_EveryoneTakenRefuge:
	.string "Everyone in town has taken refuge\n"
	.string "and won't come out of their homes.\p"
	.string "Even I would rather not venture\n"
	.string "outside.$"

SootopolisCity_PokemonCenter_1F_Text_AlwaysBeFriendsWithPokemon:
	.string "Whenever, wherever, and whatever\n"
	.string "happens, I will always be friends with\l"
	.string "Pokémon.\p"
	.string "Because it's fun to be with Pokémon!$"

SootopolisCity_PokemonCenter_1F_Text_ArentPokemonOurFriends:
	.string "Aren't Pokémon our friends?\p"
	.string "Why are they going wild this way?$"

