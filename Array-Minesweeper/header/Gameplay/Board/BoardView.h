#pragma once
#include "../../UI/UIElement/ImageView.h"

using namespace UI::UIElement;

namespace Gameplay
{
	namespace Board
	{
		class BoardController;
		class BoardView
		{
		private:
			BoardController* board_controller;
			ImageView* background_image;
			ImageView* board_image;
			
			const float background_alpha = 85.f;
			const float board_width = 866.f;
			const float board_height = 1080.f;

			void InitializeBackgroundImage();
			void InitializeBoardImage();
			void Destroy();
		
		public:
			BoardView(BoardController* controller);
			~BoardView();

			void Initialize();
			void Update();
			void Render();
		};
	}
}


