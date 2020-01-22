#pragma once
#include "GgaetIp.h"
class Character: public Script
{
private:
	Physics* _physics;
	Transform* _transform;
	Sound* _sound;

	int _jumpCount = 0;
public:
	virtual void Init() override;
	virtual void Update() override;

	virtual void OnCollisionEnter(Object* obj);
	virtual void OnCollisionExit(Object* obj);
	virtual void OnCollisionStay(Object* obj);


	void keyControl();


};

