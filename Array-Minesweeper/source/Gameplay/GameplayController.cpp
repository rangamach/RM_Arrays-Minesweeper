#include "../../header/Gameplay/GameplayController.h"
#include "../../header/Global/ServiceLocator.h"

using namespace Global;
using namespace Gameplay;

void GameplayController::Destroy()
{
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
}

void GameplayController::Render()
{
}

void GameplayController::Reset()
{
	ServiceLocator::getInstance()->GetBoardService()->Reset();
}
