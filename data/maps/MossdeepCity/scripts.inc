.set LOCALID_RIVAL, 12
.set LOCALID_SCOTT, 13

MossdeepCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_OnTransition
	.byte 0

MossdeepCity_OnTransition:
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

MossdeepCity_Eventscript_RivalTrigger:: @TODO: do more work on this
	clearflag FLAG_HIDE_MOSSDEEP_CITY_RIVAL
	opendoor 64, 15
	waitdooranim
	addobject LOCALID_RIVAL
	applymovement LOCALID_RIVAL, MossdeepCity_Movement_RivalExitsSpaceCenter
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Movement_PlayerMovesOutOfWay
	waitmovement 0
	closedoor 64, 15
	waitdooranim
	delay 10
	goto MossdeepCity_EventScript_Rival

MossdeepCity_Movement_RivalExitsSpaceCenter:
	walk_down
	step_end

MossdeepCity_Movement_PlayerMovesOutOfWay:
	walk_down
	face_up
	step_end

MossdeepCity_EventScript_Rival::
	lock
	faceplayer
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq MossdeepCity_EventScript_May
	compare VAR_RESULT, FEMALE
	goto_if_eq MossdeepCity_EventScript_Brendan
	end

MossdeepCity_EventScript_May::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_MOSSDEEP, MossdeepCity_EventScript_MayAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_MOSSDEEP, MossdeepCity_EventScript_MayAskToBattle
	compare VAR_RESULT, NO
	goto_if_eq MossdeepCity_EventScript_DeclineMayBattle
	msgbox MossdeepCity_Text_MayWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, MossdeepCity_EventScript_BattleMayTreecko
	case 1, MossdeepCity_EventScript_BattleMayTorchic
	case 2, MossdeepCity_EventScript_BattleMayMudkip
	end

MossdeepCity_EventScript_MayAskToBattleAgain::
	msgbox MossdeepCity_Text_MayBattleMe, MSGBOX_YESNO
	return

MossdeepCity_EventScript_MayAskToBattle::
	msgbox MossdeepCity_Text_MaySpaceCenterLetsBattle, MSGBOX_YESNO
	return

MossdeepCity_EventScript_DeclineMayBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_MOSSDEEP
	msgbox MossdeepCity_Text_MayNotRaisingPokemon, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

MossdeepCity_EventScript_Brendan::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_MOSSDEEP, MossdeepCity_EventScript_BrendanAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_MOSSDEEP, MossdeepCity_EventScript_BrendanAskToBattle
	compare VAR_RESULT, NO
	goto_if_eq MossdeepCity_EventScript_DeclineBrendanBattle
	msgbox MossdeepCity_Text_BrendanWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, MossdeepCity_EventScript_BattleBrendanTreecko
	case 1, MossdeepCity_EventScript_BattleBrendanTorchic
	case 2, MossdeepCity_EventScript_BattleBrendanMudkip
	end

MossdeepCity_EventScript_BrendanAskToBattleAgain::
	msgbox MossdeepCity_Text_BrendanBattleMe, MSGBOX_YESNO
	return

MossdeepCity_EventScript_BrendanAskToBattle::
	msgbox MossdeepCity_Text_BrendanSpaceCenterLetsBattle, MSGBOX_YESNO
	return

MossdeepCity_EventScript_DeclineBrendanBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_MOSSDEEP
	msgbox MossdeepCity_Text_BrendanNoConfidence, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

MossdeepCity_EventScript_BattleMayTreecko::
	trainerbattle_no_intro TRAINER_MAY_MOSSDEEP_TREECKO, MossdeepCity_Text_MayDefeat
	goto MossdeepCity_EventScript_DefeatedMay
	end

MossdeepCity_EventScript_BattleMayTorchic::
	trainerbattle_no_intro TRAINER_MAY_MOSSDEEP_TORCHIC, MossdeepCity_Text_MayDefeat
	goto MossdeepCity_EventScript_DefeatedMay
	end

MossdeepCity_EventScript_BattleMayMudkip::
	trainerbattle_no_intro TRAINER_MAY_MOSSDEEP_MUDKIP, MossdeepCity_Text_MayDefeat
	goto MossdeepCity_EventScript_DefeatedMay
	end

MossdeepCity_EventScript_BattleBrendanTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_MOSSDEEP_TREECKO, MossdeepCity_Text_BrendanDefeat
	goto MossdeepCity_EventScript_DefeatedBrendan
	end

MossdeepCity_EventScript_BattleBrendanTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_MOSSDEEP_TORCHIC, MossdeepCity_Text_BrendanDefeat
	goto MossdeepCity_EventScript_DefeatedBrendan
	end

MossdeepCity_EventScript_BattleBrendanMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_MOSSDEEP_MUDKIP, MossdeepCity_Text_BrendanDefeat
	goto MossdeepCity_EventScript_DefeatedBrendan
	end

MossdeepCity_EventScript_DefeatedMay::
	msgbox MossdeepCity_Text_MayGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, MossdeepCity_EventScript_CheckFinalBadge
	compare VAR_RESULT, FALSE
	call_if_eq MossdeepCity_EventScript_MayCollectBadges
	compare VAR_RESULT, TRUE
	call_if_eq MossdeepCity_EventScript_MayPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL
	setflag FLAG_HIDE_MOSSDEEP_CITY_RIVAL
	goto MossdeepCity_EventScript_RivalFlyAway
	end

MossdeepCity_EventScript_CheckFinalBadge::
	goto_if_set FLAG_BADGE08_GET, MossdeepCity_EventScript_HasFinalBadge
	return

MossdeepCity_EventScript_HasFinalBadge::
	setvar VAR_RESULT, TRUE
	return

MossdeepCity_EventScript_MayCollectBadges::
	msgbox MossdeepCity_Text_MayYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

MossdeepCity_EventScript_MayPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_EventScript_MayBattleFrontier
	msgbox MossdeepCity_Text_MayYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

MossdeepCity_EventScript_MayBattleFrontier::
	msgbox MossdeepCity_Text_MayYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

MossdeepCity_EventScript_DefeatedBrendan::
	msgbox MossdeepCity_Text_BrendanGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, MossdeepCity_EventScript_CheckFinalBadge
	compare VAR_RESULT, FALSE
	call_if_eq MossdeepCity_EventScript_BrendanCollectBadges
	compare VAR_RESULT, TRUE
	call_if_eq MossdeepCity_EventScript_BrendanPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
	goto MossdeepCity_EventScript_RivalFlyAway
	end

MossdeepCity_EventScript_BrendanCollectBadges::
	msgbox MossdeepCity_Text_BrendanYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

MossdeepCity_EventScript_BrendanPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_EventScript_BrendanBattleFrontier
	msgbox MossdeepCity_Text_BrendanYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

MossdeepCity_EventScript_BrendanBattleFrontier::
	msgbox MossdeepCity_Text_BrendanYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

MossdeepCity_EventScript_RivalFlyAway::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject VAR_LAST_TALKED
	waitfieldeffect FLDEFF_NPCFLY_OUT
	savebgm MUS_DUMMY
	fadedefaultbgm
	setflag FLAG_MET_RIVAL_MOSSDEEP
	release
	end

MossdeepCity_EventScript_PokefanF::
	lock
	faceplayer
	msgbox MossdeepCity_Text_SpaceCenterLaunchingRockets, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_Sailor::
	lock
	faceplayer
	msgbox MossdeepCity_Text_FeelReliefOnLand, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_NinjaBoy::
	msgbox MossdeepCity_Text_WailmerWatching, MSGBOX_NPC
	end

MossdeepCity_EventScript_ExpertM::
	msgbox MossdeepCity_Text_LifeNeedsSeaToLive, MSGBOX_NPC
	end

MossdeepCity_EventScript_Girl::
	msgbox MossdeepCity_Text_NiceIfWorldCoveredByFlowers, MSGBOX_NPC
	end

MossdeepCity_EventScript_Woman::
	msgbox MossdeepCity_Text_SpecialSpaceCenterRock, MSGBOX_NPC
	end

MossdeepCity_EventScript_WhiteRock::
	msgbox MossdeepCity_Text_ItsAWhiteRock, MSGBOX_SIGN
	end

MossdeepCity_EventScript_GymSign::
	msgbox MossdeepCity_Text_GymSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_CitySign::
	msgbox MossdeepCity_Text_CitySign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_SpaceCenterSign::
	msgbox MossdeepCity_Text_SpaceCenterSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_VisitedMossdeep::
	setflag FLAG_VISITED_MOSSDEEP_CITY
	setvar VAR_TEMP_1, 1
	end

MossdeepCity_EventScript_Man::
	lock
	faceplayer
	msgbox MossdeepCity_Text_SurfExhilarating, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_EventScript_KingsRockBoy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_KINGS_ROCK, MossdeepCity_EventScript_ReceivedKingsRock
	msgbox MossdeepCity_Text_WantKingsRockStevenGaveMe, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MossdeepCity_EventScript_DeclineKingsRock
	msgbox MossdeepCity_Text_YouCanKeepIt, MSGBOX_DEFAULT
	giveitem ITEM_KINGS_ROCK
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_KINGS_ROCK
	release
	end

MossdeepCity_EventScript_ReceivedKingsRock::
	msgbox MossdeepCity_Text_StevensHouseOverThere, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_DeclineKingsRock::
	msgbox MossdeepCity_Text_WhatToDoWithWeirdRock, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_BlackBelt::
	msgbox MossdeepCity_Text_WavesOverFeet, MSGBOX_NPC
	end

MossdeepCity_EventScript_Scott::
	lock
	faceplayer
	msgbox MossdeepCity_Text_ScottSomethingWrongWithTown, MSGBOX_DEFAULT
	closemessage
	compare VAR_FACING, DIR_NORTH
	call_if_eq MossdeepCity_EventScript_ScottExitNorth
	compare VAR_FACING, DIR_EAST
	call_if_eq MossdeepCity_EventScript_ScottExitEast
	addvar VAR_SCOTT_STATE, 1
	removeobject LOCALID_SCOTT
	release
	end

MossdeepCity_EventScript_ScottExitNorth::
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SCOTT, MossdeepCity_Movement_ScottExitNorth
	waitmovement 0
	return

MossdeepCity_EventScript_ScottExitEast::
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SCOTT, MossdeepCity_Movement_ScottExitEast
	waitmovement 0
	return

MossdeepCity_Movement_PlayerWatchScottExit:
	delay_16
	delay_16
	walk_in_place_fastest_left
	step_end

MossdeepCity_Movement_ScottExitNorth:
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

MossdeepCity_Movement_ScottExitEast:
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
	step_end

MossdeepCity_Text_MaySpaceCenterLetsBattle:
	.string "May: Oh, hey {PLAYER},\n"
	.string "fancy meeting you here!\p"
	.string "I didn't have any business at Mossdeep\n"
	.string "or anything, I just felt like checking\l"
	.string "out the Space Center.\p"
	.string "Of course, I've also caught a lot of\n"
	.string "Pokémon, and I've been putting in a lot\l"
	.string "more effort raising them too.\p"
	.string "Do you think you can beat my new team,\n"
	.string "{PLAYER}?\p"
	.string "I'll battle with you, so you can show\n"
	.string "me your Pokémon, {PLAYER}.$"

MossdeepCity_Text_MayNotRaisingPokemon:
	.string "May: Oh, why? {PLAYER}, haven't you\n"
	.string "been raising your Pokémon?\p"
	.string "That's not a very good showing as a\n"
	.string "Trainer$"

MossdeepCity_Text_MayBattleMe:
	.string "May: Come on, battle with me, so I can\n"
	.string "check out your Pokémon!$"

MossdeepCity_Text_MayWontBeBeaten:
	.string "May: The Pokémon I raised won't be\n"
	.string "beaten by your Pokémon, {PLAYER}!$"

MossdeepCity_Text_MayDefeat:
	.string "… … … … … … … …\p"
	.string "I remember the battle I had with you,\n"
	.string "{PLAYER}, on Route 103.\p"
	.string "That battle helped you become this\n"
	.string "strong, {PLAYER}, didn't it?$"

MossdeepCity_Text_MayGoingBackToLittleroot:
	.string "May: I'm thinking of going back to\n"
	.string "Littleroot soon.\p"
	.string "Travelling across Hoenn and catching\n"
	.string "Pokémon has been fun, but I'm a bit\l"
	.string "burnt out and I need a break.\p"
	.string "I've caught a good group of Pokémon,\n"
	.string "and my Pokédex is coming along, so\l"
	.string "I'm going home to show my dad.$"

MossdeepCity_Text_MayYouGoingToCollectBadges:
	.string "{PLAYER}{KUN}, what are you going to do?\p"
	.string "Collect all the Gym Badges and take\n"
	.string "the Pokémon League challenge?\p"
	.string "Well, while you're collecting Badges,\n"
	.string "{PLAYER}{KUN}, I'm going to work on my\l"
	.string "Pokédex. I'll complete it before you!\p"
	.string "See you!$"

MossdeepCity_Text_MayYouGoingToPokemonLeague:
	.string "{PLAYER}{KUN}, what are you going to do?\p"
	.string "Are you taking the Pokémon League\n"
	.string "challenge?\p"
	.string "Or, are you going to complete your\n"
	.string "Pokédex?\p"
	.string "I might've lost to you in battling,\n"
	.string "but I'll finish my Pokédex before you!\p"
	.string "See you!$"

MossdeepCity_Text_MayYouGoingToBattleFrontier:
	.string "{PLAYER}{KUN}, what are you going to do?\p"
	.string "Are you taking the Battle Frontier\n"
	.string "challenge?\p"
	.string "Or, are you going to complete your\n"
	.string "Pokédex?\p"
	.string "I might've lost to you in battling,\n"
	.string "but I'll finish my Pokédex before you!\p"
	.string "See you!$"

MossdeepCity_Text_BrendanSpaceCenterLetsBattle:
	.string "Brendan: Oh, hey, it's {PLAYER}.\p"
	.string "Did you come to check out the Space\n"
	.string "Center too? Well, of course you wouldn't\l"
	.string "be up here otherwise.\p"
	.string "I caught a lot more Pokémon on the way\n"
	.string "here and I've raised an awesome team.\p"
	.string "Want to have a battle to check them out?$"

MossdeepCity_Text_BrendanNoConfidence:
	.string "Brendan: Oh, what's the matter?\n"
	.string "Don't have the confidence?$"

MossdeepCity_Text_BrendanBattleMe:
	.string "Brendan: Want to battle to see who's\n"
	.string "been raising Pokémon better?$"

MossdeepCity_Text_BrendanWontBeBeaten:
	.string "Brendan: Okay, bring it on {PLAYER}!$"

MossdeepCity_Text_BrendanDefeat:
	.string "Humph…\n"
	.string "You've done a lot of raising.\p"
	.string "That stings a bit--I had a head start\n"
	.string "on you as a Trainer$"

MossdeepCity_Text_BrendanGoingBackToLittleroot:
	.string "Brendan: I…\n"
	.string "I plan on going home to Littleroot.\p"
	.string "You know I'm helping out my dad on his\n"
	.string "Pokédex. It's coming together pretty\l"
	.string "well, so I should go show him.$"

MossdeepCity_Text_BrendanYouGoingToCollectBadges:
	.string "{PLAYER}, what are you going to do?\p"
	.string "Collect all the Gym Badges and take\n"
	.string "the Pokémon League challenge?\p"
	.string "Maybe I'll do that, too…\p"
	.string "Well, anyway, hang in there!$"

MossdeepCity_Text_BrendanYouGoingToPokemonLeague:
	.string "{PLAYER}, what are you going to do?\p"
	.string "Since you're that strong, are you\n"
	.string "taking the Pokémon League challenge?\p"
	.string "Heh, even me--if I trained my Pokémon\n"
	.string "a bit more, I should be stronger than\l"
	.string "you, {PLAYER}.\p"
	.string "Well, anyway, hang in there!$"

MossdeepCity_Text_BrendanYouGoingToBattleFrontier:
	.string "{PLAYER}, what are you going to do?\p"
	.string "Are you taking the Battle Frontier\n"
	.string "challenge?\p"
	.string "Or, are you going to complete your\n"
	.string "Pokédex?\p"
	.string "Since you're that strong, you should\n"
	.string "consider the Battle Frontier.\p"
	.string "Heh, if I train my Pokémon a bit more,\n"
	.string "I'll get stronger than you, {PLAYER}.\p"
	.string "Maybe I should go to the Battle\n"
	.string "Frontier.\p"
	.string "Well, anyway, hang in there!$"

MossdeepCity_Text_WantKingsRockStevenGaveMe:
	.string "I got this from Steven, but I don't\n"
	.string "know what it's good for.\p"
	.string "I think it's called King's Rock.\n"
	.string "Do you want it?$"

MossdeepCity_Text_YouCanKeepIt:
	.string "Why would you want it?\n"
	.string "You're weird.\p"
	.string "You can keep it, but keep it a secret\n"
	.string "from Steven.$"

MossdeepCity_Text_StevensHouseOverThere:
	.string "Steven's house is right over there!$"

MossdeepCity_Text_WhatToDoWithWeirdRock:
	.string "Yeah, you think so, too! What are you\n"
	.string "supposed to do with some weird rock?$"

MossdeepCity_Text_WailmerWatching:
	.string "Around Mossdeep, you can see wild\n"
	.string "Wailmer.\p"
	.string "It's called, uh…\n"
	.string "What was it now…\p"
	.string "Wai, Wai, Wai…\p"
	.string "Wailmer watching!$"

MossdeepCity_Text_SpaceCenterReceivedLetter:
	.string "The island's Space Center has been\n"
	.string "launching huge rockets.\p"
	.string "There's been some kind of an uproar\n"
	.string "over a letter they received recently.$"

MossdeepCity_Text_SpaceCenterLaunchingRockets:
	.string "The island's Space Center has been\n"
	.string "launching huge rockets.$"

MossdeepCity_Text_FeelReliefOnLand:
	.string "I'm a Sailor, so the sea's obviously\n"
	.string "more important to me.\p"
	.string "But you know? When I get back on land\n"
	.string "after a long voyage, I do feel relief!$"

MossdeepCity_Text_NiceIfWorldCoveredByFlowers:
	.string "Wouldn't it be nice?\p"
	.string "If the whole world was covered in\n"
	.string "plants and flowers like this island?$"

MossdeepCity_Text_LifeNeedsSeaToLive:
	.string "All life needs the sea to live, even\n"
	.string "though it makes its home on the land.\p"
	.string "Life, having run its course, becomes\n"
	.string "soil and returns to the land.\p"
	.string "And the sea is always connected to\n"
	.string "the land.\p"
	.string "Yes, like the very shoreline here.$"

MossdeepCity_Text_SurfExhilarating:
	.string "A voyage on a ship is fine.\p"
	.string "But crossing the sea with Pokémon\n"
	.string "using Surf…\p"
	.string "Now that's an exhilarating trip!\n"
	.string "Wouldn't you agree, youngster?$"

MossdeepCity_Text_SpecialSpaceCenterRock:
	.string "This rock has a special meaning to\n"
	.string "the people at the Space Center.\p"
	.string "They put it here as their wish for\n"
	.string "their rockets to fly safely.\p"
	.string "When you make a wish, what do you use?\n"
	.string "Do you wish upon a star?\p"
	.string "I use a wish tag to make it happen.\n"
	.string "That's what I do.$"

MossdeepCity_Text_ItsAWhiteRock:
	.string "It's a white rock.$"

MossdeepCity_Text_GymSign:
	.string "MOSSDEEP CITY POKéMON GYM\n"
	.string "LEADERS: LIZA & TATE\p"
	.string "“The mystic combination!”$"

MossdeepCity_Text_CitySign:
	.string "MOSSDEEP CITY\n"
	.string "“Our slogan: Cherish Pokémon!”$"

MossdeepCity_Text_SpaceCenterSign:
	.string "MOSSDEEP SPACE CENTER\n"
	.string "“The closest place to space.”$"

MossdeepCity_Text_ScottSomethingWrongWithTown:
	.string "Scott: {PLAYER}{KUN}, feeling good?\n"
	.string "I'm doing great!\p"
	.string "I'd heard Mossdeep's Gym Leader is\n"
	.string "pretty strong, so I decided to come\l"
	.string "take a look-see for myself.\p"
	.string "But there's something wrong about\n"
	.string "this town.\p"
	.string "People are going on about a warning\n"
	.string "letter and the SPACE CENTER…\p"
	.string "I don't think it concerns me in any\n"
	.string "way, though.$"

MossdeepCity_Text_WavesOverFeet:
	.string "Ahh… It feels great letting the waves\n"
	.string "wash over my feet…$"

