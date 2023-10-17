#include "App.h";

int main(int argc, char* args[])
{
	App app;
	if (app.OnInit())
	{
		int selected = -1;
		while (selected != MAIN_QUIT)
		{
			// Get selected option from Main menu
			selected = app.OnMainMenuLoop();
			if (selected != MAIN_QUIT)
			{
				app.ResetState();
				app.LoadEntities();
				app.OnLoop();
				app.DeleteEntities();
			}
		}
		app.OnShutdown();
	}
	return 0;
}