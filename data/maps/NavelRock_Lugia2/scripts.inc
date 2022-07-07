NavelRock_Lugia2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NavelRock_Lugia2_OnTransition
	.byte 0

NavelRock_Lugia2_OnTransition::
	call_if_set FLAG_NAVEL_ROCK_LUGIA_HIDE_BOULDER1, NavelRock_Lugia2_Eventscript_BlockCurrent1
	call_if_set FLAG_NAVEL_ROCK_LUGIA_HIDE_BOULDER2, NavelRock_Lugia2_Eventscript_BlockCurrent2
	call_if_set FLAG_NAVEL_ROCK_LUGIA_HIDE_BOULDER3, NavelRock_Lugia2_Eventscript_ShowBoulder4
	end

NavelRock_Lugia2_Eventscript_BlockCurrent1::
	setmetatile 30, 4, METATILE_General_Shallow_Water, 0
	setmetatile 31, 4, METATILE_NavelRock_Submerged_Boulder, 0
	setmetatile 32, 4, METATILE_General_Shallow_Water, 0
	setmetatile 30, 5, METATILE_NavelRock_Ocean_Water_NorthWestCornerShallow, 0
	setmetatile 31, 5, METATILE_NavelRock_Ocean_Water_NorthShallow, 0
	setmetatile 32, 5, METATILE_NavelRock_Ocean_Water_NorthEastCornerShallow, 0
	setmetatile 30, 6, METATILE_NavelRock_Ocean_Water_WestShallow, 0
	setmetatile 31, 6, METATILE_NavelRock_Ocean_Water, 0
	setmetatile 32, 6, METATILE_NavelRock_Ocean_Water_EastShallow, 0
	setmetatile 30, 7, METATILE_NavelRock_Ocean_Water_WestShallow, 0
	setmetatile 31, 7, METATILE_NavelRock_Ocean_Water, 0
	setmetatile 32, 7, METATILE_NavelRock_Ocean_Water_EastShallow, 0
	setmetatile 30, 8, METATILE_NavelRock_Ocean_Water_NorthWestShallow, 0
	setmetatile 31, 8, METATILE_NavelRock_Ocean_Water, 0
	setmetatile 32, 8, METATILE_NavelRock_Ocean_Water_EastShallow, 0
	setmetatile 30, 9, METATILE_NavelRock_Ocean_Water_SouthWestShallow, 0
	setmetatile 31, 9, METATILE_NavelRock_Ocean_Water, 0
	setmetatile 32, 9, METATILE_NavelRock_Ocean_Water_EastShallow, 0
	setmetatile 30, 10, METATILE_NavelRock_Ocean_Water_WestShallow, 0
	setmetatile 31, 10, METATILE_NavelRock_Ocean_Water, 0
	setmetatile 32, 10, METATILE_NavelRock_Ocean_Water_EastShallow, 0
	return

NavelRock_Lugia2_Eventscript_BlockCurrent2::
	setmetatile 7, 22, METATILE_General_Shallow_Water, 0
	return

NavelRock_Lugia2_Eventscript_ShowBoulder4::
	goto_if_set FLAG_NAVEL_ROCK_LUGIA_HIDE_BOULDER4, NavelRock_Lugia2_Eventscript_HideBoulder4
	clearflag FLAG_NAVEL_ROCK_LUGIA_HIDE_BOULDER4
	end

NavelRock_Lugia2_Eventscript_HideBoulder4::
	end
