// OpenTransferClient (OTC) - window.h
// Version: 0.0.1-dev - NDVX - 2026

#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <SDL3/SDL.h>
#include "log.h"
#include "err.h"

class Window
{
	private:
		Log m_log;
		Log::logpoint m_logpoint;
		SDL_Window* m_window = nullptr;
		SDL_Renderer* m_renderer = nullptr;
	public:
		Window(std::string id, std::string title, int width, int height);
		~Window();
};

#endif // WINDOW_H