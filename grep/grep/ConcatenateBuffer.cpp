#include "stdafx.h"
DWORD ReturnIndexOfLastCharInBuffer(BYTE* buffer);
VOID CopyBuffer(BYTE* source, BYTE* destination);

VOID ConcatenateBuffer(BYTE* last_buffer, BYTE* current_buffer)
{
	//wprintf(L"%ls\n",last_buffer);
	//wprintf(L"%ls\n",current_buffer);
	DWORD i =  ReturnIndexOfLastCharInBuffer(last_buffer), j, l;
	DWORD k =  ReturnIndexOfLastCharInBuffer(current_buffer);
	for(j=i,l=0;j<i+k; j++,l++)
		last_buffer[j] = current_buffer[l]; 
	last_buffer[j] = L'\0';
	//wprintf(L"The index for last character in last_buffer is %lu\n", ReturnIndexOfLastCharInBuffer(last_buffer));
	//wprintf(L"The index for last character in current_buffer is  %lu\n", ReturnIndexOfLastCharInBuffer(current_buffer));
	//wprintf(L"%ls",last_buffer);
}

VOID CopyBuffer(BYTE* destination, BYTE* source)
{
	DWORD i = 0;
		//, j = ReturnIndexOfLastCharInBuffer(destination);
	//printf("%u", j);
	while(!((destination[i] == '\0') && (destination[i+1] == '\0')))
	{
		destination[i] = '\0';
		++i;
	}
	i = 0;

	//printf("address copying here is %d\n", source);
	//if(source[i] == '\0')
		//printf("yes true lol\n");
	while(!((source[i] == '\0') && (source[i+1] == '\0')))
	{
		//_tprintf(_T("CHar at %lu is %lc\n"), i,source[i]);
		destination[i] = source[i];
		//_tprintf(_T("CHar at %lu is %lc\n"), i,destination[i]);
		++i;
	}
	destination[i] = L'\0';
	//while(i++<j)
		//destination[i] = '\0';
}

