// grep.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define BUFFER_SIZE 100  /* Optimal in several experiments. Small values such as 256 give very bad performance */

DWORD ReturnIndexOfLastCharInBuffer(BYTE* buffer);
VOID ReportError (LPCTSTR userMessage, DWORD exitCode, BOOL printErrorMessage);
VOID ConcatenateBuffer(BYTE* last_buffer, BYTE* current_buffer);
VOID CopyBuffer(BYTE* source, BYTE* destination);

int _tmain(int argc, _TCHAR* argv[])
{
	//_TCHAR test1[BUFFER_SIZE]=_T("How are you are you good "), test2[BUFFER_SIZE*2]=_T("Yees i m fucking good");

	//ConcatenateBuffer((LPTSTR)test1, (LPTSTR)test2);
	//CopyBuffer((LPTSTR)test1, (LPTSTR)test2);
	//wprintf(L"%ls\n",test1);
	//wprintf(L"%ls\n",test2);
	if(argc < 3)
		ReportError(_T("Command useage: file_comparison search_string file2.txt"), 2, FALSE);

	DWORD nIn, flag = 0, counter = 0;
	BYTE current_buffer[BUFFER_SIZE]={0}, last_buffer[BUFFER_SIZE]={0}, buffer[BUFFER_SIZE*2]={0};
	HANDLE a = CreateFile(argv[2], GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	while(ReadFile (a, current_buffer, BUFFER_SIZE-2, &nIn, NULL) && (nIn != 0))
	{
		//printf("%u\n", nIn);
		current_buffer[nIn+1] = L'\0';
		//current_buffer[nIn+2] = '\0';
		//_tprintf(_T("%ls"), current_buffer);
		//CopyBuffer((LPTSTR)last_buffer, (LPTSTR)current_buffer);
		/*for(int i=1; i<257; i++)
		{
			if(current_buffer[i] == '\0')
				printf("\nnull character is found at index %d\n", i);
		
		}*/
		//current_buffer[nIn*2] = '\0';
		//_tprintf(_T("%ls\n\n\n"), current_buffer);


		//checking wether the last character is null_character or not

		/*if(current_buffer[nIn] == '\0')
			printf("yes last character is null");
		if(current_buffer[BUFFER_SIZE] == '\0')
			printf("yes last character in index 257 is null");*/

		LPTSTR pr = StrStr((PCTSTR)current_buffer, argv[1]);
		if(!(pr == NULL))
		{
			counter = counter + 1;
			flag = 1;
		}
		//printf("below is the content for the current buffer below\n");
		//wprintf(L"%ls\n",current_buffer);
		//CopyBuffer(last_buffer, current_buffer);
		ConcatenateBuffer(buffer, current_buffer);
		//printf("below is the content for the last buffer below\n\n\n\n");
		//wprintf(L"%ls\n",last_buffer);
		printf("below is the content for the buffer below\n\n\n");
		wprintf(L"%ls\n",buffer);
		//wprintf(L"%ls\n",current_buffer);
		//last_buffer = current_buffer;
		//break;
	}

	
	if(flag == 1)
	{
			_tprintf(_T("String is founded\n"));
			_tprintf(_T("Search string is founded this many times %lu"), counter);
	}
	else
	{
		_tprintf(_T("String is not founded\n"));
	}
	return 0;
}

