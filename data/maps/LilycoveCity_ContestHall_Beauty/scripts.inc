LilycoveCity_ContestHall_Beauty_MapScripts::
	.byte 0

LilycoveCity_ContestHall_Beauty_EventScript_BeautyStageSign::
	msgbox LilycoveCity_ContestHall_Beauty_Text_BeautyContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_Beauty_EventScript_BeautyContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Beauty_Text_AreYouEnteringBeautyContest, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_Beauty_EventScript_BeautyContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Beauty_Text_EveryPokemonPristineBeauty, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_Beauty_EventScript_BeautyContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Beauty_Text_EyesWillBeGluedToMyBeauty, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_Beauty_EventScript_BeautyContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Beauty_Text_OverdidGrooming, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_Beauty_EventScript_BeautyContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Beauty_Text_JudgeWontSeeAuroraBeam, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_Beauty_EventScript_BeautyContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Beauty_Text_PokemonLooksLikeYoungerMe, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_Beauty_EventScript_BeautyContestAudience1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Beauty_Text_WinBeautyContestMakesMeHappy, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_Beauty_EventScript_BeautyContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Beauty_Text_GanderAtAllThosePrettyPokemon, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_Beauty_EventScript_BeautyContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Beauty_Text_CantWinOnBeautyAlone, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_Beauty_EventScript_Glacia::
	locktarget
	faceplayer
	msgbox LilycoveCity_ContestHall_Beauty_Text_Glacia, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_Beauty_Text_BeautyContestStage:
	.string "BEAUTY CONTEST STAGE\n"
	.string "BE ALLURED BY BEAUTIFUL POKéMON!$"

LilycoveCity_ContestHall_Beauty_Text_AreYouEnteringBeautyContest:
	.string "MC: Are you entering the Beauty\n"
	.string "Contest, too? Good luck!$"

LilycoveCity_ContestHall_Beauty_Text_EveryPokemonPristineBeauty:
	.string "Judge: Ah, every Pokémon here is\n"
	.string "a model of pristine beauty!\p"
	.string "Why, I almost forgot to score them!$"

LilycoveCity_ContestHall_Beauty_Text_EyesWillBeGluedToMyBeauty:
	.string "A Pokémon this beautiful…\n"
	.string "There isn't another one like it.\p"
	.string "Everyone's eyes will be glued to\n"
	.string "my beauty.$"

LilycoveCity_ContestHall_Beauty_Text_OverdidGrooming:
	.string "Waaaah!\p"
	.string "I brushed and groomed my Pokémon\n"
	.string "carefully for this Contest…\p"
	.string "But I overdid it…\n"
	.string "My Pokémon's coat turned all scraggly…\p"
	.string "What should I do?$"

LilycoveCity_ContestHall_Beauty_Text_JudgeWontSeeAuroraBeam:
	.string "This Aurora Beam is so dazzling,\n"
	.string "the Judge won't be able to see it.\p"
	.string "Uh, wait a second…\n"
	.string "That'll be meaningless, then!$"

LilycoveCity_ContestHall_Beauty_Text_PokemonLooksLikeYoungerMe:
	.string "This pretty Pokémon looks just like\n"
	.string "me when I was younger.\p"
	.string "Right when I said that, my husband\n"
	.string "spewed the coffee he was drinking.\p"
	.string "Did I say something funny?$"

LilycoveCity_ContestHall_Beauty_Text_WinBeautyContestMakesMeHappy:
	.string "You know, if I win at a Beauty\n"
	.string "Contest, sure it makes me\l"
	.string "happy. More than usual, anyway.$"

LilycoveCity_ContestHall_Beauty_Text_GanderAtAllThosePrettyPokemon:
	.string "Wahahahah!\p"
	.string "Will you take a gander at all those\n"
	.string "pretty Pokémon!\l"
	.string "I just love this sort of glitz!$"

LilycoveCity_ContestHall_Beauty_Text_CantWinOnBeautyAlone:
	.string "You can't always win on just beauty\n"
	.string "alone.\p"
	.string "You have to groom your Pokémon so\n"
	.string "it's nice and glossy like mine.$"

LilycoveCity_ContestHall_Beauty_Text_Glacia:
	.string "A kaleidoscope of polished moves…\p"
	.string "Synchronized collaboration between\n"
	.string "Trainer and Pokémon.\p"
	.string "Their souls like burning hot flames…\p"
	.string "Watching a Pokémon contest is as\n"
	.string "enjoyable as watching a Pokémon battle.\p"
	.string "I wonder if I could participate in\n"
	.string "contests without jeopardizing my\l"
	.string "training for battles?$"
