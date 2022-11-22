#pragma once
#include "console.h"
class Text{
	public:
	Text();
	~Text();
	int checkTimer(int);
	void showText(int);
	void display(const char**, const char**);
	void display(const char**, const char**, const char**, const char**);
};

