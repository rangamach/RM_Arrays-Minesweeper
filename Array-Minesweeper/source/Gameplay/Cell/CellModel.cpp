#include "../../header/Gameplay/Cell/CellModel.h"

using namespace Gameplay::Cell;

CellModel::CellModel()
{
}

CellModel::~CellModel() = default;

CellState CellModel::GetCellState()
{
	return cell_state;
}

void CellModel::SetCellState(CellState state)
{
	cell_state = state;
}

CellValue CellModel::GetCellValue()
{
	return cell_value;
}

void CellModel::SetCellValue(CellValue value)
{
	cell_value = value;
}

sf::Vector2i Gameplay::Cell::CellModel::GetCellPosition()
{
	return position;
}

void Gameplay::Cell::CellModel::SetCellPosition(sf::Vector2i pos)
{
	position = pos;
}
