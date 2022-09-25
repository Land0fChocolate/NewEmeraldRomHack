NavelRock_Hooh3_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, NavelRock_Hooh3_OnLoad
	.byte 0

NavelRock_Hooh3_OnLoad::
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_1, NavelRock_Hooh3_Eventscript_OpenDoor1
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_2, NavelRock_Hooh3_Eventscript_OpenDoor2
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_3, NavelRock_Hooh3_Eventscript_OpenDoor3
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_4, NavelRock_Hooh3_Eventscript_OpenDoor4
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_5, NavelRock_Hooh3_Eventscript_OpenDoor5
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_6, NavelRock_Hooh3_Eventscript_OpenDoor6
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_7, NavelRock_Hooh3_Eventscript_OpenDoor7
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_8, NavelRock_Hooh3_Eventscript_OpenDoor8
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_9, NavelRock_Hooh3_Eventscript_OpenDoor9
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_10, NavelRock_Hooh3_Eventscript_OpenDoor10
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_11, NavelRock_Hooh3_Eventscript_OpenDoor11
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_12, NavelRock_Hooh3_Eventscript_OpenDoor12
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_13, NavelRock_Hooh3_Eventscript_OpenDoor13
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_14, NavelRock_Hooh3_Eventscript_OpenDoor14
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_15, NavelRock_Hooh3_Eventscript_OpenDoor15
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_16, NavelRock_Hooh3_Eventscript_OpenDoor16
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_17, NavelRock_Hooh3_Eventscript_OpenDoor17
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_18, NavelRock_Hooh3_Eventscript_OpenDoor18
	call_if_set FLAG_NAVEL_ROCK_HOOH_PUZZLE_EXIT_1, NavelRock_Hooh3_Eventscript_OpenPuzzleExit1
	call_if_set FLAG_NAVEL_ROCK_HOOH_PUZZLE_EXIT_2, NavelRock_Hooh3_Eventscript_OpenPuzzleExit2
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_1, NavelRock_Hooh3_Eventscript_CloseDoor1
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_2, NavelRock_Hooh3_Eventscript_CloseDoor2
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_3, NavelRock_Hooh3_Eventscript_CloseDoor3
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_4, NavelRock_Hooh3_Eventscript_CloseDoor4
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_5, NavelRock_Hooh3_Eventscript_CloseDoor5
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_6, NavelRock_Hooh3_Eventscript_CloseDoor6
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_7, NavelRock_Hooh3_Eventscript_CloseDoor7
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_8, NavelRock_Hooh3_Eventscript_CloseDoor8
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_9, NavelRock_Hooh3_Eventscript_CloseDoor9
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_10, NavelRock_Hooh3_Eventscript_CloseDoor10
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_11, NavelRock_Hooh3_Eventscript_CloseDoor11
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_12, NavelRock_Hooh3_Eventscript_CloseDoor12
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_13, NavelRock_Hooh3_Eventscript_CloseDoor13
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_14, NavelRock_Hooh3_Eventscript_CloseDoor14
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_15, NavelRock_Hooh3_Eventscript_CloseDoor15
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_16, NavelRock_Hooh3_Eventscript_CloseDoor16
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_17, NavelRock_Hooh3_Eventscript_CloseDoor17
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_18, NavelRock_Hooh3_Eventscript_CloseDoor18
	call_if_unset FLAG_NAVEL_ROCK_HOOH_PUZZLE_EXIT_1, NavelRock_Hooh3_Eventscript_ClosePuzzleExit1
	call_if_unset FLAG_NAVEL_ROCK_HOOH_PUZZLE_EXIT_2, NavelRock_Hooh3_Eventscript_ClosePuzzleExit2
	end

NavelRock_Hooh3_Eventscript_OpenDoor1::
	setmetatile 18, 10, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 19, 10, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 18, 11, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 19, 11, METATILE_NavelRock_GoldCave_Floor, 0
	return

NavelRock_Hooh3_Eventscript_OpenDoor2::
	setmetatile 18, 14, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 19, 14, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 18, 15, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 19, 15, METATILE_NavelRock_GoldCave_Floor, 0
	return

NavelRock_Hooh3_Eventscript_OpenDoor3::
	setmetatile 18, 18, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 19, 18, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 18, 19, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 19, 19, METATILE_NavelRock_GoldCave_Floor, 0
	return

NavelRock_Hooh3_Eventscript_OpenDoor4::
	setmetatile 16, 12, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 17, 12, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 16, 13, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 17, 13, METATILE_NavelRock_GoldCave_Floor, 0
	return

NavelRock_Hooh3_Eventscript_OpenDoor5::
	setmetatile 16, 16, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 17, 16, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 16, 17, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 17, 17, METATILE_NavelRock_GoldCave_Floor, 0
	return

NavelRock_Hooh3_Eventscript_OpenDoor6::
	setmetatile 14, 10, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 15, 10, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 14, 11, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 15, 11, METATILE_NavelRock_GoldCave_Floor, 0
	return

NavelRock_Hooh3_Eventscript_OpenDoor7::
	setmetatile 14, 14, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 15, 14, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 14, 15, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 15, 15, METATILE_NavelRock_GoldCave_Floor, 0
	return

NavelRock_Hooh3_Eventscript_OpenDoor8::
	setmetatile 14, 18, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 15, 18, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 14, 19, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 15, 19, METATILE_NavelRock_GoldCave_Floor, 0
	return

NavelRock_Hooh3_Eventscript_OpenDoor9::
	setmetatile 12, 12, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 13, 12, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 12, 13, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 13, 13, METATILE_NavelRock_GoldCave_Floor, 0
	return

NavelRock_Hooh3_Eventscript_OpenDoor10::
	setmetatile 12, 16, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 13, 16, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 12, 17, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 13, 17, METATILE_NavelRock_GoldCave_Floor, 0
	return

NavelRock_Hooh3_Eventscript_OpenDoor11::
	setmetatile 10, 10, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 11, 10, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 10, 11, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 11, 11, METATILE_NavelRock_GoldCave_Floor, 0
	return

NavelRock_Hooh3_Eventscript_OpenDoor12::
	setmetatile 10, 14, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 11, 14, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 10, 15, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 11, 15, METATILE_NavelRock_GoldCave_Floor, 0
	return

NavelRock_Hooh3_Eventscript_OpenDoor13::
	setmetatile 10, 18, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 11, 18, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 10, 19, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 11, 19, METATILE_NavelRock_GoldCave_Floor, 0
	return

NavelRock_Hooh3_Eventscript_OpenDoor14::
	setmetatile 8, 12, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 9, 12, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 8, 13, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 9, 13, METATILE_NavelRock_GoldCave_Floor, 0
	return

NavelRock_Hooh3_Eventscript_OpenDoor15::
	setmetatile 8, 16, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 9, 16, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 8, 17, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 9, 17, METATILE_NavelRock_GoldCave_Floor, 0
	return

NavelRock_Hooh3_Eventscript_OpenDoor16::
	setmetatile 6, 10, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 7, 10, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 6, 11, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 7, 11, METATILE_NavelRock_GoldCave_Floor, 0
	return

NavelRock_Hooh3_Eventscript_OpenDoor17::
	setmetatile 6, 14, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 7, 14, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 6, 15, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 7, 15, METATILE_NavelRock_GoldCave_Floor, 0
	return

NavelRock_Hooh3_Eventscript_OpenDoor18::
	setmetatile 6, 18, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 7, 18, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 6, 19, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 7, 19, METATILE_NavelRock_GoldCave_Floor, 0
	return

NavelRock_Hooh3_Eventscript_CloseDoor1::
	setmetatile 18, 10, METATILE_NavelRock_GoldCave_BrownWall_TopLeft, 1
	setmetatile 19, 10, METATILE_NavelRock_GoldCave_BrownWall_TopRight, 1
	setmetatile 18, 11, METATILE_NavelRock_GoldCave_BrownWall_BotLeft, 1
	setmetatile 19, 11, METATILE_NavelRock_GoldCave_BrownWall_BotRight, 1
	return

NavelRock_Hooh3_Eventscript_CloseDoor2::
	setmetatile 18, 14, METATILE_NavelRock_GoldCave_BrownWall_TopLeft, 1
	setmetatile 19, 14, METATILE_NavelRock_GoldCave_BrownWall_TopRight, 1
	setmetatile 18, 15, METATILE_NavelRock_GoldCave_BrownWall_BotLeft, 1
	setmetatile 19, 15, METATILE_NavelRock_GoldCave_BrownWall_BotRight, 1
	return

NavelRock_Hooh3_Eventscript_CloseDoor3::
	setmetatile 18, 18, METATILE_NavelRock_GoldCave_BrownWall_TopLeft, 1
	setmetatile 19, 18, METATILE_NavelRock_GoldCave_BrownWall_TopRight, 1
	setmetatile 18, 19, METATILE_NavelRock_GoldCave_BrownWall_BotLeft, 1
	setmetatile 19, 19, METATILE_NavelRock_GoldCave_BrownWall_BotRight, 1
	return

NavelRock_Hooh3_Eventscript_CloseDoor4::
	setmetatile 16, 12, METATILE_NavelRock_GoldCave_BrownWall_TopLeft, 1
	setmetatile 17, 12, METATILE_NavelRock_GoldCave_BrownWall_TopRight, 1
	setmetatile 16, 13, METATILE_NavelRock_GoldCave_BrownWall_BotLeft, 1
	setmetatile 17, 13, METATILE_NavelRock_GoldCave_BrownWall_BotRight, 1
	return

NavelRock_Hooh3_Eventscript_CloseDoor5::
	setmetatile 16, 16, METATILE_NavelRock_GoldCave_BrownWall_TopLeft, 1
	setmetatile 17, 16, METATILE_NavelRock_GoldCave_BrownWall_TopRight, 1
	setmetatile 16, 17, METATILE_NavelRock_GoldCave_BrownWall_BotLeft, 1
	setmetatile 17, 17, METATILE_NavelRock_GoldCave_BrownWall_BotRight, 1
	return

NavelRock_Hooh3_Eventscript_CloseDoor6::
	setmetatile 14, 10, METATILE_NavelRock_GoldCave_BrownWall_TopLeft, 1
	setmetatile 15, 10, METATILE_NavelRock_GoldCave_BrownWall_TopRight, 1
	setmetatile 14, 11, METATILE_NavelRock_GoldCave_BrownWall_BotLeft, 1
	setmetatile 15, 11, METATILE_NavelRock_GoldCave_BrownWall_BotRight, 1
	return

NavelRock_Hooh3_Eventscript_CloseDoor7::
	setmetatile 14, 14, METATILE_NavelRock_GoldCave_BrownWall_TopLeft, 1
	setmetatile 15, 14, METATILE_NavelRock_GoldCave_BrownWall_TopRight, 1
	setmetatile 14, 15, METATILE_NavelRock_GoldCave_BrownWall_BotLeft, 1
	setmetatile 15, 15, METATILE_NavelRock_GoldCave_BrownWall_BotRight, 1
	return

NavelRock_Hooh3_Eventscript_CloseDoor8::
	setmetatile 14, 18, METATILE_NavelRock_GoldCave_BrownWall_TopLeft, 1
	setmetatile 15, 18, METATILE_NavelRock_GoldCave_BrownWall_TopRight, 1
	setmetatile 14, 19, METATILE_NavelRock_GoldCave_BrownWall_BotLeft, 1
	setmetatile 15, 19, METATILE_NavelRock_GoldCave_BrownWall_BotRight, 1
	return

NavelRock_Hooh3_Eventscript_CloseDoor9::
	setmetatile 12, 12, METATILE_NavelRock_GoldCave_BrownWall_TopLeft, 1
	setmetatile 13, 12, METATILE_NavelRock_GoldCave_BrownWall_TopRight, 1
	setmetatile 12, 13, METATILE_NavelRock_GoldCave_BrownWall_BotLeft, 1
	setmetatile 13, 13, METATILE_NavelRock_GoldCave_BrownWall_BotRight, 1
	return

NavelRock_Hooh3_Eventscript_CloseDoor10::
	setmetatile 12, 16, METATILE_NavelRock_GoldCave_BrownWall_TopLeft, 1
	setmetatile 13, 16, METATILE_NavelRock_GoldCave_BrownWall_TopRight, 1
	setmetatile 12, 17, METATILE_NavelRock_GoldCave_BrownWall_BotLeft, 1
	setmetatile 13, 17, METATILE_NavelRock_GoldCave_BrownWall_BotRight, 1
	return

NavelRock_Hooh3_Eventscript_CloseDoor11::
	setmetatile 10, 10, METATILE_NavelRock_GoldCave_BrownWall_TopLeft, 1
	setmetatile 11, 10, METATILE_NavelRock_GoldCave_BrownWall_TopRight, 1
	setmetatile 10, 11, METATILE_NavelRock_GoldCave_BrownWall_BotLeft, 1
	setmetatile 11, 11, METATILE_NavelRock_GoldCave_BrownWall_BotRight, 1
	return

NavelRock_Hooh3_Eventscript_CloseDoor12::
	setmetatile 10, 14, METATILE_NavelRock_GoldCave_BrownWall_TopLeft, 1
	setmetatile 11, 14, METATILE_NavelRock_GoldCave_BrownWall_TopRight, 1
	setmetatile 10, 15, METATILE_NavelRock_GoldCave_BrownWall_BotLeft, 1
	setmetatile 11, 15, METATILE_NavelRock_GoldCave_BrownWall_BotRight, 1
	return

NavelRock_Hooh3_Eventscript_CloseDoor13::
	setmetatile 10, 18, METATILE_NavelRock_GoldCave_BrownWall_TopLeft, 1
	setmetatile 11, 18, METATILE_NavelRock_GoldCave_BrownWall_TopRight, 1
	setmetatile 10, 19, METATILE_NavelRock_GoldCave_BrownWall_BotLeft, 1
	setmetatile 11, 19, METATILE_NavelRock_GoldCave_BrownWall_BotRight, 1
	return

NavelRock_Hooh3_Eventscript_CloseDoor14::
	setmetatile 8, 12, METATILE_NavelRock_GoldCave_BrownWall_TopLeft, 1
	setmetatile 9, 12, METATILE_NavelRock_GoldCave_BrownWall_TopRight, 1
	setmetatile 8, 13, METATILE_NavelRock_GoldCave_BrownWall_BotLeft, 1
	setmetatile 9, 13, METATILE_NavelRock_GoldCave_BrownWall_BotRight, 1
	return

NavelRock_Hooh3_Eventscript_CloseDoor15::
	setmetatile 8, 16, METATILE_NavelRock_GoldCave_BrownWall_TopLeft, 1
	setmetatile 9, 16, METATILE_NavelRock_GoldCave_BrownWall_TopRight, 1
	setmetatile 8, 17, METATILE_NavelRock_GoldCave_BrownWall_BotLeft, 1
	setmetatile 9, 17, METATILE_NavelRock_GoldCave_BrownWall_BotRight, 1
	return

NavelRock_Hooh3_Eventscript_CloseDoor16::
	setmetatile 6, 10, METATILE_NavelRock_GoldCave_BrownWall_TopLeft, 1
	setmetatile 7, 10, METATILE_NavelRock_GoldCave_BrownWall_TopRight, 1
	setmetatile 6, 11, METATILE_NavelRock_GoldCave_BrownWall_BotLeft, 1
	setmetatile 7, 11, METATILE_NavelRock_GoldCave_BrownWall_BotRight, 1
	return

NavelRock_Hooh3_Eventscript_CloseDoor17::
	setmetatile 6, 14, METATILE_NavelRock_GoldCave_BrownWall_TopLeft, 1
	setmetatile 7, 14, METATILE_NavelRock_GoldCave_BrownWall_TopRight, 1
	setmetatile 6, 15, METATILE_NavelRock_GoldCave_BrownWall_BotLeft, 1
	setmetatile 7, 15, METATILE_NavelRock_GoldCave_BrownWall_BotRight, 1
	return

NavelRock_Hooh3_Eventscript_CloseDoor18::
	setmetatile 6, 18, METATILE_NavelRock_GoldCave_BrownWall_TopLeft, 1
	setmetatile 7, 18, METATILE_NavelRock_GoldCave_BrownWall_TopRight, 1
	setmetatile 6, 19, METATILE_NavelRock_GoldCave_BrownWall_BotLeft, 1
	setmetatile 7, 19, METATILE_NavelRock_GoldCave_BrownWall_BotRight, 1
	return

NavelRock_Hooh3_Eventscript_OpenPuzzleExit1::
	setmetatile 2, 13, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 3, 13, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 2, 14, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 3, 14, METATILE_NavelRock_GoldCave_Floor, 0
	return

NavelRock_Hooh3_Eventscript_ClosePuzzleExit1::
	setmetatile 2, 13, METATILE_NavelRock_GoldCave_BrownWall_TopLeft, 1
	setmetatile 3, 13, METATILE_NavelRock_GoldCave_BrownWall_TopRight, 1
	setmetatile 2, 14, METATILE_NavelRock_GoldCave_BrownWall_BotLeft, 1
	setmetatile 3, 14, METATILE_NavelRock_GoldCave_BrownWall_BotRight, 1
	return

NavelRock_Hooh3_Eventscript_OpenPuzzleExit2::
	setmetatile 2, 7, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 3, 7, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 2, 8, METATILE_NavelRock_GoldCave_Floor, 0
	setmetatile 3, 8, METATILE_NavelRock_GoldCave_Floor, 0
	return

NavelRock_Hooh3_Eventscript_ClosePuzzleExit2::
	setmetatile 2, 7, METATILE_NavelRock_GoldCave_BrownWall_TopLeft, 1
	setmetatile 3, 7, METATILE_NavelRock_GoldCave_BrownWall_TopRight, 1
	setmetatile 2, 8, METATILE_NavelRock_GoldCave_BrownWall_BotLeft, 1
	setmetatile 3, 8, METATILE_NavelRock_GoldCave_BrownWall_BotRight, 1
	return

NavelRock_Hooh3_Eventscript_BoulderSwitch4::
	lockall
	compare VAR_NAVEL_ROCK_BOULDER_BUTTON_4, 100
	goto_if_eq NavelRock_Hooh3_Eventscript_BoulderSwitch4_AlreadyPressed
	playse SE_BANG
	waitse
	setvar VAR_NAVEL_ROCK_BOULDER_BUTTON_4, 100
NavelRock_Hooh3_Eventscript_BoulderSwitch4_AlreadyPressed::
	releaseall
	end

NavelRock_Hooh3_Eventscript_BrownSwitch::
	lockall
	getplayerxy VAR_0x8004, VAR_0x8005
	compare VAR_0x8004, 2
	goto_if_eq NavelRock_Hooh3_Eventscript_PuzzleExitSwitch1
	compare VAR_0x8005, 8
	goto_if_eq NavelRock_Hooh3_Eventscript_PuzzleExitSwitch2
	compare VAR_0x8005, 11
	goto_if_eq NavelRock_Hooh3_Eventscript_PuzzleSwitch1
	compare VAR_0x8005, 12
	goto_if_eq NavelRock_Hooh3_Eventscript_PuzzleSwitch2
	compare VAR_0x8005, 13
	goto_if_eq NavelRock_Hooh3_Eventscript_PuzzleSwitch3
	compare VAR_0x8005, 16
	goto_if_eq NavelRock_Hooh3_Eventscript_PuzzleSwitch4
	compare VAR_0x8005, 17
	goto_if_eq NavelRock_Hooh3_Eventscript_PuzzleSwitch5
	compare VAR_0x8005, 18
	goto_if_eq NavelRock_Hooh3_Eventscript_PuzzleSwitch6
	end

@ Switch 1 - 2, 3, 5, 8, 15, 17
@ Switch 2 - 4, 7, 11, 13, 15, 18
@ Switch 3 - 1, 4, 5, 7, 12, 16
@ Switch 4 - 1, 6, 9, 10, 14, 16
@ Switch 5 - 3, 6, 8, 10, 12, 17
@ Switch 6 - 2, 9, 11, 13, 14, 18

NavelRock_Hooh3_Eventscript_PuzzleSwitch1::
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_2, NavelRock_Hooh3_Eventscript_OpenDoor2
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_2, NavelRock_Hooh3_Eventscript_CloseDoor2
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_3, NavelRock_Hooh3_Eventscript_OpenDoor3
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_3, NavelRock_Hooh3_Eventscript_CloseDoor3
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_5, NavelRock_Hooh3_Eventscript_OpenDoor5
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_5, NavelRock_Hooh3_Eventscript_CloseDoor5
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_8, NavelRock_Hooh3_Eventscript_OpenDoor8
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_8, NavelRock_Hooh3_Eventscript_CloseDoor8
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_15, NavelRock_Hooh3_Eventscript_OpenDoor15
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_15, NavelRock_Hooh3_Eventscript_CloseDoor15
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_17, NavelRock_Hooh3_Eventscript_OpenDoor17
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_17, NavelRock_Hooh3_Eventscript_CloseDoor17
	flipflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_2
	flipflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_3
	flipflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_5
	flipflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_8
	flipflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_15
	flipflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_17
	goto NavelRock_Hooh3_Eventscript_PuzzleSwitchEnd
	end

NavelRock_Hooh3_Eventscript_PuzzleSwitch2::
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_4, NavelRock_Hooh3_Eventscript_OpenDoor4
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_4, NavelRock_Hooh3_Eventscript_CloseDoor4
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_7, NavelRock_Hooh3_Eventscript_OpenDoor7
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_7, NavelRock_Hooh3_Eventscript_CloseDoor7
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_11, NavelRock_Hooh3_Eventscript_OpenDoor11
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_11, NavelRock_Hooh3_Eventscript_CloseDoor11
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_13, NavelRock_Hooh3_Eventscript_OpenDoor13
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_13, NavelRock_Hooh3_Eventscript_CloseDoor13
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_15, NavelRock_Hooh3_Eventscript_OpenDoor15
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_15, NavelRock_Hooh3_Eventscript_CloseDoor15
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_18, NavelRock_Hooh3_Eventscript_OpenDoor18
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_18, NavelRock_Hooh3_Eventscript_CloseDoor18
	flipflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_4
	flipflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_7
	flipflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_11
	flipflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_13
	flipflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_15
	flipflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_18
	goto NavelRock_Hooh3_Eventscript_PuzzleSwitchEnd
	end

NavelRock_Hooh3_Eventscript_PuzzleSwitch3::
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_1, NavelRock_Hooh3_Eventscript_OpenDoor1
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_1, NavelRock_Hooh3_Eventscript_CloseDoor1
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_4, NavelRock_Hooh3_Eventscript_OpenDoor4
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_4, NavelRock_Hooh3_Eventscript_CloseDoor4
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_5, NavelRock_Hooh3_Eventscript_OpenDoor5
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_5, NavelRock_Hooh3_Eventscript_CloseDoor5
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_7, NavelRock_Hooh3_Eventscript_OpenDoor7
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_7, NavelRock_Hooh3_Eventscript_CloseDoor7
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_12, NavelRock_Hooh3_Eventscript_OpenDoor12
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_12, NavelRock_Hooh3_Eventscript_CloseDoor12
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_16, NavelRock_Hooh3_Eventscript_OpenDoor16
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_16, NavelRock_Hooh3_Eventscript_CloseDoor16
	flipflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_1
	flipflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_4
	flipflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_5
	flipflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_7
	flipflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_12
	flipflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_16
	goto NavelRock_Hooh3_Eventscript_PuzzleSwitchEnd
	end

NavelRock_Hooh3_Eventscript_PuzzleSwitch4::
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_1, NavelRock_Hooh3_Eventscript_OpenDoor1
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_1, NavelRock_Hooh3_Eventscript_CloseDoor1
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_6, NavelRock_Hooh3_Eventscript_OpenDoor6
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_6, NavelRock_Hooh3_Eventscript_CloseDoor6
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_9, NavelRock_Hooh3_Eventscript_OpenDoor9
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_9, NavelRock_Hooh3_Eventscript_CloseDoor9
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_10, NavelRock_Hooh3_Eventscript_OpenDoor10
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_10, NavelRock_Hooh3_Eventscript_CloseDoor10
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_14, NavelRock_Hooh3_Eventscript_OpenDoor14
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_14, NavelRock_Hooh3_Eventscript_CloseDoor14
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_16, NavelRock_Hooh3_Eventscript_OpenDoor16
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_16, NavelRock_Hooh3_Eventscript_CloseDoor16
	flipflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_1
	flipflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_6
	flipflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_9
	flipflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_10
	flipflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_14
	flipflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_16
	goto NavelRock_Hooh3_Eventscript_PuzzleSwitchEnd
	end

NavelRock_Hooh3_Eventscript_PuzzleSwitch5::
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_3, NavelRock_Hooh3_Eventscript_OpenDoor3
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_3, NavelRock_Hooh3_Eventscript_CloseDoor3
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_6, NavelRock_Hooh3_Eventscript_OpenDoor6
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_6, NavelRock_Hooh3_Eventscript_CloseDoor6
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_8, NavelRock_Hooh3_Eventscript_OpenDoor8
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_8, NavelRock_Hooh3_Eventscript_CloseDoor8
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_10, NavelRock_Hooh3_Eventscript_OpenDoor10
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_10, NavelRock_Hooh3_Eventscript_CloseDoor10
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_12, NavelRock_Hooh3_Eventscript_OpenDoor12
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_12, NavelRock_Hooh3_Eventscript_CloseDoor12
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_17, NavelRock_Hooh3_Eventscript_OpenDoor17
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_17, NavelRock_Hooh3_Eventscript_CloseDoor17
	flipflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_3
	flipflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_6
	flipflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_8
	flipflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_10
	flipflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_12
	flipflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_17
	goto NavelRock_Hooh3_Eventscript_PuzzleSwitchEnd
	end

NavelRock_Hooh3_Eventscript_PuzzleSwitch6::
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_2, NavelRock_Hooh3_Eventscript_OpenDoor2
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_2, NavelRock_Hooh3_Eventscript_CloseDoor2
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_9, NavelRock_Hooh3_Eventscript_OpenDoor9
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_9, NavelRock_Hooh3_Eventscript_CloseDoor9
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_11, NavelRock_Hooh3_Eventscript_OpenDoor11
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_11, NavelRock_Hooh3_Eventscript_CloseDoor11
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_13, NavelRock_Hooh3_Eventscript_OpenDoor13
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_13, NavelRock_Hooh3_Eventscript_CloseDoor13
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_14, NavelRock_Hooh3_Eventscript_OpenDoor14
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_14, NavelRock_Hooh3_Eventscript_CloseDoor14
	call_if_unset FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_18, NavelRock_Hooh3_Eventscript_OpenDoor18
	call_if_set FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_18, NavelRock_Hooh3_Eventscript_CloseDoor18
	flipflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_2
	flipflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_9
	flipflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_11
	flipflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_13
	flipflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_14
	flipflag FLAG_NAVEL_ROCK_HOOH_SWITCH_DOOR_18
	goto NavelRock_Hooh3_Eventscript_PuzzleSwitchEnd
	end

NavelRock_Hooh3_Eventscript_PuzzleExitSwitch1::
	call_if_unset FLAG_NAVEL_ROCK_HOOH_PUZZLE_EXIT_1, NavelRock_Hooh3_Eventscript_OpenPuzzleExit1
	call_if_set FLAG_NAVEL_ROCK_HOOH_PUZZLE_EXIT_1, NavelRock_Hooh3_Eventscript_ClosePuzzleExit1
	flipflag FLAG_NAVEL_ROCK_HOOH_PUZZLE_EXIT_1
	goto NavelRock_Hooh3_Eventscript_PuzzleSwitchEnd
	end

NavelRock_Hooh3_Eventscript_PuzzleExitSwitch2::
	call_if_unset FLAG_NAVEL_ROCK_HOOH_PUZZLE_EXIT_2, NavelRock_Hooh3_Eventscript_OpenPuzzleExit2
	call_if_set FLAG_NAVEL_ROCK_HOOH_PUZZLE_EXIT_2, NavelRock_Hooh3_Eventscript_ClosePuzzleExit2
	flipflag FLAG_NAVEL_ROCK_HOOH_PUZZLE_EXIT_2
	goto NavelRock_Hooh3_Eventscript_PuzzleSwitchEnd
	end

NavelRock_Hooh3_Eventscript_PuzzleSwitchEnd::
	playse SE_BANG
	special DrawWholeMapView
	waitse
	releaseall
	end
