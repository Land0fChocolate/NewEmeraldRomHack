CrumblingGorge_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CrumblingGorge_OnTransition
	.byte 0

CrumblingGorge_OnTransition:
	setflag FLAG_LANDMARK_CRUMBLING_GORGE
	end

@Need to figure out what kind of event I'm going to do here. 
CrumblingGorge_EventScript_TODO::
	setflag FLAG_HIDE_ROUTE_111_MAGMA_GRUNTS
	msgbox CrumblingGorge_Text_TODO, MSGBOX_SIGN
	end

CrumblingGorge_Text_TODO:
	.string "TODO: Team Magma event.\n"
	.string "Flag to hide Route 111 Magma Grunts\l"
	.string "is now set.$"
