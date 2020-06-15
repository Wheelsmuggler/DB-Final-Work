#include "leveldb/db.h"
#include "leveldb/comparator.h"
#include "leveldb/filter_policy.h"
#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>

#define TOTAL_DATA_LENGTH (5000000)

using namespace std;
using namespace leveldb;

//vector<string> testSplit(string srcStr, const string& delim);

//int main() {
//    DB* db = nullptr;
//    Options op;
//    op.create_if_missing = true;
//    //op.comparator = leveldb::BytewiseComparator();
//    Status status = DB::Open(op, "testdb1", &db);
//    assert(status.ok());
//
//    //读取文件1
//    freopen("./test/input1","r", stdin);
//    string key, value;
//    for(int t=0; t<10; t++) {
//       cin >> key >> value;
//       db->Put(WriteOptions(), key, value);
//    }
//    fclose(stdin);
//
//    ReadOptions options;
//    options.snapshot = db->GetSnapshot();
//
//    cin.clear();
//
//    //读取文件2
//    freopen("./test/input2","r", stdin);
//    for(int t=0; t<10; t++) {
//        cin >> key >> value;
//        db->Put(WriteOptions(), key, value);
//    }
//    fclose(stdin);
//
//
//    //写入文件
//    freopen("./test/output","w",stdout);
//    string s[15];
//    int i=0;
//    Iterator* iter = db->NewIterator(options);
//    for(iter->SeekToFirst(); iter->Valid(); iter->Next())
//    {
//        s[i] = iter->key().ToString() + " " + iter->value().ToString() + " ";
//        i++;
//
//    }
//
//    Iterator* iter1 = db->NewIterator(ReadOptions());
//    i=0;
//    for(iter1->SeekToFirst(); iter1->Valid(); iter1->Next())
//    {
//        s[i] += iter1->value().ToString();
//        cout << s[i] << endl;
//        i++;
//    }
//    fclose(stdout);
//
//    delete iter;
//    delete iter1;
//    db->ReleaseSnapshot(options.snapshot);
//
//    delete db;
//    return 0;
//}






int main(){
    //TODO：实验的一些基本参数和变量配置
    DB* db = nullptr;
    Options op;
    op.create_if_missing = true;
    int bits_per_key=10;
    float fpp = 0.25; //误判率

    op.filter_policy = leveldb::NewBloomFilterPolicy(bits_per_key);
    op.comparator = leveldb::BytewiseComparator();
    Status status = DB::Open(op,"Final",&db);


    //TODO:写数据库部分
    string filename = "./test/data.csv";
    ifstream infile(filename);
    string line;
    string key,value;
    string::size_type index;
    int count = 1000000;
    //读取文件并且写入
      cout<<"开始写入:"<<endl;
    while(infile.good()&&count>0) {
        getline(infile, line);
        index = line.find(',');
        key = line.substr(0, index);
        value = line.substr(index + 1, line.size() - index - 1);
        //cout<<"key is: "<<key<<"\t"<<"value is: "<<value<<endl;
        db->Put(WriteOptions(), key, value);
        count--;
    }


    //学生学号的参数，小的为stuNo1， 大的为stuNo2
    int targetScore;
    ReadOptions options;
    options.snapshot = db->GetSnapshot();


//    int i=0;
    cout<<"------------开始查找--------------"<<endl;
    for(iter->SeekToFirst(); iter->Valid(); iter->Next())
    {
        cout<<"key is:"<<iter->key().ToString()<<"\t"<<"value is:"<<iter->value().ToString()<<endl;
    }

    //iter 先寻找到 stuNo1的数据片
//    iter->Seek("100");
//    for (int j = 0; j < 100&&iter->Valid(); ++j,iter->Next()) {
//        cout<<"key is:"<<iter->key().ToString()<<"\t"<<"value is:"<<iter->value().ToString()<<endl;
//    }
//    cout<<"------------查找结束--------------"<<endl;
//    //op.filter_policy->KeyMayMatch();
//    delete iter;
    delete db;

}
