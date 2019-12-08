#include "stdafx.h"
#include "BitMap.h"
CBitMap* CBitMap::m_hInstance = NULL;

CBitMap::CBitMap()
{
}

CBitMap::~CBitMap()
{
	this->Release();
}

CBitMap * CBitMap::LoadBmp(HWND hwnd, PTCHAR pFileName)
{
	m_hdc = GetDC(hwnd);
	m_MemDC = CreateCompatibleDC(m_hdc);

	m_bitMap = (HBITMAP)LoadImage(NULL, pFileName, IMAGE_BITMAP,
		0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	if (!m_bitMap)
	{
		MessageBox(hwnd, pFileName, L"File Load False", NULL);
	}

	// SelectObject�Լ��� ����� : m_MemDC�� m_bitmap�� ������ ���� �ִ� ���� �����Ѵ�.
	m_oldbitMap = (HBITMAP)SelectObject(m_MemDC, m_bitMap);

	ReleaseDC(hwnd, m_hdc);
	return this;
}

void CBitMap::Release()
{
	SelectObject(m_MemDC, m_oldbitMap);
	DeleteObject(m_bitMap);
	DeleteObject(m_oldbitMap);
	DeleteDC(m_MemDC);
}
