#pragma once

#include <SDL.h>
#include <EASTL/functional.h>
#include <EASTL/fixed_vector.h>
#include <EASTL/array.h>
#include "engine/math_types.h"
#include "engine/memory/permanent_allocator.h"

namespace Engine {
	class EventDispatcher;
	class RuntimeEngine;

	namespace Graphics {

		class Graphics;

		enum class WindowEvent : uint8_t
		{
			SHOW,
			HIDE,
			CLOSE,
			RESIZE,
			MOVE,
			MINIMIZE,
			MAXIMIZE,
			FOCUS,
			UNFOCUS
		};

		struct WindowEventData
		{
			int x;
			int y;

			WindowEventData(int x, int y);
		};

		class GameWindow
		{
			friend class Engine::EventDispatcher;
			friend class Engine::Graphics::Graphics;

		private:
			static constexpr int MAX_CALLBACKS = 4;
			static constexpr int WINDOW_EVENT_COUNT = 9;

			using EventCallback = eastl::function<void(const WindowEventData&)>;
			using CallbackList = eastl::fixed_vector<EventCallback, MAX_CALLBACKS, false, Memory::PermanentAllocator>;

			SDL_Window* m_window;
			eastl::array<CallbackList, WINDOW_EVENT_COUNT> m_eventCallbacks;

			uint16_t m_width;
			uint16_t m_height;
			Memory::PermanentAllocator m_allocator;

			void invokeWindowEvent(WindowEvent event);
			void invokeWindowEvent(WindowEvent event, WindowEventData data);
			void handleEvent(SDL_WindowEvent e);

			GameWindow(GameWindow&);

		public:

			GameWindow(Memory::PermanentAllocator allocator);

			void resize(int width, int height);
			void setPosition(int x, int y);
			void setFullscreen(bool fullscreen);
			void close();
			void setTitle(std::string title);

			// Returns the rect of the window viewport
			Rect getRect() const;

			// Returns a rect with a width:height ratio that best fits the window viewport
			Rect getRect(uint16_t width, uint16_t height) const;

			const uint16_t getWidth();
			const uint16_t getHeight();

			void registerWindowEventListener(WindowEvent event, EventCallback callback);
			~GameWindow();
		};
	}
}