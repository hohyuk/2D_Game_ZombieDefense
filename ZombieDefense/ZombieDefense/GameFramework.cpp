#include "stdafx.h"
#include "GameFramework.h"
#include "LogoScene.h"
#include "GameScene.h"
#include "OverScene.h"
CGameFramework::CGameFramework()
{
}

CGameFramework::~CGameFramework()
{
}

void CGameFramework::Create(HWND hWnd)
{
	m_hWnd = hWnd;
	// �ʱ� ȭ���� �ΰ�� �����Ѵ�.
	ChangeScene(ENUM_SCENEID::LOGOSCENE);

	if (m_pScene) m_pScene->Create(hWnd);
}

void CGameFramework::Draw(HDC hdc) const
{
	if (m_pScene) m_pScene->Draw(hdc);
}

void CGameFramework::Update(const float ftime)
{
	if (m_SceneID != ENUM_SCENEID::END)
	{
		ChangeScene_FW(m_SceneID);
		m_SceneID = ENUM_SCENEID::END;
	}
	if (m_pScene) m_pScene->Update(ftime);
}

void CGameFramework::Message(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (m_pScene) m_pScene->Message(hWnd, message, wParam, lParam);
}

void CGameFramework::Release()
{
	if (m_pScene)
	{
		m_pScene->Release();
		delete m_pScene;
		m_pScene = nullptr;
	}
}

void CGameFramework::ChangeScene(ENUM_SCENEID sceneID)
{
	m_SceneID = sceneID;
}

void CGameFramework::ChangeScene_FW(ENUM_SCENEID sceneID)
{
	Release();

	switch (sceneID)
	{
	case ENUM_SCENEID::LOGOSCENE:				// ���� ȭ�� Logo Scene
		m_pScene = new CLogoScene(this);
		break;
	case ENUM_SCENEID::GAMESCENE:				// ���� �÷��� ȭ�� Game Scene 
		m_pScene = new CGameScene(this);
		break;
	case ENUM_SCENEID::OVERSCENE:				// ���� ���� ȭ�� GameOver Scene
		m_pScene = new COverScene(this);
		break;
	default:
		break;
	}
	if (m_pScene)m_pScene->Create(m_hWnd);
}
