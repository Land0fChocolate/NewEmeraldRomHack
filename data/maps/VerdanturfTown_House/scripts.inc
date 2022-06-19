VerdanturfTown_House_MapScripts::
	.byte 0

VerdanturfTown_House_EventScript_AttractGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM45, VerdanturfTown_House_EventScript_ReceivedAttract
	msgbox VerdanturfTown_House_Text_AttractionRunsDeep, MSGBOX_DEFAULT
	giveitem ITEM_TM45
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM45
	msgbox VerdanturfTown_House_Text_AttractionMutual, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_House_EventScript_ReceivedAttract::
	msgbox VerdanturfTown_House_Text_AttractionMutual, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_House_Text_AttractionRunsDeep:
	.string "My feelings toward my Pokémon…\n"
	.string "The attraction runs deep…\p"
	.string "Oh, hi, you didn't see that, did you?\n"
	.string "Well, it doesn't matter.\p"
	.string "How would you like this TM for\n"
	.string "your Pokémon?$"

VerdanturfTown_House_Text_AttractionMutual:
	.string "My feelings toward my Pokémon…\n"
	.string "I'm sure the attraction is mutual!\p"
	.string "They battle exactly the way I want\n"
	.string "them to!$"
