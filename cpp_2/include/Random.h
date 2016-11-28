#ifndef RANDOM_H_
#define RANDOM_H_

#include <time.h>
#include <cmath>

/*
	Seed the random number generator using nanoseconds
*/
void seed_random() {
	//http://stackoverflow.com/questions/20201141/same-random-numbers-generated-every-time-in-c
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	srand((time_t)ts.tv_nsec);
}

/*
	Calculate the k-th power of d
*/
double vpow(double d, int k) {
	return pow(d, k);
}

/*
	Calculate the square root of d
*/
double vsqrt(double d) {
	return sqrt(d);
}


#endif