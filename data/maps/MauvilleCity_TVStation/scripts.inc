MauvilleCity_TVStation_MapScripts::
	.byte 0

MauvilleCity_TVStation_EventScript_Receptionist::
	msgbox MauvilleCity_TVStation_Text_Receptionist, MSGBOX_NPC
	end

MauvilleCity_TVStation_EventScript_Man::
	msgbox MauvilleCity_TVStation_Text_Man, MSGBOX_NPC
	end

MauvilleCity_TVStation_EventScript_CameraMan::
	msgbox MauvilleCity_TVStation_Text_CameraMan, MSGBOX_NPC
	end

MauvilleCity_TVStation_EventScript_Beauty::
	msgbox MauvilleCity_TVStation_Text_Beauty, MSGBOX_NPC
	end

MauvilleCity_TVStation_EventScript_Sidney::
	msgbox MauvilleCity_TVStation_Text_Sidney, MSGBOX_NPC
	end

MauvilleCity_TVStation_EventScript_Maniac::
	msgbox MauvilleCity_TVStation_Text_Maniac, MSGBOX_NPC
	end

MauvilleCity_TVStation_EventScript_Triathlete::
	msgbox MauvilleCity_TVStation_Text_Triathlete, MSGBOX_NPC
	end

MauvilleCity_TVStation_Text_Receptionist:
	.string "Hello, welcome to TV Mauville.\p"
	.string "Many TV programs broadcast in the Hoenn\n"
	.string "region are filmed and edited in the\l"
	.string "studios here.\p"
	.string "Feel free to tour the studios.$"

MauvilleCity_TVStation_Text_Man:
	.string "Much of our content isn't filmed here.\n"
	.string "We have reporters across Hoenn to catch\l"
	.string "the latest action on scene.\p"
	.string "You may have come across them.\n"
	.string "Please do accept their interviews when\l"
	.string "you have the time!$"

MauvilleCity_TVStation_Text_CameraMan:
	.string "Are you touring the studios?\n"
	.string "Don't touch any of the equipment.\l"
	.string "That stuff is expensive.$"

MauvilleCity_TVStation_Text_Beauty: @TODO
	.string ""
	.string "TODO$"

MauvilleCity_TVStation_Text_Sidney:
	.string "Some Pokémon get an undeserved bad rep.\n"
	.string "I'm here to try to change people's\l"
	.string "misconceptions of them.\p"
	.string "If I can change the minds of even just\n"
	.string "a few people through this interview,\l"
	.string "then my job will be a success.\p"
	.string "However my work won't be done until I\n"
	.string "change all of public perception.$"

MauvilleCity_TVStation_Text_Maniac:
	.string "Coming up with new scripts is tough.\n"
	.string "I'm tempted to pinch ideas from older\l"
	.string "shows. Hehehe.$"

MauvilleCity_TVStation_Text_Triathlete: @TODO: something about becoming a TV star?
	.string "TODO$"
