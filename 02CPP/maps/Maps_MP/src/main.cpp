#include "mappers.hpp"
#include <iostream>
#include <stdlib.h>
#include <map>
#include <vector>

using namespace std;

int main() {
    Mappers* name_list = new Mappers;
    
    pair<int,string> p1 = {1,"Louis Sungwoo Cho"};
    pair<int,string> p2 = {2,"Juyoung Choi"};
    pair<int,string> p3 = {3,"Hakyung Peter Yun"};
    pair<int,string> p4 = {4,"Sangyun Lee"};
    pair<int,string> p5 = {5,"Yunseok Lee"};
    
    std::vector<pair<int,string>> pairs = {p1,p2,p3,p4,p5};

    for(size_t i = 0; i < pairs.size(); i++) {
        name_list->Insert(pairs[i].first, pairs[i].second);
    }

    name_list->Insert(p1.first,p1.second);
    cout << "List of my friends' names: " << endl;
    name_list->Print();
    cout << endl;
    cout << "My Functions that I have implemented:" << endl;
    cout << "Find Louis: " << name_list->Find(1) << endl;
    cout << "Size of my map: " << name_list->GetSize() << endl;
    name_list->Delete(1);
    name_list->Print();
    name_list->Clear();

    cout << "Cleared my map: ";
    name_list->Print();
    
}