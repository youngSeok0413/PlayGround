/*
* for more research : Wolfenstein 3D(Wekipedia)
*/

#include <iostream>
#include <Windows.h>
#include <chrono>

using namespace std;

int nScreenWidth = 120;	//Console Screen Size X(Column)
int nScreenHeight = 40;	//Console Screen Size Y(rows)
int nMapWidth = 16;	// World Dimension
int nMapHeight = 16;

float fPlayerX = 14.7f;	//Player Start Position
float fPlayerY = 5.09f;
float fPlayerA = 0.0f; // Player Start Rotation
float fFOV = 3.14159f / 4.0f;
float fDepth = 16.0f; //Maximum rendering distance
float fSpeed = 16.0f; // Walking Speed


int main() {

	wchar_t* screen = new wchar_t[nScreenWidth * nScreenHeight];
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;

	wstring map;
	map += L"#########.......";
	map += L"#...............";
	map += L"#.......########";
	map += L"#..............#";
	map += L"#......##......#";
	map += L"#......##......#";
	map += L"#..............#";
	map += L"###............#";
	map += L"##.............#";
	map += L"#......####..###";
	map += L"#......#.......#";
	map += L"#......#.......#";
	map += L"#..............#";
	map += L"#......#########";
	map += L"#..............#";
	map += L"################";

	auto tp1 = chrono::system_clock::now();
	auto tp2 = chrono::system_clock::now();

	while (1) {
		tp2 = chrono::system_clock::now();
		chrono::duration<float> elapsedTime = tp2 - tp1; //시간차
		tp1 = tp2;
		float fElapsedTime = elapsedTime.count(); // fps를 구하는 것, ms 단위로 반환

		//Handle CCW Rotation
		if (GetAsyncKeyState((unsigned short)'A') & 0x8000)
			fPlayerA -= (fSpeed * 0.75f) * fElapsedTime;

		//Handle CW Rotation
		if (GetAsyncKeyState((unsigned short)'D') & 0x8000)
			fPlayerA += (fSpeed * 0.75f) * fElapsedTime;

		//Handle forwards movement & collision
		if (GetAsyncKeyState((unsigned short)'W') & 0x8000) {
			fPlayerX += fSpeed * fElapsedTime * sinf(fPlayerA);
			fPlayerY += fSpeed * fElapsedTime * cosf(fPlayerA);
			//collision check
			if (map.c_str()[(int)fPlayerX * nMapWidth + (int)fPlayerY] == '#') {
				fPlayerX -= fSpeed * fElapsedTime * sinf(fPlayerA);
				fPlayerY -= fSpeed * fElapsedTime * cosf(fPlayerA);
			}
		}

		//Handle backwards movement & collision
		if (GetAsyncKeyState((unsigned short)'S') & 0x8000) {
			fPlayerX -= fSpeed * fElapsedTime * sinf(fPlayerA);
			fPlayerY -= fSpeed * fElapsedTime * cosf(fPlayerA);
			//collision check
			if (map.c_str()[(int)fPlayerX * nMapWidth + (int)fPlayerY] == '#') {
				fPlayerX += fSpeed * fElapsedTime * sinf(fPlayerA);
				fPlayerY += fSpeed * fElapsedTime * cosf(fPlayerA);
			}
		}

		//randering
		for (int x = 0; x < nScreenWidth; x++) {
			//For each column, calculate the projected ray angle into world space
			float fRayAngle = (fPlayerA - fFOV / 2.0f) + ((float)x / (float)nScreenWidth) * fFOV;

			//Find distance to wall
			float fStepSize = 0.1f;
			float fDistanceToWall = 0.0f;

			bool bHitWall = false;
			bool bBoundary = false;

			float fEyeX = sinf(fRayAngle); // Unit vector for ray in player space
			float fEyeY = cosf(fRayAngle);

			while (!bHitWall && fDistanceToWall < fDepth) {
				fDistanceToWall += fStepSize;
				int nTestX = (int)(fPlayerX + fEyeX*fDistanceToWall);
				int nTestY = (int)(fPlayerY + fEyeX * fDistanceToWall);

				if (nTestX < 0 || nTestX >= nMapWidth || nTestY < 0 || nTestY >= nMapHeight)
				{
					bHitWall = true;			// Just set distance to maximum depth
					fDistanceToWall = fDepth;
				}
				else {

				}
			}
		}

		// Display Frame
		screen[nScreenWidth * nScreenHeight - 1] = '\0';
		WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten);

	}

	delete[] screen;
	return 0;
}