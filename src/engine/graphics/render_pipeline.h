#pragma once

#include <memory>
#include "graphics.h"
#include "render_texture.h"

namespace Engine::Graphics
{
	class RenderPipeline
	{
	private:
		std::shared_ptr<RenderTexture> m_mainTexture;
		std::shared_ptr<RenderTexture> m_swapTexture;

	public:
		RenderPipeline();
		void initialize(std::shared_ptr<Graphics> graphics);
		void render(std::shared_ptr<Graphics> graphics);
	};
}