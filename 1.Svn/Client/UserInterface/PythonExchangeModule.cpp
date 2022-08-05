PyObject * exchangeGetItemMetinSocketFromSelf(PyObject * poTarget, PyObject * poArgs)
{
	int pos;
	if (!PyTuple_GetInteger(poArgs, 0, &pos))
		return Py_BuildException();
	int iMetinSocketPos;
	if (!PyTuple_GetInteger(poArgs, 1, &iMetinSocketPos))
		return Py_BuildException();
	return Py_BuildValue("i", CPythonExchange::Instance().GetItemMetinSocketFromSelf(pos, iMetinSocketPos));
}

//arat


PyObject * exchangeGetItemRentTimeFromSelf(PyObject * poTarget, PyObject * poArgs)
{
	int pos;
	if (!PyTuple_GetInteger(poArgs, 0, &pos))
		return Py_BuildException();

	return Py_BuildValue("i", CPythonExchange::Instance().GetItemRentTimeFromSelf((char) pos));
}

PyObject * exchangeGetItemRentTimeFromTarget(PyObject * poTarget, PyObject * poArgs)
{
	int pos;
	if (!PyTuple_GetInteger(poArgs, 0, &pos))
		return Py_BuildException();

	return Py_BuildValue("i", CPythonExchange::Instance().GetItemRentTimeFromTarget((char) pos));
}

//altına ekle
	
		{"GetItemMetinSocketFromTarget",	exchangeGetItemMetinSocketFromTarget,	METH_VARARGS},
		{"GetItemMetinSocketFromSelf",		exchangeGetItemMetinSocketFromSelf,		METH_VARARGS},

//arat
	
		{"GetItemRentTimeFromSelf", exchangeGetItemRentTimeFromSelf,	METH_VARARGS},
		{"GetItemRentTimeFromTarget", exchangeGetItemRentTimeFromTarget,	METH_VARARGS},

//altına ekle

