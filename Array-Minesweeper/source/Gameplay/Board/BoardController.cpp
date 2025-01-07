#include "../../header/Gameplay/Board/BoardController.h"
#include "../../header/Gameplay/Board/BoardView.h"
#include "../../header/Gameplay/Cell/CellController.h"

using namespace Gameplay::Board;
using namespace Gameplay::Cell;

void BoardController::CreateBoard()
{
	cell_controller = new CellController();
}

void BoardController::InitializeCells()
{
}

void BoardController::ResetBoard()
{
}

void BoardController::DeleteBoard()
{
}

void BoardController::Destroy()
{
}

BoardController::BoardController()
{
	board_view = new BoardView(this);
	CreateBoard();
}

BoardController::~BoardController()
{
	Destroy();
}

void BoardController::Initialize()
{
	board_view->Initialize();
	cell_controller->Initialize();
}

void BoardController::Update()
{
	board_view->Update();
	cell_controller->Update();
}

void BoardController::Render()
{
	board_view->Render();
	cell_controller->Render();
}

void BoardController::Reset()
{
	cell_controller->Reset();
}
