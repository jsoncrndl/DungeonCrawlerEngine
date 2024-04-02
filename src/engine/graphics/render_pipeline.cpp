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
		m_grid = Engine::RuntimeEngine::getInstance()->getAssetManager()->getTexture(Resources::ResourceLocation("engine", "gridCell"));
		graphics->setProjectionMatrix(Matrix3x3({ 2 / static_cast<float>(m_mainTexture->getWidth()), 0, 0, 0, 2 / static_cast<float>(m_mainTexture->getHeight()), 0, 0, 0, 1 }));

		graphics->setViewMatrix(Matrix3x3({ 16, 0, 0, 0, 16, 0, 0, 0, 1 }));
	}

	void RenderPipeline::render(std::shared_ptr<Graphics> graphics)
	{
		// Prepare main texture
		graphics->setRenderTarget(m_mainTexture);
		graphics->clear(1, 1, 0);

		graphics->setProjectionMatrix(Matrix3x3({ 2 / static_cast<float>(m_mainTexture->getWidth()), 0, 0, 0, 2 / static_cast<float>(m_mainTexture->getHeight()), 0, 0, 0, 1 }));
		graphics->setViewMatrix(Matrix3x3({ 16, 0, 0, 0, 16, 0, 0, 0, 1 }));

		//loadedGame.render();
		//graphics->drawTexture(m_testTexture, m_testTexture->getRect(), m_mainTexture->getRect(), nullptr);

		Sprite sprite{ m_grid, m_grid->getRect() };
		graphics->drawSprite(sprite, Vector2(0, 0), Vector2(1, 1), 0, nullptr);
		graphics->drawSprite(sprite, Vector2(1, 1), Vector2(1, 1), 0, nullptr);
		graphics->drawSprite(sprite, Vector2(4, 0), Vector2(1, 1), 0, nullptr);
		graphics->drawSprite(sprite, Vector2(6, 0), Vector2(1, 1), 0, nullptr);
		graphics->drawSprite(sprite, Vector2(-2, 0), Vector2(1, 1), 0, nullptr);
		graphics->drawSprite(sprite, Vector2(-4, 0), Vector2(1, 1), 0, nullptr);
		graphics->drawSprite(sprite, Vector2(-6, 0), Vector2(1, 1), 0, nullptr);


		// Switch to window, scale texture and display
		graphics->setRenderTarget(nullptr);
		graphics->clear(0, 0, 0);

		graphics->setProjectionMatrix(Matrix3x3::identity);
		graphics->setViewMatrix(Matrix3x3::identity);

		graphics->drawTexture(m_mainTexture, m_mainTexture->getRect(), graphics->getWindow()->getRect(m_mainTexture->getWidth(), m_mainTexture->getHeight()));
		//graphics->blit(m_mainTexture);

		graphics->present();
	}
}