// OpenTransferClient (OTC) - window.cpp
// Version: 0.0.1-dev - NDVX - 2026

#include "window.h"

Window::Window(std::string id, std::string title, int width, int height) : m_logpoint("Window: " + id)
{
	Log::logpoint lp(m_logpoint, "Constructor");
	m_log << lp << "Creating window: " << title << Log::endl;
	if(SDL_CreateWindowAndRenderer(title.c_str(), width, height, SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED, &m_window, &m_renderer))
	{
		m_log << lp << "Window and renderer created successfully" << Log::endl;
	}
	else
	{
		m_log << lp << "Failed to create window and renderer: " << SDL_GetError() << Log::endl;
		throw err::sdl_window_creation_failed;
	}
}

Window::~Window()
{
	Log::logpoint lp(m_logpoint, "Destructor");
	m_log << lp << "Destroying window and renderer" << Log::endl;
	if(m_renderer)
	{
		SDL_DestroyRenderer(m_renderer);
		m_log << lp << "Renderer destroyed successfully" << Log::endl;
	}
	if(m_window)
	{
		SDL_DestroyWindow(m_window);
		m_log << lp << "Window destroyed successfully" << Log::endl;
	}
}