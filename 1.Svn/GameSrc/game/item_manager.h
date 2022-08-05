class ITEM_MANAGER : public singleton<ITEM_MANAGER>
{
	public:
		ITEM_MANAGER();
		virtual ~ITEM_MANAGER();

//aratt,

		int				DeleteRentItems(DWORD ch_owner);
		bool			HasRentItemRenter(DWORD ch_renter);

//altına ekle

