// chk_scr.cpp : 
//
#include "stdafx.h"
#include "tlhelp32.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	HANDLE hSnap;
	if((hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0)) 
		== INVALID_HANDLE_VALUE) return 1;

	PROCESSENTRY32 pe;
	pe.dwSize = sizeof(pe);

	char *p;
	char lc = 'a' - 'A';
	BOOL flag = false;
	BOOL bResult = Process32First(hSnap, &pe);

	while(bResult){
		p = pe.szExeFile;
		p += strlen(p);
		if((*--p|lc) == 'r' && (*--p|lc) == 'c' && 
		   (*--p|lc) == 's' &&  *--p     == '.'){
			flag = true;
		}
		bResult = Process32Next(hSnap, &pe);
	}
	printf("%s\n", flag ? "true" : "false");
	return flag ? 0 : 1;

}

