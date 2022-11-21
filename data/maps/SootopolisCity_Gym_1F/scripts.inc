SootopolisCity_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_Gym_1F_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_Gym_1F_OnResume
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_Gym_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_Gym_1F_OnTransition
	.byte 0

SootopolisCity_Gym_1F_OnTransition:
	setvar VAR_ICE_STEP_COUNT, 1
	call SootopolisCity_Gym_1F_SetUpWallace
	end

SootopolisCity_Gym_1F_SetUpWallace::
	goto_if_unset FLAG_BADGE08_GET, SootopolisCity_Gym_1F_Eventscript_WallaceRematch
	setorcopyvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_WALLACE_1
    specialvar VAR_RESULT, IsTrainerReadyForRematch
    compare VAR_RESULT, TRUE
    goto_if_eq SootopolisCity_Gym_1F_Eventscript_WallaceRematch
    compare VAR_RESULT, FALSE
    goto_if_eq SootopolisCity_Gym_1F_Eventscript_WallaceAtContestHall
    return

SootopolisCity_Gym_1F_Eventscript_WallaceRematch::
	setflag FLAG_HIDE_CONTEST_HALL_WALLACE
	clearflag FLAG_HIDE_SOOTOPOLIS_GYM_WALLACE
	return

SootopolisCity_Gym_1F_Eventscript_WallaceAtContestHall::
	goto_if_unset FLAG_SYS_GAME_CLEAR, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_CONTEST_HALL_WALLACE
	setflag FLAG_HIDE_SOOTOPOLIS_GYM_WALLACE
	return

SootopolisCity_Gym_1F_OnResume:
	setstepcallback STEP_CB_SOOTOPOLIS_ICE
	end

SootopolisCity_Gym_1F_OnLoad:
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special SetSootopolisGymCrackedIceMetatiles
	end

SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles::
	compare VAR_ICE_STEP_COUNT, 8
	goto_if_lt SootopolisCity_Gym_1F_EventScript_StopCheckingStairs  @ All stairs ice
	compare VAR_ICE_STEP_COUNT, 28
	goto_if_lt SootopolisCity_Gym_1F_EventScript_OpenFirstStairs
	compare VAR_ICE_STEP_COUNT, 67
	goto_if_lt SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs
	setmetatile 8, 4, METATILE_SootopolisGym_Stairs, 0
	setmetatile 8, 5, METATILE_SootopolisGym_Stairs, 0
SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs::
	setmetatile 8, 10, METATILE_SootopolisGym_Stairs, 0
	setmetatile 8, 11, METATILE_SootopolisGym_Stairs, 0
SootopolisCity_Gym_1F_EventScript_OpenFirstStairs::
	setmetatile 8, 15, METATILE_SootopolisGym_Stairs, 0
	setmetatile 8, 16, METATILE_SootopolisGym_Stairs, 0
SootopolisCity_Gym_1F_EventScript_StopCheckingStairs::
	return

SootopolisCity_Gym_1F_OnFrame:
	map_script_2 VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs
	map_script_2 VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs
	map_script_2 VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs
	map_script_2 VAR_ICE_STEP_COUNT, 0, SootopolisCity_Gym_1F_EventScript_FallThroughIce
	.2byte 0

SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_FallThroughIce::
	lockall
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_Gym_1F_Movement_FallThroughIce
	waitmovement 0
	playse SE_FALL
	delay 60
	warphole MAP_SOOTOPOLIS_CITY_GYM_B1F
	waitstate
	end

SootopolisCity_Gym_1F_Movement_FallThroughIce:
	set_invisible
	step_end

SootopolisCity_Gym_1F_EventScript_Wallace::
	trainerbattle_single TRAINER_WALLACE_1, SootopolisCity_Gym_1F_Text_WallaceIntro, SootopolisCity_Gym_1F_Text_WallaceDefeat, SootopolisCity_Gym_1F_EventScript_WallaceDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq SootopolisCity_Gym_1F_EventScript_WallaceRematch
	goto_if_unset FLAG_RECEIVED_TM03, SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2
	goto_if_unset FLAG_BADGE06_GET, SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge
	msgbox SootopolisCity_Gym_1F_Text_WallacePostBattle, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_WallaceDefeated::
	message SootopolisCity_Gym_1F_Text_ReceivedRainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
	setflag FLAG_BADGE08_GET
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
	setflag FLAG_HIDE_OUTSIDE_ELITE_4
	setvar VAR_SOOTOPOLIS_CITY_STATE, 6
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
	clearflag FLAG_HIDE_SOOTOPOLIS_OVERWORLD_POKEMON
	setvar VAR_0x8008, 8
	call Common_EventScript_SetGymTrainers
	call SootopolisCity_Gym_1F_EventScript_GiveWaterPulse
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SootopolisCity_Gym_1F_Text_RegisteredWallace, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WALLACE_MATCH_CALL
	release
	end

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse::
	giveitem ITEM_TM03
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_BagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM03
	return

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2::
	giveitem ITEM_TM03
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM03
	release
	end

SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge::
	msgbox SootopolisCity_Gym_1F_Text_GoGetFortreeBadge, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_WallaceRematch::
	trainerbattle_rematch_double TRAINER_WALLACE_1, SootopolisCity_Gym_1F_Text_WallacePreRematch, SootopolisCity_Gym_1F_Text_WallaceRematchDefeat, SootopolisCity_Gym_1F_Text_WallaceRematchNeedTwoMons
	msgbox SootopolisCity_Gym_1F_Text_WallacePostRematch, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SOOTOPOLIS_GYM, SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory
	msgbox SootopolisCity_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox SootopolisCity_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_GymStatueCertified::
	msgbox SootopolisCity_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_EventScript_GymStatue::
	msgbox SootopolisCity_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_Text_GymGuideAdvice:
	.string "Yo! How's it going, Champion-\n"
	.string "bound {PLAYER}?\p"
	.string "Sootopolis's Gym Leader Wallace is\n"
	.string "a master of Water-type Pokémon.\p"
	.string "And, to get to Wallace, an icy floor\n"
	.string "will hamper your progress…\p"
	.string "Listen, I'm sorry, but that's all the\n"
	.string "advice that I have for you.\p"
	.string "The rest of the way, you have to\n"
	.string "go for it yourself!$"

SootopolisCity_Gym_1F_Text_GymGuidePostVictory:
	.string "Yow! You've beaten even Wallace, who\n"
	.string "was supposedly the best in all Hoenn!\p"
	.string "Okay! Check out your Trainer Card.\p"
	.string "If you've gotten all the Badges, you're\n"
	.string "set for the Pokémon League challenge!$"

SootopolisCity_Gym_1F_Text_WallaceIntro:
	.string "Allow me to formally introduce myself.\p"
	.string "I am Wallace\n"
	.string "The Gym Leader of Sootopolis City.\p"
	.string "There's something about you…\n"
	.string "A difference in your demeanor…\l"
	.string "I think I sense that in you.\p"
	.string "What happened at Sky Pillar,\n"
	.string "and what you did there…\p"
	.string "Our upcoming battle will make that\n"
	.string "all clear.\p"
	.string "Now, show me. Show me the power\n"
	.string "you wield with your Pokemon.\p"
	.string "And I, in turn shall present you…\p"
	.string "with a performance of illusions\n"
	.string "in water by me and my Pokemon!$"

@ NOTE: This defeat text actually causes a buffer overflow. It's about 50 bytes too long for
@ the gDisplayedStringBattle buffer that it's put into, and it stomps all over the gBattleTextBuffs
@ after, as well as the otherwise unused array after that. One wonders if that's the reason for
@ the existence of that unused array of ints.
SootopolisCity_Gym_1F_Text_WallaceDefeat:
	.string "Bravo!\p"
	.string "I realize now your authenticity and\n"
	.string "magnificence as a Pokemon Trainer!\p"
	.string "I find much joy in having met you\n"
	.string "and your Pokemon.\p"
	.string "You have proven yourself worthy\n"
	.string "of the Rain Badge.$"

SootopolisCity_Gym_1F_Text_ReceivedRainBadge:
	.string "{PLAYER} received the Rain Badge\n"
	.string "from Wallace.$"

SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis:
	.string "Having that badge assures you full\n"
	.string "obedience of all your Pokémon to every\l"
	.string "command you make.\p"
	.string "The Rain Badge also gifts your Pokémon\n"
	.string "the strength to carry you up walls of\l"
	.string "cascading water with the Waterfall\l"
	.string "field move.\p"
	.string "And, so you never forget the battle\n"
	.string "we shared…$"

SootopolisCity_Gym_1F_Text_ExplainWaterPulse:
	.string "The Technical Machine I handed you\n"
	.string "contains Water Pulse.\p"
	.string "In use, it will occasionally confuse\n"
	.string "the target with ultrasonic waves.\p"
	.string "…\p"
	.string "Many paths are open to you now.\p"
	.string "One path would take you to the Pokemon\n"
	.string "League.\p"
	.string "It is the goal that all trainers in\n"
	.string "Hoenn aspire to reach after obtaining\l"
	.string "all 8 Gym Badges.\p"
	.string "You can reach it from Evergrande City.$"

SootopolisCity_Gym_1F_Text_RegisteredWallace:
	.string "Registered Gym Leader Wallace\n"
	.string "in the Pokénav.$"

SootopolisCity_Gym_1F_Text_WallacePostBattle:
	.string "The Trainers who have gathered all\n"
	.string "the Gym Badges of Hoenn should make\l"
	.string "way to the ultimate destination.\p"
	.string "Travel to the easternmost reaches\n"
	.string "of Hoenn, to the island Ever Grande.\p"
	.string "There, you shall find the Pokémon\n"
	.string "League.$"

SootopolisCity_Gym_1F_Text_GoGetFortreeBadge:
	.string "There remains but one Badge to obtain\n"
	.string "in Hoenn.\p"
	.string "If you wish to challenge the Pokémon\n"
	.string "League, you must obtain the last\l"
	.string "Badge from the Gym in Fortree.$"

SootopolisCity_Gym_1F_Text_GymStatue:
	.string "SOOTOPOLIS CITY POKéMON GYM$"

SootopolisCity_Gym_1F_Text_GymStatueCertified:
	.string "SOOTOPOLIS CITY POKéMON GYM\p"
	.string "WALLACE'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"

@TODO: update the Wallace rematch text. He is currently using Juan's.
SootopolisCity_Gym_1F_Text_WallacePreRematch:
	.string "Wallace: Ah, this gym had returned to its\n"
	.string "usual state of serenity…\p"
	.string "But our young typhoon has returned\n"
	.string "to put us to the test again!\p"
	.string "Well, my friend, most certainly!\p"
	.string "I shall be delighted to dance with you\n"
	.string "as often as you wish!$"

SootopolisCity_Gym_1F_Text_WallaceRematchDefeat:
	.string "Ahahaha, you are the winner!\n"
	.string "You have defeated me again!$"

SootopolisCity_Gym_1F_Text_WallacePostRematch:
	.string "Wallace: If I told you to become my\n"
	.string "apprentice, you will refuse, I am sure.\p"
	.string "I would like to make a gift of my coat\n"
	.string "to you.\p"
	.string "But again, you will refuse.\n"
	.string "I imagine that to be so.\p"
	.string "And that, my friend, is a certain sign\n"
	.string "of nobility!$"

SootopolisCity_Gym_1F_Text_WallaceRematchNeedTwoMons:
	.string "Wallace: Ah, this gym had returned to its\n"
	.string "usual state of serenity…\p"
	.string "But our young typhoon has returned\n"
	.string "to put us to the test again!\p"
	.string "Well, my friend, most certainly!\n"
	.string "I shall be delighted to dance with you…\p"
	.string "Ah, no, no, no.\n"
	.string "You have with you but one Pokémon.\p"
	.string "I wish that you would return with\n"
	.string "two, perhaps more, Pokémon, please.$"

