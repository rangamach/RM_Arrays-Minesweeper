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

			sf::Vector2i cell_index;

		public:
			CellModel(sf::Vector2i index);
			~CellModel();

			CellState GetCellState();
			void SetCellState(CellState state);
			CellValue GetCellValue();
			void SetCellValue(CellValue value);
			sf::Vector2i GetCellPosition();
			void SetCellPosition(sf::Vector2i pos);
			sf::Vector2i GetCellIndex();
			void Reset();
		};
	}
}

