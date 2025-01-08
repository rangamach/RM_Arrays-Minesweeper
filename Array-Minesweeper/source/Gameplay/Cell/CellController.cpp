#include "../../header/Gameplay/Cell/CellController.h"
#include "../../header/Gameplay/Cell/CellView.h"
#include "../../header/Gameplay/Cell/CellModel.h"

using namespace Gameplay::Cell;

void CellController::Destroy()
{
	delete(cell_view);
}

CellController::CellController()
{
	cell_view = new CellView(this);
	cell_model = new CellModel();
}

CellController::~CellController()
{
	Destroy();
}

void CellController::Initialize(float cell_width, float cell_height)
{
	cell_view->Initialize(cell_width,cell_height);
}

void CellController::Update()
{
	cell_view->Update();
}

void CellController::Render()
{
	cell_view->Render();
}

void Gameplay::Cell::CellController::Reset()
{
	cell_model->Reset();
}

CellState Gameplay::Cell::CellController::GetCellState()
{
	return cell_model->GetCellState();
}

void Gameplay::Cell::CellController::SetCellState(CellState state)
{
	cell_model->SetCellState(state);
}

CellValue Gameplay::Cell::CellController::GetCellValue()
{
	return cell_model->GetCellValue();
}

void Gameplay::Cell::CellController::SetCellValue(CellValue value)
{
	cell_model->SetCellValue(value);
}
