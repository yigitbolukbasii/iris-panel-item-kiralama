	def SetInventoryItem(self, slotIndex, window_type = player.INVENTORY):
//arat

		self.__AppendRentInformation(player.INVENTORY, slotIndex)
			
//altına ekle

	def SetExchangeOwnerItem(self, slotIndex):
//arat

		self.__AppendRentInformation(10, slotIndex)		
//altına ekle


	def SetExchangeTargetItem(self, slotIndex):
//arat
		self.__AppendRentInformation(11, slotIndex)
//altına ekle

	def __AppendFishInfo(self, size):
		if size > 0:
			self.AppendSpace(5)
			self.AppendTextLine(localeInfo.TOOLTIP_FISH_LEN % (float(size) / 100.0), self.NORMAL_COLOR)
//arat

	def __AppendRentInformation(self, window_type, slotIndex):
		if window_type == player.INVENTORY:
			if player.GetItemRentTime(slotIndex) <= 1:
				rent = player.GetItemRentTime(slotIndex)
			else:
				rent = max(0, player.GetItemRentTime(slotIndex) - app.GetGlobalTimeStamp())
		elif window_type == 10:
			if exchange.GetItemRentTimeFromSelf(slotIndex) <= 1:
				rent = exchange.GetItemRentTimeFromSelf(slotIndex)
			else:
				rent = max(0, exchange.GetItemRentTimeFromSelf(slotIndex) - app.GetGlobalTimeStamp())
		elif window_type == 11:
			if exchange.GetItemRentTimeFromTarget(slotIndex) <= 1:
				rent = exchange.GetItemRentTimeFromTarget(slotIndex)
			else:
				rent = max(0, exchange.GetItemRentTimeFromTarget(slotIndex) - app.GetGlobalTimeStamp())				
			
		if rent == 0:
			return
		elif rent > 0:
			self.AppendSpace(5)
			hrs = rent / 3600
			rent -= 3600 * hrs
			mins = rent / 60
			rent -= 60 * mins
			self.AppendSpace(5)
			self.AppendTextLine(localeInfo.TOOLTIP_RENT, self.NORMAL_COLOR) 
			self.AppendSpace(5)
			self.AppendTextLine(localeInfo.TOOLTIP_RENT_LEFT_TIME % (hrs, mins), self.NORMAL_COLOR)
			
//altına ekle

