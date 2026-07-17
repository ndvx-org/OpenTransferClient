// OpenTransferClient (OTC) - window.h
// Version: 0.0.1-dev - NDVX - 2026

#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <functional>
#include <SDL3/SDL.h>
#include "log.h"
#include "err.h"
#include "form.h"

class Window
{
	private:
		Log m_log;
		Log::logpoint m_logpoint;
		SDL_Window* m_window = nullptr;
		SDL_Surface* m_surface = nullptr;
	public:
		Window(std::string id, std::string title, int width, int height);
		void event(SDL_Event& event);
		operator SDL_Window*(){return m_window;}
		~Window();
		bool is_safe_area(int x, int y);
		std::function<void(Window*, SDL_WindowEvent&)> on_show; // SDL_EVENT_WINDOW_SHOWN
		std::function<void(Window*, SDL_WindowEvent&)> on_hide; // SDL_EVENT_WINDOW_HIDDEN
		std::function<void(Window*, bool /*live_resize*/, SDL_WindowEvent&)> on_invalidated; // SDL_EVENT_WINDOW_EXPOSED
		std::function<void(Window*, d2::point, SDL_WindowEvent&)> on_move; // SDL_EVENT_WINDOW_MOVED
		std::function<void(Window*, d2::point /*window size*/, SDL_WindowEvent&)> on_resize; // SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED
		std::function<void(Window*, SDL_WindowEvent&)> on_minimize; // SDL_EVENT_WINDOW_MINIMIZED
		std::function<void(Window*, SDL_WindowEvent&)> on_maximize; // SDL_EVENT_WINDOW_MAXIMIZED
		std::function<void(Window*, SDL_WindowEvent&)> on_restore; // SDL_EVENT_WINDOW_RESTORED
		std::function<void(Window*, SDL_WindowEvent&)> on_mouseenter; // SDL_EVENT_WINDOW_MOUSE_ENTER
		std::function<void(Window*, SDL_WindowEvent&)> on_mouseleave; // SDL_EVENT_WINDOW_MOUSE_LEAVE
		std::function<void(Window*, SDL_WindowEvent&)> on_keyboardfocus; // SDL_EVENT_WINDOW_KEYBOARD_FOCUS_GAINED
		std::function<void(Window*, SDL_WindowEvent&)> on_keyboardunfocus; // SDL_EVENT_WINDOW_KEYBOARD_FOCUS_LOST
		std::function<void(Window*, SDL_WindowEvent&)> on_close; // SDL_EVENT_WINDOW_CLOSE_REQUESTED
		
};

#endif // WINDOW_H