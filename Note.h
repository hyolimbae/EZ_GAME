#pragma once
#include "GgaetIp.h"

#define DropTime 0.45f
#define StartScale Vector2(3,3)
#define EndScale Vector2(7.f,7.f)

class Note : public ScriptComponent
{
protected:
	float pressTime;
	int keyNumber;
	float lerpCount = 0;

	TransformComponent* transform;
	SpriteComponent* sprite;

	Vector2 startPosition;
	Vector2 endPosition;
public:
	virtual void Init();
	virtual void Update();
	float GetPressTime();
	void SetPressTime(float pressTime);
	void InactiveNote();
	void SetLine(int lineNumber);
};

