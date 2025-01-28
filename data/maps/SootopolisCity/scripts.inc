.set LOCALID_EXPERT, 1
.set LOCALID_WOMAN_2, 2
.set LOCALID_KIRI, 3
.set LOCALID_NINJA_BOY, 4
.set LOCALID_BOY_1, 5
.set LOCALID_STEVEN, 7
.set LOCALID_WOMAN_1, 8
.set LOCALID_GROUDON, 9
.set LOCALID_KYOGRE, 10
.set LOCALID_RAYQUAZA, 11
.set LOCALID_MANIAC, 12
.set LOCALID_GIRL, 13
.set LOCALID_BLACK_BELT, 14
.set LOCALID_BOY_2, 15
.set LOCALID_MAXIE, 16
.set LOCALID_ARCHIE, 17
.set LOCALID_WALLACE, 18
.set LOCALID_TABITHA, 19
.set LOCALID_COURTNEY, 20
.set LOCALID_MATT, 21
.set LOCALID_SHELLY, 22
.set LOCALID_JUAN, 23

SootopolisCity_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SootopolisCity_OnWarp
	.byte 0

SootopolisCity_OnLoad:
	call_if_unset FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_LockGymDoor
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_EventScript_LegendariesNotArrived
	call_if_unset FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_LockHouseDoors
	end

SootopolisCity_EventScript_LegendariesNotArrived::
	end

SootopolisCity_EventScript_LockHouseDoors::
	setmetatile 9, 6, METATILE_Sootopolis_Door_Closed, 1
	setmetatile 9, 17, METATILE_Sootopolis_Door_Closed, 1
	setmetatile 9, 26, METATILE_Sootopolis_Door_Closed, 1
	setmetatile 44, 17, METATILE_Sootopolis_Door_Closed, 1
	setmetatile 8, 35, METATILE_Sootopolis_Door_Closed, 1
	setmetatile 53, 28, METATILE_Sootopolis_Door_Closed, 1
	setmetatile 45, 6, METATILE_Sootopolis_Door_Closed, 1
	setmetatile 48, 25, METATILE_Sootopolis_Door_Closed, 1
	setmetatile 51, 36, METATILE_Sootopolis_Door_Closed, 1
	return

SootopolisCity_EventScript_LockGymDoor::
	setmetatile 31, 32, METATILE_Sootopolis_GymDoor_Closed, 1
	return

SootopolisCity_OnTransition:
	setflag FLAG_VISITED_SOOTOPOLIS_CITY
	compare VAR_SOOTOPOLIS_CITY_STATE, 1
	call_if_eq SootopolisCity_EventScript_HideMapNamePopup
	compare VAR_SKY_PILLAR_STATE, 1
	call_if_eq SootopolisCity_EventScript_HideMapNamePopup
	call SootopolisCity_EventScript_SetWeather
	call SootopolisCity_EventScript_SetLayout
	compare VAR_SOOTOPOLIS_CITY_STATE, 1
	call_if_eq SootopolisCity_EventScript_SetBattleSpectators
	compare VAR_SOOTOPOLIS_CITY_STATE, 2
	call_if_eq SootopolisCity_EventScript_SetBattleSpectators
	compare VAR_SOOTOPOLIS_CITY_STATE, 3
	call_if_eq SootopolisCity_EventScript_SetBattleSpectators
	compare VAR_SOOTOPOLIS_CITY_STATE, 4
	call_if_eq SootopolisCity_EventScript_SetBattleSpectators
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
	call_if_eq SootopolisCity_EventScript_SetBattleSpectators
	compare VAR_SOOTOPOLIS_CITY_STATE, 2
	call_if_eq SootopolisCity_EventScript_SetBattleSpectators
	compare VAR_SOOTOPOLIS_CITY_STATE, 3
	call_if_eq SootopolisCity_EventScript_SetBattleSpectators
	compare VAR_SOOTOPOLIS_CITY_STATE, 4
	call_if_eq SootopolisCity_EventScript_SetBattleSpectators
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
	call_if_eq SootopolisCity_EventScript_SetOutsideGymObjPos
	compare VAR_SOOTOPOLIS_CITY_STATE, 6
	call_if_eq SootopolisCity_EventScript_SetExpertBlockCaveEntrance
	end

SootopolisCity_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

SootopolisCity_EventScript_SetBattleSpectators::
	setobjectxyperm LOCALID_KIRI, 13, 48
	setobjectxyperm LOCALID_BOY_1, 46, 32
	setobjectxyperm LOCALID_NINJA_BOY, 48, 41
	setobjectxyperm LOCALID_WOMAN_1, 45, 43
	setobjectmovementtype LOCALID_KIRI, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_BOY_1, MOVEMENT_TYPE_FACE_LEFT
	setobjectmovementtype LOCALID_NINJA_BOY, MOVEMENT_TYPE_FACE_LEFT
	setobjectmovementtype LOCALID_WOMAN_1, MOVEMENT_TYPE_FACE_LEFT
	return

SootopolisCity_EventScript_SetLayout::
	compare VAR_SOOTOPOLIS_CITY_STATE, 0
	goto_if_eq SootopolisCity_EventScript_SetNormalLayout
	compare VAR_SOOTOPOLIS_CITY_STATE, 6
	goto_if_ge SootopolisCity_EventScript_SetNormalLayout
	compare VAR_SOOTOPOLIS_CITY_STATE, 1
	goto_if_eq SootopolisCity_EventScript_SetLegendariesLayout
	compare VAR_SOOTOPOLIS_CITY_STATE, 2
	goto_if_eq SootopolisCity_EventScript_SetLegendariesLayout
	compare VAR_SOOTOPOLIS_CITY_STATE, 3
	goto_if_eq SootopolisCity_EventScript_SetLegendariesLayout
	compare VAR_SOOTOPOLIS_CITY_STATE, 4
	goto_if_eq SootopolisCity_EventScript_SetLegendariesLayout
	compare VAR_SKY_PILLAR_STATE, 1
	goto_if_le SootopolisCity_EventScript_SetLegendariesLayout
	return

SootopolisCity_EventScript_SetNormalLayout::
	return

SootopolisCity_EventScript_SetLegendariesLayout::
	setmaplayoutindex LAYOUT_SOOTOPOLIS_CITY_LEGENDS_BATTLE
	return

SootopolisCity_EventScript_SetWeather::
	compare VAR_SOOTOPOLIS_CITY_STATE, 0
	goto_if_eq SootopolisCity_EventScript_SetNormalWeather
	compare VAR_SOOTOPOLIS_CITY_STATE, 6
	goto_if_ge SootopolisCity_EventScript_SetNormalWeather
	compare VAR_SOOTOPOLIS_CITY_STATE, 1
	goto_if_eq SootopolisCity_EventScript_SetDownpour
	compare VAR_SKY_PILLAR_STATE, 1
	goto_if_eq SootopolisCity_EventScript_SetDownpour
	compare VAR_SKY_PILLAR_STATE, 1
	goto_if_le Common_EventScript_SetAbnormalWeather
	return

SootopolisCity_EventScript_SetNormalWeather::
	return

SootopolisCity_EventScript_SetDownpour::
	setweather WEATHER_DOWNPOUR
	return

SootopolisCity_EventScript_SetOutsideGymObjPos::
	setobjectxyperm LOCALID_EXPERT, 31, 18
	setobjectxyperm LOCALID_WALLACE, 31, 33
	setobjectxyperm LOCALID_TABITHA, 27, 35
	setobjectxyperm LOCALID_MAXIE, 28, 35
	setobjectxyperm LOCALID_COURTNEY, 29, 35
	setobjectxyperm LOCALID_MATT, 32, 35
	setobjectxyperm LOCALID_ARCHIE, 33, 35
	setobjectxyperm LOCALID_SHELLY, 34, 35
	setobjectxyperm LOCALID_STEVEN, 30, 33
	checkflag FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE
	goto_if TRUE SootopolisCity_EventScript_StevenInFrontOfGym
	return

SootopolisCity_EventScript_StevenInFrontOfGym::
	setobjectxyperm LOCALID_STEVEN, 31, 33
	return

SootopolisCity_EventScript_SetExpertBlockCaveEntrance::
	setobjectxyperm LOCALID_EXPERT, 31, 18
	return

SootopolisCity_OnWarp:
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_PlayerFaceLegendaries
	.2byte 0

SootopolisCity_EventScript_PlayerFaceLegendaries::
	compare VAR_SKY_PILLAR_STATE, 1
	call_if_eq SootopolisCity_EventScript_PlayerFaceLegendaries1
	compare VAR_SKY_PILLAR_STATE, 2
	call_if_eq SootopolisCity_EventScript_PlayerFaceLegendaries2
	end

SootopolisCity_EventScript_PlayerFaceLegendaries1::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	return

SootopolisCity_EventScript_PlayerFaceLegendaries2::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	setvar VAR_SKY_PILLAR_STATE, 3
	return

SootopolisCity_OnResume:
	setdivewarp MAP_UNDERWATER_SOOTOPOLIS_CITY, 255, 9, 6
	end

SootopolisCity_OnFrame:
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_StartLegendariesScene
	map_script_2 VAR_SKY_PILLAR_STATE, 1, SootopolisCity_EventScript_StartRayquazaScene
	.2byte 0

@ If not at PokeCenter, assumed to have arrived via Dive
SootopolisCity_EventScript_StartLegendariesScene::
	lockall
	special StorePlayerCoordsInVars
	compare VAR_0x8004, 43
	goto_if_ne SootopolisCity_EventScript_LegendariesSceneFromDive
	compare VAR_0x8005, 32
	goto_if_ne SootopolisCity_EventScript_LegendariesSceneFromDive
	goto SootopolisCity_EventScript_LegendariesSceneFromPokeCenter
	end

SootopolisCity_EventScript_LegendariesSceneFromPokeCenter::
	delay 60
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, SootopolisCity_Movement_PanToActionFromPokeCenter
	waitmovement 0
	special RemoveCameraObject
	delay 60
	fadescreenspeed FADE_TO_BLACK, 8
	setweather WEATHER_ABNORMAL
	doweather
	setvar VAR_0x8004, FALSE @ Just do Groudon/Kyogre fight scene
	special Script_DoRayquazaScene
	waitstate
	applymovement LOCALID_KYOGRE, Common_Movement_WalkInPlaceFastestLeft
	applymovement LOCALID_GROUDON, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	delay 60
	waitse
	playmoncry SPECIES_KYOGRE, 2
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreAttack
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonDefend
	waitmovement 0
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonMoveBack
	waitmovement 0
	waitse
	playmoncry SPECIES_GROUDON, 2
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreDefend
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonAttack
	waitmovement 0
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonMoveBack
	waitmovement 0
	waitse
	playmoncry SPECIES_KYOGRE, 2
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreAttack
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonDefend
	waitmovement 0
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonMoveBack
	waitmovement 0
	special SpawnCameraObject
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreIdle
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonIdle
	applymovement OBJ_EVENT_ID_CAMERA, SootopolisCity_Movement_PanBackToPokeCenter
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_SOOTOPOLIS_CITY_STATE, 2
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	releaseall
	end

SootopolisCity_Movement_PanToActionFromPokeCenter:
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	step_end

SootopolisCity_Movement_PanBackToPokeCenter:
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	step_end

SootopolisCity_EventScript_LegendariesSceneFromDive::
	delay 60
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, SootopolisCity_Movement_PanToActionFromDive
	waitmovement 0
	special RemoveCameraObject
	delay 60
	fadescreenspeed FADE_TO_BLACK, 8
	setweather WEATHER_ABNORMAL
	doweather
	setvar VAR_0x8004, FALSE @ Just do Groudon/Kyogre fight scene
	special Script_DoRayquazaScene
	waitstate
	applymovement LOCALID_KYOGRE, Common_Movement_WalkInPlaceFastestLeft
	applymovement LOCALID_GROUDON, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	delay 60
	waitse
	playmoncry SPECIES_KYOGRE, 2
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreAttack
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonDefend
	waitmovement 0
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonMoveBack
	waitmovement 0
	waitse
	playmoncry SPECIES_GROUDON, 2
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreDefend
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonAttack
	waitmovement 0
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonMoveBack
	waitmovement 0
	waitse
	playmoncry SPECIES_KYOGRE, 2
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreAttack
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonDefend
	waitmovement 0
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonMoveBack
	waitmovement 0
	special SpawnCameraObject
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreIdle
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonIdle
	applymovement OBJ_EVENT_ID_CAMERA, SootopolisCity_Movement_PanBackToDive
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_SOOTOPOLIS_CITY_STATE, 2
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	releaseall
	end

SootopolisCity_Movement_PanToActionFromDive:
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SootopolisCity_Movement_PanBackToDive:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	step_end

SootopolisCity_Movement_KyogreAttack:
	walk_in_place_slow_left
	walk_in_place_slow_left
	walk_in_place_slow_left
	delay_16
	delay_16
	delay_16
	init_affine_anim
	walk_left_affine
	clear_affine_anim
	step_end

SootopolisCity_Movement_KyogreDefend:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	init_affine_anim
	walk_left_affine
	clear_affine_anim
	step_end

SootopolisCity_Movement_KyogreMoveBack:
	lock_facing_direction
	walk_right
	delay_16
	delay_16
	delay_16
	unlock_facing_direction
	step_end

SootopolisCity_Movement_KyogreIdle:
	walk_in_place_slow_left
	walk_in_place_slow_left
	walk_in_place_slow_left
	walk_in_place_slow_left
	walk_in_place_slow_left
	walk_in_place_slow_left
	step_end

SootopolisCity_Movement_GroudonAttack:
	walk_in_place_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	delay_16
	delay_16
	delay_16
	walk_fast_right
	step_end

SootopolisCity_Movement_GroudonDefend:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_fast_right
	step_end

SootopolisCity_Movement_GroudonMoveBack:
	lock_facing_direction
	walk_left
	delay_16
	delay_16
	delay_16
	unlock_facing_direction
	step_end

SootopolisCity_Movement_GroudonIdle:
	walk_in_place_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	step_end

@ If not at PokeCenter, assumed to have arrived via Dive
SootopolisCity_EventScript_StartRayquazaScene::
	lockall
	special StorePlayerCoordsInVars
	compare VAR_0x8004, 43
	goto_if_ne SootopolisCity_EventScript_RayquazaSceneFromDive
	compare VAR_0x8005, 32
	goto_if_ne SootopolisCity_EventScript_RayquazaSceneFromDive
	goto SootopolisCity_EventScript_RayquazaSceneFromPokeCenter
	end

SootopolisCity_EventScript_RayquazaSceneFromPokeCenter::
	delay 60
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, SootopolisCity_Movement_PanToActionFromPokeCenter
	waitmovement 0
	special RemoveCameraObject
	delay 60
	fadescreenspeed FADE_TO_BLACK, 8
	call SootopolisCity_EventScript_SetRoughWater
	removeobject LOCALID_GROUDON
	removeobject LOCALID_KYOGRE
	addobject LOCALID_RAYQUAZA
	setvar VAR_0x8004, TRUE
	special Script_DoRayquazaScene
	waitstate
	playse SE_THUNDER
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, SootopolisCity_Movement_PanUp
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
	setweather WEATHER_NONE
	doweather
	applymovement LOCALID_RAYQUAZA, SootopolisCity_Movement_RayquazaFlyOff
	waitmovement 0
	removeobject LOCALID_RAYQUAZA
	special WaitWeather
	waitstate
	clearflag FLAG_SYS_WEATHER_CTRL
	setvar VAR_SKY_PILLAR_STATE, 3
	clearflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
	fadenewbgm MUS_SOOTOPOLIS
	delay 120
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	warpsootopolislegend MAP_SOOTOPOLIS_CITY, 255, 43, 32
	waitstate
	end

SootopolisCity_EventScript_RayquazaSceneFromDive::
	delay 60
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, SootopolisCity_Movement_PanToActionFromDive
	waitmovement 0
	special RemoveCameraObject
	delay 60
	fadescreenspeed FADE_TO_BLACK, 8
	call SootopolisCity_EventScript_SetRoughWater
	removeobject LOCALID_GROUDON
	removeobject LOCALID_KYOGRE
	addobject LOCALID_RAYQUAZA
	setvar VAR_0x8004, TRUE
	special Script_DoRayquazaScene
	waitstate
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, SootopolisCity_Movement_PanUp
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_Movement_PlayerApproachLegendaries
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
	setweather WEATHER_NONE
	doweather
	applymovement LOCALID_RAYQUAZA, SootopolisCity_Movement_RayquazaFlyOff
	waitmovement 0
	removeobject LOCALID_RAYQUAZA
	special WaitWeather
	waitstate
	clearflag FLAG_SYS_WEATHER_CTRL
	setvar VAR_SKY_PILLAR_STATE, 2
	clearflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
	fadenewbgm MUS_SURF
	delay 120
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	warpsootopolislegend MAP_SOOTOPOLIS_CITY, 255, 29, 53
	waitstate
	end

SootopolisCity_EventScript_SetRoughWater::
	setmetatile 27, 43, METATILE_Sootopolis_RoughWater, 0
	setmetatile 28, 43, METATILE_Sootopolis_RoughWater, 0
	setmetatile 29, 43, METATILE_Sootopolis_RoughWater, 0
	setmetatile 30, 43, METATILE_Sootopolis_RoughWater, 0
	setmetatile 27, 44, METATILE_Sootopolis_RoughWater, 0
	setmetatile 28, 44, METATILE_Sootopolis_RoughWater, 0
	setmetatile 29, 44, METATILE_Sootopolis_RoughWater, 0
	setmetatile 30, 44, METATILE_Sootopolis_RoughWater, 0
	setmetatile 27, 45, METATILE_Sootopolis_RoughWater, 0
	setmetatile 28, 45, METATILE_Sootopolis_RoughWater, 0
	setmetatile 29, 45, METATILE_Sootopolis_RoughWater, 0
	setmetatile 30, 45, METATILE_Sootopolis_RoughWater, 0
	setmetatile 32, 43, METATILE_Sootopolis_RoughWater, 0
	setmetatile 33, 43, METATILE_Sootopolis_RoughWater, 0
	setmetatile 34, 43, METATILE_Sootopolis_RoughWater, 0
	setmetatile 35, 43, METATILE_Sootopolis_RoughWater, 0
	setmetatile 32, 44, METATILE_Sootopolis_RoughWater, 0
	setmetatile 33, 44, METATILE_Sootopolis_RoughWater, 0
	setmetatile 34, 44, METATILE_Sootopolis_RoughWater, 0
	setmetatile 35, 44, METATILE_Sootopolis_RoughWater, 0
	setmetatile 32, 45, METATILE_Sootopolis_RoughWater, 0
	setmetatile 33, 45, METATILE_Sootopolis_RoughWater, 0
	setmetatile 34, 45, METATILE_Sootopolis_RoughWater, 0
	setmetatile 35, 45, METATILE_Sootopolis_RoughWater, 0
	return

SootopolisCity_Movement_RayquazaFlyOff:
	walk_fast_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	step_end

SootopolisCity_Movement_PanUp:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SootopolisCity_Movement_PlayerApproachLegendaries:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

@ Unused
SootopolisCity_Movement_PlayerApproachLegendariesDown:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

@ Unused
SootopolisCity_Movement_UnusedPanUp:
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

@ Unused
SootopolisCity_Movement_UnusedPanBack:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	step_end

SootopolisCity_EventScript_CaveOfOriginExpert::
	lock
	faceplayer
	@compare VAR_SOOTOPOLIS_CITY_STATE, 6
	@goto_if_ge SootopolisCity_EventScript_ExpertPostLegendaries
	@compare VAR_SOOTOPOLIS_CITY_STATE, 5
	@goto_if_eq SootopolisCity_EventScript_ExpertLegendaries
	@compare VAR_SOOTOPOLIS_CITY_STATE, 2
	@goto_if_ge SootopolisCity_EventScript_ExpertLeadToCave
	msgbox SootopolisCity_Text_CaveOfOriginPleaseLeave, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_ExpertLeadToCave::
	msgbox SootopolisCity_Text_LeadSuperiorTrainerToCave, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_ExpertPostLegendaries::
	msgbox SootopolisCity_Text_CaveOfOriginSleepsToo, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_ExpertLegendaries::
	msgbox SootopolisCity_Text_AwakenedPokemonClash, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_Kiri::
	lock
	faceplayer
	compare VAR_SOOTOPOLIS_CITY_STATE, 1
	goto_if_le SootopolisCity_EventScript_KiriGiveBerry
	compare VAR_SOOTOPOLIS_CITY_STATE, 6
	goto_if_ge SootopolisCity_EventScript_KiriGiveBerry
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
	goto_if_eq SootopolisCity_EventScript_KiriRayquaza
	msgbox SootopolisCity_Text_BigPokemonFighting, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_KIRI, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SootopolisCity_EventScript_KiriRayquaza::
	msgbox SootopolisCity_Text_PrettyMonCameFromSky, MSGBOX_DEFAULT
	closemessage
	release
	end

@ Gives 2 berries daily. First ranges from FIRST_KIRI_BERRY to LAST_KIRI_BERRY, second is always Figy or Iapapa
SootopolisCity_EventScript_KiriGiveBerry::
	dotimebasedevents
	special GetPlayerBigGuyGirlString
	goto_if_set FLAG_DAILY_SOOTOPOLIS_RECEIVED_BERRY, SootopolisCity_EventScript_KiriReceivedBerry
	msgbox SootopolisCity_Text_NameIsKiriHaveOneOfThese, MSGBOX_DEFAULT
	random NUM_KIRI_BERRIES
	addvar VAR_RESULT, NUM_KIRI_BERRIES_SKIPPED
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Text_GiveYouThisBerryToo, MSGBOX_DEFAULT
	random NUM_KIRI_BERRIES
	addvar VAR_RESULT, NUM_KIRI_BERRIES_SKIPPED
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_SOOTOPOLIS_RECEIVED_BERRY
	msgbox SootopolisCity_Text_WhatKindOfWishInYourName, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_KiriReceivedBerry::
	msgbox SootopolisCity_Text_LikeSeasonBornIn, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq SootopolisCity_EventScript_KiriLikeSeasonBornIn
	msgbox SootopolisCity_Text_OhDoesntMatter, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_KiriLikeSeasonBornIn::
	msgbox SootopolisCity_Text_ThenILoveAutumn, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_Woman2::
	lockall
	applymovement LOCALID_WOMAN_2, Common_Movement_FacePlayer
	waitmovement 0
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
	goto_if_ge SootopolisCity_EventScript_Woman2Rayquaza
	msgbox SootopolisCity_Text_WeatherWentWild, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WOMAN_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SootopolisCity_EventScript_Woman2Rayquaza::
	msgbox SootopolisCity_Text_YouBroughtFlyingMon, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_Man::
	lock
	faceplayer
	compare VAR_SOOTOPOLIS_CITY_STATE, 6
	goto_if_ge SootopolisCity_EventScript_ManPostLegendaries
	msgbox SootopolisCity_Text_NoOrdinaryTourist, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_ManPostLegendaries::
	msgbox SootopolisCity_Text_CityRegainedCalm, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_Woman1::
	lock
	faceplayer
	compare VAR_SOOTOPOLIS_CITY_STATE, 6
	goto_if_ge SootopolisCity_EventScript_Woman1PostLegendaries
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
	goto_if_eq SootopolisCity_EventScript_Woman1Rayquaza
	compare VAR_SOOTOPOLIS_CITY_STATE, 2
	goto_if_ge SootopolisCity_EventScript_Woman1Legendaries
	msgbox SootopolisCity_Text_SootopolisSkyBeautiful, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_Woman1Legendaries::
	msgbox SootopolisCity_Text_GiganticPokemonFight, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WOMAN_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SootopolisCity_EventScript_Woman1PostLegendaries::
	msgbox SootopolisCity_Text_NightSkyFavoriteScenery, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_Woman1Rayquaza::
	msgbox SootopolisCity_Text_FearedWorstWhenPokemonFlewDown, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_NinjaBoy::
	lockall
	applymovement LOCALID_NINJA_BOY, Common_Movement_FacePlayer
	waitmovement 0
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
	goto_if_eq SootopolisCity_EventScript_NinjaBoyRayquaza
	compare VAR_SOOTOPOLIS_CITY_STATE, 6
	goto_if_ge SootopolisCity_EventScript_NinjaBoyNormal
	compare VAR_SOOTOPOLIS_CITY_STATE, 1
	goto_if_le SootopolisCity_EventScript_NinjaBoyNormal
	msgbox SootopolisCity_Text_ThisIsWicked, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_NINJA_BOY, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SootopolisCity_EventScript_NinjaBoyNormal::
	msgbox SootopolisCity_Text_WonderWhatWorldIsLike, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_NinjaBoyRayquaza::
	msgbox SootopolisCity_Text_ThatWasWicked, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_Boy1::
	lockall
	applymovement LOCALID_BOY_1, Common_Movement_FacePlayer
	waitmovement 0
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
	goto_if_eq SootopolisCity_EventScript_Boy1Rayquaza
	goto_if_set FLAG_SYS_GAME_CLEAR, SootopolisCity_EventScript_Boy1GameClear
	compare VAR_SOOTOPOLIS_CITY_STATE, 6
	goto_if_ge SootopolisCity_EventScript_Boy1Normal
	compare VAR_SOOTOPOLIS_CITY_STATE, 1
	goto_if_le SootopolisCity_EventScript_Boy1Normal
	msgbox SootopolisCity_Text_GiantPokemonSuddenlyAppeared, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BOY_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SootopolisCity_EventScript_Boy1Rayquaza::
	msgbox SootopolisCity_Text_WhatIsThatGreenPokemon, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_Boy1GameClear::
	msgbox SootopolisCity_Text_WhereDidLegendariesGo, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_Boy1Normal::
	msgbox SootopolisCity_Text_PhysicallyFitLivingHere, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_GymSign::
	msgbox SootopolisCity_Text_GymSign, MSGBOX_SIGN
	end

SootopolisCity_EventScript_CitySign::
	msgbox SootopolisCity_Text_CitySign, MSGBOX_SIGN
	end

EventScript_ClosedSootopolisDoor::
	msgbox SootopolisCity_Text_DoorIsClosed, MSGBOX_SIGN
	end

SootopolisCity_EventScript_Steven_Wallace_Encounter::
	lockall
	getplayerxy VAR_0x8004, VAR_0x8005
	compare VAR_0x8004, 19
	goto_if_eq SootopolisCity_EventScript_Steven_Wallace_Legendaries
	compare VAR_0x8004, 20
	goto_if_eq SootopolisCity_EventScript_StevenMoveToPlayer
	end

SootopolisCity_EventScript_StevenMoveToPlayer::
	applymovement LOCALID_STEVEN, SootopolisCity_Movement_StevenMoveToPlayer
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	goto SootopolisCity_EventScript_Steven_Wallace_Legendaries

SootopolisCity_Movement_StevenMoveToPlayer:
	walk_down
	face_right
	step_end

SootopolisCity_EventScript_Steven_Wallace_Legendaries::
	msgbox SootopolisCity_Text_StevenGreetsPlayer, MSGBOX_DEFAULT
	closemessage
	getplayerxy VAR_0x8004, VAR_0x8005
	compare VAR_0x8004, 19
	goto_if_eq SootopolisCity_EventScript_WallaceMoveToPlayer
	compare VAR_0x8004, 20
	goto_if_eq SootopolisCity_EventScript_PlayerTurnToWallace
	end

SootopolisCity_EventScript_WallaceMoveToPlayer::
	applymovement LOCALID_WALLACE, SootopolisCity_Movement_WallaceMoveToPlayer
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	goto SootopolisCity_EventScript_WallaceIntro

SootopolisCity_EventScript_PlayerTurnToWallace::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	goto SootopolisCity_EventScript_WallaceIntro

SootopolisCity_Movement_WallaceMoveToPlayer:
	walk_down
	face_left
	step_end

SootopolisCity_EventScript_WallaceIntro::
	msgbox SootopolisCity_Text_WallaceGreetsPlayer, MSGBOX_DEFAULT
	closemessage
	getplayerxy VAR_0x8004, VAR_0x8005
	compare VAR_0x8004, 19
	goto_if_eq SootopolisCity_EventScript_PlayerFaceStevenUp
	compare VAR_0x8004, 20
	goto_if_eq SootopolisCity_EventScript_PlayerFaceStevenLeft
	end

SootopolisCity_EventScript_PlayerFaceStevenUp::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	goto SootopolisCity_EventScript_StevenDiscussStorm

SootopolisCity_EventScript_PlayerFaceStevenLeft::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	goto SootopolisCity_EventScript_StevenDiscussStorm

SootopolisCity_EventScript_StevenDiscussStorm::
	msgbox SootopolisCity_Text_StevenDiscussStorm, MSGBOX_DEFAULT
	closemessage
	getplayerxy VAR_0x8004, VAR_0x8005
	compare VAR_0x8004, 19
	goto_if_eq SootopolisCity_EventScript_PlayerFaceWallaceRight
	compare VAR_0x8004, 20
	goto_if_eq SootopolisCity_EventScript_PlayerFaceWallaceUp
	end

SootopolisCity_EventScript_PlayerFaceWallaceRight::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	goto SootopolisCity_EventScript_WallaceFollowToJuan

SootopolisCity_EventScript_PlayerFaceWallaceUp::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	goto SootopolisCity_EventScript_WallaceFollowToJuan

SootopolisCity_EventScript_WallaceFollowToJuan::
	msgbox SootopolisCity_Text_WallaceFollowToJuan, MSGBOX_DEFAULT
	closemessage
	getplayerxy VAR_0x8004, VAR_0x8005
	compare VAR_0x8004, 19
	goto_if_eq SootopolisCity_EventScript_PlayerLeftFollowWallace
	compare VAR_0x8004, 20
	goto_if_eq SootopolisCity_EventScript_PlayerRightFollowWallace
	end

SootopolisCity_Movement_StepBack:
	walk_up
	step_end

SootopolisCity_EventScript_PlayerLeftFollowWallace::
	applymovement LOCALID_WALLACE, SootopolisCity_Movement_StepBack
	waitmovement 0
	applymovement LOCALID_WALLACE, SootopolisCity_Movement_WallaceMoveToJuan
	applymovement LOCALID_STEVEN, SootopolisCity_Movement_StevenMoveToJuan
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_Movement_PlayerLeftMoveToJuan
	waitmovement 0
	goto SootopolisCity_EventScript_JuanIntro

SootopolisCity_EventScript_PlayerRightFollowWallace::
	applymovement LOCALID_STEVEN, SootopolisCity_Movement_StepBack
	waitmovement 0
	applymovement LOCALID_WALLACE, SootopolisCity_Movement_WallaceMoveToJuan
	applymovement LOCALID_STEVEN, SootopolisCity_Movement_StevenMoveToJuan
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_Movement_PlayerRightMoveToJuan
	waitmovement 0
	goto SootopolisCity_EventScript_JuanIntro

SootopolisCity_Movement_WallaceMoveToJuan:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	face_down
	step_end

SootopolisCity_Movement_StevenMoveToJuan:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	face_down
	step_end

SootopolisCity_Movement_PlayerLeftMoveToJuan:
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	walk_down
	face_right
	step_end

SootopolisCity_Movement_PlayerRightMoveToJuan:
	delay_16
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	walk_down
	face_right
	step_end

SootopolisCity_EventScript_JuanIntro::
	msgbox SootopolisCity_Text_WallaceHailsJuan, MSGBOX_DEFAULT
	applymovement LOCALID_JUAN, Common_Movement_FaceUp
	msgbox SootopolisCity_Text_JuanRayquazaLegend, MSGBOX_DEFAULT
	applymovement LOCALID_STEVEN, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox SootopolisCity_Text_StevenJustFindRayquaza, MSGBOX_DEFAULT
	msgbox SootopolisCity_Text_JuanPerhaps, MSGBOX_DEFAULT
	applymovement LOCALID_JUAN, Common_Movement_FaceLeft
	msgbox SootopolisCity_Text_JuanAsksWherePlayerFrom, MSGBOX_DEFAULT
	closemessage
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject LOCALID_JUAN
	waitfieldeffect FLDEFF_NPCFLY_OUT
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_JUAN
	setflag FLAG_JUAN_GOES_TO_SKY_PILLAR
	clearflag FLAG_HIDE_SKY_PILLAR_JUAN
	setvar VAR_SOOTOPOLIS_STEVEN_WALLACE_STATE, 1
	setvar VAR_SOOTOPOLIS_CITY_STATE, 3
	setobjectxyperm LOCALID_STEVEN, 23, 7
	setobjectxyperm LOCALID_WALLACE, 24, 7
	releaseall
	end

SootopolisCity_EventScript_Steven::
	lockall
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	checkflag FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE
	goto_if TRUE SootopolisCity_EventScript_StevenThanksPlayerAndLeaves
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
	goto_if_eq SootopolisCity_EventScript_StevenRayquazaStoppedIt
	msgbox SootopolisCity_Text_StevenGoToSkyPillar, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

SootopolisCity_EventScript_StevenRayquazaStoppedIt::
	msgbox SootopolisCity_Text_StevenRayquazaStoppedIt, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLACE, Common_Movement_FaceLeft
	waitmovement 0
	msgbox SootopolisCity_Text_WallaceStevenDrooling, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

SootopolisCity_EventScript_StevenThanksPlayerAndLeaves::
	msgbox SootopolisCity_Text_StevenThanksPlayerAndGivesMasterBall, MSGBOX_DEFAULT
	giveitem ITEM_MASTER_BALL
	msgbox SootopolisCity_Text_StevenLeaves, MSGBOX_DEFAULT
	closemessage
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject LOCALID_STEVEN
	waitfieldeffect FLDEFF_NPCFLY_OUT
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	setvar VAR_SOOTOPOLIS_CITY_STATE, 6
	releaseall
	end

SootopolisCity_EventScript_Wallace::
	lockall
	applymovement LOCALID_WALLACE, Common_Movement_FacePlayer
	waitmovement 0
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
	goto_if_eq SootopolisCity_EventScript_WallaceItsOver
	msgbox SootopolisCity_Text_WallaceMentorJuan, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

SootopolisCity_EventScript_WallaceItsOver::
	msgbox SootopolisCity_Text_WallaceItsOver, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

SootopolisCity_EventScript_Boy2::
	lockall
	applymovement LOCALID_BOY_2, Common_Movement_FacePlayer
	waitmovement 0
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
	goto_if_ge SootopolisCity_EventScript_Boy2Rayquaza
	msgbox SootopolisCity_Text_TwoPokemonArentAngry, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BOY_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SootopolisCity_EventScript_Boy2Rayquaza::
	msgbox SootopolisCity_Text_FlyingMonStoppedRampage, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

SootopolisCity_EventScript_BlackBelt::
	lockall
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
	goto_if_ge SootopolisCity_EventScript_BlackBeltRayquaza
	msgbox SootopolisCity_Text_GoRedAndBlueMon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BLACK_BELT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SootopolisCity_Text_DoYouKnowMonNames, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BLACK_BELT, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SootopolisCity_EventScript_BlackBeltRayquaza::
	applymovement LOCALID_BLACK_BELT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SootopolisCity_Text_GreenOneSettlesThings, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_Girl::
	lockall
	applymovement LOCALID_GIRL, Common_Movement_FacePlayer
	waitmovement 0
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
	goto_if_ge SootopolisCity_EventScript_GirlRayquaza
	msgbox SootopolisCity_Text_SootopolisWillBeWrecked, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GIRL, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SootopolisCity_EventScript_GirlRayquaza::
	msgbox SootopolisCity_Text_SootopolisDidntGetWrecked, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

SootopolisCity_EventScript_Maniac::
	lockall
	applymovement LOCALID_MANIAC, Common_Movement_FacePlayer
	waitmovement 0
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
	goto_if_ge SootopolisCity_EventScript_ManiacRayquaza
	msgbox SootopolisCity_Text_SeeingLegendWithOwnEyes, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MANIAC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SootopolisCity_EventScript_ManiacRayquaza::
	msgbox SootopolisCity_Text_SawLegendWithOwnEyes, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_Maxie::
	lockall
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
	goto_if_eq SootopolisCity_EventScript_MaxieRayquaza
	msgbox SootopolisCity_Text_GroudonPleaseStop, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

SootopolisCity_EventScript_MaxieRayquaza::
	faceplayer
	msgbox SootopolisCity_Text_IHaveCausedHarm, MSGBOX_DEFAULT
	setflag FLAG_MET_MAXIE_SOOTOPOLIS
	goto_if_set FLAG_MET_ARCHIE_SOOTOPOLIS, SootopolisCity_EventScript_MaxieArchieLeave
	releaseall
	end

SootopolisCity_EventScript_Tabitha::
	lockall
	faceplayer
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
	goto_if_eq SootopolisCity_EventScript_TabithaRayquaza
	msgbox SootopolisCity_Text_TabithaGroudonKyogre, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

SootopolisCity_EventScript_TabithaRayquaza::
	msgbox SootopolisCity_Text_TabithaRayquaza, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_Courtney::
	lockall
	faceplayer
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
	goto_if_eq SootopolisCity_EventScript_CourtneyRayquaza
	msgbox SootopolisCity_Text_CourtneyGroudonKyogre, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

SootopolisCity_EventScript_CourtneyRayquaza::
	msgbox SootopolisCity_Text_CourtneyRayquaza, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_Archie::
	lockall
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
	goto_if_eq SootopolisCity_EventScript_ArchieRayquaza
	msgbox SootopolisCity_Text_KyogreCalmDown, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

SootopolisCity_EventScript_ArchieRayquaza::
	faceplayer
	msgbox SootopolisCity_Text_TryingMeaninglessToPokemon, MSGBOX_DEFAULT
	setflag FLAG_MET_ARCHIE_SOOTOPOLIS
	goto_if_set FLAG_MET_MAXIE_SOOTOPOLIS, SootopolisCity_EventScript_MaxieArchieLeave
	releaseall
	end

SootopolisCity_EventScript_Shelly::
	lockall
	faceplayer
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
	goto_if_eq SootopolisCity_EventScript_ShellyRayquaza
	msgbox SootopolisCity_Text_ShellyGroudonKyogre, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

SootopolisCity_EventScript_ShellyRayquaza::
	msgbox SootopolisCity_Text_ShellyRayquaza, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_Matt::
	lockall
	faceplayer
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
	goto_if_eq SootopolisCity_EventScript_MattRayquaza
	msgbox SootopolisCity_Text_MattGroudonKyogre, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

SootopolisCity_EventScript_MattRayquaza::
	msgbox SootopolisCity_Text_MattRayquaza, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_MaxieArchieLeave::
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_MAXIE
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_ARCHIE
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
	setflag FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE
	warpsilent MAP_SOOTOPOLIS_CITY, 255, 31, 34
	waitstate
	releaseall
	end

SootopolisCity_EventScript_Juan::
	msgbox SootopolisCity_Text_Juan, MSGBOX_NPC
	end

SootopolisCity_Text_GymSign:
	.string "SOOTOPOLIS CITY POKéMON GYM\n"
	.string "LEADER: WALLACE\p"
	.string "“The Gym Leader with the beauty\n"
	.string "of pure water!”$"

SootopolisCity_Text_CitySign:
	.string "SOOTOPOLIS CITY\p"
	.string "“The mystical city where history\n"
	.string "slumbers.”$"

SootopolisCity_Text_DoorIsClosed:
	.string "The door is closed.$"

SootopolisCity_Text_PhysicallyFitLivingHere:
	.string "Diving in the sea. Climbing up and\n"
	.string "down stairs all the time…\p"
	.string "If you live in this town, you end up\n"
	.string "getting physically fit.$"

SootopolisCity_Text_GiantPokemonSuddenlyAppeared:
	.string "These giant Pokémon suddenly appeared\n"
	.string "in the middle of the city!\p"
	.string "And, I've never seen them before!\p"
	.string "Why are they smashing into each\n"
	.string "other like that?\p"
	.string "Why can't they be friends, those\n"
	.string "Pokémon?$"

SootopolisCity_Text_WhatIsThatGreenPokemon:
	.string "What? What? What?\n"
	.string "What is that green Pokémon?!$"

SootopolisCity_Text_WhereDidLegendariesGo:
	.string "Groudon and Kyogre…\n"
	.string "Where did they go?\p"
	.string "Will they cause droughts or downpours\n"
	.string "somewhere else?$"

SootopolisCity_Text_TwoPokemonArentAngry:
	.string "I just get this sense somehow that\n"
	.string "the two Pokémon aren't angry.\p"
	.string "I think… They probably can't control\n"
	.string "their own power…$"

SootopolisCity_Text_FlyingMonStoppedRampage:
	.string "That flying Pokémon came down from\n"
	.string "the sky and stopped the rampaging\l"
	.string "Pokémon…$"

SootopolisCity_Text_WonderWhatWorldIsLike:
	.string "I… I've never been out of this city.\p"
	.string "I wonder what the world is like on\n"
	.string "the other side of this round sky?$"

SootopolisCity_Text_ThisIsWicked:
	.string "Wow!\n"
	.string "This is wicked!$"

SootopolisCity_Text_ThatWasWicked:
	.string "Wow!\n"
	.string "That was wicked!$"

SootopolisCity_Text_GoRedAndBlueMon:
	.string "Go for it, red Pokémon!\n"
	.string "Don't back off, blue Pokémon!$"

SootopolisCity_Text_DoYouKnowMonNames:
	.string "… … … … … …\p"
	.string "Hi, do you know the names of those\n"
	.string "Pokémon fighting over there?$"

SootopolisCity_Text_GreenOneSettlesThings:
	.string "I was wondering which one would win,\n"
	.string "the red one or the blue one, but, oh no,\l"
	.string "it's the green one that settles things!\p"
	.string "Talk about a huge turn of events!$"

SootopolisCity_Text_SeeingLegendWithOwnEyes:
	.string "There's an ancient legend that claims\n"
	.string "the land and sea were shaped by\l"
	.string "a colossal battle between Pokémon.\p"
	.string "Well, I'm seeing that happen with\n"
	.string "my very own eyes!\p"
	.string "Whoa! I never expected to be\n"
	.string "witness to something this huge!$"

SootopolisCity_Text_SawLegendWithOwnEyes:
	.string "There's an ancient legend that claims\n"
	.string "the land and sea were shaped by\l"
	.string "a colossal battle between Pokémon.\p"
	.string "Well, I saw that happen with\n"
	.string "my very own eyes!\p"
	.string "Whoa! I never expected to be\n"
	.string "witness to something this huge!$"

SootopolisCity_Text_BigPokemonFighting:
	.string "A big Pokémon is fighting with\n"
	.string "another big Pokémon!\p"
	.string "Please, someone make them stop!$"

SootopolisCity_Text_PrettyMonCameFromSky:
	.string "A pretty Pokémon came down from\n"
	.string "the sky…$"

SootopolisCity_Text_SootopolisWillBeWrecked:
	.string "Oh, no!\n"
	.string "Sootopolis City will get wrecked!$"

SootopolisCity_Text_SootopolisDidntGetWrecked:
	.string "Sootopolis City didn't get wrecked!$"

SootopolisCity_Text_NoOrdinaryTourist:
	.string "Hm!\n"
	.string "You've come all the way to Sootopolis?\l"
	.string "You're no ordinary tourist.\p"
	.string "But I suppose that doesn't make you\n"
	.string "an extraordinary tourist, either.$"

SootopolisCity_Text_CityRegainedCalm:
	.string "The city has regained its calm…$"

SootopolisCity_Text_CaveOfOriginPleaseLeave:
	.string "Who might you be?\p"
	.string "This is the Cave of Origin.\p"
	.string "The spirits of Pokémon, becalmed at\n"
	.string "Mt. Pyre, are said to be revived here.\p"
	.string "Please leave.$"

SootopolisCity_Text_LeadSuperiorTrainerToCave:
	.string "A person with a strong will and\n"
	.string "superior talent…\p"
	.string "A Trainer who has knowledge and\n"
	.string "experience of many kinds of Pokémon…\p"
	.string "If such a person were to appear, I was\n"
	.string "instructed by Wallace to lead that\l"
	.string "Trainer to this Cave.$"

SootopolisCity_Text_AwakenedPokemonClash:
	.string "Oh, my…\p"
	.string "The clash between the two awakened\n"
	.string "Pokémon was quelled by the awakening\l"
	.string "of a third Pokémon…$"

SootopolisCity_Text_CaveOfOriginSleepsToo:
	.string "This is the Cave of Origin…\p"
	.string "With the passing of the crisis,\n"
	.string "the cave, too, shall sleep…$"

SootopolisCity_Text_SootopolisSkyBeautiful:
	.string "Sootopolis sprang up as a town in\n"
	.string "the crater of a volcano.\p"
	.string "If you look up at the sky, the lip of\n"
	.string "the crater is also visible.\l"
	.string "So, all you see is the sky in a circle.\p"
	.string "But that's what makes the sky above\n"
	.string "Sootopolis the most beautiful.$"

SootopolisCity_Text_GiganticPokemonFight:
	.string "When two Pokémon that gigantic\n"
	.string "are fighting that savagely, there's\l"
	.string "not much that we can do.$"

SootopolisCity_Text_FearedWorstWhenPokemonFlewDown:
	.string "When that third Pokémon flew down,\n"
	.string "I feared the worst.$"

SootopolisCity_Text_NightSkyFavoriteScenery:
	.string "A circle of a night sky framed by\n"
	.string "the crater of a volcano…\p"
	.string "And in that ring, stars flicker and\n"
	.string "blink as if they were alive…\l"
	.string "It's my favorite scenery.$"

SootopolisCity_Text_WeatherWentWild:
	.string "The weather was clear this morning,\n"
	.string "but…\p"
	.string "All of a sudden, dark clouds brewed up,\n"
	.string "rain started falling in sheets, and\l"
	.string "there was thunder and lightning, too.\p"
	.string "The weather just went completely\n"
	.string "wild!\p"
	.string "Is all of this because of those\n"
	.string "Pokémon?$"

SootopolisCity_Text_YouBroughtFlyingMon:
	.string "Oh?\p"
	.string "It was you who brought that flying\n"
	.string "Pokémon here?\p"
	.string "Well, aren't you amazing!$"

SootopolisCity_Text_GroudonPleaseStop:
	.string "Maxie: Groudon!\n"
	.string "Please! Stop what you're doing!\p"
	.string "I know the extent of your power now!\p"
	.string "If you keep going, all Hoenn, not just\n"
	.string "Sootopolis, will be utterly ruined!$"

SootopolisCity_Text_IHaveCausedHarm:
	.string "Maxie: I have caused great harm, and for\n"
	.string "that I apologize most sincerely.\p"
	.string "I have committed wrongs so great as to\n"
	.string "bring the whole world to its knees.\p"
	.string "I have much to atone for, though it may\n"
	.string "be too much to assume that I should\l"
	.string "deserve the chance to start anything\l"
	.string "over.\p"
	.string "Child, you… No. I have no right to call\n"
	.string "you “child.” Fellow Trainer.\p"
	.string "Farewell.$"

SootopolisCity_Text_KyogreCalmDown:
	.string "Archie: Kyogre! Listen to me!\n"
	.string "Look over here! It's the Blue Orb!\l"
	.string "Calm down! Kyogre!\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "It's no good!\n"
	.string "It's not responding at all!$"

SootopolisCity_Text_TryingMeaninglessToPokemon:
	.string "Archie: Kyogre and Groudon both\n"
	.string "flew off to who knows where.\p"
	.string "The weather in Hoenn has returned\n"
	.string "to its normal state…\p"
	.string "Haha…\n"
	.string "Hahaha…\p"
	.string "The world I believed to be ideal… the\n"
	.string "kind of world that I dreamed of making,\l"
	.string "where I could live alongside my beloved\l"
	.string "Pokémon…\p"
	.string "Maybe what we were trying to do was\n"
	.string "something small, even meaningless,\l"
	.string "to Pokémon…\p"
	.string "I'm heading out to reflect.\n"
	.string "See ya, scamp.$"

SootopolisCity_Text_TabithaGroudonKyogre:
	.string "Tabitha: Dammit, all of our efforts to\n"
	.string "control Groudon have failed!\p"
	.string "At this rate, its fight with the other\n"
	.string "legendary Pokémon will cause\l"
	.string "unimaginable damage across Hoenn.$"

SootopolisCity_Text_TabithaRayquaza:
	.string "Tabitha: Without a doubt, we have\n"
	.string "committed an offense that can never be\l"
	.string "forgiven.\p"
	.string "We will accept responsibility and must\n"
	.string "now set things right.$"

SootopolisCity_Text_CourtneyGroudonKyogre:
	.string "Courtney: …Air pressure, rising.\n"
	.string "Wind speeds, rising.\l"
	.string "Temperature, rising.\l"
	.string "Hoenn destruction is imminent.$"

SootopolisCity_Text_CourtneyRayquaza:
	.string "Courtney: … … …\n"
	.string "Our impact, was grossly underestimated.\l"
	.string "Our crimes, regrettable.\p"
	.string "We… no… I trust in Maxie to move us\n"
	.string "forward on a better path.$"

SootopolisCity_Text_ShellyGroudonKyogre:
	.string "Shelly: Archie… the world you have\n"
	.string "dreamt of and the world that Kyogre\l"
	.string "will create are two very different\l"
	.string "places…\p"
	.string "What…have you done…$"

SootopolisCity_Text_ShellyRayquaza:
	.string "Shelly: Even if our leader is a big dolt\n"
	.string "who no one in the world will ever\l"
	.string "forgive, we still love him.\p"
	.string "We'll be staying with him forever.$"

SootopolisCity_Text_MattGroudonKyogre:
	.string "Matt: This is not cool, man.\n"
	.string "Really not cool!\p"
	.string "People and Pokémon are gonna get really\n"
	.string "hurt. This ain't what we wanted…$"

SootopolisCity_Text_MattRayquaza:
	.string "Matt: Whew! I'm glad that's over.\p"
	.string "Me and my bro, Archie…\n"
	.string "We ain't gonna cause trouble for\l"
	.string "anyone else anymore.$"

SootopolisCity_Text_StevenGreetsPlayer:
	.string "Steven: {PLAYER}!\n"
	.string "It's good to see you!\p"
	.string "The two legendary Pokémon, Groudon and\n"
	.string "Kyogre were awakened and are now\l"
	.string "smashing into each other.\p"
	.string "You being here now I'll take to mean\n"
	.string "that you're prepared to become\l"
	.string "involved in this crisis.\p"
	.string "The man next to me is my good friend,\n"
	.string "Wallace.$"

SootopolisCity_Text_WallaceGreetsPlayer:
	.string "Wallace: Hello, {PLAYER}.\p"
	.string "Normally I would introduce a fellow\n"
	.string "Trainer to my Gym, but given the current\l"
	.string "circumstance that will have to wait.$"

SootopolisCity_Text_StevenDiscussStorm::
	.string "Steven: The storm over Sootopolis is\n"
	.string "growing even more intense. Soon it will\l"
	.string "extend to all of Hoenn…\p"
	.string "If that were to happen… Hoenn will\n"
	.string "become devastated.\l"
	.string "If we had a way of clearing the sky…$"

SootopolisCity_Text_WallaceFollowToJuan::
	.string "Wallace: Clearing the sky…\p"
	.string "That reminds me of a legend I'd heard\n"
	.string "of another legendary Pokémon…\p"
	.string "I can't remember the details, but I know\n"
	.string "someone who would know more.\p"
	.string "Follow me!$"

SootopolisCity_Text_WallaceHailsJuan:
	.string "Wallace: Mentor, Juan!\p"
	.string "Those Pokémon down there fighting,\n"
	.string "isn't it just like that old legend you\l"
	.string "used to tell me about?$"

SootopolisCity_Text_JuanRayquazaLegend:
	.string "Juan: Indeed. The scene we see before\n"
	.string "us is the near spitting image of that\l"
	.string "old legend.\p"
	.string "Long ago, the two titans, Groudon and\n"
	.string "Kyogre fought over land and sea.\p"
	.string "Their battle caused devastation\n"
	.string "throughout the world.\p"
	.string "It wasn't until a third titan, the sky\n"
	.string "Pokémon, Rayquaza, arrived that the\l"
	.string "fighting ceased.\p"
	.string "Rayquaza cleared the skies and calmed\n"
	.string "Groudon and Kyogre, where they returned\l"
	.string "to their domains to slumber.$"

SootopolisCity_Text_StevenJustFindRayquaza:
	.string "Steven: So, that's it! We just need to\n"
	.string "find Rayquaza and it will put a stop to\l"
	.string "all this! Do you know where it is?$"

SootopolisCity_Text_JuanPerhaps:
	.string "Juan: Perhaps…$"

SootopolisCity_Text_JuanAsksWherePlayerFrom:
	.string "Juan: You are unfamiliar.\n"
	.string "May I ask where you are from?\p"
	.string "Ah, Littleroot. A quaint little place.\n"
	.string "Very much distant from the troubles of\l"
	.string "the world.\p"
	.string "If you are a friend of Steven, then I\n"
	.string "can trust you.\p"
	.string "Rayquaza resides at Sky Pillar on\n"
	.string "Route 131.\p"
	.string "The entrance is closed to all except\n"
	.string "yours truly, for I am the only one who\l"
	.string "possesses a key.\p"
	.string "I am reluctant to aid in the release of\n"
	.string "Rayquaza, however regarding the\l"
	.string "circumstances I see no other choice.\p"
	.string "Meet me at Sky Pillar.\n"
	.string "I shall open the way.$"

SootopolisCity_Text_StevenGoToSkyPillar:
	.string "Steven: We'll keep an eye on the\n"
	.string "situation here, {PLAYER}.\p"
	.string "You go to Sky Pillar on Route 131\n"
	.string "and wake up Rayquaza.$"

SootopolisCity_Text_WallaceMentorJuan:
	.string "Wallace: My mentor, Juan, is highly\n"
	.string "knowledgable and skilled.\p"
	.string "I can trust that you can wake Rayquaza\n"
	.string "so this mess can get sorted out.$"

SootopolisCity_Text_StevenRayquazaStoppedIt:
	.string "Steven: That was …astonishing.$"

SootopolisCity_Text_WallaceStevenDrooling:
	.string "Wallace: Ha, Steven! This is the first\n"
	.string "time I've seen you with that expression\l"
	.string "when you're not looking at your rocks!$"

SootopolisCity_Text_WallaceItsOver::
	.string "Wallace: It's over. Sootopolis is saved.\n"
	.string "No, all of Hoenn is saved.\p"
	.string "On behalf of all the people, I thank you.$"

SootopolisCity_Text_StevenThanksPlayerAndGivesMasterBall:
	.string "Steven: {PLAYER},\n"
	.string "we owe you a great thanks.\p"
	.string "The sky over Sootopolis has returned\n"
	.string "to normal.\p"
	.string "Team Magma and Team Aqua both wished to\n"
	.string "make the world a better place, but they\l"
	.string "went too far and nearly ruined it.\p"
	.string "I think this crisis has made them\n"
	.string "realize that.\p"
	.string "{PLAYER}, I would like to give you this.\n"
	.string "It's a prototype developed by the\l"
	.string "Devon Corporation.\p"
	.string "They call it the Master Ball. It can\n"
	.string "catch any Pokémon without fail.\p"
	.string "It was given as a gift to me, but I\n"
	.string "think a Trainer such as yourself will\l"
	.string "make better use of it.$"

SootopolisCity_Text_StevenLeaves:
	.string "{PLAYER}… I hope you will continue to\n"
	.string "travel this world and see its richness\l"
	.string "with your own eyes.\p"
	.string "But for the present, you may wish to\n"
	.string "challenge this city's Pokémon Gym.\p"
	.string "There, Wallace is waiting for you.\n"
	.string "He's strong. But the way you are now,\l"
	.string "you should be capable of battling him on\l"
	.string "an equal footing.\p"
	.string "Should we meet again, I hope you will be\n"
	.string "able to show me and my team what you've\l"
	.string "learned.\p"
	.string "Until then…$"

SootopolisCity_Text_Juan:
	.string "Juan: From you, I sense the brilliant\n"
	.string "shine of skill that will overcome all!\p"
	.string "However, you are somewhat lacking in\n"
	.string "elegance. Perhaps I should make you a\l"
	.string "loan of my outfit?\p"
	.string "Hahaha, I merely jest!$"
