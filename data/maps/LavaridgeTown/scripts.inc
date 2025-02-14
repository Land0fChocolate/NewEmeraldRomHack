.set LOCALID_RIVAL_ON_BIKE, 7
.set LOCALID_RIVAL, 8

LavaridgeTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavaridgeTown_OnFrame
	.byte 0

LavaridgeTown_OnTransition:
	setflag FLAG_VISITED_LAVARIDGE_TOWN
	call_if_set FLAG_WHITEOUT_TO_LAVARIDGE, LavaridgeTown_EventScript_ClearLavaridgeWhiteOut
	call_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, LavaridgeTown_EventScript_ShowMtChimneyTrainers
	call Common_EventScript_SetupRivalGfxId
	call Common_EventScript_SetupRivalOnBikeGfxId
	compare VAR_LAVARIDGE_TOWN_STATE, 1
	call_if_eq LavaridgeTown_EventScript_CheckSetRivalPos
	compare VAR_LAVARIDGE_TOWN_STATE, 1
	call_if_eq LavaridgeTown_EventScript_HideMapNamePopup
	call LavaridgeTown_Eventscript_SetUpFlannery
	end

LavaridgeTown_Eventscript_SetUpFlannery::
	goto_if_unset FLAG_SYS_GAME_CLEAR, LavaridgeTown_Eventscript_FlanneryRematch
	setorcopyvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_FLANNERY_1
    specialvar VAR_RESULT, IsTrainerReadyForRematch
    compare VAR_RESULT, TRUE
    goto_if_eq LavaridgeTown_Eventscript_FlanneryRematch
    compare VAR_RESULT, FALSE
    goto_if_eq LavaridgeTown_Eventscript_FlanneryHotSprings
    return

LavaridgeTown_Eventscript_FlanneryRematch::
	setflag FLAG_HIDE_FLANNERY_HOT_SPRINGS
	clearflag FLAG_HIDE_FLANNERY_GYM
	return

LavaridgeTown_Eventscript_FlanneryHotSprings::
	goto_if_unset FLAG_BADGE05_GET, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_FLANNERY_HOT_SPRINGS
	setflag FLAG_HIDE_FLANNERY_GYM
	return

LavaridgeTown_EventScript_ClearLavaridgeWhiteOut::
	clearflag FLAG_WHITEOUT_TO_LAVARIDGE
	return

LavaridgeTown_EventScript_CheckSetRivalPos::
	getplayerxy VAR_0x8004, VAR_0x8005
	compare VAR_0x8004, 9
	goto_if_eq LavaridgeTown_EventScript_SetRivalPos
	return

LavaridgeTown_EventScript_SetRivalPos::
	setobjectxyperm LOCALID_RIVAL, 11, 9
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 9, 8
	setobjectmovementtype LOCALID_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_UP
	clearflag FLAG_HIDE_LAVARIDGE_TOWN_RIVAL
	return

LavaridgeTown_EventScript_ShowMtChimneyTrainers::
	clearflag FLAG_HIDE_MT_CHIMNEY_TRAINERS
	return

LavaridgeTown_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

LavaridgeTown_OnFrame:
	map_script_2 VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_RivalGiveGoGoggles
	.2byte 0

LavaridgeTown_EventScript_RivalGiveGoGoggles::
	lockall
	getplayerxy VAR_0x8008, VAR_0x8009
	compare VAR_0x8008, 9
	call_if_eq LavaridgeTown_EventScript_RivalNoticePlayer
	compare VAR_0x8008, 9
	call_if_ne LavaridgeTown_EventScript_RivalExitHerbShop
	delay 20
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LavaridgeTown_EventScript_PlayMayMusic
	compare VAR_RESULT, FEMALE
	call_if_eq LavaridgeTown_EventScript_PlayBrendanMusic
	compare VAR_0x8008, 9
	call_if_eq LavaridgeTown_EventScript_RivalApproachPlayer1
	compare VAR_0x8008, 9
	call_if_ne LavaridgeTown_EventScript_RivalApproachPlayer2
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq LavaridgeTown_EventScript_MayGiveGoGoggles
	compare VAR_RESULT, FEMALE
	goto_if_eq LavaridgeTown_EventScript_BrendanGiveGoGoggles
	end

LavaridgeTown_EventScript_MayGiveGoGoggles::
	msgbox LavaridgeTown_Text_MayNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_MayExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_BrendanGiveGoGoggles::
	msgbox LavaridgeTown_Text_BrendanNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_RivalExit::
	closemessage
	removeobject LOCALID_RIVAL
	addobject LOCALID_RIVAL_ON_BIKE
	delay 30
	compare VAR_0x8008, 9
	call_if_eq LavaridgeTown_EventScript_RivalExit1
	compare VAR_0x8008, 9
	call_if_ne LavaridgeTown_EventScript_RivalExit2
	removeobject LOCALID_RIVAL_ON_BIKE
	setvar VAR_LAVARIDGE_TOWN_STATE, 2
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LavaridgeTown_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

LavaridgeTown_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

LavaridgeTown_EventScript_RivalNoticePlayer::
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExitHerbShop::
	opendoor 12, 15
	waitdooranim
	addobject LOCALID_RIVAL
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalExitHerbShop
	waitmovement 0
	closedoor 12, 15
	waitdooranim
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalApproachPlayer1::
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalApproachPlayer2::
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer2
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit1::
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeTown_Movement_PlayerWatchRivalExit
	applymovement LOCALID_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit2::
	applymovement LOCALID_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit2
	waitmovement 0
	return

LavaridgeTown_Movement_RivalExit2:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

LavaridgeTown_Movement_PlayerWatchRivalExit:
	delay_16
	delay_8
	walk_in_place_fastest_right
	step_end

LavaridgeTown_Movement_RivalExit1:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

LavaridgeTown_Movement_RivalApproachPlayer2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LavaridgeTown_Movement_RivalApproachPlayer1:
	walk_left
	walk_left
	walk_up
	step_end

LavaridgeTown_Movement_RivalExitHerbShop:
	walk_down
	step_end

LavaridgeTown_EventScript_HotSpringsTrigger::
	specialvar VAR_RESULT, GetPlayerFacingDirection
	compare VAR_RESULT, DIR_SOUTH
	goto_if_eq LavaridgeTown_EventScript_EnteredHotSprings
	end

LavaridgeTown_EventScript_EnteredHotSprings::
	incrementgamestat GAME_STAT_ENTERED_HOT_SPRINGS
	end

LavaridgeTown_EventScript_ExpertM::
	msgbox LavaridgeTown_Text_HotSpringsNeverRunDry, MSGBOX_NPC
	end

LavaridgeTown_EventScript_OldMan::
	msgbox LavaridgeTown_Text_PokemonNippedBackside, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_Twin::
	msgbox LavaridgeTown_Text_BatheInHotSpringsEveryDay, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman1::
	msgbox LavaridgeTown_Text_IfPokemonInHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman2::
	msgbox LavaridgeTown_Text_HotSpringsClaims, MSGBOX_NPC
	end

LavaridgeTown_EventScript_ExpertF::
	msgbox LavaridgeTown_Text_OhYouLikeHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_EggWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_LAVARIDGE_EGG, LavaridgeTown_EventScript_ReceivedEgg
	msgbox LavaridgeTown_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LavaridgeTown_EventScript_DeclineEgg
	getpartysize
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq LavaridgeTown_EventScript_NoRoomForEgg
	msgbox LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_LAVARIDGE_EGG
	playfanfare MUS_OBTAIN_ITEM
	message LavaridgeTown_Text_ReceivedTheEgg
	waitfanfare
	giveegg SPECIES_VULPIX_ALOLAN
	release
	end

LavaridgeTown_EventScript_ReceivedEgg::
	msgbox LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_NoRoomForEgg::
	msgbox LavaridgeTown_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_DeclineEgg::
	msgbox LavaridgeTown_Text_AsYouWishThen, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_Flannery::
	faceplayer
	goto_if_unset FLAG_MET_FLANNERY_HOT_SPRINGS, LavaridgeTown_EventScript_FlanneryHotSpringsFirstMeet
	goto_if_set FLAG_FLANNERY_DAILY_LIMIT_LIFTED, LavaridgeTown_EventScript_FlanneryPart3
	goto_if_set FLAG_POST_GAME_COMPLETE, LavaridgeTown_EventScript_FlanneryNoLimits
LavaridgeTown_EventScript_FlanneryPart2::
	dotimebasedevents
	goto_if_set FLAG_DAILY_FLANNERY_TRAINING, LavaridgeTown_EventScript_ComeBackTomorrow
LavaridgeTown_EventScript_FlanneryPart3::
	msgbox LavaridgeTown_Text_WouldYouLikeTraining, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LavaridgeTown_EventScript_FlanneryDeclined
	msgbox LavaridgeTown_Text_FlanneryChoosePokemon, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq LavaridgeTown_EventScript_FlanneryDeclined
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq LavaridgeTown_EventScript_CantTrainEgg
	special CheckForMaxedEVTotal
	compare VAR_0x8007, 1
	goto_if_eq LavaridgeTown_Eventscript_EVsAreMaxedOut
LavaridgeTown_EventScript_FlanneryPart4::
	multichoice 0, 0, MULTI_STAT_EV_TRAIN, FALSE
	switch VAR_RESULT
	case 0, LavaridgeTown_Eventscript_EVTrainHP
	case 1, LavaridgeTown_Eventscript_EVTrainAttack
	case 2, LavaridgeTown_Eventscript_EVTrainDefense
	case 3, LavaridgeTown_Eventscript_EVTrainSpecialAttack
	case 4, LavaridgeTown_Eventscript_EVTrainSpecialDefense
	case 5, LavaridgeTown_Eventscript_EVTrainSpeed
	case 6, LavaridgeTown_EventScript_FlanneryDeclined
	goto LavaridgeTown_EventScript_FlanneryDeclined
LavaridgeTown_Eventscript_FlanneryPart5::
	msgbox LavaridgeTown_Text_TrainingTime, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_LEVEL_UP
	waitfanfare
	special EVTrainPokemon
	fadescreen FADE_FROM_BLACK
	special BufferMonNickname
	msgbox LavaridgeTown_Text_DoneTraining, MSGBOX_DEFAULT
	setflag FLAG_DAILY_FLANNERY_TRAINING
	release
	end

LavaridgeTown_Eventscript_EVsAreMaxedOut::
	msgbox LavaridgeTown_Text_EVsAreMaxedOut, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Eventscript_EVTrainHP::
	setvar VAR_0x8009, STAT_HP
	goto LavaridgeTown_Eventscript_CheckStat

LavaridgeTown_Eventscript_EVTrainAttack::
	setvar VAR_0x8009, STAT_ATK
	goto LavaridgeTown_Eventscript_CheckStat

LavaridgeTown_Eventscript_EVTrainDefense::
	setvar VAR_0x8009, STAT_DEF
	goto LavaridgeTown_Eventscript_CheckStat

LavaridgeTown_Eventscript_EVTrainSpeed::
	setvar VAR_0x8009, STAT_SPEED
	goto LavaridgeTown_Eventscript_CheckStat

LavaridgeTown_Eventscript_EVTrainSpecialAttack::
	setvar VAR_0x8009, STAT_SPATK
	goto LavaridgeTown_Eventscript_CheckStat

LavaridgeTown_Eventscript_EVTrainSpecialDefense::
	setvar VAR_0x8009, STAT_SPDEF
	goto LavaridgeTown_Eventscript_CheckStat

LavaridgeTown_Eventscript_CheckStat::
	special CheckForMaxedEVStat
	compare VAR_0x8007, 1
	goto_if_eq LavaridgeTown_Eventscript_FlanneryStatIsAtMax
	goto LavaridgeTown_Eventscript_FlanneryPart5

LavaridgeTown_Eventscript_FlanneryStatIsAtMax::
	msgbox LavaridgeTown_Text_StatIsAtMax, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_FlanneryPart4

LavaridgeTown_EventScript_FlanneryHotSpringsFirstMeet::
	msgbox LavaridgeTown_Text_FlanneryCanTrainYourPokemon, MSGBOX_DEFAULT
	setflag FLAG_MET_FLANNERY_HOT_SPRINGS
	goto LavaridgeTown_EventScript_FlanneryPart2
	end

LavaridgeTown_EventScript_FlanneryNoLimits::
	msgbox LavaridgeTown_Text_FlanneryNoLimits, MSGBOX_DEFAULT
	setflag FLAG_FLANNERY_DAILY_LIMIT_LIFTED
	goto LavaridgeTown_EventScript_FlanneryPart3

LavaridgeTown_EventScript_ComeBackTomorrow::
	msgbox LavaridgeTown_Text_ComeBackTomorrow, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_FlanneryDeclined::
	msgbox LavaridgeTown_Text_FlanneryDeclined, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_CantTrainEgg::
	msgbox LavaridgeTown_Text_CantTrainEgg, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_TownSign::
	msgbox LavaridgeTown_Text_TownSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_GymSign::
	msgbox LavaridgeTown_Text_GymSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_HerbShopSign::
	msgbox LavaridgeTown_Text_HerbShopSign, MSGBOX_SIGN
	end

LavaridgeTown_Text_FlanneryCanTrainYourPokemon:
	.string "Flannery: Hey, {PLAYER}.\p"
	.string "I didn't know you liked the hot springs\n"
	.string "too, or did you come over to see me?\p"
	.string "Bathing here isn't just for relaxation,\n"
	.string "it's a key part of my training.\p"
	.string "Your Pokemon can join in too, I have\n"
	.string "some free space.$"

LavaridgeTown_Text_FlanneryNoLimits:
	.string "Flannery: I've perfected my training\n"
	.string "regimen to the point where I don't even\l"
	.string "need to rest!\p"
	.string "I can even train your Pokémon anytime,\n"
	.string "{PLAYER}! No more daily limits!$"

LavaridgeTown_Text_WouldYouLikeTraining:
	.string "Flannery: So… how about it,\n"
	.string "would you like me to max out one of\l"
	.string "your Pokémon's effort values?$"

LavaridgeTown_Text_FlanneryChoosePokemon:
	.string "All right!\n"
	.string "Which Pokémon needs training?$"

LavaridgeTown_Text_TrainingTime:
	.string "Yes! Let's get fired up!$"

LavaridgeTown_Text_ComeBackTomorrow:
	.string "I like meeting the kind of Pokémon\n"
	.string "you raise, {PLAYER}.\p"
	.string "I'm open for training tomorrow as well,\n"
	.string "if you'd care to join me.$"

LavaridgeTown_Text_FlanneryDeclined:
	.string "Oh… okay, we can do it some\n"
	.string "other time.$"

LavaridgeTown_Text_CantTrainEgg:
	.string "Umm… this is an egg.\n"
	.string "I can't do anything with it.$"

LavaridgeTown_Text_EVsAreMaxedOut:
	.string "This Pokémon is maxed out in EVs\n"
	.string "I can't train it further.$"

LavaridgeTown_Text_StatIsAtMax:
	.string "I can't make that stat any better.\n"
	.string "It's as good as it can be.$"

LavaridgeTown_Text_DoneTraining:
	.string "All right, that was cool,\n"
	.string "oh I mean- hot!\p"
	.string "Your Pokémon did great, and is looking\n"
	.string "stronger.$"

LavaridgeTown_Text_MayNiceBadgesTakeThis:
	.string "May: {PLAYER}{KUN}! Long time no see!\p"
	.string "Oh? While I visited the hot springs,\n"
	.string "you got the Lavaridge Gym Badge.\p"
	.string "You must have collected\n"
	.string "good Pokémon…\l"
	.string "No, I believe you raised some.\p"
	.string "I guess it would be okay for you to\n"
	.string "have this.$"

LavaridgeTown_Text_MayExplainGoGogglesChallengeDad:
	.string "May: With those Go-Goggles, you'll\n"
	.string "have no trouble getting through the\l"
	.string "desert near Route 111.\p"
	.string "But, wow, {PLAYER}{KUN}…\n"
	.string "Challenging Gyms…\p"
	.string "You're trying hard because you don't\n"
	.string "want to lose to me, I bet!\p"
	.string "{PLAYER}{KUN}, I think I should challenge\n"
	.string "your dad in Petalburg Gym.\p"
	.string "See you again!$"

LavaridgeTown_Text_BrendanNiceBadgesTakeThis:
	.string "Brendan: {PLAYER}, hey, it's been a while.\n"
	.string "How's it going?\p"
	.string "Hmm…\n"
	.string "That's a decent collection of Badges.\p"
	.string "All right, then.\n"
	.string "You may as well have this.$"

LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad:
	.string "Brendan: Keep those with you if you're\n"
	.string "planning on going into that desert near\l"
	.string "Route 111.\p"
	.string "There should be some Pokémon that\n"
	.string "are exclusively desert-dwellers.\l"
	.string "You might look around for those.\p"
	.string "As for me…\n"
	.string "I'm considering challenging Norman,\l"
	.string "the Gym Leader of Petalburg.\p"
	.string "Unlike you, {PLAYER}, your dad looks like\n"
	.string "he really is tough.\p"
	.string "See you around!$"

LavaridgeTown_Text_HaveEggWillYouTakeIt:
	.string "Some tourists have left this egg\n"
	.string "behind.\p"
	.string "I'd hoped to hatch it by covering it in\n"
	.string "hot sand by the hot springs.\l"
	.string "But that doesn't seem to be enough…\p"
	.string "I've heard it would be best if it were\n"
	.string "kept together with Pokémon and\l"
	.string "carried about.\p"
	.string "You are a Trainer, yes?\n"
	.string "And your Pokémon radiate vitality.\p"
	.string "So, what say you?\n"
	.string "Will you take this egg to hatch?$"

LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg:
	.string "Good! I hope you'll walk plenty with\n"
	.string "this here egg!$"

LavaridgeTown_Text_ReceivedTheEgg:
	.string "{PLAYER} received the egg.$"

LavaridgeTown_Text_NoRoomForThisEgg:
	.string "Oh? You've too many Pokémon.\n"
	.string "There's no room for this egg…$"

LavaridgeTown_Text_AsYouWishThen:
	.string "As you wish, then…\p"
	.string "If you have a change of heart about\n"
	.string "hatching this egg, I will be here.$"

LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare:
	.string "Every so often, an egg will be found at\n"
	.string "the Pokémon Day Care.\p"
	.string "Or at least that's how the rumor goes.$"

LavaridgeTown_Text_HotSpringsNeverRunDry:
	.string "We draw as much hot water as we need,\n"
	.string "and yet the hot springs never run dry.\p"
	.string "Isn't it magical?\p"
	.string "These hot springs appear near active\n"
	.string "volcanoes. Veins of water under the\l"
	.string "ground are heated by magma to well up\l"
	.string "as hot springs.$"

LavaridgeTown_Text_PokemonNippedBackside:
	.string "Being buried in this hot sand is…\n"
	.string "Sigh…\p"
	.string "So warm and heavenly…\p"
	.string "Eh? Gyaah! Ouch!\p"
	.string "A Pokémon nipped my backside!$"

LavaridgeTown_Text_OhYouLikeHotSprings:
	.string "I like to go fight with other Trainers\n"
	.string "on Mt. Chimney, but those Team Magma\l"
	.string "bullies pushed us out.\p"
	.string "If Team Magma are gone now, then the\n"
	.string "Trainers should be coming back.$"

LavaridgeTown_Text_BatheInHotSpringsEveryDay:
	.string "I bathe in the hot springs every day.\p"
	.string "I want to become a beautiful and strong\n"
	.string "Gym Leader like Flannery.$"

LavaridgeTown_Text_IfPokemonInHotSprings:
	.string "If people put Pokémon in hot springs,\n"
	.string "it might be seriously strange.\p"
	.string "Why, it might be an electric bath, or\n"
	.string "a bubble bath, or even a lava bath…$"

LavaridgeTown_Text_HotSpringsClaims:
	.string "They're claiming that these hot springs\n"
	.string "are good for calming nervous tension,\l"
	.string "relieving aching muscles, solving\l"
	.string "romantic problems, and attracting\l"
	.string "money…$"

LavaridgeTown_Text_TownSign:
	.string "LAVARIDGE TOWN\p"
	.string "“POKéMON CENTER HOT SPRINGS\n"
	.string "An excellent place for relaxing!”$"

LavaridgeTown_Text_GymSign:
	.string "LAVARIDGE TOWN POKéMON GYM\n"
	.string "LEADER: FLANNERY\l"
	.string "“One with a fiery passion that burns!”$"

LavaridgeTown_Text_HerbShopSign:
	.string "POKéMON HERB SHOP\n"
	.string "“Bitter taste--better cure!”$"

