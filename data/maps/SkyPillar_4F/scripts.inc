.set LOCALID_ZINNIA, 1

SkyPillar_4F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SkyPillar_4F_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_4F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SkyPillar_4F_SetHoleWarp
	.byte 0

SkyPillar_4F_OnFrame:
	map_script_2 VAR_SKY_PILLAR_4F_TRIGGER, 0, SkyPillar_4F_EventScript_ZinniaTrigger
	map_script_2 VAR_ICE_STEP_COUNT, 0, EventScript_FallDownHole
	.2byte 0

SkyPillar_4F_OnTransition:
	compare VAR_SKY_PILLAR_STATE, 2
	call_if_lt SkyPillar_4F_EventScript_CleanFloor
	copyvar VAR_ICE_STEP_COUNT, 1
	end

SkyPillar_4F_EventScript_CleanFloor::
	setmaplayoutindex LAYOUT_SKY_PILLAR_4F_CLEAN
	return

SkyPillar_4F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_SKY_PILLAR_3F, 255, 0, 0
	end

SkyPillar_4F_EventScript_ZinniaTrigger::
	lockall
	setvar VAR_SKY_PILLAR_4F_TRIGGER, 1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	msgbox SkyPillar_4F_Text_ZinniaStoryPart2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ZINNIA, SkyPillar_4F_Movement_ZinniaMove
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_ZINNIA
	setflag FLAG_HIDE_ZINNIA_SKY_PILLAR_4F
	releaseall
	end

SkyPillar_4F_Movement_ZinniaMove:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

SkyPillar_4F_Text_ZinniaStoryPart2:
	.string "Zinnia: Oh! Here you are!\n"
	.string "Let me continue. Here we go!\p"
	.string "Not too long ago, I was visiting a\n"
	.string "friend of mine, Dr Cozmo.\p"
	.string "You've met him, he's the meteorite\n"
	.string "researcher in Fallarbor.\p"
	.string "He showed me a map of a particular set\n"
	.string "of meteorites that landed at the same\l"
	.string "time and in a triangle pattern.\p"
	.string "That was when I knew, that Deoxys was\n"
	.string "about to return and bring destruction\l"
	.string "to Hoenn once more.\p"
	.string "The solution is simple. Reawaken\n"
	.string "Rayquaza to fight Deoxys again.\p"
	.string "However, my ancestors were locked out of\n"
	.string "Sky Pillar long ago by the Sootopolis\l"
	.string "clan.\p"
	.string "Their descendants are suspicious of\n"
	.string "anyone who would want to get into Sky\l"
	.string "Pillar.\p"
	.string "They would refuse access, and they\n"
	.string "wouldn't believe my tale of Deoxys\l"
	.string "returning.\p"
	.string "The only way I could get them to open\n"
	.string "it, would be to force their hand.\p"
	.string "So, I infiltrated two gangs and gave\n"
	.string "them the idea to wake up other\l"
	.string "legendary Pokémon.\p"
	.string "Their leaders possess a great deal of\n"
	.string "talent.\l"
	.string "It's a shame they have both wasted it\l"
	.string "on their ridiculous idealogies.\p"
	.string "But I managed to put them to good use!\p"
	.string "Team Aqua was supposed to be searching\n"
	.string "the ocean for Kyogre much earlier, but\l"
	.string "thanks to your interference in Petalburg\l"
	.string "Woods and Rustboro, they weren't able to\l"
	.string "get the submarine parts needed.\p"
	.string "I had to run requests to Captain Stern\n"
	.string "and convince him to search the ocean for\l"
	.string "my “research”.\p"
	.string "Progress was slow and Team Aqua were\n"
	.string "getting impatient, so they attempted a\l"
	.string "raid on the Weather Institute.\p"
	.string "I had to pull them away from that.\n"
	.string "I doubt that they could have found an\l"
	.string "inactive Kyogre that way.\p"
	.string "Team Magma found Groudon far quicker\n"
	.string "than I expected. I underestimated the\l"
	.string "power of those digging machines!\p"
	.string "I was still figuring out the location\n"
	.string "of Kyogre when Team Magma had the idea\l"
	.string "to wake up Groudon by blowing up the\l"
	.string "volcano!\p"
	.string "Good thing you came along to stop them.\n"
	.string "I didn't want to have to blow my cover!\p"
	.string "I had to leak the info about the orbs\n"
	.string "after that fiasco, so that Team Magma\l"
	.string "didn't try that again.\p"
	.string "You were an unexpected, but mostly\n"
	.string "welcome addition to the overall plan.\p"
	.string "You quickly convinced the Sootopolis\n"
	.string "folk to open Sky Pillar for you, and\l"
	.string "you cleaned up the mess caused by\l"
	.string "Groudon and Kyogre!\l"
	.string "Very well done!\p"
	.string "And that's part 2! Climb higher for\n"
	.string "the last chapter!$"
