#pragma once

#include "../../header/Gameplay/Board/BoardService.h"

namespace Gameplay
{
	using namespace Gameplay::Board;
	enum class GameResult
	{
		None,
		Won,
		Lost,
	};
	class GameplayController
	{
	private:
		const float game_over_time = 11.f;

		float remaining_time;
		GameResult game_result = GameResult::None;
		BoardService* board_service;

		void Destroy();
		void UpdateRemainingTime();
		void GameLost();
		void GameWon();
		bool IsTimeOver();

	public:
		GameplayController();
		~GameplayController();

		void Initialize();
		void Update();
		void Render();

		void Reset();
		float GetRemainingTime();
		int GetMineCount();
		void EndGame(GameResult result);
		void BeginGameOverTimer();
		void ShowCredits();
	};
}


