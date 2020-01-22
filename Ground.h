#pragma once
#include "GgaetIp.h"
class Ground :
	public Script
{
public:
	virtual void OnCollisionEnter(Object* obj) override;
	virtual void OnCollisionStay(Object* obj) override;
	virtual void OnCollisionExit(Object* obj) override;

};

