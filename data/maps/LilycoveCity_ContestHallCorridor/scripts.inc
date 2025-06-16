LilycoveCity_ContestHallCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_ContestHallCorridor_OnTransition
	.byte 0

LilycoveCity_ContestHallCorridor_OnTransition:
	call LilycoveCity_ContestHallCorridor_SetUpWallace
	end

LilycoveCity_ContestHallCorridor_SetUpWallace::
	goto_if_unset FLAG_SYS_GAME_CLEAR, LilycoveCity_ContestHallCorridor_Eventscript_WallaceRematch
	setorcopyvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_WALLACE_1
    specialvar VAR_RESULT, IsTrainerReadyForRematch
    compare VAR_RESULT, TRUE
    goto_if_eq LilycoveCity_ContestHallCorridor_Eventscript_WallaceRematch
    compare VAR_RESULT, FALSE
    goto_if_eq LilycoveCity_ContestHallCorridor_Eventscript_WallaceAtContestHall
    return

LilycoveCity_ContestHallCorridor_Eventscript_WallaceRematch::
	setflag FLAG_HIDE_CONTEST_HALL_WALLACE
	clearflag FLAG_HIDE_SOOTOPOLIS_GYM_WALLACE
	return

LilycoveCity_ContestHallCorridor_Eventscript_WallaceAtContestHall::
	clearflag FLAG_HIDE_CONTEST_HALL_WALLACE
	setflag FLAG_HIDE_SOOTOPOLIS_GYM_WALLACE
	return

LilycoveCity_ContestHallCorridor_EventScript_Sailor::
	msgbox LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous, MSGBOX_NPC
	end

LilycoveCity_ContestHallCorridor_EventScript_Delinquent::
	msgbox LilycoveCity_ContestHall_Text_Delinquent, MSGBOX_NPC
	end

LilycoveCity_ContestHallCorridor_EventScript_Wallace::
	locktarget
	faceplayer
	msgbox LilycoveCity_ContestHallCorridor_Text_Wallace, MSGBOX_DEFAULT
	closemessage
	end

LilycoveCity_ContestHallCorridor_EventScript_WallaceFan1::
	locktarget
	msgbox LilycoveCity_ContestHallCorridor_Text_WallaceFan1, MSGBOX_DEFAULT
	closemessage
	release
	end

LilycoveCity_ContestHallCorridor_EventScript_WallaceFan2::
	locktarget
	msgbox LilycoveCity_ContestHallCorridor_Text_WallaceFan2, MSGBOX_DEFAULT
	closemessage
	release
	end

LilycoveCity_ContestHallCorridor_EventScript_WallaceFan3::
	locktarget
	msgbox LilycoveCity_ContestHallCorridor_Text_WallaceFan3, MSGBOX_DEFAULT
	closemessage
	release
	end

LilycoveCity_ContestHallCorridor_EventScript_Woman::
	msgbox LilycoveCity_ContestHallCorridor_Text_Woman, MSGBOX_NPC
	end

LilycoveCity_ContestHallCorridor_Text_IsntThisPlaceHumongous:
	.string "Whoa, isn't this place humongous!\p"
	.string "The tension in the air… It's got\n"
	.string "a different vibe to the gyms.$"

LilycoveCity_ContestHallCorridor_Text_Delinquent:
	.string "One day, I'm going to be up on the\n"
	.string "stage and be a contest superstar.\p"
	.string "Until then, I'll need to grow lots of\n"
	.string "berries for {POKEBLOCK}s.\p"
	.string "The berry master's wife kindly helped\n"
	.string "me out when I told her I was going to\l"
	.string "“Challenge Contest”.$"

LilycoveCity_ContestHallCorridor_Text_Wallace:
	.string "Wallace: No matter whether you stand in\n"
	.string "a Pokémon Gym or a Contest Hall, a\l"
	.string "Trainer who holds to his/her belief in\l"
	.string "the Pokémon beside him/her…\p"
	.string "The Pokémon that battles on, believing\n"
	.string "in the Trainer with whom it stands\l"
	.string "together…\p" 
	.string "The settings may differ, but their\n"
	.string "labors come to fruition in a way that\l"
	.string "honors their bond!\l"
	.string "There is equal beauty in both!$"

LilycoveCity_ContestHallCorridor_Text_WallaceFan1:
	.string "Eek! It's Wallace!\n"
	.string "Wallace! Wallace!\p"
	.string "Are you here to enter the contests?$"

LilycoveCity_ContestHallCorridor_Text_WallaceFan2:
	.string "Darling! Do you need anyone to show\n"
	.string "you around? It's no bother to me at all.$"

LilycoveCity_ContestHallCorridor_Text_WallaceFan3:
	.string "Mr. Wallace! I'm your biggest fan!\n"
	.string "Could you sign my Pikachu?$"

LilycoveCity_ContestHallCorridor_Text_Woman::
	.string "See!\n"
	.string "My Pokémon won all these ribbons!\p"
	.string "Have your Pokémon earned any ribbons?\n"
	.string "You can check them on your Pokénav.$"
