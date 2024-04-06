#include "reset_object_visitor.h"

void Engine::Game::ResetObjectVisitor::visit(PooledObject* object)
{
	object->reset();	
}
