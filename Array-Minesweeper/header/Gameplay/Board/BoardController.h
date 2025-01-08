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
		public:
			static const int number_of_rows = 9;
			static const int number_of_columns = 9;
			static const int mine_count = 8;

		private:
			BoardView* board_view;
			//CellController* cell_controller;
			CellController* cells[number_of_rows];
			CellController* board[number_of_rows][number_of_columns];


			void CreateBoard();
			void InitializeCells();
			//void ResetBoard();
			void DeleteBoard();
			void Destroy();

		public:

			BoardController();
			~BoardController();

			void Initialize();
			void Update();
			void Render();

			void Reset();
		};
	}
}

