#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include<fstream>
#include<Windows.h>
#include<vector>
#define MAX_BadWord_count 7
using namespace std;
void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

// Hàm dịch chuyển con trỏ đến tọa độ x, y.
void gotoxy(int x,int y)
{    
	HANDLE hConsoleOutput;    
	COORD Cursor_an_Pos = {x-1,y-1};   
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);    
	SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}
string Choosen_Word(ifstream &Filein)
{
	Filein.open("INPUT.txt",ios :: in);
	vector<string> word;
	
	string Word;
	while(!Filein.eof())
	{
		Filein >> Word;
		word.push_back(Word);
	}
	
	int n = word.size();
	int a = rand()% n;
	return word[a];
	Filein.close();
}
void RenderGame(string GuessedWord, int BadWord_Count)
{
	
	switch(BadWord_Count) 
	{ 
	case 1 : 
		
		system("cls");
		cout << "     ________  " << endl; 
		cout << "     |     |  " << endl;      
		cout << "     |         " << endl; 
		cout << "     |         " << endl; 
		cout << "     |         " << endl; 
		cout << "    ===========" << endl;break; 
	case 2 : 
		system("cls");
		cout << "     ________ " << endl; 
		cout << "     |     | " << endl;      
		cout << "     |     0 " << endl; 
		cout << "     |        " << endl; 
		cout << "     |        " << endl; 
		cout <<"     ==========" << endl;break; 

	case 3 : 
		system("cls");
		cout << "     ________ " << endl; 
		cout << "     |     | " << endl;      
		cout << "     |     0 " << endl; 
		cout << "     |     o " << endl; 
		cout << "     |        " << endl; 
		cout <<"     ==========" << endl; break; 

	case 4 : 
		
		system("cls");
		cout << "     ________ " << endl; 
		cout << "     |     |  " << endl;      
		cout << "     |     0  " << endl; 
		cout << "     |    -o  " << endl; 
		cout << "     |        " << endl; 
		cout << "    ========= " << endl;break; 

	case 5 : 
		
		system("cls");
		cout << "     ________ " << endl; 
		cout << "     |     |  " << endl;      
		cout << "     |     0  " << endl; 
		cout << "     |    -o- " << endl; 
		cout << "     |        " << endl; 
		cout << "    ==========" << endl;break; 

	case 6 : 
		
		system("cls");
		cout << "     ________ " << endl; 
		cout << "     |     |  " << endl;      
		cout << "     |     0  " << endl; 
		cout << "     |    -o- " << endl; 
		cout << "     |        " << endl; 
		cout << "    ==========" << endl;break; 
	case 7 : 
		
		system("cls");
		cout << "     ________  " << endl; 
		cout << "     |     |   " << endl;      
		cout << "     |     0   " << endl; 
		cout << "     |    -o-  " << endl; 
		cout << "     |    / \\ " << endl; 
		cout << "    ===========" << endl;break;
	} 
	cout << "\nCurrent guess = " << GuessedWord << endl;
	cout << "You have made " << BadWord_Count << " bad guess(es)";
}
string UpDate(string GuessWord, string Word, char Guess)
{
	for(int i = Word.length() ; i >= 0; i--)
	{
		if(Word[i] == Guess)
		{
			GuessWord[i] = Guess;
		}
	}
	return GuessWord;
}
void DoiChuoi(string s1, string & s2)
{
	for(int i = 0; i < s1.length(); i++)
	{
		s2[i] = '-';
	}
}
int Contain(string Word, char guess)
{
	for(int i = 0; i < Word.length(); i++)
	{
		if(Word[i] == guess)
		{
			return 1;
		}
	}
	return 0;
}
char readAGuess()
{
    cout<<endl << "Please enter your next guess: " << endl;
    char guess;
    cin >> guess;
    return guess;
	//cout << endl;
}
int main()
{
	ifstream Filein;
	srand(time(0));
	string Word = Choosen_Word(Filein);
	string GuessWord = Word;
	int BadWord_Count = 0;
	char Guess;
	cout << Word;
    DoiChuoi(Word,GuessWord);
	cout << "============== WELCOM TO HANGMAN==============";
	do{
		RenderGame(GuessWord, BadWord_Count);
		Guess = readAGuess();
		if(Contain(Word,Guess) == 1)
		{
			GuessWord = UpDate(GuessWord,Word,Guess);
		}
		else
		{
			BadWord_Count++;
		}
	}while(Word != GuessWord && BadWord_Count < MAX_BadWord_count);
	RenderGame(GuessWord, BadWord_Count);
	if(BadWord_Count > MAX_BadWord_count || Word != GuessWord)
	{
		cout << "\nYOU LOSE";
		cout << "\nTu may tinh nghi ra la: "<<Word <<endl;
		for(int i = 0; i < 10; i++)
		{
			system("cls");
			cout << "     ________  " << endl; 
			cout << "     |     |   " << endl;      
			cout << "     |     0   " << endl; 
			cout << "     |    -o-  " << endl; 
			cout << "     |    / \\ " << endl; 
			cout << "    ===========" << endl;
			Sleep(300);
			system("cls");
			cout << "     ________  " << endl; 
			cout << "     |     |   " << endl;      
			cout << "     |      0   " << endl; 
			cout << "     |      -o-  " << endl; 
			cout << "     |       / \\ " << endl; 
			cout << "    ===========" << endl;
			Sleep(300);
			system("cls");
			cout << "     ________  " << endl; 
			cout << "     |     |   " << endl;      
			cout << "     |    0   " << endl; 
			cout << "     |  -o-  " << endl; 
			cout << "     | / \\ " << endl; 
			cout << "    ===========" << endl;
		}
	}
	else
	{
		cout << "\ncongratulations ! YOU WIN";
		for(int i = 0; i < 10; i++)
		{
			Sleep(500);
			system("cls");
			cout << "               " << endl; 
			cout << "               " << endl;      
			cout << "           0   " << endl; 
			cout << "         /o\\   " << endl; 
			cout << "         / \\  " << endl; 
			cout << "    =============" << endl;
			Sleep(300);
			system("cls");
			cout << "              " << endl; 
			cout << "              " << endl;      
			cout << "         0    " << endl; 
			cout << "         /o\  " << endl; 
			cout << "         / \\ " << endl; 
			cout << "    =============" << endl;

			Sleep(500);
			system("cls");
			cout << "              " << endl; 
			cout << "              " << endl;      
			cout << "          0__  " << endl; 
			cout << "         /o  " << endl; 
			cout << "         / \\ " << endl; 
			cout << "    =============" << endl;

			Sleep(500);
			system("cls");
			cout << "              " << endl; 
			cout << "              " << endl;      
			cout << "        __0__  " << endl; 
			cout << "          o  " << endl; 
			cout << "         / \\ " << endl; 
			cout << "    =============" << endl;
			Sleep(500);
			system("cls");
			cout << "              " << endl; 
			cout << "              " << endl;      
			cout << "          0 /  " << endl; 
			cout << "         /o  " << endl; 
			cout << "         / \\ " << endl; 
			cout << "    =============" << endl;

			Sleep(500);
			system("cls");
			cout << "              " << endl; 
			cout << "              " << endl;      
			cout << "        \\ 0 /  " << endl; 
			cout << "        __o__ " << endl; 
			cout << "             " << endl; 
			cout << "    =============" << endl;
			Sleep(500);
			system("cls");
			cout << "              " << endl; 
			cout << "              " << endl;      
			cout << "        \\ 0 /  " << endl; 
			cout << "         __o__ " << endl; 
			cout << "             " << endl; 
			cout << "    =============" << endl;
			Sleep(500);
			system("cls");
			cout << "              " << endl; 
			cout << "              " << endl;      
			cout << "        \\ 0 /  " << endl; 
			cout << "       __o__ " << endl; 
			cout << "             " << endl; 
			cout << "    =============" << endl;
			Sleep(500);
			system("cls");
			cout << "              " << endl; 
			cout << "              " << endl;      
			cout << "        \\ 0 /  " << endl; 
			cout << "          o  " << endl; 
			cout << "         / \\ " << endl; 
			cout << "    =============" << endl;
		}
	}
	system("pause");
	return 0;
}