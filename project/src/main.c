/**
* @file: main.c
* @author: Mishicoder
* 
* Punto de entrada del videojuego.
* Raylib: https://github.com/raysan5/raylib/blob/master/src/raylib.h
* Hoja de Raylib: https://www.raylib.com/cheatsheet/cheatsheet.html
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <raylib.h>
#include <stdint.h>
//#include "core/resources_manager.h"
#include "core/game.h"
#include "levels/test_level.h"

// definir funciones para cargar sprites
/*int LoadSprite(ResourcesManager* manager, const char* textureFilename, const char* name);
int LoadSpriteWithOptions(ResourcesManager* manager, const char* textureFilename, const char* dataFilename);
int LoadSpriteAtlas(ResourcesManager* manager, const char* textureFilename, const char* dataFilename);*/

int main()
{
	GameConfig config = { 0 };
	config.windowTitle = "My Farm Game";
	config.windowWidth = 800;
	config.windowHeight = 600;
	config.windowFullscreen = 0;
	config.useEscapeToExit = 1;
	config.colorBackground = (Color){ 20, 23, 21, 255 };

	Game game;
	InitGame(&game, config);
	AddLevel(&game, "test", 0, 0, 0, TL_Run);
	RunGame(&game);
	FreeGame(&game);

	return 0;
}

/*
int LoadSprite(ResourcesManager* manager, const char* textureFilename, const char* name)
{
	TextureResult result = AddTexture(manager, textureFilename);
	if (result.status == -1) return 0;

	Sprite* sprite = CreateSprite(name, result.textureIndex, 0, 0, result.textureWidth, result.textureHeight, 0);
	if (!sprite) return 0;

	AddSprite(manager, sprite);
	return 1;
}

int LoadSpriteWithOptions(ResourcesManager* manager, const char* textureFilename, const char* dataFilename)
{
	FILE* file = fopen(dataFilename, "r");
	if (file == NULL) return 0;

	TextureResult result = AddTexture(manager, textureFilename);
	if (result.status == -1)
	{
		fclose(file);
		return 0;
	}

	Sprite* sprite = NULL;

	char buffer[1024];
	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		size_t len = strlen(buffer);
		if (len > 0 && buffer[len - 1] == '\n')
			buffer[len - 1] = '\0';

		if (strlen(buffer) > 0 && buffer[0] != '#')
		{
			char* line = strdup(buffer);
			if (line != NULL)
			{
				if (strcmp(line, "@break") == 0)
				{
					free(line);
					break;
				}

				char* key = strtok(line, "=");
				char* value = strtok(NULL, "=");
				if (key != NULL && value != NULL)
				{
					if (strcmp(key, "data") == 0)
					{
						char* spriteName = strtok(value, "@");
						char* spriteData = strtok(NULL, "@");
						if (spriteName != NULL && spriteData != NULL)
						{
							char* sxStr = strtok(spriteData, ",");
							char* syStr = strtok(NULL, ",");
							if (sxStr != NULL && syStr != NULL)
							{
								int sliceX = atoi(sxStr);
								int sliceY = atoi(syStr);

								sprite = CreateSprite(spriteName, result.textureIndex, 0, 0, result.textureWidth, result.textureHeight, (sliceX * sliceY));
								if (sprite != NULL)
								{
									int frameWidth = result.textureWidth / sliceX;
									int frameHeight = result.textureHeight / sliceY;
									for (int i = 0; i < sliceY; i++)
									{
										for (int j = 0; j < sliceX; j++)
										{
											AddSpriteFrame(sprite, frameWidth * j, frameHeight * i, frameWidth, frameHeight);
										}
									}
								}
							}
						}
					}

					// animaciones
					if (strcmp(key, "anik") == 0)
					{
						char* animationName = strtok(value, "@");
						char* animationData = strtok(NULL, "@");
						if (animationName != NULL && animationData != NULL)
						{
							int animationOptions[4] = { 0, 0, 0, 0 };
							int index = 0;
							char* token;
							char* context = NULL; // hace feliz a visual studio

							token = strtok_s(animationData, ",", &context);
							while (token != NULL)
							{
								animationOptions[index] = atoi(token);
								index++;
								token = strtok_s(NULL, ",", &context);
							}
							if (sprite != NULL)
							{
								AddSpriteAnimation(
									sprite,
									animationName,
									animationOptions[0],
									animationOptions[1],
									animationOptions[2],
									animationOptions[3]
								);
							}
						}
					}
				}

				free(line);
			}
		}
	}

	if (sprite != NULL)
		AddSprite(manager, sprite);

	return 1;
}

int LoadSpriteAtlas(ResourcesManager* manager, const char* textureFilename, const char* dataFilename)
{
	FILE* file = fopen(dataFilename, "r");
	if (file == NULL) return 0;

	TextureResult result = AddTexture(manager, textureFilename);
	if (result.status == -1) 
	{
		fclose(file);
		return 0;
	}

	char buffer[1024];
	while(fgets(buffer, sizeof(buffer), file) != NULL)
	{
		size_t len = strlen(buffer);
		if (len > 0 && buffer[len - 1] == '\n')
			buffer[len - 1] = '\0';

		if (strlen(buffer) > 0 && buffer[0] != '#')
		{
			char* line = strdup(buffer);
			if (line != NULL)
			{
				char* key = strtok(line, "=");
				char* value = strtok(NULL, "=");

				if (key != NULL && value != NULL)
				{
					if (strcmp(key, "sprite") == 0)
					{
						char* spriteName = strtok(value, "[");
						char* spriteCoords = strtok(NULL, "[");

						if (spriteName != NULL && spriteCoords != NULL)
						{
							int coords[4] = { 0, 0, 0, 0 };
							int index = 0;
							char* token;
							char* context = NULL;

							token = strtok_s(spriteCoords, ",", &context);
							while (token != NULL)
							{
								coords[index] = atoi(token);
								index++;
								token = strtok_s(NULL, ",", &context);
							}
							// crear un nuevo sprite
							Sprite* newSprite = CreateSprite(
								spriteName,
								result.textureIndex,
								coords[0],
								coords[1],
								coords[2],
								coords[3],
								0
							);

							if (newSprite != NULL)
								AddSprite(manager, newSprite);
						}
					}
				}

				free(line);
			}
		}
	}

	fclose(file);
	return 1;
}
*/