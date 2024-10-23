#include "UltralightContext.h"
#include <AppCore/Platform.h>

void UltralightContext::init()
{
	ultralight::Config config;

	config.user_stylesheet = "body { background: purple; }";

	ultralight::Platform::instance().set_config(config);

	ultralight::Platform::instance().set_font_loader(ultralight::GetPlatformFontLoader());

	ultralight::Platform::instance().set_file_system(ultralight::GetPlatformFileSystem("."));

	ultralight::Platform::instance().set_logger(&this->logger);

	this->renderer = ultralight::Renderer::Create();
	//this->view = this->renderer->CreateView(1280, 1024, false, nullptr)
}
