#pragma once
#include <windows.h>

void write_clipboard(const char* msg)
{
	OpenClipboard(0);
	EmptyClipboard();
	const size_t lenght = strlen(msg) + 1;
	HGLOBAL h = GlobalAlloc(GMEM_MOVEABLE, lenght);
	memcpy(GlobalLock(h), msg, lenght);
	GlobalUnlock(h);
	SetClipboardData(CF_TEXT, h);
	CloseClipboard();
}

const char* read_clipboard()
{
	OpenClipboard(0);
	HANDLE msg = GetClipboardData(CF_TEXT);
	CloseClipboard();
	return (const char*)msg;
}