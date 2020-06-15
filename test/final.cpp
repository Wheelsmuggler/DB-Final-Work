//
// Created by hj Zhou on 2020-05-14.
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



using namespace std;
using namespace leveldb;

#define TOTAL_DATA_LENGTH (5000000)


struct BlockIndex{
  uint32_t key_length, value_length;
  char *limit_key;
  uint64_t offset, size;
  BlockIndex(int len){
    limit_key = new char[len];
    memset(limit_key,'\0', len);
  }
};

void getAllFiles(const char* path, vector<string>& files);
void parseSStable(string file);
char* GetVarint32(char *p, int size, uint32_t *value, uint32_t &bytes){
  char *limit = p + size;
  uint32_t result = 0;
  bytes = 0;
  for(uint32_t shift=0; shift < 32 && p < limit; shift += 7){
    uint32_t byte = *(static_cast<char *>(p));
    p++;
    bytes++;
    if(byte & 128){
      result |=((byte & 127 << shift));
    } else {
      result |= (byte << shift);
      *value = result;
      return p;
    }
  }
  return nullptr;
}

char* GetVarint64(char *p, int size, uint64_t *value){
  char *limit = p + size;
  uint64_t result = 0;
  for(uint32_t shift=0; shift < 64 && p < limit; shift += 7){
    uint64_t byte = *(static_cast<char *>(p));
    p++;
    if(byte & 128){
      result |=((byte & 127 << shift));
    } else {
      result |= (byte << shift);
      *value = result;
      return p;
    }
  }
  return nullptr;
}

//int main(){
//  DB* db = nullptr;
//  Options op;
//  op.create_if_missing = true;
//  int bits_per_key = 10;
//  op.filter_policy = leveldb::NewBloomFilterPolicy(bits_per_key);
//  Status status = DB::Open(op,"RealFW2.0",&db);
//  op.comparator = leveldb::BytewiseComparator();
//  assert(status.ok());
//
//  //TODO:写数据库部分
//  string filename = "./test/data.csv";
//  ifstream infile(filename);
//  string line;
//  string key,value;
//  string::size_type index;
//  //读取文件并且写入
////  int count = 500000;
//  cout<<"------开始写入:------"<<endl;
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
//  delete db;
//}

int main(){
  DB* db = nullptr;
  Options op;
  op.create_if_missing = true;
  op.filter_policy = leveldb::NewBloomFilterPolicy(12);
  op.comparator = leveldb::BytewiseComparator();
  Status status = DB::Open(op,"RealFW1.0",&db);
  ReadOptions options;
  string v1;
  cout<<"----------开始查找---------------"<<endl;
  //db->Get(ReadOptions(),"10000",&v1);
  //cout<<"v1 is:"<<v1<<endl;
  //int count = 1000;
  //Iterator* iter = db->NewIterator(ReadOptions());
//  for(iter->SeekToFirst(); iter->Valid(),count>0; iter->Next(),count--)
//  {
//
//    cout<<"key is:"<<iter->key().ToString()<<"\t"<<"value is:"<<iter->value().ToString()<<endl;
//  }
//  for(iter->Seek("1000");iter->Valid()&&iter->key().ToString() < "2000";iter->Next()){
//    cout<<"key is:"<<iter->key().ToString()<<"\t"<<"value is:"<<iter->value().ToString()<<endl;
//  }
  //db->GetStuNo(ReadOptions(),"10000","30000","555");

}


void getAllFiles(const char* path, vector<string>& files){
  struct dirent *dirp;
  DIR *dir = opendir(path);
  string tmp;
  while ((dirp = readdir(dir))!= nullptr){
    tmp = string(dirp->d_name);
    int index = tmp.find('.');
    if (index!=-1){
      if (tmp.substr(index,tmp.size()-1) == ".ldb"){
        files.push_back(string(dirp->d_name));
      }
    }
  }
  closedir(dir);
}

void getStuNo(string stuNo1,string stuNo2,vector<string>&stuNo,string target){

}

void parseSStable(string file){
  FILE *fp = fopen(file.c_str(),"r");
  if (fp== nullptr){
    cout<<"wrong file name!"<<endl;
    exit(1);
  }
  fseek(fp,-48L,SEEK_END);
  char *footer = new char[48];
  fgets(footer,48,fp);
  uint64_t metaOffset, metaSize, indexOffset, indexSize;
  footer = GetVarint64(footer,10,&metaOffset);
  footer = GetVarint64(footer,10,&metaSize);
  footer = GetVarint64(footer, 10, &indexOffset);
  GetVarint64(footer, 10, &indexSize);
  cout<<"Meta_block_offset:"<<metaOffset<<endl
      << "Meta Size:" << metaSize << endl
      << "Index offset:" << indexOffset << endl
      << "Index size:" << indexSize << endl;

  char *index_block = new char[indexSize+1];
  fseek(fp,163836,SEEK_SET);
  fread(index_block,1,indexSize,fp);
  cout<<index_block<<endl;
  indexSize -= 1;
  uint32_t numberOfIndex=0, k=0;
  while (k<4){
    numberOfIndex = numberOfIndex << 8 |(uint32_t)index_block[indexSize];
    k++;
    indexSize --;
  }
  cout<<"numberOfIndex:"<<numberOfIndex<<endl;

  int i = 0;
  vector<BlockIndex> bx;
  while (i < numberOfIndex){
    index_block++;
    cout<<"index_block:"<<index_block;
    uint32_t keyLen,valueLen,bytes;
    index_block = GetVarint32(index_block,5,&keyLen,bytes);
    keyLen -= 8;
    BlockIndex now(keyLen+1);
    index_block = GetVarint32(index_block,5,&valueLen,bytes);

    now.key_length = keyLen;
    now.value_length = valueLen;
    memcpy(now.limit_key,index_block,keyLen);
    index_block += keyLen;
    index_block += 8;
    cout << "key_length:" << keyLen
         << " limit_key:" << now.limit_key << endl;

    uint64_t block_offset, block_size;
    index_block = GetVarint64(index_block, 10, &block_offset);
    index_block = GetVarint64(index_block, 10, &block_size);
    now.offset = block_offset, now.size = block_size;
    cout << "block_offset:" << block_offset
         << " block_size:" << now.limit_key << endl << endl;

    bx.push_back(now), i++;
  }
}






