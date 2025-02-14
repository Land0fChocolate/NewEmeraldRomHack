.set LOCALID_RICH_BOY, 1
.set LOCALID_GENTLEMAN, 2
.set LOCALID_SCIENTIST_1, 3
.set LOCALID_SCIENTIST_2, 4
.set LOCALID_ZINNIA, 5
.set LOCALID_STEVEN, 6
.set LOCALID_MAXIE, 7
.set LOCALID_ARCHIE, 8

MossdeepCity_SpaceCenter_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_SpaceCenter_2F_OnTransition
	.byte 0

MossdeepCity_SpaceCenter_2F_OnTransition::
	compare VAR_MOSSDEEP_SPACE_CENTER_STATE, 1
	call_if_eq MossdeepCity_SpaceCenter_2F_EventScript_MoveCivilians
	compare VAR_MOSSDEEP_SPACE_CENTER_STATE, 2
	call_if_eq MossdeepCity_SpaceCenter_2F_EventScript_MoveCiviliansPostZinnia
	end

MossdeepCity_SpaceCenter_2F_EventScript_MoveCivilians::
	setobjectxyperm LOCALID_SCIENTIST_1, 4, 3
	setobjectmovementtype LOCALID_SCIENTIST_1, MOVEMENT_TYPE_FACE_DOWN
	setobjectxyperm LOCALID_SCIENTIST_2, 5, 3
	setobjectmovementtype LOCALID_SCIENTIST_2, MOVEMENT_TYPE_FACE_DOWN
	setobjectxyperm LOCALID_RICH_BOY, 3, 2
	setobjectmovementtype LOCALID_RICH_BOY, MOVEMENT_TYPE_FACE_DOWN
	setobjectxyperm LOCALID_GENTLEMAN, 7, 2
	setobjectmovementtype LOCALID_GENTLEMAN, MOVEMENT_TYPE_FACE_DOWN
	return

MossdeepCity_SpaceCenter_2F_EventScript_MoveCiviliansPostZinnia::
	setobjectxyperm LOCALID_SCIENTIST_1, 4, 3
	setobjectmovementtype LOCALID_SCIENTIST_1, MOVEMENT_TYPE_FACE_DOWN
	setobjectxyperm LOCALID_SCIENTIST_2, 5, 3
	setobjectmovementtype LOCALID_SCIENTIST_2, MOVEMENT_TYPE_FACE_DOWN
	setobjectxyperm LOCALID_RICH_BOY, 3, 2
	setobjectmovementtype LOCALID_RICH_BOY, MOVEMENT_TYPE_FACE_DOWN
	setobjectxyperm LOCALID_GENTLEMAN, 7, 2
	setobjectmovementtype LOCALID_GENTLEMAN, MOVEMENT_TYPE_FACE_DOWN
	setobjectxyperm LOCALID_STEVEN, 3, 7
	setobjectmovementtype LOCALID_STEVEN, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_MAXIE, 4, 6
	setobjectmovementtype LOCALID_MAXIE, MOVEMENT_TYPE_FACE_DOWN
	setobjectxyperm LOCALID_ARCHIE, 5, 6
	setobjectmovementtype LOCALID_ARCHIE, MOVEMENT_TYPE_FACE_DOWN
	return

MossdeepCity_SpaceCenter_2F_EventScript_Scientist1::
	lock
	compare VAR_MOSSDEEP_SPACE_CENTER_STATE, 1
	goto_if_ge MossdeepCity_SpaceCenter_2F_EventScript_Scientist1Zinnia
	msgbox MossdeepCity_SpaceCenter_2F_Text_PokemonInSpace, MSGBOX_DEFAULT
	closemessage
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_Scientist1Zinnia::
	faceplayer
	msgbox MossdeepCity_SpaceCenter_2F_Text_WhyStealSpaceSuit, MSGBOX_DEFAULT
	closemessage
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_Scientist2::
	lock
	compare VAR_MOSSDEEP_SPACE_CENTER_STATE, 1
	goto_if_ge MossdeepCity_SpaceCenter_2F_EventScript_Scientist2Zinnia
	msgbox MossdeepCity_SpaceCenter_2F_Text_StrangeReadings, MSGBOX_DEFAULT
	closemessage
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_Scientist2Zinnia::
	faceplayer
	msgbox MossdeepCity_SpaceCenter_2F_Text_WomanHasScaryPokemon, MSGBOX_DEFAULT
	closemessage
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_Gentleman::
	lock
	faceplayer
	compare VAR_MOSSDEEP_SPACE_CENTER_STATE, 1
	goto_if_ge MossdeepCity_SpaceCenter_2F_EventScript_GentlemanZinnia
	msgbox MossdeepCity_SpaceCenter_2F_Text_WouldveLikedToBeAstronaut, MSGBOX_DEFAULT
	closemessage
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_GentlemanZinnia::
	msgbox MossdeepCity_SpaceCenter_2F_Text_DisruptingScientificWork, MSGBOX_DEFAULT
	closemessage
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_RichBoy::
	lock
	faceplayer
	compare VAR_MOSSDEEP_SPACE_CENTER_STATE, 1
	goto_if_ge MossdeepCity_SpaceCenter_2F_EventScript_RichBoyZinnia
	msgbox MossdeepCity_SpaceCenter_2F_Text_WishOrdinaryPeopleCouldGoIntoSpace, MSGBOX_DEFAULT
	closemessage
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_RichBoyZinnia::
	msgbox MossdeepCity_SpaceCenter_2F_Text_CouldSheNotJustBuyTheSuits, MSGBOX_DEFAULT
	closemessage
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_ZinniaTrigger::
	lockall
	setvar VAR_SPACE_CENTER_TRIGGER_STATE, 1
	getplayerxy VAR_0x8004, VAR_0x8005
	compare VAR_0x8005, 5
	call_if_eq MossdeepCity_SpaceCenter_2F_EventScript_PlayerMovesFromY5
	compare VAR_0x8005, 6
	call_if_eq MossdeepCity_SpaceCenter_2F_EventScript_PlayerMovesFromY6Y7
	compare VAR_0x8005, 7
	call_if_eq MossdeepCity_SpaceCenter_2F_EventScript_PlayerMovesFromY6Y7
	compare VAR_0x8005, 8
	call_if_eq MossdeepCity_SpaceCenter_2F_EventScript_PlayerMovesFromY8
	compare VAR_0x8005, 10
	call_if_eq MossdeepCity_SpaceCenter_2F_EventScript_PlayerMovesFromY10
	compare VAR_0x8005, 11
	call_if_eq MossdeepCity_SpaceCenter_2F_EventScript_PlayerMovesFromY11
	applymovement LOCALID_STEVEN, MossdeepCity_SpaceCenter_2F_Movement_StevenBackOff
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_2F_Text_StevenLose, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ZINNIA, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_2F_Text_ZinniaVictory, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ZINNIA, Common_Movement_FaceRight
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_2F_Text_ZinniaSeesPlayer, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_STEVEN, Common_Movement_FaceRight
	waitmovement 0
	clearflag FLAG_HIDE_ARCHIE_MAXIE_SPACE_CENTER
	addobject LOCALID_MAXIE
	addobject LOCALID_ARCHIE
	applymovement LOCALID_MAXIE, MossdeepCity_SpaceCenter_2F_Movement_MaxieArchieMove
	applymovement LOCALID_ARCHIE, MossdeepCity_SpaceCenter_2F_Movement_MaxieArchieMove
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_2F_Text_ArchieConfrontingZinnia, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAXIE, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_2F_Text_MaxieConfrontingZinnia, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ZINNIA, Common_Movement_WalkInPlaceRight
	applymovement LOCALID_STEVEN, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_2F_Text_ZinniaRespondsToMaxieArchie, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 2
	setflag FLAG_HIDE_ZINNIA_SPACE_CENTER
	removeobject LOCALID_ZINNIA
	setvar VAR_SKY_PILLAR_STATE, 4
	setvar VAR_SKY_PILLAR_2F_TRIGGER, 0
	setvar VAR_SKY_PILLAR_4F_TRIGGER, 0
	setvar VAR_SKY_PILLAR_5F_TRIGGER, 0
	setvar VAR_SKY_PILLAR_TOP_TRIGGER, 0
	clearflag FLAG_HIDE_ZINNIA_SKY_PILLAR_2F
	clearflag FLAG_HIDE_ZINNIA_SKY_PILLAR_4F
	clearflag FLAG_HIDE_ZINNIA_SKY_PILLAR_5F
	clearflag FLAG_HIDE_ZINNIA_SKY_PILLAR_TOP
	setflag FLAG_HIDE_MAXIE_ARCHIE_BIRCH_LAB
	fadescreen FADE_FROM_BLACK
	getplayerxy VAR_0x8004, VAR_0x8005
	compare VAR_0x8005, 6
	call_if_eq MossdeepCity_SpaceCenter_2F_EventScript_StevenLookingAroundY6
	compare VAR_0x8005, 7
	call_if_eq MossdeepCity_SpaceCenter_2F_EventScript_StevenLookingAroundY7
	msgbox MossdeepCity_SpaceCenter_2F_Text_StevenCatchUpToHer, MSGBOX_DEFAULT
	closemessage
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_PlayerMovesFromY5::
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_SpaceCenter_2F_Movement_PlayerMovesY5
	waitmovement 0
	return

MossdeepCity_SpaceCenter_2F_Movement_PlayerMovesY5:
	walk_left
	walk_down
	walk_left
	walk_left
	step_end

MossdeepCity_SpaceCenter_2F_EventScript_PlayerMovesFromY6Y7::
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_SpaceCenter_2F_Movement_PlayerMovesY6Y7
	waitmovement 0
	return

MossdeepCity_SpaceCenter_2F_Movement_PlayerMovesY6Y7:
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_SpaceCenter_2F_EventScript_PlayerMovesFromY8::
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_SpaceCenter_2F_Movement_PlayerMovesY8
	waitmovement 0
	return

MossdeepCity_SpaceCenter_2F_Movement_PlayerMovesY8:
	walk_left
	walk_up
	walk_left
	walk_left
	step_end

MossdeepCity_SpaceCenter_2F_EventScript_PlayerMovesFromY10::
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_SpaceCenter_2F_Movement_PlayerMovesY10
	waitmovement 0
	return

MossdeepCity_SpaceCenter_2F_Movement_PlayerMovesY10:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_SpaceCenter_2F_EventScript_PlayerMovesFromY11::
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_SpaceCenter_2F_Movement_PlayerMovesY11
	waitmovement 0
	return

MossdeepCity_SpaceCenter_2F_Movement_PlayerMovesY11:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_SpaceCenter_2F_Movement_StevenBackOff:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

MossdeepCity_SpaceCenter_2F_Movement_MaxieArchieMove:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_SpaceCenter_2F_EventScript_StevenLookingAroundY6::
	applymovement LOCALID_STEVEN, MossdeepCity_SpaceCenter_2F_Movement_StevenLookingAroundY6
	applymovement LOCALID_MAXIE, MossdeepCity_SpaceCenter_2F_Movement_MaxieLookingAround
	applymovement LOCALID_ARCHIE, MossdeepCity_SpaceCenter_2F_Movement_ArchieLookingAround
	waitmovement 0
	return

MossdeepCity_SpaceCenter_2F_Movement_StevenLookingAroundY6:
	walk_up
	face_right
	delay_16
	face_left
	delay_16
	face_down
	delay_16
	walk_up
	walk_right
	delay_16
	step_end

MossdeepCity_SpaceCenter_2F_EventScript_StevenLookingAroundY7::
	applymovement LOCALID_STEVEN, MossdeepCity_SpaceCenter_2F_Movement_StevenLookingAroundY7
	applymovement LOCALID_MAXIE, MossdeepCity_SpaceCenter_2F_Movement_MaxieLookingAround
	applymovement LOCALID_ARCHIE, MossdeepCity_SpaceCenter_2F_Movement_ArchieLookingAround
	waitmovement 0
	return

MossdeepCity_SpaceCenter_2F_Movement_StevenLookingAroundY7:
	walk_up
	face_right
	delay_16
	face_left
	delay_16
	face_down
	delay_16
	walk_right
	delay_16
	step_end

MossdeepCity_SpaceCenter_2F_Movement_MaxieLookingAround:
	delay_16
	face_up
	delay_16
	face_right
	delay_16
	face_left
	step_end

MossdeepCity_SpaceCenter_2F_Movement_ArchieLookingAround:
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	step_end

MossdeepCity_SpaceCenter_2F_EventScript_Steven::
	lock
	faceplayer
	msgbox MossdeepCity_SpaceCenter_2F_Text_StevenCatchUpToHer, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_Maxie::
	lock
	faceplayer
	msgbox MossdeepCity_SpaceCenter_2F_Text_Maxie, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_Archie::
	lock
	faceplayer
	msgbox MossdeepCity_SpaceCenter_2F_Text_Archie, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_Text_PokemonInSpace:
	.string "Gamma ray pulse? Solar flare?\n"
	.string "Maybe some kind of incredibly powerful\l"
	.string "Pokémon up there in space?\p"
	.string "That couldn't be it, could it?$"

MossdeepCity_SpaceCenter_2F_Text_StrangeReadings:
	.string "These readings are beyond strange.\n"
	.string "What in the world could expel that\l"
	.string "amount of energy?$"

MossdeepCity_SpaceCenter_2F_Text_WouldveLikedToBeAstronaut:
	.string "Hahaha!\p"
	.string "Our research into space exploration\n"
	.string "has produced new technological\l"
	.string "advancements!\p"
	.string "Travelling through the vacuum of space\n"
	.string "will become far easier!$"

MossdeepCity_SpaceCenter_2F_Text_WishOrdinaryPeopleCouldGoIntoSpace:
	.string "I wish ordinary people could go into\n"
	.string "space one day…$"

MossdeepCity_SpaceCenter_2F_Text_WhyStealSpaceSuit:
	.string "Why would anyone need to steal a Space\n"
	.string "Belt? They're only good for travelling\l"
	.string "in space.$"

MossdeepCity_SpaceCenter_2F_Text_WomanHasScaryPokemon:
	.string "I've never seen such terrifying Pokémon\n"
	.string "before. How come I've never heard of\l"
	.string "this woman until now?$"

MossdeepCity_SpaceCenter_2F_Text_DisruptingScientificWork:
	.string "That woman is disrupting scientific\n"
	.string "progress!\l"
	.string "This is an outrage!$"

MossdeepCity_SpaceCenter_2F_Text_CouldSheNotJustBuyTheSuits:
	.string "Why is she stealing from the Space\n"
	.string "Center?\l"
	.string "Could she not just buy their tech?$"

MossdeepCity_SpaceCenter_2F_Text_StevenLose:
	.string "Steven: I've heard that the Lorekeeper\n"
	.string "is an exceptionally skilled trainer,\l"
	.string "but I had no idea that you were this\l"
	.string "strong…\p"
	.string "You could have become the champion.\n"
	.string "Why are you committing petty thievery?$"

MossdeepCity_SpaceCenter_2F_Text_ZinniaVictory:
	.string "Zinnia: I couldn't turn away from my\n"
	.string "duties for sport or fame.\p"
	.string "Winning the Pokémon League doesn't\n"
	.string "compare to the importance of looking\l"
	.string "after the history of Hoenn.\p"
	.string "Nor does it compare to protecting Hoenn\n"
	.string "from great catastrophe.$"

MossdeepCity_SpaceCenter_2F_Text_ZinniaSeesPlayer:
	.string "Zinnia: Oh, our audience grows!$"

MossdeepCity_SpaceCenter_2F_Text_ArchieConfrontingZinnia:
	.string "Archie: Well, well, well.\n"
	.string "What do we have here?\p"
	.string "Ya know, thinking back when I was\n"
	.string "doing misdeeds with Team Aqua,\l"
	.string "something smelled fishy.\p"
	.string "Our movement was just a little…\n"
	.string "too successful.\p"
	.string "Our info was just a little too\n"
	.string "convenient.\p"
	.string "And it was peculiar how we were making\n"
	.string "similar progress with our goals as our\l"
	.string "rivals, Team Magma.\p"
	.string "Me an' Maxie got to talking, and we've\n"
	.string "got it worked out now.$"

MossdeepCity_SpaceCenter_2F_Text_MaxieConfrontingZinnia:
	.string "Maxie: It was an ingenious scheme you\n"
	.string "have had us both play young lady.\p"
	.string "Playing both sides, carefully feeding us\n"
	.string "specific information at specific times\l"
	.string "to construct our actions.\p"
	.string "It's rather impressive, though I don't\n"
	.string "appreciate the fact that you allowed so\l"
	.string "many people and Pokémon to be placed in\l"
	.string "harm's way.\p"
	.string "That is why you must stop right here.\n"
	.string "We cannot continue to allow you to\l"
	.string "endanger the residents of Hoenn any\l"
	.string "longer just to get to Rayquaza.$"

MossdeepCity_SpaceCenter_2F_Text_ZinniaRespondsToMaxieArchie:
	.string "Zinnia: So you've finally figured it\n"
	.string "out. It doesn't matter.\p"
	.string "You have already played your parts, and\n"
	.string "you can't stop me now.\p"
	.string "I will be preventing tragedy befalling\n"
	.string "Hoenn, even if its ignorant citizens\l"
	.string "don't understand.\p"
	.string "Until next time, Buh-bye!$"

MossdeepCity_SpaceCenter_2F_Text_StevenCatchUpToHer:
	.string "Steven: I don't know what the Lorekeeper\n"
	.string "is up to, {PLAYER}, but it could be\l"
	.string "trouble.\p"
	.string "You should run after her.\p"
	.string "If she is really going after Rayquaza\n"
	.string "then she is probably heading for\l"
	.string "Sky Pillar.$"

MossdeepCity_SpaceCenter_2F_Text_Maxie:
	.string "Maxie: Since that woman just defeated\n"
	.string "the former Champion, you {PLAYER}\l"
	.string "remain the only person in Hoenn who can\l"
	.string "stop her.\p"
	.string "I would recommend to be well prepared.$"

MossdeepCity_SpaceCenter_2F_Text_Archie:
	.string "Archie: Bwahahaha!\n"
	.string "Go get her, {PLAYER}!$"
