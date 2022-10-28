OriginStrand_EventScript_SelectOrigin::
	lockall
	msgbox OriginStrand_Text_OriginMovesSet, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_ORIGIN_STRAND, FALSE
	switch VAR_RESULT
	case 0, OriginStrand_EventScript_ChooseOriginSlot1
	case 1, OriginStrand_EventScript_ChooseOriginSlot2
	case 2, OriginStrand_EventScript_Exit
	goto OriginStrand_EventScript_Exit
	end

OriginStrand_EventScript_Exit::
	end

OriginStrand_EventScript_ChooseOriginSlot1::
	setvar VAR_0x8006, 0
	goto OriginStrand_EventScript_ChooseMonMoveForOrigin
	end

OriginStrand_EventScript_ChooseOriginSlot2::
	setvar VAR_0x8006, 1
	goto OriginStrand_EventScript_ChooseMonMoveForOrigin
	end

OriginStrand_EventScript_ChooseMonMoveForOrigin::
	msgbox OriginStrand_Text_WhichMonForMove, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq OriginStrand_EventScript_ChooseOriginMoveCancelled
	special IsSelectedMonEgg
	compare VAR_RESULT, TRUE
	goto_if_eq OriginStrand_EventScript_CantUseEgg
	msgbox OriginStrand_Text_WhichMoveForOrigin, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special OriginChooseMove @moveslot set to VAR_0x8005?
	fadescreen FADE_FROM_BLACK
	special BufferMoveDeleterNicknameAndMove
	msgbox OriginStrand_Text_SetThisAsOriginMove, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, OriginStrand_EventScript_TrySetOriginMove
	case NO, OriginStrand_EventScript_ChooseOriginMoveCancelled
	releaseall
	end

OriginStrand_EventScript_TrySetOriginMove::
	special SetOriginMove
	playfanfare MUS_OBTAIN_TMHM
	waitfanfare
	msgbox OriginStrand_Text_MoveHasBeenSetForOrigin, MSGBOX_DEFAULT
	releaseall
	end

OriginStrand_EventScript_CantUseEgg::
	msgbox OriginStrand_Text_CantUseEgg, MSGBOX_DEFAULT
	releaseall
	end

OriginStrand_EventScript_ChooseOriginMoveCancelled::
	releaseall
	end

OriginStrand_Text_OriginMovesSet:
	.string "{STR_VAR_1} and\n"
	.string "{STR_VAR_2} are set.\p"
	.string "Set new move?$"

OriginStrand_Text_WhichMonForMove:
	.string "Choose a Pokémon for an Origin move.$"

OriginStrand_Text_WhichMoveForOrigin:
	.string "Which move to assign to Origin?$"

OriginStrand_Text_SetThisAsOriginMove:
	.string "Assign {STR_VAR_2} to Origin?$"

OriginStrand_Text_MoveHasBeenSetForOrigin:
	.string "{STR_VAR_2} has been set for Origin.$"

OriginStrand_Text_CantUseEgg:
	.string "Egg has no moves. Cannot assign a\n"
	.string "move from an egg.$"
