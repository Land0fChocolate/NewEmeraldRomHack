.set LOCALID_ZINNIA, 1

SkyPillar_5F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SkyPillar_5F_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_5F_OnTransition
	.byte 0

SkyPillar_5F_OnFrame:
	map_script_2 VAR_SKY_PILLAR_5F_TRIGGER, 0, SkyPillar_5F_EventScript_ZinniaTrigger
	.2byte 0

SkyPillar_5F_OnTransition:
	compare VAR_SKY_PILLAR_STATE, 2
	call_if_lt SkyPillar_5F_EventScript_CleanFloor
	return

SkyPillar_5F_EventScript_CleanFloor::
	setmaplayoutindex LAYOUT_SKY_PILLAR_5F_CLEAN
	return

SkyPillar_5F_EventScript_ZinniaTrigger::
	lockall
	setvar VAR_SKY_PILLAR_5F_TRIGGER, 1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox SkyPillar_5F_Text_ZinniaStoryPart3, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ZINNIA, SkyPillar_5F_Movement_ZinniaMove
	waitmovement 0
	playse SE_EXIT
	setflag FLAG_HIDE_ZINNIA_SKY_PILLAR_5F
	removeobject LOCALID_ZINNIA
	releaseall
	end

SkyPillar_5F_Movement_ZinniaMove:
	walk_right
	walk_up
	walk_up
	step_end

SkyPillar_5F_Text_ZinniaStoryPart3:
	.string "Zinnia: The Draconids have a very\n"
	.string "special ritual which calls legendary\l"
	.string "Pokémon to come before us.\l"
	.string "It's been passed down to me.\p"
	.string "However, it has not been very effective\n"
	.string "on Groudon, Kyogre or Rayquaza recently.\p"
	.string "They seem to be far more interested in\n"
	.string "other matters than the calling ritual.\p"
	.string "A side effect of waking them up with the\n"
	.string "orbs perhaps?\p"
	.string "I was running across Hoenn chasing after\n"
	.string "Rayquaza, trying to call it.\l"
	.string "But I kept getting ignored…\p"
	.string "After many tries, I thought that\n"
	.string "Rayquaza may settle back down at Sky\l"
	.string "Pillar if I settled Groudon and Kyogre\l"
	.string "down first.\p"
	.string "So I went to the Weather Institute to\n"
	.string "locate them.\p"
	.string "Then you turned up, and you wanted to\n"
	.string "put a stop to Groudon and Kyogre too!\p"
	.string "So I just let you do it. You've always\n"
	.string "been so reliable, I knew you would get\l"
	.string "the job done!\p"
	.string "Once I saw Rayquaza returning to Sky\n"
	.string "Pillar, I knew the other legendaries\l"
	.string "had been dealt with.\p"
	.string "So that brings the story to now.\p"
	.string "Oh, and I stole a space suit so I can\n"
	.string "fight with Rayquaza against Deoxys in\l"
	.string "space.\p"
	.string "I think that covers everything.\n"
	.string "So now you know why I did all that I\l"
	.string "did.\p"
	.string "All I have to do now, is meet up with\n"
	.string "Rayquaza. You're welcome to observe.$"
