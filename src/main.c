#include <nfd.h>
#include <stdlib.h>
#include "app.h"


int main() {
	nfdchar_t* file_path = NULL;
	nfdresult_t result = NFD_OpenDialog("ch8", NULL, &file_path);

	if (result != NFD_OKAY) {
		return 1;
	}

	app_t* app = app_new();

	app_run(app);
	app_kill(app);

	free(file_path);

	return 0;
}
