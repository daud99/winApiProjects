// file_comparison.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define BUF_SIZE 256
VOID ReportError (LPCTSTR userMessage, DWORD exitCode, BOOL printErrorMessage);
int _tmain(int argc, _TCHAR* argv[])
{   BYTE buffer1[BUF_SIZE], buffer2[BUF_SIZE];
	HANDLE hReadFile1, hReadFile2;
	DWORD nBytesRead1, nBytesRead2, success,i,j;
	BOOL match= TRUE;
	// checking that we got all the parameter
	if(argc != 3)
		ReportError(_T("Command useage: file_comparison file1.txt file2.txt"), 1, FALSE);

	hReadFile1 = CreateFile(argv[1], GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, NULL);

	if(hReadFile1 == INVALID_HANDLE_VALUE)
		ReportError(_T("Not Able to readfile"), 2, TRUE);

	hReadFile2 = CreateFile(argv[2], GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, NULL);

	if(hReadFile2 == INVALID_HANDLE_VALUE)
		ReportError(_T("Not Able to readfile"), 3, TRUE);

	i = GetFileSize(hReadFile1, NULL);
	j = GetFileSize(hReadFile2, NULL);

	if(i == INVALID_FILE_SIZE || j == INVALID_FILE_SIZE)
		ReportError(_T("Not Able to get file size"), 0, TRUE);
	else if(i != j)
	{
		_tprintf(_T("Size for firstfile is %lu and size for secondfile is %lu\n"), i,j);
		match = FALSE;
		nBytesRead1 = 0;
	}

	while(ReadFile(hReadFile1, &buffer1, BUF_SIZE, &nBytesRead1, NULL) && (nBytesRead1 != 0) && ReadFile(hReadFile2, &buffer2, BUF_SIZE, &nBytesRead2, NULL))
	{
		for(i=0,j=0; i< nBytesRead1 && j < nBytesRead2; i++,j++)
		{
			if(buffer1[i] != buffer2[j])
				match = FALSE;

		}
	}

	
	if (match == TRUE)
		_tprintf(_T("Both files are same\n"));
	else
		_tprintf(_T("Both files are different\n"));


	
	return 0;
}

