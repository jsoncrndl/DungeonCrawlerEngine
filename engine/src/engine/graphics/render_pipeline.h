#pragma once

#include <memory>
#include "graphics.h"
#include "render_texture.h"
#include "../resource/registry.h"
#include "texture.h"

namespace Engine::Graphics
{

	class RenderPipeline
	{
	public:
		virtual void initialize(Graphics* graphics) = 0;
		virtual void render(Graphics* graphics) = 0;
		virtual void quit(Graphics* graphics) = 0;
	};
}