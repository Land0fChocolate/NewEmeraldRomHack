NavelRock_Lugia2_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, NavelRock_Lugia2_OnLoad
	.byte 0

NavelRock_Lugia2_OnLoad::
	call_if_set FLAG_NAVEL_ROCK_LUGIA_HIDE_BOULDER1, NavelRock_Lugia2_Eventscript_BlockCurrent1
	call_if_set FLAG_NAVEL_ROCK_LUGIA_HIDE_BOULDER2, NavelRock_Lugia2_Eventscript_BlockCurrent2
	call_if_set FLAG_NAVEL_ROCK_LUGIA_HIDE_BOULDER3, NavelRock_Lugia2_Eventscript_ShowBoulder4
	end

NavelRock_Lugia2_Eventscript_BlockCurrent1::
	setmetatile 30, 4, METATILE_Pacifidlog_DarkOcean_TopLeftCornerLedge, 0
	setmetatile 31, 4, METATILE_Pacifidlog_SubmergedBoulder_NorthLedge, 1
	setmetatile 32, 4, METATILE_Pacifidlog_DarkOcean_TopRightCornerLedge, 0
	setmetatile 30, 5, METATILE_Pacifidlog_DarkOcean_LeftLedge, 0
	setmetatile 31, 5, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 32, 5, METATILE_Pacifidlog_DarkOcean_RightLedge, 0
	setmetatile 30, 6, METATILE_Pacifidlog_DarkOcean_LeftLedge, 0
	setmetatile 31, 6, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 32, 6, METATILE_Pacifidlog_DarkOcean_RightLedge, 0
	setmetatile 30, 7, METATILE_Pacifidlog_DarkOcean_LeftLedge, 0
	setmetatile 31, 7, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 32, 7, METATILE_Pacifidlog_DarkOcean_RightLedge, 0
	setmetatile 30, 8, METATILE_Pacifidlog_DarkOcean_BotLeftLedge, 0
	setmetatile 31, 8, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 32, 8, METATILE_Pacifidlog_DarkOcean_RightLedge, 0
	setmetatile 30, 9, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 31, 9, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 32, 9, METATILE_Pacifidlog_DarkOcean_RightLedge, 0
	setmetatile 30, 10, METATILE_Pacifidlog_DarkOcean_TopLeftLedge, 0
	setmetatile 31, 10, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 32, 10, METATILE_Pacifidlog_DarkOcean_RightLedge, 0
	setmetatile 30, 11, METATILE_Pacifidlog_DarkOcean_LeftLedge, 0
	setmetatile 31, 11, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 32, 11, METATILE_Pacifidlog_DarkOcean_RightLedge, 0
	return

NavelRock_Lugia2_Eventscript_BlockCurrent2::
	setmetatile 4, 7, METATILE_Pacifidlog_DarkOcean_LeftLedge, 0
	setmetatile 5, 7, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 6, 7, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 7, 7, METATILE_Pacifidlog_DarkOcean_RightLedge, 0
	setmetatile 4, 8, METATILE_Pacifidlog_DarkOcean_LeftLedge, 0
	setmetatile 5, 8, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 6, 8, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 7, 8, METATILE_Pacifidlog_DarkOcean_RightLedge, 0
	setmetatile 4, 9, METATILE_Pacifidlog_DarkOcean_LeftLedge, 0
	setmetatile 5, 9, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 6, 9, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 7, 9, METATILE_Pacifidlog_DarkOcean_RightLedge, 0
	setmetatile 4, 10, METATILE_Pacifidlog_DarkOcean_LeftLedge, 0
	setmetatile 5, 10, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 6, 10, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 7, 10, METATILE_Pacifidlog_DarkOcean_RightLedge, 0
	setmetatile 4, 11, METATILE_Pacifidlog_DarkOcean_LeftLedge, 0
	setmetatile 5, 11, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 6, 11, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 7, 11, METATILE_Pacifidlog_DarkOcean_RightLedge, 0
	setmetatile 4, 12, METATILE_Pacifidlog_DarkOcean_LeftLedge, 0
	setmetatile 5, 12, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 6, 12, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 7, 12, METATILE_Pacifidlog_DarkOcean_RightLedge, 0
	setmetatile 4, 13, METATILE_Pacifidlog_DarkOcean_LeftLedge, 0
	setmetatile 5, 13, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 6, 13, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 7, 13, METATILE_Pacifidlog_DarkOcean_RightLedge, 0
	setmetatile 4, 14, METATILE_Pacifidlog_DarkOcean_LeftLedge, 0
	setmetatile 5, 14, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 6, 14, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 7, 14, METATILE_Pacifidlog_DarkOcean_RightLedge, 0
	setmetatile 4, 15, METATILE_Pacifidlog_DarkOcean_LeftLedge, 0
	setmetatile 5, 15, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 6, 15, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 7, 15, METATILE_Pacifidlog_DarkOcean_BotRightLedge, 0
	setmetatile 8, 15, METATILE_Pacifidlog_DarkOcean_TopLedge, 0
	setmetatile 9, 15, METATILE_Pacifidlog_DarkOcean_TopLedge, 0
	setmetatile 10, 15, METATILE_Pacifidlog_DarkOcean_TopRightCornerLedge, 0
	setmetatile 4, 16, METATILE_Pacifidlog_DarkOcean_LeftLedge, 0
	setmetatile 5, 16, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 6, 16, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 7, 16, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 8, 16, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 9, 16, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 10, 16, METATILE_Pacifidlog_DarkOcean_RightLedge, 0
	setmetatile 4, 17, METATILE_Pacifidlog_DarkOcean_LeftLedge, 0
	setmetatile 5, 17, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 6, 17, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 7, 17, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 8, 17, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 9, 17, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 10, 17, METATILE_Pacifidlog_DarkOcean_RightLedge, 0
	setmetatile 6, 18, METATILE_Pacifidlog_DarkOcean_TopLeftLedge, 0
	setmetatile 7, 18, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 8, 18, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 9, 18, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 10, 18, METATILE_Pacifidlog_DarkOcean_RightLedge, 0
	setmetatile 6, 19, METATILE_Pacifidlog_DarkOcean_LeftLedge, 0
	setmetatile 7, 19, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 8, 19, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 9, 19, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 10, 19, METATILE_Pacifidlog_DarkOcean_RightLedge, 0
	setmetatile 6, 20, METATILE_Pacifidlog_DarkOcean_LeftLedge, 0
	setmetatile 7, 20, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 8, 20, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 9, 20, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 10, 20, METATILE_Pacifidlog_DarkOcean_RightLedge, 0
	setmetatile 6, 21, METATILE_Pacifidlog_DarkOcean_LeftLedge, 0
	setmetatile 7, 21, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 8, 21, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 9, 21, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 10, 21, METATILE_Pacifidlog_DarkOcean_RightLedge, 0
	setmetatile 7, 22, METATILE_Pacifidlog_DarkOcean_TopLeftLedge, 0
	setmetatile 8, 22, METATILE_Pacifidlog_SubmergedBoulder_DarkOcean, 1
	setmetatile 9, 22, METATILE_Pacifidlog_DarkOcean_TopRightLedge, 0

	return

NavelRock_Lugia2_Eventscript_ShowBoulder4::
	goto_if_unset FLAG_NAVEL_ROCK_LUGIA_HIDE_BOULDER3, NavelRock_Lugia2_Eventscript_HideBoulder4
	clearflag FLAG_NAVEL_ROCK_LUGIA_HIDE_BOULDER4
	end

NavelRock_Lugia2_Eventscript_HideBoulder4::
	setflag FLAG_NAVEL_ROCK_LUGIA_HIDE_BOULDER4
	end
