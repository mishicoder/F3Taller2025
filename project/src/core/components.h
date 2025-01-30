#pragma once
#ifndef COMPONENTS_H
#define COMPONENTS_H

#include "gametypes.h"

struct Game;
struct Level;

typedef enum COMPONENT_TYPE
{
	INFO = 0,
	TRANSFORM,
	SPRITE_RENDER
} COMPONENT_TYPE;

/*********************************************************
* componentes generales
**********************************************************/

/* Permite que la entidad tenga nombre y etiqueta */
typedef struct Info
{
	// nombre de la entidad
	char* name;
	// etiqueta de la entidad
	char* tag;
} C_Info;

/* Capa de renderizado de la entidad (solo si tiene C_SpriteRendere) */
typedef struct C_RenderLayer
{
	// indice de la capa
	unsigned int index;
} C_RenderLayer;

/* Gestiona la posición, escala y rotación de la entidad */
typedef struct C_Transform
{
	// posicion en el eje x
	float positionX;
	// posicion en el eje y
	float positionY;

	// escala en ancho de la entidad
	float scaleX;
	// escala en alto de la entidad
	float scaleY;

	// rotación de la entidad (a favor de las agujas del reloj)
	float rotation;
} C_Transfom;

typedef struct C_SpriteRender
{
	const char* spriteID;
	unsigned int visible;
	unsigned int opacity; // 0 - 1
} C_SpriteRender;

typedef struct C_Color
{
	unsigned int r;
	unsigned int g;
	unsigned int b;
} C_Color;

typedef struct C_MapRender
{
	const char* name;
} C_MapRender;

typedef struct C_Behaviour
{
	void(*OnInput)(struct Game* game, struct Level* level);
	void(*OnCreate)(struct Game* game, struct Level* level);
	void(*OnUpdate)(struct Game* game, struct Level* level);
} C_Behaviour;

typedef struct C_RectCollider
{
	float offsetX;
	float offsetY;
	unsigned int width;
	unsigned int height;
} C_RectCollider;

/*********************************************************
* componentes para eljuego
**********************************************************/

/* Controla el ciclo de día y noche. */
typedef struct C_DayCicle
{
	// (unsigned int) Tiempo total que dura un día
	unsigned int dayTime;
	// tiempo completo actual del día
	unsigned int currentTime;
	// hora actual en el juego (por día)
	unsigned int currentHour;
	// minuto actual en el juego (por día)
	unsigned int currentMinute;
	// Factor de tiempo que tarda un minuto en pasar
} C_DayCicle;

/* Controla el rango de colección de objectos del juegador. */
typedef struct C_Collector
{
	// desplazamiento en el eje de coordenadas x
	float offsetX;
	// desplazamiento en el eje de coordenadas y
	float offsetY;
	// radio de acción para recolectar los objectos.
	float radius;
} C_Collector;

/* Permite que un NPC tenga diálogos con lo que comunicarse con el jugador */
typedef struct C_Dialog
{
	// diálogos en memoria
	char** dialogs;
	// maximo de interacciones que puede tener el npc
	unsigned int maxInteractions;
} C_Dialog;


#endif // !COMPONENTS_H
