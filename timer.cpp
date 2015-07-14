#include "timer.h"


namespace td
{
	void Timer::tick() {
		m_current+=1;
		LabDelay(1);
	}

	__int64 Timer::getTime() {
		return m_current;
	}

	__int64 Timer::getDeltaTime(int time) {
		return m_current-time;
	}
}
