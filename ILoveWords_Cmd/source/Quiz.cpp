#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include "DataBase.h"
#include "Pattern.h"
#include "Quiz.h"
#include "func.h"
#include "Word.h"
#include "Test.h"
using namespace std;


Quiz::Quiz (const string& username, const string& dictname, Processor* proc) :
	Pattern (username, dictname, proc), 
	pos_ (0), correct_ (0), wrong_ (0)
{
	memset (num_, 0, sizeof (num_));
}
	
	
Quiz::~Quiz()
{
	Quit();
}


void Quiz::Start()
{
	cout << endl << "***************************************************************" << endl;
	cout << "$Please choose the type and the number of the quiz:" << endl;
	cout << endl << "$The number of multiple choice I (English -> Chinese): ";
	if (!Input (1)) return;
	cout << "$The number of multiple choice II (Chinese -> English): ";
	if (!Input (2)) return;
	cout << "$The number of spelling check: ";
	if (!Input (3)) return;
	sum_ = num_[1] + num_[2] + num_[3]; 
	correct_ = wrong_ = pos_ = 0;
	
	for (int i = 1; i <= 3; i++)
		Create (i);
	
	if (test_.size()) cout << endl << '[' << pos_ + 1 << "] " << *(test_[0]) << endl;
}


void Quiz::Quit()
{
	for (int i = 0; i < test_.size(); i++)
		if (test_[i])
		{
			delete test_[i];
			test_[i] = NULL;
		}
	test_.clear();
}


DataBase* Quiz::GetDataBase() const 
	{ return processor_ -> GetDataBase(); }


bool Quiz::Input (int i)
{
	string ans;
	while (getline(cin, ans))
	{
		///if (ans == "--quit") { Quit(); return false; }
		num_[i] = StringToInt (ans);
		if (num_[i] != -1 /*&& num_[1] + num_[2] + num_[3] <= processor_ -> GetDataBase() -> GetReciteNum()*/)
			break;
		cout << endl << "$Invalid or too large input. Please Try again." << endl;
	}
	return true;
}


void Quiz::Create (int x)
{
	set<string> s;
	for (int i = 1; i <= num_[x]; i++)
	{
		SingleWord word = processor_ -> GetDataBase() -> RandWord();
		if (!s.count (word.GetWord()))
		{
			s.insert (word.GetWord());
			if (x == 1) test_.push_back (new Test1 (this, word));
			if (x == 2) test_.push_back (new Test2 (this, word));
			if (x == 3) test_.push_back (new Test3 (this, word));
		} else i--;
	}
}


void Quiz::Info() const
{
	cout << endl << "$Quiz finished." << endl
				 << "***********************************" << endl
				 << "$User: "    << username_ << endl
				 << "$Correct: " << correct_  << endl
				 << "$Wrong: "   << wrong_    << endl
				 << "$Sum: "     << sum_      << endl
				 << "$Score: "   << ((double)correct_ / sum_) * 100.0 << endl
				 << "***********************************" << endl << endl;
}		



void Quiz::RunCmd (const string& cmd)
{
	//!调试加入，之后删除
	//if (cmd == "--quit") { Quit(); return; }
	//!调试加入，之后删除
	
	if (pos_ >= test_.size()) {
		cout << endl << "$Wrong command. Please try again." << endl;
		return;
	}
	
	int ans = test_[pos_] -> CheckResponse (cmd);
	if (ans == -1)
	{
		cout << endl << "$Wrong command. Please try again." << endl;
	} else if (ans == 0)
	{
		cout << "$Oh no, wrong answer!" << endl;
		test_[pos_] -> ShowAns();
		pos_++; wrong_++;
		if (pos_ < test_.size()) cout << endl << '[' << pos_ + 1 << "] " << *(test_[pos_]) << endl;
	} else 
	{
		cout << "$Congratulations!" << endl;
		test_[pos_] -> ShowAns();
		pos_++; correct_++;
		if (pos_ < test_.size()) cout << endl << '[' << pos_ + 1 << "] " << *(test_[pos_]) << endl;
	}
	
	if (pos_ == test_.size())
		Info();
}
