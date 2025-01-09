#include "../../header/Gameplay/Board/BoardController.h"
#include "../../header/Gameplay/Board/BoardView.h"
#include "../../header/Gameplay/Cell/CellController.h"

using namespace Gameplay::Board;
using namespace Gameplay::Cell;

void BoardController::CreateBoard()
{
	//cell_controller = new CellController();
	for (int i = 0; i < number_of_rows; i++)
	{
		/*cells[i] = new CellController(i);*/
		for (int i = 0; i < number_of_rows; i++)
		{
			for (int j = 0; j < number_of_columns; j++)
			{
				board[i][j] = new CellController(sf::Vector2i(i, j));
			}
		}
	}
}

void BoardController::InitializeCells()
{
	float cell_width = board_view->GetCellWidth();
	float cell_height = board_view->GetCellHeight();
	//cell_controller->Initialize(cell_width, cell_height);
	//for (int i = 0; i < number_of_rows; i++)
	//{
	//	cells[i]->Initialize(cell_width,cell_height);
	//}
	for (int i = 0; i < number_of_rows; i++)
	{
		for (int j = 0; j < number_of_columns; j++)
		{
			board[i][j]->Initialize(cell_width,cell_height);
		}
	}
}

void BoardController::DeleteBoard()
{
	//for (int i = 0; i < number_of_rows; i++)
	//{
	//	delete(cells[i]);
	//}
	for (int i = 0; i < number_of_rows; i++)
	{
		for (int j = 0; j < number_of_columns; j++)
		{
			delete(board[i][j]);
		}
	}
}

void BoardController::Destroy()
{
	DeleteBoard();
	delete(board_view);
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
	//cell_controller->Initialize();
	InitializeCells();
}

void BoardController::Update()
{
	board_view->Update();
	//cell_controller->Update();
	//for (int i = 0; i < number_of_rows; i++)
	//{
	//	cells[i]->Update();
	//}
	for (int i = 0; i < number_of_rows; i++)
	{
		for (int j = 0; j < number_of_columns; j++)
		{
			board[i][j]->Update();;
		}
	}
}

void BoardController::Render()
{
	board_view->Render();
	//cell_controller->Render();
	//for (int i = 0; i < number_of_rows; i++)
	//{
	//	cells[i]->Render();
	//}
	for (int i = 0; i < number_of_rows; i++)
	{
		for (int j = 0; j < number_of_columns; j++)
		{
			board[i][j]->Render();
		}
	}
}

void BoardController::Reset()
{
	//cell_controller->Reset();
	//for (int i = 0; i < number_of_rows; i++)
	//{
	//	cells[i]->Reset();
	//}
	for (int i = 0; i < number_of_rows; i++)
	{
		for (int j = 0; j < number_of_columns; j++)
		{
			board[i][j]->Reset();
		}
	}
}
