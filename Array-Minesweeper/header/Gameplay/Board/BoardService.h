#pragma once

namespace Gameplay
{
	namespace Board
	{
		class BoardController;
		class BoardService
		{
		private:
			BoardController* board_controller;

			void Destroy();

		public:
			BoardService();
			~BoardService();
			
			void Initialize();
			void Update();
			void Render();

			void Reset();
		};
	}
}

