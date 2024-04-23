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
	private:
		std::shared_ptr<RenderTexture> m_mainTexture;
		std::shared_ptr<RenderTexture> m_swapTexture;
		std::shared_ptr<Texture> m_testTexture;
		std::shared_ptr<Texture> m_grid;

	public:
		RenderPipeline();
		void initialize(Graphics* graphics);
		void render(Graphics* graphics);
	};
}