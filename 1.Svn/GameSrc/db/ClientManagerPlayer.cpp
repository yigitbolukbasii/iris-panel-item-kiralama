bool CreateItemTableFromRes(MYSQL_RES * res, std::vector<TPlayerItem> * pVec, DWORD dwPID)
{
	if (!res)
	{
		pVec->clear();
		return true;
	}

	int rows;

	if ((rows = mysql_num_rows(res)) <= 0)	// µ•¿Ã≈Õ æ¯¿Ω
	{
		pVec->clear();
		return true;
	}

	pVec->resize(rows);

	for (int i = 0; i < rows; ++i)
	{
		MYSQL_ROW row = mysql_fetch_row(res);
		TPlayerItem & item = pVec->at(i);

		int cur = 0;

		// Check all SELECT syntax on item table before change this function!!!
		// Check all SELECT syntax on item table before change this function!!!
		// Check all SELECT syntax on item table before change this function!!!
		str_to_number(item.id, row[cur++]);
		str_to_number(item.window, row[cur++]);
		str_to_number(item.pos, row[cur++]);
		str_to_number(item.count, row[cur++]);
		str_to_number(item.vnum, row[cur++]);
//arat

		str_to_number(item.dwRentTime, row[cur++]);
		str_to_number(item.dwRentOwner, row[cur++]);

//alt˝na ekle.

void CClientManager::QUERY_PLAYER_LOAD(CPeer * peer, DWORD dwHandle, TPlayerLoadPacket * packet)
{
	CPlayerTableCache * c;
	TPlayerTable * pTab;
	
	//
	// «— ∞Ë¡§ø° º”«— ∏µÁ ƒ≥∏Ø≈ÕµÈ ƒ≥Ω¨√≥∏Æ
	//
	CLoginData * pLoginData = GetLoginDataByAID(packet->account_id);

	if (pLoginData)
	{
		for (int n = 0; n < PLAYER_PER_ACCOUNT; ++n)
			if (pLoginData->GetAccountRef().players[n].dwID != 0)
				DeleteLogoutPlayer(pLoginData->GetAccountRef().players[n].dwID);
	}

	//----------------------------------------------------------------
	// 1. ¿Ø¿˙¡§∫∏∞° DBCache ø° ¡∏¿Á : DBCacheø°º≠ 
	// 2. ¿Ø¿˙¡§∫∏∞° DBCache ø° æ¯¿Ω : DBø°º≠ 
	// ---------------------------------------------------------------
	
	//----------------------------------
	// 1. ¿Ø¿˙¡§∫∏∞° DBCache ø° ¡∏¿Á : DBCacheø°º≠ 
	//----------------------------------
	if ((c = GetPlayerCache(packet->player_id)))
	{
		CLoginData * pkLD = GetLoginDataByAID(packet->account_id);

		if (!pkLD || pkLD->IsPlay())
		{
			sys_log(0, "PLAYER_LOAD_ERROR: LoginData %p IsPlay %d", pkLD, pkLD ? pkLD->IsPlay() : 0);
			peer->EncodeHeader(HEADER_DG_PLAYER_LOAD_FAILED, dwHandle, 0); 
			return;
		}

		pTab = c->Get();

		pkLD->SetPlay(true);
		SendLoginToBilling(pkLD, true);

		peer->EncodeHeader(HEADER_DG_PLAYER_LOAD_SUCCESS, dwHandle, sizeof(TPlayerTable));
		peer->Encode(pTab, sizeof(TPlayerTable));

		if (packet->player_id != pkLD->GetLastPlayerID())
		{
			TPacketNeedLoginLogInfo logInfo;
			logInfo.dwPlayerID = packet->player_id;

			pkLD->SetLastPlayerID( packet->player_id );

			peer->EncodeHeader( HEADER_DG_NEED_LOGIN_LOG, dwHandle, sizeof(TPacketNeedLoginLogInfo) );
			peer->Encode( &logInfo, sizeof(TPacketNeedLoginLogInfo) );
		}

		char szQuery[1024] = { 0, };

		TItemCacheSet * pSet = GetItemCacheSet(pTab->id);

		sys_log(0, "[PLAYER_LOAD] ID %s pid %d gold %lld ", pTab->name, pTab->id, pTab->gold);

		//--------------------------------------------
		// æ∆¿Ã≈€ & AFFECT & QUEST ∑Œµ˘ : 
		//--------------------------------------------
		// 1) æ∆¿Ã≈€¿Ã DBCache ø° ¡∏¿Á : DBCache ø°º≠ ∞°¡Æø»
		// 2) æ∆¿Ã≈€¿Ã DBCache ø° æ¯¿Ω : DB ø°º≠ ∞°¡Æø» 

		/////////////////////////////////////////////
		// 1) æ∆¿Ã≈€¿Ã DBCache ø° ¡∏¿Á : DBCache ø°º≠ ∞°¡Æø»
		/////////////////////////////////////////////
		if (pSet)
		{
			static std::vector<TPlayerItem> s_items;
			s_items.resize(pSet->size());

			DWORD dwCount = 0;
			TItemCacheSet::iterator it = pSet->begin();

			while (it != pSet->end())
			{
				CItemCache * c = *it++;
				TPlayerItem * p = c->Get();

				if (p->vnum) // vnum¿Ã æ¯¿∏∏È ªË¡¶µ» æ∆¿Ã≈€¿Ã¥Ÿ.
					thecore_memcpy(&s_items[dwCount++], p, sizeof(TPlayerItem));
			}

			if (g_test_server)
				sys_log(0, "ITEM_CACHE: HIT! %s count: %u", pTab->name, dwCount);

			peer->EncodeHeader(HEADER_DG_ITEM_LOAD, dwHandle, sizeof(DWORD) + sizeof(TPlayerItem) * dwCount);
			peer->EncodeDWORD(dwCount);

			if (dwCount)
				peer->Encode(&s_items[0], sizeof(TPlayerItem) * dwCount);

			// Quest
			snprintf(szQuery, sizeof(szQuery),
					"SELECT dwPID,szName,szState,lValue FROM quest%s WHERE dwPID=%d AND lValue<>0",
					GetTablePostfix(), pTab->id);
			
			CDBManager::instance().ReturnQuery(szQuery, QID_QUEST, peer->GetHandle(), new ClientHandleInfo(dwHandle,0,packet->account_id));

			// Affect
			snprintf(szQuery, sizeof(szQuery),
					"SELECT dwPID,bType,bApplyOn,lApplyValue,dwFlag,lDuration,lSPCost FROM affect%s WHERE dwPID=%d",
					GetTablePostfix(), pTab->id);
			CDBManager::instance().ReturnQuery(szQuery, QID_AFFECT, peer->GetHandle(), new ClientHandleInfo(dwHandle, pTab->id));
		}
		/////////////////////////////////////////////
		// 2) æ∆¿Ã≈€¿Ã DBCache ø° æ¯¿Ω : DB ø°º≠ ∞°¡Æø» 
		/////////////////////////////////////////////
		else
		{
			snprintf(szQuery, sizeof(szQuery), 
					"SELECT id,window+0,pos,count,vnum,socket0,socket1,socket2,attrtype0,attrvalue0,attrtype1,attrvalue1,attrtype2,attrvalue2,attrtype3,attrvalue3,attrtype4,attrvalue4,attrtype5,attrvalue5,attrtype6,attrvalue6 "
					"FROM item%s WHERE owner_id=%d AND (window < %d)",
					GetTablePostfix(), pTab->id, SAFEBOX);

///arat

					"SELECT id,window+0,pos,count,vnum,renttime,rentowner,socket0,socket1,socket2,attrtype0,attrvalue0,attrtype1,attrvalue1,attrtype2,attrvalue2,attrtype3,attrvalue3,attrtype4,attrvalue4,attrtype5,attrvalue5,attrtype6,attrvalue6 "
		
		//dei˛tir..
		
		
		ClientHandleInfo * pkInfo = new ClientHandleInfo(dwHandle, packet->player_id);
		pkInfo->account_id = packet->account_id;
		CDBManager::instance().ReturnQuery(queryStr, QID_PLAYER, peer->GetHandle(), pkInfo);

		//--------------------------------------------------------------
		// æ∆¿Ã≈€ ∞°¡Æø¿±‚ 
		//--------------------------------------------------------------
		snprintf(queryStr, sizeof(queryStr),
				"SELECT id,window+0,pos,count,vnum,socket0,socket1,socket2,attrtype0,attrvalue0,attrtype1,attrvalue1,attrtype2,attrvalue2,attrtype3,attrvalue3,attrtype4,attrvalue4,attrtype5,attrvalue5,attrtype6,attrvalue6 "
				"FROM item%s WHERE owner_id=%d AND (window < %d)",
				GetTablePostfix(), packet->player_id, SAFEBOX);
		CDBManager::instance().ReturnQuery(queryStr, QID_ITEM, peer->GetHandle(), new ClientHandleInfo(dwHandle, packet->player_id));
		
		//iÁinde arat
			
				"SELECT id,window+0,pos,count,vnum,renttime,rentowner,socket0,socket1,socket2,attrtype0,attrvalue0,attrtype1,attrvalue1,attrtype2,attrvalue2,attrtype3,attrvalue3,attrtype4,attrvalue4,attrtype5,attrvalue5,attrtype6,attrvalue6 "
				
				//dei˛tir..
				
		
		