#include "../../header/Global/ServiceLocator.h"
#include "../../header/Main/GameService.h"


namespace Global
{
	using namespace Graphics;
	using namespace Event;
	using namespace Sound;
	using namespace UI;
	using namespace Gameplay::Board;
	using namespace Gameplay;
	using namespace Main;

	ServiceLocator::ServiceLocator()
	{
		graphic_service = nullptr;
		event_service = nullptr;
		sound_service = nullptr;
		ui_service = nullptr;
		board_service = nullptr;
		gameplay_service = nullptr;

		createServices();
	}

	ServiceLocator::~ServiceLocator() { clearAllServices(); }

	void ServiceLocator::createServices()
	{
		event_service = new EventService();
		graphic_service = new GraphicService();
		sound_service = new SoundService();
		ui_service = new UIService();
		board_service = new BoardService();
		gameplay_service = new GameplayService();
	}

	void ServiceLocator::initialize()
	{
		graphic_service->initialize();
		sound_service->initialize();
		event_service->initialize();
		ui_service->initialize();
		board_service->Initialize();
		gameplay_service->Initialize();
	}

	void ServiceLocator::update()
	{
		event_service->update();
		ui_service->update();
		graphic_service->update();
		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
			board_service->Update();
			gameplay_service->Update();
		}
	}

	void ServiceLocator::render()
	{
		ui_service->render();
		graphic_service->render();
		if (GameService::getGameState() ==	GameState::GAMEPLAY)
		{
			board_service->Render();
			gameplay_service->Render();
		}
	}

	void ServiceLocator::clearAllServices()
	{
		delete(ui_service);
		delete(graphic_service);
		delete(sound_service);
		delete(event_service);
		delete(board_service);
		delete(gameplay_service);
	}

	ServiceLocator* ServiceLocator::getInstance()
	{
		static ServiceLocator instance;
		return &instance;
	}

	EventService* ServiceLocator::getEventService() { return event_service; }

	GraphicService* ServiceLocator::getGraphicService() { return graphic_service; }

	SoundService* ServiceLocator::getSoundService() { return sound_service; }

	UIService* ServiceLocator::getUIService() { return ui_service; }

	Gameplay::Board::BoardService* ServiceLocator::GetBoardService()
	{
		return board_service;
	}

	Gameplay::GameplayService* ServiceLocator::GetGameplayService()
	{
		return gameplay_service;
	}

	void ServiceLocator::deleteServiceLocator() { delete(this); }
}