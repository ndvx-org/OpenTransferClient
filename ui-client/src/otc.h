// OpenTransferClient (OTC) - otc.h
// Version: 0.0.1-dev - NDVX - 2026

#ifndef OTC_H
#define OTC_H

#include <iostream>
#include <string>
#include <memory>
#include <SDL3/SDL.h>
#include "window.h"
#include "err.h"
#include "log.h"

class OpenTransferClient
{
	private:
		Log m_log;
		Log::logpoint m_logpoint{"Main"};
		const SDL_InitFlags m_initFlags;
		bool m_initialized = false;
		std::shared_ptr<Window> m_window = nullptr;
	public:
		OpenTransferClient();
		bool init();
		void deinit();
		~OpenTransferClient();
};

#endif // OTC_H