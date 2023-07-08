.set LOCALID_HEX_MANIAC, 1

LilycoveCity_House5_MapScripts::
	.byte 0

LilycoveCity_House5_EventScript_HexManiac::
	lockall
	applymovement LOCALID_HEX_MANIAC, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_set FLAG_TEMP_5, LilycoveCity_House5_EventScript_TalkedToAlready
	setflag FLAG_TEMP_5
	msgbox LilycoveCity_House5_Text_IMakeBrews, MSGBOX_DEFAULT
	goto LilycoveCity_House5_EventScript_TalkedToAlready
	end

LilycoveCity_House5_EventScript_TalkedToAlready::
	msgbox LilycoveCity_House5_Text_UseBrew, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, LilycoveCity_House5_EventScript_DontUseCursedStatue
	goto LilycoveCity_House5_EventScript_ChooseMonForStatue
	end

LilycoveCity_House5_EventScript_DontUseCursedStatue::
	msgbox LilycoveCity_House5_Text_DontUseBrew, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_House5_EventScript_ChooseMonForStatue::
	msgbox LilycoveCity_House5_Text_ChooseWhichMon, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq LilycoveCity_House5_EventScript_DontUseCursedStatue
	special IsSelectedMonEgg
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_House5_EventScript_CantUseEgg
	multichoice 0, 0, MULTI_STAT_EV_TRAIN, FALSE
	switch VAR_RESULT
	case 0, LilycoveCity_House5_Eventscript_IVNerfHP
	case 1, LilycoveCity_House5_Eventscript_IVNerfAttack
	case 2, LilycoveCity_House5_Eventscript_IVNerfDefense
	case 3, LilycoveCity_House5_Eventscript_IVNerfSpecialAttack
	case 4, LilycoveCity_House5_Eventscript_IVNerfSpecialDefense
	case 5, LilycoveCity_House5_Eventscript_IVNerfSpeed
	case 6, LilycoveCity_House5_EventScript_DontUseCursedStatue
	goto LilycoveCity_House5_EventScript_DontUseCursedStatue
LilycoveCity_House5_Eventscript_NerfStat::
	special BufferMonNickname
	special NerfMonIV
	msgbox LilycoveCity_House5_Text_PokemonConsumesBrew, MSGBOX_DEFAULT
	closemessage
	release
	end

LilycoveCity_House5_EventScript_CantUseEgg::
	msgbox LilycoveCity_House5_Text_EggUnaffected, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_House5_Eventscript_IVNerfHP::
	setvar VAR_0x8005, 0
	goto LilycoveCity_House5_Eventscript_CheckMonIV

LilycoveCity_House5_Eventscript_IVNerfAttack::
	setvar VAR_0x8005, 1
	goto LilycoveCity_House5_Eventscript_CheckMonIV

LilycoveCity_House5_Eventscript_IVNerfDefense::
	setvar VAR_0x8005, 2
	goto LilycoveCity_House5_Eventscript_CheckMonIV

LilycoveCity_House5_Eventscript_IVNerfSpecialAttack::
	setvar VAR_0x8005, 3
	goto LilycoveCity_House5_Eventscript_CheckMonIV

LilycoveCity_House5_Eventscript_IVNerfSpecialDefense::
	setvar VAR_0x8005, 4
	goto LilycoveCity_House5_Eventscript_CheckMonIV

LilycoveCity_House5_Eventscript_IVNerfSpeed::
	setvar VAR_0x8005, 5
	goto LilycoveCity_House5_Eventscript_CheckMonIV

LilycoveCity_House5_Eventscript_CheckMonIV::
	special CheckForMinMonIV
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_House5_EventScript_CantDecreaseStat
	goto LilycoveCity_House5_Eventscript_NerfStat

LilycoveCity_House5_EventScript_CantDecreaseStat::
	msgbox LilycoveCity_House5_Text_StatCantBeDecreased, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_House5_Text_IMakeBrews:
	.string "Kekeke…\p"
	.string "Were your Pokémon attracted to the smell\n"
	.string "of my brew?\p"
	.string "They will find it delicious…\n"
	.string "They all do.\p"
	.string "But consuming it comes at a terrible\n"
	.string "price.\p"
	.string "One of their Individual Values will go\n"
	.string "down.$"

LilycoveCity_House5_Text_UseBrew:
	.string "It's up to you to treat your Pokémon\n"
	.string "at the cost of their strength.\p"
	.string "Will you do it?$"

LilycoveCity_House5_Text_DontUseBrew:
	.string "Kekeke… a wise choice!$"

LilycoveCity_House5_Text_ChooseWhichMon:
	.string "Tempted to spoil your Pokémon?\n"
	.string "Which one do you choose?$"

LilycoveCity_House5_Text_EggUnaffected:
	.string "What do you expect me to do with\n"
	.string "this egg? I have nothing for it.$"

LilycoveCity_House5_Text_StatCantBeDecreased:
	.string "This Pokémon's stat can't be\n"
	.string "decreased.$"

LilycoveCity_House5_Text_PokemonConsumesBrew:
	.string "{STR_VAR_1} loves the brew!\p"
	.string "{STR_VAR_1} loses an IV point!$"
