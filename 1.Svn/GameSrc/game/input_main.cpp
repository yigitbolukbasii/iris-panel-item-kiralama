void CInputMain::SafeboxCheckin(LPCHARACTER ch, const char * c_pData)
{
//arat

	if (pkItem->IsRentItem())
	{
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("RENT_ITEM_SAFEBOX_CHECK_IN"));
		return;
	}
	
**//altına ekle

void CInputMain::Refine(LPCHARACTER ch, const char* c_pData)
{
	
//arat

	if (item->IsRentItem())
	{
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("RENT_ITEM_WARNING_UPGRADE"));
		ch->ClearRefineMode();
		return;
	}
**//altına ekle