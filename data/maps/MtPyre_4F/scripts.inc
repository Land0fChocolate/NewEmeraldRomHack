MtPyre_4F_MapScripts::
	.byte 0

@ Seems like the scripts for the 4F and 5F were swapped

MtPyre_5F_EventScript_Atsushi::
	trainerbattle_single TRAINER_ATSUSHI, MtPyre_5F_Text_AtsushiIntro, MtPyre_5F_Text_AtsushiDefeat
	msgbox MtPyre_5F_Text_AtsushiPostBattle, MSGBOX_AUTOCLOSE
	end


MtPyre_5F_EventScript_Momo::
	trainerbattle_single TRAINER_MOMO_1, MtPyre_5F_Text_MomoIntro, MtPyre_5F_Text_MomoDefeat, MtPyre_5F_EventScript_RegisterMomo
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq MtPyre_5F_EventScript_MomoRematch
	msgbox MtPyre_5F_Text_MomoPostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_5F_EventScript_RegisterMomo::
	special PlayerFaceTrainerAfterBattle
	msgbox MtPyre_5F_Text_MomoRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_MOMO_1
	release
	end

MtPyre_5F_EventScript_MomoRematch::
	trainerbattle_rematch TRAINER_MOMO_1, MtPyre_5F_Text_MomoRematchIntro, MtPyre_5F_Text_MomoRematchDefeat
	msgbox MtPyre_5F_Text_MomoPostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_5F_Text_AtsushiIntro:
	.string "Teacher…\n"
	.string "Please watch over my progress!$"

MtPyre_5F_Text_AtsushiDefeat:
	.string "Teacher…\n"
	.string "Please forgive me!$"

MtPyre_5F_Text_AtsushiPostBattle:
	.string "Until I improve, my teacher, who rests\n"
	.string "here, will never find true peace…$"

MtPyre_5F_Text_MomoIntro:
	.string "When I told everyone that I can talk\n"
	.string "with Pokémon, they became concerned for\l"
	.string "me…$"

MtPyre_5F_Text_MomoDefeat:
	.string "My Pokémon! You aren't in pain, are you?$"

MtPyre_5F_Text_MomoPostBattle:
	.string "I don't get along with people, so my\n"
	.string "Pokémon are my friends.$"

MtPyre_5F_Text_MomoRegister:
	.string "My Pokémon have taken a liking to you.\n"
	.string "Please register with me, so that we may\l"
	.string "battle again.$"

MtPyre_5F_Text_MomoRematchIntro:
	.string "Oh, hello Trainer!\n"
	.string "Have you come here to battle?$"

MtPyre_5F_Text_MomoRematchDefeat:
	.string "My Pokémon seemed to enjoy that.$"

MtPyre_5F_Text_MomoPostRematch:
	.string "It's more fun to be with Pokémon than\n"
	.string "to talk with people.\p"
	.string "Battling Trainers make Pokémon happy\n"
	.string "though, so I don't mind you.$"
