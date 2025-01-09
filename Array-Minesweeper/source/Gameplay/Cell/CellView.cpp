#include "../../header/Gameplay/Cell/CellView.h"
#include "../../header/Gameplay/Cell/CellController.h"
#include "../../header/Global/Config.h"
#include "../../header/UI/UIElement/ButtonView.h"
#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>

using namespace Gameplay::Cell;
using namespace UI::UIElement;
using namespace Global;
using namespace std;

void CellView::Destroy()
{
	delete(cell_view);
}

void CellView::InitializeButtonImage(float width, float height)
{
	sf::Vector2f cell_position = GetCellPosition(width,height);
	cell_view->initialize("Cell", Config::cells_texture_path, width * slice_count, height, cell_position);
}

CellView::CellView(CellController* controller)
{
	cell_controller = controller;
	cell_view = new ButtonView();
}

CellView::~CellView()
{
	Destroy();
}

void CellView::Initialize(float cell_width,float cell_height)
{
	InitializeButtonImage(cell_width, cell_height);
}

void CellView::Update()
{
	cell_view->update();
}

void CellView::Render()
{
	SetCellTexture();
	cell_view->render();
}

void CellView::SetCellTexture()
{
	int index = static_cast<int>(cell_controller->GetCellValue());
	switch (cell_controller->GetCellState())
	{
	case CellState::Hidden:
		cell_view->setTextureRect(sf::IntRect(10 * cell_size, 0, cell_size, cell_size));
		break;
	case CellState::Open:
		cell_view->setTextureRect(sf::IntRect(index * cell_size, 0, cell_size, cell_size));
		break;
	case CellState::Flagged:
		cell_view->setTextureRect(sf::IntRect(11 * cell_size, 0, cell_size, cell_size));
		break;
	}
}

sf::Vector2f Gameplay::Cell::CellView::GetCellPosition(float width, float height)
{
	sf::Vector2i cell_index = cell_controller->GetCellIndex();
	float x = cell_left_offset + cell_index.y * width;
	float y = cell_top_offset + cell_index.x * height;
	return sf::Vector2f(x, y);
}

void Gameplay::Cell::CellView::RegisterButtonCallBack()
{
	cell_view->registerCallbackFuntion(std::bind(&CellView::CellButtonCallBack, this, std::placeholders::_1));
}


void CellView::CellButtonCallBack(UI::UIElement::ButtonType button_type)
{
	
}
