// OpenTransferClient (OTC) - otc.h
// Version: 0.0.1-dev - NDVX - 2026

#include <iostream>
#include <string>
#include <SDL3/SDL.h>
#include "err.h"
#include "log.h"

class OpenTransferClient
{
	private:
		Log m_log;
		Log::logpoint m_logpoint{"Main"};
		const SDL_InitFlags m_initFlags;
		bool m_initialized = false;
	public:
		OpenTransferClient();
		bool init();
		void deinit();
		~OpenTransferClient();
};
