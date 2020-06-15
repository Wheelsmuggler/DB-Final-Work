//
// Created by hj Zhou on 2020/6/14.
//

#include "leveldb/db.h"
#include "leveldb/comparator.h"
#include "leveldb/filter_policy.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <dirent.h>
#include <vector>
#include <cstdio>

using namespace leveldb;
using namespace std;
int main(){
  DB* db = nullptr;
  Options op;
  op.create_if_missing = true;
  int bits_per_key = 10;
  op.filter_policy = leveldb::NewBloomFilterPolicy(bits_per_key);
  Status status = DB::Open(op,"LastDB",&db);
  op.comparator = leveldb::BytewiseComparator();
  assert(status.ok());

  //TODO:写数据库部分
  string filename = "./test/data.csv";
  ifstream infile(filename);
  string line;
  string key,value;
  string::size_type index;
  //读取文件并且写入
  //int count = 500000;
  //cout<<"------开始写入:------"<<endl;
//  while(infile.good()) {
//    getline(infile, line);
//    index = line.find(',');
//    key = line.substr(0, index);
//    value = line.substr(index + 1, line.size() - index - 1);
//    //std::cout<<"key is: "<<key<<"\t"<<"value is: "<<value<<endl;
//    db->Put(WriteOptions(), key, value);
//    //count--;
//  }
//  cout<<"------完成写入:------"<<endl;
  db->GetStuNo(ReadOptions(),"1","3000000","749\r");

}