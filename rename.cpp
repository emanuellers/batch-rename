
#include <string>
#include <iostream>
#include <cstring>
#include <map>
#include <windows.h>
#include <tchar.h> 
#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

//Checks if a file is a directory.
bool isDirectory(string name){
    char ch = '.';
    int countOccurrences = count(name.begin(), name.end(), ch);
    if(countOccurrences > 1 || name.size() == 1){
        return true;
    }
    return false;
}

//Return a map containing the flags passed as arguments on command line.
map<string, string> getFlags(int size, char* elements[]){
    map<string, string> flags;
    for(int i=1; i < size; i++){
      string flag = elements[i];
      string value = flag.substr(flag.find("=") + 1, flag.size() -1);
      if(flag.find("filepath")!= std::string::npos){
          flags["filepath"] = value;
      }
      else if(flag.find("templateName")!= std::string::npos){
          flags["templateName"] = value;
      }
    }
    return flags;
}
// Converts string to TCHAR (LPCWSTR)
TCHAR * stringToLPCWSTR(string str){
    TCHAR *tchSTR = new TCHAR[str.size()+1];
    tchSTR[str.size()] = 0;
    copy(str.begin(), str.end(), tchSTR); 
    return tchSTR;
}
int main(int argc, char* argv[]){
    
    vector<string> files;

    if(argc == 1){
        cout << "No flags passed. Finishing application.";
        exit(0);
    }

    //Flags:
    //filepath: path to target directory.
    //templateName: base string to rename the files.

    map<string, string> flags = getFlags(argc, argv);

    WIN32_FIND_DATA findFileData;
    HANDLE handle = INVALID_HANDLE_VALUE;
    LARGE_INTEGER filesize;

    string directory = flags["filepath"] + "\\*";

    TCHAR *filePath = stringToLPCWSTR(directory);

    handle = FindFirstFile(filePath, &findFileData);

    if(handle == INVALID_HANDLE_VALUE){
        cout << "An error ocurred." << endl;
        exit(0);
    }

     do{
        char* charFileName = findFileData.cFileName;
        string strFileName = charFileName;

        if(findFileData.dwFileAttributes  && FILE_ATTRIBUTE_DIRECTORY && !isDirectory(strFileName)){
            files.push_back(strFileName);
        }
     }while(FindNextFile(handle, &findFileData) != 0);

     string path = flags["filepath"] + "\\";

     for(int i = 0; i < files.size(); i++){
         string oldName = path + files[i];

         string fileType = files[i].substr(files[i].find(".") + 1, files[i].size() -1);

         string newName = path + flags["templateName"] +  "_" + to_string(i) + "." + fileType;

         if (rename(oldName.c_str(), newName.c_str()) != 0){
             cout << "Error ocurred during file " << oldName.c_str() << " rename" << endl;
             exit(0); 
         }
         else{
            cout << "Ok... " << oldName << " => " << newName << endl;
         }
     }
   

    FindClose(handle);

}