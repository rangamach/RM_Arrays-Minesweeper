#include "../../header/Gameplay/GameplayService.h"
#include "../../header/Gameplay/GameplayController.h"

using namespace Gameplay;

void GameplayService::Destroy()
{
	delete(gameplay_controller);
}

GameplayService::GameplayService()
{
	gameplay_controller = new GameplayController();
}

GameplayService::~GameplayService()
{
	Destroy();
}

void GameplayService::Initialize()
{
	gameplay_controller->Initialize();
}

void GameplayService::Update()
{
	gameplay_controller->Update();
}

void GameplayService::Render()
{
	gameplay_controller->Render();
}

void GameplayService::StartGame()
{
	gameplay_controller->Reset();
}

float GameplayService::GetRemainingTime()
{
	return gameplay_controller->GetRemainingTime();
}

int Gameplay::GameplayService::GetMineCount()
{
	return gameplay_controller->GetMineCount();
}
