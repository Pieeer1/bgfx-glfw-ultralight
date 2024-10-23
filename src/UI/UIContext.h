#pragma once

#include <Ultralight/Ultralight.h>
#include <iostream>
#include <bgfx/bgfx.h> 
#include "../Math/Vector2.h"

struct Logger : ultralight::Logger
{
	void LogMessage(ultralight::LogLevel log_level, const ultralight::String& message) override
	{
		std::cout << message.utf8().data() << std::endl;
	};
};

class UIContext
{
private: 
	ultralight::RefPtr<ultralight::View> view;
	ultralight::RefPtr<ultralight::Renderer> renderer;
	ultralight::RefPtr<ultralight::Bitmap> bitmap;

	Vector2 uiSize;

	Logger logger;
	ultralight::ViewListener viewListener;
	ultralight::LoadListener loadListener;
	bgfx::TextureHandle textureHandle; 

public:
	void init(Vector2 size);
	void copy_surface_bitmap_to_texture();
	void on_resize(Vector2 newSize);
	void tick();
};

