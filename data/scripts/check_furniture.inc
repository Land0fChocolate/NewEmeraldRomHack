EventScript_PictureBookShelf::
	msgbox Text_PictureBookShelf, MSGBOX_SIGN
	end

EventScript_BookShelf::
	msgbox Text_BookShelf, MSGBOX_SIGN
	end

EventScript_PokemonCenterBookShelf::
	msgbox Text_PokemonCenterBookShelf, MSGBOX_SIGN
	end

EventScript_Vase::
	msgbox Text_Vase, MSGBOX_SIGN
	end

EventScript_EmptyTrashCan::
	msgbox Text_EmptyTrashCan, MSGBOX_SIGN
	end

EventScript_ShopShelf::
	msgbox Text_ShopShelf, MSGBOX_SIGN
	end

EventScript_SweetShopShelf::
	msgbox Text_SweetShopShelf, MSGBOX_SIGN
	end

EventScript_Blueprint::
	msgbox Text_Blueprint, MSGBOX_SIGN
	end

EventScript_BambooTree::
	msgbox Text_BambooTree, MSGBOX_SIGN
	checkitem ITEM_WISH_TAG, 1
	compare VAR_RESULT, TRUE
	goto_if_eq SlateportCity_EventScript_BambooTree_PlaceWishTag
	end
