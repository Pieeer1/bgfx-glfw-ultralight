#include "UltralightContext.h"
#include <AppCore/Platform.h>
#include <bgfx/bgfx.h>

void UltralightContext::init()
{
	ultralight::Config config;

	config.user_stylesheet = "body { background: purple; }";

	ultralight::Platform::instance().set_config(config);

	ultralight::Platform::instance().set_font_loader(ultralight::GetPlatformFontLoader());

	ultralight::Platform::instance().set_file_system(ultralight::GetPlatformFileSystem("."));

	ultralight::Platform::instance().set_logger(&this->logger);

	this->renderer = ultralight::Renderer::Create();

	ultralight::ViewConfig view_config;
	view_config.is_accelerated = false;
	
	this->view = this->renderer->CreateView(1280, 1024, view_config, nullptr);

	this->view->LoadHTML("<h1>Hello world</h1>");

	ultralight::Surface* surface = this->view->surface();

	ultralight::BitmapSurface* bmSurface = (ultralight::BitmapSurface*)surface;

	this->bitmap = bmSurface->bitmap();
}

void on_resize()
{

}

void UltralightContext::copy_surface_bitmap_to_texture()
{
	void* pixels = this->bitmap->LockPixels();

	uint32_t width = bitmap->width();
	uint32_t height = bitmap->height();
	uint32_t stride = bitmap->row_bytes();

	{
		const uint16_t tw = static_cast<uint32_t>(bitmap->width());
		const uint16_t th = static_cast<uint32_t>(bitmap->height());
		const uint16_t tx = 0;
		const uint16_t ty = 0;

		const bgfx::Memory* mem = bgfx::makeRef(pixels, stride);

		if (bgfx::isValid(textureHandle)) 
		{
			bgfx::updateTexture2D(textureHandle, 0, 0, tx, ty, tw, th, mem, stride);
		}
	}

	this->bitmap->UnlockPixels();
}

void UltralightContext::tick()
{
	this->renderer->Update();
}