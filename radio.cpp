/******************************************************/
//功能：通过UDP协议，将端口雷达数据读取解析出来
//作者：张程
//日期：2018.6.22
/****************************************************/
#include "stdafx.h"  
#include <stdio.h>  
#include <winsock2.h> 
#include < windows.h>  
#include <fstream>

#pragma comment(lib,"ws2_32.lib")  

using namespace std;

int main(int argc, char* argv[])
{
	//初始化WSA  
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA wsaData;

	if (WSAStartup(sockVersion, &wsaData) != 0)
	{
		return 0;
	}
	//创建套接字  
	SOCKET slisten = socket(AF_INET, SOCK_DGRAM, 0);
	if (slisten == INVALID_SOCKET)
	{
		printf("socket error !");
		//return 0;
	}
	//绑定IP和端口  
	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(6699);//端口8888  
	sin.sin_addr.S_un.S_addr = INADDR_ANY;

	if (bind(slisten, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR)
	{
		printf("bind error !");
	} 
	//循环接收数据  
	sockaddr_in remoteAddr;
	int nAddrlen = sizeof(remoteAddr);

	char revdata[1248];
	int tembuf[1248];
	double disbuf[792];

SYSTEMTIME sys;
GetLocalTime(&sys);
//printf(" %d-%d-%d-%d-%d-%d-%d\n", sys.wYear, sys.wMonth, sys.wDay, sys.wHour, sys.wMinute, sys.wSecond, sys.wMilliseconds);

	ofstream outfile;
	ofstream outfile2;
	//ofstream outfile("11.txt", ios::trunc);
	outfile.open("source.txt", ios::binary | ios::trunc| ios::in | ios::out);
	outfile2.open("processed.txt", ios::binary | ios::trunc| ios::in | ios::out);
	//注意，里面有iOS：：app，表示打开文件后，在写入的文件不会覆盖原文件中的内容，也就是原来文件中的数据会得到保存。
	while (true)
	{
		int ret;
		int i, i1,i2,i3,j,j1;
		while (true)
		{			
			ret = recvfrom(slisten, revdata, 1248, 0,(SOCKADDR*)&remoteAddr, &nAddrlen);	//接收数据  
			Sleep(10);
			if (ret)
			{
				//printf("接收 %s 的数据\n",inet_ntoa(remoteAddr.sin_addr));
				i1 = 0; i2 = 0; i3 = 0; j1 = 0;//i1关于角度，i2关于第几线雷达，i3关于源数据索引值。
				for (i = 0; i < 1248; i++)
				{
					tembuf[i] = int(revdata[i]);
					if (tembuf[i] < 0)
					{
						tembuf[i] = tembuf[i] + 256;
					}
					outfile <<tembuf[i]<<" ，";
					if (i==41 || i==1241)
					{
						outfile << "\r\n";
						if (i==41)
						{
							GetLocalTime(&sys);
							outfile << sys.wYear << " ，" <<
								sys.wMonth << " ，" << sys.wDay << " ，"
								<< sys.wHour << " ，" << sys.wMinute << " ，"
								<< sys.wSecond << " ，"
								<< sys.wMilliseconds << " ，" << "\r\n";
						}
					}
					if ((i - 41) % 100 == 0)
					{
						outfile << "\r\n";
					}
				}
				outfile << "\r\n" << "\r\n" << "\r\n" << "\r\n";

				if ((tembuf[0] == 85) && (tembuf[1] == 170) && (tembuf[2] == 5) && (tembuf[3] == 10) && (tembuf[4] == 90))
				{
					printf("数据有效\n");
				for (j = 0; j < 12;j++)
				{
					for (i = 0; i < 32;i++)
					{
						if ((i1 / 33) % 2 == 0)
						{
							disbuf[i1] = double(tembuf[44 + j1] * 256 + tembuf[44 + j1 + 1]) / 100;//水平角度
						}

						if (((i1 / 33) % 2 != 0) && (j1 < 1100))
						{
							disbuf[i1] = double((tembuf[44 + j1] * 256 + tembuf[44 + j1 + 1]) + (tembuf[44 + j1 + 100] * 256 + tembuf[44 + j1 + 1 + 100])) / 200;//水平角度

							if (double(tembuf[44 + j1] * 256 + tembuf[44 + j1 + 1]) / 100 > 359.63)
							{
								disbuf[i1] = double(tembuf[44 + j1] * 256 + tembuf[44 + j1 + 1]) / 100 + 0.18;
								if (disbuf[i1] > 360)
								{
									disbuf[i1] = disbuf[i1] - 360;
								}
							}
						}
						if (((i1 / 33) % 2 != 0) && (j1 == 1100))
						{
							disbuf[i1] = disbuf[i1 - 33] + 0.18;//水平角度//0.18最后一组角度值的处理，和电机转速有关
							if (disbuf[i1]>360)
							{
								disbuf[i1] = disbuf[i1] - 360;
							}
						}

						disbuf[i2 + 1] = double(tembuf[44 + i3 + 2] * 256 + tembuf[44 + i3 + 3]) / 100;//激光距离
						if (disbuf[i2 + 1]>200)
						{

							disbuf[i2 + 1] = 200;
						}
						disbuf[i2 + 2] = tembuf[44 + i3 + 4];//激光反射率

						i2 = i2 + 2;
						i3 = i3 + 3;
						if ((i2+1) % 33 == 0)
						{
							i1 = i1 + 33;
							i2 = i2 + 1;							
						}
					}
					j1 = j1 + 100;
					i3 = i3 + 4;
									
				}
				

				for (i = 0; i < 792;i++)
				{ 
					if (i == 0)
					{
						/*GetLocalTime(&sys);
						outfile2 << sys.wYear << " ，" <<
						sys.wMonth << " ，" << sys.wDay << " ，"
						<< sys.wHour << " ，" << sys.wMinute << " ，"
						<< sys.wSecond << " ，"
						<< sys.wMilliseconds << " ，" << "\r\n";*/
					}
					

					outfile2<< disbuf[i] << "    " ;
					if ((i+1)%33==0)
					{ 
						outfile2 << "\r\n" ;
					}
				}
				outfile2 << "\r\n" << "\r\n" << "\r\n" << "\r\n";
			}
			}
			Sleep(100);
		}

	}
	outfile.close();//关闭文件，保存文件。
	outfile2.close();
	closesocket(slisten);
	WSACleanup();
	return 0;
}

//#include "stdafx.h"
//#include <stdio.h>
//#include < windows.h>   
//#include < stdio.h>   
//int main(void)
//{
//	int a;
//	SYSTEMTIME sys;
//	GetLocalTime(&sys);
//	printf(" %d-%d-%d-%d-%d-%d-%d\n"
//		, sys.wYear, sys.wMonth, sys.wDay
//		, sys.wHour, sys.wMinute, sys.wSecond, sys.wMilliseconds
//		);
//	a = sys.wMonth;
//	printf("%d",a);
//	Sleep(5000);
//	return 0;
//}