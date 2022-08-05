EverGrandeCity_House3_MapScripts::
	.byte 0

EverGrandeCity_House3_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM54, EverGrandeCity_House3_EventScript_ReceivedFalseSwipe
	msgbox EverGrandeCity_House3_Text_GiveFalseSwipe, MSGBOX_DEFAULT
	giveitem ITEM_TM54
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM54
	msgbox EverGrandeCity_House3_Text_ExplainFalseSwipe, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_House3_EventScript_ReceivedFalseSwipe::
	msgbox EverGrandeCity_House3_Text_ExplainFalseSwipe, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_House3_EventScript_Girl::
	msgbox EverGrandeCity_House3_Text_Girl, MSGBOX_NPC
	end

EverGrandeCity_House3_Text_GiveFalseSwipe:
	.string "TODO$"

EverGrandeCity_House3_Text_ExplainFalseSwipe:
	.string "TODO$"

EverGrandeCity_House3_Text_Girl:
	.string "TODO$"
