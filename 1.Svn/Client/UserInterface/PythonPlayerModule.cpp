void initPlayer()
{
//arat

PyObject * playerGetItemRentTime(PyObject* poSelf, PyObject* poArgs)
{
	switch (PyTuple_Size(poArgs))
	{
	case 1:
	{
		int iSlotIndex;
		if (!PyTuple_GetInteger(poArgs, 0, &iSlotIndex))
			return Py_BuildException();

		DWORD time = CPythonPlayer::Instance().GetItemRentTime(TItemPos(INVENTORY, iSlotIndex));
		return Py_BuildValue("i", time);
	}
	case 2:
	{
		TItemPos Cell;
		if (!PyTuple_GetByte(poArgs, 0, &Cell.window_type))
			return Py_BuildException();
		if (!PyTuple_GetInteger(poArgs, 1, &Cell.cell))
			return Py_BuildException();

		DWORD time = CPythonPlayer::Instance().GetItemRentTime(Cell);
		return Py_BuildValue("i", time);
	}
	default:
		return Py_BuildException();
	}
}

//üstüne ekle

void initPlayer()
{
	static PyMethodDef s_methods[] =
	{

//arat

		{ "GetItemRentTime",			playerGetItemRentTime,				METH_VARARGS },
		
//altına ekle

