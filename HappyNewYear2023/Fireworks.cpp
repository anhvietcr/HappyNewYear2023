#include "Fireworks.h"
/***************** PROTOTYPE FUNCTION *****************/

Fireworks::Fireworks(){
	V = 0;
}
//khởi tạo 1 quả pháo
void Fireworks::start(int x, int y){
	//khởi tạo quả pháo
	gotoXY(x, y);
	int ascii[] = {219, 176, 177, 178, 232, 237};
	cout << char(ascii[random(0, 5)]);
	//vẫn tốc ban đầu
	V = 1;

	//di chuyển quả pháo
	delete_FW(x, y);
	move_FW(x, y, V);
}
//hủy quả pháo ở nơi chờ bắn
Fireworks::~Fireworks(){
	for (int i = 0; i <= MAX_X; i++){
		gotoXY(i, MAX_Y);
		cout << " ";
	}
}
//kiểm tra trùng với nội dung mặc định
int Fireworks::check(int x, int y){
	return (x < xThanhPho || y < yThanhPho) ? 1 : 0;
}
//tạo quả pháo mới từ việc di chuyển
void Fireworks::init_new_FW(int x, int& y, int& vantoc){
	if (check(x, y)){
		//thẳng đứng
		gotoXY(x, y);
		cout << " ";		//xóa vị trí cũ
		gotoXY(x, --y);		//tới vị trí mới
		int ascii[] = {219, 176, 177, 178, 232, 237};
		cout << char(ascii[random(0, 5)]);  //in ra quả pháo mới
	} else{
		--y;
	}
	vantoc = vantoc+1;
	Sleep(vantoc);		//dừng lại 1 khoảng thời gian
}
//xóa đường đi của pháo
void Fireworks::delete_FW(int x, int y){
	gotoXY(x, y);
	cout << " ";
}
//di chuyển pháo bông lên không trung
void Fireworks::move_FW(int x, int y, int vantoc){
	int num = random(10, 15);
	int type_move = random(1, 3); //3 loại di chuyển:  |  /  \  
	int rank;
	int show;
	while (true){
		if (y > LINE_DISPLAY){		//chưa phát nổ	
		//thẳng đứng -> giảm y
		//khi quả pháo chạm vào những vùng bị quy định -> không in quả pháo.
		//Chỉ IN ra quả pháo
		//nếu x của quả pháo < x thành phố
		//hoặc y của quả pháo < y của thành phố
			init_new_FW(x, y, vantoc);
		} else{	//bắt đầu phát nổ
			if (y <= num){
				//phát nổ
				show = random(1, 2);
				display_FW(x, y, show);
				//kết thúc quả pháo
				break;
			} else{
				//vẫn di chuyển
				init_new_FW(x, y, vantoc);
			}
		}
	}
	//bouns thêm 3 quả phụ tại 3 vị trí khác
	if (x > CENT_MIN && x < CENT_MAX){
		rank = random(3, 6);
	} else{
		rank = 0;
	}
	show = random(1, 2);
	Sleep(10);
	display_FW(x+rank, y, show);
	Sleep(20);
	display_FW(x-rank, y-4, show);
	Sleep(15);
	display_FW(x+rank, y+3, show);
}

//pháo bông nổ
void Fireworks::display_FW(int x, int y, int show){ 
	Fireworks obj;		//tạo đối tượng để quản lý
	delete_FW(x, y);	//xóa đi viên pháo khi bắn lên
	/*
	--------------
	248 ° |
	249 ∙ |
	250 · |
	42 *  |
	167 º |
	43 +  |
	*/
	//bảng lưu ký mã ký tự
	int ascii[] = {42, 43, 46, 250, 236, 249, 167};
	int n = 1,		//độ dài đường đi của quả pháo khi nổ
		num = 3,	//vị trí lưu ký tự trong bảng mã
		rand = 0,   //sinh số cộng, trừ thêm cho hiển thị
		option = 0, //trạng thái cho hiển thị tùy chọn
		type = 0,	//kiểu nổ pháo
		rank = 0;
	//0 -> 7 ( vì tạo ngẫu nhiên có -3 và +3 )
	rand = random(1, 3);
	//nếu là đường đi cuối cùng -> cho về thành hạt nhỏ
	if (n == MAX_N){
		num = 3;
		rand = 0;
	}
	//kiểu hiển thị pháo ngẫu nhiên theo type loại
	type = random(1, 5);
	if (x > CENT_MIN && x < CENT_MAX) rank = random(4, 10);
	else rank = random(3, 6);
	
	//bắt đầu hiển thị pháo nổ
	while (n <= MAX_N){
		switch (type){
			case 1:
				//hiển thị pháo chính ra màn hình
				display(x, y, ascii, n, num, show); Sleep(1);
				display(x+rank, y-3, ascii, n-2, num+rand, show);
				display(x-rank, y-5, ascii, n-1, num-rand, show);
				//tùy chọn hiển thị thêm pháo phụ
				if (x > CENT_MIN && x < CENT_MAX){
					display(x+rank+10, y-4, ascii, n+2, num, show);
					display(x-rank-10, y+4, ascii, n+4, num, show);
					option = 1;
				}
				//dừng lại quan sát
				Sleep(1);
				//sau đó xóa những hạt pháo đã khởi tạo
				del(x, y, n, obj, show);
				del(x+rank, y-3, n-2, obj, show);
				del(x-rank, y-5, n-1, obj, show);
				//nếu tùy chọn bật thì mới xóa những hạt pháo này
				if (option == 1){
					del(x+rank+10, y-4, n+2, obj, show);
					del(x-rank-10, y+4, n+4, obj, show);
				}
				break;
			case 2:
				//hiển thị pháo chính ra màn hình
				display(x, y, ascii, n, num, show);
				display(x+rank/2, y-rank, ascii, n, num+rand, show);
				display(x-rank/2, y-rank, ascii, n, num-rand, show);
				//tùy chọn hiển thị thêm pháo phụ
				if (x > CENT_MIN && x < CENT_MAX){
					display(x+rank+15, y-6, ascii, n, num, show);
					display(x-rank-10, y+4, ascii, n, num, show);
					option = 1;
				}
				//dừng lại quan sát
				Sleep(1);
				//sau đó xóa những hạt pháo đã khởi tạo
				del(x, y, n, obj, show);
				del(x+rank/2, y-rank, n, obj, show);
				del(x-rank/2, y-rank, n, obj, show);
				//nếu tùy chọn bật thì mới xóa những hạt pháo này
				if (option == 1){
					del(x+rank+15, y-6, n, obj, show);
					del(x-rank-10, y+4, n, obj, show);
				}
				break;
			case 3:
				//hiển thị pháo chính ra màn hình
				display(x, y, ascii, n, num, show); 
				display(x+rank, y-3, ascii, n, num+rand, show);
				display(x-rank/2, y-7, ascii, n, num-rand, show);
				//tùy chọn hiển thị thêm pháo phụ
				if (x > CENT_MIN && x < CENT_MAX){
					display(x+5, y-rank-1, ascii, n, num, show);
					display(x-5, y+rank+5, ascii, n, num, show);
					option = 1;
				}
				//dừng lại quan sát
				Sleep(2);
				//sau đó xóa những hạt pháo đã khởi tạo
				del(x, y, n, obj, show);
				del(x+rank, y-3, n, obj, show);
				del(x-rank/2, y-7, n, obj, show);
				//nếu tùy chọn bật thì mới xóa những hạt pháo này
				if (option == 1){
					del(x+5, y-rank-1, n, obj, show);
					del(x-5, y+rank+5, n, obj, show);
				}
				break;
			case 4:
				//hiển thị pháo chính ra màn hình
				display(x, y, ascii, n, num, show);
				display(x+rank, y+3, ascii, n, num+rand, show);
				display(x-rank, y-7, ascii, n-4, num-rand, show);
				//tùy chọn hiển thị thêm pháo phụ
				if (x > CENT_MIN && x < CENT_MAX){
					display(x+rank+15, y-8, ascii, n-2, num, show);
					display(x-rank-6, y+rank, ascii, n-1, num, show);
					option = 1;
				}
				//dừng lại quan sát
				Sleep(2);
				//sau đó xóa những hạt pháo đã khởi tạo
				del(x, y, n, obj, show);
				del(x+rank, y+3, n, obj, show);
				del(x-rank, y-7, n-4, obj, show);
				//nếu tùy chọn bật thì mới xóa những hạt pháo này
				if (option == 1){
					del(x+rank+15, y-8, n-2, obj, show);
					del(x-rank-6, y+rank, n-1, obj, show);
				}
				break;
			case 5:
				//hiển thị pháo chính ra màn hình
				display(x, y, ascii, n, num, show); Sleep(1);
				display(x+rank, y+4, ascii, n, num+rand, show);
				display(x-rank/2, y-2, ascii, n, num-rand, show);
				//tùy chọn hiển thị thêm pháo phụ
				if (x > CENT_MIN && x < CENT_MAX){
					display(x+rank+6, y-7, ascii, n, num, show);
					display(x-rank-16, y-5, ascii, n, num, show);
					option = 1;
				}
				//dừng lại quan sát
				Sleep(1);
				//sau đó xóa những hạt pháo đã khởi tạo
				del(x, y, n, obj, show);
				del(x+rank, y+4, n, obj, show);
				del(x-rank/2, y-2, n, obj, show);
				//nếu tùy chọn bật thì mới xóa những hạt pháo này
				if (option == 1){
					del(x+rank+6, y-7, n, obj, show);
					del(x-rank-16, y-5, n, obj, show);
				}
				break;
			default:
				break;
		}
		//tăng đường đi của pháo lên 1 đơn vị
		n += 1;
	}
}/*************************** END CLASS PHÁP BÔNG **********/

 /*****************  DEFINE FUNCTION *****************/
//hiển thị các hạt pháo hoa
void display(int x, int y, int ascii[], int n, int num, int show){
	int color = random(1, 8);
	if (show == 1){
		// hinh tron 1
		//len
		gotoXY(x, y-n);			Textcolor(2+color); cout << char(ascii[num]);
		gotoXY(x-(n-1), y-n);	Textcolor(1+color); cout << char(ascii[num]);
		gotoXY(x+(n-1), y-n);	Textcolor(4+color); cout << char(ascii[num]);
		//xuong
		gotoXY(x, y+n);			Textcolor(6+color); cout << char(ascii[num]);
		gotoXY(x-(n-1), y+n);	Textcolor(3+color); cout << char(ascii[num]);
		gotoXY(x+(n-1), y+n);	Textcolor(7+color); cout << char(ascii[num]);
		//trai
		gotoXY(x-(n+1), y);		Textcolor(2+color); cout << char(ascii[num]);
		gotoXY(x-n, y-(n-1));	Textcolor(1+color); cout << char(ascii[num]);
		gotoXY(x-n, y+(n-1));	Textcolor(color); cout << char(ascii[num]);
		//phai
		gotoXY(x+(n+1), y);		Textcolor(7+color); cout << char(ascii[num]);
		gotoXY(x+n, y-(n-1));	Textcolor(3+color); cout << char(ascii[num]);
		gotoXY(x+n, y+(n-1));	Textcolor(2+color); cout << char(ascii[num]);
	} else {
		//hinh tron 2
		//len
		gotoXY(x-(n+1), y-(n+1));	Textcolor(7+color); cout << char(ascii[num]);
		gotoXY(x, y-(n+1));			Textcolor(4+color); cout << char(ascii[num]);
		gotoXY(x+(n+1), y-(n+1));	Textcolor(5+color); cout << char(ascii[num]);
		//xuong
		gotoXY(x-(n+1), y+(n+1));	Textcolor(2+color); cout << char(ascii[num]);
		gotoXY(x, y+(n+1));			Textcolor(1+color); cout << char(ascii[num]);
		gotoXY(x+(n+1), y+(n+1));	Textcolor(5+color); cout << char(ascii[num]);
		//trai
		gotoXY(x-(n+3), y-n);		Textcolor(3+color); cout << char(ascii[num]);
		gotoXY(x-(n+4), y);			Textcolor(7+color); cout << char(ascii[num]);
		gotoXY(x-(n+3), y+n);		Textcolor(3+color); cout << char(ascii[num]);
		//phai
		gotoXY(x+(n+3), y-n);		Textcolor(0+color); cout << char(ascii[num]);
		gotoXY(x+(n+4), y);			Textcolor(2+color); cout << char(ascii[num]);
		gotoXY(x+(n+3), y+n);		Textcolor(4+color); cout << char(ascii[num]);
	}
	//xóa 1/2 màn hình để khỏi sót lại bột pháo
	del_screen(x, y);
}
//xóa vị trí các hạt pháo
void del(int x, int y, int n, Fireworks object, int show){
	if (show == 1){
		object.delete_FW(x, y-n);
		object.delete_FW(x-(n-1), y-n);
		object.delete_FW(x+(n-1), y-n);
		object.delete_FW(x, y+n);
		object.delete_FW(x-(n-1), y+n);
		object.delete_FW(x+(n-1), y+n);
		object.delete_FW(x-(n+1), y);
		object.delete_FW(x-n, y-(n-1));
		object.delete_FW(x-n, y+(n-1));
		object.delete_FW(x+(n+1), y);
		object.delete_FW(x+n, y-(n-1));
		object.delete_FW(x+n, y+(n-1));
	} else {
		object.delete_FW(x-(n+1), y-(n+1));
		object.delete_FW(x, y-(n+1));
		object.delete_FW(x+(n+1), y-(n+1));
		object.delete_FW(x-(n+1), y+(n+1));
		object.delete_FW(x, y+(n+1));
		object.delete_FW(x+(n+1), y+(n+1));
		object.delete_FW(x-(n+3), y-n);
		object.delete_FW(x-(n+4), y);
		object.delete_FW(x-(n+3), y+n);
		object.delete_FW(x+(n+3), y-n);
		object.delete_FW(x+(n+4), y);
		object.delete_FW(x+(n+3), y+n);
	}
}
//xóa màn hình ở góc trái (nhiều bột pháo sót lại)
void del_screen(int x, int y){
	for (int i = MIN; i <= MAX_X/3; i++){
		for (int j = MAX_Y/1.5; j <= MAX_Y; j++){
			gotoXY(i, j);
			cout << " ";
		}
	}
}

//sinh số ngẫu nhiên
int random(int min, int max){
	srand(time(NULL));
	int num = rand()%max + min;
	return num;
}