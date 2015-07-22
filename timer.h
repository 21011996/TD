#pragma once
#include <windows.h>
#include "labengine\labengine.h"

namespace td
{

struct Timer
{
	Timer();
	void reset();
	double getTime();
	double getDeltaTime(double time);
	void pause();
	void unPause();

private :
	LARGE_INTEGER m_timerFrequency, m_current_time;
	double m_time_paused;
};

} // namespace utils
