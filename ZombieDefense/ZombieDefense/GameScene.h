#pragma once
#include "Scene.h"
#include "BackGround.h"
#include "Card.h"
#include "UI.h"

class CPlayer;
class CZombie;
class CMineral;
class CBullet;

class CGameScene:public CScene
{
	CBackGround mBackGround;
	CCard mCard;
	CUI mUI;
	int Cardindex;		// ī��
	
	CPlayer* mPlayer[PLAYER_MAX] = { nullptr };
	CZombie* mZombie[ZOMBIE_MAX] = { nullptr };
	CMineral* mMineral[MINERAL_MAX] = { nullptr };
	CBullet* mBullet[BULLET_MAX] = { nullptr };
	// �ð�
	float MineralTime;		// �帣�� �ð� (����)
	float MaxMineralTime;	// ���� �ð�
	float ZombieTime;		// ���� ���� �ð�
	float MaxZombieTime;
	// ���
	bool Life[LIFE_MAX];

	// ���� �ε���
	int ZombieIndex;
	// ��ü �ð� 
	float BalanceTime;
	int Level;
	bool GameStart;
public:
	CGameScene(CGameFramework * ptFW);
	virtual ~CGameScene();

	virtual void Create(HWND hWnd) override;
	virtual void Draw(HDC hdc) override;
	virtual void Update(const float ftime) override;
	virtual void Message(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;
	virtual void Release() override;

private:
	void CreateBitPath(HWND hWnd);
	void LButton(LPARAM lParam);
	void LButtonUP(LPARAM lParam);
	void CreatePlayers(LPARAM lParam);
	void DeletePlayers(LPARAM lParam);
	void DeletePlayers(CPlayer*& player);
	void CreateMineral(CMineral*& mineral);
	void DeleteMineral(CMineral*& mineral);
	void CreateZombie(CZombie*& zombie);
	void DeleteZombie(CZombie*& zombie);
	void CreateBullect(CPlayer*& player);
	bool ZombieBeing(CPlayer*& player);
	void DeleteBullect(CBullet*& bullet);

	// �浹 üũ
	void ZombieAndPlayerCollision(CZombie*& zombie);
	void BulletAndZombieCollision(CBullet*& bullet);
	void BombAndZombieCollision(CPlayer*& bomb);
};

