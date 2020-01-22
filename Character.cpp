#include "stdafx.h"
#include "Character.h"

void Character::Init()
{
	_physics = object->GetComponent<Physics>();
	_transform = object->GetTransform();
	_sound = object->GetComponent<Sound>();
}

void Character::Update()
{
	if (InputManager::GetInstance()->GetKeyDown(VK_ESCAPE))
		exit(0);

	keyControl();
}

void Character::OnCollisionEnter(Object* obj)
{
	int i = 0;
	if (obj->GetTag() == "Mouse")
	{
		_transform->SetScale(Vector2(2, 2));
	}
}

void Character::OnCollisionExit(Object* obj)
{
	if (obj->GetTag() == "Mouse")
	{
		_transform->SetScale(Vector2(4, 4));
	}
}

void Character::OnCollisionStay(Object* obj)
{
	if (obj->GetTag() == "Mouse")
	{
		_transform->SetScale(Vector2(2, 2));
	}
}
void Character::keyControl()
{
	if (InputManager::GetInstance()->GetKey(VK_RIGHT))
	{
		_transform->Translate(Vector2(5, 0));
	}
	if (InputManager::GetInstance()->GetKey(VK_LEFT))
	{
		_transform->Translate(Vector2(-5, 0));
	}
	if (InputManager::GetInstance()->GetKey(VK_SPACE) && _jumpCount == 0)
	{
		_physics->AddForce(Vector2(0, -200));
		_jumpCount++;
		_sound->Play();
	}
}