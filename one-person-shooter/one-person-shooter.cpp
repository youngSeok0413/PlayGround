/*
* for more research : Wolfenstein 3D(Wekipedia)
*/

#include <iostream>
#include <Windows.h>
#include <chrono>
#include <vector>
#include <utility>
#include <algorithm>

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
					if (map.c_str()[nTestX*nMapWidth + nTestY] == '#') {
						bHitWall = true;

						vector<pair<float, float>> p;

						for(int tx = 0; tx < 2; tx++)
							for (int ty = 0; ty < 2; ty++) {
								float vy = (float)nTestY + ty - fPlayerY;
								float vx = (float)nTestX + tx - fPlayerX;
								float d = sqrt(vx*vx+ vy * vy);
								float dot = (fEyeX * vx/d) + (fEyeY*vy/d);
								p.push_back(make_pair(d, dot));
							}

						sort(p.begin(), p.end(), [](const pair<float, float>& left, const pair<float, float>& right) {return left.first < right.first; });

						float fBound = 0.01;
						if (acos(p.at(0).second) < fBound) bBoundary = true;
						if (acos(p.at(1).second) < fBound) bBoundary = true;
						if (acos(p.at(2).second) < fBound) bBoundary = true;
					}
				}
			}

			// Calculate distance to ceiling and floor
			int nCeiling = (float)(nScreenHeight / 2.0) - nScreenHeight / ((float)fDistanceToWall);
			int nFloor = nScreenHeight - nCeiling;

			// Shader walls based on distance
			short nShade = ' ';
			if (fDistanceToWall <= fDepth / 4.0f)			nShade = 0x2588;	// Very close	
			else if (fDistanceToWall < fDepth / 3.0f)		nShade = 0x2593;
			else if (fDistanceToWall < fDepth / 2.0f)		nShade = 0x2592;
			else if (fDistanceToWall < fDepth)				nShade = 0x2591;
			else											nShade = ' ';		// Too far away

			if (bBoundary)		nShade = ' '; // Black it out

			for (int y = 0; y < nScreenHeight; y++)
			{
				// Each Row
				if (y <= nCeiling)
					screen[y * nScreenWidth + x] = ' ';
				else if (y > nCeiling && y <= nFloor)
					screen[y * nScreenWidth + x] = nShade;
				else // Floor
				{
					// Shade floor based on distance
					float b = 1.0f - (((float)y - nScreenHeight / 2.0f) / ((float)nScreenHeight / 2.0f));
					if (b < 0.25)		nShade = '#';
					else if (b < 0.5)	nShade = 'x';
					else if (b < 0.75)	nShade = '.';
					else if (b < 0.9)	nShade = '-';
					else				nShade = ' ';
					screen[y * nScreenWidth + x] = nShade;
				}
			}
		}

		// Display Stats
		swprintf_s(screen, 40, L"X=%3.2f, Y=%3.2f, A=%3.2f FPS=%3.2f ", fPlayerX, fPlayerY, fPlayerA, 1.0f / fElapsedTime);

		// Display Map
		for (int nx = 0; nx < nMapWidth; nx++)
			for (int ny = 0; ny < nMapWidth; ny++)
			{
				screen[(ny + 1) * nScreenWidth + nx] = map[ny * nMapWidth + nx];
			}
		screen[((int)fPlayerX + 1) * nScreenWidth + (int)fPlayerY] = 'P';


		// Display Frame
		screen[nScreenWidth * nScreenHeight - 1] = '\0';
		WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten);

	}

	delete[] screen;
	return 0;
}