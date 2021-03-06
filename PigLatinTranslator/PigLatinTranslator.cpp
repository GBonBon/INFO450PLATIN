// PigLatinTranslator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" 
#include <iostream>
#include <string>

using namespace std;

string getWord(string &);
string translateToPigLatin(string);
string Trim(string);
string isVowel(string);
bool isConjuction(string);
bool isNumber(string);
void createSentence();


int main()
{
	char answer;
	bool cont = true;

	//honestly please look over this I have tried and tried to make it work but It seems to just delete the first letter then after the initial run it works fine.
	while(cont) {
		cout << "please enter a sentence that you want to translate in  Pig Latin" << endl;

		cin.ignore();

		createSentence();

		cout << "do you want to enter another sentence? Y/N";
			cin >> answer;

			if(answer== 'Y'|| answer == 'y')
			{
				cont = true;
			}
			else if (answer == 'N' || answer == 'n')
			{
				cont = false;
			}

	}

	return 0;
}
//creates piglatin sentence and prints to console
void createSentence()
{ 
	string str; //user entered sentence
	string pigLatin; // translated sentence

	getline(cin, str);

	while (str.size() > 0)
	{
		string word = getWord(str);

		word = translateToPigLatin(word);

		pigLatin += word + " ";

	}

	cout << pigLatin << endl;

	
}

//parses word from sentence
string getWord(string &str)
{
	str = Trim(str);

	int i = 0;


	while (str[i] != ' ' && i < str.size())

		i++;

	string word = str.substr(0, i);

	str.erase(0, i);

	return word;

}
//trims spaces 
string Trim(string str)
{
	while (str[0] == ' ')
	{
		str.erase(0, 1);

	}
	return str;
}
//translate words and sentences to piglatin
string translateToPigLatin(string word)
{
	
	char first = word[0];

	if (word.length() > 2 && !isConjuction(word) && !isNumber(word))
	{
		if (word[0] == 'A', word[0] == 'E', word[0] == 'I', word[0] == 'O', word[0] == 'U', word[0] == 'Y',
			word[0] == 'a', word[0] == 'e', word[0] == 'i', word[0] == 'o', word[0] == 'u', word[0] == 'y')
		{
			word.append("ay");
		}

		else
		{
			word.append(1,first);

			word.append("ay");

			word.erase(0, 1);
		}
	}
	return word;
}
//checks for conjunction
	bool isConjuction(string word)
	{
		string conjunction[10] = { "and", "but", "for", "nor", "so", "yet", "or", "the", "a", "an" };
		for(int i =0; i<10;i++)
		{
			if (word == conjunction[i])
			{
				return true;
			}
		}
		return false;
	}
//checks if number
	bool isNumber(string word)
	{
		string number[10] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "0" };
		for (int i = 0; i<10; i++)
		{
			if (word == number[i])
			{
				
				return true;
				
			}
		}
		return false;
	}


