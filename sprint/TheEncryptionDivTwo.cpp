#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class TheEncryptionDivTwo {
  public:
  string encrypt(string message)
  {
    string cipher = "";
    map<char, char> key;
    map<char, char> :: iterator it;
    char next_key = {'a'};

    for (char c : message)
    {
      it = key.find(c);
      if (it == key.end())
      {
        key[c] = next_key;
        next_key++;
      }
      cipher += key[c];
    }
    return cipher;
  }
};
