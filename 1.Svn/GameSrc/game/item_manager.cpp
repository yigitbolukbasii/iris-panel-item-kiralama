	t.id = item->GetID();
	t.window = item->GetWindow();
	t.pos = t.window == EQUIPMENT ? item->GetCell() - INVENTORY_MAX_NUM : item->GetCell();
	t.count = item->GetCount();
//arat

	t.dwRentTime = item->GetRentTime();
	t.dwRentOwner = item->GetRentOwner();
	
**//yanına ekle

void ITEM_MANAGER::SaveSingleItem(LPITEM item)
{
	[..]
}

//arat

int ITEM_MANAGER::DeleteRentItems(DWORD ch_owner)
{	
	std::auto_ptr<SQLMsg> pMsg(DBManager::instance().DirectQuery("SELECT id,pos,count,vnum,socket0,socket1,socket2,socket3,socket4,socket5,attrtype0,attrvalue0,attrtype1,attrvalue1,attrtype2,attrvalue2,attrtype3,attrvalue3,attrtype4,attrvalue4,attrtype5,attrvalue5,attrtype6,attrvalue6 FROM player.item WHERE rent_owner=%u",ch_owner));
	if (pMsg->Get()->uiNumRows == 0)
		return 0;
	
	MYSQL_ROW row;
	while (NULL != (row = mysql_fetch_row(pMsg->Get()->pSQLResult)))
	{
		DWORD item_id;
		str_to_number(item_id, row[0]);
		
		std::auto_ptr<SQLMsg> pMsgEvent(DBManager::instance().DirectQuery("SELECT item_id FROM %srent_event WHERE owner_id = '%d' AND rent < %u;", get_table_postfix(), ch_owner, time(0)));
		if (pMsgEvent->Get()->uiNumRows == 0)
			break;
		
		TPlayerItem t;
		
		t.id = item_id;
		t.window = MALL;
		str_to_number(t.pos, row[1]);
		str_to_number(t.count, row[2]);
		str_to_number(t.vnum, row[3]);
		t.sealbind = 0;
		t.dwRentTime = 0;
		t.dwRentOwner = 0;
		t.owner = ch_owner;
		str_to_number(t.alSockets[0], row[4]);
		str_to_number(t.alSockets[1], row[5]);
		str_to_number(t.alSockets[2], row[6]);
		str_to_number(t.alSockets[3], row[7]);
		str_to_number(t.alSockets[4], row[8]);
		str_to_number(t.alSockets[5], row[9]);
		for (int i=0, iStartAttributeType=10, iStartAttributeValue=11; i < ITEM_ATTRIBUTE_MAX_NUM; ++i, iStartAttributeType += 2, iStartAttributeValue += 2)
		{
			str_to_number(t.aAttr[i].bType, row[iStartAttributeType]);
			str_to_number(t.aAttr[i].sValue, row[iStartAttributeValue]);
		}

		db_clientdesc->DBPacketHeader(HEADER_GD_ITEM_SAVE, 0, sizeof(TPlayerItem));
		db_clientdesc->Packet(&t, sizeof(TPlayerItem));
		
		return 1;
	}
	
	return 0;
}

bool ITEM_MANAGER::HasRentItemRenter(DWORD ch_renter)
{
	std::auto_ptr<SQLMsg> pMsg(DBManager::instance().DirectQuery("SELECT id FROM player.item WHERE owner_id=%u AND rent_owner=!0",ch_renter));	
	if (pMsg->Get()->uiNumRows != 0)
		return 1;
	
	return 0;
}

**//altına ekle
