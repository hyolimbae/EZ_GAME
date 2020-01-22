#include "stdafx.h"
#include "Building.h"
#include "InfoBox.h"

void Building::Init()
{
	_infoBoxComponent = _infoBox->GetComponent<InfoBox>();

	_transform = object->GetTransform();
	//_spriteRect = object->GetComponent<Sprite>()->GetTransform()->GetRect();
	//_polydraw = object->GetComponent<PolygonDraw>();

	//pos.push_back(Vector2(_spriteRect.left, _spriteRect.top));
	//pos.push_back(Vector2(_spriteRect.right, _spriteRect.top));

	//_polydraw->SetVertices(pos);
	//_polydraw->SetStrokeWidth(10);

	// + opacity를 0으로 설정.

	_mouseX = InputManager::GetInstance()->GetMousePosition().x;
	_mouseY = InputManager::GetInstance()->GetMousePosition().y;
	text = ImGuiText::CreateText("", "TEST");

	map<int, int> m;
	vector<int> v;
	for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
		v.push_back(it->first);
		cout << it->first << "\n";
	}
	_infoBox->SetIsActive(false);

}

void Building::Update()
{
	//text->SetText("%f", TimeManager::GetInstance()->GetDeltaTime());
}

void Building::OnCollisionEnter(Object* obj)
{

}

void Building::OnCollisionStay(Object* obj)
{

}

void Building::OnCollisionExit(Object* obj)
{

}

void Building::OnMouse()
{
	_infoBox->SetIsActive(true);
}

void Building::OnMouseExit()
{
	_infoBox->SetIsActive(false);
}