#pragma once
#include "GgaetIp.h"

class InfoBox;
class Building : public Script
{
private:
	Object* _infoBox;
	InfoBox* _infoBoxComponent;

	Transform* _transform;

	// Mouse 효과용
	vector<Vector2> pos;
	PolygonDraw* _polydraw;
	RECT _spriteRect;

	float _mouseX, _mouseY;

	// 메시지박스 호출용
	bool _isShowInfoBox = false;

	ImGuiText* text;

public:
	virtual void Init() override;
	virtual void Update() override;

	virtual void OnCollisionEnter(Object* obj) override;
	virtual void OnCollisionStay(Object* obj) override;
	virtual void OnCollisionExit(Object* obj) override;

	virtual void OnMouse() override;
	virtual void OnMouseExit() override;

	void SetLink(Object* ob) { _infoBox = ob; }
};