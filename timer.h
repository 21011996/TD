#pragma once
#include <windows.h>
#include "labengine\labengine.h"

namespace td
{

struct Timer
{
	Timer(int start_time): m_current(start_time) {};
	Timer(){};
	void tick();
	__int64 getTime();
	__int64 getDeltaTime(int time);

private :
	__int64 m_current;
};

} // namespace utils
