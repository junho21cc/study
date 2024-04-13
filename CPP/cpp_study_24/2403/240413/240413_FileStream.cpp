#pragma once

#include "240413_FileStream.h"

FileStream::FileStream() : file_(NULL), file_size_(0), is_open_(false)
{

}

FileStream::~FileStream()
{
	Close();
}

bool FileStream::Open(const char* file_name, const char* mode)
{
	// ������ �̹� ������ ������̶�� �ٽ� ���� ���ϰ� �Ѵ�.
	if (is_open_)
		return false;

	fopen_s(&file_, file_name, mode);

	if (!file_)
		return false;

	// ���� Ŀ���� ���� �ڷ� �̵���Ų��.
	// fseek �Լ��� ���� Ŀ���� ���ϴ� ��ġ�� �̵���ų �� �ִ� �Լ�.
	// 3��° ���ڴ� 3������ �ִ�.
	// SEEK_SET : ������ ���� ó��
	// SEEK_CUR : ���� ����Ű�� �ִ� ���� Ŀ���� ��ġ
	// SEEK_END : ������ ���� ������
	// 2��° ������ offset�� ���� ����Ʈ ����ŭ 3��° ���ڿ���
	// ������ ��ġ���� �̵��ϰ� �ȴ�.
	fseek(file_, 0, SEEK_END);

	// ftell : ���� Ŀ���� ��ġ�� ������ �Լ��̴�.
	// ������ ���� Ŀ���� ���� ���������� �̵����ױ� ������ ftell�� �̿��ؼ�
	// ���� Ŀ���� ��ġ�� ������ �� ���� ũ�Ⱑ �ȴ�.
	file_size_ = ftell(file_);

	// ���� ũ�⸦ ���� �Ŀ� �ٽ� Ŀ���� ���� ������ �̵��Ѵ�.
	fseek(file_, 0, SEEK_SET);
	is_open_ = true;

	return true;
}

bool FileStream::Close()
{
	if (!is_open_)
		return false;

	is_open_ = false;
	fclose(file_);
	file_ = NULL;
	file_size_ = 0;
	return true;
}

void FileStream::Read(void* data, int size)
{
	// ������ �������� �ʴٸ� �а� ���� �Ұ���.
	if (!is_open_)
		return;

	fread(data, size, 1, file_);
}

void FileStream::ReadLine(void* data, int& size)
{
	if (!is_open_)
		return;

	char character;
	char* change_data = (char*)data; //void �����Ϳ��� �������� �Ұ����ϹǷ� �̸� �̷��� ����ȯ �س���.
	size = 0; //���� ũ�⵵ ó���� 0���� �ʱ�ȭ

	// �ѱ��ھ� �дٰ� ���� ������ �� �������� ���͸� �� �ƴٸ�
	// ������ ���� �Ѿ�� ��� ���� �� �ִ�.
	// ���Ͱ� ������ ������ ���� �����ϸ� ������Ѵ�.
	// feof(end of file) �Լ��� �̿��ϸ� �ذ��� �ȴ�.
	// feof(file_) �� ����ϸ� file_�� ���� �����ϸ� 0�� �ƴ� ���� ��ȯ�ǰ�
	// ������ ���� �ƴ� ��쿡�� 0�� ��ȯ�Ѵ�.
	// feof �Լ��� ���� Ŀ���� ������ ���� �����ߴ����� üũ�Ѵ�.
	while (feof(file_) == 0)
	{
		fread(&character, 1, 1, file_);

		// �� �پ� �о�� ����.
		if (character == '\n')
			break;

		change_data[size] = character;
		++size;
	}
}

void FileStream::Write(void* data, int size)
{
	// ������ �������� �ʴٸ� �а� ���� �Ұ���.
	if (!is_open_)
		return;

	fwrite(data, size, 1, file_);
}

void FileStream::WriteLine(void* data, int size)
{
	if (!is_open_)
		return;

	char* buffer = new char[size + 1];
	strcpy_s(buffer, size, (const char*)data);
	*(buffer + size) = '\n';

	fwrite(buffer, size + 1, 1, file_);

	delete[] buffer;
}