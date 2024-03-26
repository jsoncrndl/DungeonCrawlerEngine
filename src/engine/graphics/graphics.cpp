#include <iostream>
#include <SDL_image.h>
#include "graphics.h"
#include "../engine.h"

namespace Engine::Graphics
{
	void GLAPIENTRY
		MessageCallback(GLenum source,
			GLenum type,
			GLuint id,
			GLenum severity,
			GLsizei length,
			const GLchar* message,
			const void* userParam)
	{
		fprintf(stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
			(type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : ""),
			type, severity, message);
	}

	void Graphics::loadShaders(std::shared_ptr<Resources::Registry<Shader, Resources::ShaderImporter>> shaders)
	{
		for (auto& shader : shaders->entries())
		{
			shader.second->isValid = loadShader(shader.second);
		}
	}

	void Graphics::loadTextures(std::shared_ptr<Resources::Registry<Texture, Resources::TextureImporter>> textures)
	{
		std::vector<uint32_t> textureObjects(textures->entries().size());
		glGenTextures(textures->entries().size(), textureObjects.data());

		for (int i = 0; auto texture : textures->entries())
		{
			loadTexture(texture.second, (std::filesystem::path(textures->getContentPath()) / texture.first).replace_extension(".png").string(), textureObjects[i]);
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
		}
		else
		{
			glBindFramebuffer(GL_FRAMEBUFFER, target->m_fbo);
		}

		m_currentTarget = target;
		updateViewport();
	}

	void Graphics::drawSprite(const Sprite& sprite, const Vector2& position, const Vector2& scale, const std::shared_ptr<Material>& material)
	{
		std::shared_ptr<Shader> shader;

		if (material == nullptr)
		{
			shader = m_defaultSpriteShader;
		}
		else
		{
			shader = material->getShader();
		}

		glBindVertexArray(quad->vao);
		glUseProgram(shader->programID);

		Rect renderTargetRect{ 0, 0, 0, 0 };

		if (m_currentTarget == nullptr)
		{
			renderTargetRect = m_window->getRect();
		}
		else
		{
			renderTargetRect = m_currentTarget->getRect();
		}

		float vertexTransform[] = {
			scale.x * sprite.getRect().getWidth() / renderTargetRect.getWidth(), 0, 0,
			0, scale.y * sprite.getRect().getHeight() / renderTargetRect.getHeight(), 0,
			position.x, position.y, 1
		};

		float texCoordsTransform[] = {
			static_cast<float>(sprite.getRect().getWidth()) / static_cast<float>(sprite.getTexture()->getWidth()), 0, 0,
			0, static_cast<float>(sprite.getRect().getHeight()) / static_cast<float>(sprite.getTexture()->getHeight()), 0,
			sprite.getRect().getX() / sprite.getTexture()->getWidth(), sprite.getRect().getY() / sprite.getTexture()->getHeight(), 1
		};

		// Set global uniforms
		
		std::optional<Uniform> uniform = shader->getUniform("vertexTransform");
		if (uniform.has_value())
		{
			glUniformMatrix3fv(uniform->location, 1, GL_FALSE, vertexTransform);
		}

		uniform = shader->getUniform("texCoordsTransform");
		if (uniform.has_value())
		{
			glUniformMatrix3fv(uniform->location, 1, GL_FALSE, texCoordsTransform);
		}

		uniform = shader->getUniform("mainTexture");
		if (uniform.has_value())
		{
			glUniform1i(uniform->location, 0);
		}

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, sprite.getTexture()->m_texture);

		if (material != nullptr)
		{
			// Set material property uniforms
		}

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, quad->indices);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, nullptr);
	}

	void Graphics::drawTexture(std::shared_ptr<Texture> texture, const Rect& src, const Rect& dst, const std::shared_ptr<Material>& material)
	{
		std::shared_ptr<Shader> shader;
		


		if (material == nullptr)
		{
			shader = m_defaultSpriteShader;
		}
		else
		{
			shader = material->getShader();
		}

		glBindVertexArray(quad->vao);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture->m_texture);

		glUseProgram(shader->programID);

		Rect renderTargetRect { 0, 0, 0, 0 };

		if (m_currentTarget == nullptr)
		{
			renderTargetRect = m_window->getRect();
		}
		else
		{
			renderTargetRect = m_currentTarget->getRect();
		}

		float vertexTransform[] = {
			static_cast<float>(dst.getWidth()) / static_cast<float>(renderTargetRect.getWidth()), 0, 0,
			0, static_cast<float>(dst.getHeight()) / static_cast<float>(renderTargetRect.getHeight()), 0,
			dst.getX() / renderTargetRect.getWidth(), dst.getY() / renderTargetRect.getHeight(), 1
		};

		float texCoordsTransform[] = {
			static_cast<float>(src.getWidth()) / static_cast<float>(texture->getWidth()), 0, 0,
			0, static_cast<float>(src.getHeight()) / static_cast<float>(texture->getHeight()), 0,
			src.getX() / renderTargetRect.getWidth(), src.getY() / texture->getHeight(), 1
		};

		// Set global uniforms

		std::optional<Uniform> uniform = shader->getUniform("vertexTransform");
		if (uniform.has_value())
		{
			glUniformMatrix3fv(uniform->location, 1, GL_FALSE, vertexTransform);
		}

		uniform = shader->getUniform("texCoordsTransform");
		if (uniform.has_value())
		{
			glUniformMatrix3fv(uniform->location, 1, GL_FALSE, texCoordsTransform);
		}

		uniform = shader->getUniform("mainTexture");
		if (uniform.has_value())
		{
			glUniform1i(uniform->location, 0);
		}

		// Bind texture to TEXTURE0

		if (material != nullptr)
		{
			// Set material property uniforms
		}

		// for each material property in material, set uniform to value

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, quad->indices);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, nullptr);

	}

	void Graphics::blit(std::shared_ptr<Texture> texture)
	{
		const uint32_t aPos = 1;
		const uint32_t aTexCoord = 2;

		glBindVertexArray(quad->vao);

		//Bind the texture to TEXTURE0
		glActiveTexture(GL_TEXTURE0);

		glBindTexture(GL_TEXTURE_2D, texture->m_texture);
		glUseProgram(m_blitShader->programID);

		// Tell the blit sampler to use texture0
		std::optional<Uniform> blitTexture = m_blitShader->getUniform("blitTexture");

		if (blitTexture.has_value())
		{
			glUniform1i(blitTexture.value().location, 0);
		}
		else
		{
			std::cerr << "Error: Blit shader must have blitTexture uniform!\n";
		}

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, quad->indices);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, 0);
		
	}

	void Graphics::clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Graphics::postLoad()
	{
		auto assetManager = RuntimeEngine::getInstance()->getAssetManager();
		m_blitShader = assetManager->getShader(Resources::ResourceLocation("engine", "blit"));
		m_defaultSpriteShader = assetManager->getShader(Resources::ResourceLocation("engine", "sprite"));
	}

	void Graphics::clear(float r, float g, float b)
	{
		glClearColor(r, g, b, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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
		uint32_t color;
		glGenTextures(1, &color);

		glBindTexture(GL_TEXTURE_2D, color);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		// Make a depth texture
		uint32_t depth;
		glGenTextures(1, &depth);

		glBindTexture(GL_TEXTURE_2D, depth);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, width, height, 0, GL_DEPTH_COMPONENT, GL_UNSIGNED_BYTE, NULL);

		// Make a frame buffer
		uint32_t fbo;
		glGenFramebuffers(1, &fbo);
		glBindFramebuffer(GL_FRAMEBUFFER, fbo);

		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, color, 0);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depth, 0);

		// Unbind everything
		glBindTexture(GL_TEXTURE_2D, 0);
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		return std::shared_ptr<RenderTexture>(new RenderTexture(fbo, color, depth, width, height));
	}

	void Graphics::updateViewport()
	{
		if (m_currentTarget == nullptr)
		{
			glViewport(0, 0, m_window->getWidth(), m_window->getHeight());
		}
		else
		{
			glViewport(0, 0, m_currentTarget->getWidth(), m_currentTarget->getHeight());
		}
	}

	void Graphics::loadTexture(std::shared_ptr<Texture> texture, std::string path, uint32_t textureObject)
	{
		SDL_Surface* surface = IMG_Load(path.c_str());

		glBindTexture(GL_TEXTURE_2D, textureObject);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface->w, surface->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, surface->pixels);

		texture->m_width = static_cast<uint16_t>(surface->w);
		texture->m_height = static_cast<uint16_t>(surface->h);
		texture->m_texture = textureObject;

		SDL_FreeSurface(surface);
	}

	bool Graphics::loadShader(std::shared_ptr<Shader> shader)
	{
		// Vertex Shader
		shader->vertexID = glCreateShader(GL_VERTEX_SHADER);

		const char* vertexSource = shader->vertSource.c_str();
		const int vertexLength = static_cast<int>(shader->vertSource.length());
		glShaderSource(shader->vertexID, 1, &vertexSource, &vertexLength);
		glCompileShader(shader->vertexID);
		
		GLint isCompiled = 0;
		glGetShaderiv(shader->vertexID, GL_COMPILE_STATUS, &isCompiled);
		if (isCompiled == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetShaderiv(shader->vertexID, GL_INFO_LOG_LENGTH, &maxLength);

			// The maxLength includes the NULL character
			std::vector<GLchar> errorLog(maxLength);
			glGetShaderInfoLog(shader->vertexID, maxLength, &maxLength, &errorLog[0]);

			std::cerr << std::string(errorLog.data()) << "\n";

			// Exit with failure.
			glDeleteShader(shader->vertexID); // Don't leak the shader.
			return false;
		}

		// Fragment Shader
		shader->fragmentID = glCreateShader(GL_FRAGMENT_SHADER);

		const char* fragmentSource = shader->fragSource.c_str();
		const int fragmentLength = static_cast<int>(shader->fragSource.length());
		glShaderSource(shader->fragmentID, 1, &fragmentSource, &fragmentLength);
		glCompileShader(shader->fragmentID);

		isCompiled = 0;
		glGetShaderiv(shader->fragmentID, GL_COMPILE_STATUS, &isCompiled);
		if (isCompiled == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetShaderiv(shader->fragmentID, GL_INFO_LOG_LENGTH, &maxLength);

			// The maxLength includes the NULL character
			std::vector<GLchar> errorLog(maxLength);
			glGetShaderInfoLog(shader->fragmentID, maxLength, &maxLength, &errorLog[0]);

			std::cerr << std::string(errorLog.data()) << "\n";

			// Exit with failure.
			glDeleteShader(shader->vertexID);
			glDeleteShader(shader->fragmentID); // Don't leak the shader.
			return false;
		}

		// Make shader program
		shader->programID = glCreateProgram();
		glAttachShader(shader->programID, shader->vertexID);
		glAttachShader(shader->programID, shader->fragmentID);
		glLinkProgram(shader->programID);

		GLint success;
		GLint logLength;
		glGetProgramiv(shader->programID, GL_LINK_STATUS, &success);
		glGetProgramiv(shader->programID, GL_INFO_LOG_LENGTH, &logLength);
		if (logLength > 0) {
			char* log = new char[logLength];
			glGetProgramInfoLog(shader->programID, logLength, NULL, log);
			printf("Error linking shader:\n\n%s\n", log);

			glDeleteShader(shader->vertexID);
			glDeleteShader(shader->fragmentID);
			glDeleteProgram(shader->programID);
			return false;
		}
		if (!success) {
			printf("Error linking shader");

			glDeleteShader(shader->vertexID);
			glDeleteShader(shader->fragmentID);
			glDeleteProgram(shader->programID);
			return false;
		}

		for (auto& uniform : shader->m_uniforms)
		{
			uniform.second.location = glGetUniformLocation(shader->programID, uniform.second.name.c_str());
		}

		return true;
	}

	Graphics::Graphics(std::shared_ptr<GameWindow> window) :
		m_window(window)
		//m_renderer(SDL_CreateRenderer(m_window->m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE))
	{
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

		glDisable(GL_CULL_FACE);
		
		m_glContext = SDL_GL_CreateContext(window->m_window);
		glewExperimental = GL_TRUE;
		GLenum err = glewInit();

		glEnable(GL_DEBUG_OUTPUT);
		glDebugMessageCallback(MessageCallback, 0);

		m_window->registerWindowEventListener(RESIZE, [this](const WindowEventData& e) {
			updateViewport();
			}
		);

		quad = Quad::create();
	}
	Graphics::~Graphics()
	{
		// Clean up any shaders and textures

		SDL_GL_DeleteContext(m_glContext);
	}
}