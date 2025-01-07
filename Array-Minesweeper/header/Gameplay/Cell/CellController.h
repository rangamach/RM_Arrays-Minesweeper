#pragma once

namespace Gameplay
{
	namespace Cell
	{
		class CellView;
		class CellController
		{
		private:
			CellView* cell_view;

			void Destroy();

		public:
			CellController();
			~CellController();

			void Initialize();
			void Update();
			void Render();

			void Reset();
		};
	}
}


