#include "../../header/UI/Gameplay/GameplayUIController.h"
#include "../../header/UI/UIElement/TextView.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Sound/SoundService.h"
#include "../../header/UI/UIElement/ButtonView.h"
#include "../../header/Global/Config.h"
#include <sstream>
#include <iomanip>

using namespace UI;
using namespace Global;
using namespace Sound;
using namespace UI::UIElement;

void GameplayUIController::CreateTexts()
{
	mine_text = new UIElement::TextView();
	time_text = new UIElement::TextView();
}

void GameplayUIController::CreateButton()
{
	restart_button = new UIElement::ButtonView();
}

void GameplayUIController::InitializeTexts()
{
	InitializeTimeText();
	InitializeMineText();
}

void GameplayUIController::InitializeTimeText()
{
	time_text->initialize("000", sf::Vector2f(time_text_left_offset, time_text_top_offset), UIElement::FontType::DS_DIGIB, font_size, text_color);
}

void GameplayUIController::InitializeMineText()
{
	mine_text->initialize("000", sf::Vector2f(mine_text_left_offset, mine_text_top_offset), UIElement::FontType::DS_DIGIB, font_size, text_color);
}

void GameplayUIController::InitializeRestartButton()
{
	restart_button->initialize("Restart", Config::restart_button_texture_path, restart_button_width, restart_button_height, sf::Vector2f(restart_button_left_offset, restart_button_top_offset));
	RegisterButtonCallback();
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

void GameplayUIController::UpdateMineText()
{
	int mine_count = ServiceLocator::getInstance()->GetGameplayService()->GetMineCount();
	std::stringstream stream;
	stream << std::setw(3) << std::setfill('0') << ServiceLocator::getInstance()->GetBoardService()->GetMineCount();
	std::string string_mine_count = stream.str();

	mine_text->setText(string_mine_count);
	mine_text->update();
}

void GameplayUIController::Destroy()
{
	delete(restart_button);
	delete(mine_text);
	delete(time_text);
}

GameplayUIController::GameplayUIController()
{
	CreateButton();
	CreateTexts();
}

GameplayUIController::~GameplayUIController()
{
	Destroy();
}

void GameplayUIController::initialize()
{
	InitializeRestartButton();
	InitializeTexts();
}

void GameplayUIController::update()
{
	restart_button->update();
	UpdateMineText();
	UpdateTimeText();
}

void GameplayUIController::render()
{
	restart_button->render();
	mine_text->render();
	time_text->render();
}

void GameplayUIController::show()
{
	restart_button->show();
	mine_text->show();
	time_text->show();
}

void GameplayUIController::RegisterButtonCallback()
{
	restart_button->registerCallbackFuntion(std::bind(&GameplayUIController::RestartButtonCallback, this));
}

void GameplayUIController::RestartButtonCallback()
{
	ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
	ServiceLocator::getInstance()->GetGameplayService()->StartGame();
}
