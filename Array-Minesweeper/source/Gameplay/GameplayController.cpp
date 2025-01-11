#include "../../header/Gameplay/GameplayController.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Main/GameService.h"
#include "../../header/Gameplay/Board/BoardService.h"
#include "../../header/Sound/SoundService.h"

using namespace Global;
using namespace Sound;
using namespace Gameplay;
using namespace Main;

void GameplayController::Destroy()
{
}

void GameplayController::UpdateRemainingTime()
{
	remaining_time -= ServiceLocator::getInstance()->GetTimeService()->getDeltaTime();
}

void GameplayController::EndGame(GameResult result)
{
	switch (result)
	{
	case GameResult::Won:
		GameWon();
		break;
	case GameResult::Lost:
		GameLost();
		break;
	default:
		break;
	}
}

void GameplayController::BeginGameOverTimer()
{
	remaining_time = game_over_time;
}

void GameplayController::ShowCredits()
{
	GameService::setGameState(GameState::CREDITS);
}

void GameplayController::GameLost()
{
	if (game_result == GameResult::None)
	{
		game_result = GameResult::Lost;
		BeginGameOverTimer();
		board_service->ShowBoard();
		board_service->SetBoardState(BoardState::Completed);
	}
	else
	{
		ShowCredits();
	}
}

void Gameplay::GameplayController::GameWon()
{
	game_result = GameResult::Won;
	board_service->FlagAllMines();
	board_service->SetBoardState(BoardState::Completed);
	ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::COMPLETED);
}

bool Gameplay::GameplayController::IsTimeOver()
{
	return remaining_time <= 1;
}

GameplayController::GameplayController()
{
}

GameplayController::~GameplayController()
{
}

void GameplayController::Initialize()
{
	board_service = ServiceLocator::getInstance()->GetBoardService();
}

void GameplayController::Update()
{
	UpdateRemainingTime();
	if (IsTimeOver())
	{
		EndGame(GameResult::Lost);
	}
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
