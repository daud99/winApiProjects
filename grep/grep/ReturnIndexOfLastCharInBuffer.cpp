#include "stdafx.h"

DWORD ReturnIndexOfLastCharInBuffer(BYTE* buffer)
{
	DWORD i = 0;
	while(((buffer[i] != '\0') || buffer[i+1] != '\0') && ++i);
	return i;
}