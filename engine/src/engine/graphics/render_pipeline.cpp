#include "render_pipeline.h"
#include "engine/engine.h"

namespace Engine::Graphics
{
	RenderPipeline::RenderPipeline()
	{
	}

	void RenderPipeline::initialize(Graphics* graphics)
	{
		m_mainTexture = graphics->createRenderTexture(240, 160);
		m_swapTexture = graphics->createRenderTexture(240, 160);

		m_testTexture = Engine::RuntimeEngine::Engine.getAssetManager()->getTexture(Resources::ResourceLocation("engine", "screentest"));
		m_grid = Engine::RuntimeEngine::Engine.getAssetManager()->getTexture(Resources::ResourceLocation("engine", "gridCell"));
		graphics->setProjectionMatrix(Matrix3x3({ 2 / static_cast<float>(m_mainTexture->getWidth()), 0, 0, 0, 2 / static_cast<float>(m_mainTexture->getHeight()), 0, 0, 0, 1 }));

		graphics->setViewMatrix(Matrix3x3({ 16, 0, 0, 0, 16, 0, 0, 0, 1 }));
	}

	void RenderPipeline::render(Graphics* graphics)
	{
		// Prepare main texture
		graphics->setRenderTarget(m_mainTexture);
		graphics->clear(1, 1, 0);

		graphics->setProjectionMatrix(Matrix3x3({ 2 / static_cast<float>(m_mainTexture->getWidth()), 0, 0, 0, 2 / static_cast<float>(m_mainTexture->getHeight()), 0, 0, 0, 1 }));
		graphics->setViewMatrix(Matrix3x3({ 16, 0, 0, 0, 16, 0, 0, 0, 1 }));



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