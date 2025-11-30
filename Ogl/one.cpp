#include<Windows.h>
#include<iostream>
#include<chrono>
#include<thread>
#include<string>
#include<conio.h>

using namespace std;

BOOL setCursorToPosition(int x, int y) {
	COORD c;
	c.X = x;
	c.Y = y;
	return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

bool isVirtualKeyPressed(int virtKey) {
	return GetAsyncKeyState(virtKey) & 0x8000;
}

int main() {
	////1 make the cursor set to position
	//COORD c = { 22,22 };
	//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);

	//int i; cin >> i;

	////2 move the cursor to other positon
	//c = { 22,10 };
	//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);

	//cin >> i;

	//3 use the funtion
	/*setCursorToPosition(33,7);*/
	/*cout << "position of cursor changed"; //line to test */
	int moveX = 0; int moveY = 0;
	string message="aayush";
	while(true){
		if (GetAsyncKeyState(VK_LEFT)){
				
			--moveX;
		}
		else if (GetAsyncKeyState(VK_RIGHT)) {
			++moveX;
		}else if (GetAsyncKeyState(VK_DOWN)) {
			++moveY;
		}else if (GetAsyncKeyState(VK_UP)) {
			--moveY;
		}else if (GetAsyncKeyState(VK_ESCAPE)) {
			break;
		}
		/*if (_kbhit()) {
			char ch = _getche();
				message += ch;
		}*/
		this_thread::sleep_for(chrono::milliseconds(6));
		LockWindowUpdate(GetConsoleWindow());
		system("cls");
		setCursorToPosition(10+moveX,10 + moveY);
		cout <<message;
		LockWindowUpdate(NULL);
	}
	return 0;
}