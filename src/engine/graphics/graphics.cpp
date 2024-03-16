#include <iostream>
#include <SDL_image.h>
#include "graphics.h"

namespace Engine::Graphics
{
	void Graphics::loadShaders(std::shared_ptr<Resources::Registry<Shader, Resources::ShaderImporter>> shaders)
	{
		std::vector<uint32_t> textureObjects(shaders->entries().size());
		(shaders->entries().size(), textureObjects.data());

		for (int i = 0; auto& shader : shaders->entries())
		{
			loadShader(shader.second);
			++i;
		}
	}

	void Graphics::loadTextures(std::shared_ptr<Resources::Registry<Texture, Resources::TextureImporter>> textures)
	{
		std::vector<uint32_t> textureObjects(textures->entries().size());
		glGenTextures(textures->entries().size(), textureObjects.data());

		for (int i = 0; auto& texture : textures->entries())
		{
			loadTexture(texture.second, (std::filesystem::path(textures->getContentPath()) / "/" / texture.first).string(), textureObjects[i]);
			++i;
		}
	}

	void Graphics::loadMaterials()
	{
	}

	void Graphics::setRenderTarget(std::shared_ptr<RenderTexture> target)
	{
		if (target == nullptr)
		{
			glBindFramebuffer(GL_FRAMEBUFFER, 0);
			return;
		}

		glBindFramebuffer(GL_FRAMEBUFFER, target->m_fbo);
	}

	void Graphics::drawSprite(Sprite texture, Vector2Int position, Vector2Int scale, Material* material)
	{
	}

	void Graphics::drawTexture(std::shared_ptr<Texture> texture, Rect src, Rect dst)
	{

	}

	void Graphics::blit(std::shared_ptr<Texture> texture)
	{
		const uint32_t aPos = 0;
		const uint32_t aTexCoord = 1;

		glVertexAttribPointer(aPos, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), &(quad->vertices));
		glEnableVertexAttribArray(aPos);

		glVertexAttribPointer(aTexCoord, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), &(quad->texCoords));
		glEnableVertexAttribArray(aTexCoord);

		glDrawElements(GL_TRIANGLES, 2, GL_UNSIGNED_BYTE, &(quad->indices));
	}

	void Graphics::clear()
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void Graphics::present()
	{
		SDL_GL_SwapWindow(m_window->m_window);
	}

	std::shared_ptr<GameWindow> Graphics::getWindow()
	{
		return m_window;
	}

	std::shared_ptr<RenderTexture> Graphics::createRenderTexture(uint16_t width, uint16_t height)
	{
		// Make a new texture
		uint32_t texture;
		glGenTextures(1, &texture);

		glBindTexture(GL_TEXTURE_2D, texture);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA8, GL_UNSIGNED_BYTE, NULL);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);


		// Make a frame buffer
		uint32_t fbo;
		glGenFramebuffers(1, &fbo);

		glBindFramebuffer(GL_FRAMEBUFFER, fbo);

		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture, 0);


		// Unbind everything
		glBindTexture(GL_TEXTURE_2D, 0);
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		//new RenderTexture(fbo, texture, width, height)
		return std::shared_ptr<RenderTexture>();
	}

	void Graphics::loadTexture(Texture& texture, std::string path, uint32_t textureObject)
	{
		SDL_Surface* surface = IMG_Load(path.c_str());

		glBindTexture(GL_TEXTURE_2D, textureObject);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface->w, surface->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, surface->pixels);

		texture.m_width = static_cast<uint16_t>(surface->w);
		texture.m_height = static_cast<uint16_t>(surface->h);
		texture.m_texture = textureObject;

		SDL_FreeSurface(surface);
	}

	void Graphics::loadShader(Shader& texture)
	{
		
	}

	Graphics::Graphics(std::shared_ptr<GameWindow> window) :
		m_window(window)
		//m_renderer(SDL_CreateRenderer(m_window->m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE))
	{
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

		
		m_glContext = SDL_GL_CreateContext(window->m_window);
		glewExperimental = GL_TRUE;
		GLenum err = glewInit();

		quad = Quad::create();
	}
	Graphics::~Graphics()
	{
		SDL_GL_DeleteContext(m_glContext);
	}
}