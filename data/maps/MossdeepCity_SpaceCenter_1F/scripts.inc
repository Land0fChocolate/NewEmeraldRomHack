.set LOCALID_SCIENTIST_1, 1
.set LOCALID_SCIENTIST_2, 2
.set LOCALID_SAILOR, 3
.set LOCALID_OLD_MAN, 4
.set LOCALID_WOMAN, 5

MossdeepCity_SpaceCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_SpaceCenter_1F_OnTransition
	.byte 0

MossdeepCity_SpaceCenter_1F_OnTransition:
	compare VAR_MOSSDEEP_SPACE_CENTER_STATE, 1
	goto_if_ge MossdeepCity_SpaceCenter_1F_EventScript_MoveObjectsForZinnia
	end

MossdeepCity_SpaceCenter_1F_EventScript_MoveObjectsForZinnia::
	setobjectxyperm LOCALID_SAILOR, 5, 6
	setobjectmovementtype LOCALID_SAILOR, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_WOMAN, 14, 8
	setobjectmovementtype LOCALID_WOMAN, MOVEMENT_TYPE_FACE_UP
	setobjectxyperm LOCALID_OLD_MAN, 5, 4
	setobjectmovementtype LOCALID_OLD_MAN, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_SCIENTIST_1, 3, 4
	setobjectmovementtype LOCALID_SCIENTIST_1, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype LOCALID_SCIENTIST_2, MOVEMENT_TYPE_FACE_RIGHT
	end

MossdeepCity_SpaceCenter_1F_EventScript_RocketLaunchCounter::
	lock
	faceplayer
	compare VAR_MOSSDEEP_SPACE_CENTER_STATE, 1
	goto_if_ge MossdeepCity_SpaceCenter_1F_EventScript_RocketLaunchCounterZinnia
	dotimebasedevents
	specialvar VAR_RESULT, GetWeekCount
	buffernumberstring 0, VAR_RESULT
	compare VAR_RESULT, 0
	call_if_eq MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYet
	compare VAR_RESULT, 1
	call_if_ge MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumber
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_RocketLaunchCounterZinnia::
	dotimebasedevents
	specialvar VAR_RESULT, GetWeekCount
	buffernumberstring 0, VAR_RESULT
	compare VAR_RESULT, 0
	call_if_eq MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYetZinnia
	compare VAR_RESULT, 1
	call_if_ge MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumberZinnia
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYetZinnia::
	msgbox MossdeepCity_SpaceCenter_1F_Text_HaywireButRocketLaunchImminent, MSGBOX_DEFAULT
	return

MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumberZinnia::
	msgbox MossdeepCity_SpaceCenter_1F_Text_HaywireButSuccessfulLaunchNumber, MSGBOX_DEFAULT
	return

MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYet::
	msgbox MossdeepCity_SpaceCenter_1F_Text_RocketLaunchImminent, MSGBOX_DEFAULT
	return

MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumber::
	msgbox MossdeepCity_SpaceCenter_1F_Text_SuccessfulLaunchNumber, MSGBOX_DEFAULT
	return

MossdeepCity_SpaceCenter_1F_EventScript_Scientist::
	lock
	faceplayer
	compare VAR_MOSSDEEP_SPACE_CENTER_STATE, 1
	goto_if_ge MossdeepCity_SpaceCenter_1F_EventScript_ScientistZinnia
	msgbox MossdeepCity_SpaceCenter_1F_Text_RocketLaunchDemandsPerfection, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_ScientistZinnia::
	msgbox MossdeepCity_SpaceCenter_1F_Text_WomanCrashedPast, MSGBOX_DEFAULT
	closemessage
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_SunStoneMan::
	lock
	faceplayer
	compare VAR_MOSSDEEP_SPACE_CENTER_STATE, 1
	goto_if_ge MossdeepCity_SpaceCenter_1F_EventScript_SunStoneManZinnia
	goto_if_set FLAG_RECEIVED_SUN_STONE_MOSSDEEP, MossdeepCity_SpaceCenter_1F_EventScript_GaveSunStone
	msgbox MossdeepCity_SpaceCenter_1F_Text_FoundThisYouCanHaveIt, MSGBOX_DEFAULT
	giveitem ITEM_SUN_STONE
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SUN_STONE_MOSSDEEP
	msgbox MossdeepCity_SpaceCenter_1F_Text_HoennFamousForMeteorShowers, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_SunStoneManZinnia::	
	msgbox MossdeepCity_SpaceCenter_1F_Text_NotSafe, MSGBOX_DEFAULT
	closemessage
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_GaveSunStone::
	msgbox MossdeepCity_SpaceCenter_1F_Text_HoennFamousForMeteorShowers, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_Woman::
	lock
	faceplayer
	compare VAR_MOSSDEEP_SPACE_CENTER_STATE, 1
	goto_if_ge MossdeepCity_SpaceCenter_1F_EventScript_WomanZinnia
	msgbox MossdeepCity_SpaceCenter_1F_Text_MissingRocket, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_WomanZinnia::
	msgbox MossdeepCity_SpaceCenter_1F_Text_CriminalsRunningAround, MSGBOX_DEFAULT
	closemessage
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_OldMan::
	lock
	faceplayer
	compare VAR_MOSSDEEP_SPACE_CENTER_STATE, 1
	goto_if_ge MossdeepCity_SpaceCenter_1F_EventScript_OldManZinnia
	msgbox MossdeepCity_SpaceCenter_1F_Text_RocketsBoggleMyMind, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_OldManZinnia::
	msgbox MossdeepCity_SpaceCenter_1F_Text_AboutToSpoilMyDream, MSGBOX_DEFAULT
	closemessage
	release
	end

MossdeepCity_SpaceCenter_1F_Text_AboutToSpoilMyDream:
	.string "A giant chunk of metal bursts through\n"
	.string "the skies and flies into space…\p"
	.string "But some adolescent is about to spoil\n"
	.string "that dream of mine!\p"
	.string "I'm not having any of that!$"

MossdeepCity_SpaceCenter_1F_Text_RocketLaunchImminent:
	.string "The rocket's launch is imminent!$"

MossdeepCity_SpaceCenter_1F_Text_SuccessfulLaunchNumber:
	.string "The rocket launched safely!\n"
	.string "That's successful launch no. {STR_VAR_1}!$"

MossdeepCity_SpaceCenter_1F_Text_HaywireButRocketLaunchImminent:
	.string "I know that things are a little\n"
	.string "haywire right now, but…\p"
	.string "The rocket's launch is imminent!$"

MossdeepCity_SpaceCenter_1F_Text_HaywireButSuccessfulLaunchNumber:
	.string "I know that things are a little\n"
	.string "haywire right now, but…\p"
	.string "The rocket launched safely!\n"
	.string "That's successful launch no. {STR_VAR_1}!$"

MossdeepCity_SpaceCenter_1F_Text_RocketLaunchDemandsPerfection:
	.string "A rocket launch demands perfection.\n"
	.string "Not even a 1% margin of error is allowed.\p"
	.string "Even if it's 99% okay, the whole thing\n"
	.string "is useless if 1% happens to be no good.\p"
	.string "Despite that, we never stop trying.\n"
	.string "Why? It's a dream that never ends.$"

MossdeepCity_SpaceCenter_1F_Text_FoundThisYouCanHaveIt:
	.string "I was taking a stroll down the beach\n"
	.string "when I found this.\p"
	.string "It's not anything I need, so you can\n"
	.string "have it.$"

MossdeepCity_SpaceCenter_1F_Text_HoennFamousForMeteorShowers:
	.string "The Hoenn region has been famous for \n"
	.string "its meteor showers for a long time.$"

MossdeepCity_SpaceCenter_1F_Text_MissingRocket:
	.string "I worked on one of the rockets that was\n"
	.string "launched here.\p"
	.string "I wanted to see how it was doing, but\n"
	.string "the scientists here said it went missing\l"
	.string "and are being weird and dodging my\l"
	.string "questions. What's going on?$"

MossdeepCity_SpaceCenter_1F_Text_RocketsBoggleMyMind:
	.string "A giant chunk of metal bursts through\n"
	.string "the skies and flies into space…\p"
	.string "It boggles my mind!$"

MossdeepCity_SpaceCenter_1F_Text_WomanCrashedPast:
	.string "A woman is causing a ruckus upstairs.\p"
	.string "We can't allow anything to interfere\n"
	.string "with our rocket launch, but we are\l"
	.string "unable to stop her!$"

MossdeepCity_SpaceCenter_1F_Text_NotSafe:
	.string "Who was that person who walked through?\p"
	.string "She didn't look like Team Aqua or Team\n"
	.string "Magma…$"

MossdeepCity_SpaceCenter_1F_Text_CriminalsRunningAround:
	.string "With all these criminals running around\n"
	.string "nowadays, we really ought to invest in\l"
	.string "better security.\p"
	.string "Or perhaps even a national police\n"
	.string "force?$"
