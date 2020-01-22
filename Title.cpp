#include "stdafx.h"
#include "Title.h"
#include "TestScene.h"

void Title::Init()
{
	ApplicationManager::GetInstance()->SetResolution(600, 600, false);
	SceneManager::GetInstance()->PushScene(new TestScene);
}