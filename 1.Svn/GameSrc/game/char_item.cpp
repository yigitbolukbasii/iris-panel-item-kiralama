			pack.count = pItem->GetCount();
			pack.vnum = pItem->GetVnum();		
//ARat


			pack.renttime = pItem->GetRentTime();
//alt�na ekle

					case USE_DETACHMENT:
						{

// Arat

							if (item2->IsRentItem())
							{
								ChatPacket(CHAT_TYPE_INFO, LC_TEXT("RENT_ITEM_WARNING_CLEAN_SOCKET"));
								return false;
							}
//alt�na ekle

					case USE_ADD_ATTRIBUTE2:
						{
//arat

							if (item2->IsRentItem())
							{
								ChatPacket(CHAT_TYPE_INFO, LC_TEXT("RENT_ITEM_WARNING_USE_TYPES"));
								return false;
							}
//alt�na ekle

	case ITEM_METIN:
			{
//arat

				if (item2->IsRentItem())
				{
					ChatPacket(CHAT_TYPE_INFO, LC_TEXT("RENT_ITEM_WARNING_ADD_SOCKET"));
					return false;
				}

///alt�na ekle

bool CHARACTER::DropItem(TItemPos Cell, short bCount)
{
	
//arat

	if (item->IsRentItem())
	{
		ChatPacket(CHAT_TYPE_INFO, LC_TEXT("RENT_ITEM_WARNING_DROP_ITEM"));
		return false;
	}
				