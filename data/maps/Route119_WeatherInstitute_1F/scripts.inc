.set LOCALID_LITTLE_BOY, 5

Route119_WeatherInstitute_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_1F_OnTransition
	.byte 0

Route119_WeatherInstitute_1F_OnTransition:
	compare VAR_WEATHER_INSTITUTE_STATE, 0
	call_if_eq Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos
	compare VAR_WEATHER_INSTITUTE_STATE, 6
	call_if_eq Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos
	checkflag FLAG_ARRIVED_AT_NAVEL_ROCK
	goto_if TRUE Route119_WeatherInstitute_1F_SetWeatherInstituteStateTo5
	end

Route119_WeatherInstitute_1F_SetWeatherInstituteStateTo5::
	setvar VAR_WEATHER_INSTITUTE_STATE, 5
	setflag FLAG_HIDE_ZINNIA_WEATHER_INSTITUTE
	end

Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos::
	setobjectxyperm LOCALID_LITTLE_BOY, 0, 5
	setobjectmovementtype LOCALID_LITTLE_BOY, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_1F_EventScript_LittleBoy::
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	compare VAR_WEATHER_INSTITUTE_STATE, 0
	goto_if_eq Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere
	compare VAR_WEATHER_INSTITUTE_STATE, 6
	goto_if_eq Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere
	msgbox Route119_WeatherInstitute_1F_Text_WowYoureStrong, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere::
	msgbox Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker1::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_1F_EventScript_StudyingRain
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	compare VAR_0x8004, 2  @ Both defeated
	goto_if_eq Route119_WeatherInstitute_1F_EventScript_StudyingRain
	msgbox Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated::
	addvar VAR_0x8004, 1
	return

Route119_WeatherInstitute_1F_EventScript_StudyingRain::
	msgbox Route119_WeatherInstitute_1F_Text_ProfStudyingRain, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker2::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_1F_EventScript_InstituteWorker2PreHallOfFame
	dotimebasedevents
	goto_if_set FLAG_DAILY_CASTFORM, Route119_WeatherInstitute_1F_EventScript_BreedingMoreCastform
	msgbox Route119_WeatherInstitute_1F_Text_WouldYouLikeACastform, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Route119_WeatherInstitute_1F_EventScript_DeclinedCastform
	setvar VAR_TEMP_1, SPECIES_CASTFORM
	givemon SPECIES_CASTFORM, 30, ITEM_NONE
	compare VAR_RESULT, 0
	goto_if_eq Route119_WeatherInstitute_1F_EventScript_ReceiveCastform
	compare VAR_RESULT, 1
	goto_if_eq Route119_WeatherInstitute_1F_EventScript_ReceiveCastform
	goto Common_EventScript_NoMoreRoomForPokemon
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker2PreHallOfFame::
	msgbox Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_BreedingMoreCastform::
	msgbox Route119_WeatherInstitute_1F_Text_BreedingMoreCastform, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_DeclinedCastform::
	msgbox Route119_WeatherInstitute_1F_Text_DeclinedCastform, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_ReceiveCastform::
	setflag FLAG_DAILY_CASTFORM
	release
	end

Route119_WeatherInstitute_1F_EventScript_Bed::
	lockall
	msgbox Route119_WeatherInstitute_1F_Text_TakeRestInBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	releaseall
	end

Route119_WeatherInstitute_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_1, Route119_WeatherInstitute_1F_Text_Grunt1Intro, Route119_WeatherInstitute_1F_Text_Grunt1Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_4, Route119_WeatherInstitute_1F_Text_Grunt4Intro, Route119_WeatherInstitute_1F_Text_Grunt4Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_Text_Grunt1Intro:
	.string "The boss got interested in the fancy\n"
	.string "sciencey work they do here,\l"
	.string "so he sent us out.\p"
	.string "Stay out of our way!$"

Route119_WeatherInstitute_1F_Text_Grunt1Defeat:
	.string "Blast it…\n"
	.string "Blasted by a kid…$"

Route119_WeatherInstitute_1F_Text_Grunt1PostBattle:
	.string "Our boss knows everything.\p"
	.string "But I'm just a grunt. What would I know\n"
	.string "about what he's thinking?$"

Route119_WeatherInstitute_1F_Text_Grunt4Intro:
	.string "Huh?\n"
	.string "There's another kid?$"

Route119_WeatherInstitute_1F_Text_Grunt4Defeat:
	.string "Huh?\n"
	.string "I lost?!$"

Route119_WeatherInstitute_1F_Text_Grunt4PostBattle:
	.string "Oh, no…\n"
	.string "I'll catch an earful for losing to a kid…\p"
	.string "I should just take a nap in the bed…$"

Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs:
	.string "While I was sleeping, everyone went\n"
	.string "upstairs!$"

Route119_WeatherInstitute_1F_Text_WowYoureStrong:
	.string "Wow, you're really strong!\p"
	.string "I wish I could be a Pokémon Trainer\n"
	.string "like you!$"

Route119_WeatherInstitute_1F_Text_ProfStudyingRain:
	.string "The professor loves rain.\n"
	.string "That's a fact.\p"
	.string "But if it keeps raining, people will be in\n"
	.string "trouble. That's another fact.\p"
	.string "And thus, the professor is studying\n"
	.string "if the rain can be put to good use.$"

Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather:
	.string "On the 2nd floor of the Institute,\n"
	.string "we study the weather patterns over\l"
	.string "the Hoenn region.\p"
	.string "We've been noticing temporary and\n"
	.string "isolated cases of droughts and\l"
	.string "heavy rain lately…$"

Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo:
	.string "Hello!\n"
	.string "We've been saved by your actions!\p"
	.string "What I don't understand is what on\n"
	.string "earth the Aquas were up to.$"

Route119_WeatherInstitute_1F_Text_BreedingMoreCastform:
	.string "Be sure to give the Castform a nice\n"
	.string "home.$"

Route119_WeatherInstitute_1F_Text_WouldYouLikeACastform:
	.string "Somehow more Castform keep showing up.\n"
	.string "Where do they keep coming from?\p"
	.string "We don't need all of them. Perhaps you\n"
	.string "would like to take one off our hands?$"

Route119_WeatherInstitute_1F_Text_DeclinedCastform:
	.string "That's okay. The Castform is quite\n"
	.string "happy here anyway.$"

Route119_WeatherInstitute_1F_Text_TakeRestInBed:
	.string "There's a bed…\n"
	.string "Let's take a rest.$"

