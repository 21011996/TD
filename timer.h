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

private :
	LARGE_INTEGER m_timerFrequency, m_timerStart, m_current_time;
};

} // namespace utils
