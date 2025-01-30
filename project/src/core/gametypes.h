#pragma once
#ifndef GAMETYPES_H
#define GAMETYPES_H

typedef struct GameItem 
{
	// nombre del sprite que renderizará el item en el inventario.
	const char* itemSprite;
	// cantidad actual del item en el inventario.
	unsigned int inStack;
	// cantidad maxima que puede haber de este item en el slot.
	unsigned int maxStack;
	// calidad del material (-1 si el material no posee calidad)
	signed int quality;
	// indica si el item se puede vender (en tienda).
	unsigned int canBeSold;
	// indica el precio de venta del item en tienda (solo si se puede vender en tienda).
	unsigned int retailPriceInStore;
	// indica el precio de venta del item en la caja de envíos.
	unsigned int retailPriceInShippingBox;
	// indica el nivel del item (solo para herramientas, si no es una herramienta: -1)
	signed int toolLevel;
	// indica el frame actual de la herramienta (afecta al sprite - siempre y cuando tenga frames)
	signed int toolLevelSpriteFrame;
} GameItem;

typedef struct InvSlot
{
	// indica el slot del item.
	unsigned int index;
	// indica el índice del item que contiene el slot (-1 si no contiene ningún item).
	signed int itemIdex;
	// indica si el slot está vacío.
	signed int isEmpty;
	// indica la cantidad del item que contiene el slot.
	unsigned int inStack;
} InventorySlot;

#endif // !GAMETYPES_H
