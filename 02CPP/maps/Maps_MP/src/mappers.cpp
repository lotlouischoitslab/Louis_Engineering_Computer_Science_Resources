#include "mappers.hpp"

void Mappers::Insert(int address, string name) {
    pair<int,string> checker = {address,name};
    if(Exists(address)) {
        cout << "Item already exists" << endl;
    } else {
        mp_.insert(pair<int,string>(address, name));
    }
}

void Mappers::Delete(int address) {
    map<int,string>::iterator i = mp_.find(address);
    if (i != mp_.end()) {
        mp_.erase(i);
    }
}

string Mappers::Find(int address) {
    map<int,string>::iterator i = mp_.find(address);
    if (i != mp_.end()) {
        return i->second;
    }

    return "No Member Found";
}

void Mappers::Print() {
    for (auto i : mp_) {
        cout << i.first << ": " << i.second << endl;
    }
}

int Mappers::GetSize() {
    return mp_.size();
}

void Mappers::Clear() {
    mp_.clear();
}

bool Mappers::Exists(int address) {
    return mp_.find(address) != mp_.end();
}