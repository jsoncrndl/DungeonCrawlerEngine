#include "render_pipeline.h"

namespace Engine::Graphics
{


	RenderPipeline::RenderPipeline()
	{
	}

	void RenderPipeline::initialize(std::shared_ptr<Graphics> graphics)
	{
		m_mainTexture = graphics->createRenderTexture(240, 160);
		m_swapTexture = graphics->createRenderTexture(240, 160);
	}

	void RenderPipeline::render(std::shared_ptr<Graphics> graphics)
	{
		graphics->setRenderTarget(m_mainTexture);
		graphics->clear();

		// Draw game
		//graphics->drawSprite(Sprite(), Vector2Int(), Vector2Int());
		
		// Switch to screen target
		graphics->setRenderTarget(nullptr);
		graphics->clear();

		graphics->drawTexture(m_mainTexture, m_mainTexture->getRect(), graphics->getWindow()->getRect(240, 160));
		graphics->present();
	}
}