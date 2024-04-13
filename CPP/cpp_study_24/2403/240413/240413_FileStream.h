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
	void Read(void* data, int size); // � �����͸� �о�� �� �� �𸣹Ƿ� void ������
	void ReadLine(void* data, int& size); // ���� ����� �����ϴ°� �ƴ϶�, �� ���� �а��� �� ����� ��ȯ�Ұ���.
	void Write(void* data, int size);
	void WriteLine(void* data, int size);
};