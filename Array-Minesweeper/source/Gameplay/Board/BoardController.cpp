#include "../../header/Gameplay/Board/BoardController.h"
#include "../../header/Gameplay/Board/BoardView.h"
#include "../../header/Gameplay/Cell/CellController.h"

using namespace Gameplay::Board;
using namespace Gameplay::Cell;

void BoardController::CreateBoard()
{
	for (int i = 0; i < number_of_rows; i++)
	{
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
	InitializeCells();
}

void BoardController::Update()
{
	board_view->Update();
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
	flagged_cells = 0;
	for (int i = 0; i < number_of_rows; i++)
	{
		for (int j = 0; j < number_of_columns; j++)
		{
			board[i][j]->Reset();
		}
	}
}

int BoardController::GetMineCount()
{
	return mine_count;
}

void BoardController::OpenCell(sf::Vector2i cell_pos)
{
	if (board[cell_pos.x][cell_pos.y]->CanOpenCell())
	{
		board[cell_pos.x][cell_pos.y]->OpenCell();
	}
}

void BoardController::FlagCell(sf::Vector2i cell_pos)
{
	switch (board[cell_pos.x][cell_pos.y]->GetCellState())
	{
	case CellState::Flagged:
		flagged_cells--;
		break;
	case CellState::Hidden:
		flagged_cells++;
		break;
	default:
		break;
	}
	board[cell_pos.x][cell_pos.y]->FlagCell();
}

void BoardController::ProcessCellInput(Cell::CellController* cell_controller, UI::UIElement::ButtonType button_type)
{
	switch (button_type)
	{
	case UI::UIElement::ButtonType::LEFT_MOUSE_BUTTON:
		OpenCell(cell_controller->GetCellIndex());
		break;
	case UI::UIElement::ButtonType::RIGHT_MOUSE_BUTTON:
		FlagCell(cell_controller->GetCellIndex());
		break;
	default:
		break;
	}
}
