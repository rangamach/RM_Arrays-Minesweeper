#include "../../header/Gameplay/Board/BoardController.h"
#include "../../header/Gameplay/Board/BoardView.h"

using namespace Gameplay::Board;

void BoardController::CreateBoard()
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
}

BoardController::~BoardController()
{
}

void BoardController::Initialize()
{
	board_view->Initialize();
}

void BoardController::Update()
{
	board_view->Update();
}

void BoardController::Render()
{
	board_view->Render();
}

void BoardController::Reset()
{
}
