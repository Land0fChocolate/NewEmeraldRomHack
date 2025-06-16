LilycoveCity_ContestHall_Cute_MapScripts::
	.byte 0

LilycoveCity_ContestHall_Cute_EventScript_CuteStageSign::
	msgbox LilycoveCity_ContestHall_Cute_Text_CuteContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_Cute_EventScript_CuteContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Cute_Text_InTheMiddleOfContest, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_Cute_EventScript_CuteContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Cute_Text_SuchCharmingCuteAppeals, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_Cute_EventScript_CuteContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Cute_Text_MyAzurillWasDistracted, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_Cute_EventScript_CuteContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Cute_Text_NeverWonBattleButContest, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_Cute_EventScript_CuteContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Cute_Text_PetalDanceIsMarvel, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_Cute_EventScript_CuteContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Cute_Text_MyMonAppealSoMuchCuter, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_Cute_EventScript_CuteContestAudience1::
	lockall
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_ContestHall_Cute_Text_MyChildIsInContest, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 25
	msgbox LilycoveCity_ContestHall_Cute_Text_ComeOnDear, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_ContestHall_Cute_EventScript_CuteContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Cute_Text_WantCuteMonOfMyOwn, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_Cute_EventScript_CuteContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Cute_Text_ThatGirlThereIsCutest, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_Cute_EventScript_FairyTaleGirl::
	msgbox LilycoveCity_ContestHall_Cute_Text_FairyTaleGirl, MSGBOX_NPC
	end

LilycoveCity_ContestHall_Cute_Text_CuteContestStage:
	.string "CUTENESS CONTEST STAGE\n"
	.string "BE CHARMED BY CUTE POKéMON!$"

LilycoveCity_ContestHall_Cute_Text_InTheMiddleOfContest:
	.string "MC: Uh-oh! Hello!\n"
	.string "We're in the middle of a Contest!\p"
	.string "Please enter at our registration\n"
	.string "counter and come out, okay?$"

LilycoveCity_ContestHall_Cute_Text_SuchCharmingCuteAppeals:
	.string "Judge: Oh, such charming and cute\n"
	.string "appeals!\p"
	.string "Oh, my goodness! What a perfectly\n"
	.string "adorable Water Sport appeal!$"

LilycoveCity_ContestHall_Cute_Text_MyAzurillWasDistracted:
	.string "Oh, no… My sweet Azurill was\n"
	.string "distracted by another Pokémon.$"

LilycoveCity_ContestHall_Cute_Text_NeverWonBattleButContest:
	.string "My Pokémon has never won in a battle,\n"
	.string "but put it in a Contest and look out!$"

LilycoveCity_ContestHall_Cute_Text_PetalDanceIsMarvel:
	.string "My Pokémon's Petal Dance is a marvel\n"
	.string "of elegance.\p"
	.string "I won't let anyone disturb its\n"
	.string "performance.$"

LilycoveCity_ContestHall_Cute_Text_MyMonAppealSoMuchCuter:
	.string "Everyone's Pokémon are very cute.\p"
	.string "However, if my Pokémon were to make\n"
	.string "a cute appeal…\p"
	.string "I'm sure that it would be so much \n"
	.string "cuter than the others.$"

LilycoveCity_ContestHall_Cute_Text_MyChildIsInContest:
	.string "My child is in this Contest.$"

LilycoveCity_ContestHall_Cute_Text_ComeOnDear:
	.string "Come on, dear. Go for it!\n"
	.string "Your Pokémon is the best!$"

LilycoveCity_ContestHall_Cute_Text_ThatGirlThereIsCutest:
	.string "I think that girl over there is\n"
	.string "the cutest of the lot.\p"
	.string "What's that? They're judging\n"
	.string "Pokémon by their looks?$"

LilycoveCity_ContestHall_Cute_Text_WantCuteMonOfMyOwn:
	.string "Ohh, seeing all these cute Pokémon,\n"
	.string "they make we want to get my own!\p"
	.string "I'm going to go catch some!$"

LilycoveCity_ContestHall_Cute_Text_FairyTaleGirl:
	.string "I don't know what the rules are in\n"
	.string "contests. I just like seeing all\l"
	.string "the gorgeous Pokémon.$"
