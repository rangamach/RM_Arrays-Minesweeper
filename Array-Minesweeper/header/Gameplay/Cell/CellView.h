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

			const int cell_size = 32;

			void Destroy();

			void InitializeButtonImage(float width, float height);

		public:
			CellView(CellController* controller);
			~CellView();

			void Initialize();
			void Update();
			void Render();
		};
	}
}

