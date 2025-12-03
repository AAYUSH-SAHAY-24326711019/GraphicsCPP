#include <iostream>
#include <conio.h>      // for _kbhit(), _getch()
#include <windows.h>    // for Sleep()
#include <vector>
#include<algorithm> // remove if error
using namespace std;

// Console size
const int WIDTH = 60;
const int HEIGHT = 20;

// Spaceship design
const string SHIP = "==|^|==";
const int SHIP_WIDTH = SHIP.length();

// Bullet   
struct Bullet {
    int x, y;
};

void clearScreen() {
    // Move cursor to top-left (prevents flicker)
    COORD c;
    c.X = 0; c.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int main() {
    // Initial spaceship position
    int shipX = WIDTH / 2 - SHIP_WIDTH / 2;
    int shipY = HEIGHT - 2;

    vector<Bullet> bullets;

    // Hide console cursor
    CONSOLE_CURSOR_INFO cursor;
    cursor.bVisible = FALSE;
    cursor.dwSize = 1;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);

    while (true) {
        // 1. INPUT HANDLING
        if (_kbhit()) {
            char ch = _getch();

            if (ch == 'a' || ch == 'A')  // left
                if (shipX > 1) shipX--;

            if (ch == 'd' || ch == 'D')  // right
                if (shipX < WIDTH - SHIP_WIDTH - 1) shipX++;

            if (ch == 'w' || ch == 'W')  // up
                if (shipY > 1) shipY--;

            if (ch == 's' || ch == 'S')  // down
                if (shipY < HEIGHT - 2) shipY++;

            if (ch == 'f' || ch == 'F')  // fire
                bullets.push_back({ shipX + SHIP_WIDTH / 2, shipY - 1 });

            if (ch == 'q' || ch == 'Q') // quit
                break;
        }

        // 2. UPDATE BULLETS
        for (int i = 0; i < bullets.size(); i++)
            bullets[i].y--;

        // Remove off-screen bullets
        bullets.erase(remove_if(bullets.begin(), bullets.end(),
            [](Bullet& b) { return b.y <= 0; }), bullets.end());

        // 3. DRAW EVERYTHING
        clearScreen();
        vector<string> screen(HEIGHT, string(WIDTH, ' '));

        // Draw bullets
        for (auto& b : bullets) {
            if (b.y >= 0 && b.y < HEIGHT && b.x >= 0 && b.x < WIDTH)
                screen[b.y][b.x] = '|';
        }

        // Draw ship
        for (int i = 0; i < SHIP_WIDTH; i++)
            screen[shipY][shipX + i] = SHIP[i];

        // Print screen
        for (int i = 0; i < HEIGHT; i++)
            cout << screen[i] << "\n";

        cout << "\nControls: W A S D to move | F to fire | Q to quit\n";

        Sleep(40); // 25 FPS
    }

    return 0;
}
