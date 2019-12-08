#pragma once
#include "GameObj.h"
#include "Explosion.h"
class CZombie :
	public CGameObj
{
protected:
	BOARD Board;
	ENUM_ANIM_STATE State;
	ENUM_ANIM_STATE OldState;
	CExplosion Explosion;
	float Speed;
	int playerIndex;			// �÷��̾��� �ε��� ������ �˾Ƴ��� �Ǵ��Ѵ�.
	bool bAttackDamage;			// �� �ѹ� �������� �ֱ����� bool��
	bool StopMove;
	float Stoptime;
public:
	CZombie();
	virtual ~CZombie();

	virtual void Create(HWND hWnd) override;
	virtual void Draw(HDC hdc) override;
	virtual void Update(const float ftime) override;
	virtual void Message(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;
	virtual void Release()override;

	RECT GetRect()const { return Board.rect; }
	POINT GetPosIndex()const { return Board.pt; }
	ENUM_ANIM_STATE GetState()const { return State; }
	void SetState(ENUM_ANIM_STATE s) { State = s; }
	int GetIndex()const { return playerIndex; }
	void SetIndex(int n) { playerIndex = n; }
	int GetAttackMotion()const { return BitInfo.curFrame; }

	bool GetAttackDamage() { return bAttackDamage; }
	void SetAttackDamage(bool b) { bAttackDamage = b; }

	// �Ķ��� �Ѿ˿� ������ ����
	void SetStopMove(bool b) { StopMove = b; }
protected:
	virtual void Init();
	virtual void StateChainge(ENUM_ANIM_STATE& state) = 0;
	virtual void Animate(const float ftime, ENUM_ANIM_STATE& state);
	virtual void MoveUpdate(const float ftime);
	virtual void HpDraw(HDC hdc);
};

