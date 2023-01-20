.set LOCALID_TEACHER, 6
.set LOCALID_ROXANNE, 8

RustboroCity_PokemonSchool_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_PokemonSchool_OnTransition
	.byte 0

RustboroCity_PokemonSchool_OnTransition::
	goto_if_unset FLAG_BADGE04_GET, RustboroCity_PokemonSchool_Eventscript_RoxanneRematch
	setorcopyvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_ROXANNE_1
    specialvar VAR_RESULT, IsTrainerReadyForRematch
    compare VAR_RESULT, TRUE
    goto_if_eq RustboroCity_PokemonSchool_Eventscript_RoxanneRematch
    compare VAR_RESULT, FALSE
    goto_if_eq RustboroCity_PokemonSchool_Eventscript_RoxanneTrainerSchool
    end

RustboroCity_PokemonSchool_Eventscript_RoxanneRematch::
	setflag FLAG_HIDE_TRAINERS_SCHOOL_ROXANNE
	clearflag FLAG_HIDE_RUSTBORO_GYM_ROXANNE
	return

RustboroCity_PokemonSchool_Eventscript_RoxanneTrainerSchool::
	setobjectxyperm LOCALID_TEACHER, 1, 3
	setobjectmovementtype LOCALID_TEACHER, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT
	clearflag FLAG_HIDE_TRAINERS_SCHOOL_ROXANNE
	setflag FLAG_HIDE_RUSTBORO_GYM_ROXANNE
	return

RustboroCity_PokemonSchool_EventScript_Roxanne::
	lock
	faceplayer
	goto_if_set FLAG_ROXANNE_TRADE_STONES, RustboroCity_PokemonSchool_EventScript_RoxanneTrade
	msgbox RustboroCity_PokemonSchool_Text_RoxanneTradeStones, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_ROXANNE_TRADE_STONES
	release
	end

RustboroCity_PokemonSchool_EventScript_RoxanneTrade::
	checkitem ITEM_HELIX_FOSSIL, 1
	compare VAR_RESULT, TRUE
	call_if_eq RustboroCity_PokemonSchool_Eventscript_RoxanneEyeingHelixFossil
	checkitem ITEM_DOME_FOSSIL, 1
	compare VAR_RESULT, TRUE
	call_if_eq RustboroCity_PokemonSchool_Eventscript_RoxanneEyeingDomeFossil
	checkitem ITEM_OLD_AMBER, 1
	compare VAR_RESULT, TRUE
	call_if_eq RustboroCity_PokemonSchool_Eventscript_RoxanneEyeingOldAmber
	checkitem ITEM_ROOT_FOSSIL, 1
	compare VAR_RESULT, TRUE
	call_if_eq RustboroCity_PokemonSchool_Eventscript_RoxanneEyeingRootFossil
	checkitem ITEM_CLAW_FOSSIL, 1
	compare VAR_RESULT, TRUE
	call_if_eq RustboroCity_PokemonSchool_Eventscript_RoxanneEyeingClawFossil
	msgbox RustboroCity_PokemonSchool_Text_RoxanneOpenToTrade, MSGBOX_DEFAULT
	closemessage
	release
	end

RustboroCity_PokemonSchool_Eventscript_RoxanneEyeingHelixFossil::
	msgbox RustboroCity_PokemonSchool_Text_RoxanneEyeingHelixFossil, MSGBOX_YESNO
	compare VAR_RESULT, NO
    goto_if_eq Common_EventScript_NopReturn
    setvar VAR_0x8008, ITEM_HELIX_FOSSIL
    goto RustboroCity_PokemonSchool_Eventscript_RoxanneChooseStone
    return

RustboroCity_PokemonSchool_Eventscript_RoxanneEyeingDomeFossil::
	msgbox RustboroCity_PokemonSchool_Text_RoxanneEyeingDomeFossil, MSGBOX_YESNO
	compare VAR_RESULT, NO
    goto_if_eq Common_EventScript_NopReturn
    setvar VAR_0x8008, ITEM_DOME_FOSSIL
    goto RustboroCity_PokemonSchool_Eventscript_RoxanneChooseStone
    return

RustboroCity_PokemonSchool_Eventscript_RoxanneEyeingOldAmber::
	msgbox RustboroCity_PokemonSchool_Text_RoxanneEyeingOldAmber, MSGBOX_YESNO
	compare VAR_RESULT, NO
    goto_if_eq Common_EventScript_NopReturn
    setvar VAR_0x8008, ITEM_OLD_AMBER
    goto RustboroCity_PokemonSchool_Eventscript_RoxanneChooseStone
    return

RustboroCity_PokemonSchool_Eventscript_RoxanneEyeingRootFossil::
	msgbox RustboroCity_PokemonSchool_Text_RoxanneEyeingRootFossil, MSGBOX_YESNO
	compare VAR_RESULT, NO
    goto_if_eq Common_EventScript_NopReturn
    setvar VAR_0x8008, ITEM_ROOT_FOSSIL
    goto RustboroCity_PokemonSchool_Eventscript_RoxanneChooseStone
    return

RustboroCity_PokemonSchool_Eventscript_RoxanneEyeingClawFossil::
	msgbox RustboroCity_PokemonSchool_Text_RoxanneEyeingClawFossil, MSGBOX_YESNO
	compare VAR_RESULT, NO
    goto_if_eq Common_EventScript_NopReturn
    setvar VAR_0x8008, ITEM_CLAW_FOSSIL
    goto RustboroCity_PokemonSchool_Eventscript_RoxanneChooseStone
    return

RustboroCity_PokemonSchool_Eventscript_RoxanneChooseStone::
	msgbox RustboroCity_PokemonSchool_Text_RoxanneChooseStone, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_EVO_STONE, FALSE
	switch VAR_RESULT
	case 0, RustboroCity_PokemonSchool_Eventscript_PickMoonStone
	case 1, RustboroCity_PokemonSchool_Eventscript_PickSunStone
	case 2, RustboroCity_PokemonSchool_Eventscript_PickShinyStone
	case 3, RustboroCity_PokemonSchool_Eventscript_PickDuskStone
	case 4, RustboroCity_PokemonSchool_Eventscript_PickDawnStone
	case 5, RustboroCity_PokemonSchool_Eventscript_PickIceStone
	case 6, RustboroCity_PokemonSchool_Eventscript_DeclineTrade
	goto RustboroCity_PokemonSchool_Eventscript_DeclineTrade
	end

RustboroCity_PokemonSchool_Eventscript_PickMoonStone::
	setvar VAR_0x8009, ITEM_MOON_STONE
	goto RustboroCity_PokemonSchool_Eventscript_CheckTrade
	end

RustboroCity_PokemonSchool_Eventscript_PickSunStone::
	setvar VAR_0x8009, ITEM_SUN_STONE
	goto RustboroCity_PokemonSchool_Eventscript_CheckTrade
	end

RustboroCity_PokemonSchool_Eventscript_PickShinyStone::
	setvar VAR_0x8009, ITEM_SHINY_STONE
	goto RustboroCity_PokemonSchool_Eventscript_CheckTrade
	end

RustboroCity_PokemonSchool_Eventscript_PickDuskStone::
	setvar VAR_0x8009, ITEM_DUSK_STONE
	goto RustboroCity_PokemonSchool_Eventscript_CheckTrade
	end

RustboroCity_PokemonSchool_Eventscript_PickDawnStone::
	setvar VAR_0x8009, ITEM_DAWN_STONE
	goto RustboroCity_PokemonSchool_Eventscript_CheckTrade
	end

RustboroCity_PokemonSchool_Eventscript_PickIceStone::
	bufferitemname 0, VAR_0x8008
	setvar VAR_0x8009, ITEM_ICE_STONE
	bufferitemname 1, VAR_0x8009
	goto RustboroCity_PokemonSchool_Eventscript_CheckTrade
	end

RustboroCity_PokemonSchool_Eventscript_CheckTrade::
	bufferitemname 0, VAR_0x8008
	bufferitemname 1, VAR_0x8009
	msgbox RustboroCity_PokemonSchool_Text_RoxanneYoullTradeFossilForStone, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Common_EventScript_NopReturn
	checkitemspace VAR_0x8009, 1
	compare VAR_RESULT, FALSE
	goto_if_eq RustboroCity_PokemonSchool_Eventscript_BagFull
	goto RustboroCity_PokemonSchool_Eventscript_RoxanneCommenceTrade
	end

RustboroCity_PokemonSchool_Eventscript_DeclineTrade::
	msgbox RustboroCity_PokemonSchool_Text_RoxanneOpenToTrade, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_Eventscript_BagFull::
	msgbox RustboroCity_PokemonSchool_Text_BagFull, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_Eventscript_RoxanneCommenceTrade::
	msgbox RustboroCity_PokemonSchool_Text_RoxanneCommenceTrade, MSGBOX_DEFAULT
	bufferitemname 1, VAR_0x8009
	giveitem VAR_0x8009
	removeitem VAR_0x8008
	msgbox RustboroCity_PokemonSchool_Text_RoxanneComeBackForMore, MSGBOX_DEFAULT
	closemessage
	end

RustboroCity_PokemonSchool_EventScript_Blackboard::
	lockall
	msgbox RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic::
	message RustboroCity_PokemonSchool_Text_ReadWhichTopic
	waitmessage
	multichoicegrid 8, 1, MULTI_STATUS_INFO, 3, FALSE
	switch VAR_RESULT
	case 0, RustboroCity_PokemonSchool_EventScript_Poison
	case 1, RustboroCity_PokemonSchool_EventScript_Paralysis
	case 2, RustboroCity_PokemonSchool_EventScript_Sleep
	case 3, RustboroCity_PokemonSchool_EventScript_Burn
	case 4, RustboroCity_PokemonSchool_EventScript_Freeze
	case 5, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	case MULTI_B_PRESSED, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	end

RustboroCity_PokemonSchool_EventScript_Poison::
	msgbox RustboroCity_PokemonSchool_Text_ExplainPoison, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Paralysis::
	msgbox RustboroCity_PokemonSchool_Text_ExplainParalysis, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Sleep::
	msgbox RustboroCity_PokemonSchool_Text_ExplainSleep, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Burn::
	msgbox RustboroCity_PokemonSchool_Text_ExplainBurn, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Freeze::
	msgbox RustboroCity_PokemonSchool_Text_ExplainFreeze, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ExitTopicSelect::
	releaseall
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid1::
	msgbox RustboroCity_PokemonSchool_Text_TradingRightNow, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid2::
	msgbox RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_RichBoy::
	msgbox RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_Lass::
	msgbox RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_SchoolKidM::
	msgbox RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_StudentNotebook::
	msgbox RustboroCity_PokemonSchool_Text_StudentsNotes, MSGBOX_SIGN
	end

RustboroCity_PokemonSchool_EventScript_Teacher::
	lock
	faceplayer
	goto_if_unset FLAG_HIDE_TRAINERS_SCHOOL_ROXANNE, RustboroCity_PokemonSchool_EventScript_TeacherAndRoxanne
	goto_if_set FLAG_RECEIVED_QUICK_CLAW, RustboroCity_PokemonSchool_EventScript_GaveQuickClaw
	compare VAR_FACING, DIR_EAST
	call_if_eq RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast
	compare VAR_FACING, DIR_WEST
	call_if_eq RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest
	msgbox RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw, MSGBOX_DEFAULT
	giveitem ITEM_QUICK_CLAW
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	setflag FLAG_RECEIVED_QUICK_CLAW
	release
	end

RustboroCity_PokemonSchool_EventScript_TeacherAndRoxanne::
	msgbox RustboroCity_PokemonSchool_Text_RoxanneTeaching, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_GaveQuickClaw::
	msgbox RustboroCity_PokemonSchool_Text_ExplainQuickClaw, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	release
	end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest:
	walk_left
	walk_down
	walk_down
	walk_right
	walk_in_place_fastest_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_fastest_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	walk_right
	step_end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_in_place_fastest_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_fastest_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_right
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

RustboroCity_PokemonSchool_EventScript_Girl::
	msgbox RustboroCity_PokemonSchool_Text_Natures, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_Text_Natures:
	.string "Even Pokémon of the same species can\n"
	.string "have different natures.\p"
	.string "Natures affect Pokémon stats, and what\n"
	.string "foods they like to eat.$"

RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges:
	.string "The blackboard lists status changes\n"
	.string "that may affect Pokémon in battle.$"

RustboroCity_PokemonSchool_Text_ReadWhichTopic:
	.string "Which topic do you want to read?$"

RustboroCity_PokemonSchool_Text_ExplainPoison:
	.string "If a Pokémon is poisoned, it will\n"
	.string "steadily lose HP.\p"
	.string "The effects of poison remain after\n"
	.string "a battle.\p"
	.string "A poisoned Pokémon's HP will drop\n"
	.string "while it is traveling.\p"
	.string "Heal a poisoning using an antidote.$"

RustboroCity_PokemonSchool_Text_ExplainParalysis:
	.string "If a Pokémon becomes paralyzed,\n"
	.string "its Speed halves.\p"
	.string "It may also not be able to move while\n"
	.string "it is in battle.\p"
	.string "Paralysis remains after battle.\n"
	.string "Cure it using a Parlyz Heal.$"

RustboroCity_PokemonSchool_Text_ExplainSleep:
	.string "If a Pokémon falls asleep, it will be\n"
	.string "unable to attack.\p"
	.string "A Pokémon may wake up on its own,\n"
	.string "but if a battle ends while it is\l"
	.string "sleeping, it will stay asleep.\p"
	.string "Wake it up using an Awakening.$"

RustboroCity_PokemonSchool_Text_ExplainBurn:
	.string "A burn reduces Attack power, and it\n"
	.string "steadily reduces the victim's HP.\p"
	.string "A burn lingers after battle.\n"
	.string "Cure a burn using a Burn Heal.$"

RustboroCity_PokemonSchool_Text_ExplainFreeze:
	.string "If a Pokémon is frozen, it becomes\n"
	.string "completely helpless.\p"
	.string "It will remain frozen after battle.\n"
	.string "Thaw it out using an Ice Heal.$"

RustboroCity_PokemonSchool_Text_RoxanneTeaching:
	.string "It doesn't feel all that long ago when\n"
	.string "I was teaching Roxanne.\p"
	.string "Now, she is the one teaching.\n"
	.string "It makes me swell with pride!$"

RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw:
	.string "Students who don't study get a little\n"
	.string "taste of my Quick Claw.\p"
	.string "Whether or not you are a good student \n"
	.string "will be evident from the way you use\l"
	.string "this item.$"

RustboroCity_PokemonSchool_Text_ExplainQuickClaw:
	.string "A Pokémon holding the Quick Claw will\n"
	.string "slightly speed up if it has taken\l"
	.string "significant damage.\p"
	.string "There are many other items that are\n"
	.string "meant to be held by Pokémon.\p"
	.string "Just those alone will give you many\n"
	.string "topics to study!$"

RustboroCity_PokemonSchool_Text_TradingRightNow:
	.string "Did you know that when a Pokémon uses\n"
	.string "a move the same type as itself, that\l"
	.string "move does much more damage?$"

RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot:
	.string "Electric type Pokémon don't get\n"
	.string "paralyzed, and Fire type Pokémon don't\l"
	.string "get burned.\p"
	.string "There's more to types than just type\n"
	.string "matchups.$"

RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems:
	.string "Pokémon can hold items, but they\n"
	.string "don't know what to do with man-made\l"
	.string "items like potions and antidotes.$"

RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself:
	.string "You know how some Pokémon moves can\n"
	.string "confuse a Pokémon?\p"
	.string "A confused Pokémon will sometimes\n"
	.string "attack itself without meaning to.\p"
	.string "But once it leaves battle, it will\n"
	.string "return to normal.$"

RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry:
	.string "A Pokémon holding a berry will heal\n"
	.string "itself…\p"
	.string "There are many kinds of items that\n"
	.string "Pokémon can hold…\p"
	.string "Boy, it sure is hard taking notes\n"
	.string "down…$"

RustboroCity_PokemonSchool_Text_StudentsNotes:
	.string "It's this student's notebook…\p"
	.string "Pokémon are to be caught using\n"
	.string "Poké Balls.\p"
	.string "Up to six Pokémon can accompany\n"
	.string "a Trainer.\p"
	.string "A Trainer is someone who catches\n"
	.string "Pokémon, raises them, and battles\l"
	.string "with them.\p"
	.string "A Trainer's mission is to defeat\n"
	.string "the strong Trainers who await\l"
	.string "challengers in Pokémon Gyms.$"

RustboroCity_PokemonSchool_Text_RoxanneTradeStones:
	.string "Roxanne: Hello, {PLAYER}.\n"
	.string "Have you also come here to teach?\p"
	.string "Or perhaps you would be more interested\n"
	.string "in my collection of rare stones?\p"
	.string "These rare stones I've found can be used\n"
	.string "to evolve certain species of Pokémon.\p"
	.string "I could offer them to you, in return for\n"
	.string "other earthly treasures…\p"
	.string "I have always been a fan of Pokémon\n"
	.string "fossils, but I have had terrible luck\l"
	.string "trying to find any!\p"
	.string "I am willing to trade any of my stones\n"
	.string "for any of your fossils.\p"
	.string "I will be at the school if I am not\n"
	.string "battling!$"

RustboroCity_PokemonSchool_Text_RoxanneOpenToTrade:
	.string "Roxanne: If you have any fossils, you\n"
	.string "are welcome to trade one for one of my\l"
	.string "evolution stones.$"

RustboroCity_PokemonSchool_Text_RoxanneEyeingHelixFossil:
	.string "Roxanne: That swirl…\n"
	.string "That is unmistakably a Helix Fossil!\p"
	.string "Would you be willing to trade it for an\n"
	.string "evolution stone?$"

RustboroCity_PokemonSchool_Text_RoxanneEyeingDomeFossil:
	.string "Roxanne: You have a Dome Fossil with\n"
	.string "you, do you not?\p"
	.string "Would you be willing to trade it for an\n"
	.string "evolution stone?$"

RustboroCity_PokemonSchool_Text_RoxanneEyeingOldAmber:
	.string "Roxanne: What a lovely color!\n"
	.string "I must have that piece of Old Amber!\p"
	.string "Would you be willing to trade it for an\n"
	.string "evolution stone?$"

RustboroCity_PokemonSchool_Text_RoxanneEyeingRootFossil:
	.string "Roxanne: I like the look of that Root\n"
	.string "Fossil you have with you.\p"
	.string "Would you be willing to trade it for an\n"
	.string "evolution stone?$"

RustboroCity_PokemonSchool_Text_RoxanneEyeingClawFossil:
	.string "Roxanne: That is a well preserved Claw\n"
	.string "Fossil you have with you!\p"
	.string "Would you be willing to trade it for an\n"
	.string "evolution stone?$"

RustboroCity_PokemonSchool_Text_RoxanneChooseStone:
	.string "Roxanne: Which of my stones would you\n"
	.string "like to trade it for?$"

RustboroCity_PokemonSchool_Text_RoxanneYoullTradeFossilForStone:
	.string "Roxanne: You'll trade your\n"
	.string "{STR_VAR_1} for my {STR_VAR_2}, then?$"

RustboroCity_PokemonSchool_Text_BagFull:
	.string "Roxanne: Oh dear, it appears that your\n"
	.string "bag is full. Come back later!$"

RustboroCity_PokemonSchool_Text_RoxanneCommenceTrade:
	.string "Roxanne: All right, here you go!$"

RustboroCity_PokemonSchool_Text_RoxanneComeBackForMore:
	.string "Roxanne: I'm always up for trading if\n"
	.string "you get any more fossils!$"
