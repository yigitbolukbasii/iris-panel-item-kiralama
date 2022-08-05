		void		StartRealTimeExpireEvent();

//aratt,

		void		StartRentTimeExpireEvent();
		bool		IsRentItem();
		void		SetRentTime(DWORD rent);
		void		SetRentOwner(DWORD owner);
		DWORD		GetRentTime();
		DWORD		GetRentOwner();

//altına ekle

		DWORD		m_dwMaskVnum;
		DWORD		m_dwSIGVnum;
		
//aratt,

		DWORD		m_dwRentTime;
		DWORD		m_dwRentOwner;
		LPEVENT		m_pkRentTimeExpireEvent;

//altına ekle

