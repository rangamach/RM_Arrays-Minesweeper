#include "../../header/Gameplay/Cell/CellController.h"
#include "../../header/Gameplay/Cell/CellView.h"
#include "../../header/Gameplay/Cell/CellModel.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Sound/SoundService.h"

using namespace Gameplay::Cell;
using namespace Global;
using namespace Sound;

void CellController::Destroy()
{
	delete(cell_view);
}

CellController::CellController(sf::Vector2i index)
{
	cell_model = new CellModel(index);
	cell_view = new CellView(this);
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

sf::Vector2i CellController::GetCellIndex()
{
	return cell_model->GetCellIndex();
}

void CellController::OpenCell()
{
	ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
	SetCellState(CellState::Open);
}

void CellController::FlagCell()
{
	switch (cell_model->GetCellState())
	{
	case CellState::Flagged:
		cell_model->SetCellState(CellState::Hidden);
		break;
	case CellState::Hidden:
		cell_model->SetCellState(CellState::Flagged);
		break;
	}
	ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::FLAGGED);
}

bool CellController::CanOpenCell()
{
	return cell_model->GetCellState() != CellState::Flagged && cell_model->GetCellState() != CellState::Open;
}

