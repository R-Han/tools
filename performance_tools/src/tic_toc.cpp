/********************************************************
*   Copyright (C) 2017 All rights reserved.
*   
*   Filename: tic_toc.cpp
*   Author  : lubing.han
*   Date    : 2017-11-02
*   Describe: tic_toc.cpp
*
********************************************************/

#include "tic_toc.h"
using namespace std;

namespace performance_tools {

Counter::Counter() {

}

Counter::Counter(const string& id, int cycle): _id(id), _counter(0), _timer(0.0) {
	_cycle = cycle;
	gettimeofday(&_last_time, NULL);
}

Counter::~Counter() {

}

void Counter::tic() {
	gettimeofday(&_last_time, NULL);
}

void Counter::toc() {
	gettimeofday(&_now_time, NULL);
	++_counter;
	double dt = double(_now_time.tv_usec - _last_time.tv_usec) / 1e6 + double(_now_time.tv_sec - _last_time.tv_sec);
	_timer += dt;
	_last_time = _now_time;
	if (_counter % _cycle == 0) {
		cout << _id << " consumes " << _timer << " seconds in " << _cycle << " iterations." << endl;
		_timer = 0;
		_counter = 0;
	}
}

TicToc::TicToc(int cycle) {
	_default_cycle = cycle;
}

TicToc::~TicToc() {

}

void TicToc::tic(const string &id, int cycle) {
	if (_timers.find(id) == _timers.end())
		_timers[id] = Counter(id, cycle <= 0 ? _default_cycle : cycle);
	else
		_timers[id].tic();
}

void TicToc::toc(const string &id) {
	if (_timers.find(id) == _timers.end())
		cout << "Error in TicToc::toc, invalid id: " << id << endl;
	else
		_timers[id].toc();
}

}