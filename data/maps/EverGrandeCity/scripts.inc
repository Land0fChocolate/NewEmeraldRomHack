.set LOCALID_MEDICHAM, 1
.set LOCALID_LUDICOLO, 2

EverGrandeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_OnTransition
	.byte 0

EverGrandeCity_OnTransition:
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

EverGrandeCity_EventScript_VictoryRoadSign::
	msgbox EverGrandeCity_Text_EnteringVictoryRoad, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_CitySign::
	msgbox EverGrandeCity_Text_CitySign, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_PokemonLeagueSign::
	msgbox EverGrandeCity_Text_EnteringPokemonLeague, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_SetVisitedEverGrande::
	setflag FLAG_VISITED_EVER_GRANDE_CITY
	setvar VAR_TEMP_1, 1
	end

@this stuff is kept around for testing
EverGrandeCity_EventScript_TestAbra1::
	faceplayer
	cleartrainerflag TRAINER_LEAF
	trainerbattle_single TRAINER_LEAF, EverGrandeCity_Text_LeafIntro, EverGrandeCity_Text_LeafDefeated
	end

EverGrandeCity_EventScript_TestAbra2::
	faceplayer
	msgbox EverGrandeCity_Text_LeafPostBattle, MSGBOX_NPC
	@giveitem ITEM_RARE_CANDY, 99
	givemon SPECIES_BULBASAUR, 10, ITEM_NONE
	givemon SPECIES_CHARMANDER, 10, ITEM_NONE
	givemon SPECIES_SQUIRTLE, 10, ITEM_NONE
	givemon SPECIES_PIKACHU, 10, ITEM_NONE
	givemon SPECIES_EEVEE, 10, ITEM_NONE
	closemessage
	end

EverGrandeCity_Text_FlagIsSet:
	.string "Cozmo house meteorite flag is set"

EverGrandeCity_Text_LeafIntro:
	.string "Hello, I'm here for testing!$"

EverGrandeCity_Text_LeafDefeated:
	.string "Test end!$"

EverGrandeCity_Text_LeafPostBattle:
	.string "I'm here for testing!\n"
	.string "Remove me!$"

    @{
    @  "graphics_id": "OBJ_EVENT_GFX_ABRA",
    @  "x": 30,
    @  "y": 49,
    @  "elevation": 3,
    @  "movement_type": "MOVEMENT_TYPE_NONE",
    @  "movement_range_x": 0,
    @  "movement_range_y": 0,
    @  "trainer_type": "TRAINER_TYPE_NONE",
    @  "trainer_sight_or_berry_tree_id": "0",
    @  "script": "EverGrandeCity_EventScript_TestAbra1",
    @  "flag": "0"
    @}

EverGrandeCity_EventScript_WomanInBattle::
	locktarget
	msgbox EverGrandeCity_Text_WomanInBattle, MSGBOX_SIGN
	waitse
	playmoncry SPECIES_MEDICHAM, 0
	waitmoncry
	playse SE_EFFECTIVE
	applymovement LOCALID_MEDICHAM, EverGrandeCity_Movement_MedichamAttacks
	waitmovement 0
	applymovement LOCALID_MEDICHAM, EverGrandeCity_Movement_MedichamMovesBack
	waitmovement 0
	release
	end

EverGrandeCity_Movement_MedichamAttacks::
	walk_fast_right
	walk_fast_right
	step_end

EverGrandeCity_Movement_MedichamMovesBack::
	lock_facing_direction
	walk_left
	walk_left
	step_end

EverGrandeCity_EventScript_ManInBattle::
	locktarget
	msgbox EverGrandeCity_Text_ManInBattle, MSGBOX_SIGN
	waitse
	playmoncry SPECIES_LUDICOLO, 0
	waitmoncry
	playse SE_EFFECTIVE
	applymovement LOCALID_LUDICOLO, EverGrandeCity_Movement_LudicoloAttacks
	waitmovement 0
	applymovement LOCALID_LUDICOLO, EverGrandeCity_Movement_LudicoloMovesBack
	waitmovement 0
	release
	end

EverGrandeCity_Movement_LudicoloAttacks::
	walk_fast_left
	walk_fast_left
	step_end

EverGrandeCity_Movement_LudicoloMovesBack::
	lock_facing_direction
	walk_right
	walk_right
	step_end

EverGrandeCity_EventScript_BattleGirl::
	msgbox EverGrandeCity_Text_BattleGirl, MSGBOX_NPC
	end

EverGrandeCity_EventScript_ExpertM::
	msgbox EverGrandeCity_Text_ExpertM, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_HexManiac::
	msgbox EverGrandeCity_Text_HexManiac, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_Man::
	msgbox EverGrandeCity_Text_Man, MSGBOX_NPC
	end

EverGrandeCity_EventScript_Triathlete::
	msgbox EverGrandeCity_Text_Triathlete, MSGBOX_NPC
	end

EverGrandeCity_EventScript_Scott::
	msgbox EverGrandeCity_Text_Scott, MSGBOX_NPC
	end

EverGrandeCity_Text_EnteringVictoryRoad:
	.string "ENTERING VICTORY ROAD$"

EverGrandeCity_Text_EnteringPokemonLeague:
	.string "ENTERING POKéMON LEAGUE\n"
	.string "CENTER GATE$"

EverGrandeCity_Text_CitySign:
	.string "EVER GRANDE CITY\p"
	.string "“The paradise of flowers, the sea,\n"
	.string "and Pokémon.”$"

EverGrandeCity_Text_WomanInBattle:
	.string "Medicham, strike it with a\n"
	.string "High Jump Kick!$"

EverGrandeCity_Text_ManInBattle:
	.string "We still got this.\n"
	.string "Use Waterfall, Ludicolo!$"

EverGrandeCity_Text_BattleGirl:
	.string "Ooh, boy. The trainers here are tougher\n"
	.string "than I expected.\l"
	.string "I've got a lot of catching up to do!$"

EverGrandeCity_Text_ExpertM:
	.string "Yes, that's it!\n"
	.string "Go my protégé, you have this battle\l"
	.string "in the bag!$"

EverGrandeCity_Text_HexManiac:
	.string "Fufufufufu…\p"
	.string "That man… something about the way he\n"
	.string "battles… I should make him mine!$"

EverGrandeCity_Text_Man:
	.string "We get people coming in from all over\n"
	.string "to test their Pokémon here.\l"
	.string "The city practically never sleeps.$"

EverGrandeCity_Text_Triathlete:
	.string "It might be fun to jump into the sea\n"
	.string "from here, but it won't be fun hitting\l"
	.string "the rocks at the bottom.\p"
	.string "I should probably try a safer jump\n"
	.string "someplace else first.$"

EverGrandeCity_Text_Scott:
	.string "Scott: Hi, hi {PLAYER}!\n"
	.string "Good to see you've made it all the way\l"
	.string "to Ever Grande City!\p"
	.string "Strong trainers from all over gather\n"
	.string "here to face off against the Pokémon\l"
	.string "League.\l"
	.string "Naturally, I come to observe them!\p"
	.string "Speaking of strong trainers, there was\n"
	.string "another kid. This one younger than you.\p"
	.string "He'd been making a stir around here.\n"
	.string "I wonder where he ran off to?$"
