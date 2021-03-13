// cat.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define BUFFER_SIZE 256

int _tmain(int argc, _TCHAR* argv[])
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE), hStdIn = GetStdHandle(STD_INPUT_HANDLE);
	DWORD i, fileReadStatus, numberOfBytesRead, numberOfBytesWrite;
	char buffer [BUFFER_SIZE];
	/*
	Logic is simply to find the first filename argument index and then creating handle for each file. 
	Reading each file and sending these to stdinput stream which will also act as input to stdoutput
	*/
	HANDLE hFileReader = NULL;
	for(i=1; i<=argc; i++)
	{
		hFileReader = CreateFileW(argv[i],  GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		while(fileReadStatus=ReadFile(hFileReader, buffer, BUFFER_SIZE, &numberOfBytesRead, NULL) && numberOfBytesRead > 0)
		{
			_fprintf_p(stdout, "\n\n/n\n");
			WriteFile(hStdOut, buffer, numberOfBytesRead, &numberOfBytesWrite, NULL);
		}

			CloseHandle(hFileReader);

	}
	CloseHandle(hStdIn);
	CloseHandle(hStdOut);
	return 0;
}

