
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
	HANDLE fileHandle = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, L"MySharedMemory");
	MyData* data = new MyData();
	if (fileHandle != nullptr)
	{
		std::cout << "Shared file Accessed..." << std::endl;
		data = (MyData*)MapViewOfFile(fileHandle, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(MyData));
		if (data != NULL)
		{
			std::cout << "MyData = { ";
			std::cout << data->i << ", ";
			std::cout << data->f << ", ";
			std::cout << data->c << ", ";
			std::cout << data->b << ", ";
			std::cout << data->d << ", ";
			std::cout << " };" << std::endl;
		}

		if (data != 0)
		{
			UnmapViewOfFile(data);
		}
	}
	else
	{
		std::cout << "Shared file does not exist. Open first application first";
	}

	system("pause");
	if (fileHandle != nullptr)
	{
		CloseHandle(fileHandle);
	}

	return 0;

}