#include "stdafx.h"
#include "Title.h"
#include "GameScene.h"

void Title::Init()
{
	ApplicationManager::GetInstance()->SetResolution(1200, 700, false);
	SceneManager::GetInstance()->PushScene(new GameScene);
}