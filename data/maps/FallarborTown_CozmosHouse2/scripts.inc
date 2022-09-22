FallarborTown_CozmosHouse2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_CozmosHouse2_OnTransition
	.byte 0

FallarborTown_CozmosHouse2_OnTransition:
	call_if_set FLAG_RETURNED_METEORITE_TO_COZMO, FallarborTown_CozmosHouse2_EventScript_PlaceMeteorite
	end

FallarborTown_CozmosHouse2_EventScript_PlaceMeteorite:
	setmetatile 5, 2, METATILE_GenericBuilding_WoodenFloor_Meteorite, 1
	return

FallarborTown_CozmosHouse2_EventScript_ProfCozmo::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_METEORITE_TO_COZMO, FallarborTown_CozmosHouse2_EventScript_GaveMeteorite
	checkitem ITEM_METEORITE, 1
	compare VAR_RESULT, TRUE
	goto_if_eq FallarborTown_CozmosHouse2_EventScript_PlayerHasMeteorite
	msgbox FallarborTown_CozmosHouse2_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse2_EventScript_PlayerHasMeteorite::
	call_if_unset FLAG_TEMP_2, FallarborTown_CozmosHouse2_EventScript_NoticeMeteorite
	call_if_set FLAG_TEMP_2, FallarborTown_CozmosHouse2_EventScript_AskForMeteorite
	compare VAR_RESULT, NO
	goto_if_eq FallarborTown_CozmosHouse2_EventScript_DeclineGiveMeteorite
	msgbox FallarborTown_CozmosHouse2_Text_PleaseUseThisTM, MSGBOX_DEFAULT
	giveitem ITEM_TM82
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setvar VAR_0x8004, ITEM_METEORITE
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_RETURNED_METEORITE_TO_COZMO
	clearflag FLAG_HIDE_COZMOS_HOUSE_METEORITE
	msgbox FallarborTown_CozmosHouse2_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse2_EventScript_NoticeMeteorite::
	msgbox FallarborTown_CozmosHouse2_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	msgbox FallarborTown_CozmosHouse2_Text_IsThatMeteoriteMayIHaveIt, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse2_EventScript_AskForMeteorite::
	msgbox FallarborTown_CozmosHouse2_Text_MayIHaveMeteorite, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse2_EventScript_DeclineGiveMeteorite::
	setflag FLAG_TEMP_2
	msgbox FallarborTown_CozmosHouse2_Text_CrushedWithDisappointment, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse2_EventScript_GaveMeteorite::
	msgbox FallarborTown_CozmosHouse2_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse2_EventScript_CozmosWife::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_METEORITE_TO_COZMO, FallarborTown_CozmosHouse2_EventScript_CozmoIsHappy
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_CozmosHouse2_EventScript_CozmoIsSad
	msgbox FallarborTown_CozmosHouse2_Text_CozmoWentToMeteorFalls, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse2_EventScript_CozmoIsSad::
	msgbox FallarborTown_CozmosHouse2_Text_FeelSorryForCozmo, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse2_EventScript_CozmoIsHappy::
	msgbox FallarborTown_CozmosHouse2_Text_CozmoIsSoHappy, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse2_EventScript_Journal::
	msgbox FallarborTown_CozmosHouse2_Text_Journal, MSGBOX_SIGN
	release
	end

FallarborTown_CozmosHouse2_EventScript_Meteorite::
	@TODO: Deoxys change form here
	end

FallarborTown_CozmosHouse2_Text_Journal:
	.string "This journal is covered in notes with\n"
	.string "scientific terms and math equations.\p"
	.string "There is also a map of Hoenn with impact\n"
	.string "locations. Cozmo has noted that they are\l"
	.string "unusually positioned in an exact\l"
	.string "triangle pattern.$"

FallarborTown_CozmosHouse2_Text_MeteoriteWillNeverBeMineNow:
	.string "Prof. Cozmo: Oh…\n"
	.string "I never should have let myself be\l"
	.string "conned into telling Team Magma where\l"
	.string "you can find Meteorites…\p"
	.string "That Meteorite from Meteor Falls…\n"
	.string "It's never going to be mine now…$"

FallarborTown_CozmosHouse2_Text_IsThatMeteoriteMayIHaveIt:
	.string "Oh!\n"
	.string "Hah?\p"
	.string "That item…\p"
	.string "Could it be?\p"
	.string "Is it the Meteorite that Team Magma\n"
	.string "took from Meteor Falls?\p"
	.string "Please, may I have it?\p"
	.string "I'm not asking for it for free.\n"
	.string "How about in exchange for this TM?$"

FallarborTown_CozmosHouse2_Text_PleaseUseThisTM:
	.string "Prof. Cozmo: This TM, it represents\n"
	.string "my feeling of gratitude.\l"
	.string "Please use it!$"

FallarborTown_CozmosHouse2_Text_ReallyGoingToHelpMyResearch:
	.string "Prof. Cozmo: Oh, I can't believe it.\n"
	.string "This is really, really great!\p"
	.string "This is really going to help my research!$"

FallarborTown_CozmosHouse2_Text_CrushedWithDisappointment:
	.string "Prof. Cozmo: Oh, but…\n"
	.string "I'm crushed with disappointment…$"

FallarborTown_CozmosHouse2_Text_MayIHaveMeteorite:
	.string "Prof. Cozmo: Please, may I have that\n"
	.string "Meteorite?\p"
	.string "I'm not asking for it for free.\n"
	.string "How about in exchange for this TM?$"

FallarborTown_CozmosHouse2_Text_CozmoWentToMeteorFalls:
	.string "Prof. Cozmo went off to Meteor Falls\n"
	.string "on Route 114 with some people from\l"
	.string "Team Magma.$"

FallarborTown_CozmosHouse2_Text_FeelSorryForCozmo:
	.string "Poor Prof. Cozmo…\n"
	.string "He's so depressed… I feel sorry for him.$"

FallarborTown_CozmosHouse2_Text_CozmoIsSoHappy:
	.string "Look at Prof. Cozmo…\n"
	.string "He's so happy! I think it's cute.$"

