.set LOCALID_GRUNT_1, 1 @left door guard
.set LOCALID_GRUNT_2, 2 @right door guard
.set LOCALID_GRUNT_3, 3 @beaten
.set LOCALID_GRUNT_4, 4 @beaten, behind Archie
.set LOCALID_GRUNT_5, 5 @beaten, kicked back
.set LOCALID_SHELLY, 6
.set LOCALID_ARCHIE, 7
.set LOCALID_RIVAL, 8
.set LOCALID_SCIENTIST, 10

Route119_WeatherInstitute_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_2F_OnTransition
	.byte 0

Route119_WeatherInstitute_2F_OnTransition:
	compare VAR_WEATHER_INSTITUTE_STATE, 0
	call_if_eq Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaHere
	compare VAR_WEATHER_INSTITUTE_STATE, 1
	call_if_eq Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaGone
	call_if_set FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_2F_EventScript_SetScientistPosGameClear
	end

Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaHere::
	setobjectxyperm LOCALID_SCIENTIST, 1, 6
	setobjectmovementtype LOCALID_SCIENTIST, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaGone::
	setobjectxyperm LOCALID_SCIENTIST, 4, 6
	setobjectmovementtype LOCALID_SCIENTIST, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_2F_EventScript_SetScientistPosGameClear::
	setobjectxyperm LOCALID_SCIENTIST, 2, 2
	setobjectmovementtype LOCALID_SCIENTIST, MOVEMENT_TYPE_FACE_UP
	return

Route119_WeatherInstitute_2F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_5, Route119_WeatherInstitute_2F_Text_Grunt1Intro, Route119_WeatherInstitute_2F_Text_Grunt1Defeat
	faceplayer
	msgbox Route119_WeatherInstitute_2F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_2, Route119_WeatherInstitute_2F_Text_Grunt2Intro, Route119_WeatherInstitute_2F_Text_Grunt2Defeat
	faceplayer
	msgbox Route119_WeatherInstitute_2F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_Grunt3::
	faceplayer
	msgbox Route119_WeatherInstitute_2F_Text_Grunt3, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_Grunt4::
	msgbox Route119_WeatherInstitute_2F_Text_Grunt4, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_Grunt5::
	faceplayer
	msgbox Route119_WeatherInstitute_2F_Text_Grunt5, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_FightTrigger1::
	goto Route119_WeatherInstitute_2F_EventScript_FightScene
	end

Route119_WeatherInstitute_2F_EventScript_FightTrigger2::
	goto Route119_WeatherInstitute_2F_EventScript_FightScene
	end

Route119_WeatherInstitute_2F_EventScript_FightTrigger3::
	goto Route119_WeatherInstitute_2F_EventScript_FightScene
	end

Route119_WeatherInstitute_2F_EventScript_ReturnToFightTrigger::
	msgbox Route119_WeatherInstitute_2F_ReturnToTheFight, MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_ID_PLAYER, Route119_WeatherInstitute_2F_BackToFight
	end

Route119_WeatherInstitute_2F_BackToFight::
	walk_right
	step_end

Route119_WeatherInstitute_2F_EventScript_FightScene::
	lockall
	setvar VAR_WEATHER_INSTITUTE_TRIGGER_STATE, 1
	playse SE_NOT_EFFECTIVE
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFastestRight
	applymovement LOCALID_GRUNT_5, Route119_WeatherInstitute_2F_Knocked_Back
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_FaceDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route119_WeatherInstitute_2F_MaySeesPlayer
	compare VAR_RESULT, FEMALE
	goto_if_eq Route119_WeatherInstitute_2F_BrendanSeesPlayer
Route119_WeatherInstitute_2F_EventScript_FightScenePart2::
	applymovement LOCALID_SHELLY, Common_Movement_FaceDown
	applymovement LOCALID_ARCHIE, Common_Movement_FaceDown
	waitmovement 0
	msgbox Route119_WeatherInstitute_2F_Text_ArchieSeesPlayer, MSGBOX_DEFAULT
	applymovement LOCALID_RIVAL, Route119_WeatherInstitute_2F_Move_Up_To_Shelly
	applymovement LOCALID_GRUNT_5, Route119_WeatherInstitute_2F_Shove_Grunt_OutOfWay
	waitmovement 0
	applymovement LOCALID_SHELLY, Common_Movement_FaceLeft
	applymovement LOCALID_ARCHIE, Common_Movement_FaceLeft
	waitmovement 0
	compare VAR_RESULT, MALE
	goto_if_eq Route119_WeatherInstitute_2F_MayAsksPlayerToJoinFight
	compare VAR_RESULT, FEMALE
	goto_if_eq Route119_WeatherInstitute_2F_BrendanAsksPlayerToJoinFight
Route119_WeatherInstitute_2F_EventScript_FightScenePart3::
	releaseall
	end

Route119_WeatherInstitute_2F_MaySeesPlayer::
	msgbox Route119_WeatherInstitute_2F_Text_RivalMaySeesPlayer, MSGBOX_DEFAULT
	closemessage
	goto Route119_WeatherInstitute_2F_EventScript_FightScenePart2

Route119_WeatherInstitute_2F_BrendanSeesPlayer::
	msgbox Route119_WeatherInstitute_2F_Text_RivalBrendanSeesPlayer, MSGBOX_DEFAULT
	closemessage
	goto Route119_WeatherInstitute_2F_EventScript_FightScenePart2

Route119_WeatherInstitute_2F_Knocked_Back::
	lock_facing_direction
	walk_fast_right
	unlock_facing_direction
	delay_16
	step_end

Route119_WeatherInstitute_2F_Move_Up_To_Shelly::
	walk_right
	walk_right
	walk_up
	face_down
	step_end

Route119_WeatherInstitute_2F_Shove_Grunt_OutOfWay::
	delay_16
	ride_water_current_up
	ride_water_current_up
	walk_in_place_fastest_down
	step_end

Route119_WeatherInstitute_2F_MayAsksPlayerToJoinFight::
	msgbox Route119_WeatherInstitute_2F_Text_MayAsksPlayerToJoinFight, MSGBOX_DEFAULT
	closemessage
	goto Route119_WeatherInstitute_2F_EventScript_FightScenePart3

Route119_WeatherInstitute_2F_BrendanAsksPlayerToJoinFight::
	msgbox Route119_WeatherInstitute_2F_Text_BrendanAsksPlayerToJoinFight, MSGBOX_DEFAULT
	closemessage
	goto Route119_WeatherInstitute_2F_EventScript_FightScenePart3

Route119_WeatherInstitute_2F_EventScript_Shelly::
	lock
	faceplayer
	msgbox Route119_WeatherInstitute_2F_Text_ShellyWaitingForBattle, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_Archie::
	lock
	faceplayer
	msgbox Route119_WeatherInstitute_2F_Text_ArchieWaitingForBattle, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_RivalReadyForBattlePrompt::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route119_WeatherInstitute_2F_MayAreYouReadyToBattle
	compare VAR_RESULT, FEMALE
	goto_if_eq Route119_WeatherInstitute_2F_BrendanAreYouReadyToBattle
Route119_WeatherInstitute_2F_EventScript_RivalReadyForBattlePromptPart2::
	compare VAR_RESULT, YES
	goto_if_eq Route119_WeatherInstitute_2F_EventScript_ChoosePartyForMultiBattle
	msgbox MossdeepCity_SpaceCenter_2F_Text_RivalHurryGetReadyQuickly, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

Route119_WeatherInstitute_2F_MayAreYouReadyToBattle::
	msgbox Route119_WeatherInstitute_2F_Text_MayAreYouReadyToBattle, MSGBOX_YESNO
	goto Route119_WeatherInstitute_2F_EventScript_RivalReadyForBattlePromptPart2

Route119_WeatherInstitute_2F_BrendanAreYouReadyToBattle::
	msgbox Route119_WeatherInstitute_2F_Text_BrendanAreYouReadyToBattle, MSGBOX_YESNO
	goto Route119_WeatherInstitute_2F_EventScript_RivalReadyForBattlePromptPart2

Route119_WeatherInstitute_2F_EventScript_ChoosePartyForMultiBattle::
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	special SavePlayerParty
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	compare VAR_RESULT, 0
	goto_if_ne Route119_WeatherInstitute_2F_EventScript_DoRivalMultiBattle
	special LoadPlayerParty
	goto Route119_WeatherInstitute_2F_EventScript_RivalReadyForBattlePrompt

Route119_WeatherInstitute_2F_EventScript_DoRivalMultiBattle::
	special ReducePlayerPartyToSelectedMons
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	setvar VAR_0x8004, SPECIAL_BATTLE_RIVAL
	setvar VAR_0x8005, 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_RIVAL, Common_Movement_FaceRight
	waitmovement 0
	special DoSpecialTrainerBattle
	waitstate
	frontier_saveparty
	special LoadPlayerParty
	switch VAR_RESULT
	case 1, Route119_WeatherInstitute_2F_EventScript_DefeatedArchieShelly
	fadescreen FADE_TO_BLACK
	special SetCB2WhiteOut
	waitstate

Route119_WeatherInstitute_2F_EventScript_DefeatedArchieShelly::
	lockall
	applymovement LOCALID_ARCHIE, Common_Movement_FaceLeft
	msgbox Route119_WeatherInstitute_2F_Text_ArchieLost, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_1, Route119_WeatherInstitute_2F_Grunt_Reporting
	applymovement LOCALID_GRUNT_4, Route119_WeatherInstitute_2F_Grunt_MoveAwayForReporter
	waitmovement 0
	msgbox Route119_WeatherInstitute_2F_Text_TeamMagmaJustPassedBy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ARCHIE, Common_Movement_FaceRight
	msgbox Route119_WeatherInstitute_2F_Text_WeHaveToHurryToMtPyre, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ARCHIE, Common_Movement_FaceLeft
	msgbox Route119_WeatherInstitute_2F_Text_ArchieLetsMeetAgain, MSGBOX_DEFAULT
	closemessage
	setvar VAR_WEATHER_INSTITUTE_STATE, 1
	clearflag FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_ROUTE_119_TEAM_AQUA
	setflag FLAG_HIDE_WEATHER_INSTITUTE_2F_AQUA_GRUNT_M
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_GRUNT_3
	removeobject LOCALID_GRUNT_4
	removeobject LOCALID_GRUNT_5
	removeobject LOCALID_SHELLY
	removeobject LOCALID_ARCHIE
	setobjectxy OBJ_EVENT_ID_PLAYER, 7, 6
	setobjectxy LOCALID_RIVAL, 8, 6
	applymovement LOCALID_RIVAL, Common_Movement_FaceRight
	fadescreen FADE_FROM_BLACK
	applymovement LOCALID_RIVAL, Common_Movement_FaceLeft
	waitmovement 0
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route119_WeatherInstitute_2F_MayThanksForTheHelp
	compare VAR_RESULT, FEMALE
	goto_if_eq Route119_WeatherInstitute_2F_BrendanThanksForTheHelp
Route119_WeatherInstitute_2F_EventScript_DefeatedArchieShellyPart2::
	applymovement LOCALID_RIVAL, Route119_WeatherInstitute_2F_Movement_RivalLeaves
	waitmovement 0
	applymovement LOCALID_SCIENTIST, Route119_WeatherInstitute_2F_Movement_ScientistApproachPlayer
	waitmovement 0
	removeobject LOCALID_RIVAL
	copyobjectxytoperm LOCALID_SCIENTIST
	goto Route119_WeatherInstitute_2F_EventScript_ReceiveCastform
	releaseall
	end

Route119_WeatherInstitute_2F_MayThanksForTheHelp::
	msgbox Route119_WeatherInstitute_2F_Text_MayThanksForTheHelp, MSGBOX_DEFAULT
	closemessage
	goto Route119_WeatherInstitute_2F_EventScript_DefeatedArchieShellyPart2

Route119_WeatherInstitute_2F_BrendanThanksForTheHelp::
	msgbox Route119_WeatherInstitute_2F_Text_BrendanThanksForTheHelp, MSGBOX_DEFAULT
	closemessage
	goto Route119_WeatherInstitute_2F_EventScript_DefeatedArchieShellyPart2

Route119_WeatherInstitute_2F_EventScript_ArchieTrainer::
	trainerbattle TRAINER_BATTLE_SET_TRAINER_A, TRAINER_ARCHIE_WEATHER_INSTITUTE, 0, Route119_WeatherInstitute_2F_Text_ArchieDefeat, Route119_WeatherInstitute_2F_Text_ArchieDefeat
	end

Route119_WeatherInstitute_2F_EventScript_ShellyTrainer::
	trainerbattle TRAINER_BATTLE_SET_TRAINER_B, TRAINER_SHELLY_WEATHER_INSTITUTE, 0, Route119_WeatherInstitute_2F_Text_ShellyDefeat, Route119_WeatherInstitute_2F_Text_ShellyDefeat
	end

Route119_WeatherInstitute_2F_Grunt_Reporting::
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route119_WeatherInstitute_2F_Grunt_MoveAwayForReporter::
	delay_16
	delay_16
	delay_16
	delay_16
	ride_water_current_down
	walk_in_place_fastest_down
	face_up
	step_end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastform::
	msgbox Route119_WeatherInstitute_2F_Text_ThanksPleaseTakePokemon, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, SPECIES_CASTFORM
	givemon SPECIES_CASTFORM, 25, ITEM_MYSTIC_WATER
	compare VAR_RESULT, 0
	goto_if_eq Route119_WeatherInstitute_2F_EventScript_ReceiveCastformParty
	compare VAR_RESULT, 1
	goto_if_eq Route119_WeatherInstitute_2F_EventScript_ReceiveCastformPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastformParty::
	call Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastformPC::
	call Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Route119_WeatherInstitute_2F_EventScript_SendCastformToPC
	call Common_EventScript_NameReceivedBoxMon
	goto Route119_WeatherInstitute_2F_EventScript_SendCastformToPC
	end

Route119_WeatherInstitute_2F_EventScript_SendCastformToPC::
	call Common_EventScript_TransferredToPC
	goto Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	end

Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare::
	playfanfare MUS_OBTAIN_ITEM
	message Route119_WeatherInstitute_2F_Text_PlayerReceivedCastform
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_CASTFORM
	return

Route119_WeatherInstitute_2F_EventScript_ExplainCastform::
	msgbox Route119_WeatherInstitute_2F_Text_PokemonChangesWithWeather, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_CASTFORM
	release
	end

Route119_WeatherInstitute_2F_EventScript_ScientistMentionWeather::
	goto_if_set FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_2F_EventScript_TryStartAbnormalWeather
	msgbox Route119_WeatherInstitute_2F_Text_ChangingWeatherRidiculous, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_TryStartAbnormalWeather::
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated
	compare VAR_0x8004, 2  @ Both defeated
	goto_if_eq Route119_WeatherInstitute_2F_EventScript_NoAbnormalWeather
	call_if_unset FLAG_TEMP_2, Route119_WeatherInstitute_2F_EventScript_CreateAbnormalWeather
	specialvar VAR_RESULT, GetAbnormalWeatherMapNameAndType
	compare VAR_RESULT, 1
	goto_if_eq Route119_WeatherInstitute_2F_EventScript_KyogreWeather
	msgbox Route119_WeatherInstitute_2F_Text_GroudonWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_KyogreWeather::
	msgbox Route119_WeatherInstitute_2F_Text_KyogreWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_CreateAbnormalWeather::
	special CreateAbnormalWeatherEvent
	setflag FLAG_TEMP_2
	return

Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated::
	addvar VAR_0x8004, 1
	return

Route119_WeatherInstitute_2F_EventScript_NoAbnormalWeather::
	msgbox Route119_WeatherInstitute_2F_Text_NoAbnormalWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_Movement_RivalLeaves:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route119_WeatherInstitute_2F_Movement_ScientistApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route119_WeatherInstitute_2F_EventScript_WeatherScientist::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CASTFORM, Route119_WeatherInstitute_2F_EventScript_ScientistMentionWeather
	goto Route119_WeatherInstitute_2F_EventScript_ReceiveCastform
	end

Route119_WeatherInstitute_2F_ReturnToTheFight:
	.string "Return to the fight!$"

Route119_WeatherInstitute_2F_Text_Grunt2Intro:
	.string "Don't tell me you're looking for that\n"
	.string "weather Pokémon, too?\p"
	.string "That's a no-no!\n"
	.string "We were here to get it first!$"

Route119_WeatherInstitute_2F_Text_Grunt1Defeat:
	.string "Oh, will you look at my Pokémon?$"

Route119_WeatherInstitute_2F_Text_Grunt2PostBattle:
	.string "Humph, so what?\n"
	.string "What we want…\p"
	.string "What we really want isn't here…\n"
	.string "Ihihihihi…$"

Route119_WeatherInstitute_2F_Text_Grunt1Intro:
	.string "The Institute created a type of\n"
	.string "Pokémon that has something to do with\l"
	.string "the weather. We're here to take them!$"

Route119_WeatherInstitute_2F_Text_Grunt2Defeat:
	.string "Our plan's being spoiled by kids?$"

Route119_WeatherInstitute_2F_Text_Grunt1PostBattle:
	.string "I don't get why the boss needs the\n"
	.string "weather Pokémon but he always knows\l"
	.string "what's best.$"

Route119_WeatherInstitute_2F_Text_Grunt3:
	.string "Don't mind me. I'm just\n"
	.string "watching the show.$"

Route119_WeatherInstitute_2F_Text_Grunt4:
	.string "Oof! When did kids get so tough?$"

Route119_WeatherInstitute_2F_Text_Grunt5:
	.string "Oh great, another kid.\n"
	.string "I'm already down!$"

Route119_WeatherInstitute_2F_Text_RivalMaySeesPlayer:
	.string "May: {PLAYER}! Good timing,\n"
	.string "I need your help!\p"
	.string "Team Aqua is trying to steal the\n"
	.string "Pokémon here!$"

Route119_WeatherInstitute_2F_Text_RivalBrendanSeesPlayer:
	.string "Brendan: {PLAYER}! Glad you're here.\n"
	.string "Team Aqua is trying to steal the\n"
	.string "Weather Institute's Pokémon!$"

Route119_WeatherInstitute_2F_Text_ArchieSeesPlayer:
	.string "Archie: Oh, it's you again.\n"
	.string "Bwahahahahah! It's very bold of you\l"
	.string "to continue to meddle in our affairs!\p"
	.string "But you're going down along with the\n"
	.string "other fry!$"

Route119_WeatherInstitute_2F_Text_MayAsksPlayerToJoinFight:
	.string "Let's go beat these goons, {PLAYER}!$"

Route119_WeatherInstitute_2F_Text_BrendanAsksPlayerToJoinFight:
	.string "Let's take down their leader, {PLAYER}\n"
	.string "are you with me?$"

MossdeepCity_SpaceCenter_2F_Text_RivalHurryGetReadyQuickly:
	.string "Then, hurry!\n"
	.string "Get ready quickly!$"

Route119_WeatherInstitute_2F_Text_ShellyWaitingForBattle:
	.string "Shelly: Ahahahaha!\p"
	.string "You're going to meddle in Team Aqua's\n"
	.string "affairs?\p"
	.string "You're either absolutely fearless,\n"
	.string "simply ignorant, or both!$"

Route119_WeatherInstitute_2F_Text_ShellyDefeat:
	.string "Ahahahaha!\n"
	.string "You're disgustingly strong!$"

Route119_WeatherInstitute_2F_Text_ArchieWaitingForBattle:
	.string "Archie: Ha! Come at me, scamp!$"

Route119_WeatherInstitute_2F_Text_ArchieDefeat:
	.string "Oh! You went and did it, didn't you?$"

Route119_WeatherInstitute_2F_Text_MayAreYouReadyToBattle:
	.string "May: {PLAYER}!\n"
	.string "Let's go into battle together!\n"
	.string "Are you ready?$"

Route119_WeatherInstitute_2F_Text_BrendanAreYouReadyToBattle:
	.string "Brendan: {PLAYER}!\n"
	.string "Let's fight them together!\n"
	.string "Are you ready?$"

Route119_WeatherInstitute_2F_Text_ArchieLost:
	.string "Archie: Heheheh. Ya little scamp!\n"
	.string "I knew you were the real deal!\p"
	.string "Though I'm afraid it doesn't matter\n"
	.string "how often you beat us, we'll always\l"
	.string "be back for more as long as our goal\l"
	.string "remains incomplete.$"

Route119_WeatherInstitute_2F_Text_TeamMagmaJustPassedBy:
	.string "Boss, we have a situation here!\p"
	.string "We've spotted a Team Magma mob\n"
	.string "heading east towards Mt. Pyre.$"

Route119_WeatherInstitute_2F_Text_WeHaveToHurryToMtPyre:
	.string "What?!\p"
	.string "What are they up to?\n"
	.string "We have to follow them!\p"
	.string "Ahahahaha!\n"
	.string "Team, it's time to pull out!$"

Route119_WeatherInstitute_2F_Text_ArchieLetsMeetAgain:
	.string "I'd love to stick around and\n"
	.string "fight some more, scamp.\l"
	.string "But when you're a grown-up,\l"
	.string "y'see, sometimes things crop up.\p"
	.string "Let's meet again somewhere.\n"
	.string "I'll be sure to remember that face.$"

Route119_WeatherInstitute_2F_Text_MayThanksForTheHelp:
	.string "May: Thanks for the help {PLAYER},\n"
	.string "I don't think I could have won\l"
	.string "against them all by myself.\p"
	.string "My dad asked me to come here to\n"
	.string "pick up research data on the\l"
	.string "Pokémon they created.\p"
	.string "I wasn't expecting to have to\n"
	.string "fight Team Aqua!\p"
	.string "Whew! I'm beat! I'm going to go\n"
	.string "outside and take a breather!$"

Route119_WeatherInstitute_2F_Text_BrendanThanksForTheHelp:
	.string "Brendan: That got a bit hairy.\n"
	.string "They were wearing me down,\l"
	.string "so thanks for backing me up.\p"
	.string "I only came here to pick up copies\n"
	.string "of the research notes on the Pokémon\l"
	.string "they created.\p"
	.string "Team Aqua made that trip a bit\n"
	.string "more lively!\p"
	.string "I'm going to go rest outside.$"

Route119_WeatherInstitute_2F_Text_ThanksPleaseTakePokemon:
	.string "Thanks!\n"
	.string "Thanks to you, we're safe!\p"
	.string "It might be an odd way of thanking you,\n"
	.string "but take this Pokémon.$"

@ Unused
Route119_WeatherInstitute_2F_Text_NoRoomForPokemon:
	.string "Hm? You don't seem to have any room\n"
	.string "for this Pokémon.$"

Route119_WeatherInstitute_2F_Text_PlayerReceivedCastform:
	.string "{PLAYER} received Castform!$"

Route119_WeatherInstitute_2F_Text_PokemonChangesWithWeather:
	.string "There're plenty of them in the\n"
	.string "Institute--go ahead and take it.\p"
	.string "That Pokémon changes shape according\n"
	.string "to the weather conditions. It's very\l"
	.string "sensitive to atmospheric changes,\l"
	.string "hence why we use it for data at the\l"
	.string "Institute.\p"
	.string "I don't know why Team Aqua wanted\n"
	.string "them, but I'm happy they're all safe.$"

Route119_WeatherInstitute_2F_Text_ChangingWeatherRidiculous:
	.string "I've been researching rain for many\n"
	.string "years, but it's ridiculous to think that\l"
	.string "humans can freely change the weather.$"

Route119_WeatherInstitute_2F_Text_GroudonWeather:
	.string "I track weather patterns over\n"
	.string "the Hoenn region.\p"
	.string "Presently, a drought has been recorded\n"
	.string "in {STR_VAR_1}.\p"
	.string "Could that mean, somewhere near\n"
	.string "{STR_VAR_1}…$"

Route119_WeatherInstitute_2F_Text_KyogreWeather:
	.string "I track weather patterns over\n"
	.string "the Hoenn region.\p"
	.string "Presently, heavy rainfall has been\n"
	.string "recorded over {STR_VAR_1}.\p"
	.string "Could that mean, somewhere near\n"
	.string "{STR_VAR_1}…$"

Route119_WeatherInstitute_2F_Text_NoAbnormalWeather:
	.string "Abnormal weather conditions are\n"
	.string "no longer being reported.\p"
	.string "The occasional rainfall is a blessing,\n"
	.string "really.$"

