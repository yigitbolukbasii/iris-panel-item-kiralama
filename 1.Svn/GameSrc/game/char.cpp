void CHARACTER::OpenMyShop(const char * c_pszSign, TShopItemTable * pTable, short bItemCount)
{
	[....]
	
	
	std::set<TItemPos> cont;
	for (short i = 0; i < bItemCount; ++i)
	{
		if (cont.find((pTable + i)->pos) != cont.end())
		{
			sys_err("MYSHOP: duplicate shop item detected! (name: %s)", GetName());
			return;
		}

		// ANTI_GIVE, ANTI_MYSHOP check
		LPITEM pkItem = GetItem((pTable + i)->pos);

		if (pkItem)
		{
		
//ARat


			if (pkItem->IsRentItem())
			{
				ChatPacket(CHAT_TYPE_INFO, LC_TEXT("RENT_ITEM_WARNING_MYSHOP"));
				return;
			}
//altýna ekle

void CHARACTER::OpenMyOfflineShop(const char * c_pszSign, TOfflineShopItemTable * pTable, BYTE bItemCount, BYTE bTime)
{
	[......]
	for (BYTE i = 0; i < bItemCount; ++i)
	{
		if (cont.find((pTable + i)->pos) != cont.end())
		{
			sys_err("MY_OFFLINE_SHOP: duplicate shop item detected! (name: %s)", GetName());
			return;
		}

		// ANTI_GIVE, ANTI_MYSHOP check
		LPITEM pkItem = GetItem((pTable + i)->pos);

		if (pkItem)
		{

// Arat

			if (pkItem->IsRentItem())
			{
				ChatPacket(CHAT_TYPE_INFO, LC_TEXT("RENT_ITEM_WARNING_MYSHOP"));
				return;
			}
//altýna ekle