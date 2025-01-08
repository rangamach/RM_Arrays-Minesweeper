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
			CellController();
			~CellController();

			void Initialize();
			void Update();
			void Render();

			void Reset();
			CellState GetCellState();
			void SetCellState(CellState state);
			CellValue GetCellValue();
			void SetCellValue(CellValue value);
		};
	}
}


