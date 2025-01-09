#pragma once

#include "CellModel.h"

namespace Gameplay
{
	namespace Cell
	{
		class CellView;
		class CellController
		{
		private:
			CellView* cell_view;
			CellModel* cell_model;

			void Destroy();

		public:
			CellController(sf::Vector2i index);
			~CellController();

			void Initialize(float cell_width,float cell_height);
			void Update();
			void Render();

			void Reset();
			CellState GetCellState();
			void SetCellState(CellState state);
			CellValue GetCellValue();
			void SetCellValue(CellValue value);
			sf::Vector2i GetCellIndex();
<<<<<<< Updated upstream
=======
			void OpenCell();
			void FlagCell();
>>>>>>> Stashed changes
		};
	}
}


