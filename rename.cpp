
#include <string>
#include <iostream>
#include <cstring>
#include <map>
#include <windows.h>
#include <tchar.h> 
#include <stdio.h>
using namespace std;


int main(int argc, char* argv[]){
    map<string, string> flags;

    if(argc == 1){
        cout << "No flags passed. Finishing application.";
        exit(0);
    }
//filepath = caminho do diretório
//templateName = nome base para renomear os arquivos
 
   int i;
   for(i=1; i < argc; i++){
      string flag = argv[i];
      string value = flag.substr(flag.find("=") + 1, flag.size() -1);
      if(flag.find("filepath")!= std::string::npos){
          flags["filepath"] = value;
      }
      else if(flag.find("templateName")!= std::string::npos){
          flags["templateName"] = value;
      }
    }

    //Encontra o primeiro arquivo do diretório
    WIN32_FIND_DATAA findFileData;
    HANDLE handle;
    TCHAR directory[MAX_PATH];

    LPCSTR wStringFilePath ; 
    wStringFilePath = flags["filepath"].c_str();

    handle = FindFirstFileA(wStringFilePath , &findFileData);
    cout << "Handle >>> " << handle << endl;

    if(handle == INVALID_HANDLE_VALUE){
        cout << "An error ocurred." << endl;
        exit(0);
    }

   do{
        if(findFileData.dwFileAttributes  && FILE_ATTRIBUTE_DIRECTORY){
         _tprintf(TEXT("  %s   <DIR>\n"), findFileData.cFileName);
        }else{
            cout << "aqui";
        }
    } while(FindNextFileA(handle, &findFileData) != 0);

    

}