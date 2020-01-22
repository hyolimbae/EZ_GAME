#pragma once
#include "GgaetIp.h"

#define PerfectTime 0.042f
#define GreateTime 0.085f
#define GoodTime 0.14f

class Note;

enum class Judgment
{
	None,
	Miss,
	Good,
	Greate,
	Perfect,
};

class LongNote;
class Map : public ScriptComponent
{
private:
	SpriteComponent* judgment;
	Sprite* perfectSprite;
	Sprite* greatSprite;
	Sprite* goodSprite;
	Sprite* missSprite;
	SoundComponent* sound;
	map<int,vector<Note*>> noteMap;
	map<int, LongNote*> longNoteMap;
	float startTime = 2.5f;
	float nowTime;
	bool stopMap = false;
	Judgment CheckNote(Note* note,bool deleteObject = true);
	Judgment CheckLongNote(LongNote* note);
	bool allowPlayMusic = true;
public:
	virtual void Init();
	virtual void Update();
	Judgment CheckNote(int keyNumber);
	Judgment CheckLongNote(int keyNumber);
	void PlayMusic();
	void PauseMusic();
	void ResumeMusic();
	void SetMap(map<int, vector<Note*>> notes);
};

