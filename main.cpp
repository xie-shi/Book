#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#pragma pack(push, 1)
typedef struct
{
    uint8_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
    uint16_t ms;
    uint16_t us;
} RSTimestampYMD;

typedef struct
{
    uint64_t id;
    uint8_t reserved_1[12];
    RSTimestampYMD timestamp;
    uint8_t lidar_type;
    uint8_t reserved_2[7];
    uint16_t temp_raw;
    uint8_t reserved_3[2];
} RSMsopHeader;

typedef struct{
    float Point_X;
    float Point_Y;
    float Point_Z;
}Point;

typedef struct
{
    uint16_t distance;
    uint8_t intensity;
    Point Point;
} RSChannel;

typedef struct
{
  uint16_t id;
  uint16_t azimuth;
  RSChannel channels[32];
} RS16MsopBlock;

typedef struct
{
  //RSMsopHeader header;
  RS16MsopBlock blocks[12];
  unsigned int index;
  //uint16_t tail;
} RS16MsopPkt;
#pragma pack(pop)

unsigned int getIndex(unsigned int* Num){
    unsigned int Rev_Index;
    Rev_Index = *Num;
    Rev_Index <<= 8;
    Rev_Index |= *(Num+1);
    Rev_Index <<=8;
    Rev_Index |= *(Num+2);
    Rev_Index <<=8;
    Rev_Index |= *(Num+3);

    return  Rev_Index;
}
uint16_t get_shortData(unsigned int* iter){
    uint16_t Rev_short;
    Rev_short = *iter;
    Rev_short <<= 8;
    Rev_short |= *(iter+1);

    return Rev_short;
}

RS16MsopPkt getDataPkt(unsigned int* Begin,unsigned int* end){

    RS16MsopPkt Data;//单帧数据包
    Data.index = getIndex(end-5);//获取当前帧的顺序
    while(Begin!=end) {
       unsigned int BlockIndex = 0;//帧块的标志
        if (*Begin==0xff && *(Begin+1) == 0xEE){
            Data.blocks[BlockIndex].id = BlockIndex;
            Data.blocks[BlockIndex].azimuth = get_shortData(Begin+2);

        }





    }



    return Data;
};


int main(int agrc,char* agrv[]){
/*二进制方式读取文件*/
std::ifstream ReadPcap("../test.pcap",std::ios::in|std::ios::binary);
unsigned int Header[8] = {0x55,0xAA,0x05,0x0A,0x5A,0xA5,0x50,0xA0};//帧头
unsigned int Tail[2] = {0x00,0xff};//帧尾
unsigned char ref[32000];//接收数据缓存区
//std::vector<unsigned char> Data;
//std::vector<std::string> Input;

/*判断文件是否正常打开*/
if(!ReadPcap.is_open()){
std::cout<<"The file open fail"<<std::endl;
return -1;
}
std::vector<RS16MsopPkt> MospData;

//std::vector<unsigned int> NumSign;
//std::vector<std::vector<unsigned int>> Data;
std::vector<int> SignIter;//存放缓存区有限帧的帧头地址

while(ReadPcap.read(reinterpret_cast<char*>(&ref),sizeof(ref))) {
    //寻找有效缓存数据
    for (auto iter = 0; iter < 33000; iter++) {
        bool Is_Header = false;
        int TempNum = int(static_cast<unsigned char>(ref[iter]));
        std::cout << std::hex << TempNum << " ";
        if (TempNum == Header[0]
            && Header[7] == int(static_cast<unsigned char>(ref[iter + 7]))
            && Tail[0] == int(static_cast<unsigned char>(ref[iter + 1246]))
            && Tail[0] == int(static_cast<unsigned char>(ref[iter + 1247]))
                )
            SignIter.push_back(iter);
    }


    SignIter.clear();//清空此次待选帧头
}
/*
while(ReadPcap.read(reinterpret_cast<char*>(&Data),sizeof(Data))){
 std::cout<<line<<" " << ReadPcap.gcount()<<"\n ";
}
*/
ReadPcap.close();
return 0;
}
