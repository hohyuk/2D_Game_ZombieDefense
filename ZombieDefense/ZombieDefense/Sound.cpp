#include "stdafx.h"
#include "Sound.h"

CSound::CSound()
{
	CSound::Init();
	CSound::Set_sound();
}

CSound::~CSound()
{
	CSound::Release();
}

void CSound::Init()
{
	// �ý����� ũ������Ʈ
	FMOD::System_Create(&m_pSystem);
	// �ý����� Init
	m_pSystem->init(SOUND_NUM, FMOD_INIT_NORMAL, nullptr);
	// ���带 null���·� �ʱ�ȭ
	for (int i = 0; i < SOUND_NUM; ++i)
		m_pSounds[i] = nullptr;
}

void CSound::Release()
{
	// ���带 ������
	for (int i = 0; i < SOUND_NUM; ++i)
		m_pSounds[i]->release();

	// �ý��� ������
	m_pSystem->release();

	// �ý��� �ݱ�
	m_pSystem->close();
}

void CSound::Set_sound()
{
	// BGM
	// Logo
	m_pSystem->createStream("../Sound/LogoBgm.mp3", FMOD_2D | FMOD_LOOP_NORMAL	//FMOD_LOOP_NORMAL �ݺ����� �뷡
		,nullptr
		, &m_pSounds[BGM1]	// ���° �뷡�� Ʋ����?
	);	
	// Game
	m_pSystem->createStream("../Sound/GameBgm.mp3", FMOD_2D | FMOD_LOOP_NORMAL, nullptr, &m_pSounds[BGM2]);
	m_pSystem->createStream("../Sound/skyway.mp3", FMOD_2D | FMOD_LOOP_NORMAL, nullptr, &m_pSounds[BGM3]);

	

	// ��ư
	m_pSystem->createStream("../Sound/UI_button2.wav", FMOD_DEFAULT | FMOD_LOOP_OFF	, nullptr, &m_pSounds[BUTTON1]);
	m_pSystem->createStream("../Sound/UI_button.wav", FMOD_DEFAULT | FMOD_LOOP_OFF	, nullptr, &m_pSounds[BUTTON2]);
	m_pSystem->createStream("../Sound/button3.wav", FMOD_DEFAULT | FMOD_LOOP_OFF, nullptr, &m_pSounds[BUTTON3]);

	// �Ĺ� �ɱ�
	m_pSystem->createStream("../Sound/Sound01.wav", FMOD_DEFAULT | FMOD_LOOP_OFF, nullptr, &m_pSounds[EFFECT1]);
	m_pSystem->createStream("../Sound/Sound02.wav", FMOD_DEFAULT | FMOD_LOOP_OFF, nullptr, &m_pSounds[EFFECT2]);
	m_pSystem->createStream("../Sound/Sound03.wav", FMOD_DEFAULT | FMOD_LOOP_OFF, nullptr, &m_pSounds[EFFECT3]);
	m_pSystem->createStream("../Sound/Sound04.wav", FMOD_DEFAULT | FMOD_LOOP_OFF, nullptr, &m_pSounds[EFFECT4]);
	m_pSystem->createStream("../Sound/explosion_01.wav", FMOD_DEFAULT | FMOD_LOOP_OFF, nullptr, &m_pSounds[EFFECT5]);
	m_pSystem->createStream("../Sound/charge_tune.wav", FMOD_DEFAULT | FMOD_LOOP_OFF, nullptr, &m_pSounds[EFFECT6]);
}

void CSound::Play(size_t soundid)
{
	// ������Ʈ�� ������ ������ ������ �����ִ�.
	m_pSystem->update();

	m_pSystem->playSound(m_pSounds[soundid], nullptr, false, &m_pChannel[soundid]);
}
