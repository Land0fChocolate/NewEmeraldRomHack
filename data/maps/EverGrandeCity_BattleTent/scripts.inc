EverGrandeCity_BattleTent_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_BattleTent_OnLoad
	.byte 0

EverGrandeCity_BattleTent_OnLoad:
	dotimebasedevents
	goto_if_unset FLAG_DAILY_BATTLE_TENT_TRAINERS, EverGrandeCity_BattleTent_EventScript_SetUpTrainers
	end

EverGrandeCity_BattleTent_EventScript_SetUpTrainers::
	setflag FLAG_HIDE_BATTLE_TENT_BEAUTY
	setflag FLAG_HIDE_BATTLE_TENT_BLACK_BELT
	setflag FLAG_HIDE_BATTLE_TENT_BUG_CATCHER
	setflag FLAG_HIDE_BATTLE_TENT_DELINQUENT
	setflag FLAG_HIDE_BATTLE_TENT_EXPERT_F
	setflag FLAG_HIDE_BATTLE_TENT_FAIRY_TALE_GIRL
	setflag FLAG_HIDE_BATTLE_TENT_HIKER
	setflag FLAG_HIDE_BATTLE_TENT_HEX_MANIAC
	setflag FLAG_HIDE_BATTLE_TENT_GUITARIST
	setflag FLAG_HIDE_BATTLE_TENT_MANIAC
	setflag FLAG_HIDE_BATTLE_TENT_COOLTRAINER_M
	setflag FLAG_HIDE_BATTLE_TENT_NINJA_BOY
	setflag FLAG_HIDE_BATTLE_TENT_RANGER_F
	setflag FLAG_HIDE_BATTLE_TENT_RANGER_M
	setflag FLAG_HIDE_BATTLE_TENT_PSYCHIC_F
	setflag FLAG_HIDE_BATTLE_TENT_TRIATHLETE_M
	setflag FLAG_HIDE_BATTLE_TENT_STREET_THUG
	setflag FLAG_HIDE_BATTLE_TENT_LADY
	setflag FLAG_HIDE_BATTLE_TENT_COOLTRAINER_F
	setflag FLAG_HIDE_BATTLE_TENT_RICH_BOY
	setflag FLAG_HIDE_BATTLE_TENT_TRIATHLETE_F
	setflag FLAG_DAILY_BATTLE_TENT_TRAINERS
	call EverGrandeCity_BattleTent_EventScript_SetUpATrainer
	call EverGrandeCity_BattleTent_EventScript_SetUpATrainer
	call EverGrandeCity_BattleTent_EventScript_SetUpATrainer
	call EverGrandeCity_BattleTent_EventScript_SetUpATrainer
	call EverGrandeCity_BattleTent_EventScript_SetUpATrainer
	call EverGrandeCity_BattleTent_EventScript_SetUpATrainer
	call EverGrandeCity_BattleTent_EventScript_SetUpATrainer
	end

EverGrandeCity_BattleTent_EventScript_SetUpATrainer::
	random 21
	copyvar VAR_0x800A, VAR_RESULT
	switch VAR_RESULT
	case 0, EverGrandeCity_BattleTent_EventScript_SetUpBeauty
	case 1, EverGrandeCity_BattleTent_EventScript_SetUpBlackbelt
	case 2, EverGrandeCity_BattleTent_EventScript_SetUpBugCatcher
	case 3, EverGrandeCity_BattleTent_EventScript_SetUpDelinquent
	case 4, EverGrandeCity_BattleTent_EventScript_SetUpExpertF
	case 5, EverGrandeCity_BattleTent_EventScript_SetUpFairyTaleGirl
	case 6, EverGrandeCity_BattleTent_EventScript_SetUpHiker
	case 7, EverGrandeCity_BattleTent_EventScript_SetUpHexManiac
	case 8, EverGrandeCity_BattleTent_EventScript_SetUpManiac
	case 9, EverGrandeCity_BattleTent_EventScript_SetUpGuitarist
	case 10, EverGrandeCity_BattleTent_EventScript_SetUpCoolTrainerM
	case 11, EverGrandeCity_BattleTent_EventScript_SetUpNinjaBoy
	case 12, EverGrandeCity_BattleTent_EventScript_SetUpPokemonRangerF
	case 13, EverGrandeCity_BattleTent_EventScript_SetUpPokemonRangerM
	case 14, EverGrandeCity_BattleTent_EventScript_SetUpPsychicF
	case 15, EverGrandeCity_BattleTent_EventScript_SetUpTriathleteM
	case 16, EverGrandeCity_BattleTent_EventScript_SetUpStreetThug
	case 17, EverGrandeCity_BattleTent_EventScript_SetUpLady
	case 18, EverGrandeCity_BattleTent_EventScript_SetUpCoolTrainerF
	case 19, EverGrandeCity_BattleTent_EventScript_SetUpRichBoy
	case 20, EverGrandeCity_BattleTent_EventScript_SetUpTriathleteF
	return

EverGrandeCity_BattleTent_EventScript_SetUpBeauty::
	clearflag FLAG_HIDE_BATTLE_TENT_BEAUTY
	cleartrainerflag TRAINER_ALYSSA
	return

EverGrandeCity_BattleTent_EventScript_SetUpBlackbelt::
	clearflag FLAG_HIDE_BATTLE_TENT_BLACK_BELT
	cleartrainerflag TRAINER_TYRON
	return

EverGrandeCity_BattleTent_EventScript_SetUpBugCatcher::
	clearflag FLAG_HIDE_BATTLE_TENT_BUG_CATCHER
	cleartrainerflag TRAINER_DEANDRE
	return

EverGrandeCity_BattleTent_EventScript_SetUpDelinquent::
	clearflag FLAG_HIDE_BATTLE_TENT_DELINQUENT
	cleartrainerflag TRAINER_MELINA
	return

EverGrandeCity_BattleTent_EventScript_SetUpExpertF::
	clearflag FLAG_HIDE_BATTLE_TENT_EXPERT_F
	cleartrainerflag TRAINER_PAT
	return

EverGrandeCity_BattleTent_EventScript_SetUpFairyTaleGirl::
	clearflag FLAG_HIDE_BATTLE_TENT_FAIRY_TALE_GIRL
	cleartrainerflag TRAINER_CAROLINA
	return

EverGrandeCity_BattleTent_EventScript_SetUpHiker::
	clearflag FLAG_HIDE_BATTLE_TENT_HIKER
	cleartrainerflag TRAINER_PETE
	return

EverGrandeCity_BattleTent_EventScript_SetUpHexManiac::
	clearflag FLAG_HIDE_BATTLE_TENT_HEX_MANIAC
	cleartrainerflag TRAINER_SOPHIE
	return

EverGrandeCity_BattleTent_EventScript_SetUpManiac::
	clearflag FLAG_HIDE_BATTLE_TENT_MANIAC
	cleartrainerflag TRAINER_CLARENCE
	return

EverGrandeCity_BattleTent_EventScript_SetUpGuitarist::
	clearflag FLAG_HIDE_BATTLE_TENT_GUITARIST
	cleartrainerflag TRAINER_COBY
	return

EverGrandeCity_BattleTent_EventScript_SetUpCoolTrainerM::
	clearflag FLAG_HIDE_BATTLE_TENT_COOLTRAINER_M
	cleartrainerflag TRAINER_JOSEPH
	return

EverGrandeCity_BattleTent_EventScript_SetUpNinjaBoy::
	clearflag FLAG_HIDE_BATTLE_TENT_NINJA_BOY
	cleartrainerflag TRAINER_JAIDEN
	return

EverGrandeCity_BattleTent_EventScript_SetUpPokemonRangerF::
	clearflag FLAG_HIDE_BATTLE_TENT_RANGER_F
	cleartrainerflag TRAINER_KARA
	return

EverGrandeCity_BattleTent_EventScript_SetUpPokemonRangerM::
	clearflag FLAG_HIDE_BATTLE_TENT_RANGER_M
	cleartrainerflag TRAINER_DAVIS
	return

EverGrandeCity_BattleTent_EventScript_SetUpPsychicF::
	clearflag FLAG_HIDE_BATTLE_TENT_PSYCHIC_F
	cleartrainerflag TRAINER_ISABELLE
	return

EverGrandeCity_BattleTent_EventScript_SetUpTriathleteM::
	clearflag FLAG_HIDE_BATTLE_TENT_TRIATHLETE_M
	cleartrainerflag TRAINER_MYLES
	return

EverGrandeCity_BattleTent_EventScript_SetUpStreetThug::
	clearflag FLAG_HIDE_BATTLE_TENT_STREET_THUG
	cleartrainerflag TRAINER_KEVIN
	return

EverGrandeCity_BattleTent_EventScript_SetUpLady::
	clearflag FLAG_HIDE_BATTLE_TENT_LADY
	cleartrainerflag TRAINER_BETH
	return

EverGrandeCity_BattleTent_EventScript_SetUpCoolTrainerF::
	clearflag FLAG_HIDE_BATTLE_TENT_COOLTRAINER_F
	cleartrainerflag TRAINER_JAZMYN
	return

EverGrandeCity_BattleTent_EventScript_SetUpRichBoy::
	clearflag FLAG_HIDE_BATTLE_TENT_RICH_BOY
	cleartrainerflag TRAINER_ANDRES
	return

EverGrandeCity_BattleTent_EventScript_SetUpTriathleteF::
	clearflag FLAG_HIDE_BATTLE_TENT_TRIATHLETE_F
	cleartrainerflag TRAINER_BRANDI
	return

EverGrandeCity_BattleTent_EventScript_Teala::
	msgbox EverGrandeCity_BattleTent_Text_Teala, MSGBOX_NPC
	end

EverGrandeCity_BattleTent_EventScript_Beauty::
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq EverGrandeCity_BattleTent_EventScript_BeautyPlayerMale
	goto EverGrandeCity_BattleTent_EventScript_BeautyPlayerFemale
	end

EverGrandeCity_BattleTent_EventScript_BeautyPlayerMale::
	trainerbattle_single TRAINER_ALYSSA, EverGrandeCity_BattleTent_Text_AlyssaIntroMalePlayer, EverGrandeCity_BattleTent_Text_AlyssaDefeated
	msgbox EverGrandeCity_BattleTent_Text_AlyssaPostBattle, MSGBOX_AUTOCLOSE
	end

EverGrandeCity_BattleTent_EventScript_BeautyPlayerFemale::
	trainerbattle_single TRAINER_ALYSSA, EverGrandeCity_BattleTent_Text_AlyssaIntroFemalePlayer, EverGrandeCity_BattleTent_Text_AlyssaDefeated
	msgbox EverGrandeCity_BattleTent_Text_AlyssaPostBattle, MSGBOX_AUTOCLOSE
	end

EverGrandeCity_BattleTent_EventScript_BlackBelt::
	trainerbattle_single TRAINER_TYRON, EverGrandeCity_BattleTent_Text_TyronIntro, EverGrandeCity_BattleTent_Text_TyronDefeated
	msgbox EverGrandeCity_BattleTent_Text_TyronPostBattle, MSGBOX_AUTOCLOSE
	end

EverGrandeCity_BattleTent_EventScript_BugCatcher::
	trainerbattle_single TRAINER_DEANDRE, EverGrandeCity_BattleTent_Text_DeandreIntro, EverGrandeCity_BattleTent_Text_DeandreDefeated
	msgbox EverGrandeCity_BattleTent_Text_DeandrePostBattle, MSGBOX_AUTOCLOSE
	end

EverGrandeCity_BattleTent_EventScript_Delinquent::
	trainerbattle_single TRAINER_MELINA, EverGrandeCity_BattleTent_Text_MelinaIntro, EverGrandeCity_BattleTent_Text_MelinaDefeated
	msgbox EverGrandeCity_BattleTent_Text_MelinaPostBattle, MSGBOX_AUTOCLOSE
	end

EverGrandeCity_BattleTent_EventScript_ExpertF::
	trainerbattle_single TRAINER_PAT, EverGrandeCity_BattleTent_Text_PatIntro, EverGrandeCity_BattleTent_Text_PatDefeated
	msgbox EverGrandeCity_BattleTent_Text_PatPostBattle, MSGBOX_AUTOCLOSE
	end

EverGrandeCity_BattleTent_EventScript_FairyTaleGirl::
	trainerbattle_single TRAINER_CAROLINA, EverGrandeCity_BattleTent_Text_CarolinaIntro, EverGrandeCity_BattleTent_Text_CarolinaDefeated
	msgbox EverGrandeCity_BattleTent_Text_CarolinaPostBattle, MSGBOX_AUTOCLOSE
	end

EverGrandeCity_BattleTent_EventScript_Hiker::
	trainerbattle_single TRAINER_PETE, EverGrandeCity_BattleTent_Text_PeteIntro, EverGrandeCity_BattleTent_Text_PeteDefeated
	msgbox EverGrandeCity_BattleTent_Text_PetePostBattle, MSGBOX_AUTOCLOSE
	end

EverGrandeCity_BattleTent_EventScript_HexManiac::
	trainerbattle_single TRAINER_SOPHIE, EverGrandeCity_BattleTent_Text_SophieIntro, EverGrandeCity_BattleTent_Text_SophieDefeated
	msgbox EverGrandeCity_BattleTent_Text_SophiePostBattle, MSGBOX_AUTOCLOSE
	end

EverGrandeCity_BattleTent_EventScript_Guitarist::
	trainerbattle_single TRAINER_COBY, EverGrandeCity_BattleTent_Text_CobyIntro, EverGrandeCity_BattleTent_Text_CobyDefeated
	msgbox EverGrandeCity_BattleTent_Text_CobyPostBattle, MSGBOX_AUTOCLOSE
	end

EverGrandeCity_BattleTent_EventScript_Maniac::
	trainerbattle_single TRAINER_CLARENCE, EverGrandeCity_BattleTent_Text_ClarenceIntro, EverGrandeCity_BattleTent_Text_ClarenceDefeated
	msgbox EverGrandeCity_BattleTent_Text_ClarencePostBattle, MSGBOX_AUTOCLOSE
	end

EverGrandeCity_BattleTent_EventScript_CoolTrainerM::
	trainerbattle_single TRAINER_JOSEPH, EverGrandeCity_BattleTent_Text_JosephIntro, EverGrandeCity_BattleTent_Text_JosephDefeated
	msgbox EverGrandeCity_BattleTent_Text_JosephPostBattle, MSGBOX_AUTOCLOSE
	end

EverGrandeCity_BattleTent_EventScript_NinjaBoy::
	trainerbattle_single TRAINER_JAIDEN, EverGrandeCity_BattleTent_Text_JaidenIntro, EverGrandeCity_BattleTent_Text_JaidenDefeated
	msgbox EverGrandeCity_BattleTent_Text_JaidenPostBattle, MSGBOX_AUTOCLOSE
	end

EverGrandeCity_BattleTent_EventScript_RangerF::
	trainerbattle_single TRAINER_KARA, EverGrandeCity_BattleTent_Text_KaraIntro, EverGrandeCity_BattleTent_Text_KaraDefeated
	msgbox EverGrandeCity_BattleTent_Text_KaraPostBattle, MSGBOX_AUTOCLOSE
	end

EverGrandeCity_BattleTent_EventScript_RangerM::
	trainerbattle_single TRAINER_DAVIS, EverGrandeCity_BattleTent_Text_DavisIntro, EverGrandeCity_BattleTent_Text_DavisDefeated
	msgbox EverGrandeCity_BattleTent_Text_DavisPostBattle, MSGBOX_AUTOCLOSE
	end

EverGrandeCity_BattleTent_EventScript_PsychicF::
	trainerbattle_single TRAINER_ISABELLE, EverGrandeCity_BattleTent_Text_IsabelleIntro, EverGrandeCity_BattleTent_Text_IsabelleDefeated
	msgbox EverGrandeCity_BattleTent_Text_IsabellePostBattle, MSGBOX_AUTOCLOSE
	end

EverGrandeCity_BattleTent_EventScript_TriathleteM::
	trainerbattle_single TRAINER_MYLES, EverGrandeCity_BattleTent_Text_MylesIntro, EverGrandeCity_BattleTent_Text_MylesDefeated
	msgbox EverGrandeCity_BattleTent_Text_MylesPostBattle, MSGBOX_AUTOCLOSE
	end

EverGrandeCity_BattleTent_EventScript_StreetThug::
	trainerbattle_single TRAINER_KEVIN, EverGrandeCity_BattleTent_Text_KevinIntro, EverGrandeCity_BattleTent_Text_KevinDefeated
	msgbox EverGrandeCity_BattleTent_Text_KevinPostBattle, MSGBOX_AUTOCLOSE
	end

EverGrandeCity_BattleTent_EventScript_Lady::
	trainerbattle_single TRAINER_BETH, EverGrandeCity_BattleTent_Text_BethIntro, EverGrandeCity_BattleTent_Text_BethDefeated
	msgbox EverGrandeCity_BattleTent_Text_BethPostBattle, MSGBOX_AUTOCLOSE
	end

EverGrandeCity_BattleTent_EventScript_CoolTrainerF::
	trainerbattle_single TRAINER_JAZMYN, EverGrandeCity_BattleTent_Text_JazmynIntro, EverGrandeCity_BattleTent_Text_JazmynDefeated
	msgbox EverGrandeCity_BattleTent_Text_JazmynPostBattle, MSGBOX_AUTOCLOSE
	end

EverGrandeCity_BattleTent_EventScript_RichBoy::
	trainerbattle_single TRAINER_ANDRES, EverGrandeCity_BattleTent_Text_AndresIntro, EverGrandeCity_BattleTent_Text_AndresDefeated
	msgbox EverGrandeCity_BattleTent_Text_AndresPostBattle, MSGBOX_AUTOCLOSE
	end

EverGrandeCity_BattleTent_EventScript_TriathleteF::
	trainerbattle_single TRAINER_BRANDI, EverGrandeCity_BattleTent_Text_BrandiIntro, EverGrandeCity_BattleTent_Text_BrandiDefeated
	msgbox EverGrandeCity_BattleTent_Text_BrandiPostBattle, MSGBOX_AUTOCLOSE
	end

EverGrandeCity_BattleTent_Text_Teala:
	.string "Hello, and welcome to the Battle Tent.\p"
	.string "Here trainers may come here to battle\n"
	.string "with other trainers.\p"
	.string "New trainers come in every day. You may\n"
	.string "check in daily for new battles.$"
