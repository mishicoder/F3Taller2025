#include "test_level.h"

void TL_Run(Game* game, GameLevel* level)
{
	ECS_COMPONENT(level->world, C_Info);
	if (level->isComponentsAdded == 0)
	{	
		ecs_entity_t ent = ecs_entity(level->world, {.name= "player"});
		ecs_add(level->world, ent, C_Info);
		ecs_set(level->world, ent, C_Info, { "ent", "test" });

		const C_Info* info = ecs_get(level->world, ent, C_Info);
		printf("Name: %s | tag: %s\n", info->name, info->tag);

		// agregar componentes al mundo del nivel
		level->isComponentsAdded = 1;
	}

	ecs_entity_t player = ecs_lookup(level->world, "player");
	
	const C_Info* info = ecs_get(level->world, player, C_Info);
	//printf("Tag: %s\n", info->tag);
}