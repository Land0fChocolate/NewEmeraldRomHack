EventScript_TV::
	lockall
	incrementgamestat GAME_STAT_WATCHED_TV
	special ResetTVShowState
	specialvar VAR_RESULT, CheckForPlayersHouseNews
	compare VAR_RESULT, PLAYERS_HOUSE_TV_MOVIE
	goto_if_eq EventScript_PlayersHouseMovie
	compare VAR_RESULT, PLAYERS_HOUSE_TV_LATI
	goto_if_eq EventScript_PlayersHouseLatiNewsFlash
	goto_if_unset FLAG_SYS_TV_START, EventScript_MomDadMightLikeThis1
	goto_if_set FLAG_SYS_TV_WATCH, EventScript_MomDadMightLikeThis1 
	goto_if_set FLAG_TV_STERN_ANNOUNCEMENT, EventScript_SternAnnouncement
	goto_if_set FLAG_TV_RARE_CANDY_ADVERT, EventScript_RareCandyAdvert
	specialvar VAR_RESULT, IsGabbyAndTyShowOnTheAir
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_DoInSearchOfTrainers
	goto EventScript_TryDoPokeNews
	end

EventScript_TryDoTVShow::
	specialvar VAR_0x8004, GetRandomActiveShowIdx
	compare VAR_0x8004, 255
	goto_if_eq EventScript_MomDadMightLikeThis2
	specialvar VAR_RESULT, GetNextActiveShowIfMassOutbreak
	compare VAR_RESULT, 255
	goto_if_eq EventScript_MomDadMightLikeThis2
	copyvar VAR_0x8004, VAR_RESULT
	specialvar VAR_RESULT, GetSelectedTVShow
	compare VAR_RESULT, 0
	goto_if_ne EventScript_DoTVShow
	end

EventScript_MomDadMightLikeThis1::
	special GetMomOrDadStringForTVMessage
	msgbox gText_MomOrDadMightLikeThisProgram, MSGBOX_DEFAULT
	special TurnOffTVScreen
	releaseall
	end

EventScript_SternAnnouncement::
	msgbox gText_SternAnouncement, MSGBOX_DEFAULT
	special TurnOffTVScreen
	clearflag FLAG_TV_STERN_ANNOUNCEMENT
	releaseall
	end

EventScript_RareCandyAdvert::
	msgbox gText_RareCandyAdvert, MSGBOX_DEFAULT
	special TurnOffTVScreen
	clearflag FLAG_TV_RARE_CANDY_ADVERT
	releaseall
	end

EventScript_PlayersHouseMovie::
	msgbox PlayersHouse_1F_Text_TheresAMovieOnTV, MSGBOX_DEFAULT
	releaseall
	end

EventScript_PlayersHouseLatiNewsFlash::
	msgbox PlayersHouse_1F_Text_LatiEmergencyNewsFlash, MSGBOX_DEFAULT
	clearflag FLAG_SYS_TV_LATIAS_LATIOS
	setflag FLAG_LATIOS_OR_LATIAS_ROAMING
	special TurnOffTVScreen
	releaseall
	end

EventScript_DoTVShow::
	special DoTVShow
	waitmessage
	waitbuttonpress
	compare VAR_RESULT, 1
	goto_if_ne EventScript_DoTVShow
	goto EventScript_TurnOffTV
	end

EventScript_TurnOffTV::
	special TurnOffTVScreen
	setflag FLAG_SYS_TV_WATCH
	releaseall
	end

EventScript_MomDadMightLikeThis2::
	special GetMomOrDadStringForTVMessage
	msgbox gText_MomOrDadMightLikeThisProgram, MSGBOX_DEFAULT
	goto EventScript_TurnOffTV
	end

EventScript_TryDoPokeNews::
	special DoPokeNews
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_TryDoTVShow
	waitmessage
	waitbuttonpress
	goto EventScript_TurnOffTV
	end

EventScript_DoInSearchOfTrainers::
	special DoTVShowInSearchOfTrainers
	waitmessage
	waitbuttonpress
	compare VAR_RESULT, 0
	goto_if_eq EventScript_DoInSearchOfTrainers
	goto EventScript_TurnOffTV
	end
