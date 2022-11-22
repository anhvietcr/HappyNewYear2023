#pragma once
/*
 ___ ___ ____ ____ ____ ____ ___ ____ ____ ___ ____ ____
|     _          _  __     ___      _            		|
|    / \   _ __ | |_\ \   / (_) ___| |_ ___ _ __ 		|
|   / _ \ | '_ \| '_ \ \ / /| |/ _ \ __/ __| '__|		|
|  / ___ \| | | | | | \ V / | |  __/ || (__| |   		|
| /_/   \_\_| |_|_| |_|\_/  |_|\___|\__\___|_|   		|
|			Coding By Anhvietcr - fb.com/anhvietcr		|
|			Build in Visual Studio Community 2015       |
|                Happy New Year 2017                    |
|_ ___ ____ ____ ____ ____ ____ ____ ____ __ __ __ __ __|

*/
#define _WIN32_WINNT 0x0500
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <time.h>
#include <random>
#include <thread>

//DEFINE SIZE (áp dụng khi phóng to màn hình)
#define MAX_Y 38	//y dọc, cao (thực ra là 39 nhưng nên để giảm 1 đơn vị)
#define MAX_X 168	//x ngang, rộng
#define MIN 1
#define LINE_DISPLAY 15
#define MAX_N 5
#define CENT_MIN MAX_X/6    //1/6 đầu tiên -> MIN -> MAX_X/6
#define CENT_MAX MAX_X*5/6  //2/3 tiếp theo -> MAX_X/6 -> MAX_X*5/6
							//1/6 cuối cùng -> MAX_X*5/6 -> MAX_X

using namespace std;

void ResizeConsole(int, int);
void Textcolor(int);
void gotoXY(int, int);
void HideCursor();

/* Console

				(0,0) o---------------------> (x)
				|
				|
				|
				|
				|
				v (y)
*/