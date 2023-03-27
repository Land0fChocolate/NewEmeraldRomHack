.set LOCALID_OWNER, 1

LilycoveCity_CoveLilyMotel_1F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_1F_EventScript_MotelOwner::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot, MSGBOX_DEFAULT
	applymovement LOCALID_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem, MSGBOX_DEFAULT
	applymovement LOCALID_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar, MSGBOX_DEFAULT
	applymovement LOCALID_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_BlockingTV::
	lockall
	playse SE_PIN
	applymovement LOCALID_OWNER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_OWNER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV
	applymovement LOCALID_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer
	waitmovement 0
	applymovement LOCALID_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn
	waitmovement 0
	release
	end

LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV:
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer:
	walk_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn:
	face_down
	walk_down
	face_up
	step_end

LilycoveCity_CoveLilyMotel_1F_EventScript_Cook::
	lock
	faceplayer
	showmoneybox 0, 0, 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_SellGalarCurry, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LilycoveCity_CoveLilyMotel_1F_EventScript_DeclineGalarCurry
	checkmoney 900, 0
	compare VAR_RESULT, FALSE
	goto_if_eq LilycoveCity_CoveLilyMotel_1F_EventScript_NotEnoughMoney
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_ThankYouEnjoy, MSGBOX_DEFAULT
	checkitemspace ITEM_GALAR_CURRY, 1
	compare VAR_RESULT, TRUE
	call_if_eq LilycoveCity_CoveLilyMotel_1F_EventScript_RemoveMoney
	giveitem ITEM_GALAR_CURRY
	compare VAR_RESULT, FALSE
	goto_if_eq LilycoveCity_CoveLilyMotel_1F_EventScript_BagIsFull
	hidemoneybox
	release
	end

LilycoveCity_CoveLilyMotel_1F_Text_SellGalarCurry:
	.string "I've gone through a lot of trouble to\n"
	.string "procure the finest ingredients straight\l"
	.string "from Galar!\p"
	.string "My curry is the best and only authentic\n"
	.string "Galarian curry in all of Hoenn!\p"
	.string "You have come to me because you would\n"
	.string "like a plate, yes? It's ¥900.$"

LilycoveCity_CoveLilyMotel_1F_Text_CurryDeclined:
	.string "Very well.\n"
	.string "Come back when you have an appetite.$"

LilycoveCity_CoveLilyMotel_1F_Text_YouveNotGotTheMoney:
	.string "It appears you don't have enough money.\n"
	.string "I'm not running a soup kitchen here!$"

LilycoveCity_CoveLilyMotel_1F_Text_ThankYouEnjoy:
	.string "Enjoy your curry!$"

LilycoveCity_CoveLilyMotel_1F_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_RemoveMoney::
	removemoney 900, 0
	updatemoneybox 0, 0
	return

LilycoveCity_CoveLilyMotel_1F_EventScript_DeclineGalarCurry::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_CurryDeclined, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_NotEnoughMoney::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot:
	.string "Hm, so they doubled the guests by\n"
	.string "using Pokémon as attractions?\p"
	.string "Hm, well, maybe I should make a cute\n"
	.string "Pokémon our inn's mascot.\p"
	.string "I wonder if that will attract more\n"
	.string "guests to stay with us?$"

LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua:
	.string "Oh, sorry, sorry!\n"
	.string "I was too involved in watching TV!\p"
	.string "Since that Team Aqua came to town,\n"
	.string "the tourists have been staying away.$"

LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV:
	.string "Hey, down in front!\n"
	.string "I can't see the TV!$"

LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem:
	.string "Amazing! You're telling me a Pokémon\n"
	.string "found someone's lost item?\p"
	.string "That's something. If we had some smart\n"
	.string "Pokémon like that…\p"
	.string "We could recover anything that our\n"
	.string "guests mislaid…$"

LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted:
	.string "Oh, sorry, sorry!\n"
	.string "I was too involved in watching TV!\p"
	.string "I heard that someone busted\n"
	.string "the Team Aqua Hideout.\p"
	.string "Thanks to that, we just booked\n"
	.string "a reservation from a big group.\p"
	.string "It was a company called… Uh…\n"
	.string "GAME something…$"

LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar:
	.string "Amazing! A house-sitting Pokémon\n"
	.string "caught a burglar?\p"
	.string "That's something. If we had a tough\n"
	.string "Pokémon as a security guard…\p"
	.string "We would be able to provide our guests\n"
	.string "with greater safety.$"

LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner:
	.string "Oh, sorry, sorry!\n"
	.string "I was too involved in watching TV.\p"
	.string "Oh, yes. A big group of guests arrived\n"
	.string "a little while ago.\p"
	.string "They booked in as GAME FREAK,\n"
	.string "so I guess they must make games.\p"
	.string "Uh-oh, I'd better get working on\n"
	.string "their dinner!$"

