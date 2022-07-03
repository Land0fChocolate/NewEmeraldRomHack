RustboroCity_Flat2_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_Flat2_1F_OnTransition
	.byte 0

RustboroCity_Flat2_1F_OnTransition::
	call_if_set FLAG_HIDE_BOULDER2, RustboroCity_Flat2_1F_Eventscript_ShowBoulder
	end

RustboroCity_Flat2_1F_Eventscript_ShowBoulder::
	clearflag FLAG_HIDE_BOULDER1
	end

RustboroCity_Flat2_1F_EventScript_OldWoman::
	msgbox RustboroCity_Flat2_1F_Text_DevonWorkersLiveHere, MSGBOX_NPC
	end

RustboroCity_Flat2_1F_Text_DevonWorkersLiveHere:
	.string "Devon Corporation's workers live in\n"
	.string "this building.$"
