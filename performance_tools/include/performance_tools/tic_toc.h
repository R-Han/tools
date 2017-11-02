/********************************************************
*   Copyright (C) 2017 All rights reserved.
*   
*   Filename: tic_toc.h
*   Author  : lubing.han
*   Date    : 2017-11-02
*   Describe: tic_toc.h
*
********************************************************/

#include <unistd.h>
#include <sys/time.h>
#include <map>
#include <iostream>
using namespace std;

#ifndef PERFORMANCE_TOOLS_TIC_TOC_H
#define PERFORMANCE_TOOLS_TIC_TOC_H

namespace performance_tools {

class Counter
{
public:
	Counter();
	Counter(const string& id, int cycle);
	~Counter();
	void tic();
	void toc();
private:
	string _id;
	int _cycle, _counter;
	struct timeval _last_time, _now_time;
	double _timer;
};

class TicToc
{
public:
	TicToc(int cycle = 1);
	~TicToc();
	void tic(const string &id = "_default", int cycle = -1);
	void toc(const string &id = "_default");
private:
	int _default_cycle;
	map<string, Counter> _timers;
};

}

#endif