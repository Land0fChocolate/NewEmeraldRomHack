NavelRock_Hooh3_MapScripts::
	.byte 0

NavelRock_Hooh3_Eventscript_BoulderSwitch4::
	lockall
	compare VAR_NAVEL_ROCK_BOULDER_BUTTON_4, 100
	goto_if_eq NavelRock_Hooh3_Eventscript_BoulderSwitch4_AlreadyPressed
	playse SE_BANG
	waitse
	setvar VAR_NAVEL_ROCK_BOULDER_BUTTON_4, 100
NavelRock_Hooh3_Eventscript_BoulderSwitch4_AlreadyPressed::
	releaseall
	end
