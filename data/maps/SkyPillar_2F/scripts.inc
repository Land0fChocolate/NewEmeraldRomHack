.set LOCALID_ZINNIA, 1

SkyPillar_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_2F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SkyPillar_2F_SetHoleWarp
	.byte 0

SkyPillar_2F_OnTransition:
	compare VAR_SKY_PILLAR_STATE, 2
	call_if_lt SkyPillar_2F_EventScript_CleanFloor
	copyvar VAR_ICE_STEP_COUNT, 1
	end

SkyPillar_2F_EventScript_CleanFloor::
	setmaplayoutindex LAYOUT_SKY_PILLAR_2F_CLEAN
	return

SkyPillar_2F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_SKY_PILLAR_1F, 255, 0, 0
	end

SkyPillar_2F_EventScript_ZinniaTrigger::
	lockall
	setvar VAR_SKY_PILLAR_2F_TRIGGER, 1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	msgbox SkyPillar_2F_Text_ZinniaStoryPart1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ZINNIA, SkyPillar_2F_Movement_ZinniaMove
	waitmovement 0
	playse SE_EXIT
	setflag FLAG_HIDE_ZINNIA_SKY_PILLAR_2F
	removeobject LOCALID_ZINNIA
	releaseall
	end

SkyPillar_2F_Movement_ZinniaMove:
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

SkyPillar_2F_Text_ZinniaStoryPart1:
	.string "Zinnia: Hey, {PLAYER}.\n"
	.string "Welcome to Sky Pillar.\p"
	.string "I'm sorry you had to see it like this.\n"
	.string "The entire structure has been left in a\l"
	.string "state of disrepair…\p"
	.string "At least the paintings on the walls\n"
	.string "still remain. They tell of an important\l"
	.string "tale in Hoenn history.\p"
	.string "Thousands of years ago, my ancestors\n"
	.string "used the power of Rayquaza to bring\l"
	.string "peace and prosperity to Hoenn.\p"
	.string "However one day, Hoenn was besieged by\n"
	.string "meteorites from outer space.\p"
	.string "These weren't just any meteorites, they\n"
	.string "radiated a strange energy, and they\l"
	.string "landed in a precise triangle pattern.\p"
	.string "More meteorites kept falling, bringing\n"
	.string "destruction throughout Hoenn.\p"
	.string "Then, a strange entity arrived. It was\n"
	.string "like no creature ever seen before.\p"
	.string "It encountered Rayquaza, and the two.\n"
	.string "Pokémon were engaged in a battle so\l"
	.string "ferocious the land below was torn to\l"
	.string "shreds.\l"
	.string "The battle scars remain to this day.\p"
	.string "Eventually, Rayquaza emerged victorious\n"
	.string "and the strange creature, whom we have\l"
	.string "named, Deoxys, retreated to space.\p"
	.string "However, Rayquaza was exhausted after\n"
	.string "the battle. It took to rest at Sky\l"
	.string "Pillar, and remained there since.\p"
	.string "…Okay! That was part one.\n"
	.string "I'll tell you more higher up.\l"
	.string "Look forward to it!$"
