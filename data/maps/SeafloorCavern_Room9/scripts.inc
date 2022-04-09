.set LOCALID_KYOGRE, 1
.set LOCALID_ARCHIE, 2
.set LOCALID_KYOGRE_SLEEPING, 4

SeafloorCavern_Room9_MapScripts::
	.byte 0

SeafloorCavern_Room9_EventScript_ArchieAwakenKyogre::
	lockall
	setvar VAR_0x8004, LOCALID_ARCHIE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, SeafloorCavern_Room9_Movement_Delay32
	waitmovement 0
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox SeafloorCavern_Room9_Text_ArchieHoldItRightThere, MSGBOX_DEFAULT
	closemessage
	addobject VAR_0x8004
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieSoItWasYou, MSGBOX_DEFAULT
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieBeholdKyogre, MSGBOX_DEFAULT
	applymovement VAR_0x8004, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieYouMustDisappear, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ARCHIE, SeafloorCavern_Room9_Text_ArchieDefeat
	msgbox SeafloorCavern_Room9_Text_ArchieWithThisBlueOrb, MSGBOX_DEFAULT
	setweather WEATHER_NONE
	doweather
	special Script_FadeOutMapMusic
	waitstate
	special WaitWeather
	waitstate
	setvar VAR_RESULT, 1
	playse SE_M_DETECT
	dofieldeffectsparkle 16, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	closemessage
	setvar VAR_RESULT, 0
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFastestUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	delay 150
	removeobject LOCALID_KYOGRE_SLEEPING
	addobject LOCALID_KYOGRE
	waitstate
	delay 60
	applymovement LOCALID_KYOGRE, SeafloorCavern_Room9_Movement_KyogreApproach
	waitmovement 0
	special FadeOutOrbEffect
	waitstate
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_KYOGRE, SeafloorCavern_Room9_Movement_KyogreExit
	waitmovement 0
	removeobject LOCALID_KYOGRE
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	setvar VAR_0x8004, LOCALID_ARCHIE
	msgbox SeafloorCavern_Room9_Text_ArchieWhereDidKyogreGo, MSGBOX_DEFAULT
	playse SE_PC_LOGIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieAMessageFromOutside, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieListenMessage
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieWhatRainingTooHard, MSGBOX_DEFAULT
	closemessage
	playse SE_PC_OFF
	delay 20
	applymovement LOCALID_ARCHIE, Common_Movement_FaceRight
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieWhyDidKyogreDisappear, MSGBOX_DEFAULT
	closemessage
	setvar VAR_ROUTE128_STATE, 1
	setvar VAR_SOOTOPOLIS_CITY_STATE, 1
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_ARCHIE
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAXIE
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_GROUDON
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_KYOGRE
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
	setflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
	clearflag FLAG_HIDE_ROUTE_128_ARCHIE
	setflag FLAG_SYS_WEATHER_CTRL
	setflag FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN
	checkflag FLAG_RECEIVED_TM91
	goto_if FALSE, SeafloorCavern_Room9_PlaceTM91StevensHouse
SeafloorCavern_Room9_EventScript_ArchieAwakenKyogrePart2::
	setvar VAR_STEVENS_HOUSE_STATE, 2
	setvar VAR_SEAFLOOR_CAVERN_STATE, 1
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_ARCHIE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_KYOGRE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_AQUA_GRUNTS
	setflag FLAG_HIDE_MAP_NAME_POPUP
	warp MAP_ROUTE128, 255, 38, 22
	waitstate
	releaseall
	end

SeafloorCavern_Room9_PlaceTM91StevensHouse::
	clearflag FLAG_ITEM_MOSSDEEP_CITY_TM91
	goto SeafloorCavern_Room9_EventScript_ArchieAwakenKyogrePart2

SeafloorCavern_Room9_Movement_ArchieApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SeafloorCavern_Room9_Movement_Unused1:
	walk_left
	walk_left
	step_end

SeafloorCavern_Room9_Movement_ArchieListenMessage:
	walk_left
	delay_16
	step_end

SeafloorCavern_Room9_Movement_Unused2:
	walk_right
	step_end

SeafloorCavern_Room9_Movement_KyogreApproach:
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

SeafloorCavern_Room9_Movement_KyogreExit:
	slide_up
	slide_up
	step_end

SeafloorCavern_Room9_Movement_Delay32:
	delay_16
	delay_16
	step_end

SeafloorCavern_Room9_Text_ArchieHoldItRightThere:
	.string "Archie: Hold it right there.$"

SeafloorCavern_Room9_Text_ArchieSoItWasYou:
	.string "Archie: Well, if it isn't my little\n"
	.string "adversary! I can't even find the words\l"
	.string "to praise you as you deserve.\p"
	.string "Sometimes it's best to keep things\n"
	.string "simple. All I'll say is you met my\l"
	.string "expectations, scamp!\p"
	.string "And I'm not just talking about today,\n"
	.string "but everything you've done up till now.\p"
	.string "And that's why you'll get the honor of\n"
	.string "meeting my new partner before anyone\l"
	.string "else living in this world!$"

SeafloorCavern_Room9_Text_ArchieBeholdKyogre:
	.string "Archie: Behold, the super-ancient\n"
	.string "Pokémon, Kyogre!\p"
	.string "How 'bout that?! That beautiful form so\n"
	.string "long resting at peace within the azure\l"
	.string "sea!$"

SeafloorCavern_Room9_Text_ArchieYouMustDisappear:
	.string "Archie: I've been waiting so long for\n"
	.string "this day to come. We humans have\l"
	.string "disregarded Pokémon and nature both in\l"
	.string "our endless pursuit of our own desires\l"
	.string "and needs…\p"
	.string "And in the process, we've created this\n"
	.string "broken and disordered world… But this\l"
	.string "is the day when I finally obtain the\l"
	.string "power to return everything to how it\l"
	.string "once was, to return to our beginnings!\p"
	.string "I can release the ancient power!\p"
	.string "And now, you are the last token\n"
	.string "resistance that's trying to ruin my\l"
	.string "day. I'll use everything my team and\l"
	.string "I have to crush you once and for all!$"

SeafloorCavern_Room9_Text_ArchieDefeat:
	.string "Like I figured…$"

SeafloorCavern_Room9_Text_ArchieWithThisBlueOrb:
	.string "Archie: Hah… Hah… Ahh… … Ah. Aha…\p"
	.string "Hah… Hah… Ahh… … Ah. Aha… Ahahahaha…\p"
	.string "Bwahahahahahaha! Bwaha! AHAHAHAHAHA!\p"
	.string "Perfect! You're just as great as any\n"
	.string "little hero trying to save the world\l"
	.string "oughta be!\p"
	.string "But it changes nothing!\n"
	.string "I can still use the Blue Orb!\p"
	.string "Now! AWAKEN, KYOGRE!\n"
	.string "RETURN EVERYTHING TO THE WAY IT WAS!!\p"

SeafloorCavern_Room9_Text_ArchieWhereDidKyogreGo:
	.string "Archie: Bwahahahaha! At last… AT LAST!\p"
	.string "I've finally done it!!! It hasn't even\n"
	.string "finished reversion, and it still has\l"
	.string "this much power!!!\p"
	.string "With this I can return everything to its\n"
	.string "natural beginning! It's time at last!$"

SeafloorCavern_Room9_Text_ArchieAMessageFromOutside:
	.string "Archie: Hm? It's a message from our\n"
	.string "members outside…$"

SeafloorCavern_Room9_Text_ArchieWhatRainingTooHard:
	.string "Archie: Yes, what is it?\p"
	.string "Oh? So the great deluge has already\n"
	.string "begun… But of course it has!\p"
	.string "What…? Far greater than we thought?!\n"
	.string "Well, that's great!\l"
	.string "Continue to monitor it.$"

SeafloorCavern_Room9_Text_ArchieWhyDidKyogreDisappear:
	.string "Archie: Bwahahahaha!\p"
	.string "I'll be heading outside to observe the\n"
	.string "birth of our new world.\p"
	.string "Care to join me, scamp?$"
