// OpenTransferClient (OTC) - otc.cpp
// Version: 0.0.1-dev - NDVX - 2026

#include "otc.h"

int main(int argc, char* argv[])
{
	SDL_SetAppMetadataProperty(SDL_PROP_APP_METADATA_NAME_STRING, "NDVX OpenTransferClient");
	SDL_SetAppMetadataProperty(SDL_PROP_APP_METADATA_VERSION_STRING, "0.0.1-dev");
	SDL_SetAppMetadataProperty(SDL_PROP_APP_METADATA_IDENTIFIER_STRING, "io.github.ndvx-org.otc");
	SDL_SetAppMetadataProperty(SDL_PROP_APP_METADATA_CREATOR_STRING, "NDVX");
	SDL_SetAppMetadataProperty(SDL_PROP_APP_METADATA_URL_STRING, "https://github.com/ndvx-org/opentransferclient");
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Quit();
	return 0;
}