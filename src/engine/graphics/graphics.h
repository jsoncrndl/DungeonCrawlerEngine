#pragma once

#include <memory>
#include <string>

#include "SDL.h"
#include <GL/glew.h>
#include "game_window.h"
#include "../math/math_types.h"
#include "render_texture.h"
#include "sprite.h"
#include "texture.h"
#include "quad.h"


/// <summary>
/// This class abstracts the main SDL graphics API for use in the engine.
/// </summary>
namespace Engine::Graphics
{
	class Graphics
	{
	private:
		std::shared_ptr<GameWindow> m_window;
		//SDL_Renderer* m_renderer;
		SDL_GLContext m_glContext;

		std::shared_ptr<Quad> quad;

		// Load a texture from an image
		std::shared_ptr<Texture> loadTexture(std::string path);

	public:
		Graphics(std::shared_ptr<GameWindow> m_window);
		~Graphics();

		void loadShaders();
		void compileShaders();

		void loadTextures();

		void loadMaterials();

		// Set the render target, or null for default window
		void setRenderTarget(std::shared_ptr<RenderTexture> target);

		// Draw a sprite to the current render target
		void drawSprite(Sprite texture, Vector2Int position, Vector2Int scale);

		void drawTexture(std::shared_ptr<Texture> texture, Rect src, Rect dst);

		void blit(std::shared_ptr<Texture> texture);

		// Clear the screen
		void clear();

		// Display the texture to the screen
		void present();

		std::shared_ptr<GameWindow> getWindow();

		// Create a new render texture
		std::shared_ptr<RenderTexture> createRenderTexture(uint16_t width, uint16_t height);
	};
}