void CPythonExchange::SetItemMetinSocketToSelf(int pos, int imetinpos, DWORD vnum)
{
	if (pos >= EXCHANGE_ITEM_MAX_NUM)
		return;

	m_self.item_metin[pos][imetinpos] = vnum;
}

//arat

void CPythonExchange::SetItemRentTimeToSelf(int pos, DWORD rent)
{
	if (pos >= EXCHANGE_ITEM_MAX_NUM)
		return;
	
	m_self.item_rent[pos] = rent;
}

void CPythonExchange::SetItemRentTimeToTarget(int pos, DWORD rent)
{
	if (pos >= EXCHANGE_ITEM_MAX_NUM)
		return;

	m_victim.item_rent[pos] = rent;
}

**//Altýna Ekle

DWORD CPythonExchange::GetItemMetinSocketFromSelf(BYTE pos, int iMetinSocketPos)
{
	if (pos >= EXCHANGE_ITEM_MAX_NUM)
		return 0;

	return m_self.item_metin[pos][iMetinSocketPos];
}

//arat

DWORD CPythonExchange::GetItemRentTimeFromSelf(BYTE pos)
{
	if (pos >= EXCHANGE_ITEM_MAX_NUM)
		return 0;
	
	return m_self.item_rent[pos];
}

DWORD CPythonExchange::GetItemRentTimeFromTarget(BYTE pos)
{
	if (pos >= EXCHANGE_ITEM_MAX_NUM)
		return 0;

	return m_victim.item_rent[pos];
}

**//Altýna Ekle

