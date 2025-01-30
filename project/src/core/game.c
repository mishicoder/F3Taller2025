#include "game.h"

void InitGame(Game* game, GameConfig config)
{
	game->config = config;
	InitResourcesManager(&game->resourcesManager);

	InitWindow(game->config.windowWidth, game->config.windowHeight, game->config.windowTitle);
	SetWindowState(FLAG_WINDOW_RESIZABLE);
	SetWindowMinSize(game->config.windowWidth, game->config.windowHeight);

	// verifica si el juego se puede cerrar con la tecla "Escape"
	if (game->config.useEscapeToExit == 0)
	{
		SetExitKey(-1);
	}

	// verificar si el juego se incializa en pantalla completa
	if (game->config.windowFullscreen == 1)
	{
		int fsWidth = GetMonitorWidth(GetCurrentMonitor());
		int fsHeight = GetMonitorHeight(GetCurrentMonitor());
		printf("Win Width: %d | Win Height: %d\n", fsWidth, fsHeight);
		SetWindowSize(fsWidth, fsHeight);
		ToggleFullscreen();
	}

	game->levelCache = NULL;
	game->levelStack = NULL;
	game->levelCacheCount = 0;
	game->levelStackCount = 0;
}

void RunGame(Game* game)
{

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(game->config.colorBackground);

		if (game->levelStackCount > 0)
		{
			for (int i = 0; i < game->levelStackCount; i++)
			{
				game->levelStack[i]->Run(game, game->levelStack[i]);
			}
		}

		EndDrawing();
	}
}

int LoadLevel(Game* game, const char* filename)
{
	// si no se puede abrir el archivo, se retorna cero.
	FILE* levelFile = fopen(filename, "r");
	if (levelFile == NULL) return 0;

	mxml_options_t* options = mxmlOptionsNew();
	mxmlOptionsSetTypeValue(options, MXML_TYPE_OPAQUE);
	mxml_node_t* root = mxmlLoadFile(NULL, options, levelFile);
	fclose(levelFile);

	// si no se encuentra el elemento root, se retorna cero
	if (root == NULL)
	{
		mxmlOptionsDelete(options);
		return 0;
	}

	mxmlOptionsDelete(options);
	return 0;
}

int AddLevel(Game* game,
	const char* name, 
	unsigned int keepInMemory, 
	unsigned int renderInStack, 
	unsigned int updateInStack,
	void(*Run)(struct Game* game, struct GameLevel* level)
)
{
	GameLevel* level = CreateLevel(name, keepInMemory, renderInStack, updateInStack, Run);
	if (level == NULL) return 0;

	GameLevel** levelsMemTemp = (GameLevel**)realloc(game->levelStack, (size_t)(game->levelStackCount + 1) * sizeof(GameLevel*));
	if (levelsMemTemp == NULL)
	{
		UnloadLevel(level);
		return NULL;
	}

	game->levelStack = levelsMemTemp;
	game->levelStack[game->levelStackCount] = level;
	game->levelStackCount += 1;

	return 1;
}

void GameInput(Game* game)
{
}

void FreeGame(Game* game)
{
	if (game->levelStackCount > 0)
	{
		for (int i = 0; i < game->levelStackCount; i++)
		{
			UnloadLevel(game->levelStack[i]);
		}
		free(game->levelStack);
		game->levelStack = NULL;
	}

	CloseWindow();
}
