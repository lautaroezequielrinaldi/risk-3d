#include "itemhandler.h"

const int ItemHandler::INVALID_ID = -1;
const int ItemHandler::ID_NOT_SELECTED = 0;

int ItemHandler::itemIdCount = ItemHandler::ID_NOT_SELECTED;

int ItemHandler::generateNextItemId() {
	ItemHandler::itemIdCount++;
	return ItemHandler::itemIdCount;
}

