#include <Windows.h>
#include <iostream>

struct MyData
{
	int i;
	float f;
	char c;
	bool b;
	double d;
};

int main()
{
	HANDLE fileHandle = CreateFileMapping(INVALID_HANDLE_VALUE, nullptr, PAGE_READWRITE, 0, sizeof(MyData), L"MySharedMemory");
	MyData* data = new MyData();
	MyData myData;

	myData.i = 7;
	myData.f = 2.5f;
	myData.c = 'g';
	myData.b = false;
	myData.d = 8.99;

	if (fileHandle != nullptr)
	{
		data = (MyData*)MapViewOfFile(fileHandle, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(MyData));
		if (data != NULL)
		{
			*data = myData;
		}
		if (data != 0)
		{
			UnmapViewOfFile(data);
		}
	}
	std::cout << "Sharing File..." << std::endl;
	system("pause");
	if (fileHandle != nullptr)
	{
		CloseHandle(fileHandle);
	}
	return 0;
}