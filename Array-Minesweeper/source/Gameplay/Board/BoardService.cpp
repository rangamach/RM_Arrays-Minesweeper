#include "../../header/Gameplay/Board/BoardService.h"
#include "../../header/Gameplay/Board/BoardController.h"
#include "../../header/UI/UIElement/ButtonView.h"
#include "../../header/Gameplay/Cell/CellController.h"

using namespace Gameplay::Board;
using namespace Gameplay::Cell;

void BoardService::Destroy()
{
	delete(board_controller);
}

BoardService::BoardService()
{
	board_controller = nullptr;
}

BoardService::~BoardService()
{
	Destroy();
}

void BoardService::Initialize()
{
	board_controller = new BoardController();
	board_controller->Initialize();
}

void BoardService::Update()
{
	board_controller->Update();
}

void BoardService::Render()
{
	board_controller->Render();
}

void BoardService::Reset()
{
	board_controller->Reset();
}

int BoardService::GetMineCount()
{
	return board_controller->GetMineCount();
}

void BoardService::ProcessCellInput(Cell::CellController* cell_controller, UI::UIElement::ButtonType button_type)
{
	board_controller->ProcessCellInput(cell_controller, button_type);
}

BoardState BoardService::GetBoardState()
{
	return board_controller->GetBoardState();
}

void BoardService::SetBoardState(BoardState state)
{
	board_controller->SetBoardState(state);
}

void Gameplay::Board::BoardService::ShowBoard()
{
	board_controller->ShowBoard();
}


