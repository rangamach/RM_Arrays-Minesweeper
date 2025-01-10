#include "../../header/UI/Gameplay/GameplayUIController.h"
#include "../../header/UI/UIElement/TextView.h"
#include "../../header/Global/ServiceLocator.h"
#include <sstream>
#include <iomanip>

using namespace UI;
using namespace Global;

void GameplayUIController::CreateTexts()
{
	time_text = new UIElement::TextView();
}

void GameplayUIController::InitializeTexts()
{
	InitializeTimeText();
}

void GameplayUIController::InitializeTimeText()
{
	time_text->initialize("000", sf::Vector2f(time_text_left_offset, time_text_top_offset), UIElement::FontType::DS_DIGIB, font_size, text_color);
}

void GameplayUIController::UpdateTimeText()
{
	int remaining_time = ServiceLocator::getInstance()->GetGameplayService()->GetRemainingTime();
	std::stringstream stream;
	stream << std::setw(3) << std::setfill('0') << remaining_time;
	std::string string_remaining_time = stream.str();

	time_text->setText(string_remaining_time);
	time_text->update();
}

void UI::GameplayUIController::Destroy()
{
	delete(time_text);
}

GameplayUIController::GameplayUIController()
{
	CreateTexts();
}

GameplayUIController::~GameplayUIController()
{
	Destroy();
}

void GameplayUIController::Initialize()
{
	InitializeTexts();
}

void GameplayUIController::Update()
{
	UpdateTimeText();
}

void GameplayUIController::Render()
{
	time_text->render();
}

void GameplayUIController::Show()
{
	time_text->show();
}
