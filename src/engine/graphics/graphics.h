#pragma once

#include <memory>
#include <string>
#include <GL/glew.h>
#include <SDL.h>

#include "game_window.h"
#include "../math/math_types.h"
#include "render_texture.h"
#include "sprite.h"
#include "texture.h"
#include "quad.h"
#include "../resource/registry.h"
#include "../resource/texture_importer.h"
#include "../resource/shader_importer.h"
#include "material.h"
#include "shader.h"


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

		std::shared_ptr<Shader> m_blitShader;
		std::shared_ptr<Shader> m_defaultSpriteShader;

		GLuint vertices;
		GLuint texCoords;
		GLuint indices;

		std::shared_ptr<Quad> quad;
		std::shared_ptr<RenderTexture> m_currentTarget;

		// Load a texture from an image
		void loadTexture(std::shared_ptr<Texture> texture, std::string path, uint32_t textureObject);
		bool loadShader(std::shared_ptr<Shader> texture);

		void updateViewport();

	public:
		Graphics(std::shared_ptr<GameWindow> m_window);
		~Graphics();

		void loadShaders(std::shared_ptr<Resources::Registry<Shader, Resources::ShaderImporter>> registry);

		void loadTextures(std::shared_ptr<Resources::Registry<Texture, Resources::TextureImporter>> registry);

		void loadMaterials();

		// Set the render target, or null for default window
		void setRenderTarget(std::shared_ptr<RenderTexture> target);

		// Draw a sprite to the current render target
		void drawSprite(const Sprite& texture, const Vector2& position, const Vector2& scale, const std::shared_ptr<Material>& material);

		void drawTexture(const std::shared_ptr<Texture> texture, const Rect& src, const Rect& dst, const std::shared_ptr<Material>& material);

		void blit(std::shared_ptr<Texture> texture);

		// Perform any post content loading setup such as loading engine shaders
		void postLoad();

		// Clear the screen
		void clear();

		// Set the clear color and clear the screen
		void clear(float r, float g, float b);

		// Display the texture to the screen
		void present();

		std::shared_ptr<GameWindow> getWindow();

		// Create a new render texture
		std::shared_ptr<RenderTexture> createRenderTexture(uint16_t width, uint16_t height);
	};
}