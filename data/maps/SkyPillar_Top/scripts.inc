.set LOCALID_RAYQUAZA_SLEEPING, 1
.set LOCALID_ZINNIA, 3

SkyPillar_Top_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, SkyPillar_Top_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_Top_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SkyPillar_Top_OnWarp
	.byte 0

SkyPillar_Top_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, SkyPillar_Top_EventScript_TryRemoveRayquaza
	end

SkyPillar_Top_EventScript_TryRemoveRayquaza::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

SkyPillar_Top_OnTransition:
	compare VAR_SKY_PILLAR_STATE, 2
	call_if_lt SkyPillar_Top_EventScript_SetCleanLayout
	compare VAR_SKY_PILLAR_STATE, 4
	call_if_ge SkyPillar_Top_EventScript_TryShowRayquaza
	compare VAR_SKY_PILLAR_STATE, 5
	call_if_ge SkyPillar_Top_EventScript_MoveZinnia
	end

SkyPillar_Top_EventScript_MoveZinnia:
	setobjectxyperm LOCALID_ZINNIA, 15, 9
	setobjectmovementtype LOCALID_SCIENTIST_1, MOVEMENT_TYPE_FACE_RIGHT
	return

SkyPillar_Top_EventScript_SetCleanLayout::
	setmaplayoutindex LAYOUT_SKY_PILLAR_TOP_CLEAN
	setobjectmovementtype LOCALID_RAYQUAZA_SLEEPING, MOVEMENT_TYPE_FACE_DOWN
	return

SkyPillar_Top_EventScript_TryShowRayquaza::
	call_if_unset FLAG_DEFEATED_RAYQUAZA, SkyPillar_Top_EventScript_ShowRayquaza
	return

SkyPillar_Top_EventScript_ShowRayquaza::
	clearflag FLAG_HIDE_SKY_PILLAR_TOP_RAYQUAZA_STILL
	return

SkyPillar_Top_OnWarp:
	map_script_2 VAR_SKY_PILLAR_STATE, 0, SkyPillar_Top_EventScript_RayquazaFaceDown
	.2byte 0

SkyPillar_Top_EventScript_RayquazaFaceDown::
	turnobject LOCALID_RAYQUAZA_SLEEPING, DIR_SOUTH
	end

SkyPillar_Top_EventScript_Rayquaza::
	lockall
	waitse
	playmoncry SPECIES_RAYQUAZA, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_RAYQUAZA, 70, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq SkyPillar_Top_EventScript_RayquazaCaught
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq SkyPillar_Top_EventScript_DefeatedRayquaza
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq SkyPillar_Top_EventScript_RanFromRayquaza
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq SkyPillar_Top_EventScript_RanFromRayquaza
	setflag FLAG_DEFEATED_RAYQUAZA
	releaseall
	end

SkyPillar_Top_EventScript_RayquazaCaught::
	compare VAR_SKY_PILLAR_STATE, 6
	goto_if_eq Common_EventScript_NopReturn
	setflag FLAG_DEFEATED_RAYQUAZA
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	applymovement LOCALID_ZINNIA, SkyPillar_Top_Movement_ZinniaMoveCaughtRayquaza
	waitmovement 0
	msgbox SkyPillar_Top_Text_CaughtRayquaza, MSGBOX_DEFAULT
	closemessage
	@giveitem ITEM_KEY_STONE
	msgbox SkyPillar_Top_Text_YouWillNeedThisToo, MSGBOX_DEFAULT
	closemessage
	@giveitem ITEM_SPACE_SUIT
	msgbox SkyPillar_Top_Text_UseDragonAscent, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ZINNIA, SkyPillar_Top_Movement_ZinniaMoveBackCaughtRayquaza
	waitmovement 0
	setvar VAR_SKY_PILLAR_STATE, 6
	setflag FLAG_HIDE_SKY_PILLAR_JUAN
	releaseall
	end

SkyPillar_Top_EventScript_DefeatedRayquaza::
	compare VAR_SKY_PILLAR_STATE, 5
	goto_if_eq SkyPillar_Top_EventScript_SetRematchRayquaza
	setflag FLAG_DEFEATED_RAYQUAZA
	goto SkyPillar_Top_EventScript_DefeatedRayquaza2
	end

SkyPillar_Top_EventScript_RanFromRayquaza::
	compare VAR_SKY_PILLAR_STATE, 5
	goto_if_eq SkyPillar_Top_EventScript_SetRematchRayquaza
	setvar VAR_0x8004, SPECIES_RAYQUAZA
	goto SkyPillar_Top_EventScript_RanFromRayquaza2
	end

SkyPillar_Top_EventScript_DefeatedRayquaza2::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	releaseall
	end

SkyPillar_Top_EventScript_RanFromRayquaza2::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	bufferspeciesname 0, VAR_0x8004
	msgbox gText_LegendaryFlewAway, MSGBOX_DEFAULT
	releaseall
	end

SkyPillar_Top_Movement_ZinniaMoveCaughtRayquaza:
	walk_left
	walk_up
	step_end

SkyPillar_Top_Movement_ZinniaMoveBackCaughtRayquaza:
	walk_down
	walk_right
	face_left
	step_end

SkyPillar_Top_EventScript_SetRematchRayquaza::
	releaseall
	end

SkyPillar_Top_EventScript_AwakenRayquaza::
	lockall
	fadeoutbgm 1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, SkyPillar_Top_Movement_CameraPanUp
	waitmovement 0
	special RemoveCameraObject
	applymovement LOCALID_RAYQUAZA_SLEEPING, SkyPillar_Top_Movement_RayquazaStir
	waitmovement 0
	waitse
	playmoncry SPECIES_RAYQUAZA, 2
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
	waitstate
	waitse
	playmoncry SPECIES_RAYQUAZA, 2
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	waitmoncry
	applymovement LOCALID_RAYQUAZA_SLEEPING, SkyPillar_Top_Movement_RayquazaFlyOff
	waitmovement 0
	removeobject LOCALID_RAYQUAZA_SLEEPING
	msgbox SkyPillar_Top_Text_RayquazaFlewOff, MSGBOX_DEFAULT
	closemessage
	delay 20
	fadeinbgm 1
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, SkyPillar_Top_Movement_CameraPanDown
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_SOOTOPOLIS_CITY_STATE, 5
	setvar VAR_SKY_PILLAR_STATE, 1
	setvar VAR_SKY_PILLAR_RAQUAZA_CRY_DONE, 1
	releaseall
	end

@ Rayquaza has unusual movement frames
@ See comments, or sAnimTable_Rayquaza
SkyPillar_Top_Movement_RayquazaStir:
	delay_16
	walk_in_place_fast_left  @ Coiled, awake
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_left  @ Coiled, mouth open
	delay_16
	walk_in_place_right  @ Normal, awake
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

SkyPillar_Top_Movement_RayquazaFlyOff:
	delay_16
	walk_in_place_down  @ Coiled, asleep
	delay_8
	walk_in_place_right  @ Normal, awake
	delay_8
	walk_fastest_up  @ Fly up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	step_end

SkyPillar_Top_Movement_CameraPanUp:
	walk_slow_up
	walk_slow_up
	walk_slow_up
	step_end

SkyPillar_Top_Movement_CameraPanDown:
	walk_slow_down
	walk_slow_down
	walk_slow_down
	step_end

SkyPillar_Top_EventScript_Zinnia::
	lock
	compare VAR_SKY_PILLAR_STATE, 6
	goto_if_eq SkyPillar_Top_EventScript_GoToSpace
	compare VAR_SKY_PILLAR_STATE, 5
	goto_if_eq SkyPillar_Top_EventScript_CatchRayquaza
	applymovement LOCALID_ZINNIA, Common_Movement_FaceUp
	waitmovement 0
	msgbox SkyPillar_Top_Text_HereWeAre, MSGBOX_DEFAULT
	closemessage
	faceplayer
	msgbox SkyPillar_Top_Text_NoNeedToWait, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ZINNIA, SkyPillar_Top_Movement_ZinniaMoveToRayquaza
	getplayerxy VAR_0x8004, VAR_0x8005
	compare VAR_0x8004, 13
	call_if_eq SkyPillar_Top_EventScript_PlayerMoveX13
	compare VAR_0x8004, 14
	call_if_eq SkyPillar_Top_EventScript_PlayerMoveX14
	compare VAR_0x8004, 15
	call_if_eq SkyPillar_Top_EventScript_PlayerMoveX15
	waitmovement 0
	msgbox SkyPillar_Top_Text_GreatRayquaza, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_RAYQUAZA, 2
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 1  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	msgbox SkyPillar_Top_Text_LendMeAid, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_RAYQUAZA, 2
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 2  @ num shakes
	setvar VAR_0x8007, 10  @ shake delay
	special ShakeCamera
	waitstate
	msgbox SkyPillar_Top_Text_RejectedByRayquaza, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_RAYQUAZA, 1
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 1  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_ZINNIA, Common_Movement_FaceDown
	waitmovement 0
	delay 60
	applymovement LOCALID_ZINNIA, Common_Movement_FaceUp
	waitmovement 0
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq SkyPillar_Top_EventScript_PlayerChosenMale
	compare VAR_RESULT, FEMALE
	call_if_eq SkyPillar_Top_EventScript_PlayerChosenFemale
	closemessage
	applymovement LOCALID_ZINNIA, SkyPillar_Top_Movement_ZinniaMoveToPlayer
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox SkyPillar_Top_Text_AreYouWorthy, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_ZINNIA, SkyPillar_Top_Text_ZinniaDefeated
	msgbox SkyPillar_Top_Text_FallsToYouNow, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ZINNIA, SkyPillar_Top_Movement_ZinniaMovesAway
	waitmovement 0
	setvar VAR_SKY_PILLAR_STATE, 5
	release
	end

SkyPillar_Top_Movement_ZinniaMovesAway:
	walk_right
	face_left
	step_end

SkyPillar_Top_Movement_ZinniaMoveToPlayer:
	walk_down
	face_left
	step_end

SkyPillar_Top_EventScript_PlayerChosenMale::
	msgbox SkyPillar_Top_Text_PlayerChosenMale, MSGBOX_DEFAULT
	return

SkyPillar_Top_EventScript_PlayerChosenFemale::
	msgbox SkyPillar_Top_Text_PlayerChosenFemale, MSGBOX_DEFAULT
	return

SkyPillar_Top_Movement_ZinniaMoveToRayquaza:
	walk_up
	walk_up
	walk_up
	step_end

SkyPillar_Top_EventScript_PlayerMoveX13::
	applymovement OBJ_EVENT_ID_PLAYER, SkyPillar_Top_Movement_PlayerMoveX13
	return

SkyPillar_Top_Movement_PlayerMoveX13:
	walk_right
	walk_up
	walk_up
	walk_left
	face_up
	step_end

SkyPillar_Top_EventScript_PlayerMoveX14::
	applymovement OBJ_EVENT_ID_PLAYER, SkyPillar_Top_Movement_PlayerMoveX14
	return

SkyPillar_Top_Movement_PlayerMoveX14:
	walk_up
	walk_up
	walk_up
	walk_left
	face_up
	step_end

SkyPillar_Top_EventScript_PlayerMoveX15::
	applymovement OBJ_EVENT_ID_PLAYER, SkyPillar_Top_Movement_PlayerMoveX15
	return

SkyPillar_Top_Movement_PlayerMoveX15:
	walk_left
	walk_up
	walk_up
	walk_left
	face_up
	step_end

SkyPillar_Top_EventScript_CatchRayquaza::
	faceplayer
	msgbox SkyPillar_Top_Text_FallsToYouNow, MSGBOX_DEFAULT
	closemessage
	release
	end

SkyPillar_Top_EventScript_GoToSpace::
	faceplayer
	msgbox SkyPillar_Top_Text_UseDragonAscent, MSGBOX_DEFAULT
	closemessage
	release
	end

SkyPillar_Top_Text_RayquazaFlewOff:
	.string "The awakened Rayquaza flew off…$"

SkyPillar_Top_Text_HereWeAre:
	.string "Zinnia: Here we are.\n"
	.string "Rayquaza's throne.$"

SkyPillar_Top_Text_NoNeedToWait:
	.string "Zinnia: There's no need to wait.\n"
	.string "I can meet with Rayquaza now!$"

SkyPillar_Top_Text_GreatRayquaza:
	.string "Zinnia: Great Rayquaza! Hear my wish!\p"
	.string "Catastrophe threatens Hoenn!\n"
	.string "Come with me and we shall defeat the\l"
	.string "danger together!\p"
	.string "Achieve your Mega Evolution!\n"
	.string "Take hold of your true power!\l"
	.string "Show me your true face!\l"
	.string "The Rayquaza that will save this planet!$"

SkyPillar_Top_Text_LendMeAid:
	.string "Zinnia: … … …huh?\p"
	.string "Rayquaza, I am the last in line of the\n"
	.string "Draconid Lorekeepers.\l"
	.string "Please, lend me your aid!$"

SkyPillar_Top_Text_RejectedByRayquaza:
	.string "Zinnia: … … but… why…\p"
	.string "Why won't you work with me!?\p"

SkyPillar_Top_Text_PlayerChosenMale:
	.string "Zinnia: …you chose him over me?\n"
	.string "…but I worked so hard to get here.\l"
	.string "This was supposed to be my duty!$"
	.string "I can't accept this.\p"
	.string "After everything that I've done.\n"
	.string "This is the end of the line for me?$"

SkyPillar_Top_Text_PlayerChosenFemale:
	.string "Zinnia: …you chose her over me?\n"
	.string "…but I worked so hard to get here.\l"
	.string "This was supposed to be my duty!\p"
	.string "I can't accept this.\p"
	.string "After everything that I've done.\n"
	.string "This is the end of the line for me?$"

SkyPillar_Top_Text_AreYouWorthy:
	.string "Zinnia: {PLAYER}.\p"
	.string "Are you truly worthy of fighting\n"
	.string "alongside Rayquaza?\p"
	.string "Show me what Rayquaza sees in you,\n"
	.string "right now!$"

SkyPillar_Top_Text_ZinniaDefeated:
	.string "Zinnia: …$"

SkyPillar_Top_Text_FallsToYouNow:
	.string "Zinnia: I guess it falls to you now.\p"
	.string "{PLAYER}, use everything you've got\n"
	.string "and win over Rayquaza!\p"
	.string "This is the Legendary Pokémon that all\n"
	.string "Hoenn views as as our great protector!\l"
	.string "And the only one who can direct it now…\l"
	.string "It's you! You have to do this!\l"
	.string "Catch it, and save Hoenn!\p"

SkyPillar_Top_Text_CaughtRayquaza:
	.string "Zinnia: … Congratulations, {PLAYER}.\n"
	.string "History has chosen you…\p"
	.string "Rayquaza chose you and not me…\n"
	.string "I think I understand why…\p"
	.string "I think Rayquaza knows of my actions\n"
	.string "and is displeased.\p"
	.string "I don't think Rayquaza believes that the\n"
	.string "ends justify the means…\p"
	.string "As your heart is purer than mine,\n"
	.string "Rayquaza has chosen you over me.\p"
	.string "The duty to defend Hoenn is now yours,\n"
	.string "and so I pass the final key to\l"
	.string "Rayquaza's true power onto you.$"

SkyPillar_Top_Text_YouWillNeedThisToo:
	.string "Zinnia: You'll need this too.$"

SkyPillar_Top_Text_UseDragonAscent:
	.string "Zinnia: With that keystone I just gave\n"
	.string "to you, you'll be able to unlock\l"
	.string "Rayquaza's Mega Evolution.\p"
	.string "In its Mega Evolved form, Rayquaza can\n"
	.string "take you beyond the skies.\p"
	.string "Much like how your Pokémon can carry you\n"
	.string "across water, Rayquaza can carry you to\l"
	.string "space.$"
