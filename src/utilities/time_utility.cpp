/*
 MIT License

 Copyright (c) 2019 SAE Institute Switzerland AG

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 */

#include <thread>
#include <chrono>
#include <utilities/time_utility.h>

namespace neko
{

Timer::Timer(float time, float period) :
        time(time), period(period)
{
}

void Timer::Update(float dt)
{
    if (time > 0.0f)
    {
        time -= dt;
    }
}

bool Timer::IsOver() const
{
    return !(time > 0.0f);
}

void Timer::Reset()
{
    if (time < 0.0f)
    {
        time += period;
    }
    else
    {
        time = period;
    }
}

float Timer::GetCurrentRatio() const
{
    return GetTimeFromStart() / period;
}

float Timer::GetTimeFromStart() const
{
    return period - time;
}

void SleepMs(const uint32_t ms)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
} 

}


