EverGrandeCity_Mart_MapScripts::
	.byte 0

EverGrandeCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_Mart_EventScript_ExpertF::
	msgbox EverGrandeCity_Mart_Text_ExpertF, MSGBOX_NPC
	end

EverGrandeCity_Mart_EventScript_Maniac::
	msgbox EverGrandeCity_Mart_Text_Maniac, MSGBOX_NPC
	end

EverGrandeCity_Mart_Text_ExpertF:
	.string "Victory Road is a gruelling journey,\n"
	.string "with many strong trainers and wild\l"
	.string "Pokémon.\p"
	.string "I always make sure I'm fully prepared.$"

EverGrandeCity_Mart_Text_Maniac:
	.string "Hmm… the mart doesn't stock items like\n"
	.string "Max Revive or Elixir.\p"
	.string "Where do people get those?$"
