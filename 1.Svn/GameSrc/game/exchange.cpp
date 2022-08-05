	if (sub_header == EXCHANGE_SUBHEADER_GC_ITEM_ADD && pvData)
	{
		thecore_memcpy(&pack_exchg.alSockets, ((LPITEM) pvData)->GetSockets(), sizeof(pack_exchg.alSockets));
		thecore_memcpy(&pack_exchg.aAttr, ((LPITEM) pvData)->GetAttributes(), sizeof(pack_exchg.aAttr));
//arat

		pack_exchg.arg4 = ((LPITEM) pvData)->GetRentTime();
//altına ekle

	else
	{
		memset(&pack_exchg.alSockets, 0, sizeof(pack_exchg.alSockets));
		memset(&pack_exchg.aAttr, 0, sizeof(pack_exchg.aAttr));
//arat 

		pack_exchg.arg4 = 0;
//altına ekle var ise değiştir..

bool CExchange::AddItem(TItemPos item_pos, BYTE display_pos)

//arat

bool CExchange::AddItem(TItemPos item_pos, BYTE display_pos, short rent)

//değiştir

bool CExchange::AddItem(TItemPos item_pos, BYTE display_pos, short rent)
//arat

	if (item->IsRentItem())
	{
		m_pOwner->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("RENT_ITEM_WARNING_EXCHANGE"));
		return false;
	}

//içerisine ekle

	for (int i = 0; i < EXCHANGE_ITEM_MAX_NUM; ++i)
	{
		if (m_apItems[i])
			continue;

		m_apItems[i]		= item;
		m_aItemPos[i]		= item_pos;
		m_abItemDisplayPos[i]	= display_pos;
		m_pGrid->Put(display_pos, 1, item->GetSize());

		item->SetExchanging(true);
//arat

		switch(rent)
		{
			case 1:
				item->SetRentTime(time(0) + 900);	/* 15 Min */
				m_ItemRents[i] = time(0) + 900;
				break;
			case 2:
				item->SetRentTime(time(0) + 21600);	/* 6 Hour */
				m_ItemRents[i] = time(0) + 21600;
				break;
			case 3:
				item->SetRentTime(time(0) + 43200);	/* 12 Hour */
				m_ItemRents[i] = time(0) + 43200;
				break;
			case 4:
				item->SetRentTime(time(0) + 86400);	/* 1 Day */
				m_ItemRents[i] = time(0) + 86400;
				break;
			case 5:
				item->SetRentTime(time(0) + 259200);	/* 3 Day */
				m_ItemRents[i] = time(0) + 259200;
				break;
			case 6:
				item->SetRentTime(time(0) + 604800);	/* 7 Day */
				m_ItemRents[i] = time(0) + 604800;
				break;
			case 7:
				item->SetRentTime(time(0) + 1209600);	/* 14 Day */
				m_ItemRents[i] = time(0) + 1209600;
				break;
		}
//altına ekle


bool CExchange::Done()
{
	int		empty_pos, i;
	LPITEM	item;

	LPCHARACTER	victim = GetCompany()->GetOwner();

	for (i = 0; i < EXCHANGE_ITEM_MAX_NUM; ++i)
	{
//arat

		if (m_ItemRents[i] > 0)
		{
			char szColumns[QUERY_MAX_LEN], szValues[QUERY_MAX_LEN];
			int iLen = snprintf(szColumns, sizeof(szColumns), "owner_id,item_id,rent,target_id");
			int iUpdateLen = snprintf(szValues, sizeof(szValues), "%u,%u,%d,%u", m_pOwner->GetPlayerID(), item->GetID(), item->GetRentTime(), victim->GetPlayerID());
			char szInsertQuery[QUERY_MAX_LEN];
			snprintf(szInsertQuery, sizeof(szInsertQuery), "INSERT INTO player.rent_event (%s) VALUES (%s)", szColumns, szValues);
			std::auto_ptr<SQLMsg> pMsg(DBManager::instance().DirectQuery(szInsertQuery));
			
			item->SetRentTime(m_ItemRents[i]);
			item->SetRentOwner(m_pOwner->GetPlayerID());
			item->StartRentTimeExpireEvent();
		}
		
//altına ekle

