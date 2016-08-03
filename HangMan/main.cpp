/\
* Title: HangMan Mini Game
* CC-By: @OsandaMalith
*\
/

#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

#include "ascii.h"

#define MAX 15

using namespace std;

string Words[] = {
	"cat",
	"mouse",
	"dog"
};

int Count = sizeof(Words) / sizeof(*Words);

void Banner() {
	system("title -=:: Hang Man ::=-");
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(h, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
	for (banner; *banner; ++banner) fprintf(stdout, "%c", *banner);
	SetConsoleTextAttribute(h, wOldColorAttrs);
	cout << "\t\t[~] Welome to Hang Man Mini Game\n"
		"\t\t[~] Coded by @OsandaMalith\n\n";
	system("pause > nul & cls");
}

void Ascii(int State) {
	switch (State) {
	case 1:
		cout << endl << *(ascii + 5);
		break;
	case 2:
		cout << endl << *(ascii + 4);
		break;
	case 3:
		cout << endl << *(ascii + 3);
		break;
	case 4:
		cout << endl << *(ascii + 2);
		break;
	case 5:
		cout << endl << *(ascii + 1);
		break;
	case 6:
		cout << endl << *ascii;
	}
}

void RunGame() {
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(h, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;

	size_t size;
	int index;
	int State = 1;
	int character = 0;
	char Guess[MAX];
	char Letter;
	int right = false;

	srand((unsigned)time(NULL));
	index = rand() % Count;

	size = Words[index].length();

	for (; character < size; character++)
		Guess[character] = '_';
	Guess[character] = '\0';

	while (State != 6) {
		Ascii(State);
		cout << Guess
			<< endl;

		cout << endl << "[+] Guess a letter: ";
		cin >> Letter;
		system("cls");

		for (character = 0; character < size; character++) {
			if ((Words[index][character] == Letter)) {
				Guess[character] = Letter;
				right = true;
				SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << endl << endl << "[*] Good Guess!";
				SetConsoleTextAttribute(h, wOldColorAttrs);
				if (!strcmp(Words[index].c_str(), Guess)) {
					SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
					fwrite(congratz, sizeof(char), sizeof(congratz), stdout);
					SetConsoleTextAttribute(h, wOldColorAttrs);
					return;
				}
			}
		}

		if (!right) {
			SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << endl << "[!] Sorry, bad guess!";
			SetConsoleTextAttribute(h, wOldColorAttrs);
			++State;
		}
		right = false;
	}

	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
	Ascii(State);
	SetConsoleTextAttribute(h, wOldColorAttrs);
	cout << "[~] The word was: " 
		 << Words[index].c_str()
		 << endl;
}


int _tmain(int argc, _TCHAR* argv[]) {
	Banner();
	char con = '\x79';

	while (con == '\x79') {
		RunGame();
		cout << endl
			<< "[?] Replay? (Yes or No) ";
		cin >> con;
		con = tolower(con);
		system("cls");
	}
	MessageBox(NULL, TEXT("HangMan Coded by Osanda Malith\nFollow @OsandaMalith"), TEXT("-=About :)=-"), MB_OK | MB_ICONASTERISK | MB_RTLREADING | MB_RIGHT); exit(0);

	return 0;
}
//EOF
