#include "Fireworks.h"
#include "Text.h"
/* 
			******************** COPYRIGHT 2023 *************************
+ Software			: Happy New Year 2023
+ Author			: Phan Anh Viet (Anhvietcr)

<> Đây là OpenSource, bạn có thể thay đổi, chỉnh sửa mã nguồn.!
<> Xin hãy tôn trọng tác giả, không sửa đổi nội dung ở đây.!
<> Release by Anhvietcr (fb.com/anhvietcr)

			****************** Code haven't Bugs, It's Futures ******************
		  
															  '-.       ,   ,       .-'
																 \    _.-'"'-._    /
				.--.       .--.                              	  \  (_).---.(_)  /
			 _  `    \     /    `  _                               '-/  FUTURE \-'
			  `\.===. \.^./ .===./`									 \__.---.__/
					 \/`"`\/										 / .'   '. \
				  ,  | BUG |  ,									 ,--(_;.-----.;_)--,
				 / `\|;-.-'|/` \								/   |  \     /  |   \
				/    |::\  |    \		Code haven't Bugs 	   /   /;'-.'._.'.-';\   \
			 .-' ,-'`|:::; |`'-, '-.  ----------------->	,-'   /, \~ \-=-/ ~/ ,\   '-,
				 |   |::::\|   | 		It's Futures        	 ; ;  |~ '.' ~|  ; ;
				 |   |::::;|   |								 |; '  \=====/  ; ;|
				 |   \:::://   |								/| ; ;_| === |_; ; |\
				 |    `.://'   |							   / |  \_/;= = =;\_/  | \
				.'             `.							 _/  | ; ;_ \===/ _; ; |  \_
			 _,'                 `,_						`    |  \_/ ;\=/; \_/  |    `
																 | \_| ; ;|; ; |_/ |
																 ;\_/ ; ;/ \; ; \_/;
																 ;/, ; ; | | ; ; ,\;
																  ; ; ; /   \ ; ; ;
																  \; ; ;|   |; ; ;/
																   \; ; /   \ ; ;/
																	\_.'     '._/
*/
/* Console

      (0,0) o---------------------> (x) 
			|
			|
			|
			|
			|
			v (y)
*/
void playSoundFunc();
/********************* MAIN SOFTWARE ************************/
int main(){
	HideCursor(); //ẩn con trỏ chuột
	ResizeConsole(1400, 900); //resize màn hình

	//**************** DECLARE OBJECTs 
	int num, randX = 0, time = 0;
	Text objText;
	Fireworks objFire, objFire2; //3 quả pháo cùng 1 lúc

	//**************** PROCESSING FOR SOUNDING
	std::thread sound{ playSoundFunc };
	sound.detach();
	
	//**************** START FIREWORKS
	while (true){

		//ngẫu nhiên vị trí xuất phát pháo
		randX = random(CENT_MIN, MAX_X/2);
		//10s đầu tiên
		if (time < 10){
			std::thread text(&Text::showText, &objText, time);
			text.join();
			Sleep(1000);
		} else{
			//show fireworks
			std::thread fire1(&Fireworks::start, &objFire, randX, MAX_Y);
			fire1.join();
			//show text
			std::thread text(&Text::showText, &objText, time);
			std::thread fire2(&Fireworks::start, &objFire2, randX+5, MAX_Y);
			text.join(); fire2.join();
		}
		++time;
	}
	
	return 0;
}
void playSoundFunc(){
	PlaySound(TEXT("music/clock.wav"), NULL, SND_ASYNC | SND_FILENAME);
	Sleep(10000); //10 giây đầu tiên
	PlaySound(TEXT("music/fire.wav"), NULL, SND_ASYNC | SND_LOOP);
}
/*
			PLEASE DON'T CHANGE HERE
<> Release  	: Anhvietcr
<> Contact		: fb.com/anhvietcr
<> Email		: anhvietcr20@gmail.com
*/