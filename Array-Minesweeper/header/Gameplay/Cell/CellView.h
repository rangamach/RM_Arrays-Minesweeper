#pragma once
#include "../../UI/UIElement/ButtonView.h"

namespace Gameplay
{
	namespace Cell
	{
		class CellController;
		class CellView
		{
		private:
			UI::UIElement::ButtonView* cell_view;
			CellController* cell_controller;
			sf::Sprite* sprite;

			const int cell_size = 32;
			int slice_count = 12;


			void Destroy();

			void InitializeButtonImage(float width, float height);

		public:
			CellView(CellController* controller);
			~CellView();

			void Initialize();
			void Update();
			void Render();

			void SetCellTexture();
		};
	}
}

