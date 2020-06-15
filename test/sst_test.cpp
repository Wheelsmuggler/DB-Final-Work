//
// Created by hj Zhou on 2020-04-24.
//

#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>


#define FOOTER_SIZE 48
using namespace std;


char *getVarint64(char* p, size_t size,uint64_t *value);
char *getVarint32(char* p, size_t size,uint32_t *value,uint32_t &bytes);

struct BlockIndex{
    uint32_t key_length, value_length;
    char *limit_key;
    uint64_t offset,size;
    BlockIndex(int len){
        limit_key = new char[len];
        memset(limit_key,'\0', len);
    }
};

int main(){
    string file = "testdb/000095.ldb";

    FILE *fp = fopen(file.c_str(),"r");
    if(fp==NULL){
        printf("file open error!\n");
    }
    //从文件指针的末尾寻找倒数第48个bytes。
    fseek(fp,-FOOTER_SIZE,SEEK_END);
    char *footer = new char[FOOTER_SIZE];
    fgets(footer,FOOTER_SIZE,fp);
    //printf("%s",footer);
    uint64_t metaOffset, metaSize, indexOffset, indexSize;
    footer = getVarint64(footer,10,&metaOffset);
    footer = getVarint64(footer,10,&metaSize);
    footer = getVarint64(footer,10,&indexOffset);
    footer = getVarint64(footer,10,&indexSize);
    cout<<"metaOffset: "<<metaOffset<<endl;
    cout<<"metasize: "<<metaSize<<endl;
    cout<<"indexoffset: "<<indexOffset<<endl;
    cout<<"indexsize: "<<indexSize<<endl;

    char* index_block = new char[indexSize+1];
    fseek(fp,indexOffset,SEEK_SET);
    fgets(index_block,indexSize,fp);

    indexSize -= 1;
    uint32_t indexNumber=0, k=0;
    while (k<4){
        indexNumber = indexNumber << 8| (uint32_t)index_block[indexSize];
        k++;
        indexSize--;
    }

    int i = 0;
    vector<BlockIndex> bx;
    while(i<indexNumber){
        index_block ++;
        uint32_t key_length, value_length,bytes;
        index_block = getVarint32(index_block,5,&key_length,bytes);
        key_length -= 8;
        BlockIndex now(key_length+1);
        index_block = getVarint32(index_block,5,&value_length,bytes);

        now.key_length  = key_length;
        now.value_length = value_length;
        memcpy(now.limit_key,index_block,key_length);
        index_block +=key_length;
        index_block += 8;
        cout<<"key length: " <<now.key_length<<endl;
        cout<<"limit_key: "<<now.limit_key<<endl;

        uint64_t block_offset, block_size;
        index_block = getVarint64(index_block,10,&block_offset);
        index_block = getVarint64(index_block,10,&block_size);
        now.offset = block_offset;
        now.size = block_size;
        cout<<"block offset: "<<block_offset<<"\t";
        cout<<"block_size: "<<block_size<<endl;
        bx.push_back(now);
        i++;

    }

    cout<<"---------now read the data block----------"<<endl;
    for (int j = 0; j < indexNumber; ++j) {
        uint64_t block_Offset = bx[i].offset;
        uint64_t block_Size = bx[i].size;

        uint64_t limit_offset = block_Offset+block_Size -1;
        char* start_number = new char();
        uint32_t numrestart = 0, k = 0;
        while (k<4){
            fseek(fp,limit_offset,SEEK_SET);
            fread(start_number, sizeof(char),1,fp);
            numrestart = numrestart<<8 | (uint32_t)*start_number;
            k++;
            limit_offset --;
        }
        cout<<"number of restart: "<<numrestart<<endl;
        limit_offset -=numrestart*4;

        fseek(fp,block_Offset,SEEK_SET);
        string lastkey = "";
        while(block_Offset<=limit_offset){
            char* length = new char[5];
            uint32_t share_length, no_shared_length, value_length,bytes;
            fread(length, sizeof(char),5,fp);
            getVarint32(length,5,&share_length,bytes);
            cout<<"shared_length: "<<share_length<<endl;

            block_Offset += bytes;
            fseek(fp,block_Offset,SEEK_SET);
            fread(length, sizeof(char),5,fp);
            getVarint32(length,5,&no_shared_length,bytes);
            //减去（1+7）
            no_shared_length -= 8;
            cout<<"no shared length: "<<no_shared_length<<endl;
            block_Offset += bytes;
            fseek(fp,block_Offset,SEEK_SET);
            fread(length, sizeof(char),5,fp);
            getVarint32(length,5,&value_length,bytes);
            cout<<"value length: "<<value_length<<endl;
            block_Offset+= bytes;

            char* key = new char[no_shared_length+1];
            memset(key,'\0', no_shared_length+1);
            fseek(fp,block_Offset,SEEK_SET);
            fread(key, sizeof(char),no_shared_length,fp);
            string nowkey;
            if(no_shared_length){
                nowkey = lastkey.substr(0,share_length) + string(key);

            } else{
                nowkey = key;
            }
            cout<<"key: "<<nowkey<<endl;
            lastkey = nowkey;

            block_Offset += no_shared_length;
            char value_type;
            fseek(fp,block_Offset,SEEK_SET);
            fread(&value_type, sizeof(char),1,fp);
            if(value_type) cout<<"value_type:value"<<endl;
            else cout<<"value type: del"<<endl;

            block_Offset+=8;
            char value[value_length+1];
            memset(value,'\0',value_length+1);
            fseek(fp,block_Offset,SEEK_SET);
            fread(&value, sizeof(char),value_length,fp);
            cout<<"value: "<<value<<endl;
            block_Offset += value_length;

        }
    }
    return 0;
}

char *getVarint64(char* p, size_t size,uint64_t *value){
    char *end = p+size;
    uint64_t result = 0;
    for (int i = 0; i < 64 && p<end; i+=7) {
        uint64_t one_byte = *(static_cast<char *>(p));
        //printf("byte: %x\n",one_byte);
        p++;
        //1000,0000 做 & 如果最高位是1则需要后退
        if(one_byte & 128){
            //0111,1111做&并算数右移
            result |= ((one_byte&127)<<i);
            //printf("result : %d\n",result);
        }else{
            result |= (one_byte<<i);
            //printf("result : %d\n",result);
            *value = result;
            return p;
        }
    }
    return nullptr;
}

char *getVarint32(char* p, size_t size,uint32_t *value,uint32_t &bytes){
    char *end = p+size;
    uint64_t result = 0;
    bytes = 0;
    for (int i = 0; i < 32 && p<end; i+=7) {
        uint64_t one_byte = *(static_cast<char *>(p));
        p++;
        bytes++;
        if(one_byte & 128){
            result |= ((one_byte&127)<<i);
        }else{
            result |= (one_byte<<i);
            *value = result;
            return p;
        }
    }
    return nullptr;
}