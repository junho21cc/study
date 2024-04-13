#pragma once

#include "240413_value.h"

class FileStream
{
public:
	FileStream();
	~FileStream();

private:
	FILE* file_;
	int file_size_;
	bool is_open_;

public:
	bool Open(const char* file_name, const char* mode);
	bool Close();
	void Read(void* data, int size); // 어떤 데이터를 읽어야 할 지 모르므로 void 포인터
	void ReadLine(void* data, int& size); // 읽을 사이즈를 지정하는게 아니라, 한 줄을 읽고나서 그 사이즈를 반환할것임.
	void Write(void* data, int size);
	void WriteLine(void* data, int size);
};