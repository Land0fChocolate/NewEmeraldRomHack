CrumblingGorge_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CrumblingGorge_OnTransition
	.byte 0

CrumblingGorge_OnTransition:
	setflag FLAG_LANDMARK_CRUMBLING_GORGE
	end
