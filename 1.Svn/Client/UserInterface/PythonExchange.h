		typedef struct trade
		{
			char					name[CHARACTER_NAME_MAX_LEN + 1];

			DWORD					item_vnum[EXCHANGE_ITEM_MAX_NUM];
			short					item_count[EXCHANGE_ITEM_MAX_NUM];
			DWORD					item_metin[EXCHANGE_ITEM_MAX_NUM][ITEM_SOCKET_SLOT_MAX_NUM];

//arat

			DWORD					item_rent[EXCHANGE_ITEM_MAX_NUM];

//altýna ekle


		void			SetItemMetinSocketToTarget(int pos, int imetinpos, DWORD vnum);
		void			SetItemMetinSocketToSelf(int pos, int imetinpos, DWORD vnum);
//arat

		void			SetItemRentTimeToSelf(int pos, DWORD rent);
		void			SetItemRentTimeToTarget(int pos, DWORD rent);

//altýna ekle


		DWORD			GetItemMetinSocketFromTarget(BYTE pos, int iMetinSocketPos);
		DWORD			GetItemMetinSocketFromSelf(BYTE pos, int iMetinSocketPos);
		
//arat

		DWORD			GetItemRentTimeFromSelf(BYTE pos);
		DWORD			GetItemRentTimeFromTarget(BYTE pos);

//altýna ekle

