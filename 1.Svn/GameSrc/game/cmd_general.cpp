ACMD(do_get_rent_items)
{
	char szQuery[1024];
	snprintf(szQuery, sizeof(szQuery), "SELECT id,count,vnum,socket0,socket1,socket2,socket3,socket4,socket5,attrtype0,attrvalue0,attrtype1,attrvalue1,attrtype2,attrvalue2,attrtype3,attrvalue3,attrtype4,attrvalue4,attrtype5,attrvalue5,attrtype6,attrvalue6 FROM %sitem_rent WHERE owner_id = %u",get_table_postfix(), ch->GetPlayerID());
	std::auto_ptr<SQLMsg> pMsg(DBManager::instance().DirectQuery(szQuery));
	if (pMsg->Get()->uiNumRows == 0)
	{
		sys_log(0, "do_get_rent_items - This slot is empty! [%s]", ch->GetName());
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("ITEM_RENT_EMPTY_TABLE"));
		return;
	}
	
	MYSQL_ROW row;
	while (NULL != (row = mysql_fetch_row(pMsg->Get()->pSQLResult)))
	{
		TPlayerItem item;
		str_to_number(item.id, row[0]);
		str_to_number(item.count, row[1]);
		str_to_number(item.vnum, row[2]);
		str_to_number(item.alSockets[0], row[3]);
		str_to_number(item.alSockets[1], row[4]);
		str_to_number(item.alSockets[2], row[5]);
		str_to_number(item.alSockets[3], row[6]);
		str_to_number(item.alSockets[4], row[7]);
		str_to_number(item.alSockets[5], row[8]);
		for (int i=0, iStartAttributeType=9, iStartAttributeValue=10; i < ITEM_ATTRIBUTE_MAX_NUM; ++i, iStartAttributeType += 2, iStartAttributeValue += 2)
		{
			str_to_number(item.aAttr[i].bType, row[iStartAttributeType]);
			str_to_number(item.aAttr[i].sValue, row[iStartAttributeValue]);
		}

		LPITEM pItem = ITEM_MANAGER::instance().CreateItem(item.vnum, item.count);
		if (pItem)
		{
			int iEmptyPos = ch->GetEmptyInventory(pItem->GetSize());
			
			if (iEmptyPos < 0)
			{
				ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("You don't have enough space for store the item!"));
				return;
			}
			
			pItem->SetSockets(item.alSockets);
			pItem->SetAttributes(item.aAttr);
			
			pItem->AddToCharacter(ch, TItemPos(INVENTORY, iEmptyPos));
			
			ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("ITEM_RENT_%s_REWARD"),pItem->GetName());
			DBManager::instance().DirectQuery("DELETE FROM %sitem_rent WHERE owner_id = %u AND id = %u", get_table_postfix(), ch->GetPlayerID(), item.id);
		}
	}
}

sonuna ekle

