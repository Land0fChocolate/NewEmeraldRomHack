LilycoveCity_ContestHall_Smart_MapScripts::
	.byte 0

LilycoveCity_ContestHall_Smart_EventScript_SmartStageSign::
	msgbox LilycoveCity_ContestHall_Smart_Text_SmartContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_Smart_EventScript_SmartContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Smart_Text_GiveItBestSmartAppeal, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_Smart_EventScript_SmartContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Smart_Text_AreYouEnjoyingThisContest, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_Smart_EventScript_SmartContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Smart_Text_EnteredWrongContest, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_Smart_EventScript_SmartContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Smart_Text_RaisedMonToBeSmart, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_Smart_EventScript_SmartContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Smart_Text_IfMonPullsSmartMoveNext, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_Smart_EventScript_SmartContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Smart_Text_DontAppreciateCuteLeechLife, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_Smart_EventScript_SmartContestAudience1::
	msgbox LilycoveCity_ContestHall_Smart_Text_YoureBeautifulGrandpa, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_Smart_EventScript_SmartContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Smart_Text_AllSeemToUseDifferentMoves, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_Smart_EventScript_SmartContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Smart_Text_PokemonSmarterThanTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_Smart_EventScript_SmartContestAudience4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Smart_Text_StillLoveSmartnessContests, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_Smart_EventScript_Boy1::
	msgbox LilycoveCity_ContestHall_Smart_Text_TodayWonSmartnessContest, MSGBOX_NPC
	end

LilycoveCity_ContestHall_Smart_Text_SmartContestStage:
	.string "SMARTNESS CONTEST STAGE\n"
	.string "BE IMPRESSED BY SMART POKéMON!$"

LilycoveCity_ContestHall_Smart_Text_GiveItBestSmartAppeal:
	.string "MC: Okay, Smart Pokémon and their\n"
	.string "Trainers, are you ready?!\p"
	.string "Give it your best showing!\n"
	.string "Let's appeal!$"

LilycoveCity_ContestHall_Smart_Text_AreYouEnjoyingThisContest:
	.string "Judge: Are you enjoying this Contest?\p"
	.string "Come back with three friends, and\n"
	.string "all of you may enter a Contest!$"

LilycoveCity_ContestHall_Smart_Text_EnteredWrongContest:
	.string "Ayayayay…\n"
	.string "I entered the wrong Contest.\p"
	.string "I entered this tough Pokémon in\n"
	.string "the Smartness Contest…\p"
	.string "Come on, wow them with a smart-looking\n"
	.string "Rock Smash.$"

LilycoveCity_ContestHall_Smart_Text_RaisedMonToBeSmart:
	.string "I've spent many a year, and all my\n"
	.string "wisdom besides, raising this Pokémon\l"
	.string "to be smart.\p"
	.string "It won't be easily bested by some\n"
	.string "young pup's Pokémon.\p"
	.string "My dear wife, are you seeing this?$"

LilycoveCity_ContestHall_Smart_Text_IfMonPullsSmartMoveNext:
	.string "There it is!\p"
	.string "If my Pokémon pulls a smart move next,\n"
	.string "the audience's excitement will peak!$"

LilycoveCity_ContestHall_Smart_Text_DontAppreciateCuteLeechLife:
	.string "Oh, dear, no!\p"
	.string "My darling Zubat's Leech Life is so\n"
	.string "cute I kept using it over and over!\p"
	.string "But these mean people don't appreciate\n"
	.string "it at all!$"

LilycoveCity_ContestHall_Smart_Text_YoureBeautifulGrandpa:
	.string "Kiyaaah! You're beautiful, Grandpa!$"

LilycoveCity_ContestHall_Smart_Text_AllSeemToUseDifferentMoves:
	.string "Even when Trainers enter the same\n"
	.string "kind of Pokémon, they all seem to use\l"
	.string "different moves for appeals.\p"
	.string "It's just like the way people have\n"
	.string "different styles for battling.$"

LilycoveCity_ContestHall_Smart_Text_PokemonSmarterThanTrainers:
	.string "I think the Pokémon look smarter\n"
	.string "than their Trainers. By a lot.$"

LilycoveCity_ContestHall_Smart_Text_StillLoveSmartnessContests:
	.string "When all's said and done, I still love\n"
	.string "Smartness Contests.\p"
	.string "That intellectual green color…\n"
	.string "It's so… So… Cool.$"

LilycoveCity_ContestHall_Smart_Text_TodayWonSmartnessContest:
	.string "This Pokémon won the Beauty Contest\n"
	.string "here before.\p"
	.string "Well, guess what? Today, I made it\n"
	.string "win a Smartness Contest!\p"
	.string "My abilities scare even me…$"
