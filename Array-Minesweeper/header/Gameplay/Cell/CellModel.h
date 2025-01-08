#pragma once

#include <SFML/Graphics.hpp>

namespace Gameplay
{
	namespace Cell
	{
		enum class CellState
		{
			Hidden,
			Open,
			Flagged,
		};
		enum class CellValue
		{
			Empty,
			One,
			Two,
			Three,
			Four,
			Five,
			Six,
			Seven,
			Eight,
			Mine
		};
		class CellModel
		{
		private:
			CellState cell_state;
			CellValue cell_value;
			sf::Vector2i position;

		public:
			CellModel();
			~CellModel();

			CellState GetCellState();
			void SetCellState(CellState state);
			CellValue GetCellValue();
			void SetCellValue(CellValue value);
			sf::Vector2i GetCellPosition();
			void SetCellPosition(sf::Vector2i pos);
			void Reset();
		};
	}
}

