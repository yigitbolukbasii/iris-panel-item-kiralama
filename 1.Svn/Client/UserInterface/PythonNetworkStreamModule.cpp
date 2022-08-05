PyObject* netSendExchangeItemAddPacket(PyObject* poSelf, PyObject* poArgs)
{
	BYTE bWindowType;
	if (!PyTuple_GetInteger(poArgs, 0, &bWindowType))
		return Py_BuildException();
	WORD wSlotIndex;
	if (!PyTuple_GetInteger(poArgs, 1, &wSlotIndex))
		return Py_BuildException();
	int iDisplaySlotIndex;
	if (!PyTuple_GetInteger(poArgs, 2, &iDisplaySlotIndex))
		return Py_BuildException();

	CPythonNetworkStream& rkNetStream=CPythonNetworkStream::Instance();
	rkNetStream.SendExchangeItemAddPacket(TItemPos(bWindowType, wSlotIndex), iDisplaySlotIndex);
	return Py_BuildNone();
}

//arat

PyObject* netSendExchangeItemAddPacket(PyObject* poSelf, PyObject* poArgs)
{
	BYTE bWindowType;
	if (!PyTuple_GetInteger(poArgs, 0, &bWindowType))
		return Py_BuildException();
	WORD wSlotIndex;
	if (!PyTuple_GetInteger(poArgs, 1, &wSlotIndex))
		return Py_BuildException();
	int iDisplaySlotIndex;
	if (!PyTuple_GetInteger(poArgs, 2, &iDisplaySlotIndex))
		return Py_BuildException();
	int rent;
	if (!PyTuple_GetInteger(poArgs, 3, &rent))
		return Py_BuildException();

	CPythonNetworkStream& rkNetStream=CPythonNetworkStream::Instance();
	rkNetStream.SendExchangeItemAddPacket(TItemPos(bWindowType, wSlotIndex), iDisplaySlotIndex, rent);
	return Py_BuildNone();
}

//deðiþtir


