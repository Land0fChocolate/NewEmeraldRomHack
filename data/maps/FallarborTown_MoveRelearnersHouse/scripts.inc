.set LOCALID_MOVE_RELEARNER, 1
.set LOCALID_EGG_MOVE_TUTOR, 3
.set LOCALID_PRE_EVO_MOVE_TUTOR, 4

FallarborTown_MoveRelearnersHouse_MapScripts::
	.byte 0

FallarborTown_MoveRelearnersHouse_EventScript_MoveRelearner::
	lockall
	applymovement LOCALID_MOVE_RELEARNER, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_set FLAG_TEMP_1, FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove
	msgbox FallarborTown_MoveRelearnersHouse_Text_ImTheMoveTutor, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove
	end

FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove::
	checkitem ITEM_HEART_SCALE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	msgbox FallarborTown_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon::
	msgbox FallarborTown_MoveRelearnersHouse_Text_TutorWhichMon, MSGBOX_DEFAULT
	special ChooseMonForMoveRelearner
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	special IsSelectedMonEgg
	compare VAR_RESULT, TRUE
	goto_if_eq FallarborTown_MoveRelearnersHouse_EventScript_CantTeachEgg
	compare VAR_0x8005, 0
	goto_if_eq FallarborTown_MoveRelearnersHouse_EventScript_NoMoveToTeachMon
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMove
	end

FallarborTown_MoveRelearnersHouse_EventScript_ChooseMove::
	msgbox FallarborTown_MoveRelearnersHouse_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	compare VAR_0x8004, 0
	goto_if_eq FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	msgbox FallarborTown_MoveRelearnersHouse_Text_HandedOverHeartScale, MSGBOX_DEFAULT
	removeitem ITEM_HEART_SCALE
	goto FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	end

FallarborTown_MoveRelearnersHouse_EventScript_NoMoveToTeachMon::
	msgbox FallarborTown_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

FallarborTown_MoveRelearnersHouse_EventScript_CantTeachEgg::
	msgbox FallarborTown_MoveRelearnersHouse_Text_CantTeachEgg, MSGBOX_DEFAULT
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale::
	msgbox FallarborTown_MoveRelearnersHouse_Text_ComeBackWithHeartScale, MSGBOX_DEFAULT
	releaseall
	end

FallarborTown_MoveRelearnersHouse_EventScript_EggMoveTutor::
	lockall
	applymovement LOCALID_EGG_MOVE_TUTOR, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_set FLAG_TEMP_2, FallarborTown_MoveRelearnersHouse_EventScript_AskEggTutorTeachMove
	msgbox FallarborTown_MoveRelearnersHouse_Text_ImTheEggTutor, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	goto FallarborTown_MoveRelearnersHouse_EventScript_AskEggTutorTeachMove
	end

FallarborTown_MoveRelearnersHouse_EventScript_AskEggTutorTeachMove::
	checkitem ITEM_HEART_SCALE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq FallarborTown_MoveRelearnersHouse_EventScript_EggTutorComeBackWithHeartScale
	msgbox FallarborTown_MoveRelearnersHouse_Text_EggTutorThatsAHeartScaleWantMeToTeachMove, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, FallarborTown_MoveRelearnersHouse_EventScript_EggTutorComeBackWithHeartScale
	goto FallarborTown_MoveRelearnersHouse_EventScript_EggTutorChooseMon
	end

FallarborTown_MoveRelearnersHouse_EventScript_EggTutorChooseMon::
	msgbox FallarborTown_MoveRelearnersHouse_Text_EggTutorWhichMon, MSGBOX_DEFAULT
	setflag FLAG_EGG_MOVE_TUTOR
	special ChooseMonForMoveRelearner @ The list of moves is built here
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq FallarborTown_MoveRelearnersHouse_EventScript_EggTutorComeBackWithHeartScale
	special IsSelectedMonEgg
	compare VAR_RESULT, TRUE
	goto_if_eq FallarborTown_MoveRelearnersHouse_EventScript_CantTeachEgg
	compare VAR_0x8005, 0
	goto_if_eq FallarborTown_MoveRelearnersHouse_EventScript_NoMoveToTeachMon
	goto FallarborTown_MoveRelearnersHouse_EventScript_EggTutorChooseMove
	end

FallarborTown_MoveRelearnersHouse_EventScript_EggTutorChooseMove::
	msgbox FallarborTown_MoveRelearnersHouse_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	compare VAR_0x8004, 0
	goto_if_eq FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	msgbox FallarborTown_MoveRelearnersHouse_Text_HandedOverHeartScale, MSGBOX_DEFAULT
	removeitem ITEM_HEART_SCALE
	goto FallarborTown_MoveRelearnersHouse_EventScript_EggTutorComeBackWithHeartScale
	end

FallarborTown_MoveRelearnersHouse_EventScript_EggTutorComeBackWithHeartScale::
	msgbox FallarborTown_MoveRelearnersHouse_Text_ComeBackWithHeartScale, MSGBOX_DEFAULT
	clearflag FLAG_EGG_MOVE_TUTOR
	releaseall
	end

FallarborTown_MoveRelearnersHouse_EventScript_PreEvoMoveTutor::
	lockall
	applymovement LOCALID_PRE_EVO_MOVE_TUTOR, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_set FLAG_TEMP_3, FallarborTown_MoveRelearnersHouse_EventScript_AskPreEvoTutorTeachMove
	msgbox FallarborTown_MoveRelearnersHouse_Text_ImThePreEvoTutor, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	goto FallarborTown_MoveRelearnersHouse_EventScript_AskPreEvoTutorTeachMove
	end

FallarborTown_MoveRelearnersHouse_EventScript_AskPreEvoTutorTeachMove::
	checkitem ITEM_HEART_SCALE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq FallarborTown_MoveRelearnersHouse_EventScript_PreEvoTutorComeBackWithHeartScale
	msgbox FallarborTown_MoveRelearnersHouse_Text_PreEvoTutorThatsAHeartScaleWantMeToTeachMove, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, FallarborTown_MoveRelearnersHouse_EventScript_PreEvoTutorComeBackWithHeartScale
	goto FallarborTown_MoveRelearnersHouse_EventScript_PreEvoTutorChooseMon
	end

FallarborTown_MoveRelearnersHouse_EventScript_PreEvoTutorChooseMon::
	msgbox FallarborTown_MoveRelearnersHouse_Text_PreEvoTutorWhichMon, MSGBOX_DEFAULT
	setflag FLAG_PRE_EVO_TUTOR
	special ChooseMonForMoveRelearner @ The list of moves is built here
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq FallarborTown_MoveRelearnersHouse_EventScript_PreEvoTutorComeBackWithHeartScale
	special IsSelectedMonEgg
	compare VAR_RESULT, TRUE
	goto_if_eq FallarborTown_MoveRelearnersHouse_EventScript_CantTeachEgg
	compare VAR_0x8005, 0
	goto_if_eq FallarborTown_MoveRelearnersHouse_EventScript_NoMoveToTeachMon
	goto FallarborTown_MoveRelearnersHouse_EventScript_PreEvoTutorChooseMove
	end

FallarborTown_MoveRelearnersHouse_EventScript_PreEvoTutorChooseMove::
	msgbox FallarborTown_MoveRelearnersHouse_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	compare VAR_0x8004, 0
	goto_if_eq FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	msgbox FallarborTown_MoveRelearnersHouse_Text_HandedOverHeartScale, MSGBOX_DEFAULT
	removeitem ITEM_HEART_SCALE
	goto FallarborTown_MoveRelearnersHouse_EventScript_PreEvoTutorComeBackWithHeartScale
	end

FallarborTown_MoveRelearnersHouse_EventScript_PreEvoTutorComeBackWithHeartScale::
	msgbox FallarborTown_MoveRelearnersHouse_Text_ComeBackWithHeartScale, MSGBOX_DEFAULT
	clearflag FLAG_PRE_EVO_TUTOR
	releaseall
	end

FallarborTown_MoveRelearnersHouse_Text_ImThePreEvoTutor:
	.string "Hiya! I'm the pre evo move tutor!\p"
	.string "I know all the moves that Pokémon\n"
	.string "can learn from their juvenile stages,\l"
	.string "and I can teach Pokémon those moves.\p"
	.string "I can teach a move to a Pokémon\n"
	.string "of yours if you want.\p"
	.string "I'll do it for you if you give me a\n"
	.string "Heart Scale.$"

FallarborTown_MoveRelearnersHouse_Text_PreEvoTutorThatsAHeartScaleWantMeToTeachMove:
	.string "Woah! You have a Heart Scale!\p"
	.string "Do you want me to teach your Pokémon\n"
	.string "a new move?$"

FallarborTown_MoveRelearnersHouse_Text_PreEvoTutorWhichMon:
	.string "Which Pokémon needs a new move?$"

FallarborTown_MoveRelearnersHouse_Text_ImTheEggTutor:
	.string "Hello, I'm the egg move tutor.\p"
	.string "I know all the moves that Pokémon\n"
	.string "can learn from birth, and I can teach\l"
	.string "Pokémon those moves.\p"
	.string "I can teach a move to a Pokémon\n"
	.string "of yours if you'd like.\p"
	.string "The payment is a Heart Scale.\n"
	.string "I'm collecting those now.$"

FallarborTown_MoveRelearnersHouse_Text_EggTutorThatsAHeartScaleWantMeToTeachMove:
	.string "I see you have brought a Heart Scale.\p"
	.string "Would you like me to teach your Pokémon\n"
	.string "an egg move?$"

FallarborTown_MoveRelearnersHouse_Text_EggTutorWhichMon:
	.string "Which Pokémon needs an egg move?$"

FallarborTown_MoveRelearnersHouse_Text_ImTheMoveTutor:
	.string "I'm the Move Tutor.\p"
	.string "I know all the moves that Pokémon\n"
	.string "learn--every one of them--and I can\l"
	.string "teach Pokémon those moves.\p"
	.string "I can teach a move to a Pokémon\n"
	.string "of yours if you'd like.\p"
	.string "I'll do it for a Heart Scale.\n"
	.string "I'm collecting those now.$"

FallarborTown_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove:
	.string "Oh! That's it! That's an honest to\n"
	.string "goodness Heart Scale!\p"
	.string "Let me guess, you want me to teach\n"
	.string "a move?$"

FallarborTown_MoveRelearnersHouse_Text_TutorWhichMon:
	.string "Which Pokémon needs tutoring?$"

FallarborTown_MoveRelearnersHouse_Text_TeachWhichMove:
	.string "Which move should I teach?$"

FallarborTown_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon:
	.string "Sorry…\p"
	.string "It doesn't appear as if I have any move\n"
	.string "I can teach that Pokémon.$"

FallarborTown_MoveRelearnersHouse_Text_HandedOverHeartScale:
	.string "{PLAYER} handed over one Heart Scale\n"
	.string "in exchange.$"

FallarborTown_MoveRelearnersHouse_Text_ComeBackWithHeartScale:
	.string "If your Pokémon need to learn a move,\n"
	.string "come back with a Heart Scale.$"

FallarborTown_MoveRelearnersHouse_Text_CantTeachEgg:
	.string "Hunh? There isn't a single move that\n"
	.string "I can teach an Egg.$"

