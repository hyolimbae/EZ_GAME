#include "stdafx.h"
#include "Mouse.h"

void Mouse::Init()
{
	_transform = object->GetTransform();
	_sprite = object->GetComponent<Sprite>();
	_sound = object->GetComponent<Sound>();
}

void Mouse::Update()
{

	_transform->SetPosition((InputManager::GetInstance()->GetMouseWorldPosition() - DesignResolution/2)*Vector2(1,-1));

	ClickMotionAndSound();
}

void Mouse::ClickMotionAndSound()
{
	if (InputManager::GetInstance()->GetKeyDown(VK_LBUTTON))
	{
		_sound->Play();
	}

	if (InputManager::GetInstance()->GetKey(VK_LBUTTON))
	{
		_sprite->SetSprite(Image::CreateImage("Sprite/Mouse_Clicked.png"));
	}
	else
		_sprite->SetSprite(Image::CreateImage("Sprite/Mouse_Basic.png"));
}