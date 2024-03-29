// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
// Windows 헤더 파일:
#include <windows.h>

// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
#include <iostream>
#include <string>
#include <chrono>
#include <map>
#include "TwoColor.h"
#include "FontUI.h"
#include "Point.h"

//이미지
#pragma comment(lib, "msimg32.lib")
using namespace std;

/*============================DEFINE================================*/
// 윈도우 크기
#define CLIENT_WIDTH		800
#define CLIENT_HEIGHT		600
// 사운드 갯수
#define SOUND_NUM			50
// 보드판 가로 세로 갯수
#define ROW					10
#define COLUMN				5
// 보드판 시작 점 및 보드판 사각형 크기
#define X_START				-30
#define Y_START				80
#define X_RECT				80
#define Y_RECT				100
// 카드 갯수
#define CARD_MAX			6
// 카드 크기
#define X_CARD				45
#define Y_CARD				65

// 객체 갯수
#define PLAYER_MAX			ROW * COLUMN
#define ZOMBIE_MAX			100
#define BULLET_MAX			100
#define MINERAL_MAX			100
#define LIFE_MAX			5
#define GRAVITY				9.8f
/*============================DEFINE================================*/

/*=============================ENUM=================================*/
// Scene
enum class ENUM_SCENEID :UINT
{
	LOGOSCENE,
	GAMESCENE,
	OVERSCENE,
	END
};

// SoundNum
enum ENUM_SOUNDNUM
{
	BGM1,
	BGM2,
	BGM3,
	BUTTON1,
	BUTTON2,
	BUTTON3,
	BUTTON4,
	EFFECT1,
	EFFECT2,
	EFFECT3,
	EFFECT4,
	EFFECT5,
	EFFECT6,
	EFFECT7
};
// MouseSound
enum ENUM_MOUSESOUND
{
	START_SOUND,
	END_SOUND,
	NON_SOUND,
};

enum ENUM_PLAYERS
{
	SUN,
	PLANT,
	SEED,
	BOMB,
	SNOW,
	PARABOLA,
	NON
};

enum ENUM_STATE
{
	NON_STATE,
	EXPLOSION_STATE,
	DELETE_STATE,
};

enum ENUM_ANIM_STATE
{
	NON_ANIM,
	ALIVE,
	WALK,
	ATTACK,
	DIE
};

enum ENUM_LEVEL
{
	NON_LEVEL,
	LEVEL_1,
	LEVEL_2,
	LEVEL_3,
};
/*=============================ENUM=================================*/


/*============================STRUCT================================*/
// 비트맵 정보
struct BITINFO
{
	string ID;			// id
	int sizex, sizey;	// 크기
	int curFrame;		// 현재 이미지
	int maxFrame;		// 마지막 이미지
	DWORD color;		// 투명화시킬 색
	BITINFO() :ID{ 0 }, sizex{ 0 }, sizey{ 0 }, curFrame{ 0 }, maxFrame{ 0 }, color{ 0 } {}
	BITINFO(string id, int sx, int sy, int cf, int mf, DWORD c)
		: ID{ id }, sizex{ sx }, sizey{ sy }, curFrame{ cf }, maxFrame{ mf }, color{ c } {}
};
// 보드판
struct BOARD
{
	RECT rect;
	POINT pt;
	bool being = { false };		// 보드판에 플레이어가 있는지 없는지
	BITINFO bit;				// 파이어 이미지를 보여주기위한
	bool fire = { false };		// 불 이미지를 처음에는 그리지 않음
	float frameTime;
};

struct CARD
{
	RECT rect;
	DWORD color;
	bool click{ false };
	POINT savePos;
	POINT pos = POINT{ 0,0 };
	BITINFO bit1;		// 카드 이미지
	BITINFO bit2;		// 캐릭터 이미지
	ENUM_PLAYERS type;
	float alphaSize;
	bool CoolTimeStart{ false };
	int price;
	ENUM_MOUSESOUND sound;
};
/*============================STRUCT================================*/

/*==================================================================*/
// Color 색상보간 사용에 필요한 매크로
#define PI 3.141592f
#define CLIP(minX,valX,maxX) max(minX,min(valX,maxX))
/*==================================================================*/

/*==================================================================*/
// 콘솔창 띄우기
//#ifdef UNICODE
//#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console") 
//#else
//#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console") 
//#endif
/*==================================================================*/
