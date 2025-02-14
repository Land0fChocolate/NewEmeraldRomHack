.set LOCALID_MAN_2, 3
.set LOCALID_WOMAN_2, 6
.set LOCALID_SCHOOL_KID, 17
.set LOCALID_WOMAN_1, 18
.set LOCALID_MAN_1, 19
.set LOCALID_LISIA, 29
.set LOCALID_CAMERAMAN, 30
.set LOCALID_TWIN, 31
.set LOCALID_STREET_THUG, 32
.set LOCALID_GIRL, 33
.set LOCALID_MANIAC, 34

LilycoveCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_OnLoad
	.byte 0

LilycoveCity_OnTransition:
	setflag FLAG_VISITED_LILYCOVE_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	call Common_EventScript_SetupRivalGfxId
	call_if_unset FLAG_HIDE_LILYCOVE_CITY_LISIA, LilycoveCity_EventScript_SetUpLisiaEvent
	end

LilycoveCity_OnLoad:
	call_if_unset FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_SetWailmerMetatiles
	end

LilycoveCity_EventScript_SetUpLisiaEvent:
	setobjectxyperm LOCALID_WOMAN_2, 31, 26
	setobjectmovementtype LOCALID_WOMAN_2, MOVEMENT_TYPE_FACE_LEFT
	setobjectxyperm LOCALID_SCHOOL_KID, 23, 27
	setobjectmovementtype LOCALID_SCHOOL_KID, MOVEMENT_TYPE_FACE_RIGHT
	return

LilycoveCity_EventScript_SetWailmerMetatiles::
	setmetatile 76, 12, METATILE_Lilycove_Wailmer0, 1
	setmetatile 77, 12, METATILE_Lilycove_Wailmer1, 1
	setmetatile 76, 13, METATILE_Lilycove_Wailmer2, 1
	setmetatile 77, 13, METATILE_Lilycove_Wailmer3, 1
	setmetatile 76, 14, METATILE_Lilycove_Wailmer0_Alt, 1
	setmetatile 77, 14, METATILE_Lilycove_Wailmer1_Alt, 1
	setmetatile 76, 15, METATILE_Lilycove_Wailmer2, 1
	setmetatile 77, 15, METATILE_Lilycove_Wailmer3, 1
	setmetatile 77, 16, METATILE_Lilycove_Wailmer0_Alt, 1
	setmetatile 78, 16, METATILE_Lilycove_Wailmer1_Alt, 1
	setmetatile 77, 17, METATILE_Lilycove_Wailmer2, 1
	setmetatile 78, 17, METATILE_Lilycove_Wailmer3, 1
	return

LilycoveCity_EventScript_BerryGentleman::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_LILYCOVE_RECEIVED_BERRY, LilycoveCity_EventScript_ReceivedBerry
	msgbox LilycoveCity_Text_BerrySuitsYou, MSGBOX_DEFAULT
	random 10
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_LILYCOVE_RECEIVED_BERRY
	msgbox LilycoveCity_Text_BecauseYoureTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ReceivedBerry::
	msgbox LilycoveCity_Text_PokeblocksSuitPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man3::
	msgbox LilycoveCity_Text_ContestHallInTown, MSGBOX_NPC
	end

LilycoveCity_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_GirlAquaGone
	msgbox LilycoveCity_Text_StrangeCaveInCove, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_GirlAquaGone::
	msgbox LilycoveCity_Text_EvolvedPokemonWithTradeback, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_RichBoy::
	msgbox LilycoveCity_Text_ImFromKanto, MSGBOX_NPC
	end

LilycoveCity_EventScript_Sailor2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Sailor2AquaGone
	msgbox LilycoveCity_Text_TeamAquaBeenTrainingWailmer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor2AquaGone::
	msgbox LilycoveCity_Text_SomeonePuntedTeamAquaOut, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Woman2AquaGone
	msgbox LilycoveCity_Text_SomeoneStoleMyPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2AquaGone::
	msgbox LilycoveCity_Text_MissingPokemonCameBack, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man2::
	msgbox LilycoveCity_Text_ImArtDealer, MSGBOX_NPC
	end

LilycoveCity_EventScript_ExpertM1::
	msgbox LilycoveCity_Text_SeaRemainsForeverYoung, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertF::
	msgbox LilycoveCity_Text_SixtyYearsAgoHusbandProposed, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertM2::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_ExpertM2AquaGone
	msgbox LilycoveCity_Text_TeamAquaRenovatedCavern, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ExpertM2AquaGone::
	msgbox LilycoveCity_Text_TeamAquaLotGoneForGood, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor1::
	msgbox LilycoveCity_Text_HeardTowerCalledSkyPillar, MSGBOX_NPC
	end

LilycoveCity_EventScript_FatMan::
	msgbox LilycoveCity_Text_SawTallTowerOnRoute131, MSGBOX_NPC
	end

LilycoveCity_EventScript_Man1::
	lockall
	msgbox LilycoveCity_Text_JustArrivedAndSawRarePokemon, MSGBOX_NPC
	applymovement LOCALID_MAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_Woman1::
	lockall
	msgbox LilycoveCity_Text_HoneymoonVowToSeeRarePokemon, MSGBOX_NPC
	applymovement LOCALID_WOMAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_CitySign::
	msgbox LilycoveCity_Text_CitySign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ContestHallSign::
	msgbox LilycoveCity_Text_ContestHallSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MotelSign::
	msgbox LilycoveCity_Text_MotelSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_TradebackSign::
	msgbox LilycoveCity_Text_TradebackSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MuseumSign::
	lockall
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
	switch VAR_0x8004
	case 0, LilycoveCity_EventScript_MuseumSignNoPaintings
	msgbox LilycoveCity_Text_MuseumSignPlayersExhibit, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_MuseumSignNoPaintings::
	msgbox LilycoveCity_Text_MuseumSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_HarborSignFerryReady
	msgbox LilycoveCity_Text_HarborSignUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSignFerryReady::
	msgbox LilycoveCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_TrainerFanClubSign::
	msgbox LilycoveCity_Text_TrainerFanClubSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_DepartmentStoreSign::
	msgbox LilycoveCity_Text_DepartmentStoreSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MoveDeletersHouseSign::
	msgbox LilycoveCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_WailmerTrainerGrunt::
	lockall
	goto_if_set FLAG_MET_WAILMER_TRAINER, LilycoveCity_EventScript_MetWailmerTrainer
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_Text_GetLostMessingUpTraining, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_MET_WAILMER_TRAINER
	releaseall
	end

LilycoveCity_EventScript_MetWailmerTrainer::
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_AquaGrunt1::
	msgbox LilycoveCity_Text_MovedLootIntoHideoutToday, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt2::
	msgbox LilycoveCity_Text_ChanceToDoBigThings, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt3::
	msgbox LilycoveCity_Text_DontGoNearCaveInCove, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt4::
	msgbox LilycoveCity_Text_IfWorldBecomesOurs, MSGBOX_NPC
	end

LilycoveCity_EventScript_SchoolKidM::
	lock
	faceplayer
	msgbox LilycoveCity_Text_DoYouKnowAboutBerryBlender, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq LilycoveCity_EventScript_KnowAboutBerryBlender
	compare VAR_RESULT, NO
	call_if_eq LilycoveCity_EventScript_DontKnowAboutBerryBlender
	release
	end

LilycoveCity_EventScript_KnowAboutBerryBlender::
	msgbox LilycoveCity_Text_FasterSpinBetterPokeblocks, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DontKnowAboutBerryBlender::
	msgbox LilycoveCity_Text_ExplainBerryBlender, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_LisiaEvent::
	lockall
	setvar VAR_LISIA_EVENT_TRIGGER_STATE, 1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	applymovement LOCALID_LISIA, LilycoveCity_Movement_LisiaSpin
	waitmovement 0
	msgbox LilycoveCity_Text_LisiaIntro, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LISIA, LilycoveCity_Movement_LisiaLookAround
	waitmovement 0
	applymovement LOCALID_LISIA, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	delay 20
	getplayerxy VAR_0x8004, VAR_0x8005
	compare VAR_0x8005, 25
	goto_if_eq LilycoveCity_EventScript_LisiaMoveToPlayerTop
	compare VAR_0x8005, 26
	goto_if_eq LilycoveCity_EventScript_LisiaMoveToPlayerMid
	compare VAR_0x8005, 27
	goto_if_eq LilycoveCity_EventScript_LisiaMoveToPlayerBot
	end

LilycoveCity_Movement_LisiaSpin:
	face_up
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_up
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	step_end

LilycoveCity_Movement_LisiaLookAround:
	face_right
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	step_end

LilycoveCity_EventScript_LisiaMoveToPlayerTop::
	applymovement LOCALID_LISIA, LilycoveCity_Movement_LisiaMoveToPlayerTop
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	goto LilycoveCity_EventScript_LisiaTalksToPlayer

LilycoveCity_Movement_LisiaMoveToPlayerTop:
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end

LilycoveCity_EventScript_LisiaMoveToPlayerMid::
	applymovement LOCALID_LISIA, LilycoveCity_Movement_LisiaMoveToPlayerMid
	waitmovement 0
	goto LilycoveCity_EventScript_LisiaTalksToPlayer

LilycoveCity_Movement_LisiaMoveToPlayerMid:
	walk_right
	walk_right
	walk_right
	step_end

LilycoveCity_EventScript_LisiaMoveToPlayerBot::
	applymovement LOCALID_LISIA, LilycoveCity_Movement_LisiaMoveToPlayerBot
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	goto LilycoveCity_EventScript_LisiaTalksToPlayer

LilycoveCity_Movement_LisiaMoveToPlayerBot:
	walk_right
	walk_right
	walk_right
	walk_right
	face_down
	step_end

LilycoveCity_EventScript_LisiaTalksToPlayer::
	applymovement LOCALID_CAMERAMAN, LilycoveCity_Movement_CameramanStepsForward
	applymovement LOCALID_TWIN, Common_Movement_FaceRight
	applymovement LOCALID_STREET_THUG, Common_Movement_FaceRight
	applymovement LOCALID_MAN_2, Common_Movement_FaceUp
	waitmovement 0
	msgbox LilycoveCity_Text_LisiaBaffledExpression, MSGBOX_DEFAULT
	giveitem ITEM_POKEBLOCK_CASE
	setflag FLAG_RECEIVED_POKEBLOCK_CASE
	msgbox LilycoveCity_Text_LisiaThisIsAPokeblockKit, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LISIA, Common_Movement_FaceLeft
	waitmovement 0
	msgbox LilycoveCity_Text_LisiaPlayerStoryBegins, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LISIA, LilycoveCity_Movement_LisiaSpin
	waitmovement 0
	fadescreen FADE_TO_BLACK
	delay 60
	setflag FLAG_HIDE_LILYCOVE_CITY_LISIA
	removeobject LOCALID_LISIA
	removeobject LOCALID_CAMERAMAN
	removeobject LOCALID_TWIN
	removeobject LOCALID_STREET_THUG
	removeobject LOCALID_GIRL
	removeobject LOCALID_MANIAC
	setobjectmovementtype LOCALID_SCHOOL_KID, MOVEMENT_TYPE_LOOK_AROUND
	setobjectmovementtype LOCALID_WOMAN_2, MOVEMENT_TYPE_WANDER_AROUND
	fadescreen FADE_FROM_BLACK
	releaseall
	end

LilycoveCity_Movement_CameramanStepsForward:
	walk_right
	walk_right
	walk_right
	step_end

LilycoveCity_Text_LisiaIntro:
	.string "Hiiiiii, ev-er-y-bo-dy! Lisia here!\p"
	.string "I'm going to bring another fantastic\n"
	.string "Trainer into the wild world of\l"
	.string "contesting!\p"
	.string "Eenie… meenie… miney…$"

LilycoveCity_Text_LisiaBaffledExpression:
	.string "Lisia: You there, watching me with that\n"
	.string "baffled expression on your face!\p"
	.string "Hi! Have you never joined in a contest?\n"
	.string "That's just what I want to hear!\p"
	.string "This is the Trainer I'm gonna scout\n"
	.string "today! And their name is…\p"
	.string "{PLAYER}! I can easily see that\n"
	.string "{PLAYER} is a powerful Trainer, with\l"
	.string "several badges of their own already!\p"
	.string "Now listen up, {PLAYER}!\p"
	.string "I don't just want to see your Pokémon\n"
	.string "strong. I want to see you bringing out\l"
	.string "a whole new side of them to show off!\p"
	.string "So here you go, take this!$"

LilycoveCity_Text_LisiaThisIsAPokeblockKit:
	.string "Lisia: That is a Pokéblock Kit, which\n"
	.string "will let you make Pokéblocks for your\l"
	.string "Pokémon out of Berries!\p"
	.string "It also acts as your ticket to enter\n"
	.string "contests!$"

LilycoveCity_Text_LisiaPlayerStoryBegins:
	.string "{PLAYER}'s story begins today!\n"
	.string "Yep! And this chapter should be titled…\p"
	.string "'A Sudden Encounter!\n"
	.string "Miraculous Contest Scouting!'\l"
	.string "That's what I'd call it!\p"
	.string "Now, everybody out there watching…\n"
	.string "You'd better expect great things from\l"
	.string "{PLAYER}, because I do!\p"
	.string "That's it for today's Lisia's Miraculous\n"
	.string "Contest Scouting! See you all next time!$"

LilycoveCity_Text_MovedLootIntoHideoutToday:
	.string "Fufufu…\p"
	.string "We moved more loot into our secret\n"
	.string "Hideout today…\p"
	.string "Wh-who are you?!\n"
	.string "I was just talking to myself!$"

LilycoveCity_Text_ChanceToDoBigThings:
	.string "I'm just a grunt, so I don't know what\n"
	.string "the boss is thinking…\p"
	.string "But being on Team Aqua, I know I'll get\n"
	.string "the chance to do big things!\p"
	.string "Wh-who are you?!\n"
	.string "I was just talking to myself!$"

LilycoveCity_Text_DontGoNearCaveInCove:
	.string "Hey, you!\p"
	.string "Don't go near the cave in the cove!\p"
	.string "Why? You don't need a reason why!\n"
	.string "I'm an adult, so you just listen to me!$"

LilycoveCity_Text_IfWorldBecomesOurs:
	.string "If this whole wide world becomes ours,\n"
	.string "Team Aqua's, it will be a happier\l"
	.string "place for Pokémon, too.$"

LilycoveCity_Text_WailmerLeapOutOfWater:
	.string "There! Wailmer!\n"
	.string "Leap out of the water now!$"

LilycoveCity_Text_GetLostMessingUpTraining:
	.string "Hunh? What do you want?\p"
	.string "You're messing up our training,\n"
	.string "so can you, like, get lost?$"

LilycoveCity_Text_ContestHallInTown:
	.string "There's a Pokémon Contest Hall\n"
	.string "right in this here town. \p"
	.string "That means well-raised Pokémon will\n"
	.string "come from all over the country.\p"
	.string "My heart swells with excitement!$"

LilycoveCity_Text_StrangeCaveInCove:
	.string "Have you seen that strange cave in\n"
	.string "the cove at the edge of town?$"

LilycoveCity_Text_EvolvedPokemonWithTradeback:
	.string "I came all this way to see the tradeback\n"
	.string "guy so I could evolve my Pokémon.\p"
	.string "But now I'm having second thoughts,\n"
	.string "I love my Pokémon the way they are…$"

LilycoveCity_Text_ImFromKanto:
	.string "I came from Kanto.\p"
	.string "The Hoenn region is beautiful with\n"
	.string "all its water and verdant nature.\p"
	.string "Hunh? Wait a second…\p"
	.string "Could there be rare Pokémon that live\n"
	.string "only in this area?$"

LilycoveCity_Text_TeamAquaBeenTrainingWailmer:
	.string "Team Aqua's been training their\n"
	.string "Wailmer in the cove.\p"
	.string "We sailors can't get our boats out\n"
	.string "to sea with them in the way!$"

LilycoveCity_Text_SomeonePuntedTeamAquaOut:
	.string "Ahoy, did you know?\p"
	.string "Someone punted Team Aqua out of\n"
	.string "the way for us!\p"
	.string "That got the Wailmer out of the cove,\n"
	.string "so we can get our boats out again.$"

LilycoveCity_Text_SomeoneStoleMyPokemon:
	.string "I was taking a relaxing snooze at the\n"
	.string "seaside inn to the sound of waves…\p"
	.string "When someone stole my Pokémon!\p"
	.string "Who's the abductor?\n"
	.string "Team Aqua? Is it Team Aqua?$"

LilycoveCity_Text_MissingPokemonCameBack:
	.string "My missing Pokémon…\n"
	.string "It came back without me noticing!$"

LilycoveCity_Text_ImArtDealer:
	.string "I'm an Art Dealer.\p"
	.string "I am a buyer and seller of fine art,\n"
	.string "especially paintings.\p"
	.string "I've heard that the Museum here has\n"
	.string "magnificent works on exhibit…$"

LilycoveCity_Text_SeaRemainsForeverYoung:
	.string "Even as we grow old and wrinkled,\n"
	.string "the sea remains forever young with\l"
	.string "the vivid brilliance of life…\p"
	.string "Fwohoho fwohohohoho…$"

LilycoveCity_Text_SixtyYearsAgoHusbandProposed:
	.string "It was sixty years ago that my husband\n"
	.string "proposed to me here.\l"
	.string "The sea remains as beautiful as ever.\p"
	.string "Mufufufu mufufufufufu…$"

LilycoveCity_Text_TeamAquaRenovatedCavern:
	.string "Hm, you know of the peculiar cavern\n"
	.string "in this cove?\p"
	.string "That had been a natural formation,\n"
	.string "but then that Team Aqua lot came\l"
	.string "along and made their renovations.\p"
	.string "They call themselves\n"
	.string "the “nature-loving Team Aqua”!\p"
	.string "But what they do and what they say\n"
	.string "don't match at all!$"

LilycoveCity_Text_TeamAquaLotGoneForGood:
	.string "That cave in the cove…\p"
	.string "I didn't notice it right away,\n"
	.string "but it's completely empty now.\p"
	.string "That Team Aqua lot, they must\n"
	.string "have gone away for good.$"

LilycoveCity_Text_CitySign:
	.string "LILYCOVE CITY\p"
	.string "“Where the land ends and the\n"
	.string "sea begins.”$"

LilycoveCity_Text_ContestHallSign:
	.string "POKéMON CONTEST HALL\n"
	.string "“The gathering place for Trainers!”$"

LilycoveCity_Text_MotelSign:
	.string "COVE LILY MOTEL\p"
	.string "“Remember us as Cove Lily of\n"
	.string "Lilycove.”$"

LilycoveCity_Text_TradebackSign:
	.string "TRADEBACK SERVICE\n"
	.string "“Evolve your Pokémon!”$"

LilycoveCity_Text_MuseumSign:
	.string "LILYCOVE MUSEUM\p"
	.string "“Pokémon Masterpiece Collection\n"
	.string "on exhibit!”$"

LilycoveCity_Text_MuseumSignPlayersExhibit:
	.string "LILYCOVE MUSEUM\p"
	.string "“{PLAYER}'s Pokémon Collection\n"
	.string "on exhibit!”$"

LilycoveCity_Text_HarborSignUnderConstruction:
	.string "LILYCOVE CITY HARBOR\p"
	.string "“The ferry S.S. Tidal is under\n"
	.string "construction in Slateport City.\p"
	.string "“Service is scheduled to begin\n"
	.string "shortly.”$"

LilycoveCity_Text_HarborSign:
	.string "LILYCOVE CITY HARBOR\p"
	.string "“Enjoy a delightful cruise on\n"
	.string "the ferry S.S. Tidal.”$"

LilycoveCity_Text_TrainerFanClubSign:
	.string "POKéMON TRAINER FAN CLUB\p"
	.string "The names of Trainers are scribbled\n"
	.string "all over the sign…$"

LilycoveCity_Text_DepartmentStoreSign:
	.string "LILYCOVE DEPARTMENT STORE\p"
	.string "“Overflowing with great merchandise\n"
	.string "and excitement!\p"
	.string "“A great place to find that something\n"
	.string "you need!”$"

LilycoveCity_Text_MoveDeletersHouseSign:
	.string "MOVE DELETER'S HOUSE\p"
	.string "“Unwanted Pokémon moves deleted.”$"

LilycoveCity_Text_DoYouKnowAboutBerryBlender:
	.string "Do you know about the machine\n"
	.string "Berry Blender?$"

LilycoveCity_Text_FasterSpinBetterPokeblocks:
	.string "People have to work together to get it\n"
	.string "to spin faster.\p"
	.string "The faster you can make it spin, the\n"
	.string "better {POKEBLOCK}S you can get, I've heard.$"

LilycoveCity_Text_ExplainBerryBlender:
	.string "It's used for making a kind of candy\n"
	.string "called a {POKEBLOCK}.\p"
	.string "If you give a good {POKEBLOCK} to a Pokémon,\n"
	.string "its condition will improve by a lot.$"

LilycoveCity_Text_HeardTowerCalledSkyPillar:
	.string "I heard there's a tower somewhere out\n"
	.string "on the sea routes.\p"
	.string "It's called the Sky Pillar, I hear.$"

LilycoveCity_Text_SawTallTowerOnRoute131:
	.string "I saw this tall tower somewhere\n"
	.string "around Route 131.\p"
	.string "Could that possibly be…?$"

LilycoveCity_Text_JustArrivedAndSawRarePokemon:
	.string "We just arrived here on our\n"
	.string "honeymoon vacation.\p"
	.string "We happened to see a dragon-type\n"
	.string "Pokémon flying way up in the sky.\p"
	.string "Do cool Pokémon like that live in\n"
	.string "the Hoenn region?$"

LilycoveCity_Text_HoneymoonVowToSeeRarePokemon:
	.string "On our honeymoon, we vowed to see as\n"
	.string "many rare Pokémon as we can.\p"
	.string "So we were delighted to see a rare\n"
	.string "Pokémon as soon as we arrived.\p"
	.string "I mean, we are totally happy!$"

