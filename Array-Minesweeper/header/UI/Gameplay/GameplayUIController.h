#pragma once

#include "../../header/UI/Interface/IUIController.h"
#include "../UIElement/TextView.h"
#include <SFML/Graphics.hpp>

namespace UI
{
	class GameplayUIController : public Interface::IUIController
	{
	private:
		const int font_size = 110;
		const sf::Color text_color = sf::Color::Red;
		const float time_text_top_offset = 65.f;
		const float time_text_left_offset = 1090.f;
		const float mine_text_top_offset = 65.f;
		const float mine_text_left_offset = 660.f;

		UI::UIElement::TextView* time_text;
		UI::UIElement::TextView* mine_text;

		void CreateTexts();
		void InitializeTexts();
		void InitializeTimeText();
		void InitializeMineText();
		void UpdateTimeText();
		void UpdateMineText();

		void Destroy();

	public:
		GameplayUIController();
		~GameplayUIController();

		void Initialize();
		void Update();
		void Render();

		void Show();
		
	};
}

