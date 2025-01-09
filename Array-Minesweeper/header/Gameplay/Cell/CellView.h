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

			const float cell_top_offset = 274.f;
			const float cell_left_offset = 583.f;
			const int cell_size = 32;
			int slice_count = 12;


			void Destroy();

			void InitializeButtonImage(float width, float height);

		public:
			CellView(CellController* controller);
			~CellView();

			void Initialize(float cell_width,float cell_heightx);
			void Update();
			void Render();

			void SetCellTexture();
			sf::Vector2f GetCellPosition(float width, float height);
		};
	}
}

