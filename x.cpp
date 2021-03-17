// #include <iostream>
// #include <tuple>

// using namespace std;

// auto GetTuple() {
//   int x = 8, y = 21;
//   auto v = tie(x, y);
//   return tie(x, y);
// }

// int main() {
//   auto [x1, y1] = GetTuple();
//   cout << x1 << ' ' << y1 << endl;
//   return 0;
// }


#include <iostream>
#include <memory>
#include <string>
using namespace std;

#include <windows.h>
#include <cstdio>
void FindRecursive(char* path, char* mask)
{     
    WIN32_FIND_DATA finddata;
    char p[512], buf[512];
    HANDLE hFind;
    // ищем файлы
    sprintf(p, "%s\\%s", path, mask);
 
    hFind = FindFirstFile(p, &finddata);
    if (hFind != INVALID_HANDLE_VALUE) {
        do {     
         if (strcmp(finddata.cFileName, "..") && strcmp(finddata.cFileName, ".")) {
            cout << path << ' '<< finddata.cFileName<< endl; 
         }
            // cout << path << ' ' << finddata.cFileName<< endl
        } while (FindNextFile(hFind, &finddata));
    }
    FindClose(hFind);

    // ищем подпапки
    sprintf(p, "%s\\*", path);
    hFind = FindFirstFile(p, &finddata);
    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            if ((finddata.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
                if (strcmp(finddata.cFileName, "..") && strcmp(finddata.cFileName, ".")) {
                    sprintf(buf, "%s\\%s", path, finddata.cFileName);
                    FindRecursive(buf, mask);
                }
            }
        } while (FindNextFile(hFind, &finddata));
    }
    FindClose(hFind);
}


int main() {
  char* path = "D:";
  char* file = "*.*";
   FindRecursive(path,file);
  // const int x = 7;
  // unique_ptr<const int> q(&x);
  //   cout << x << ' ' << *q << endl;
//  cout << path << ' ' << file<< endl;
 
  return 0; 
}

