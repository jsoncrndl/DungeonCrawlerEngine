#pragma once
#include "engine/graphics/render_texture.h"
#include "engine/graphics/texture.h"
#include "engine/graphics/render_pipeline.h"
#include "engine/game/level/level.h"

namespace Engine::Game
{
	class Game;
	class GameRenderPipeline : public Graphics::RenderPipeline
	{

	private:
		std::shared_ptr<Graphics::RenderTexture> m_mainTexture;
		std::shared_ptr<Graphics::RenderTexture> m_swapTexture;
		Game* m_game;
		Level* m_level;

	public:
		GameRenderPipeline(Game* game);
		virtual void initialize(Graphics::Graphics* graphics) override;
		virtual void render(Graphics::Graphics* graphics) override;
		virtual void quit(Graphics::Graphics* graphics) override;
		void setLevel(Level* level);
	};
}