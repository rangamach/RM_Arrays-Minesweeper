#pragma once

namespace Gameplay
{
	class GameplayController
	{
	private:
		float remaining_time;

		void Destroy();
		void UpdateRemainingTime();

	public:
		GameplayController();
		~GameplayController();

		void Initialize();
		void Update();
		void Render();

		void Reset();
		float GetRemainingTime();
	};
}


