.set LOCALID_GROUDON, 1
.set LOCALID_GRUNT_1, 2
.set LOCALID_GRUNT_2, 3
.set LOCALID_GRUNT_3, 4
.set LOCALID_COURTNEY, 5
.set LOCALID_MAXIE, 6
.set LOCALID_GROUDON_SLEEPING, 7

MagmaHideout_4F_MapScripts::
	.byte 0

MagmaHideout_4F_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MagmaHideout_4F_Text_MaxieAwakenGroudon, MSGBOX_DEFAULT
	closemessage
	delay 20
	setvar VAR_RESULT, 1
	playse SE_M_DETECT
	dofieldeffectsparkle 18, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	setvar VAR_RESULT, 1
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	delay 150
	removeobject LOCALID_GROUDON_SLEEPING
	addobject LOCALID_GROUDON
	waitstate
	delay 60
	applymovement LOCALID_GROUDON, MagmaHideout_4F_Movement_GroudonApproach
	waitmovement 0
	special FadeOutOrbEffect
	waitstate
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_GROUDON, MagmaHideout_4F_Movement_GroudonExit
	waitmovement 0
	removeobject LOCALID_GROUDON
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	applymovement LOCALID_MAXIE, MagmaHideout_4F_Movement_MaxieLookAround
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieGroudonWhatsWrong, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	delay 30
	applymovement LOCALID_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieOhItWasYou, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_MAXIE_MAGMA_HIDEOUT, MagmaHideout_4F_Text_MaxieDefeat
	msgbox MagmaHideout_4F_Text_MaxieImGoingAfterGroudon, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_SLATEPORT_CITY_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_GABBY_AND_TY
	setflag FLAG_TV_STERN_ANNOUNCEMENT
	setvar VAR_SLATEPORT_CITY_STATE, 1
	setflag FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_PHOEBE
	setvar VAR_SLATEPORT_HARBOR_STATE, 1
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MAXIE
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_GRUNT_3
	removeobject LOCALID_COURTNEY
	setflag FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS
	fadescreen FADE_FROM_BLACK
	releaseall
	end

MagmaHideout_4F_Movement_GroudonApproach:
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	step_end

MagmaHideout_4F_Movement_GroudonExit:
	slide_up
	slide_up
	step_end

MagmaHideout_4F_Movement_MaxieLookAround:
	face_left
	delay_16
	face_right
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	face_up
	delay_16
	delay_16
	step_end

MagmaHideout_4F_EventScript_Grunt11::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_11, MagmaHideout_4F_Text_Grunt11Intro, MagmaHideout_4F_Text_Grunt11Defeat
	msgbox MagmaHideout_4F_Text_Grunt11PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt12::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_12, MagmaHideout_4F_Text_Grunt12Intro, MagmaHideout_4F_Text_Grunt12Defeat
	msgbox MagmaHideout_4F_Text_Grunt12PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt13::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_13, MagmaHideout_4F_Text_Grunt13Intro, MagmaHideout_4F_Text_Grunt13Defeat
	msgbox MagmaHideout_4F_Text_Grunt13PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Courtney::
	trainerbattle_single TRAINER_COURTNEY_MAGMA_HIDEOUT, MagmaHideout_4F_Text_CourtneyIntro, MagmaHideout_4F_Text_CourtneyDefeat
	msgbox MagmaHideout_4F_Text_CourtneyPostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MAGMA_HIDEOUT, MagmaHideout_4F_Text_TabithaIntro, MagmaHideout_4F_Text_TabithaDefeat
	msgbox MagmaHideout_4F_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_Text_Grunt11Intro:
	.string "Hey, you.\n"
	.string "Could you cover my shift?\p"
	.string "Wait, who are you!?$"

MagmaHideout_4F_Text_Grunt11Defeat:
	.string "Man, I never should have gone into\n"
	.string "work today…$"

MagmaHideout_4F_Text_Grunt11PostBattle:
	.string "I'm quitting after today.\n"
	.string "The work we do doesn't feel very\l"
	.string "rewarding and just doesn't make up for\l"
	.string "the benefits.$"

MagmaHideout_4F_Text_Grunt12Intro:
	.string "Fuhahaha!\n"
	.string "Soon! Very soon!\l"
	.string "Our grand objective will be achieved!$"

MagmaHideout_4F_Text_Grunt12Defeat:
	.string "Grrr…\n"
	.string "You can't stop us! Glory to Team Magma!$"

MagmaHideout_4F_Text_Grunt12PostBattle:
	.string "Maxie, sir!\n"
	.string "An intruder is headed your way!$"

MagmaHideout_4F_Text_Grunt13Intro:
	.string "This ends here! You won't be messing\n"
	.string "with us any longer!$"

MagmaHideout_4F_Text_Grunt13Defeat:
	.string "Was I that easy to knock down?$"

MagmaHideout_4F_Text_Grunt13PostBattle:
	.string "I-it doesn't matter!\n"
	.string "We've nearly won!$"

MagmaHideout_4F_Text_CourtneyIntro:
	.string "…\n"
	.string "…Analyzing.\p"
	.string "The anomaly that interfered with the\n"
	.string "Mt. Chimney eruption plan.\p"
	.string "High probability of interfering with\n"
	.string "Awaken the Continent plan.\p"
	.string "Deleting…$"

MagmaHideout_4F_Text_CourtneyDefeat:
	.string "That's unanticipated… Annoying…\n"
	.string "but interesting!$"

MagmaHideout_4F_Text_CourtneyPostBattle:
	.string "Target locked. Commencing… experiment.\n"
	.string "You shall be observed.$"

MagmaHideout_4F_Text_TabithaIntro:
	.string "Ahya. It's you again!\p"
	.string "I can't believe you're even following\n"
	.string "us around all the way back here.\p"
	.string "I should teach you not to stalk others,\n"
	.string "by beating you to a pulp!$"

MagmaHideout_4F_Text_TabithaDefeat:
	.string "Ahyahya!$"

MagmaHideout_4F_Text_TabithaPostBattle:
	.string "You better listen, you stress-inducing\n"
	.string "child.\p"
	.string "Leader Maxie's plan is already underway\n"
	.string "and you are too late to stop it!\p"
	.string "You should start preparing to live in\n"
	.string "our new world!$"

MagmaHideout_4F_Text_MaxieAwakenGroudon:
	.string "Maxie: Groudon…\p"
	.string "So long have I waited for this day…\n"
	.string "Immeasurably long!\p"
	.string "This foolish world has held back\n"
	.string "humanity's progress out of misguided\l"
	.string "idealism.\p"
	.string "But this ancient creature can bring that\n"
	.string "to its rightful end, creating a new land\l"
	.string "upon which humanity may stride freely\l"
	.string "forward.$"
	.string "Nothing could awaken you from your\n"
	.string "sleep bathed in magma…\p"
	.string "This Red Orb is what you sought.\n"
	.string "Wasn't it?\p"
	.string "I have brought you the Red Orb.\n"
	.string "Let its shine awaken you!\p"
	.string "And show me…\n"
	.string "Show me the full extent of your power!$"

MagmaHideout_4F_Text_MaxieGroudonWhatsWrong:
	.string "Maxie: Groudon!\n"
	.string "What's wrong?\p"
	.string "Wasn't the Red Orb the key?\p"
	.string "Groudon!\n"
	.string "Where have you gone…$"

MagmaHideout_4F_Text_MaxieOhItWasYou:
	.string "Maxie: Oh, so it was you?\p"
	.string "I've seen you poking around uninvited\n"
	.string "here and there…\p"
	.string "I get it now!\n"
	.string "You must have pulled a cheap stunt!$"

MagmaHideout_4F_Text_MaxieDefeat:
	.string "What makes you so adept at handling\n"
	.string "Pokémon?$"

MagmaHideout_4F_Text_MaxieImGoingAfterGroudon:
	.string "Maxie: There has to be some reason\n"
	.string "why Groudon fled…\p"
	.string "That's what you're trying to say,\n"
	.string "aren't you?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Humph…\n"
	.string "You think I didn't know that?\p"
	.string "With Groudon gone, there is no longer\n"
	.string "any need for this blasted volcano.\p"
	.string "I am going after Groudon, so this\n"
	.string "is where we part!$"
