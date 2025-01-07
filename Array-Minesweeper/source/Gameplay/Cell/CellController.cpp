#include "../../header/Gameplay/Cell/CellController.h"
#include "../../header/Gameplay/Cell/CellView.h"

using namespace Gameplay::Cell;

void CellController::Destroy()
{
	delete(cell_view);
}

CellController::CellController()
{
	cell_view = new CellView(this);
}

CellController::~CellController()
{
	Destroy();
}

void CellController::Initialize()
{
	cell_view->Initialize();
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
}
