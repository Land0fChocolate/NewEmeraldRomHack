#ifndef GUARD_CONSTANTS_PARTY_MENU_H
#define GUARD_CONSTANTS_PARTY_MENU_H

#define AILMENT_NONE  0
#define AILMENT_PSN   1
#define AILMENT_PRZ   2
#define AILMENT_SLP   3
#define AILMENT_FRZ   4
#define AILMENT_BRN   5
#define AILMENT_PKRS  6
#define AILMENT_FNT   7

#define TUTOR_MOVE_SWORDS_DANCE    0 //Battle Frontier
#define TUTOR_MOVE_BODY_SLAM       1 //Battle Frontier
#define TUTOR_MOVE_DOUBLE_EDGE     2 //During Mainline
#define TUTOR_MOVE_COUNTER         3 //Battle Frontier
#define TUTOR_MOVE_SEISMIC_TOSS    4 //Battle Frontier
#define TUTOR_MOVE_MIMIC           5 //During Mainline
#define TUTOR_MOVE_METRONOME       6 //During Mainline
#define TUTOR_MOVE_SOFT_BOILED     7 //Battle Frontier
#define TUTOR_MOVE_DREAM_EATER     8 //Battle Frontier
#define TUTOR_MOVE_GASTRO_ACID     9 //Battle Frontier
#define TUTOR_MOVE_EXPLOSION       10 //During Mainline
#define TUTOR_MOVE_PSYCHIC_FANGS   11 //Battle Frontier
#define TUTOR_MOVE_SUBSTITUTE      12 //During Mainline
#define TUTOR_MOVE_DYNAMIC_PUNCH   13 //During Mainline
#define TUTOR_MOVE_ROLLOUT         14 //During Mainline
#define TUTOR_MOVE_PSYCH_UP        15 //Battle Frontier
#define TUTOR_MOVE_SNORE           16 //Battle Frontier
#define TUTOR_MOVE_ICY_WIND        17 //Battle Frontier
#define TUTOR_MOVE_ENDURE          18 //Battle Frontier
#define TUTOR_MOVE_EARTH_POWER     19 //Battle Frontier
#define TUTOR_MOVE_ICE_PUNCH       20 //Battle Frontier
#define TUTOR_MOVE_SWAGGER         21 //During Mainline
#define TUTOR_MOVE_SLEEP_TALK      22 //During Mainline
#define TUTOR_MOVE_SWIFT           23 //Battle Frontier
#define TUTOR_MOVE_DEFENSE_CURL    24 //Battle Frontier
#define TUTOR_MOVE_THUNDER_PUNCH   25 //Battle Frontier
#define TUTOR_MOVE_FIRE_PUNCH      26 //Battle Frontier
#define TUTOR_MOVE_FURY_CUTTER     27 //During Mainline
#define TUTOR_MOVE_SERPENT_DANCE   28 //Battle Frontier
#define TUTOR_MOVE_FLINT_BLADE     29 //Battle Frontier
#define TUTOR_MOVE_BLAZE_IMPACT    30 //Battle Frontier
#define TUTOR_MOVE_WORK_UP         31 //Battle Frontier
#define TUTOR_MOVE_LOW_SWEEP       32 //Battle Frontier
#define TUTOR_MOVE_AVALANCHE       33 //Battle Frontier
#define TUTOR_MOVE_SIGNAL_BEAM     34 //Battle Frontier
#define TUTOR_MOVE_NASTY_PLOT      35 //Battle Frontier
#define TUTOR_MOVE_SUPERPOWER      36 //Battle Frontier
#define TUTOR_MOVE_PLAY_ROUGH      37 //Battle Frontier
#define TUTOR_MOVE_STORED_POWER    38 //Battle Frontier
#define TUTOR_MOVE_ROLE_PLAY       39 //Battle Frontier
#define TUTOR_MOVE_DEFOG           40 //Battle Frontier
#define TUTOR_MOVE_TRICK           41 //Battle Frontier
#define TUTOR_MOVE_KNOCK_OFF       42 //Battle Frontier
#define TUTOR_MOVE_STEALTH_ROCK    43 //Battle Frontier
#define TUTOR_MOVE_TAILWIND        44 //Battle Frontier
#define TUTOR_MOVE_BREAKING_SWIPE  45 //Battle Frontier
#define TUTOR_MOVE_HEAT_WAVE       46 //Battle Frontier
#define TUTOR_MOVE_GUNK_SHOT       47 //Battle Frontier
#define TUTOR_MOVE_ZEN_HEADBUTT    48 //Battle Frontier
#define TUTOR_MOVE_BODY_PRESS      49 //Battle Frontier
#define TUTOR_MOVE_WORRY_SEED      50 //Battle Frontier
#define TUTOR_MOVE_RECYCLE         51 //Battle Frontier
#define TUTOR_MOVE_LOW_KICK        52 //Battle Frontier
#define TUTOR_MOVE_MAGIC_COAT      53 //Battle Frontier
#define TUTOR_MOVE_PAIN_SPLIT      54 //Battle Frontier
#define TUTOR_MOVE_SEED_BOMB       55 //Battle Frontier
#define TUTOR_MOVE_IRON_HEAD       56 //Battle Frontier
#define TUTOR_MOVE_AQUA_TAIL       57 //Battle Frontier
#define TUTOR_MOVE_FOUL_PLAY       58 //Battle Frontier
#define TUTOR_MOVE_MEGAHORN        59 //Battle Frontier
#define TUTOR_MOVE_DRACO_METEOR    60 //Ever Grande City
#define TUTOR_MOVE_HIDDEN_THORNS   61 //Battle Frontier
#define TUTOR_MOVE_BUG_BITE        62 //Battle Frontier

#define TUTOR_MOVE_COUNT           63

#define PARTY_LAYOUT_SINGLE          0
#define PARTY_LAYOUT_DOUBLE          1
#define PARTY_LAYOUT_MULTI           2
#define PARTY_LAYOUT_MULTI_SHOWCASE  3  // The layout during the screen that appears just before a multi battle
#define PARTY_LAYOUT_COUNT           4
#define KEEP_PARTY_LAYOUT            0xFF

#define PARTY_MENU_TYPE_FIELD                     0 
#define PARTY_MENU_TYPE_IN_BATTLE                 1 
#define PARTY_MENU_TYPE_CONTEST                   2 
#define PARTY_MENU_TYPE_CHOOSE_MON                3 
#define PARTY_MENU_TYPE_CHOOSE_HALF               4  // multi battles, eReader battles, and some battle facilities
#define PARTY_MENU_TYPE_MULTI_SHOWCASE            5
#define PARTY_MENU_TYPE_DAYCARE                   6 
#define PARTY_MENU_TYPE_MOVE_RELEARNER            7 
#define PARTY_MENU_TYPE_UNION_ROOM_REGISTER       8  // trading board
#define PARTY_MENU_TYPE_UNION_ROOM_TRADE          9  // trading board
#define PARTY_MENU_TYPE_SPIN_TRADE                10 // Unused beta for Gen IV's Spin Trade
#define PARTY_MENU_TYPE_MINIGAME                  11
#define PARTY_MENU_TYPE_STORE_PYRAMID_HELD_ITEMS  12

#define PARTY_ACTION_CHOOSE_MON         0
#define PARTY_ACTION_SEND_OUT           1
#define PARTY_ACTION_CANT_SWITCH        2
#define PARTY_ACTION_USE_ITEM           3
#define PARTY_ACTION_ABILITY_PREVENTS   4
#define PARTY_ACTION_GIVE_ITEM          5  
#define PARTY_ACTION_GIVE_PC_ITEM       6   // Unused. Not possible to give non-mail items directly from PC
#define PARTY_ACTION_GIVE_MAILBOX_MAIL  7
#define PARTY_ACTION_SWITCH             8
#define PARTY_ACTION_SWITCHING          9
#define PARTY_ACTION_SOFTBOILED         10
#define PARTY_ACTION_CHOOSE_AND_CLOSE   11
#define PARTY_ACTION_MOVE_TUTOR         12
#define PARTY_ACTION_MINIGAME           13
#define PARTY_ACTION_REUSABLE_ITEM      14  // Unused. The only reusable items are handled separately

// IDs for DisplayPartyMenuStdMessage, to display the message at the bottom of the party menu
#define PARTY_MSG_CHOOSE_MON                0
#define PARTY_MSG_CHOOSE_MON_OR_CANCEL      1
#define PARTY_MSG_CHOOSE_MON_AND_CONFIRM    2
#define PARTY_MSG_MOVE_TO_WHERE             3 
#define PARTY_MSG_TEACH_WHICH_MON           4
#define PARTY_MSG_USE_ON_WHICH_MON          5
#define PARTY_MSG_GIVE_TO_WHICH_MON         6
#define PARTY_MSG_NOTHING_TO_CUT            7
#define PARTY_MSG_CANT_SURF_HERE            8
#define PARTY_MSG_ALREADY_SURFING           9
#define PARTY_MSG_CURRENT_TOO_FAST          10
#define PARTY_MSG_ENJOY_CYCLING             11
#define PARTY_MSG_ALREADY_IN_USE            12
#define PARTY_MSG_CANT_USE_HERE             13
#define PARTY_MSG_NO_MON_FOR_BATTLE         14
#define PARTY_MSG_CHOOSE_MON_2              15
#define PARTY_MSG_NOT_ENOUGH_HP             16
#define PARTY_MSG_X_MONS_ARE_NEEDED         17
#define PARTY_MSG_MONS_CANT_BE_SAME         18
#define PARTY_MSG_NO_SAME_HOLD_ITEMS        19
#define PARTY_MSG_UNUSED                    20
#define PARTY_MSG_DO_WHAT_WITH_MON          21
#define PARTY_MSG_RESTORE_WHICH_MOVE        22
#define PARTY_MSG_BOOST_PP_WHICH_MOVE       23
#define PARTY_MSG_DO_WHAT_WITH_ITEM         24
#define PARTY_MSG_DO_WHAT_WITH_MAIL         25
#define PARTY_MSG_ALREADY_HOLDING_ONE       26
#define PARTY_MSG_MEGA_STONES_BANNED        27
#define PARTY_MSG_MEWTWO_MEGA_STONES_BANNED 28
#define PARTY_MSG_NONE                      127

// IDs for DisplayPartyPokemonDescriptionText, to display a message in the party pokemon's box
#define PARTYBOX_DESC_NO_USE      0
#define PARTYBOX_DESC_ABLE_3      1
#define PARTYBOX_DESC_FIRST       2
#define PARTYBOX_DESC_SECOND      3
#define PARTYBOX_DESC_THIRD       4
#define PARTYBOX_DESC_FOURTH      5
#define PARTYBOX_DESC_ABLE        6
#define PARTYBOX_DESC_NOT_ABLE    7
#define PARTYBOX_DESC_ABLE_2      8
#define PARTYBOX_DESC_NOT_ABLE_2  9
#define PARTYBOX_DESC_LEARNED     10
#define PARTYBOX_DESC_HAVE        11
#define PARTYBOX_DESC_DONT_HAVE   12

#define SELECTWINDOW_ACTIONS  0
#define SELECTWINDOW_ITEM     1
#define SELECTWINDOW_MAIL     2
#define SELECTWINDOW_MOVES    3

#endif // GUARD_CONSTANTS_PARTY_MENU_H
