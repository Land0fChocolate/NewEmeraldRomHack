.set LOCALID_RIVAL, 16
.set LOCALID_RIVAL_ON_BIKE, 17

Route119_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route119_OnResume
	map_script MAP_SCRIPT_ON_LOAD, Route119_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_OnTransition
	.byte 0

Route119_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route119_EventScript_TryRemoveKecleon
	end

Route119_EventScript_TryRemoveKecleon::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

Route119_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	call Common_EventScript_SetupRivalOnBikeGfxId
	compare VAR_WEATHER_INSTITUTE_STATE, 1
	call_if_eq Route119_EventScript_MoveInstituteWorkersDownstairs
	special SetRoute119Weather
	end

Route119_OnLoad:
	call_if_set FLAG_SET_HIDE_BIRD_KEEPER_BIKE_QUEST, Route119_EventScript_HideBirdKeeperBikeQuest
	call_if_unset FLAG_SYS_GAME_CLEAR, Route119_EventScript_CloseConquerorsCamp
	call_if_unset FLAG_SYS_GAME_CLEAR, Route119_EventScript_CloseFortreeJungleEntrance
	end

Route119_EventScript_HideBirdKeeperBikeQuest::
	setflag FLAG_HIDE_BIRD_KEEPER_BIKE_QUEST
	return

Route119_EventScript_CloseConquerorsCamp::
	setmetatile 12, 1, METATILE_General_SmallTree_SmallTree, 1
	setmetatile 10, 2, METATILE_General_SmallTree_SmallTree, 1
	setmetatile 11, 2, METATILE_General_SmallTree_SmallTree, 1
	setmetatile 12, 2, METATILE_General_SmallTree_SmallTree, 1
	setmetatile 13, 2, METATILE_General_SmallTree_SmallTree, 1
	setmetatile 14, 2, METATILE_General_SmallTree_SmallTree, 1
	setmetatile 10, 3, METATILE_General_SmallTree_SmallTree, 1
	setmetatile 11, 3, METATILE_General_SmallTree_SmallTree, 1
	setmetatile 12, 3, METATILE_General_SmallTree_SmallTree, 1
	setmetatile 13, 3, METATILE_General_SmallTree_SmallTree, 1
	setmetatile 14, 3, METATILE_General_SmallTree_SmallTree, 1
	setmetatile 10, 4, METATILE_General_SmallTree_SmallTree, 1
	setmetatile 11, 4, METATILE_General_SmallTree_SmallTree, 1
	setmetatile 12, 4, METATILE_General_SmallTree_SmallTree, 1
	setmetatile 13, 4, METATILE_General_SmallTree_SmallTree, 1
	setmetatile 14, 4, METATILE_General_SmallTree_SmallTree, 1
	setmetatile 12, 5, METATILE_General_SmallTree_GrassBase, 1
	setmetatile 13, 5, METATILE_General_SmallTree_GrassBase, 1
	setmetatile 14, 5, METATILE_General_SmallTree_GrassBase, 1
	setmetatile 15, 4, METATILE_General_RockWallEast_Ocean, 1
	setmetatile 15, 5, METATILE_General_RockWallEast_Ocean, 1
	setmetatile 16, 4, METATILE_Fortree_OceanWater, 1
	setmetatile 16, 5, METATILE_Fortree_OceanWater, 1
	setmetatile 16, 6, METATILE_Fortree_OceanWater, 1
	setmetatile 16, 7, METATILE_Fortree_OceanWater, 1
	setmetatile 17, 6, METATILE_Fortree_OceanWater, 1
	setmetatile 17, 7, METATILE_Fortree_OceanWater, 1
	setmetatile 18, 6, METATILE_General_RockWallWest_Ocean, 1
	setmetatile 18, 7, METATILE_General_RockWallWest_Ocean, 1
	setmetatile 19, 5, METATILE_General_SmallTree_SmallTree, 1
	setmetatile 19, 6, METATILE_Fortree_BigTreeTopLeft_SmallTreeTops, 1
	setmetatile 19, 7, METATILE_Fortree_BigTreeBotLeft_SmallTreeTops, 1
	setmetatile 19, 8, METATILE_Fortree_SmallTree_SmallTreeShadow, 1
	setmetatile 19, 9, METATILE_General_SmallTree_GrassBase, 1
	return

Route119_EventScript_CloseFortreeJungleEntrance::
	setmetatile 33, 102, METATILE_Fortree_CliffBotRight_SmallTree, 1
	setmetatile 33, 103, METATILE_Fortree_BigTreeTopLeft_SmallTreeTops, 1
	setmetatile 33, 104, METATILE_Fortree_BigTreeBotLeft_SmallTreeTops, 1
	setmetatile 33, 105, METATILE_General_SmallTree_SmallTree, 1
	setmetatile 33, 106, METATILE_General_SmallTree_SmallTree, 1
	setmetatile 33, 107, METATILE_General_SmallTree_GrassBase, 1
	setmetatile 34, 103, METATILE_Fortree_BigTreeTopMid_SmallTreeTops, 1
	setmetatile 34, 104, METATILE_Fortree_BigTreeBotMid, 1
	setmetatile 34, 105, METATILE_Fortree_BigTree_Trunk, 1
	setmetatile 34, 106, METATILE_Fortree_BigTree_SmallTreeTop, 1
	setmetatile 35, 103, METATILE_Fortree_BigTreeTopRight_SmallTreeTops, 1
	setmetatile 35, 104, METATILE_Fortree_BigTreeBotRight_SmallTreeTops, 1
	setmetatile 35, 105, METATILE_General_SmallTree_SmallTree, 1
	setmetatile 35, 106, METATILE_General_SmallTree_SmallTree, 1
	setmetatile 36, 103, METATILE_General_SmallTree_SmallTree, 1
	setmetatile 36, 104, METATILE_General_SmallTree_SmallTree, 1
	setmetatile 36, 105, METATILE_General_SmallTree_SmallTree, 1
	setmetatile 36, 106, METATILE_General_SmallTree_SmallTree, 1
	setmetatile 37, 103, METATILE_General_SmallTree_SmallTree, 1
	setmetatile 37, 104, METATILE_Fortree_BigTreeTopLeft_SmallTreeTops, 1
	setmetatile 37, 105, METATILE_Fortree_BigTreeBotLeft_SmallTreeTops, 1
	setmetatile 37, 106, METATILE_General_SmallTree_SmallTree, 1
	setmetatile 38, 103, METATILE_General_SmallTree_SmallTree, 1
	setmetatile 38, 104, METATILE_Fortree_BigTreeTopMid_SmallTreeTops, 1
	return
	
Route119_EventScript_Rival::
	lock
	faceplayer
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq Route119_EventScript_PlayMayMusic
	compare VAR_RESULT, FEMALE
	call_if_eq Route119_EventScript_PlayBrendanMusic
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_set FLAG_MET_RIVAL_ROUTE_119 Route119_EventScript_MayAskToBattle
	compare VAR_RESULT, FEMALE
	goto_if_set FLAG_MET_RIVAL_ROUTE_119 Route119_EventScript_BrendanAskToBattle
	setflag FLAG_MET_RIVAL_ROUTE_119
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route119_EventScript_IntroMay
	compare VAR_RESULT, FEMALE
	goto_if_eq Route119_EventScript_IntroBrendan
	release
	end

Route119_EventScript_MoveInstituteWorkersDownstairs::
	setflag FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS
	clearflag FLAG_HIDE_WEATHER_INSTITUTE_2F_CASTFORM
	clearflag FLAG_HIDE_WEATHER_INSTITUTE_1F_WORKERS
	setvar VAR_WEATHER_INSTITUTE_STATE, 2
	return

Route119_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

Route119_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

Route119_EventScript_IntroMay::
	msgbox Route119_Text_MayIntro, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route119_EventScript_BattleMay
	msgbox Route119_Text_MaySomeOtherTimeThen, MSGBOX_DEFAULT
	call Route119_EventScript_RestoreBgm
	releaseall
	end

Route119_EventScript_MayAskToBattle::
	msgbox Route119_Text_MayAskToBattle, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route119_EventScript_BattleMay
	msgbox Route119_Text_MaySomeOtherTimeThen, MSGBOX_DEFAULT
	call Route119_EventScript_RestoreBgm
	releaseall
	end

Route119_EventScript_BattleMay::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_BattleMayTreecko
	case 1, Route119_EventScript_BattleMayTorchic
	case 2, Route119_EventScript_BattleMayMudkip
	end

Route119_EventScript_BattleMayTreecko::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_TREECKO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_BattleMayTorchic::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_TORCHIC, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_BattleMayMudkip::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_MUDKIP, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_DefeatedMay::
	setflag FLAG_ROUTE_119_HIDE_RIVAL
	msgbox Route119_Text_MayPresentForYou, MSGBOX_DEFAULT
	call Route119_EventScript_GiveTM76
	msgbox Route119_Text_MayExplainFly, MSGBOX_DEFAULT
	goto Route119_EventScript_RivalExit
	end

Route119_EventScript_IntroBrendan::
	msgbox Route119_Text_BrendanIntro, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route119_EventScript_BattleBrendan
	msgbox Route119_Text_BrendanSomeOtherTimeThen, MSGBOX_DEFAULT
	call Route119_EventScript_RestoreBgm
	releaseall
	end

Route119_EventScript_BrendanAskToBattle::
	msgbox Route119_Text_BrendanAskToBattle, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route119_EventScript_BattleBrendan
	msgbox Route119_Text_BrendanSomeOtherTimeThen, MSGBOX_DEFAULT
	call Route119_EventScript_RestoreBgm
	releaseall
	end

Route119_EventScript_BattleBrendan::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_BattleBrendanTreecko
	case 1, Route119_EventScript_BattleBrendanTorchic
	case 2, Route119_EventScript_BattleBrendanMudkip
	end

Route119_EventScript_BattleBrendanTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_TREECKO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_BattleBrendanTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_TORCHIC, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_BattleBrendanMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_MUDKIP, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_DefeatedBrendan::
	setflag FLAG_ROUTE_119_HIDE_RIVAL
	msgbox Route119_Text_BrendanIllGiveYouThis, MSGBOX_DEFAULT
	call Route119_EventScript_GiveTM76
	msgbox Route119_Text_BrendanExplainFly, MSGBOX_DEFAULT
	goto Route119_EventScript_RivalExit
	end

Route119_EventScript_GiveTM76::
	giveitem ITEM_TM76
	setflag FLAG_RECEIVED_TM76
	return

Route119_EventScript_RestoreBgm::
	savebgm MUS_DUMMY
	fadedefaultbgm
	return

Route119_EventScript_RivalExit::
	closemessage
	removeobject LOCALID_RIVAL
	addobject LOCALID_RIVAL_ON_BIKE
	delay 20
	getplayerxy VAR_0x8004, VAR_0x8005
	compare VAR_0x8004, 19
	goto_if_eq Route119_PlayerMoveOutOfWay
Route119_EventScript_RivalExitPart2::
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, Route119_Movement_WatchRivalExit
	applymovement LOCALID_RIVAL_ON_BIKE, Route119_Movement_RivalExit
	waitmovement 0
	setflag FLAG_HIDE_ROUTE_119_RIVAL_ON_BIKE
	removeobject LOCALID_RIVAL_ON_BIKE
	call Route119_EventScript_RestoreBgm
	releaseall
	end

Route119_PlayerMoveOutOfWay::
	applymovement OBJ_EVENT_ID_PLAYER Route119_Movement_PlayerMoveOutOfWay
	goto Route119_EventScript_RivalExitPart2

Route119_Movement_PlayerMoveOutOfWay::
	walk_down
	face_right
	step_end

Route119_Movement_RivalExit::
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	step_end

Route119_Movement_WatchRivalExit::
	delay_16
	face_right
	step_end

Route119_EventScript_CyclingTriathleteM::
	msgbox Route119_Text_TallGrassSnaresBikeTires, MSGBOX_NPC
	end

Route119_EventScript_RouteSignFortree::
	msgbox Route119_Text_RouteSignFortree, MSGBOX_SIGN
	end

Route119_EventScript_WeatherInstituteSign::
	msgbox Route119_Text_WeatherInstitute, MSGBOX_SIGN
	end

Route119_EventScript_Brent::
	trainerbattle_single TRAINER_BRENT, Route119_Text_BrentIntro, Route119_Text_BrentDefeat
	msgbox Route119_Text_BrentPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Donald::
	trainerbattle_single TRAINER_DONALD, Route119_Text_DonaldIntro, Route119_Text_DonaldDefeat
	msgbox Route119_Text_DonaldPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Taylor::
	trainerbattle_single TRAINER_TAYLOR, Route119_Text_TaylorIntro, Route119_Text_TaylorDefeat
	msgbox Route119_Text_TaylorPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Doug::
	trainerbattle_single TRAINER_DOUG, Route119_Text_DougIntro, Route119_Text_DougDefeat
	msgbox Route119_Text_DougPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Greg::
	trainerbattle_single TRAINER_GREG, Route119_Text_GregIntro, Route119_Text_GregDefeat
	msgbox Route119_Text_GregPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Kent::
	trainerbattle_single TRAINER_KENT, Route119_Text_KentIntro, Route119_Text_KentDefeat
	msgbox Route119_Text_KentPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Jackson::
	trainerbattle_single TRAINER_JACKSON_1, Route119_Text_JacksonIntro, Route119_Text_JacksonDefeat, Route119_EventScript_RegisterJackson
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route119_EventScript_RematchJackson
	msgbox Route119_Text_JacksonPostBattle, MSGBOX_DEFAULT
	release
	end

Route119_EventScript_RegisterJackson::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route119_Text_JacksonRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JACKSON_1
	release
	end

Route119_EventScript_RematchJackson::
	trainerbattle_rematch TRAINER_JACKSON_1, Route119_Text_JacksonRematchIntro, Route119_Text_JacksonRematchDefeat
	msgbox Route119_Text_JacksonPostRematch, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Catherine::
	trainerbattle_single TRAINER_CATHERINE_1, Route119_Text_CatherineIntro, Route119_Text_CatherineDefeat, Route119_EventScript_RegisterCatherine
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route119_EventScript_RematchCatherine
	msgbox Route119_Text_CatherinePostBattle, MSGBOX_DEFAULT
	release
	end

Route119_EventScript_RegisterCatherine::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route119_Text_CatherineRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CATHERINE_1
	release
	end

Route119_EventScript_RematchCatherine::
	trainerbattle_rematch TRAINER_CATHERINE_1, Route119_Text_CatherineRematchIntro, Route119_Text_CatherineRematchDefeat
	msgbox Route119_Text_CatherinePostRematch, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Hugh::
	trainerbattle_single TRAINER_HUGH, Route119_Text_HughIntro, Route119_Text_HughDefeat
	msgbox Route119_Text_HughPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Phil::
	trainerbattle_single TRAINER_PHIL, Route119_Text_PhilIntro, Route119_Text_PhilDefeat
	msgbox Route119_Text_PhilPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Yasu::
	trainerbattle_single TRAINER_YASU, Route119_Text_YasuIntro, Route119_Text_YasuDefeat
	msgbox Route119_Text_YasuPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Takashi::
	trainerbattle_single TRAINER_TAKASHI, Route119_Text_TakashiIntro, Route119_Text_TakashiDefeat
	msgbox Route119_Text_TakashiPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Hideo::
	trainerbattle_single TRAINER_HIDEO, Route119_Text_HideoIntro, Route119_Text_HideoDefeat
	msgbox Route119_Text_HideoPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Chris::
	trainerbattle_single TRAINER_CHRIS, Route119_Text_ChrisIntro, Route119_Text_ChrisDefeat
	msgbox Route119_Text_ChrisPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Fabian::
	trainerbattle_single TRAINER_FABIAN, Route119_Text_FabianIntro, Route119_Text_FabianDefeat
	msgbox Route119_Text_FabianPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Rachel::
	trainerbattle_single TRAINER_RACHEL, Route119_Text_RachelIntro, Route119_Text_RachelDefeat
	msgbox Route119_Text_RachelPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Cristin::
	trainerbattle_single TRAINER_CRISTIN, Route119_Text_CristinIntro, Route119_Text_CristinDefeat
	msgbox Route119_Text_CristinPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_BridgeAquaGrunt1::
	lock
	faceplayer
	msgbox Route119_Text_StayAwayFromWeatherInstitute, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route119_EventScript_BridgeAquaGrunt2::
	lock
	faceplayer
	msgbox Route119_Text_DontGoNearWeatherInstitute, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route119_EventScript_BirdKeeperBikeQuest::
	lock
	faceplayer
	goto_if_set FLAG_SET_HIDE_BIRD_KEEPER_BIKE_QUEST, Route119_EventScript_BirdKeeperBikeQuest_WillGetBike
	specialvar VAR_RESULT, GetPlayerAvatarBike
	compare VAR_RESULT, 0
	goto_if_eq Route119_EventScript_BirdKeeperBikeQuest_NoBike
	msgbox Route119_Text_ILikeYourBike, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SET_HIDE_BIRD_KEEPER_BIKE_QUEST
	addvar VAR_BIKE_UPGRADE_STATE, 1
	release
	end

Route119_EventScript_BirdKeeperBikeQuest_NoBike::
	msgbox Route119_Text_NoBike, MSGBOX_DEFAULT
	closemessage
	release
	end

Route119_EventScript_BirdKeeperBikeQuest_WillGetBike::
	msgbox Route119_Text_WillGetBike, MSGBOX_DEFAULT
	closemessage
	release
	end

Route119_EventScript_Boy1::
	msgbox Route119_Text_ThoughtFlyByCatchingBirdMons, MSGBOX_NPC
	end

Route119_EventScript_Boy2::
	msgbox Route119_Text_CanYourMonMakeSecretBase, MSGBOX_NPC
	end

Route119_EventScript_TrainerTipsDecoration::
	msgbox Route119_Text_TrainerTipsDecoration, MSGBOX_SIGN
	end

Route119_Text_MayIntro:
	.string "May: Hey, {PLAYER}{KUN}!\p"
	.string "Me and my Pokémon are already feeling\n"
	.string "refreshed after that ugly business.\p"
	.string "This is a nice scene, don't you think?\n"
	.string "It's a great spot for a Pokémon battle!\p"
	.string "It would be nice to see your Pokémon\n"
	.string "in a one-on-one. Are you up for it?$"

Route119_Text_MaySomeOtherTimeThen:
	.string "Oh, some other time then.$"

Route119_Text_MayAskToBattle:
	.string "Are you up for a battle?$"

Route119_Text_MayDefeat:
	.string "Achah!\n"
	.string "{PLAYER}{KUN}, you're strong!\p"
	.string "Well, it's no surprise seeing how you\n"
	.string "sent those Aquas running.$"

Route119_Text_MayPresentForYou:
	.string "May: That was fun, and now I have a\n"
	.string "present for you.$"

Route119_Text_MayExplainFly:
	.string "May: Some Aqua goon left this behind.\n"
	.string "I figured he wasn't going to need it\l"
	.string "anymore so I took it.\p"
	.string "But, then I found I didn't really need it\n"
	.string "either so I'm offloading it onto you.\p"
	.string "Or you can think of it as thanks for the\n"
	.string "help back there.\p"
	.string "Well, we'll see each other again\n"
	.string "somewhere! Bye!$"

Route119_Text_BrendanIntro:
	.string "Brendan: Hey, {PLAYER}{KUN}!\p"
	.string "Me and my Pokémon have already\n"
	.string "rested after that episode, we're\l"
	.string "just chilling on this bridge.\p"
	.string "My Pokémon are actually still fired\n"
	.string "up from fighting with you.\p"
	.string "Shall we go for a round, just\n"
	.string "one against one this time?$"

Route119_Text_BrendanSomeOtherTimeThen:
	.string "Oh, some other time then.$"

Route119_Text_BrendanAskToBattle:
	.string "Are you up for a battle?$"

Route119_Text_BrendanDefeat:
	.string "Hmm…\n"
	.string "Yeah, that's about what I figured.\n"
	.string "I'm not as strong as that Aqua boss.$"

Route119_Text_BrendanIllGiveYouThis:
	.string "Brendan: I think my Pokémon have had\n"
	.string "their fill of battling for today.\p"
	.string "Oh, and here, I'll give you this.\n"
	.string "Try it out.$"

Route119_Text_BrendanExplainFly:
	.string "Brendan: A Team Aqua member\n"
	.string "dropped that when he was leaving\l"
	.string "the Weather Institute.\p"
	.string "I don't need it, so I guess you\n"
	.string "can have it.\p"
	.string "Anyway, I'll catch you later. Bye!$"

Route119_Text_StayAwayFromWeatherInstitute:
	.string "We're standing lookout here.\p"
	.string "Hey, you! Stay away from the Weather\n"
	.string "Institute. It's not safe.$"

Route119_Text_DontGoNearWeatherInstitute:
	.string "Lookout duty is surprisingly boring.\p"
	.string "Hey, you! Please don't go near the\n"
	.string "Weather Institute.$"

Route119_Text_ThoughtFlyByCatchingBirdMons:
	.string "I thought you fly by catching a whole\n"
	.string "flock of bird Pokémon, and then\l"
	.string "hanging on to them somehow.\p"
	.string "But it turns out there's a field\n"
	.string "move called Fly!\p"
	.string "I wish I'd known about that a long\n"
	.string "time ago…$"

Route119_Text_TallGrassSnaresBikeTires:
	.string "Tch…\n"
	.string "It's a no-go…\p"
	.string "The tall grass snares bike tires.\n"
	.string "There's no way you can cycle here.$"

Route119_Text_CanYourMonMakeSecretBase:
	.string "Can your Pokémon use its Secret Power\n"
	.string "on a big pile of grass and make a\l"
	.string "Secret Base?$"

Route119_Text_RouteSignFortree:
	.string "ROUTE 119\n"
	.string "{RIGHT_ARROW} FORTREE CITY$"

Route119_Text_WeatherInstitute:
	.string "WEATHER INSTITUTE$"

Route119_Text_TrainerTipsDecoration:
	.string "TRAINER TIPS\p"
	.string "Up to sixteen decorations and\n"
	.string "furniture items can be placed in\l"
	.string "a Secret Base.\p"
	.string "Pick your favorite items and create\n"
	.string "your very own Secret Base exactly the\l"
	.string "way you want.$"

Route119_Text_NoBike:
	.string "I wanted to check out this little\n"
	.string "isolated patch so I got my bird Pokémon\l"
	.string "to carry me here.\p"
	.string "They got really tired though.\n"
	.string "I wish I could find another way to move\l"
	.string "around without putting strain on my\l"
	.string "birds…$"

Route119_Text_ILikeYourBike:
	.string "Woah! The way you got over here on your\n"
	.string "bike was so cool and elegant, like a\l"
	.string "bird!\p"
	.string "You got that bike from Mauville, yeah?\n"
	.string "I gotta get me one of those.$"

Route119_Text_WillGetBike:
	.string "Ooh, I'm just imagining how much fun it\n"
	.string "would be to ride a bike with my birds\l"
	.string "flying alongside me!$"
