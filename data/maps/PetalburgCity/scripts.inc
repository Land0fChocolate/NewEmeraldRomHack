.set LOCALID_WALLY, 2
.set LOCALID_BOY, 3
.set LOCALID_GYM_BOY, 7
.set LOCALID_CELEBI, 11
.set LOCALID_SHRINE_MAIDEN, 12

PetalburgCity_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, PetalburgCity_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_OnFrame
	.byte 0

PetalburgCity_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, PetalburgCity_EventScript_TryRemoveCelebi
	end

PetalburgCity_OnTransition:
	setflag FLAG_VISITED_PETALBURG_CITY
	compare VAR_PETALBURG_CITY_STATE, 0
	call_if_eq PetalburgCity_EventScript_MoveGymBoyToWestEntrance
	compare VAR_PETALBURG_CITY_STATE, 2
	call_if_eq PetalburgCity_EventScript_DisableMapNameAndMusic
	compare VAR_PETALBURG_CITY_STATE, 4
	call_if_eq PetalburgCity_EventScript_DisableMapNameAndMusic
	compare VAR_PETALBURG_GYM_STATE, 8
	call_if_eq PetalburgCity_EventScript_SetGymDoorsUnlocked
	call_if_unset FLAG_SYS_GAME_CLEAR, PetalburgCity_EventScript_MoveShrineMaiden
	end

PetalburgCity_EventScript_MoveShrineMaiden::
	setobjectxyperm LOCALID_SHRINE_MAIDEN, 18, 7
	setobjectmovementtype LOCALID_SHRINE_MAIDEN, MOVEMENT_TYPE_LOOK_AROUND
	return

PetalburgCity_EventScript_TryRemoveCelebi::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject LOCALID_CELEBI
	return

PetalburgCity_EventScript_Celebi::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CELEBI, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_CELEBI, 30, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_TEMP_1, 0
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq PetalburgCity_EventScript_DefeatedCelebi
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq PetalburgCity_EventScript_RanFromCelebi
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq PetalburgCity_EventScript_RanFromCelebi
	setflag FLAG_DEFEATED_CELEBI
	setflag FLAG_HIDE_PETALBURG_CITY_CELEBI
	release
	end

PetalburgCity_EventScript_DefeatedCelebi::
	setflag FLAG_DEFEATED_CELEBI
	setflag FLAG_HIDE_PETALBURG_CITY_CELEBI
	goto Common_EventScript_RemoveStaticPokemon
	end

PetalburgCity_EventScript_RanFromCelebi::
	setvar VAR_0x8004, SPECIES_CELEBI
	goto Common_EventScript_LegendaryFlewAway
	end

PetalburgCity_EventScript_ShrineMaiden::
	goto_if_unset FLAG_SYS_GAME_CLEAR, PetalburgCity_EventScript_ShrineIsClosed
	goto_if_set FLAG_OBTAINED_ALL_BERRIES_FOR_SHRINE, PetalburgCity_EventScript_ShrineIsHappy
	msgbox PetalburgCity_Text_ImpressShrine, MSGBOX_NPC
	end

PetalburgCity_EventScript_ShrineIsClosed::
	msgbox PetalburgCity_Text_ShrineIsClosed, MSGBOX_NPC
	end

PetalburgCity_EventScript_ShrineIsHappy::
	msgbox PetalburgCity_Text_ShrineIsHappy, MSGBOX_NPC
	end

PetalburgCity_EventScript_ShrineIsClosedTrigger::
	lockall
	applymovement LOCALID_SHRINE_MAIDEN, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_SHRINE_MAIDEN, Common_Movement_ExclamationMark
	waitmovement 0
	delay 20
	msgbox PetalburgCity_Text_ShrineIsClosed, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_WalkDown
	waitmovement 0
	releaseall
	end

PetalburgCity_Movement_WalkDown:
	walk_down
	step_end

PetalburgCity_EventScript_Shrine::
	msgbox PetalburgCity_Text_Shrine, MSGBOX_SIGN
	goto_if_unset FLAG_OBTAINED_ALL_BERRIES_FOR_SHRINE, PetalburgCity_EventScript_CheckForEveryBerry
	end

@ Checks for every berry up to Starf
PetalburgCity_EventScript_CheckForEveryBerry::
	setvar VAR_TEMP_1, 0
	checkitem ITEM_CHERI_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_CHESTO_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_PECHA_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_RAWST_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_ASPEAR_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_LEPPA_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_ORAN_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_PERSIM_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_LUM_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_SITRUS_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_FIGY_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_WIKI_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_MAGO_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_AGUAV_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_IAPAPA_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_RAZZ_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_BLUK_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_NANAB_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_WEPEAR_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_PINAP_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_POMEG_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_KELPSY_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_QUALOT_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_HONDEW_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_GREPA_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_TAMATO_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_CORNN_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_MAGOST_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_RABUTA_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_NOMEL_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_SPELON_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_PAMTRE_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_WATMEL_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_DURIN_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_BELUE_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_CHILAN_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_OCCA_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_PASSHO_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_WACAN_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_RINDO_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_YACHE_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_CHOPLE_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_KEBIA_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_SHUCA_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_COBA_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_PAYAPA_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_TANGA_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_CHARTI_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_KASIB_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_HABAN_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_COLBUR_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_BABIRI_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_ROSELI_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_LIECHI_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_GANLON_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_SALAC_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_PETAYA_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_APICOT_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_LANSAT_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	checkitem ITEM_STARF_BERRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq PetalburgCity_EventScript_AddToBerryCount
	compare VAR_TEMP_1, 60
	goto_if_ge PetalburgCity_EventScript_ObtainedAllBerries
	return

PetalburgCity_EventScript_AddToBerryCount::
	addvar VAR_TEMP_1, 1
	return

PetalburgCity_EventScript_ObtainedAllBerries::
	msgbox PetalburgCity_Text_ShrineWarpsAndGlows, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_PETALBURG_CITY_CELEBI
	addobject LOCALID_CELEBI
	applymovement LOCALID_CELEBI, PetalburgCity_Movement_CelebiEntrance
	waitmovement 0
	playmoncry SPECIES_CELEBI, 0
	waitmoncry
	setflag FLAG_OBTAINED_ALL_BERRIES_FOR_SHRINE
	end

PetalburgCity_Movement_CelebiEntrance:
	delay_4
	face_left
	delay_4
	face_up
	delay_4
	face_right
	delay_4
	face_down
	delay_8
	face_left
	delay_8
	face_up
	delay_8
	face_right
	delay_8
	face_down
	delay_16
	face_left
	delay_16
	face_up
	delay_16
	face_right
	delay_16
	face_down
	step_end

PetalburgCity_EventScript_MoveGymBoyToWestEntrance::
	setobjectxyperm LOCALID_GYM_BOY, 5, 19
	return

PetalburgCity_EventScript_DisableMapNameAndMusic::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	savebgm MUS_FOLLOW_ME
	return

PetalburgCity_EventScript_SetGymDoorsUnlocked::
	setvar VAR_PETALBURG_GYM_STATE, 7
	return

PetalburgCity_OnFrame:
	map_script_2 VAR_PETALBURG_CITY_STATE, 2, PetalburgCity_EventScript_WallyTutorial
	.2byte 0

PetalburgCity_EventScript_WallyTutorial::
	lockall
	special SavePlayerParty
	special PutZigzagoonInPlayerParty
	applymovement LOCALID_WALLY, PetalburgCity_Movement_WallyTutorialWally
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_WallyTutorialPlayer
	waitmovement 0
	msgbox Route102_Text_WatchMeCatchPokemon, MSGBOX_DEFAULT
	special StartWallyTutorialBattle
	waitstate
	msgbox Route102_Text_WallyIDidIt, MSGBOX_DEFAULT
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFastestLeft, MAP_PETALBURG_CITY
	waitmovement LOCALID_WALLY, MAP_PETALBURG_CITY
	msgbox Route102_Text_LetsGoBack, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_PETALBURG_CITY_STATE, 3
	fadedefaultbgm
	clearflag FLAG_DONT_TRANSITION_MUSIC
	special LoadPlayerParty
	setvar VAR_PETALBURG_GYM_STATE, 1
	warp MAP_PETALBURG_CITY_GYM, 255, 4, 108
	waitstate
	releaseall
	end

PetalburgCity_EventScript_Boy::
	lock
	faceplayer
	msgbox PetalburgCity_Text_WaterReflection, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BOY, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PetalburgCity_EventScript_WallysMom::
	msgbox PetalburgCity_Text_WhereIsWally, MSGBOX_NPC
	end

PetalburgCity_Movement_WalkToWallyHousePlayer:
	delay_8
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PetalburgCity_Movement_WalkInsideHousePlayer:
	walk_up
	walk_up
	step_end

PetalburgCity_Movement_WalkToWallyHouseWallysDad:
	delay_8
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
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
	step_end

PetalburgCity_Movement_WalkInsideHouseWallysDad:
	walk_up
	set_invisible
	step_end

PetalburgCity_Movement_WallyTutorialPlayer:
	delay_8
	walk_down
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
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_in_place_fastest_right
	step_end

PetalburgCity_Movement_WallyTutorialWally:
	delay_8
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
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	delay_16
	walk_in_place_fastest_up
	delay_16
	delay_16
	walk_in_place_fastest_right
	step_end

PetalburgCity_EventScript_GymSign::
	msgbox PetalburgCity_Text_GymSign, MSGBOX_SIGN
	end

PetalburgCity_EventScript_CitySign::
	msgbox PetalburgCity_Text_CitySign, MSGBOX_SIGN
	end

PetalburgCity_EventScript_Gentleman::
	msgbox PetalburgCity_Text_FullPartyExplanation, MSGBOX_NPC
	end

PetalburgCity_EventScript_WallyHouseSign::
	msgbox PetalburgCity_Text_WallyHouseSign, MSGBOX_SIGN
	end

PetalburgCity_EventScript_ShowGymToPlayer0::
	lockall
	setvar VAR_0x8008, 0
	goto PetalburgCity_EventScript_ShowGymToPlayer
	end

PetalburgCity_EventScript_ShowGymToPlayer1::
	lockall
	setvar VAR_0x8008, 1
	goto PetalburgCity_EventScript_ShowGymToPlayer
	end

PetalburgCity_EventScript_ShowGymToPlayer2::
	lockall
	setvar VAR_0x8008, 2
	goto PetalburgCity_EventScript_ShowGymToPlayer
	end

PetalburgCity_EventScript_ShowGymToPlayer3::
	lockall
	setvar VAR_0x8008, 3
	goto PetalburgCity_EventScript_ShowGymToPlayer
	end

PetalburgCity_EventScript_ShowGymToPlayer::
	applymovement LOCALID_GYM_BOY, Common_Movement_FacePlayer
	waitmovement 0
	playbgm MUS_FOLLOW_ME, FALSE
	playse SE_PIN
	applymovement LOCALID_GYM_BOY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_GYM_BOY, Common_Movement_Delay48
	waitmovement 0
	compare VAR_0x8008, 0
	call_if_eq PetalburgCity_EventScript_BoyApproachPlayer0
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_EventScript_BoyApproachPlayer1
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_EventScript_BoyApproachPlayer2
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_EventScript_BoyApproachPlayer3
	msgbox PetalburgCity_Text_AreYouRookieTrainer, MSGBOX_DEFAULT
	closemessage
	compare VAR_0x8008, 0
	call_if_eq PetalburgCity_EventScript_LeadPlayerToGym0
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_EventScript_LeadPlayerToGym1
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_EventScript_LeadPlayerToGym2
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_EventScript_LeadPlayerToGym3
	msgbox PetalburgCity_Text_ThisIsPetalburgGym, MSGBOX_DEFAULT
	applymovement LOCALID_GYM_BOY, Common_Movement_WalkInPlaceFastestRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox PetalburgCity_Text_ThisIsGymSign, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyWalkAway
	waitmovement 0
	fadedefaultbgm
	releaseall
	end

PetalburgCity_EventScript_BoyApproachPlayer0::
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyApproachPlayer0
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

PetalburgCity_EventScript_BoyApproachPlayer1::
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyApproachPlayer1
	waitmovement 0
	return

PetalburgCity_EventScript_BoyApproachPlayer2::
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyApproachPlayer2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	return

PetalburgCity_EventScript_BoyApproachPlayer3::
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyApproachPlayer3
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	return

PetalburgCity_EventScript_LeadPlayerToGym0::
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyWalkToGym0
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_PlayerWalkToGym0
	waitmovement 0
	return

PetalburgCity_EventScript_LeadPlayerToGym1::
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyWalkToGym1
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_PlayerWalkToGym1
	waitmovement 0
	return

PetalburgCity_EventScript_LeadPlayerToGym2::
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyWalkToGym2
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_PlayerWalkToGym2
	waitmovement 0
	return

PetalburgCity_EventScript_LeadPlayerToGym3::
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyWalkToGym3
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_PlayerWalkToGym3
	waitmovement 0
	return

@ Unused
PetalburgCity_Movement_Delay48::
	delay_16
	delay_16
	delay_16
	step_end

PetalburgCity_Movement_BoyApproachPlayer0:
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

PetalburgCity_Movement_BoyApproachPlayer1:
	walk_right
	walk_right
	step_end

PetalburgCity_Movement_BoyApproachPlayer2:
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_down
	step_end

PetalburgCity_Movement_BoyApproachPlayer3:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_down
	step_end

PetalburgCity_Movement_BoyWalkToGym0:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_right
	walk_in_place_fastest_up
	step_end

PetalburgCity_Movement_BoyWalkToGym1:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_in_place_fastest_up
	step_end

PetalburgCity_Movement_BoyWalkToGym2:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_right
	walk_in_place_fastest_up
	step_end

PetalburgCity_Movement_BoyWalkToGym3:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_in_place_fastest_up
	step_end

PetalburgCity_Movement_BoyWalkAway:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_PlayerWalkToGym0:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

PetalburgCity_Movement_PlayerWalkToGym1:
	delay_16
	delay_16
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

PetalburgCity_Movement_PlayerWalkToGym2:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

PetalburgCity_Movement_PlayerWalkToGym3:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

PetalburgCity_EventScript_GymBoy::
	msgbox PetalburgCity_Text_AreYouRookieTrainer, MSGBOX_NPC
	end

PetalburgCity_Text_WhereIsWally:
	.string "Where has our Wally gone?\p"
	.string "We have to leave for Verdanturf Town\n"
	.string "very soon…$"

PetalburgCity_Text_AreYouRookieTrainer:
	.string "Hiya! Are you maybe…\n"
	.string "A rookie Trainer?\p"
	.string "Do you know what Pokémon Trainers\n"
	.string "do when they reach a new town?\p"
	.string "They first check what kind of Gym\n"
	.string "is in the town.$"

PetalburgCity_Text_ThisIsPetalburgGym:
	.string "See? This is Petalburg City's Gym.$"

PetalburgCity_Text_ThisIsGymSign:
	.string "This is the Gym's sign. Look for it\n"
	.string "whenever you're looking for a Gym.$"

PetalburgCity_Text_WaterReflection:
	.string "My face is reflected in the water.\p"
	.string "It's a shining grin full of hope…\p"
	.string "Or it could be a look of somber silence\n"
	.string "struggling with fear…\p"
	.string "What do you see reflected in your face?$"

PetalburgCity_Text_FullPartyExplanation:
	.string "Let's say you have six Pokémon.\n"
	.string "If you catch another one…\p"
	.string "It is automatically sent to a Storage\n"
	.string "Box over a PC connection.$"

PetalburgCity_Text_ShrineIsClosed:
	.string "Oh, hello!\p"
	.string "I'm so sorry, but the shrine is closed\n"
	.string "for maintainance.\p"
	.string "Please visit another time.$"

PetalburgCity_Text_ImpressShrine:
	.string "Have you come to pray at the shrine?\n"
	.string "It may be difficult to get a blessing…\p"
	.string "If someone had collected at least one\n"
	.string "of every berry in Hoenn, I am sure\l"
	.string "that the Pokémon of the shrine would\l"
	.string "be impressed.$"

PetalburgCity_Text_ShrineIsHappy:
	.string "The shrine is looking more vibrant\n"
	.string "than usual.\p"
	.string "You must have made the shrine Pokémon\n"
	.string "very happy.$"

PetalburgCity_Text_Shrine:
	.string "An immaculately kept shrine.$"

PetalburgCity_Text_ShrineWarpsAndGlows:
	.string "The shrine warps and glows.\p"
	.string "A rift appears!\p"
	.string "A Pokémon came out!$"

PetalburgCity_Text_GymSign:
	.string "PETALBURG CITY POKéMON GYM\n"
	.string "LEADER: NORMAN\l"
	.string "“A man in pursuit of power!”$"

PetalburgCity_Text_CitySign:
	.string "PETALBURG CITY\n"
	.string "“Where people mingle with nature.”$"

PetalburgCity_Text_WallyHouseSign:
	.string "WALLY'S HOUSE$"
