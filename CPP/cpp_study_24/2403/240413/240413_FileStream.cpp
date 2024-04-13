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
	// 파일이 이미 열려서 사용중이라면 다시 열지 못하게 한다.
	if (is_open_)
		return false;

	fopen_s(&file_, file_name, mode);

	if (!file_)
		return false;

	// 파일 커서를 가장 뒤로 이동시킨다.
	// fseek 함수는 파일 커서를 원하는 위치로 이동시킬 수 있는 함수.
	// 3번째 인자는 3종류가 있다.
	// SEEK_SET : 파일의 제일 처음
	// SEEK_CUR : 현재 가리키고 있는 파일 커서의 위치
	// SEEK_END : 파일의 가장 마지막
	// 2번째 인자인 offset에 들어가는 바이트 수만큼 3번째 인자에서
	// 지정한 위치에서 이동하게 된다.
	fseek(file_, 0, SEEK_END);

	// ftell : 파일 커서의 위치를 얻어오는 함수이다.
	// 위에서 파일 커서를 가장 마지막으로 이동시켰기 때문에 ftell을 이용해서
	// 파일 커서의 위치를 얻어오면 곧 파일 크기가 된다.
	file_size_ = ftell(file_);

	// 파일 크기를 구한 후에 다시 커서를 가장 앞으로 이동한다.
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
	// 파일이 열려있지 않다면 읽고 쓰기 불가능.
	if (!is_open_)
		return;

	fread(data, size, 1, file_);
}

void FileStream::ReadLine(void* data, int& size)
{
	if (!is_open_)
		return;

	char character;
	char* change_data = (char*)data; //void 포인터여서 역참조가 불가능하므로 미리 이렇게 형변환 해놓음.
	size = 0; //읽은 크기도 처음엔 0으로 초기화

	// 한글자씩 읽다가 내가 파일의 맨 마지막에 엔터를 안 쳤다면
	// 파일의 끝을 넘어서서 계속 읽을 수 있다.
	// 엔터가 없더라도 파일의 끝에 도달하면 멈춰야한다.
	// feof(end of file) 함수를 이용하면 해결이 된다.
	// feof(file_) 을 사용하면 file_의 끝에 도달하면 0이 아닌 수가 반환되고
	// 파일의 끝이 아닐 경우에는 0을 반환한다.
	// feof 함수는 파일 커서가 파일의 끝에 도달했는지를 체크한다.
	while (feof(file_) == 0)
	{
		fread(&character, 1, 1, file_);

		// 한 줄씩 읽어올 것임.
		if (character == '\n')
			break;

		change_data[size] = character;
		++size;
	}
}

void FileStream::Write(void* data, int size)
{
	// 파일이 열려있지 않다면 읽고 쓰기 불가능.
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