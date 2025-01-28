.set LOCALID_ARCHIE, 2
.set LOCALID_OLD_LADY, 3
.set LOCALID_GRUNT_1, 4
.set LOCALID_GRUNT_2, 5
.set LOCALID_GRUNT_3, 6
.set LOCALID_GRUNT_4, 7
.set LOCALID_PHOEBE, 8

MtPyre_Summit_MapScripts::
	@map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Summit_OnTransition
	.byte 0

MtPyre_Summit_OnTransition:
	call_if_unset FLAG_HIDE_MT_PYRE_SUMMIT_PHOEBE, MtPyre_Summit_EventScript_Position_Phoebe
	end

MtPyre_Summit_EventScript_Position_Phoebe::
	setobjectxyperm LOCALID_PHOEBE, 23, 13
	return

MtPyre_Summit_EventScript_TeamAquaTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaExits::
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox MtPyre_Summit_Text_ArchieWeGotTheOrb, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ARCHIE, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	compare VAR_0x8008, 0
	call_if_eq MtPyre_Summit_EventScript_ArchieFacePlayer0
	compare VAR_0x8008, 1
	call_if_eq MtPyre_Summit_EventScript_ArchieFacePlayer1
	compare VAR_0x8008, 2
	call_if_eq MtPyre_Summit_EventScript_ArchieFacePlayer2
	msgbox MtPyre_Summit_Text_ArchieWeArePullingOut, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ARCHIE
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_GRUNT_3
	removeobject LOCALID_GRUNT_4
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA
	fadedefaultbgm
	fadescreen FADE_FROM_BLACK
	delay 20
	setvar VAR_MT_PYRE_STATE, 1
	compare VAR_0x8008, 0
	call_if_eq MtPyre_Summit_EventScript_OldLadyApproachPlayer0
	compare VAR_0x8008, 1
	call_if_eq MtPyre_Summit_EventScript_OldLadyApproachPlayer1
	compare VAR_0x8008, 2
	call_if_eq MtPyre_Summit_EventScript_OldLadyApproachPlayer2
	msgbox MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis, MSGBOX_DEFAULT
	giveitem ITEM_MAGMA_EMBLEM
	msgbox MtPyre_Summit_Text_LeaderMentionedMtChimney, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RECEIVED_RED_OR_BLUE_ORB
	setflag FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD
	clearflag FLAG_HIDE_MT_PYRE_SUMMIT_PHOEBE
	setobjectxyperm LOCALID_PHOEBE, 23, 13
	addobject LOCALID_PHOEBE
	getplayerxy VAR_0x8004, VAR_0x8005
	compare VAR_0x8004, 22
	goto_if_eq MtPyre_Summit_EventScript_PhoebeWalkLeftRight
	compare VAR_0x8004, 23
	goto_if_eq MtPyre_Summit_EventScript_PhoebeWalkMiddle
	compare VAR_0x8004, 24
	goto_if_eq MtPyre_Summit_EventScript_PhoebeWalkLeftRight
MtPyre_Summit_EventScript_TeamAquaExitsPart2::
	msgbox MtPyre_Summit_Text_PhoebeIntro, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PHOEBE, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MtPyre_Summit_Text_PhoebeTalksToPlayer, MSGBOX_DEFAULT
	giveitem ITEM_TM65
	msgbox MtPyre_Summit_Text_PhoebeBonds, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

MtPyre_Summit_EventScript_ArchieFacePlayer0::
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer0
	waitmovement 0
	return

@ Archie is already facing player
MtPyre_Summit_EventScript_ArchieFacePlayer1::
	return

MtPyre_Summit_EventScript_ArchieFacePlayer2::
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer0::
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer0
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer1::
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer2::
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	return

MtPyre_Summit_Movement_OldLadyApproachPlayer0:
	walk_down
	walk_down
	walk_in_place_fastest_left
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer1:
	walk_down
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer2:
	walk_down
	walk_down
	walk_in_place_fastest_right
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer0:
	walk_left
	walk_in_place_fastest_down
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer2:
	walk_right
	walk_in_place_fastest_down
	step_end

MtPyre_Summit_EventScript_PhoebeWalkMiddle:
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerMoveOutOfWay
	applymovement LOCALID_PHOEBE, MtPyre_Summit_Movement_PhoebeMiddle
	waitmovement 0
	setobjectxyperm LOCALID_PHOEBE, 23, 7
	goto MtPyre_Summit_EventScript_TeamAquaExitsPart2

MtPyre_Summit_EventScript_PhoebeWalkLeftRight:
	applymovement LOCALID_PHOEBE, MtPyre_Summit_Movement_PhoebeLeftRight
	waitmovement 0
	setobjectxyperm LOCALID_PHOEBE, 23, 8
	goto MtPyre_Summit_EventScript_TeamAquaExitsPart2

MtPyre_Summit_Movement_PhoebeMiddle:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

MtPyre_Summit_Movement_PhoebeLeftRight:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

MtPyre_Summit_Movement_PlayerMoveOutOfWay:
	delay_16
	delay_16
	delay_16
	delay_16
	walk_right
	face_left
	step_end

MtPyre_Summit_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, MtPyre_Summit_EventScript_OldManAfterRayquaza
	msgbox MtPyre_Summit_Text_WillYouHearOutMyTale, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq MtPyre_Summit_EventScript_OldManTale
	compare VAR_RESULT, NO
	call_if_eq MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_Phoebe::
	lock
	faceplayer
	msgbox MtPyre_Summit_Text_PhoebeBonds, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldManAfterRayquaza::
	msgbox MtPyre_Summit_Text_HearTheNewLegendOfHoenn, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq MtPyre_Summit_EventScript_OldManNewTale
	compare VAR_RESULT, NO
	call_if_eq MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManTale::
	msgbox MtPyre_Summit_Text_GroudonKyogreTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_DeclineOldManTale::
	msgbox MtPyre_Summit_Text_WellThatTooIsFine, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldManNewTale::
	msgbox MtPyre_Summit_Text_HoennTrioTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldLady::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_RED_OR_BLUE_ORB, MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned
	compare VAR_MT_PYRE_STATE, 2
	call_if_ge MtPyre_Summit_EventScript_OldLadyOrbsReturned
	goto_if_set FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, MtPyre_Summit_EventScript_OldLadyLegendariesAwake
	msgbox MtPyre_Summit_Text_OrbsHaveBeenTaken, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyOrbsReturned::
	msgbox MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs, MSGBOX_DEFAULT
	setflag FLAG_RETURNED_RED_OR_BLUE_ORB
	release
	end

MtPyre_Summit_EventScript_OldLadyLegendariesAwake::
	msgbox MtPyre_Summit_Text_GroudonKyogreAwakened, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned::
	msgbox MtPyre_Summit_Text_SuperAncientPokemonTaughtUs, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_1, MtPyre_Summit_Text_Grunt1Intro, MtPyre_Summit_Text_Grunt1Defeat
	msgbox MtPyre_Summit_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_2, MtPyre_Summit_Text_Grunt2Intro, MtPyre_Summit_Text_Grunt2Defeat
	msgbox MtPyre_Summit_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_3, MtPyre_Summit_Text_Grunt3Intro, MtPyre_Summit_Text_Grunt3Defeat
	msgbox MtPyre_Summit_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_4, MtPyre_Summit_Text_Grunt4Intro, MtPyre_Summit_Text_Grunt4Defeat
	msgbox MtPyre_Summit_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_Text_Grunt1Intro:
	.string "No! Those Team Magma goons got\n"
	.string "here ahead of us!\p"
	.string "We can't fall behind!$"

MtPyre_Summit_Text_Grunt1Defeat:
	.string "I thought you were one of the Magmas\n"
	.string "who happened to come back…$"

MtPyre_Summit_Text_Grunt1PostBattle:
	.string "Yeah, so you are strong…\n"
	.string "But there're a lot of us!$"

MtPyre_Summit_Text_Grunt2Intro:
	.string "Hah!\n"
	.string "Too bad for you!\p"
	.string "If you came earlier, you only would've\n"
	.string "had to battle the wimpy Team Magma.\p"
	.string "But since you arrived now, you have\n"
	.string "to take on us toughies!$"

MtPyre_Summit_Text_Grunt2Defeat:
	.string "Urgh… I should've let you take on\n"
	.string "Team Magma first…$"

MtPyre_Summit_Text_Grunt2PostBattle:
	.string "You don't know anything!\n"
	.string "So why are you messing with us?$"

MtPyre_Summit_Text_Grunt3Intro:
	.string "You…\n"
	.string "We saw you at Mt. Chimney.\p"
	.string "You don't belong to either Team,\n"
	.string "so why would you be here?$"

MtPyre_Summit_Text_Grunt3Defeat:
	.string "If you're going to mess with anyone,\n"
	.string "let it be Team Magma…$"

MtPyre_Summit_Text_Grunt3PostBattle:
	.string "Heh, it doesn't matter!\n"
	.string "We bought ourselves some time!\p"
	.string "The boss should have snatched what\n"
	.string "he was after!$"

MtPyre_Summit_Text_Grunt4Intro:
	.string "Oh, I know!\n"
	.string "You tried to join Team Magma,\l"
	.string "but they wouldn't have you!\p"
	.string "Well, don't think that we'll let you\n"
	.string "join our Team Aqua!$"

MtPyre_Summit_Text_Grunt4Defeat:
	.string "If you want to join Team Aqua that\n"
	.string "badly, we can consider it…$"

MtPyre_Summit_Text_Grunt4PostBattle:
	.string "We have a great combination going\n"
	.string "with us members and our leader.$"

MtPyre_Summit_Text_ArchieWeGotTheOrb:
	.string "Archie: The Blue Orb!\n"
	.string "I knew the legend, but I didn't know\l"
	.string "where it was or if it really existed…\p"
	.string "Thanks for the tip, Maxie!\n"
	.string "Bwhahahaha!$"

MtPyre_Summit_Text_ArchieWeArePullingOut:
	.string "I thought something was a bit noisy,\n"
	.string "and who is it but the usual scamp!\p"
	.string "Sorry, scampo, but I'm afraid I just\n"
	.string "don't have time to play with you right\l"
	.string "now.\p"
	.string "Okay, team. We are pulling out!$"

MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis:
	.string "Oh, no…\n"
	.string "This cannot happen…\p"
	.string "Not only the Red Orb, but even\n"
	.string "the Blue Orb has been taken…\p"
	.string "The Red Orb and Blue Orb must never\n"
	.string "be separated. They belong together.\p"
	.string "What are those men trying to do with\n"
	.string "the two orbs?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Oh, yes. Was it Team Magma who came\n"
	.string "and took the Red Orb first?\p"
	.string "Well, in their haste, they left this\n"
	.string "behind.\p"
	.string "I couldn't imagine what exactly it\n"
	.string "could be.\p"
	.string "Are you going after them?\n"
	.string "Perhaps it will be useful in some way.$"

MtPyre_Summit_Text_LeaderMentionedMtChimney:
	.string "I've heard their leader say that\n"
	.string "they were “returning to Mt. Chimney”.\p"
	.string "Perhaps their base is located around\n"
	.string "that area?$"

MtPyre_Summit_Text_PhoebeIntro:
	.string "Grandma! Are you alright?\n"
	.string "I heard some shifty group was\l"
	.string "occupying Mt. Pyre.$"

MtPyre_Summit_Text_PhoebeTalksToPlayer:
	.string "Oh, and you are…?\p"
	.string "{PLAYER}.\n"
	.string "Thanks for watching over my grandma.\p"
	.string "Here, a token of my gratitude.$"

MtPyre_Summit_Text_PhoebeBonds:
	.string "I can sense that the bonds between you\n"
	.string "and your Pokémon are strong.\p"
	.string "We'll probably run into each other\n"
	.string "again.$"

MtPyre_Summit_Text_OrbsHaveBeenTaken:
	.string "The Blue Orb and Red Orb stolen by\n"
	.string "those sinister men…\p"
	.string "I don't know how the first man learned\n"
	.string "about them, but if he'd have done his\l"
	.string "research properly he would know that\l"
	.string "separating the orbs invites disaster.$"

MtPyre_Summit_Text_GroudonKyogreAwakened:
	.string "Oh, my goodness…\p"
	.string "You say that both Groudon and Kyogre\n"
	.string "have been awakened?\p"
	.string "It is said that the Red Orb and\n"
	.string "the Blue Orb quelled the rage of\l"
	.string "the two Pokémon…\p"
	.string "It is also said that the true owner\n"
	.string "of the Orbs still exists.\p"
	.string "However, no one knows who, or what\n"
	.string "exactly, the Orbs belong to.\p"
	.string "It could be a human, or perhaps\n"
	.string "a Pokémon, but no one knows.$"

MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs:
	.string "The two men who took the Orbs came\n"
	.string "back to return them on their own.\p"
	.string "Those men…\n"
	.string "Perhaps they are not so evil after all…$"

MtPyre_Summit_Text_SuperAncientPokemonTaughtUs:
	.string "The embodiments of the land, sea,\n"
	.string "and the sky…\p"
	.string "That is said to be the identities of\n"
	.string "the super-ancient Pokémon…\p"
	.string "In the same way that we humans and\n"
	.string "Pokémon have life, our world, too,\l"
	.string "is alive…\p"
	.string "The super-ancient Pokémon have\n"
	.string "taught us that…$"

MtPyre_Summit_Text_WillYouHearOutMyTale:
	.string "Mt. Pyre is where we calm the spirits\n"
	.string "of Pokémon that have passed on…\p"
	.string "This is a high place where one can\n"
	.string "see all of Hoenn…\p"
	.string "The disembodied spirits of Pokémon\n"
	.string "must find solace here…\p"
	.string "Is it coincidence that you are here…\p"
	.string "Will you hear out my tale? A tale long\n"
	.string "told in the Hoenn region?$"

MtPyre_Summit_Text_GroudonKyogreTale:
	.string "It happened long, long ago…\p"
	.string "The world was wracked by a ferocious\n"
	.string "clash between the Pokémon of the land\l"
	.string "and the Pokémon of the sea…\p"
	.string "The Pokémon of the land raised\n"
	.string "mountains and created continents…\p"
	.string "The Pokémon of the sea raised huge\n"
	.string "waves and carved out oceans…\p"
	.string "Their fierce duel raged without end.\p"
	.string "The world was engulfed in massive\n"
	.string "infernos and vicious storms.\p"
	.string "The Blue Orb and the Red Orb brought\n"
	.string "an end to the calamity.\p"
	.string "Light poured from the two orbs and\n"
	.string "becalmed the enraged adversaries.\p"
	.string "The pair, made docile, dove deep into\n"
	.string "the sea where eventually they\l"
	.string "disappeared…$"

MtPyre_Summit_Text_WellThatTooIsFine:
	.string "I see…\n"
	.string "Well, that, too, is fine…$"

MtPyre_Summit_Text_MaxieSilence:
	.string "Maxie: {PLAYER}…\p"
	.string "… … … … … …\n"
	.string "… … … … … …$"

MtPyre_Summit_Text_HearTheNewLegendOfHoenn:
	.string "It is my role to pass on the legends\n"
	.string "of Hoenn to future generations.\p"
	.string "And the crisis that just ended in\n"
	.string "Sootopolis rewrote a legend…\p"
	.string "Have you the time to hear the new\n"
	.string "legend of Hoenn?$"

MtPyre_Summit_Text_HoennTrioTale:
	.string "It happened long, long ago…\p"
	.string "The world was wracked by a ferocious\n"
	.string "clash between the Pokémon of the land\l"
	.string "and the Pokémon of the sea…\p"
	.string "The Pokémon of the land raised\n"
	.string "mountains and created continents…\p"
	.string "The Pokémon of the sea raised huge\n"
	.string "waves and carved out oceans…\p"
	.string "Their fierce duel raged without end.\p"
	.string "The world was engulfed in massive\n"
	.string "fires and vicious storms.\p"
	.string "It was then that the Pokémon of\n"
	.string "the sky descended from a storm.\p"
	.string "The Pokémon, shining a vivid green,\n"
	.string "becalmed the two enraged Pokémon.\p"
	.string "Then, its duty done, the green Pokémon\n"
	.string "flew off into the wild blue yonder…$"

