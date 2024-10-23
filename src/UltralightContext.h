#pragma once

#include <Ultralight/Ultralight.h>
#include <iostream>

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

	Logger logger;
	ultralight::ViewListener viewListener;
	ultralight::LoadListener loadListener;

public:
	void init();
};

