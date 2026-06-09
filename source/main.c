#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <3ds.h>

#define RED   "\x1B[31m"
#define GREEN   "\x1B[32m"
#define YELLOW   "\x1B[33m"
#define BLUE   "\x1B[34m"
#define MAGENTA   "\x1B[35m"
#define CYAN   "\x1B[36m"
#define WHITE   "\x1B[37m"
#define RESET "\x1B[0m"

int main(int argc, char* argv[])
{
	gfxInitDefault();
	consoleInit(GFX_TOP, NULL);
	
	PrintConsole bottomScreen, topScreen;

	consoleInit(GFX_BOTTOM, &bottomScreen);
	consoleInit(GFX_TOP, &topScreen);

	consoleSelect(&topScreen);
	printf("hello there\n");
	printf("idk what have i just created lmao\n\n");
	
	printf("press A for rainbow xd\n");
	printf("other useless information: this cool game was made by pizzawizard32\n");

	// Main loop
	while (aptMainLoop())
	{
		gspWaitForVBlank();
		gfxSwapBuffers();
		hidScanInput();

		// Your code goes here
		u32 kDown = hidKeysDown();
		u32 kHeld = hidKeysHeld();
		if (kDown & KEY_START) {
			break; // break in order to return to hbmenu
		} else if (kHeld & KEY_A) {
			consoleSelect(&bottomScreen);
			int i;
			for (i = 0; i < 25; i++) {
				printf(RED "#" RESET);
				printf(YELLOW "#" RESET);
				printf(GREEN "#" RESET);
				printf(CYAN "#" RESET);
				printf(BLUE "#" RESET);
				printf(MAGENTA "#" RESET);
			}
		}
	}

	gfxExit();
	return 0;
}
