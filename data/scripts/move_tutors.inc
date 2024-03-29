MoveTutor_EventScript_OpenPartyMenu::
	special ChooseMonForMoveTutor
	waitstate
	lock
	faceplayer
	return

SlateportCity_PokemonFanClub_EventScript_SwaggerTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_SwaggerTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_SwaggerDeclined
	msgbox MoveTutor_Text_SwaggerWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_SWAGGER
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq MoveTutor_EventScript_SwaggerDeclined
	msgbox MoveTutor_Text_SwaggerTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_SwaggerDeclined::
	msgbox MoveTutor_Text_SwaggerDeclined, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_RolloutTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_RolloutTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_RolloutDeclined
	msgbox MoveTutor_Text_RolloutWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_ROLLOUT
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq MoveTutor_EventScript_RolloutDeclined
	msgbox MoveTutor_Text_RolloutTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_RolloutDeclined::
	msgbox MoveTutor_Text_RolloutDeclined, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_FuryCutterTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_FuryCutterTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_FuryCutterDeclined
	msgbox MoveTutor_Text_FuryCutterWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_FURY_CUTTER
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq MoveTutor_EventScript_FuryCutterDeclined
	msgbox MoveTutor_Text_FuryCutterTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_FuryCutterDeclined::
	msgbox MoveTutor_Text_FuryCutterDeclined, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_House_EventScript_MimicTutor::
	lock
	faceplayer
	msgbox MoveTutor_MimicTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_MimicDeclined
	msgbox MoveTutor_Text_MimicWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_MIMIC
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq MoveTutor_EventScript_MimicDeclined
	msgbox MoveTutor_Text_MimicTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_MimicDeclined::
	msgbox MoveTutor_MimicDeclined, MSGBOX_DEFAULT
	release
	end

FallarborTown_Mart_EventScript_MetronomeTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_MetronomeTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_MetronomeDeclined
	msgbox MoveTutor_Text_MetronomeWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_METRONOME
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq MoveTutor_EventScript_MetronomeDeclined
	msgbox MoveTutor_Text_MetronomeTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_MetronomeDeclined::
	msgbox MoveTutor_Text_MetronomeDeclined, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_SleepTalkTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_SleepTalkTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_SleepTalkDeclined
	msgbox MoveTutor_Text_SleepTalkWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_SLEEP_TALK
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq MoveTutor_EventScript_SleepTalkDeclined
	msgbox MoveTutor_Text_SleepTalkTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_SleepTalkDeclined::
	msgbox MoveTutor_Text_SleepTalkDeclined, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_SubstituteTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_SubstituteTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_SubstituteDeclined
	msgbox MoveTutor_Text_SubstituteWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_SUBSTITUTE
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq MoveTutor_EventScript_SubstituteDeclined
	msgbox MoveTutor_Text_SubstituteTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_SubstituteDeclined::
	msgbox MoveTutor_Text_SubstituteDeclined, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_DynamicPunchTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_DynamicPunchTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_DynamicPunchDeclined
	msgbox MoveTutor_Text_DynamicPunchWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_DYNAMIC_PUNCH
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq MoveTutor_EventScript_DynamicPunchDeclined
	msgbox MoveTutor_Text_DynamicPunchTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_DynamicPunchDeclined::
	msgbox MoveTutor_Text_DynamicPunchDeclined, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_DoubleEdgeTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_DoubleEdgeTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_DoubleEdgeDeclined
	msgbox MoveTutor_Text_DoubleEdgeWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_DOUBLE_EDGE
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq MoveTutor_EventScript_DoubleEdgeDeclined
	msgbox MoveTutor_Text_DoubleEdgeTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_DoubleEdgeDeclined::
	msgbox MoveTutor_Text_DoubleEdgeDeclined, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_PokemonCenter_1F_EventScript_ExplosionTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_ExplosionTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_ExplosionDeclined
	msgbox MoveTutor_Text_ExplosionWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_EXPLOSION
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq MoveTutor_EventScript_ExplosionDeclined
	msgbox MoveTutor_Text_ExplosionTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_ExplosionDeclined::
	msgbox MoveTutor_Text_ExplosionDeclined, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_EventScript_DracoMeteorTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_DracoMeteorTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_DracoMeteorDeclined
	msgbox MoveTutor_Text_DracoMeteorWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_DRACO_METEOR
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq MoveTutor_EventScript_DracoMeteorDeclined
	msgbox MoveTutor_Text_DracoMeteorTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_DracoMeteorDeclined::
	msgbox MoveTutor_Text_DracoMeteorDeclined, MSGBOX_DEFAULT
	release
	end
