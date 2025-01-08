#include "../../header/Gameplay/Board/BoardService.h"
#include "../../header/Gameplay/Board/BoardController.h"

using namespace Gameplay::Board;

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
