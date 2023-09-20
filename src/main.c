#include "app.h"


int main() {
	app_t* app = app_new();

	app_run(app);
	app_kill(app);

	return 0;
}
