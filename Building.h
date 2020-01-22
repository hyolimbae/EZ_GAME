#pragma once
#include "GgaetIp.h"

class InfoBox;
class Building : public Script
{
private:
	Object* _infoBox;
	InfoBox* _infoBoxComponent;

	Transform* _transform;

	// Mouse ȿ����
	vector<Vector2> pos;
	PolygonDraw* _polydraw;
	RECT _spriteRect;

	float _mouseX, _mouseY;

	// �޽����ڽ� ȣ���
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