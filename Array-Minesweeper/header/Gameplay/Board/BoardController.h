#pragma once

#include "../Cell/CellController.h"
#include "../../UI/UIElement/ButtonView.h"
#include <random>

using namespace Gameplay::Cell;

namespace Gameplay
{
	namespace Board
	{
		class BoardView;
		class BoardController
		{
			enum class BoardState
			{
				FirstCell,
				Playing,
				Completed,
			};
		public:
			static const int number_of_rows = 9;
			static const int number_of_columns = 9;
			static const int mine_count = 8;

		private:
			int flagged_cells;
			std::default_random_engine random_engine;
			std::random_device random_device;

			BoardView* board_view;
			CellController* board[number_of_rows][number_of_columns];

			BoardState board_state;


			void CreateBoard();
			void InitializeCells();
			void PopulateBoard(sf::Vector2i cell_position);
			void PopulateMines(sf::Vector2i cell_position);
			void PopulateCells();
			int CountMinesAround(sf::Vector2i cell_position);
			bool IsValidCellPosition(sf::Vector2i cell_position);
			void OpenAllCells();
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
			void ProcessCellValue(sf::Vector2i cell_position);
			void SetBoardState(BoardState state);
			BoardState GetBoardState();
		};
	}
}

