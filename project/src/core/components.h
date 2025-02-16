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

/* Gestiona la posici�n, escala y rotaci�n de la entidad */
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

	// rotaci�n de la entidad (a favor de las agujas del reloj)
	float rotation;
} C_Transfom;

/* Permite a la entidad renderizar un sprite en el mundo. */
typedef struct C_SpriteRender
{
	// Nombre del sprite que renderizar� la entidad.
	const char* spriteName;
	// Indica si el sprite es visible.
	unsigned int visible;
	// Indica la transparencia del sprite.
	unsigned int opacity; // 0 - 1
} C_SpriteRender;

/* Permite cambiar el color del componente SpriteRender de una entidad */
typedef struct C_Color
{
	// Tonalidad roja
	unsigned int r;
	// Tonalidad verde
	unsigned int g;
	// Tonalidad azul
	unsigned int b;
} C_Color;

/* Permite a la entidad renderizar un mapa de tiles. */
typedef struct C_MapRender
{
	// Nombre del mapa a renderizar.
	const char* name;
} C_MapRender;

/* En desarrollo */
typedef struct C_Behaviour
{
	void(*OnInput)(struct Game* game, struct Level* level);
	void(*OnCreate)(struct Game* game, struct Level* level);
	void(*OnUpdate)(struct Game* game, struct Level* level);
} C_Behaviour;

/* Permite que la entidad tenga colisi�n en el mundo. */
typedef struct C_RectCollider
{
	// Desplazamiento en el eje x respecto a la posici�n de la entidad.
	float offsetX;
	// Desplazamiento en el eje y respecto a la posici�n de la entidad.
	float offsetY;
	// Ancho del rect�ngulo de colisi�n.
	unsigned int width;
	// Alto del rect�ngulo de colisi�n.
	unsigned int height;
} C_RectCollider;

/*********************************************************
* componentes para eljuego
**********************************************************/

/* Controla el ciclo de d�a y noche. */
typedef struct C_DayCicle
{
	// Tiempo total que dura un d�a
	unsigned int dayTime;
	// Tiempo completo actual del d�a
	unsigned int currentTime;
	// Hora actual en el juego (por d�a)
	unsigned int currentHour;
	// Minuto actual en el juego (por d�a)
	unsigned int currentMinute;
	// Factor de tiempo que tarda un minuto en pasar
} C_DayCicle;

/* Controla el rango de colecci�n de objectos del juegador. */
typedef struct C_Collector
{
	// Desplazamiento en el eje de coordenadas x
	float offsetX;
	// Desplazamiento en el eje de coordenadas y
	float offsetY;
	// Radio de acci�n para recolectar los objectos.
	float radius;
} C_Collector;

/* Permite que un NPC tenga di�logos con lo que comunicarse con el jugador */
typedef struct C_Dialog
{
	// Di�logos en memoria
	char** dialogs;
	// Maximo de interacciones que puede tener el npc
	unsigned int maxInteractions;
} C_Dialog;

/* Permite que una entidad tenga un inventario */
typedef struct C_Inventory
{
	// Cantidad m�xima de slots que tiene el inventario.
	unsigned int maxSlots;
	// Slots del inventario
	InventorySlot* slots;

	/* No aplica para el inventario del jugador */
	// Indica si el inventario est� bloqueado por un cerrojo.
	unsigned int isLocked;
	// Indica el tipo de llave que se necesita para que sea desbloqueado.
	unsigned int keyType;
} C_Inventory;

/* Permite que el jugador tenga una barra de acci�n (inventario adicional) */
typedef struct C_HotBar
{
	// Cantidad de slots de la barra de acci�n.
	unsigned int maxSlots;
	// Slots de la barra de acci�n.
	InventorySlot* slots;
} C_HotBar;

/* Componente que dota de movimiento al jugador */
typedef struct C_Movement
{
	// Direcci�n en x de la entidad (puede ser 0, 1 o -1).
	signed int directionX;
	// Direcci�n en y de la entidad (puede ser 0, 1 o -1).
	signed int directionY;
	// Velocidad de movimiento del jugador.
	float speed;
} C_Movement;

/* Componente que permite realizar una acci�n con un item en el inventario. */
typedef struct C_Action
{
	// Controlador de acciones (lo gestiona el usuario).
	void (*OnAction)(InventorySlot* slot, ecs_entity_t playerID);
} C_Action;

/* Componente para las estad�sticas del jugador */
typedef struct C_PlayerStats
{
	// Nivel m�ximo de recolecci�n.
	unsigned int maxCollectionLevel;
	// Nivel de recolecci�n actual.
	unsigned int collectionLevel;
	// Experiencia de recolecci�n actual.
	float currentCollectionLevelExp;
	// Experiencia de recolecci�n necesaria para el siguiente nivel.
	float nextCollectionLevelExp;

	// Nivel m�ximo de granjero.
	unsigned int maxFarmerLevel;
	// Nivel de granjero actual.
	unsigned int farmerLevel;
	// Experiencia de granjero actual.
	float currentFarmerLevelExp;
	// Experiencia de granjero necesaria para el siguiente nivel.
	float nextFarmerLevelExp;

	// Nivel m�ximo de pesca.
	unsigned int maxFisingLevel;
	// Nivel de pesca actual.
	unsigned int fishingLevel;
	// Experiencia de pesca actual.
	float currentFishingLevelExp;
	// Experiencia de pesca necesaria para el siguiente nivel.
	float nextFishingLevelExp;

	// Nivel m�ximo de combate.
	unsigned int maxCombatLevel;
	// Nivel de combate actual.
	unsigned int combatLevel;
	// Experiencia de combate actual.
	float currentCombatLevelExp;
	// Experiencia de combate necesaria para el siguiente nivel.
	float nextCombatLevelExp;

	// Determina si el jugador se encuentra durmiendo o no.
	unsigned int isSleeping;

	// Vida m�xima del jugador (Solo funciona en las minas).
	float maxHealth;
	// Vida actual del jugador.
	float currentHealth;

	// Energ�a m�xima del jugador (tanto para la granja como para la cueva).
	float maxStamina;
	// Energ�a actual del jugador.
	float currentStamina;
} C_PlayerStats;

#endif // !COMPONENTS_H
