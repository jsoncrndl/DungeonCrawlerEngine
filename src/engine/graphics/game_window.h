#pragma once

#include "SDL.h"
#include "memory"
#include "unordered_map"
#include "functional"
#include "ratio"
#include "../math/math_types.h"

namespace Engine {
	class EventDispatcher;

	namespace Graphics {

		class Graphics;

		enum WindowEvent
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
			using EventMap = std::unordered_map<WindowEvent, std::vector<std::function<void(const WindowEventData&)>>>;


			SDL_Window* m_window;
			EventMap m_eventCallbacks;

			uint16_t m_width;
			uint16_t m_height;

			GameWindow();

			void invokeWindowEvent(WindowEvent event);
			void invokeWindowEvent(WindowEvent event, WindowEventData data);
			void handleEvent(SDL_Event e);

		public:
			static std::shared_ptr<GameWindow> create();

			void resize(int width, int height);
			void setPosition(int x, int y);
			void setFullscreen(bool fullscreen);
			void close();
			
			// Returns the rect of the window viewport
			Rect getRect() const;

			// Returns a rect with a width:height ratio that best fits the window viewport
			Rect getRect(uint16_t width, uint16_t height) const;

			void registerWindowEventListener(WindowEvent event, std::function<void(const WindowEventData&)>);
			~GameWindow();
		};
	}
}