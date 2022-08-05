		self.GetChild("mall_safebox_button").SAFE_SetEvent(self.__ClickInGameMallButton)
//arat

		self.GetChild("rent_item_button").SAFE_SetEvent(self.__ClickRentItemButton)
			
//altına ekle

	def __ClickInGameMallButton(self):
		self.Close()
		net.SendChatPacket("/click_mall")
//arat

	def __ClickRentItemButton(self):
		self.Close()
		event.QuestButtonClick(constInfo.RENT_ITEM_Q_INDEX)
		
//altına ekle

