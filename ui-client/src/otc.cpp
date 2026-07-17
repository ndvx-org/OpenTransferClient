// OpenTransferClient (OTC) - otc.cpp
// Version: 0.0.1-dev - NDVX - 2026

#include "otc.h"

int main(int argc, char* argv[])
{
	OpenTransferClient client;
	if(client.init())
	{
		client.m_running = true;
		while(client.m_running)
		{
			client.update();
			SDL_Delay(16); // ~60 FPS
		}
	}
	else
	{
		return unsigned short(err::sdl_init_failed);
	}
	client.deinit();
	return 0;
}
OpenTransferClient::OpenTransferClient() : m_initFlags(SDL_INIT_VIDEO)
{
	Log::logpoint lp(m_logpoint, "Constructor");
	m_log << lp << "Initializing OpenTransferClient" << Log::endl;

	if
	(
		SDL_SetAppMetadataProperty(SDL_PROP_APP_METADATA_NAME_STRING, "NDVX OpenTransferClient") &&
		SDL_SetAppMetadataProperty(SDL_PROP_APP_METADATA_VERSION_STRING, "0.0.1-dev") &&
		SDL_SetAppMetadataProperty(SDL_PROP_APP_METADATA_IDENTIFIER_STRING, "io.github.ndvx-org.otc") &&
		SDL_SetAppMetadataProperty(SDL_PROP_APP_METADATA_CREATOR_STRING, "NDVX") &&
		SDL_SetAppMetadataProperty(SDL_PROP_APP_METADATA_URL_STRING, "https://github.com/ndvx-org/opentransferclient") &&
		SDL_SetHint(SDL_HINT_QUIT_ON_LAST_WINDOW_CLOSE, "0")
	)
	{
		m_log << lp << "OpenTransferClient initialized successfully" << Log::endl;
	}
	else
	{
		m_log << lp << "Failed to set application metadata: " << SDL_GetError() << Log::endl;
	}
}

bool OpenTransferClient::init()
{
	Log::logpoint lp(m_logpoint, "Init");
	if(!m_initialized)
	{
		m_initialized = SDL_Init(m_initFlags);
		if(m_initialized)
			m_log << lp << "SDL initialized successfully" << Log::endl;
		else
		{
			m_log << lp << "Failed to initialize SDL: " << SDL_GetError() << Log::endl;
			return false;
		}
	}
	else
		m_log << lp << "Tried to initialize SDL, but it was already initialized" << Log::endl;

	try
	{
		m_window = std::make_shared<Window>("main_window", "OpenTransferClient", 800, 600);
	}
	catch(unsigned short)
	{
		return false;
	}
	return m_initialized;
}

void OpenTransferClient::update()
{
	Log::logpoint lp(m_logpoint, "Update");
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		SDL_Window* eventWindow = SDL_GetWindowFromEvent(&event);
		if(eventWindow)
		{
			SDL_PropertiesID props = SDL_GetWindowProperties(eventWindow);
			Window* window = (Window*)SDL_GetPointerProperty(props, "Window object", nullptr);
			if(!window)
			{
				m_log << lp << "Received event for unknown window" << Log::endl;
				continue;
			}
			window->event(event);
		}
		else switch (event.type)
		{
			case SDL_EVENT_QUIT:
				m_running = false;
				m_log << lp << "Quit event received" << Log::endl;
				break;
			default:
				break;
		}
	}

}

void OpenTransferClient::deinit()
{
	Log::logpoint lp(m_logpoint, "Deinit");
	if(m_initialized)
	{
		m_window.reset();
		SDL_Quit();
		m_initialized = false;
		m_log << lp << "SDL deinitialized successfully" << Log::endl;
	}
	else
		m_log << lp << "Tried to deinitialize SDL, but it was not initialized" << Log::endl;
}

OpenTransferClient::~OpenTransferClient()
{
	Log::logpoint lp(m_logpoint, "Destructor");
	if(m_initialized)
		deinit();
	m_log << lp << "OpenTransferClient destroyed" << Log::endl;
}