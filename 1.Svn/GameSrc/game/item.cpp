m_pkAccessorySocketExpireEvent(NULL),
//arat

	m_dwRentTime(0), m_dwRentOwner(0), m_pkRentTimeExpireEvent(NULL),
	
**//yanına ekle

void CItem::Initialize()
{
	
//arat

	m_dwRentTime = 0;
	m_dwRentOwner = 0;
	m_pkRentTimeExpireEvent = NULL;
**//altına ekle

void CItem::Destroy()
{
	
//arat

	event_cancel(&m_pkRentTimeExpireEvent);
	
**//altına ekle

void CItem::UpdatePacket()
{
//arat

	pack.renttime = m_dwRentTime;

**//altına ekle


bool CItem::IsRealTimeItem()
{
	if(!GetProto())
		return false;
	for (int i=0 ; i < ITEM_LIMIT_MAX_NUM ; i++)
	{
		if (LIMIT_REAL_TIME == GetProto()->aLimits[i].bType)
			return true;
	}
	return false;
}

//arat

EVENTFUNC(rent_time_expire_event)
{
	const item_vid_event_info* info = reinterpret_cast<const item_vid_event_info*>(event->info);
	
	if (NULL == info)
		return 0;

	const LPITEM item = ITEM_MANAGER::instance().FindByVID( info->item_vid );
	
	if (NULL == item)
		return 0;

	const time_t current = get_global_time();

	if (current > item->GetRentTime())
	{
		char szColumns[QUERY_MAX_LEN], szValues[QUERY_MAX_LEN];
		int iLen = snprintf(szColumns, sizeof(szColumns), "id,owner_id,count,vnum");
		int iUpdateLen = snprintf(szValues, sizeof(szValues), "%u,%u,%u,%u", item->GetID(), item->GetRentOwner(), item->GetCount(), item->GetVnum());
		iLen += snprintf(szColumns + iLen, sizeof(szColumns) - iLen, ",socket0,socket1,socket2,socket3,socket4,socket5");
		iUpdateLen += snprintf(szValues + iUpdateLen, sizeof(szValues) - iUpdateLen, ",%ld,%ld,%ld,%ld,%ld,%ld", item->GetSocket(0), item->GetSocket(1), item->GetSocket(2), item->GetSocket(3), item->GetSocket(4), item->GetSocket(5));	
		iLen += snprintf(szColumns + iLen, sizeof(szColumns) - iLen, ",attrtype0,attrvalue0,attrtype1,attrvalue1,attrtype2,attrvalue2,attrtype3,attrvalue3,attrtype4,attrvalue4,attrtype5,attrvalue5,attrtype6,attrvalue6");
		iUpdateLen += snprintf(szValues + iUpdateLen, sizeof(szValues) - iUpdateLen, ",%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
			item->GetAttributeType(0), item->GetAttributeValue(0),
			item->GetAttributeType(1), item->GetAttributeValue(1),
			item->GetAttributeType(2), item->GetAttributeValue(2),
			item->GetAttributeType(3), item->GetAttributeValue(3),
			item->GetAttributeType(4), item->GetAttributeValue(4),
			item->GetAttributeType(5), item->GetAttributeValue(5),
			item->GetAttributeType(6), item->GetAttributeValue(6));
			
		char szInsertQuery[QUERY_MAX_LEN];
		snprintf(szInsertQuery, sizeof(szInsertQuery), "INSERT INTO %sitem_rent (%s) VALUES (%s)", get_table_postfix(), szColumns, szValues);
		std::auto_ptr<SQLMsg> pMsg(DBManager::instance().DirectQuery(szInsertQuery));
		DBManager::instance().DirectQuery("DELETE FROM %srent_event WHERE owner_id = %u AND item_id = %u", get_table_postfix(), item->GetRentOwner(), item->GetID());
		item->RemoveFromCharacter();
	}
}

void CItem::StartRentTimeExpireEvent()
{
	if (m_pkRentTimeExpireEvent)
		return;
	
	item_vid_event_info * info = AllocEventInfo<item_vid_event_info>();
	info->item_vid = GetVID();
	m_pkRentTimeExpireEvent = event_create( rent_time_expire_event, info, PASSES_PER_SEC(1));
	return;
}

bool CItem::IsRentItem()
{
	if (GetRentTime() > 0)
		return true;
	
	return false;
}

void CItem::SetRentTime(DWORD rent)
{
	m_dwRentTime = rent;
	UpdatePacket();
	Save();
}

void CItem::SetRentOwner(DWORD owner)
{
	m_dwRentOwner = owner;
	UpdatePacket();
	Save();
}

DWORD CItem::GetRentTime()
{
	return m_dwRentTime;
}

DWORD CItem::GetRentOwner()
{
	return m_dwRentOwner;
}

**//altına ekle

bool CItem::OnAfterCreatedItem()
{
	
//arat

	if (GetRentTime() > 0)
		StartRentTimeExpireEvent();
	
**//altına ekle

