#include "timer.h"


namespace td
{
	Timer::Timer() {
		QueryPerformanceFrequency(&m_timerFrequency);
		QueryPerformanceCounter(&m_current_time);
		m_time_paused = 0;
	}

	void Timer::reset(){
		QueryPerformanceFrequency(&m_timerFrequency);
		QueryPerformanceCounter(&m_current_time);
	}

	double Timer::getTime() {
		QueryPerformanceCounter(&m_current_time);
		return (double) (m_current_time.QuadPart * 1000 / m_timerFrequency.QuadPart) - m_time_paused;
	}

	double Timer::getDeltaTime(double time) {
		return getTime()- time - m_time_paused;
	}

	void Timer::pause() {
		/*QueryPerformanceCounter(&m_current_time);
		m_time_paused -= (double) (m_current_time.QuadPart * 1000 / m_timerFrequency.QuadPart);*/
	}

	void Timer::unPause() {
		/*QueryPerformanceCounter(&m_current_time);
		m_time_paused += (double) (m_current_time.QuadPart * 1000 / m_timerFrequency.QuadPart);*/
	}
}
