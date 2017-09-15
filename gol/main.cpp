#include "GameWindow.h"
#include "Life.h"
#include <ctime>
int main(int argc, char** argv)
{
	srand(time(NULL));
	GameWindow window = GameWindow();
	window.runHandler(new Life());
	return 0;
}