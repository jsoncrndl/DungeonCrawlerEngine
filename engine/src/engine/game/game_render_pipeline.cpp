#include "game_render_pipeline.h"
#include "engine/engine.h"
#include "game.h"

namespace Engine::Game
{
	GameRenderPipeline::GameRenderPipeline(Game* game) : m_game(game), m_level(nullptr)
	{
	}

	void GameRenderPipeline::initialize(Graphics::Graphics* graphics)
	{
		m_mainTexture = graphics->createRenderTexture(240, 160);
		m_swapTexture = graphics->createRenderTexture(240, 160);
	}

	void GameRenderPipeline::render(Graphics::Graphics* graphics)
	{
		// Prepare main texture
		graphics->setRenderTarget(m_mainTexture);
		graphics->clear(1, 1, 0);


		m_level->render(graphics);


		// Switch to window, scale texture and display
		graphics->setRenderTarget(nullptr);
		graphics->clear(0, 0, 0);

		graphics->setProjectionMatrix(Matrix3x3::identity);
		graphics->setViewMatrix(Matrix3x3::identity);

		graphics->drawTexture(m_mainTexture, m_mainTexture->getRect(), graphics->getWindow()->getRect(m_mainTexture->getWidth(), m_mainTexture->getHeight()));

		graphics->present();
	}

	void GameRenderPipeline::quit(Graphics::Graphics* graphics)
	{

	}

	void GameRenderPipeline::setLevel(Level* level)
	{
		m_level = level;
	}
}