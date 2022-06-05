FieryPath_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FieryPath_OnTransition
	.byte 0

FieryPath_OnTransition:
	setflag FLAG_LANDMARK_FIERY_PATH
	end

FieryPath_EventScript_Devan::
	trainerbattle_single TRAINER_DEVAN, FieryPath_Text_DevanIntro, FieryPath_Text_DevanDefeat
	msgbox FieryPath_Text_DevanPostBattle, MSGBOX_AUTOCLOSE
	end

FieryPath_EventScript_Dayton::
	trainerbattle_single TRAINER_DAYTON, FieryPath_Text_DaytonIntro, FieryPath_Text_DaytonDefeat
	msgbox FieryPath_Text_DaytonPostBattle, MSGBOX_AUTOCLOSE
	end

FieryPath_EventScript_Aisha::
	trainerbattle_single TRAINER_AISHA, FieryPath_Text_AishaIntro, FieryPath_Text_AishaDefeat
	msgbox FieryPath_Text_AishaPostBattle, MSGBOX_AUTOCLOSE
	end

FieryPath_EventScript_Bryant::
	trainerbattle_single TRAINER_BRYANT, FieryPath_Text_BryantIntro, FieryPath_Text_BryantDefeat
	msgbox FieryPath_Text_BryantPostBattle, MSGBOX_AUTOCLOSE
	end

FieryPath_EventScript_Shayla::
	trainerbattle_single TRAINER_SHAYLA, FieryPath_Text_ShaylaIntro, FieryPath_Text_ShaylaDefeat
	msgbox FieryPath_Text_ShaylaPostBattle, MSGBOX_AUTOCLOSE
	end
