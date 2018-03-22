#include <cstdlib>
#include <iostream>
#include "Test.h"
#include "Word.h"
#include "Quiz.h"
#include "DataBase.h"


using namespace std;

Test::Test(Quiz *quiz, SingleWord &word) : cur_word_(word), quiz_(quiz) {}

void Test::ShowAns()
{
	cout << "Correct answer : " << ans_  << endl;
}

ostream& operator<< (ostream& o, Test &test)
{
	test.Print(o);
	return o;
}


Test1::Test1(Quiz* quiz, SingleWord& word) : Test(quiz, word) 
	{ CreateProb(); }

void Test1::CreateProb()
{
	list_.clear(); list_.push_back(cur_word_);
	for (int i = 1; i <= sum; ++i)
	{
		SingleWord word;
		while (1)
		{
			bool pd = true;
			word = quiz_ -> GetDataBase() -> RandWord();
			for (int i = 0; i != list_.size(); ++i) if (word.GetWord() == list_[i].GetWord())
			{
				pd = false;
				break;
			}
			if (pd) break;
		}
		list_.push_back(word);
	}
}

void Test1::Print(ostream &o)
{
	o << "Which one is the Chinese meaning of the following word?" << endl;
	o << cur_word_.GetWord() << ' ' << cur_word_.GetPronnounce() << endl;
	srand(time(NULL));
	int num = rand() % 4;
	char cnt = 'A';
	ans_ += (char)(cnt + num);
	for (int i = 1; i <= num; ++i) o <<  cnt++ << ' ' << list_[i].GetMeaning() << endl;
	o << cnt++ << ' ' << list_[0].GetMeaning() << endl;
	for (int i = num + 1; i <= sum; ++i) o <<  cnt++ << ' ' << list_[i].GetMeaning() << endl;
}

int Test1::CheckResponse(const string &ans)
{
	if (ans != "A" && ans != "B" && ans != "C" && ans != "D") return -1;
	if (ans != ans_) return 0;
	return 1;
}


Test2::Test2(Quiz* quiz, SingleWord& word) : Test(quiz, word) 
	{ CreateProb(); }

void Test2::CreateProb()
{
	list_.clear(); list_.push_back(cur_word_);
	for (int i = 1; i <= sum; ++i)
	{
		SingleWord word;
		while (1)
		{
			bool pd = true;
			word = quiz_ -> GetDataBase() -> RandWord();
			for (int i = 0; i != list_.size(); ++i) if (word.GetWord() == list_[i].GetWord())
			{
				pd = false;
				break;
			}
			if (pd) break;
		}
		list_.push_back(word);
	}
}

void Test2::Print(ostream &o)
{
	o << "Which one matches the following Chinese meaning?" << endl;
	o << cur_word_.GetMeaning() << endl;
	srand(time(NULL));
	int num = rand() % 4;
	char cnt = 'A';
	ans_ = cnt + num;
	for (int i = 1; i <= num; ++i) o <<  cnt++ << ' ' << list_[i].GetWord() << endl;
	o << cnt++ << ' ' << list_[0].GetWord() << endl;
	for (int i = num + 1; i <= sum; ++i) o <<  cnt++ << ' ' << list_[i].GetWord() << endl;
}

int Test2::CheckResponse(const string &ans)
{
	if (ans != "A" && ans != "B" && ans != "C" && ans != "D") return -1;
	if (ans != ans_) return 0;
	return 1;
}




void Test3::Print(ostream &o)
{
	o << "Please enter the correct spelling according to the Chinese meaning:" << endl;
	o << cur_word_.GetMeaning() << endl << cur_word_.GetPronnounce() << endl;
}

int Test3::CheckResponse(const string &ans)
{
	if (ans == ans_) return 1;
	return 0;
}