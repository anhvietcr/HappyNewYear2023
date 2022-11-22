#pragma once
#include "console.h"
/******************* PHÁO BÔNG *****************/
class Fireworks{
	private:
	int V; //vận tốc
	int xThanhPho = MAX_X/3,
		yThanhPho = MAX_Y/1.5;
	public:
	Fireworks();	
	~Fireworks();	
	void start(int, int);					//tạo quả pháo mới
	int check(int, int);					//kiểm tra trùng nội dung
	void init_new_FW(int, int&, int&);		//tạo quả pháo khi di chuyển, xóa quả cũ
	void delete_FW(int, int);				//xóa quả pháo ở nơi sinh ra
	void move_FW(int, int, int);			//di chuyển quả pháo lên không trung
	void display_FW(int, int, int);			//phát nổ
};
void display(int, int, int*, int, int, int);
void del(int, int, int, Fireworks, int);
void del_screen(int, int);
int random(int, int);