SkyPillar_3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_3F_OnTransition
	.byte 0

SkyPillar_3F_OnTransition:
	compare VAR_SKY_PILLAR_STATE, 2
	call_if_lt SkyPillar_3F_EventScript_CleanFloor
	end

SkyPillar_3F_EventScript_CleanFloor::
	setmaplayoutindex LAYOUT_SKY_PILLAR_3F_CLEAN
	return

SkyPillar_3F_Eventscript_AbraTest::
	faceplayer
	compare VAR_SKY_PILLAR_4F_TRIGGER, 0
	call_if_eq SkyPillar_3F_Eventscript_AbraTest0
	compare VAR_SKY_PILLAR_4F_TRIGGER, 1
	call_if_eq SkyPillar_3F_Eventscript_AbraTest1
	setvar VAR_SKY_PILLAR_4F_TRIGGER, 0
	setvar VAR_SKY_PILLAR_5F_TRIGGER, 0
	playmoncry SPECIES_ABRA, 2
	end

SkyPillar_3F_Eventscript_AbraTest0::
	msgbox SkyPillar_3F_Text_AbraTest0, MSGBOX_NPC
	return

SkyPillar_3F_Eventscript_AbraTest1::
	msgbox SkyPillar_3F_Text_AbraTest1, MSGBOX_NPC
	return

SkyPillar_3F_Text_AbraTest0:
	.string "trigger is 0!$"

SkyPillar_3F_Text_AbraTest1:
	.string "trigger is 1!$"
