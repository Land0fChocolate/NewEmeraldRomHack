Route111_OldLadysRestStop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route111_OldLadysRestStop_OnTransition
	.byte 0

Route111_OldLadysRestStop_OnTransition:
	setflag FLAG_LANDMARK_OLD_LADY_REST_SHOP
	end

Route111_OldLadysRestStop_EventScript_OldLady::
	lock
	faceplayer
	msgbox Route111_OldLadysRestStop_Text_RestUpHere, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route111_OldLadysRestStop_EventScript_Rest
	compare VAR_RESULT, NO
	goto_if_eq Route111_OldLadysRestStop_EventScript_DeclineRest
	end

Route111_OldLadysRestStop_EventScript_Rest::
	msgbox Route111_OldLadysRestStop_Text_TakeYourTimeRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox Route111_OldLadysRestStop_Text_PokemonRaringToGo, MSGBOX_DEFAULT
	release
	end

Route111_OldLadysRestStop_EventScript_DeclineRest::
	msgbox Route111_OldLadysRestStop_Text_NoRest, MSGBOX_DEFAULT
	release
	end

Route111_OldLadysRestStop_Text_RestUpHere:
	.string "Oh, dear, dear.\n"
	.string "Your Pokémon must be tired from\l"
	.string "travelling all the way to my home.\p"
	.string "If you'd like, you may rest up here.$"

Route111_OldLadysRestStop_Text_TakeYourTimeRestUp:
	.string "Please, take as long as you need.$"

Route111_OldLadysRestStop_Text_PokemonRaringToGo:
	.string "Oh, my.\n"
	.string "Your Pokémon are already raring to go!\l"
	.string "I wish you good fortune in your travels.$"

Route111_OldLadysRestStop_Text_NoRest:
	.string "Is that so?\n"
	.string "Very well, good fortune in your travels.$"

