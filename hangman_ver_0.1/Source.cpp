#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
string Choosen_Word()
{
	return "book";
}
void RenderGame(string GuessedWord, int BadWord_Count)
{
	cout << GuessedWord << endl;
	cout << "Number of wrong guesses: " << BadWord_Count;
}
string UpDate(string GuessWord, string Word, char Guess)
{
	for(int i = Word.length() - 1; i >= 0; i--)
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
int main()
{
	string Word = Choosen_Word();
	string GuessWord = Word;
	int BadWord_Count = 0;
	char Guess;
    DoiChuoi(Word,GuessWord);
	int check;
	do{
		cout << "\nEnter one characters: ";
		cin >> Guess;
		BadWord_Count++;
	
		GuessWord = UpDate(GuessWord,Word,Guess);
		RenderGame(UpDate(GuessWord,Word,Guess), BadWord_Count);
		check = (GuessWord == Word);
	}while(check != 1 && BadWord_Count < 7);

	system("pause");
	return 0;
}