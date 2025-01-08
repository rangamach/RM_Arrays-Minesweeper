#pragma once

namespace Gameplay
{
	class GameplayController
	{
	private:
		void Destroy();

	public:
		GameplayController();
		~GameplayController();

		void Initialize();
		void Update();
		void Render();

		void Reset();
	};
}


