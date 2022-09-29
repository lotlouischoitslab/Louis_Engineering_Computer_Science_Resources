#ifndef MAPPERS_HPP
#define MAPPERS_HPP

#include <iostream>
#include <stdlib.h>
#include <map>
using namespace std;

class Mappers {
    public:
      void Insert(int address, string name);
      void Delete(int address);
      string Find(int address);
      void Print();
      int GetSize();
      void Clear();
      bool Exists(int address);

    private:
      map<int,string> mp_;
};

#endif