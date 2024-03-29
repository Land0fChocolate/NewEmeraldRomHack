.set LOCALID_METEORITE, 4

FallarborTown_CozmosHouse2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_CozmosHouse2_OnTransition
	.byte 0

FallarborTown_CozmosHouse2_OnTransition:
	call_if_set FLAG_RETURNED_METEORITE_TO_COZMO, FallarborTown_CozmosHouse2_EventScript_PlaceMeteorite
	end

FallarborTown_CozmosHouse2_EventScript_PlaceMeteorite:
	clearflag FLAG_HIDE_COZMOS_HOUSE_METEORITE
	addobject LOCALID_METEORITE
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
	setflag FLAG_RETURNED_METEORITE_TO_COZMO
	msgbox FallarborTown_CozmosHouse2_Text_PleaseUseThisTM, MSGBOX_DEFAULT
	giveitem ITEM_TM82
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setvar VAR_0x8004, ITEM_METEORITE
	call Common_EventScript_PlayerHandedOverTheItem
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
	msgbox FallarborTown_CozmosHouse2_Text_ItsAMeteorite, MSGBOX_SIGN
	closemessage
	checkformoninparty SPECIES_DEOXYS
	compare VAR_RESULT, TRUE
	goto_if_eq FallarborTown_CozmosHouse2_EventScript_ChangeDeoxysForm
	checkformoninparty SPECIES_DEOXYS_DEFENSE
	compare VAR_RESULT, TRUE
	goto_if_eq FallarborTown_CozmosHouse2_EventScript_ChangeDeoxysForm
	checkformoninparty SPECIES_DEOXYS_SPEED
	compare VAR_RESULT, TRUE
	goto_if_eq FallarborTown_CozmosHouse2_EventScript_ChangeDeoxysForm
	end

FallarborTown_CozmosHouse2_EventScript_ChangeDeoxysForm::
	changedeoxysform 1
	playmoncry SPECIES_DEOXYS, 0
	waitse
	msgbox FallarborTown_CozmosHouse2_Text_DeoxysChangedForm, MSGBOX_SIGN
	end

FallarborTown_CozmosHouse2_Text_ItsAMeteorite:
	.string "It's the meteorite you returned to\n"
	.string "Professor Cozmo. You feel a radiating\l"
	.string "warmth coming from it.$"

FallarborTown_CozmosHouse2_Text_DeoxysChangedForm:
	.string "The Deoxys in your party changed into\n"
	.string "a more aggressive form!$"

FallarborTown_CozmosHouse2_Text_Journal:
	.string "This journal is covered in notes with\n"
	.string "scientific terms and math equations.\p"
	.string "There is also a map of Hoenn with impact\n"
	.string "locations.\p"
	.string "Cozmo has noted that they are unusually\n"
	.string "positioned in an exact triangle pattern.$"

FallarborTown_CozmosHouse2_Text_MeteoriteWillNeverBeMineNow:
	.string "Prof. Cozmo: Oh…\n"
	.string "I never should have let myself be\l"
	.string "conned into telling Team Magma where\l"
	.string "you can find Meteorites…\p"
	.string "That special Meteorite I discovered…\n"
	.string "I'm never going to get it back now…$"

FallarborTown_CozmosHouse2_Text_IsThatMeteoriteMayIHaveIt:
	.string "Oh!\n"
	.string "Hah?\p"
	.string "That item…\p"
	.string "Could it be?\p"
	.string "Is it the Meteorite that Team Magma\n"
	.string "stole from me in Meteor Falls?\p"
	.string "Thank you so much for bringing it back!\p"
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

