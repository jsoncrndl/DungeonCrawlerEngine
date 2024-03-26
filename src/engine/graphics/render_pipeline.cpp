#include "render_pipeline.h"
#include "../engine.h"

namespace Engine::Graphics
{


	RenderPipeline::RenderPipeline()
	{
	}

	void RenderPipeline::initialize(std::shared_ptr<Graphics> graphics)
	{
		m_mainTexture = graphics->createRenderTexture(240, 160);
		m_swapTexture = graphics->createRenderTexture(240, 160);

		m_testTexture = Engine::RuntimeEngine::getInstance()->getAssetManager()->getTexture(Resources::ResourceLocation("engine", "screentest"));
	}

	void RenderPipeline::render(std::shared_ptr<Graphics> graphics)
	{
		// Prepare main texture
		graphics->setRenderTarget(m_mainTexture);
		graphics->clear(1, 1, 0);

		//loadedGame.render();
		//graphics->drawTexture(m_testTexture, m_testTexture->getRect(), m_mainTexture->getRect(), nullptr);

		Sprite sprite{ m_testTexture, m_testTexture->getRect() };
		graphics->drawSprite(sprite, Vector2(1, 1), Vector2(1, 1), nullptr);

		// Switch to window, scale texture and display
		graphics->setRenderTarget(nullptr);
		graphics->clear(0, 0, 0);

		graphics->drawTexture(m_mainTexture, m_mainTexture->getRect(), graphics->getWindow()->getRect(m_mainTexture->getWidth(), m_mainTexture->getHeight()), nullptr);

		graphics->present();
	}
}