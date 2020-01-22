#include "stdafx.h"
#include "GameScene.h"

#include "Mouse.h"
#include "Building.h"
#include "BuildingInfo.h"
#include "InfoBox.h"
#include "Ground.h"

void GameScene::Init()
{
	Object* ground = Object::CreateObject(); 
	ground->SetName("Ground");
	auto groundBoxCollider = ground->AddComponent<BoxCollider>();
	groundBoxCollider->SetSize(Vector2(DesignResolution.x, 100));
	ground->GetTransform()->SetPosition(Vector2(0.f, -DesignResolution.y / 2 + groundBoxCollider->GetSize().y / 2));
	ground->AddComponent<Ground>();


	// 마우스
	auto mouse = Object::CreateObject();
	mouse->SetTag("Mouse");
	mouse->AddComponent<Mouse>();
	auto mouseSprite = mouse->AddComponent<Sprite>();
	mouseSprite->SetSprite(Image::CreateImage("Sprite/Mouse_Basic.png"));
	mouseSprite->GetTransform()->SetScale(Vector2(0.5f, 0.5f));
	auto mouseSound = mouse->AddComponent<Sound>();
	auto click = AudioClip::CreateSound("Sound/SE/Click.wav");
	mouseSound->SetSound(click);
	ShowCursor(true);

	
	// 임시 House
	Object* houseTest = Object::CreateObject();
	houseTest->SetTag("House_C");
	houseTest->AddComponent<Building>();
	houseTest->AddComponent<BuildingInfo>();
	auto houseTestCollider = houseTest->AddComponent<BoxCollider>();
	houseTestCollider->SetSize(Vector2(90, 100));
	houseTest->GetTransform()->SetPosition(Vector2(-220, -110));
	// InfoBox
	Object* infoBox = Object::CreateObject();
	infoBox->AddComponent<InfoBox>();
	

	// House랑 InfoBox 링크
	infoBox->GetComponent<InfoBox>()->SetLink(houseTest);
	houseTest->GetComponent<Building>()->SetLink(infoBox);

	//================================================================
	// 임시 House2
	Object* houseTest2 = Object::CreateObject();
	houseTest2->SetTag("House_A");
	houseTest2->AddComponent<Building>();
	houseTest2->AddComponent<BuildingInfo>();
	auto houseTest2Collider = houseTest2->AddComponent<BoxCollider>();
	houseTest2Collider->SetSize(Vector2(90, 100));
	houseTest2->GetTransform()->SetPosition(Vector2(220, -110));
	// InfoBox
	Object* infoBox2 = Object::CreateObject();
	infoBox2->AddComponent<InfoBox>();


	// House랑 InfoBox 링크
	infoBox2->GetComponent<InfoBox>()->SetLink(houseTest2);
	houseTest2->GetComponent<Building>()->SetLink(infoBox2);
	//ImGuiWindow* window = ImGuiWindow::CreateImGuiWindow("TEST",Vector2(200,200));
}