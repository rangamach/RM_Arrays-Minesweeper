#include "../../header/Gameplay/Board/BoardController.h"
#include "../../header/Gameplay/Board/BoardView.h"
#include "../../header/Gameplay/Cell/CellController.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Sound/SoundService.h"



using namespace Gameplay::Board;
using namespace Gameplay::Cell;
using namespace Global;
using namespace Sound;

void BoardController::CreateBoard()
{
	for (int i = 0; i < number_of_rows; i++)
	{
		for (int i = 0; i < number_of_rows; i++)
		{
			for (int j = 0; j < number_of_columns; j++)
			{
				board[i][j] = new Gameplay::Cell::CellController(sf::Vector2i(i, j));
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

void BoardController::PopulateBoard(sf::Vector2i cell_position)
{
	PopulateMines(cell_position);
}

void BoardController::PopulateMines(sf::Vector2i cell_position)
{
	std::uniform_int_distribution<int> x_distribution(0, number_of_columns - 1);
	std::uniform_int_distribution<int> y_distribution(0, number_of_rows - 1);

	for (int m = 0; m < mine_count; m++)
	{
		int i = static_cast<int>(x_distribution(random_engine));
		int j = static_cast<int>(y_distribution(random_engine));

		if (board[i][j]->GetCellValue() == CellValue::Mine || (cell_position.x == i && cell_position.y == j)) m--;
		else board[i][j]->SetCellValue(CellValue::Mine);
	}
}

void BoardController::PopulateCells()
{
	for (int m = 0; m < number_of_rows; m++)
	{
		for (int n = 0; n < number_of_columns; n++)
		{
			if (board[m][n]->GetCellValue() != CellValue::Mine)
			{
				CellValue value = static_cast<CellValue>(CountMinesAround(sf::Vector2i(m, n)));
				board[m][n]->SetCellValue(value);
			}
		}
	}
}

int BoardController::CountMinesAround(sf::Vector2i cell_position)
{
	int mines_around = 0;
	for (int m = -1; m < 2; m++)
	{
		for (int n = -1; n < 2; n++)
		{
			if (m == 0 && n == 0 || !IsValidCellPosition(sf::Vector2i(cell_position.x + m, cell_position.y + n))) continue;
			if (board[m + cell_position.x][n + cell_position.y]->GetCellValue() == CellValue::Mine) mines_around++;
		}
	}
	return mines_around;
}

bool BoardController::IsValidCellPosition(sf::Vector2i cell_position)
{
	return cell_position.x>=0 && cell_position.y>=0 && cell_position.x <number_of_columns && cell_position.y < number_of_rows;
}

void BoardController::OpenAllCells()
{
	for (int m = 0; m < number_of_rows; ++m)
	{
		for (int n = 0; n < number_of_columns; ++n)
		{
			board[m][n]->OpenCell();
		}
	}
}

void BoardController::OpenEmptyCells(sf::Vector2i cell_position)
{
	switch (board[cell_position.x][cell_position.y]->GetCellState())
	{
	case CellState::Open:
		return;
	case CellState::Flagged:
		flagged_cells--;
	default:
		board[cell_position.x][cell_position.y]->OpenCell();
		break;
	}

	for (int m = 0; m < 2; m++)
	{
		for (int n = 0; n < 2; n++)
		{
			if ((m == 0 && n == 0) || !IsValidCellPosition(sf::Vector2i(m + cell_position.x, n + cell_position.y)))
				continue;
			sf::Vector2i next_cell_position = sf::Vector2i(m + cell_position.x, n + cell_position.y);
			OpenCell(next_cell_position);
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

BoardController::BoardController() : random_engine(random_device())
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
	board_state = BoardState::FirstCell;
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
	return mine_count - flagged_cells;
}

void BoardController::OpenCell(sf::Vector2i cell_pos)
{
	if (board[cell_pos.x][cell_pos.y]->CanOpenCell())
	{
		if (board_state == BoardState::FirstCell)
		{
			PopulateBoard(cell_pos);
			board_state = BoardState::Playing;
		}
		ProcessCellValue(cell_pos);
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
	if (board_state == BoardState::Completed)
	{
		return;
	}

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

void BoardController::ProcessCellValue(sf::Vector2i cell_position)
{
	switch (board[cell_position.x][cell_position.y]->GetCellValue())
	{
	case CellValue::Empty:
		ProcessEmptyCell(cell_position);
		break;
	case CellValue::Mine:
		break;
	default:
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
		break;
	}
}

void BoardController::ProcessEmptyCell(sf::Vector2i cell_position)
{
	ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
	OpenEmptyCells(cell_position);
}

void BoardController::ProcessMineCell(sf::Vector2i cell_position)
{
	ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::EXPLOSION);
}

void BoardController::ShowBoard()
{
	switch (ServiceLocator::getInstance()->GetBoardService()->GetBoardState())
	{
	case BoardState::FirstCell:
		PopulateBoard(sf::Vector2i(0, 0));
		OpenAllCells();
		break;
	case BoardState::Playing:
		OpenAllCells();
		break;
	case BoardState::Completed:
		break;
	default:
		break;
	}
}

void BoardController::SetBoardState(BoardState state)
{
	board_state = state;
}

BoardState Gameplay::Board::BoardController::GetBoardState()
{
	return board_state;
}

void BoardController::FlagAllMines()
{
	for (int row = 0; row < number_of_rows; ++row)
	{
		for (int col = 0; col < number_of_columns; ++col)
		{
			if (board[row][col]->GetCellValue() == CellValue::Mine && board[row][col]->GetCellState() != CellState::Flagged)
			{
				FlagCell(sf::Vector2i(row, col));
			}
		}
	}
}

