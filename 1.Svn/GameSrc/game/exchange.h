bool		AddItem(TItemPos item_pos, BYTE display_pos

//aratt,

bool		AddItem(TItemPos item_pos, BYTE display_pos, short rent);

//değiştir

	private:
		CExchange *	m_pCompany;	// »ó´ë¹æÀÇ CExchange Æ÷ÀÎÅÍ

		LPCHARACTER	m_pOwner;

		TItemPos		m_aItemPos[EXCHANGE_ITEM_MAX_NUM];
		LPITEM		m_apItems[EXCHANGE_ITEM_MAX_NUM];
		BYTE		m_abItemDisplayPos[EXCHANGE_ITEM_MAX_NUM];
		
//aratt,

		DWORD		m_ItemRents[EXCHANGE_ITEM_MAX_NUM];

//altına ekle