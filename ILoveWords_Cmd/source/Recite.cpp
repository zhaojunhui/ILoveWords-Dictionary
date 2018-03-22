#include "Pattern.h"
#include "Recite.h"
#include <iostream>
#include <ctime>

using namespace std;

//加上procesor之后，需要将database_改为processor_ -> GetDataBase()

Recite::Recite (const string& username, const string& dictname, Processor* proc) :
	Pattern (username, dictname, proc) {}

void Recite::Start()
{
	processor_ -> GetDataBase() -> SetNewWord();
	cout << "***************************************************" << endl
		 << "* 'start'  start reciting                         *" << endl
		 << "* '-quit'   quit reciting                         *" << endl
		 << "* 'set n'  set n new words per day                *" << endl
		 << "***************************************************" << endl << endl;
	
	//new
	if (processor_ -> GetDataBase() -> CheckFinish())
	{
		cerr << "$You have finished all the words in this dictionary. Please print '-quit'." << endl << endl;
	}
	//new
}

bool Recite::Init()
{
	time_t time_ = time(NULL);
	cur_time_ = localtime(&time_);
	legal_next_ = legal_undo_ = legal_YN_ = false;
	if (processor_ -> GetDataBase() -> CheckTodayFinish(*cur_time_))
	{
		cerr << "$You have finished today's mission! Print '-quit' to quit reciting" << endl << endl;
		//Quit();
		return false;
	}
	
	period_ = 0;
	cur_word_ = processor_ -> GetDataBase() -> GetReciteWord(*cur_time_);
	word_period_ = cur_word_.GetPeriod();
	return true;
}

void Recite::Step0()
{
	if (!Init()) return;
	cout << cur_word_.GetWord() << ' ' << cur_word_.GetPronnounce() << endl;
	if (word_period_ == 1) cur_word_.PrintSentence(cout);
	legal_YN_ = true;
	cout << "$Know it? Print 'Yes' if you know it; otherwise, print 'No'." << endl << endl;
}

void Recite::StepYes()
{
	if (!legal_YN_) 
	{
		cerr << "$Bad command!" << endl << endl;
		return;
	}
	
	legal_YN_ = false;
	processor_ -> GetDataBase() -> AddFeature(-1);
	cout << cur_word_ << endl;
	if (period_ == 0)
	{
		if (word_period_ == 0)
		{
			cout << "$Word Finished! Print 'undo' if you still want to recite this word today; otherwise print 'next'" << endl << endl;
			legal_next_ = legal_undo_ = true;
		} else
		{
			legal_next_ = true;
			processor_ -> GetDataBase() -> SetWordPeriod(0, *cur_time_);
			cout << "$Print 'next' to continue reciting." << endl << endl;
		}
	} else 
	{
		legal_next_ = true;
		processor_ -> GetDataBase() -> SetWordPeriod(cur_word_.GetPeriod(), *cur_time_);//new
		cout << "$Print 'next' to continue reciting." << endl << endl;
	}
}

void Recite::StepNo()
{
	if (!legal_YN_)
	{
		cerr << "$Bad command!" << endl << endl;
		return;
	}
	
	legal_YN_ = false;
	processor_ -> GetDataBase() -> AddFeature(1);
	if (period_ == 0 && word_period_ == 0 && cur_word_.GetSentenceNum() != 0)
	{
		cur_word_.PrintSentence(cout);
		cout << "$Know it? Print 'Yes' if you know it; otherwise, print 'No'." << endl << endl;
		period_ = 1;
		legal_YN_ = true;
	} else
	{
		cout << cur_word_ << endl;
		processor_ -> GetDataBase()-> SetWordPeriod(1, *cur_time_);
		legal_next_ = true;
		cout << "$Print 'next' to continue reciting." << endl << endl;
	} 
}

void Recite::Next()
{
	if (!legal_next_)
	{
		cerr << "$Bad command!" << endl << endl;
		return;
	}
	
	legal_next_ = false;
	if (legal_undo_)
	{
		legal_undo_ = false;
		processor_ -> GetDataBase() -> SetWordPeriod(2, *cur_time_);
	}
	Step0();
}

void Recite::Undo()
{
	if (!legal_undo_)
	{
		cerr << "$Bad command!" << endl << endl;
		return;
	}
	
	legal_undo_ = legal_next_ = false;
	processor_ -> GetDataBase() -> SetWordPeriod(cur_word_.GetPeriod(), *cur_time_);//new
	cout << "$Print 'next' to continue reciting." << endl << endl;
	legal_next_ = true;
}

void Recite::SetWordPerDay(const string &s)
{
	if (atoi(s.c_str()) <= 0) return;
	processor_ -> GetDataBase() -> SetNewWordPerDay(atoi(s.c_str()));
	//cout << atoi(s.c_str()) << endl;
}

void Recite::RunCmd(const string &cmd)
{
	cout << endl;
	if (cmd == "start") Step0();
	else if (cmd == "Yes") StepYes();
	else if (cmd == "No") StepNo();
	else if (cmd == "next") Next();
	else if (cmd == "undo") Undo();
	else if (cmd.substr(0, 4) == "set ") SetWordPerDay(cmd.substr(4));
	else cerr << "$Bad command!" << endl << endl;
}
