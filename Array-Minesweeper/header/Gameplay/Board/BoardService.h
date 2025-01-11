#pragma once

#include "../../header/UI/UIElement/ButtonView.h"
#include "../../header/Gameplay/Cell/CellController.h"
#include "../../header/Gameplay/Board/BoardController.h"

namespace Gameplay
{
	namespace Board
	{
		class CellController;
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
			int GetMineCount();
			void ProcessCellInput(Cell::CellController* cell_controller, UI::UIElement::ButtonType button_type);
			BoardState GetBoardState();
			void SetBoardState(BoardState state);
			void ShowBoard();
			void FlagAllMines();
			
		};
	}
}

