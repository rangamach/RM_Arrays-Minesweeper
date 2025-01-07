#include "../../header/Gameplay/Cell/CellView.h"
#include "../../header/Gameplay/Cell/CellController.h"
#include "../../header/Global/Config.h"
#include "../../header/UI/UIElement/ButtonView.h"

using namespace Gameplay::Cell;
using namespace UI::UIElement;
using namespace Global;

void CellView::Destroy()
{
	delete(cell_view);
}

void Gameplay::Cell::CellView::InitializeButtonImage(float width, float height)
{
	cell_view->initialize("Cell", Config::cells_texture_path, width, height, sf::Vector2f(0, 0));
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

void CellView::Initialize()
{
	InitializeButtonImage(cell_size*3, cell_size * 3);
}

void CellView::Update()
{
	cell_view->update();
}

void CellView::Render()
{
	cell_view->render();
}
