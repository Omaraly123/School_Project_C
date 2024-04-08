#include "../Inc/mTime.h"

static LARGE_INTEGER frequency;
static LARGE_INTEGER start;
static LARGE_INTEGER end;

void Time_delayMilliseconds(u32 apu32milliseconds) 
{
    Sleep(apu32milliseconds);
}

void Time_Take_START_Snap(void)
{
	// Get the frequency of the performance counter
	QueryPerformanceFrequency(&frequency);
	// Record the start time
    QueryPerformanceCounter(&start); 
}

f64 Time_Take_END_Snap(void)
{
	f64 lf64CPU_TimeUsed =0.0;
	// Record the end time
	QueryPerformanceCounter(&end);

	lf64CPU_TimeUsed = (((cast_f64)(end.QuadPart - start.QuadPart)) * 1000000) / frequency.QuadPart;
	//printf("Execution time: %.9f seconds\n", lf64CPU_TimeUsed);
	return lf64CPU_TimeUsed;
}