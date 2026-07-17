// OpenTransferClient (OTC) - window.cpp
// Version: 0.0.1-dev - NDVX - 2026

#include "window.h"

Window::Window(std::string id, std::string title, int width, int height) : m_logpoint("Window: " + id)
{
	Log::logpoint lp(m_logpoint, "Constructor");
	m_log << lp << "Creating window: " << title << Log::endl;
	m_window = SDL_CreateWindow(title.c_str(), width, height, SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED);
	SDL_PropertiesID props = SDL_GetWindowProperties(m_window);
	SDL_SetPointerProperty(props, "Window object", this);
	m_surface = SDL_GetWindowSurface(m_window);
	if(m_window)
	{
		m_log << lp << "Window created successfully" << Log::endl;
	}
	else
	{
		m_log << lp << "Failed to create window: " << SDL_GetError() << Log::endl;
		throw err::sdl_window_creation_failed;
	}
}

void Window::event(SDL_Event& event)
{
	Log::logpoint lp(m_logpoint, "Event");
	switch(event.type)
	{
		case SDL_EVENT_WINDOW_RESIZED:
			m_surface = SDL_GetWindowSurface(m_window);
			break;
		default:
			break;
	}
}

Window::~Window()
{
	Log::logpoint lp(m_logpoint, "Destructor");
	m_log << lp << "Destroying window and renderer" << Log::endl;
	if(m_window)
	{
		SDL_DestroyWindow(m_window);
		m_log << lp << "Window destroyed successfully" << Log::endl;
	}
}