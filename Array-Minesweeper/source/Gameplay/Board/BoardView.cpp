#include "../../header/Gameplay/Board/BoardView.h"
#include "../../header/Gameplay/Board/BoardController.h"
#include "SFML/Graphics.hpp"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/UI/UIElement/ImageView.h"
#include "../../header/Global/Config.h"

using namespace sf;
using namespace Gameplay::Board;
using namespace Global;
using namespace UI::UIElement;

void BoardView::InitializeBackgroundImage()
{
	RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
	background_image->initialize(Config::background_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
	background_image->setImageAlpha(background_alpha);
}

void Gameplay::Board::BoardView::InitializeBoardImage()
{
	board_image->initialize(Config::board_texture_path, board_width, board_height, Vector2f(0, 0));
	board_image->setCentreAlinged();
}

void BoardView::Destroy()
{
	delete(background_image);
	delete(board_image);
}

BoardView::BoardView(BoardController* controller)
{
	board_controller = controller;
	background_image = new ImageView();
	board_image = new ImageView();
}

BoardView::~BoardView()
{
	Destroy();
}

void BoardView::Initialize()
{
	InitializeBackgroundImage();
	InitializeBoardImage();
}

void BoardView::Update()
{
	background_image->update();
	board_image->update();
}

void BoardView::Render()
{
	background_image->render();
	board_image->render();
}
