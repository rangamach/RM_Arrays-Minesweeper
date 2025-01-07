#pragma once

#include "../Cell/CellController.h"

using namespace Gameplay::Cell;

namespace Gameplay
{
	namespace Board
	{
		class BoardView;
		class BoardController
		{
		private:
			BoardView* board_view;
			CellController* cell_controller;

			void CreateBoard();
			void InitializeCells();
			void ResetBoard();
			void DeleteBoard();
			void Destroy();

		public:
			static const int number_of_rows = 9;
			static const int number_of_columns = 0;
			static const int mine_count = 8;

			BoardController();
			~BoardController();

			void Initialize();
			void Update();
			void Render();

			void Reset();
		};
	}
}

