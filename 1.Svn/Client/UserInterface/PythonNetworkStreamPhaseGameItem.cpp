bool CPythonNetworkStream::RecvSafeBoxSetPacket()
{
//arat

	kItemData.renttime = kItemSet.renttime;
//altna ekle


bool CPythonNetworkStream::RecvMallItemSetPacket()
{

//arat

	kItemData.renttime = kItemSet.renttime;

//altna ekle

bool CPythonNetworkStream::RecvItemSetPacket2()
{

//arat

	kItemData.renttime = packet_item_set.renttime;
	
//altna ekle

bool CPythonNetworkStream::RecvItemUpdatePacket()
{

//arat

	rkPlayer.SetItemRentTime(packet_item_update.Cell, packet_item_update.renttime);
	
//altna ekle

