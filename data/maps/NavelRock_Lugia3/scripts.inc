NavelRock_Lugia3_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, NavelRock_Lugia3_OnLoad
	.byte 0

NavelRock_Lugia3_OnLoad::
	call_if_set FLAG_NAVEL_ROCK_LUGIA_HIDE_BOULDER4, NavelRock_Lugia3_Eventscript_CheckBoulder3
	end

NavelRock_Lugia3_Eventscript_CheckBoulder3::
	call_if_set FLAG_NAVEL_ROCK_LUGIA_HIDE_BOULDER3, NavelRock_Lugia3_Eventscript_BlockCurrent
	end

NavelRock_Lugia3_Eventscript_BlockCurrent::
	setmetatile 3, 8, METATILE_Pacifidlog_DarkOcean_TopLeftCornerLedge, 0
	setmetatile 4, 8, METATILE_Pacifidlog_DarkOcean_TopLedge, 0
	setmetatile 5, 8, METATILE_Pacifidlog_DarkOcean_TopLedge, 0
	setmetatile 6, 8, METATILE_Pacifidlog_DarkOcean_TopRightCornerLedge, 0
	setmetatile 2, 9, METATILE_Pacifidlog_DarkOcean_TopLeftCornerLedge, 0
	setmetatile 3, 9, METATILE_Pacifidlog_DarkOcean_BotLeftLedge, 0
	setmetatile 4, 9, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 5, 9, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 6, 9, METATILE_Pacifidlog_DarkOcean_BotRightLedge, 0
	setmetatile 7, 9, METATILE_Pacifidlog_DarkOcean_TopLedge, 0
	setmetatile 8, 9, METATILE_Pacifidlog_DarkOcean_TopLedge, 0
	setmetatile 9, 9, METATILE_Pacifidlog_DarkOcean_TopLedge, 0
	setmetatile 10, 9, METATILE_Pacifidlog_DarkOcean_TopLedge, 0
	setmetatile 11, 9, METATILE_Pacifidlog_DarkOcean_TopLedge, 0
	setmetatile 12, 9, METATILE_Pacifidlog_DarkOcean_TopLedge, 0
	setmetatile 13, 9, METATILE_Pacifidlog_DarkOcean_TopLedge, 0
	setmetatile 14, 9, METATILE_Pacifidlog_DarkOcean_TopRightCornerLedge, 0
	setmetatile 2, 10, METATILE_Pacifidlog_SubmergedBoulder_WestLedge, 1
	setmetatile 3, 10, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 4, 10, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 5, 10, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 6, 10, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 7, 10, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 8, 10, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 9, 10, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 10, 10, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 11, 10, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 12, 10, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 13, 10, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 14, 10, METATILE_Pacifidlog_DarkOcean_BotRightLedge, 0
	setmetatile 15, 10, METATILE_Pacifidlog_DarkOcean_TopLedge, 0
	setmetatile 16, 10, METATILE_Pacifidlog_DarkOcean_TopRightCornerLedge, 0
	setmetatile 2, 11, METATILE_Pacifidlog_DarkOcean_LeftLedge, 0
	setmetatile 3, 11, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 4, 11, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 5, 11, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 6, 11, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 7, 11, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 8, 11, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 9, 11, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 10, 11, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 11, 11, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 12, 11, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 13, 11, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 14, 11, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 15, 11, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 16, 11, METATILE_Pacifidlog_DarkOcean_BotRightLedge, 0
	setmetatile 17, 11, METATILE_Pacifidlog_DarkOcean_TopLedge, 0
	setmetatile 18, 11, METATILE_Pacifidlog_DarkOcean_TopLedge, 0
	setmetatile 19, 11, METATILE_Pacifidlog_DarkOcean_TopRightCornerLedge, 0
	setmetatile 3, 12, METATILE_Pacifidlog_DarkOcean_TopLeftLedge, 0
	setmetatile 4, 12, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 5, 12, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 6, 12, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 7, 12, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 8, 12, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 9, 12, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 10, 12, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 11, 12, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 12, 12, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 13, 12, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 14, 12, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 15, 12, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 16, 12, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 17, 12, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 18, 12, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 19, 12, METATILE_Pacifidlog_DarkOcean_BotRightLedge, 0
	setmetatile 20, 12, METATILE_Pacifidlog_DarkOcean_TopLedge, 0
	setmetatile 21, 12, METATILE_Pacifidlog_DarkOcean_TopLedge, 0
	setmetatile 22, 12, METATILE_Pacifidlog_DarkOcean_TopLedge, 0
	setmetatile 23, 12, METATILE_Pacifidlog_DarkOcean_TopRightCornerLedge, 0
	setmetatile 6, 13, METATILE_Pacifidlog_DarkOcean_TopLeftLedge, 0
	setmetatile 7, 13, METATILE_Pacifidlog_DarkOcean_TopRightLedge, 0
	setmetatile 14, 13, METATILE_Pacifidlog_DarkOcean_TopLeftLedge, 0
	setmetatile 15, 13, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 16, 13, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 17, 13, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 18, 13, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 19, 13, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 20, 13, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 21, 13, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 22, 13, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 23, 13, METATILE_Pacifidlog_DarkOcean_BotRightLedge, 0
	setmetatile 24, 13, METATILE_Pacifidlog_DarkOcean_TopLedge, 0
	setmetatile 25, 13, METATILE_Pacifidlog_DarkOcean_TopLedge, 0
	setmetatile 16, 14, METATILE_Pacifidlog_DarkOcean_TopLeftLedge, 0
	setmetatile 17, 14, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 18, 14, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 19, 14, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 20, 14, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 21, 14, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 22, 14, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 23, 14, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 24, 14, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 25, 14, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 26, 14, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 19, 15, METATILE_Pacifidlog_DarkOcean_TopLeftLedge, 0
	setmetatile 20, 15, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 21, 15, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 22, 15, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 23, 15, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 24, 15, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 25, 15, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 26, 15, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 23, 16, METATILE_Pacifidlog_DarkOcean_TopLeftLedge, 0
	setmetatile 24, 16, METATILE_Pacifidlog_DarkOcean, 0
	setmetatile 25, 16, METATILE_Pacifidlog_DarkOcean, 0
	return
