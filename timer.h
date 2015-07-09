#pragma once
#include <windows.h>

namespace utils
{

struct Timer
{
public :
	void Start();
	float GetDeltaTime();

private :
	LARGE_INTEGER freq, t;
};

} // namespace utils
