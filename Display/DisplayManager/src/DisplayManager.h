#include "DisplayManagerBase.h"

namespace ThDisplay
{
	class DisplayManager : public ThDisplay::DisplayManagerBase
	{
	public:
		DisplayManager();
		~DisplayManager();

	protected:

		virtual void SetOrtho() override;
		virtual const char* GetTitle() override;
		virtual void RenderDisplay() override;

	private:

	};
}