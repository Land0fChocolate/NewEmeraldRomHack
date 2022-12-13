.set LOCALID_COOK, 1

RustboroCity_House4_MapScripts::
	.byte 0

RustboroCity_House4_EventScript_Cook::
	lockall
	applymovement LOCALID_COOK, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_set FLAG_TEMP_5, RustboroCity_House4_EventScript_CheckBottleCap
	msgbox RustboroCity_House4_Text_ImTheBottleCapChef, MSGBOX_DEFAULT
	setflag FLAG_TEMP_5
	goto RustboroCity_House4_EventScript_CheckBottleCap
	end

RustboroCity_House4_EventScript_CheckBottleCap::
	checkitem ITEM_BOTTLE_CAP, 1
	compare VAR_RESULT, FALSE
	goto_if_eq RustboroCity_House4_EventScript_CheckGoldBottleCapNoBottleCap
	goto RustboroCity_House4_EventScript_CheckGoldBottleCapHasBottleCap

RustboroCity_House4_EventScript_CheckGoldBottleCapNoBottleCap::
	checkitem ITEM_GOLD_BOTTLE_CAP, 1
	compare VAR_RESULT, FALSE
	goto_if_eq RustboroCity_House4_EventScript_ComeBackWithBottleCap
	setvar VAR_0x8006, 0
	goto RustboroCity_House4_EventScript_AskUseGoldBottleCapToBuff

RustboroCity_House4_EventScript_AskUseGoldBottleCapToBuff::
	msgbox RustboroCity_House4_Text_ThatsAGoldBottleCapWouldYouLikeMaxBuff, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, RustboroCity_House4_EventScript_ComeBackWithBottleCap
	goto RustboroCity_House4_EventScript_ChooseMonGoldBottleCap
	end

RustboroCity_House4_EventScript_CheckGoldBottleCapHasBottleCap::
	checkitem ITEM_GOLD_BOTTLE_CAP, 1
	compare VAR_RESULT, FALSE
	goto_if_eq RustboroCity_House4_EventScript_AskUseBottleCapToBuff
	goto RustboroCity_House4_EventScript_ChooseWhichBottleCap

RustboroCity_House4_EventScript_AskUseBottleCapToBuff::
	msgbox RustboroCity_House4_Text_ThatsABottleCapWouldYouLikeBuff, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, RustboroCity_House4_EventScript_ComeBackWithBottleCap
	goto RustboroCity_House4_EventScript_ChooseMon
	end

RustboroCity_House4_EventScript_ChooseWhichBottleCap::
	msgbox RustboroCity_House4_Text_ChooseWhichBottleCap, MSGBOX_YESNO
	compare VAR_RESULT, TRUE
	goto_if_eq RustboroCity_House4_EventScript_UsingGoldBottleCap
	msgbox RustboroCity_House4_Text_UsingBottleCap, MSGBOX_DEFAULT
	goto RustboroCity_House4_EventScript_ChooseMon

RustboroCity_House4_EventScript_UsingGoldBottleCap::
	msgbox RustboroCity_House4_Text_UsingGoldBottleCap, MSGBOX_DEFAULT
	goto RustboroCity_House4_EventScript_ChooseMonGoldBottleCap

RustboroCity_House4_EventScript_ChooseMon::
	msgbox RustboroCity_House4_Text_ChooseWhichMon, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq RustboroCity_House4_EventScript_ComeBackWithBottleCap
	special IsSelectedMonEgg
	compare VAR_RESULT, TRUE
	goto_if_eq RustboroCity_House4_EventScript_CantBuffEgg
	multichoice 0, 0, MULTI_STAT_EV_TRAIN, FALSE
	switch VAR_RESULT
	case 0, RustboroCity_House4_Eventscript_IVBuffHP
	case 1, RustboroCity_House4_Eventscript_IVBuffAttack
	case 2, RustboroCity_House4_Eventscript_IVBuffDefense
	case 3, RustboroCity_House4_Eventscript_IVBuffSpecialAttack
	case 4, RustboroCity_House4_Eventscript_IVBuffSpecialDefense
	case 5, RustboroCity_House4_Eventscript_IVBuffSpeed
	case 6, RustboroCity_House4_EventScript_ComeBackWithBottleCap
	goto RustboroCity_House4_EventScript_ComeBackWithBottleCap
RustboroCity_House4_Eventscript_BuffStat::
	msgbox RustboroCity_House4_Text_TimeToBuff, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_LEVEL_UP
	waitfanfare
	special BuffMonIV
	removeitem ITEM_BOTTLE_CAP
	fadescreen FADE_FROM_BLACK
	msgbox RustboroCity_House4_Text_ComeBackWithBottleCap, MSGBOX_DEFAULT
	closemessage
	release
	end

RustboroCity_House4_Eventscript_IVBuffHP::
	setvar VAR_0x8005, 0
	goto RustboroCity_House4_Eventscript_CheckMonIV

RustboroCity_House4_Eventscript_IVBuffAttack::
	setvar VAR_0x8005, 1
	goto RustboroCity_House4_Eventscript_CheckMonIV

RustboroCity_House4_Eventscript_IVBuffDefense::
	setvar VAR_0x8005, 2
	goto RustboroCity_House4_Eventscript_CheckMonIV

RustboroCity_House4_Eventscript_IVBuffSpeed::
	setvar VAR_0x8005, 3
	goto RustboroCity_House4_Eventscript_CheckMonIV

RustboroCity_House4_Eventscript_IVBuffSpecialAttack::
	setvar VAR_0x8005, 4
	goto RustboroCity_House4_Eventscript_CheckMonIV

RustboroCity_House4_Eventscript_IVBuffSpecialDefense::
	setvar VAR_0x8005, 5
	goto RustboroCity_House4_Eventscript_CheckMonIV

RustboroCity_House4_Eventscript_CheckMonIV::
	special CheckForMaxMonIV
	compare VAR_RESULT, TRUE
	goto_if_eq RustboroCity_House4_EventScript_CantIncreaseStat
	goto RustboroCity_House4_Eventscript_BuffStat

RustboroCity_House4_EventScript_ChooseMonGoldBottleCap::
	msgbox RustboroCity_House4_Text_ChooseWhichMon, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq RustboroCity_House4_EventScript_ComeBackWithBottleCap
	special IsSelectedMonEgg
	compare VAR_RESULT, TRUE
	goto_if_eq RustboroCity_House4_EventScript_CantBuffEggGoldBottleCap
	special CheckForMaxMonIVs
	compare VAR_RESULT, TRUE
	goto_if_eq RustboroCity_House4_EventScript_CantIncreaseAllStats
	msgbox RustboroCity_House4_Text_TimeToBuff, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_LEVEL_UP
	waitfanfare
	special MaximizeMonIVs
	removeitem ITEM_GOLD_BOTTLE_CAP
	fadescreen FADE_FROM_BLACK
	msgbox RustboroCity_House4_Text_ComeBackWithBottleCap, MSGBOX_DEFAULT
	closemessage
	release
	end

RustboroCity_House4_EventScript_CantIncreaseStat::
	msgbox RustboroCity_House4_Text_CantIncreaseStat, MSGBOX_DEFAULT
	goto RustboroCity_House4_EventScript_ChooseMon
	end

RustboroCity_House4_EventScript_CantIncreaseAllStats::
	msgbox RustboroCity_House4_Text_CantIncreaseAllStats, MSGBOX_DEFAULT
	goto RustboroCity_House4_EventScript_ChooseMonGoldBottleCap
	end

RustboroCity_House4_EventScript_CantBuffEgg::
	msgbox RustboroCity_House4_Text_CantBuffEgg, MSGBOX_DEFAULT
	goto RustboroCity_House4_EventScript_ChooseMon
	end

RustboroCity_House4_EventScript_CantBuffEggGoldBottleCap::
	msgbox RustboroCity_House4_Text_CantBuffEgg, MSGBOX_DEFAULT
	goto RustboroCity_House4_EventScript_ChooseMonGoldBottleCap
	end

RustboroCity_House4_EventScript_ComeBackWithBottleCap::
	msgbox RustboroCity_House4_Text_ComeBackWithBottleCap, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_House4_Text_Debug:
	.string "Var 8004 is {STR_VAR_1}$"

RustboroCity_House4_Text_ImTheBottleCapChef:
	.string "They call me the Bottle Cap Chef.\p"
	.string "Folks from all around come to me for\n"
	.string "my incredible delicacies to buff up\l"
	.string "their Pokémon's Individual Values.\p"
	.string "I can buff up a Pokémon of yours if you\n"
	.string "have a bottle cap.$"

RustboroCity_House4_Text_ThatsABottleCapWouldYouLikeBuff:
	.string "Oh! I see you have brought a bottle cap\n"
	.string "with you.\p"
	.string "Would you like me to buff up one of\n"
	.string "your Pokémon's IVs?$"

RustboroCity_House4_Text_ThatsAGoldBottleCapWouldYouLikeMaxBuff:
	.string "Oh my! I see you have brought a gold\n"
	.string "bottle cap with you.\p"
	.string "Would you like me to buff up all your\n"
	.string "Pokémon's IVs to max?$"

RustboroCity_House4_Text_ChooseWhichBottleCap:
	.string "Oh my! You have brought both ordinary\n"
	.string "and gold bottle caps with you.\p"
	.string "Will you use the gold bottle cap?$"

RustboroCity_House4_Text_UsingBottleCap:
	.string "Then I shall take the ordinary\n"
	.string "bottle cap.$"

RustboroCity_House4_Text_UsingGoldBottleCap:
	.string "Then I shall take the gold bottle cap.$"

RustboroCity_House4_Text_ChooseWhichMon:
	.string "Which Pokémon will be fed?$"

RustboroCity_House4_Text_WhichStatToBuff:
	.string "Which stat should I increase?$"

RustboroCity_House4_Text_CantIncreaseStat:
	.string "Hmm…\p"
	.string "It doesn't appear as I can buff this\n"
	.string "Pokémon's IV in that stat any more.$"

RustboroCity_House4_Text_CantIncreaseAllStats:
	.string "Hmm…\p"
	.string "This Pokémon is buffed to max in all\n"
	.string "IVs. I can't buff it any more.$"

RustboroCity_House4_Text_HandedOverBottleCap:
	.string "{PLAYER} handed over one Bottle Cap\n"
	.string "in exchange.$"

RustboroCity_House4_Text_TimeToBuff:
	.string "Alright! Watch as my secret recipe\n"
	.string "takes affect!$"

RustboroCity_House4_Text_ComeBackWithBottleCap:
	.string "If your Pokémon need an IV buff,\n"
	.string "come back with a Bottle Cap.$"

RustboroCity_House4_Text_CantBuffEgg:
	.string "I can't buff up an egg.\n"
	.string "You need to hatch it first.$"
