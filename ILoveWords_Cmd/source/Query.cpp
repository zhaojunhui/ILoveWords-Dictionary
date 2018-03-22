#include <iostream>
#include <fstream>
#include <algorithm>
#include "func.h"
#include "Query.h"
#include "Log.h"
#include "Word.h"
#include "DataBase.h"
#include "Processor.h"
using namespace std;

Query::Query (const string& username, const string& dictname, Processor* proc) : 
	Pattern (username, dictname, proc), log_ (new Log (username_ + "_log", this)) {}

Query::~Query() 
{
	Quit();
	delete log_;
}

void Query::Start()
{	
	legal_query_ = true;
	cout << endl << "$Please enter a word:" << endl
		 << "***************************************************" << endl
		 << "* '-quit' exit query                             *" << endl
		 << "* '-log'  view history                           *" << endl
		 << "* '-file filename' new word statistic for a file *" << endl
		 << "* 'set n'  set history number showed each time    *" << endl
		 << "***************************************************" << endl;
}

void Query::Quit()
{
	log_ -> Save();
}


inline int Query::isDelCmd (const string& cmd) const
	{ return DecodeCmd (cmd, "del", log_ -> GetNum()); }


inline int Query::isSetCmd (const string& cmd) const
	{ return DecodeCmd (cmd, "set", Log::MAX); }


inline bool Query::isFileCmd (const string& cmd) const
{
	if (cmd.length() <= 5) return false;
	return (cmd.substr (0, 5) == "-file");
}

DataBase* Query::GetDataBase() const 
	{ return processor_ -> GetDataBase(); }
	

int Query::CalcAndNote (const string& path, bool all, vector<SingleWord>& vec)
{
	ifstream fin (path);
	if (!fin)
	{
		cerr << endl << "$Invalid path. Please try again or enter '-quit' to exit." << endl;
		fin.close();
		return -1;
	}
	
	int cnt = 0;
	string wrd;
	while (fin >> wrd) if (processor_ -> GetDataBase() -> CheckWord (wrd))
	{	
		SingleWord word = processor_ -> GetDataBase() -> GetWord (wrd);
		if (all || word.GetFeature() == 0) 
			log_ -> AddRecord (wrd), vec.push_back (word), cnt++;
	}
	fin.close();
	return cnt;
}

void Query::RunFileQuery (const string& cmd)
{
	if (!legal_query_) 
	{
		cerr << endl << "$File query not available now. Please enter 'q' to exit history first." << endl;
		return;
	}
	string path = cmd.substr(6);
	bool all = false;
	cout << endl << "$Would you like to query all the words in this file (or only new words)? \n ['y' or 'n']" << endl;
	string ans;  getline (cin, ans);
	if (ans == "y") all = true;
	
	vector<SingleWord> vec;
	int sum = CalcAndNote (path, all, vec);
	if (sum != -1) 
	{
		cout << endl << "$Query finished.";
		if (!all) cout << "$There are " << sum << " new words in this file." << endl << endl;
		else cout << endl;
		
		for (int i = 0; i < vec.size(); i++)
			cout << '[' << i + 1 << ']' << ' ' << vec[i] << endl;
		cout << endl << "$Please enter a word or enter a filename after '-file' " << endl << " ('-log' history, '-quit' exit):" << endl;
	}
}

void Query::RunWordQuery (const string& cmd)
{
	if (!legal_query_) 
	{
		cerr << endl << "$Word query not available now. Please enter 'q' to exit history first." << endl;
		return;
	}
	/***这里因为调试有改动！！***/
	if (!(processor_ -> GetDataBase() -> CheckWord (cmd)))
	{
		cout << endl << "$No matched answer or Wrong command. Try again or enter '-quit' to exit" << endl;
		vector<SingleWord> vec;
		processor_ -> GetDataBase() -> Similar (cmd, vec);
		cout << "$Do you mean any one of these?" << endl;
		for (int i = 0; i < vec.size(); i++) 
			cout << vec[i].GetWord() << endl; cout << endl;
		return;
	}

	/***输出详细信息，这里为调试有改动！***/
	SingleWord word = processor_ -> GetDataBase() -> GetWord (cmd);
	log_ -> AddRecord (cmd);
	cout << word << endl;
	cout << endl << "$Please enter a word or enter a filename after '-file' " << endl << " ('-log' history):" << endl;
	return;
}

void Query::SetHistoryNum (const string& cmd)
{
	int num = isSetCmd (cmd);
	log_ -> SetNum (num);
	cout << endl << "$History num set to " << num << endl;
	if (legal_query_) cout << endl << "$Please enter a word or enter a filename after '-file' " << endl << " ('-log' history, '-quit' exit):" << endl;
	else cout << endl << "$Enter 's' for following records or 'q' to exit." << endl;
}

void Query::RunDelCmd (const string& cmd)
{
	if (legal_query_) 
	{ 
		cerr << endl << "$Del command not available now. Please enter '-log' to enter history first." << endl; 
		return; 
	}
	int key = isDelCmd (cmd);
	if (key != ALL) log_ -> DelRecord (key);				
	else 			log_ -> DelAll();
	cout << endl << "$Enter 's' for following records or 'q' to exit." << endl;
}

void Query::ShowHistoryByStep()
{
	if (legal_query_) 
	{
		cerr << endl << "$Step command not available now. Please enter '-log' to enter history first." << endl;
		return;
	}
	log_ -> ShowHistory ("\n$Enter 's' for following records or 'q' to exit.");
}

void Query::ShowLog()
{
	legal_query_ = false;
	cout << endl << "$History:" << endl
		 << "***************************************************" << endl
		 << "* 's' view next 10 records                        *" << endl
		 << "* 'q' exit and back to query                      *" << endl
		 << "* 'del i' delete record [i]                       *" << endl
		 << "* 'del *' delete all history                      *" << endl
		 << "* 'set n' set record number showed each time to n *" << endl
		 << "***************************************************" << endl;
	log_ -> Save();
	log_ -> Initialize();
	log_ -> ShowHistory ("\n$Enter 's' for following records or 'q' to exit.");
}

void Query::QuitLog()
{
	if (legal_query_) 
	{
		cerr << endl << "$'q' command not available now. Please enter '-log' to enter history first." << endl;
		return;
	}
	log_ -> Save();
	legal_query_ = true;
	cout << endl << "$Query continued. ";
	cout << "$Please enter a word or enter a filename after '-file' " << endl << " ('-log' history, '-quit' exit):" << endl;
}


void Query::RunCmd (const string& cmd)
{
	if (isFileCmd (cmd)) RunFileQuery (cmd);
	else if (isSetCmd (cmd)) SetHistoryNum (cmd);
	else if (isDelCmd (cmd)) RunDelCmd (cmd);
	else if (cmd == "-log") ShowLog();
	else if (cmd == "s") ShowHistoryByStep();
	else if (cmd == "q") QuitLog();
	else RunWordQuery (cmd);
}
