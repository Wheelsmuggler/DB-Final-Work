//
// Created by hj Zhou on 2020-05-07.
//

#include "leveldb/db.h"
#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
using namespace leveldb;

int main(){
    DB* db = nullptr;
    Options op;
    op.create_if_missing = true;
    Status status = DB::Open(op,"testdb",&db);
    assert(status.ok());

    db->CompactRange(nullptr, nullptr);


    delete db;
    return 0;



}
