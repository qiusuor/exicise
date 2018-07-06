#include <Windows.h>  
#include <stdio.h>
#include <iostream>

using namespace std;
typedef  char _TCHAR;
#define BLOCK_SIZE 512
//参数：输出的字符串指针，开始位置，长度  
//返回值：读取的大小  
DWORD ReadDisk(unsigned char* &data, DWORD start, DWORD size)
{

	OVERLAPPED over = { 0 };
	over.Offset = start;


	//HANDLE handle = CreateFile("\\\\.\\C:", GENERIC_READ, FILE_SHARE_READ || FILE_SHARE_WRITE, 0, OPEN_EXISTING, 0, 0);//打开逻辑磁盘
	HANDLE handle = CreateFile("\\\\.\\PHYSICALDRIVE0", GENERIC_READ, FILE_SHARE_READ || FILE_SHARE_WRITE, 0, OPEN_EXISTING, 0, 0);//打开物理磁盘
																																   //HANDLE handle = CreateFile(TEXT("\\\\.\\PHYSICALDRIVE1"), GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
	if (handle == INVALID_HANDLE_VALUE)return 0;


	DWORD readsize;
	if (ReadFile(handle, data, size, &readsize, &over) == 0)
	{
		CloseHandle(handle);
		return 0;
	}
	data[size] = 0;

	CloseHandle(handle);
	return readsize;
}

DWORD WriteDisk(unsigned char* &data, DWORD start, DWORD size)
{

	OVERLAPPED over = { 0 };
	over.Offset = start;


	HANDLE handle = CreateFile("\\\\.\\C:", GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);//打开逻辑磁盘
																																			  //HANDLE handle = CreateFile("\\\\.\\PHYSICALDRIVE1", GENERIC_WRITE, 0, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);  ;//打开物理磁盘
																																			  //HANDLE handle = CreateFile(TEXT("\\\\.\\PHYSICALDRIVE0"), GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
	if (handle == INVALID_HANDLE_VALUE)return 0;

	cout << "666666" << endl;

	DWORD readsize;
	if (WriteFile(handle, data, size, &readsize, &over) == 0)
	{
		CloseHandle(handle);
		return 0;
	}
	//delete [] data;  
	//注意这里需要自己释放内存  
	CloseHandle(handle);
	cout << "SDFJKJ";
	return size;
}

int main(int argc, _TCHAR* argv[])
{
	unsigned char* data = new unsigned char[BLOCK_SIZE + 1];;

	cout << "bootloader:\n";
	DWORD len = ReadDisk(data, 0, BLOCK_SIZE);
	if (len) {
		for (int i = 0; i < len; i++) {
			printf("%02X ", data[i]);
		}
	}
	cout << endl;


	unsigned char* data1 = new unsigned char[BLOCK_SIZE + 1];;
	cout << "The 100000th block is:\n";
	len = ReadDisk(data1, 100000, BLOCK_SIZE);
	if (len) {
		for (int i = 0; i < len; i++) {
			printf("%02X ", data1[i]);
		}
	}
	cout << endl;

	unsigned char* data2 = new unsigned char[BLOCK_SIZE + 1];;
	cout << "The 10000000th block is:\n";
	len = ReadDisk(data2, 10000000, BLOCK_SIZE);
	if (len) {
		for (int i = 0; i < len; i++) {
			printf("%02X ", data2[i]);
		}
	}
	cout << endl;


	len = WriteDisk(data1, 10000000, BLOCK_SIZE);
	cout << len << endl;
	cout << "The 10000000th block is:\n";
	len = ReadDisk(data, 10000000, BLOCK_SIZE);
	if (len) {
		for (int i = 0; i < len; i++) {
			printf("%02X ", data[i]);
		}
	}
	cout << endl;


	len = WriteDisk(data2, 10000000, BLOCK_SIZE);

	cout << "The 10000000th block is:\n";
	len = ReadDisk(data2, 10000000, BLOCK_SIZE);
	if (len) {
		for (int i = 0; i < len; i++) {
			printf("%02X ", data2[i]);
		}
	}
	cout << endl;
	//printf("%d", len);

	getchar();
	return 0;
}