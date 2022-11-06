.set LOCALID_RIVAL, 5

FallarborTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_OnTransition
	.byte 0

FallarborTown_OnTransition:
	setflag FLAG_VISITED_FALLARBOR_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	clearflag FLAG_CONTEST_SKETCH_CREATED
	end

FallarborTown_EventScript_RivalTrigger::
	clearflag FLAG_HIDE_FALLARBOR_TOWN_RIVAL
	setvar VAR_FALLARBOR_TOWN_RIVAL_STATE, 1
	opendoor 14, 11
	waitdooranim
	addobject LOCALID_RIVAL
	applymovement OBJ_EVENT_ID_PLAYER, FallarborTown_Movement_PlayerMovesOutOfWay
	applymovement LOCALID_RIVAL, FallarborTown_Movement_RivalExitsPokemonCenter
	waitmovement 0
	closedoor 64, 15
	waitdooranim
	delay 10
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq FallarborTown_EventScript_May
	compare VAR_RESULT, FEMALE
	goto_if_eq FallarborTown_EventScript_Brendan
	end

FallarborTown_Movement_RivalExitsPokemonCenter:
	walk_down
	step_end

FallarborTown_Movement_PlayerMovesOutOfWay:
	walk_down
	face_up
	step_end

FallarborTown_EventScript_May::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	msgbox FallarborTown_Text_MayBewareOfTeamMagma, MSGBOX_DEFAULT
	goto FallarborTown_EventScript_Rival_Leaves
	end

FallarborTown_EventScript_Brendan::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	msgbox FallarborTown_Text_BrendanBewareOfTeamMagma, MSGBOX_DEFAULT
	goto FallarborTown_EventScript_Rival_Leaves
	end

FallarborTown_EventScript_Rival_Leaves::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_RIVAL, FallarborTown_Movement_RivalLeaves
	waitmovement 0
	savebgm MUS_DUMMY
	fadedefaultbgm
	removeobject LOCALID_RIVAL
	setflag FLAG_HIDE_FALLARBOR_TOWN_RIVAL
	release
	end

FallarborTown_Movement_RivalLeaves:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

FallarborTown_EventScript_ExpertM::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_EventScript_ExpertMNormal
	msgbox FallarborTown_Text_ShadyCharactersCozmosHome, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_ExpertMNormal::
	msgbox FallarborTown_Text_RegionKnownForMeteors, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_Girl::
	msgbox FallarborTown_Text_MyPreciousAzurill, MSGBOX_NPC
	end

FallarborTown_EventScript_Gentleman::
	msgbox FallarborTown_Text_HaveYouChallengedFlannery, MSGBOX_NPC
	end

FallarborTown_EventScript_DraconidArchives_Sign::
	msgbox FallarborTown_Text_DraconidArchivesSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_TownSign::
	msgbox FallarborTown_Text_TownSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_MoveTutorSign::
	msgbox FallarborTown_Text_MoveTutorSign, MSGBOX_SIGN
	end

FallarborTown_Text_MayBewareOfTeamMagma:
	.string "May: Hey, {PLAYER}.\n"
	.string "Am I glad to see a friendly face!\p"
	.string "I had a run-in with some goons calling\n"
	.string "themselves Team Magma.\p"
	.string "They seem to like making trouble around\n"
	.string "these parts, but my Pokémon were more\l"
	.string "than a match for them.\p"
	.string "Just keep a heads up, okay?\p"
	.string "Alright, see ya!$"

FallarborTown_Text_BrendanBewareOfTeamMagma:
	.string "Brendan: Hey, {PLAYER}.\n"
	.string "Great to see you.\p"
	.string "There are some crooks called Team Magma\n"
	.string "operating in these parts.\p"
	.string "I ended up fighting their grunts, but\n"
	.string "my Pokémon were able to handle them.\p"
	.string "I'm sure you'll be fine, though.\p"
	.string "Alright, see ya!$"

FallarborTown_Text_ShadyCharactersCozmosHome:
	.string "Something's happening,\n"
	.string "and I don't like it!\p"
	.string "I've seen shady characters wandering\n"
	.string "in and out of Prof. Cozmo's home…$"

FallarborTown_Text_RegionKnownForMeteors:
	.string "This region's been known for meteors\n"
	.string "since the olden days.\p"
	.string "They say Meteor Falls was gouged out\n"
	.string "by a falling meteorite long ago.$"

FallarborTown_Text_MyPreciousAzurill:
	.string "See! Take a look!\n"
	.string "This is my precious Azurill!\p"
	.string "It's slick and smooth and plushy, too!$"

FallarborTown_Text_HaveYouChallengedFlannery:
	.string "Have you already challenged Flannery,\n"
	.string "the Leader of Lavaridge Gym?\p"
	.string "The girl's grandfather was famous.\n"
	.string "He was one of the Elite Four in the\l"
	.string "Pokémon League at one point.\p"
	.string "It wouldn't surprise me to see Flannery\n"
	.string "become a great Trainer in her own\l"
	.string "right.$"

FallarborTown_Text_DraconidArchivesSign:
	.string "DRACONID ARCHIVES\n"
	.string "“Keeping Hoenn's history alive.”$"

FallarborTown_Text_TownSign:
	.string "FALLARBOR TOWN\n"
	.string "“A farm community with small gardens.”$"

FallarborTown_Text_MoveTutorSign:
	.string "MOVE TUTOR'S HOUSE\n"
	.string "“New moves taught to Pokémon.”$"

