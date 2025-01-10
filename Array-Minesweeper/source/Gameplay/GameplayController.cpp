#include "../../header/Gameplay/GameplayController.h"
#include "../../header/Global/ServiceLocator.h"

using namespace Global;
using namespace Gameplay;

void GameplayController::Destroy()
{
}

void GameplayController::UpdateRemainingTime()
{
	remaining_time -= ServiceLocator::getInstance()->GetTimeService()->getDeltaTime();
}

GameplayController::GameplayController()
{
}

GameplayController::~GameplayController()
{
}

void GameplayController::Initialize()
{
}

void GameplayController::Update()
{
	UpdateRemainingTime();
}

void GameplayController::Render()
{
}

void GameplayController::Reset()
{
	ServiceLocator::getInstance()->GetBoardService()->Reset();
}

float GameplayController::GetRemainingTime()
{
	return remaining_time;
}

int Gameplay::GameplayController::GetMineCount()
{
	return ServiceLocator::getInstance()->GetBoardService()->GetMineCount();
}
