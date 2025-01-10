#pragma once

#include "../Cell/CellController.h"
#include "../../UI/UIElement/ButtonView.h"

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
			int flagged_cells;

			BoardView* board_view;
			CellController* cells[number_of_rows];
			CellController* board[number_of_rows][number_of_columns];


			void CreateBoard();
			void InitializeCells();
			void DeleteBoard();
			void Destroy();

		public:

			BoardController();
			~BoardController();

			void Initialize();
			void Update();
			void Render();

			void Reset();
			int GetMineCount();
			void OpenCell(sf::Vector2i cell_pos);
			void FlagCell(sf::Vector2i cell_pos);
			void ProcessCellInput(Cell::CellController* cell_controller, UI::UIElement::ButtonType button_type);
		};
	}
}

