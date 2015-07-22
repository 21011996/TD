#include "timer.h"


namespace td
{
	Timer::Timer() {
		QueryPerformanceFrequency(&m_timerFrequency);
		QueryPerformanceCounter(&m_timerStart);
		QueryPerformanceCounter(&m_current_time);
	}

	void Timer::reset(){
		QueryPerformanceFrequency(&m_timerFrequency);
		QueryPerformanceCounter(&m_timerStart);
		QueryPerformanceCounter(&m_current_time);
	}

	double Timer::getTime() {
		QueryPerformanceCounter(&m_current_time);
		return (double) (m_current_time.QuadPart * 1000 / m_timerFrequency.QuadPart);
	}

	double Timer::getDeltaTime(double time) {
		return getTime()-time;
	}
}
