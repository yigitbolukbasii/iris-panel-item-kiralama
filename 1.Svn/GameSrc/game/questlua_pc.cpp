	int pc_set_race(lua_State* L)
	{
		int race = (int)lua_tonumber(L, -1);
		LPCHARACTER ch = CQuestManager::instance().GetCurrentCharacterPtr();
		ch->SetRace(race);
		return 0;
	}
//arat

	int pc_delete_rent_items(lua_State* L)
	{
		LPCHARACTER ch = CQuestManager::instance().GetCurrentCharacterPtr();
		int ret = ITEM_MANAGER::instance().DeleteRentItems(ch->GetPlayerID());
		if (ret == 0)
			lua_pushnumber(L, 0);
		else if (ret == 1)
			lua_pushnumber(L, 1);
		else
			lua_pushnumber(L, 2);
		return 1;
	}
	
**//altına ekle

	void RegisterPCFunctionTable()
	{
		luaL_reg pc_functions[] = 
		{
//arat

	{ "delete_rent_items",	pc_delete_rent_items		},

//**//altına ekle
