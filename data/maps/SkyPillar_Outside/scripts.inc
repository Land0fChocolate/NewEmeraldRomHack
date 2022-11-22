.set LOCALID_JUAN, 1

SkyPillar_Outside_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_Outside_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, SkyPillar_Outside_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SkyPillar_Outside_OnFrame
	.byte 0

SkyPillar_Outside_OnTransition:
	compare VAR_SOOTOPOLIS_CITY_STATE, 3
	call_if_eq SkyPillar_Outside_EventScript_HideMapNamePopup
	compare VAR_SOOTOPOLIS_CITY_STATE, 4
	call_if_ge SkyPillar_Outside_EventScript_CheckSetAbnormalWeather
	compare VAR_SKY_PILLAR_STATE, 4
	call_if_ge SkyPillar_Outside_EventScript_MoveJuan
	end

SkyPillar_Outside_EventScript_MoveJuan::
	setobjectxyperm LOCALID_JUAN, 14, 8
	setobjectmovementtype LOCALID_JUAN, MOVEMENT_TYPE_FACE_UP
	return

SkyPillar_Outside_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

SkyPillar_Outside_EventScript_CheckSetAbnormalWeather::
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	return

SkyPillar_Outside_OnLoad:
	call_if_set FLAG_JUAN_GOES_TO_SKY_PILLAR, SkyPillar_Outside_EventScript_OpenDoor
	end

SkyPillar_Outside_EventScript_OpenDoor::
	setmetatile 14, 4, METATILE_Pacifidlog_SkyPillar_DoorOpen_Top, 0
	setmetatile 14, 5, METATILE_Pacifidlog_SkyPillar_DoorOpen_Bottom, 0
	return

SkyPillar_Outside_OnFrame:
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 3, SkyPillar_Outside_EventScript_JuanScene
	.2byte 0

SkyPillar_Outside_EventScript_JuanScene::
	lockall
	applymovement LOCALID_JUAN, SkyPillar_Outside_Movement_JuanApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox SkyPillar_Outside_Text_JuanDoorOpened, MSGBOX_DEFAULT
	closemessage
	delay 30
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 3  @ horizontal pan
	setvar VAR_0x8006, 20 @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 40
	msgbox SkyPillar_Outside_Text_JuanEarthquake, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SYS_WEATHER_CTRL
	setweather WEATHER_ABNORMAL
	doweather
	special WaitWeather
	waitstate
	delay 30
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_SOOTOPOLIS_CITY_STATE, 4
	releaseall
	end

SkyPillar_Outside_Movement_JuanApproachPlayer:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

SkyPillar_Outside_EventScript_Juan::
	lockall
	faceplayer
	compare VAR_SKY_PILLAR_STATE, 4
	goto_if_eq SkyPillar_Outside_EventScript_JuanBeatenByZinnia
	compare VAR_SOOTOPOLIS_CITY_STATE, 4
	goto_if_eq SkyPillar_Outside_EventScript_JuanGuardEntranceBeforeRayquaza
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
	goto_if_eq SkyPillar_Outside_EventScript_JuanGuardEntranceAfterRayquaza
	msgbox SkyPillar_Outside_Text_JuanGuardEntrance3, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

SkyPillar_Outside_EventScript_JuanBeatenByZinnia::
	msgbox SkyPillar_Outside_Text_SeverelyBeaten, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

SkyPillar_Outside_EventScript_JuanGuardEntranceBeforeRayquaza::
	msgbox SkyPillar_Outside_Text_JuanGuardEntrance1, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

SkyPillar_Outside_EventScript_JuanGuardEntranceAfterRayquaza::
	msgbox SkyPillar_Outside_Text_JuanGuardEntrance2, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

SkyPillar_Outside_EventScript_ClosedDoor::
	msgbox SkyPillar_Outside_Text_DoorIsClosed, MSGBOX_SIGN
	end

SkyPillar_Outside_Text_DoorIsClosed:
	.string "The door is closed.$"

SkyPillar_Outside_Text_JuanDoorOpened:
	.string "Juan: The door has been opened.\p"
	.string "I have confidence that Rayquaza will be\n"
	.string "able to qwell Groudon and Kyogre.\p"
	.string "I am however concerned about what may\n"
	.string "come after…\p"
	.string "Long ago, a clan called the Draconids\n"
	.string "attempted to rule over all of Hoenn\l"
	.string "using the power of Rayquaza.\p"
	.string "They caused much misery, but were\n"
	.string "ultimately defeated.\p"
	.string "Rayquaza returned to Sky Pillar, and the\n"
	.string "door was sealed by the Sootopolis clan.\p"
	.string "I am one of their descendants.\n"
	.string "The key to Sky Pillar had been passed\l"
	.string "down to me.$"

SkyPillar_Outside_Text_JuanEarthquake:
	.string "Juan: Oh my! Already there are\n"
	.string "earthquakes. I will keep you no longer.\p"
	.string "Since I am unable to close the door,\n"
	.string "I will be staying here to watch over the\l"
	.string "entrance.\p"
	.string "You go on ahead.\n"
	.string "Best of luck.$"

SkyPillar_Outside_Text_JuanGuardEntrance1:
	.string "Juan: I shall be guarding the entrance,\n"
	.string "you go on ahead.$"

SkyPillar_Outside_Text_JuanGuardEntrance2:
	.string "Juan: Excellent job, young one!\p"
	.string "Watching Rayquaza fly is like viewing\n"
	.string "a tapestry swaying in the wind.\l"
	.string "Beautiful!\p"
	.string "See if the situation has improved at\n"
	.string "Sootopolis. I will stay here.$"

SkyPillar_Outside_Text_JuanGuardEntrance3:
	.string "Juan: You have my utmost thanks. I shall\n"
	.string "be delighted to dance with you one day.\p"
	.string "However, even though Rayquaza has not\n"
	.string "yet returned to its throne, I must\l"
	.string "stand watch to prevent any other"
	.string "miscreants using legendary Pokémon\l"
	.string "to cause catastrophe.$"

SkyPillar_Outside_Text_SeverelyBeaten:
	.string "Juan: … … …\p"
	.string "Forgive me… I barely slowed her down…$"
