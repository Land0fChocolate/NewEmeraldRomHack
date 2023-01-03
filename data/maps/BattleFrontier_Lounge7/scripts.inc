BattleFrontier_Lounge7_MapScripts::
	.byte 0

BattleFrontier_Lounge7_EventScript_LeftMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_1
	goto_if_set FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor
	msgbox BattleFrontier_Lounge7_Text_LeftTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor::
	msgbox BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_E, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_D, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_GastroAcid
	case 1, BattleFrontier_Lounge7_EventScript_RolePlay
	case 2, BattleFrontier_Lounge7_EventScript_Trick
	case 3, BattleFrontier_Lounge7_EventScript_WorrySeed
	case 4, BattleFrontier_Lounge7_EventScript_Softboiled
	case 5, BattleFrontier_Lounge7_EventScript_WorkUp
	case 6, BattleFrontier_Lounge7_EventScript_Defog
	case 7, BattleFrontier_Lounge7_EventScript_Counter
	case 8, BattleFrontier_Lounge7_EventScript_MagicCoat
	case 9, BattleFrontier_Lounge7_EventScript_LowKick
	case 10, BattleFrontier_Lounge7_EventScript_SeismicToss
	case 11, BattleFrontier_Lounge7_EventScript_MegaPunch
	case 12, BattleFrontier_Lounge7_EventScript_MegaKick
	case 13, BattleFrontier_Lounge7_EventScript_BodySlam
	case 14, BattleFrontier_Lounge7_EventScript_StoredPower
	case 15, BattleFrontier_Lounge7_EventScript_SwordsDance
	case 16, BattleFrontier_Lounge7_EventScript_KnockOff
	case 17, BattleFrontier_Lounge7_EventScript_PsychicFangs
	case 18, BattleFrontier_Lounge7_EventScript_IronHead
	case 19, BattleFrontier_Lounge7_EventScript_StealthRock
	case 20, BattleFrontier_Lounge7_EventScript_SeedBomb
	case 21, BattleFrontier_Lounge7_EventScript_BlazeImpact
	case 22, BattleFrontier_Lounge7_EventScript_PlayRough
	case 23, BattleFrontier_Lounge7_EventScript_AquaTail
	case 24, BattleFrontier_Lounge7_EventScript_FoulPlay
	case 25, BattleFrontier_Lounge7_EventScript_Megahorn
	case 26, BattleFrontier_Lounge7_EventScript_Superpower
	case 27, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_E, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_D, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_GastroAcid
	case 1, BattleFrontier_Lounge7_EventScript_RolePlay
	case 2, BattleFrontier_Lounge7_EventScript_Trick
	case 3, BattleFrontier_Lounge7_EventScript_WorrySeed
	case 4, BattleFrontier_Lounge7_EventScript_Softboiled
	case 5, BattleFrontier_Lounge7_EventScript_WorkUp
	case 6, BattleFrontier_Lounge7_EventScript_Defog
	case 7, BattleFrontier_Lounge7_EventScript_Counter
	case 8, BattleFrontier_Lounge7_EventScript_MagicCoat
	case 9, BattleFrontier_Lounge7_EventScript_LowKick
	case 10, BattleFrontier_Lounge7_EventScript_SeismicToss
	case 11, BattleFrontier_Lounge7_EventScript_MegaPunch
	case 12, BattleFrontier_Lounge7_EventScript_MegaKick
	case 13, BattleFrontier_Lounge7_EventScript_BodySlam
	case 14, BattleFrontier_Lounge7_EventScript_StoredPower
	case 15, BattleFrontier_Lounge7_EventScript_SwordsDance
	case 16, BattleFrontier_Lounge7_EventScript_KnockOff
	case 17, BattleFrontier_Lounge7_EventScript_PsychicFangs
	case 18, BattleFrontier_Lounge7_EventScript_IronHead
	case 19, BattleFrontier_Lounge7_EventScript_StealthRock
	case 20, BattleFrontier_Lounge7_EventScript_SeedBomb
	case 21, BattleFrontier_Lounge7_EventScript_BlazeImpact
	case 22, BattleFrontier_Lounge7_EventScript_PlayRough
	case 23, BattleFrontier_Lounge7_EventScript_AquaTail
	case 24, BattleFrontier_Lounge7_EventScript_FoulPlay
	case 25, BattleFrontier_Lounge7_EventScript_Megahorn
	case 26, BattleFrontier_Lounge7_EventScript_Superpower
	case 27, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_GastroAcid::
	setvar VAR_0x8008, 4
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_RolePlay::
	setvar VAR_0x8008, 4
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Trick::
	setvar VAR_0x8008, 4
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_WorrySeed::
	setvar VAR_0x8008, 4
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Softboiled::
	setvar VAR_0x8008, 6
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_WorkUp::
	setvar VAR_0x8008, 6
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Defog::
	setvar VAR_0x8008, 6
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Counter::
	setvar VAR_0x8008, 6
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MagicCoat::
	setvar VAR_0x8008, 6
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_LowKick::
	setvar VAR_0x8008, 8
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SeismicToss::
	setvar VAR_0x8008, 8
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MegaPunch::
	setvar VAR_0x8008, 8
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MegaKick::
	setvar VAR_0x8008, 8
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_BodySlam::
	setvar VAR_0x8008, 12
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_StoredPower::
	setvar VAR_0x8008, 12
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SwordsDance::
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_KnockOff::
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_PsychicFangs::
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_IronHead::
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_StealthRock::
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SeedBomb::
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_BlazeImpact::
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_PlayRough::
	setvar VAR_0x8008, 20
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_AquaTail::
	setvar VAR_0x8008, 20
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_FoulPlay::
	setvar VAR_0x8008, 20
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Megahorn::
	setvar VAR_0x8008, 20
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Superpower::
	setvar VAR_0x8008, 20
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_RightMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_2
	goto_if_set FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor
	msgbox BattleFrontier_Lounge7_Text_RightTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor::
	msgbox BattleFrontier_Lounge7_Text_RightTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_E, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_D, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl
	case 1, BattleFrontier_Lounge7_EventScript_Snore
	case 2, BattleFrontier_Lounge7_EventScript_Swift
	case 3, BattleFrontier_Lounge7_EventScript_PainSplit
	case 4, BattleFrontier_Lounge7_EventScript_Recycle
	case 5, BattleFrontier_Lounge7_EventScript_IcyWind
	case 6, BattleFrontier_Lounge7_EventScript_Endure
	case 7, BattleFrontier_Lounge7_EventScript_PsychUp
	case 8, BattleFrontier_Lounge7_EventScript_DreamEater
	case 9, BattleFrontier_Lounge7_EventScript_LowSweep
	case 10, BattleFrontier_Lounge7_EventScript_BreakingSwipe
	case 11, BattleFrontier_Lounge7_EventScript_SerpentDance
	case 12, BattleFrontier_Lounge7_EventScript_Tailwind
	case 13, BattleFrontier_Lounge7_EventScript_Avalanche
	case 14, BattleFrontier_Lounge7_EventScript_HiddenThorns
	case 15, BattleFrontier_Lounge7_EventScript_IcePunch
	case 16, BattleFrontier_Lounge7_EventScript_ThunderPunch
	case 17, BattleFrontier_Lounge7_EventScript_FirePunch
	case 18, BattleFrontier_Lounge7_EventScript_FlintBlade
	case 19, BattleFrontier_Lounge7_EventScript_SignalBeam
	case 20, BattleFrontier_Lounge7_EventScript_ZenHeadbutt
	case 21, BattleFrontier_Lounge7_EventScript_HeatWave
	case 22, BattleFrontier_Lounge7_EventScript_EarthPower
	case 23, BattleFrontier_Lounge7_EventScript_BodyPress
	case 24, BattleFrontier_Lounge7_EventScript_GunkShot
	case 25, BattleFrontier_Lounge7_EventScript_NastyPlot
	case 26, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_E, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_D, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl
	case 1, BattleFrontier_Lounge7_EventScript_Snore
	case 2, BattleFrontier_Lounge7_EventScript_Swift
	case 3, BattleFrontier_Lounge7_EventScript_PainSplit
	case 4, BattleFrontier_Lounge7_EventScript_Recycle
	case 5, BattleFrontier_Lounge7_EventScript_IcyWind
	case 6, BattleFrontier_Lounge7_EventScript_Endure
	case 7, BattleFrontier_Lounge7_EventScript_PsychUp
	case 8, BattleFrontier_Lounge7_EventScript_DreamEater
	case 9, BattleFrontier_Lounge7_EventScript_LowSweep
	case 10, BattleFrontier_Lounge7_EventScript_BreakingSwipe
	case 11, BattleFrontier_Lounge7_EventScript_SerpentDance
	case 12, BattleFrontier_Lounge7_EventScript_Tailwind
	case 13, BattleFrontier_Lounge7_EventScript_Avalanche
	case 14, BattleFrontier_Lounge7_EventScript_HiddenThorns
	case 15, BattleFrontier_Lounge7_EventScript_IcePunch
	case 16, BattleFrontier_Lounge7_EventScript_ThunderPunch
	case 17, BattleFrontier_Lounge7_EventScript_FirePunch
	case 18, BattleFrontier_Lounge7_EventScript_FlintBlade
	case 19, BattleFrontier_Lounge7_EventScript_SignalBeam
	case 20, BattleFrontier_Lounge7_EventScript_ZenHeadbutt
	case 21, BattleFrontier_Lounge7_EventScript_HeatWave
	case 22, BattleFrontier_Lounge7_EventScript_EarthPower
	case 23, BattleFrontier_Lounge7_EventScript_BodyPress
	case 24, BattleFrontier_Lounge7_EventScript_GunkShot
	case 25, BattleFrontier_Lounge7_EventScript_NastyPlot
	case 26, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_DefenseCurl::
	setvar VAR_0x8008, 4
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Snore::
	setvar VAR_0x8008, 4
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Swift::
	setvar VAR_0x8008, 4
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_PainSplit::
	setvar VAR_0x8008, 6
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Recycle::
	setvar VAR_0x8008, 6
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_IcyWind::
	setvar VAR_0x8008, 8
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Endure::
	setvar VAR_0x8008, 8
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_PsychUp::
	setvar VAR_0x8008, 8
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_DreamEater::
	setvar VAR_0x8008, 8
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_LowSweep::
	setvar VAR_0x8008, 8
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_BreakingSwipe::
	setvar VAR_0x8008, 8
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SerpentDance::
	setvar VAR_0x8008, 12
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Tailwind::
	setvar VAR_0x8008, 12
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Avalanche::
	setvar VAR_0x8008, 12
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_HiddenThorns::
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_IcePunch::
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ThunderPunch::
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_FirePunch::
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_FlintBlade::
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SignalBeam::
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ZenHeadbutt::
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_HeatWave::
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_EarthPower::
	setvar VAR_0x8008, 20
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_BodyPress::
	setvar VAR_0x8008, 20
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_GunkShot::
	setvar VAR_0x8008, 20
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_NastyPlot::
	setvar VAR_0x8008, 20
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect::
	special CloseBattleFrontierTutorWindow
	special CloseBattlePointsWindow
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge7_EventScript_CancelChooseMon::
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

@ VAR_0x8008 is the price
@ VAR_TEMP_C is the scroll multichoice ID
@ VAR_TEMP_D is the move selection
@ VAR_TEMP_E is which move tutor was spoken to
BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection::
	copyvar VAR_0x8004, VAR_TEMP_D
	copyvar VAR_0x8005, VAR_TEMP_E
	special BufferBattleFrontierTutorMoveName
	buffernumberstring 1, VAR_0x8008
	copyvar VAR_0x8004, VAR_TEMP_C
	msgbox BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge7_EventScript_ChooseNewMove
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	compare VAR_TEMP_1, VAR_0x8008
	goto_if_ge BattleFrontier_Lounge7_EventScript_TeachTutorMove
	msgbox BattleFrontier_Lounge7_Text_HaventGotEnoughPoints, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseNewMove
	end

BattleFrontier_Lounge7_EventScript_TeachTutorMove::
	msgbox BattleFrontier_Lounge7_Text_TeachMoveToWhichMon, MSGBOX_DEFAULT
	special GetBattleFrontierTutorMoveIndex
	fadescreen FADE_TO_BLACK
	special CloseBattlePointsWindow
	special CloseBattleFrontierTutorWindow
	special ChooseMonForMoveTutor
	waitstate
	compare VAR_RESULT, FALSE
	goto_if_eq BattleFrontier_Lounge7_EventScript_CancelChooseMon
	msgbox BattleFrontier_Lounge7_Text_IllTakeBattlePoints, MSGBOX_DEFAULT
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	release
	end

BattleFrontier_Lounge7_EventScript_ChooseNewMove::
	compare VAR_TEMP_E, 0
	goto_if_eq BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove
	goto BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_Sailor::
	msgbox BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong, MSGBOX_NPC
	end

BattleFrontier_Lounge7_EventScript_Gentleman::
	msgbox BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful, MSGBOX_NPC
	end

BattleFrontier_Lounge7_Text_LeftTutorIntro:
	.string "Buhahaha!\p"
	.string "You couldn't tell it from looking now,\n"
	.string "but I used to be one tough Trainer.\p"
	.string "I had a reputation as the toughest\n"
	.string "Beauty around, I tell you!\p"
	.string "… … … … … …\p"
	.string "What is it now?\n"
	.string "You don't believe me.\p"
	.string "I'm not like that blowhard woman over\n"
	.string "there. I'm actually talented!\p"
	.string "Let me prove it to you.\n"
	.string "I can teach your Pokémon special and\l"
	.string "yet cute moves.\p"
	.string "But my lessons don't come free.\n"
	.string "How about paying for the moves I teach\l"
	.string "with a wee bit of Battle Points?$"

BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack:
	.string "Buhahaha!\p"
	.string "Are you back to learn special and\n"
	.string "yet cute Pokémon moves?$"

BattleFrontier_Lounge7_Text_TeachWhichMove:
	.string "Fine, fine, look here!\n"
	.string "Which move should I teach?$"

BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints:
	.string "The move {STR_VAR_1}, is it?\n"
	.string "That will be {STR_VAR_2} Battle Points, okay?$"

BattleFrontier_Lounge7_Text_TeachMoveToWhichMon:
	.string "Fine, fine, now pick the Pokémon\n"
	.string "I should teach the move to.$"

BattleFrontier_Lounge7_Text_HaventGotEnoughPoints:
	.string "What the…\n"
	.string "You haven't got enough Battle Points!$"

BattleFrontier_Lounge7_Text_IllTakeBattlePoints:
	.string "Do you see how skilled I am now?\n"
	.string "I'll take your Battle Points, thanks!$"

BattleFrontier_Lounge7_Text_YouDontWantTo:
	.string "What's that?\n"
	.string "You don't want to…\p"
	.string "If you want to see how skilled I am,\n"
	.string "you come see me anytime!$"

BattleFrontier_Lounge7_Text_RightTutorIntro:
	.string "Ihihihi!\p"
	.string "I know it's hard to see now, but I used\n"
	.string "to be one fantastic Trainer.\p"
	.string "I had a reputation as the most\n"
	.string "invincible Swimmer around, I tell you!\p"
	.string "… … … … … …\p"
	.string "What's wrong?\n"
	.string "You don't believe me.\p"
	.string "I'm not like that buffoonish woman over\n"
	.string "there. I'm actually experienced!\p"
	.string "I can prove it to you.\n"
	.string "I can teach your Pokémon hard and\l"
	.string "yet pretty moves.\p"
	.string "But my lessons don't come free.\n"
	.string "How about paying for the moves I teach\l"
	.string "with a wee bit of Battle Points?$"

BattleFrontier_Lounge7_Text_RightTutorWelcomeBack:
	.string "Ihihihi!\p"
	.string "Have you come to learn hard and\n"
	.string "yet pretty Pokémon moves?$"

BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong:
	.string "Those ladies, the way they bad-mouth\n"
	.string "each other, you probably think that\l"
	.string "they don't get along.\p"
	.string "But if that were true, they wouldn't\n"
	.string "stay out here together, would they?$"

BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful:
	.string "When I was just a wee Youngster,\n"
	.string "those ladies were strong and beautiful.\p"
	.string "They were idols among us Trainers.\p"
	.string "Even now, age hasn't dulled their\n"
	.string "abilities.\p"
	.string "In fact, their Pokémon moves have\n"
	.string "grown even more polished.\p"
	.string "But… For some reason, I can't help\n"
	.string "but feel this…\p"
	.string "Time is so cruel…$"

BattleFrontier_Lounge7_Text_GastroAcidDesc::
	.string "Eliminates the\n"
	.string "foe's abilities.$"

BattleFrontier_Lounge7_Text_RolePlayDesc::
	.string "Copies the\n"
	.string "abilities of the\n"
	.string "target.$"

BattleFrontier_Lounge7_Text_TrickDesc::
	.string "Swaps user's held\n"
	.string "item with the\n"
	.string "foe's.$"

BattleFrontier_Lounge7_Text_WorrySeedDesc::
	.string "Replaces target\n"
	.string "abilities with\n"
	.string "Insomnia.$"

BattleFrontier_Lounge7_Text_SoftboiledDesc::
	.string "Recovers up to\n"
	.string "half the user's\n"
	.string "maximum HP.$"

BattleFrontier_Lounge7_Text_WorkUpDesc::
	.string "Raises the user's\n"
	.string "Atk and Sp.Atk\n"
	.string "stats.$"

BattleFrontier_Lounge7_Text_DefogDesc::
	.string "Reduces enemy\n"
	.string "evasion and clears\n"
	.string "field hazards.$"

BattleFrontier_Lounge7_Text_MagicCoatDesc::
	.string "Retaliates any\n"
	.string "special hit with\n"
	.string "double the power.$"

BattleFrontier_Lounge7_Text_LowKickDesc::
	.string "Deals more damage\n"
	.string "the heavier\n"
	.string "the foe.$"

BattleFrontier_Lounge7_Text_SeismicTossDesc::
	.string "Inflicts damage\n"
	.string "identical to the\n"
	.string "user's level.$"

BattleFrontier_Lounge7_Text_DreamEaterDesc::
	.string "Recovers half the\n"
	.string "damage inflicted\n"
	.string "on a sleeping foe.$"

BattleFrontier_Lounge7_Text_MegaPunchDesc::
	.string "A strong punch\n"
	.string "thrown with\n"
	.string "incredible power.$"

BattleFrontier_Lounge7_Text_MegaKickDesc::
	.string "An extremely\n"
	.string "powerful kick with\n"
	.string "intense force.$"

BattleFrontier_Lounge7_Text_BodySlamDesc::
	.string "A full-body slam\n"
	.string "that may cause\n"
	.string "paralysis.$"

BattleFrontier_Lounge7_Text_CounterDesc::
	.string "Retaliates any\n"
	.string "physical hit with\n"
	.string "double the power.$"

BattleFrontier_Lounge7_Text_SwordsDanceDesc::
	.string "A fighting dance\n"
	.string "that sharply\n"
	.string "raises Attack.$"

BattleFrontier_Lounge7_Text_KnockOffDesc::
	.string "The hit knocks\n"
	.string "away the foe's\n"
	.string "held item.$"

BattleFrontier_Lounge7_Text_PsychicFangsDesc::
	.string "Destroys Light\n"
	.string "Screen and\n"
	.string "Reflect walls.$"

BattleFrontier_Lounge7_Text_IronHeadDesc::
	.string "May cause the\n"
	.string "opponent to\n"
	.string "flinch.$"

BattleFrontier_Lounge7_Text_StealthRockDesc::
	.string "Lays down a trap\n"
	.string "that damages foes\n"
	.string "on switch in.$"

BattleFrontier_Lounge7_Text_SeedBombDesc::
	.string "User barrages the\n"
	.string "foe with hard\n"
	.string "seeds.$"

BattleFrontier_Lounge7_Text_PlayRoughDesc::
	.string "May lower the\n"
	.string "Attack stat of\n"
	.string "the opponent.$"

BattleFrontier_Lounge7_Text_AquaTailDesc::
	.string "User swings its\n"
	.string "tail like a\n"
	.string "vicious wave.$"

BattleFrontier_Lounge7_Text_FoulPlayDesc::
	.string "User uses the\n"
	.string "foe's Atk stat\n"
	.string "to strike.$"

BattleFrontier_Lounge7_Text_MegahornDesc::
	.string "A powerful blow\n"
	.string "from a large horn.$"

BattleFrontier_Lounge7_Text_SuperpowerDesc::
	.string "Lowers user\n"
	.string "Atk and Def\n"
	.string "after attack.$"

BattleFrontier_Lounge7_Text_SerpentDanceDesc::
	.string "A graceful dance\n"
	.string "that raises\n"
	.string "Sp.Atk and Speed.$"

BattleFrontier_Lounge7_Text_DefenseCurlDesc::
	.string "User curls up to\n"
	.string "raise the Defense\n"
	.string "stat.$"

BattleFrontier_Lounge7_Text_SnoreDesc::
	.string "A loud attack\n"
	.string "that can be used\n"
	.string "only while asleep.$"

BattleFrontier_Lounge7_Text_SwiftDesc::
	.string "Sprays star-\n"
	.string "shaped rays\n"
	.string "that never miss.$"

BattleFrontier_Lounge7_Text_PainSplitDesc::
	.string "Shares user and\n"
	.string "foe's remaining\n"
	.string "health.$"

BattleFrontier_Lounge7_Text_RecycleDesc::
	.string "User recycles a\n"
	.string "used held item.$"

BattleFrontier_Lounge7_Text_IcyWindDesc::
	.string "A chilling attack\n"
	.string "that lowers the\n"
	.string "foe's Speed.$"

BattleFrontier_Lounge7_Text_EndureDesc::
	.string "Endures any at-\n"
	.string "tack for 1 turn,\n"
	.string "leaving 1HP.$"

BattleFrontier_Lounge7_Text_PsychUpDesc::
	.string "Copies the foe's\n"
	.string "effect(s) and\n"
	.string "gives to the user.$"

BattleFrontier_Lounge7_Text_LowSweepDesc::
	.string "Reduces the foe's\n"
	.string "Speed stat.$"

BattleFrontier_Lounge7_Text_BreakingSwipeDesc::
	.string "Reduces the foe's\n"
	.string "Attack stat.$"

BattleFrontier_Lounge7_Text_TailwindDesc::
	.string "Creates a field\n"
	.string "that boosts the\n"
	.string "team's Speed.$"

BattleFrontier_Lounge7_Text_StoredPowerDesc::
	.string "Increases power\n"
	.string "the more stat ups\n"
	.string "the user has.$"

BattleFrontier_Lounge7_Text_AvalancheDesc::
	.string "Doubles damage\n"
	.string "if user is hit\n"
	.string "on same turn.$"

BattleFrontier_Lounge7_Text_HiddenThornsDesc::
	.string "Lays down a trap\n"
	.string "that damages foes\n"
	.string "on switch in.$"

BattleFrontier_Lounge7_Text_IcePunchDesc::
	.string "An icy punch\n"
	.string "that may\n"
	.string "freeze the foe.$"

BattleFrontier_Lounge7_Text_ThunderPunchDesc::
	.string "An electrified\n"
	.string "punch that may\n"
	.string "paralyze the foe.$"

BattleFrontier_Lounge7_Text_FirePunchDesc::
	.string "A fiery punch\n"
	.string "that may burn\n"
	.string "the foe.$"

BattleFrontier_Lounge7_Text_FlintBladeDesc::
	.string "A rock-hard edge\n"
	.string "with a high\n"
	.string "critical hit rate.$"

BattleFrontier_Lounge7_Text_BlazeImpactDesc::
	.string "A harsh tackle\n"
	.string "that lowers the\n"
	.string "user's Speed.$"

BattleFrontier_Lounge7_Text_SignalBeamDesc::
	.string "May cause\n"
	.string "confusion for\n"
	.string "the foe.$"

BattleFrontier_Lounge7_Text_ZenHeadbuttDesc::
	.string "Foe is hit by a\n"
	.string "willful head.\n"
	.string "May flinch.$"

BattleFrontier_Lounge7_Text_HeatWaveDesc::
	.string "A blast of hot\n"
	.string "air that may\n"
	.string "cause burns.$"

BattleFrontier_Lounge7_Text_EarthPowerDesc::
	.string "An eruption that\n"
	.string "may lower the\n"
	.string "foe's Sp. Def.$"

BattleFrontier_Lounge7_Text_BodyPressDesc::
	.string "Uses user's\n"
	.string "Defense stat\n"
	.string "for damage.$"

BattleFrontier_Lounge7_Text_GunkShotDesc::
	.string "A chunk of filthy\n"
	.string "trash that may\n"
	.string "poison foe.$"

BattleFrontier_Lounge7_Text_NastyPlotDesc::
	.string "Wicked thoughts\n"
	.string "that sharply\n"
	.string "raises Sp.Atk.$"
