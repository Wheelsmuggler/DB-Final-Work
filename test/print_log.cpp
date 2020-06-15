//
// Created by hj Zhou on 2020-04-09.
//

//
// Created by hj Zhou on 2020-04-04.
//
#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;


enum RecordType{
    kZerotype ,
    kFulltype ,
    kFirsttype ,
    kMiddletype ,
    kLasttype
};

enum ValueType{
    typeDelete,
    typeValue
};

void ValInt32Print(ifstream *fp, uint32_t *keylength){
    uint32_t result = 0;
    int cnt = 0;

    while (cnt<35){
        uint64_t tmp = 0;
        fp->read((char*) &tmp, sizeof(uint8_t));
        if(tmp &128){
            result |= (tmp & 127) <<cnt;

        } else{
            result |= (tmp<<cnt);
            *keylength = result;
            return;
        }
        cnt +=7;
    }
}

int main(){
    string file_name =  "cmake-build-debug/testdb/000017.log";
    ifstream fp;
    fp.open(file_name, ifstream::in);
    int left = 0;
    while (fp.peek()!=EOF){
        uint32_t header = 0;
        fp.read((char *)&header, sizeof(uint32_t));
        cout<< "checksum: " << header << "\t";

        uint16_t length = 0;
        fp.read((char *)&length, sizeof(uint16_t));
        cout<<"length: " << length << "\t";

        uint8_t type = 0;
        fp.read((char *) &type, sizeof(uint8_t));
        cout<<"type :" << type << "\t";

        switch (static_cast<RecordType >(type & 0xff)){
            case kZerotype:
                cout<< "kZerotype"<<"\t";
                return 0;
            case kFulltype:
                cout<<"kFulltype"<<"\t";
                break;
            case kFirsttype:
                cout<<"kFirstype"<<"\t";
                break;
            case kMiddletype:
                cout<<"kMiddletype"<<"\t";
                break;
            case kLasttype:
                cout<<"KLasttype"<<"\t";
                break;

        }

        uint64_t sqnumber = 0;
        fp.read((char *) &sqnumber, sizeof(uint64_t));

        uint32_t entrynumber = 0;
        fp.read((char *) &entrynumber, sizeof(uint32_t));

        uint8_t valuetype;
        fp.read((char *) &valuetype, sizeof(uint8_t));

        uint32_t keylength;
        ValInt32Print(&fp,&keylength);
        cout<< "kelength: "<<keylength<<"\t";
        char *key = new char[keylength];
        fp.read(key,keylength);
        cout<< "key: "<<key<<"\t";


        switch (static_cast<ValueType >(valuetype &0xff)){
            case typeDelete:
                cout<< "del"<<"\n";
                break;
            case typeValue:
                uint32_t valuelength;
                ValInt32Print(&fp, &valuelength);
                cout<< "valueLenght" << valuelength << "\t";
                char *value = new char[valuelength];
                fp.read(value, valuelength);

                cout<< "value: "<< value<<endl;

        }

    }
    fp.close();
    return 0;
}