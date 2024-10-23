#pragma once

#include <Ultralight/Ultralight.h>
#include <iostream>
#include <bgfx/bgfx.h> 

struct Logger : ultralight::Logger
{
	void LogMessage(ultralight::LogLevel log_level, const ultralight::String& message) override
	{
		std::cout << message.utf8().data() << std::endl;
	};
};

class UltralightContext
{
private: 
	ultralight::RefPtr<ultralight::View> view;
	ultralight::RefPtr<ultralight::Renderer> renderer;
	ultralight::RefPtr<ultralight::Bitmap> bitmap;

	Logger logger;
	ultralight::ViewListener viewListener;
	ultralight::LoadListener loadListener;
	bgfx::TextureHandle textureHandle;

public:
	void init();
	void copy_surface_bitmap_to_texture();
	void on_resize();
	void tick();
};

