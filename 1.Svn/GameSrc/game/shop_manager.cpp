void CShopManager::Sell(LPCHARACTER ch, UINT bCell, short bCount)
{
//arat

	if (item->IsRentItem())
	{
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("RENT_ITEM_WARNING_SELL"));
		return;
	}
	
**//altına ekle