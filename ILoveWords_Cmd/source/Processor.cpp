#include <iostream>
#include <stdexcept>
#include "processor.h"
#include "Pattern.h"
#include "MainPattern.h"
#include "Quiz.h"
#include "Query.h"
#include "Recite.h"
#include "DataBase.h"
using namespace std;


const std::string Processor::switch_cmd_ = "-switch";
const std::string Processor::quit_cmd_ = "-quit";
const std::string Processor::dict_cmd_ = "-dict";
const std::string Processor::help_cmd_ = "-help";
const std::string Processor::increase_cmd_ = "-increase";


Processor::Processor (const std::string& user, const std::string& dict) :
	username_ (user), dictname_ (dict)
{
	patterns_[0] = new MainPattern(user, dict, this);
	patterns_[1] = new Quiz(user, dict, this);
	patterns_[2] = new Query(user, dict, this);
	patterns_[3] = new Recite(user, dict, this);
	cur_pattern_ = patterns_[0];
	cur_database_ = new DataBase(user, dict);
}

Processor::~Processor()
{
	mission_.clear();
	for (int i = 0; i != 4; ++i)
	{
		delete patterns_[i];
	}
	delete cur_database_;
}

void Processor::SetDataBase(DataBase* database)
{
	cur_database_ = database; 
}

DataBase* Processor::GetDataBase()
{
	return cur_database_;
}

void Processor::SetPattern(Pattern* pattern)
{
	cur_pattern_ = pattern;
}

Pattern* Processor::GetPattern()
{
	return cur_pattern_;
}

const std::string& Processor::GetDictname_()
{
	return dictname_;
}

void Processor::SetDictname_(const std::string& dictname)
{
	dictname_ = dictname;
}

void Processor::SetUsername_(const std::string& username)
{
	username_ = username;
}

const std::string& Processor::GetUsername_()
{
	return username_;
}

bool Processor::Isswitch_cmd_(const string& cmd)
{
	if(cmd.length() >= switch_cmd_.length() + 2) return (cmd.substr(0,switch_cmd_.length()) == switch_cmd_);
	else return false;
}

bool Processor::Isdict_cmd_(const string& cmd)
{
	if(cmd.length() >= dict_cmd_.length() + 2) return (cmd.substr(0,dict_cmd_.length()) == dict_cmd_);
	else return false;
}

bool Processor::Isincrease_cmd_(const string& cmd)
{
	if(cmd.length() >= increase_cmd_.length() + 2) return (cmd.substr(0,increase_cmd_.length()) == increase_cmd_);
	else return false;
}

void Processor::RunCmd (const string& cmd)
{
	if (Isswitch_cmd_(cmd)) {
		if(cmd.length() == switch_len_){
			if(cmd[switch_len_ - 2] != ' '){
			    cerr << "Error1" << endl;
			} else{
				if(cmd[switch_len_ - 1] >= '0' && cmd[switch_len_ -1] <= '3'){
					GotoPattern ((int) cmd[switch_len_ - 1] - '0');
				}
				else cerr << "Error2" << endl;
			}
		}
		else cerr << "Error3" << endl;
	} else if (cmd == quit_cmd_) {
		cur_pattern_ -> Quit();
		PrevPattern();
	} else if (Isdict_cmd_(cmd)) {
		//Clear();
		if(cmd[dict_cmd_.length()] == ' '){ 
			const string& tmp = cmd.substr(dict_cmd_.length() + 1);
			ChangeDict(tmp);
		}
		else cerr << "Error4" << endl;
	}else if (cmd == help_cmd_)
	{
		ShowCmd();
	}else if (Isincrease_cmd_(cmd))
	{
	    string word;
		word = cmd.substr(increase_cmd_.length() + 1);
		string sentence;
		cout << "please input the sentence" << endl;
		cin >> sentence;
		IncreaseSentence(word, sentence);
	}
	else {
		cur_pattern_ -> RunCmd (cmd);
	}
}

void Processor::GotoPattern (int i)
{
	cur_pattern_ = patterns_[i];
	mission_.push_back(cur_pattern_);
	cur_pattern_->Start();
}

void Processor::ChangeDict(const string& dictname)
{
	dictname_ = dictname;
	patterns_[0]->SetDictname_(dictname);
	patterns_[1]->SetDictname_(dictname);
	patterns_[2]->SetDictname_(dictname);
	patterns_[3]->SetDictname_(dictname);
	cur_pattern_->SetDictname_(dictname);
	cur_database_ = new DataBase(username_, dictname_);
}

void Processor::PrevPattern()
{
	if(!mission_.empty()) mission_.pop_back();
	if (mission_.size() == 0) cur_pattern_ = patterns_[0];
	else cur_pattern_ = mission_[mission_.size() - 1];
	cur_pattern_->Start();
}

void Processor::ShowCmd()
{
	cout << "-switch : to change the pattern" << endl
		 << "-dict : to change the dict" << endl
		 << "-user : to change the user" << endl
		 << "-quit : to quit the present pattern" << endl
		 << "-help : to show the legal command" << endl
		 << "-q : to quit the program" << endl;
}

void Processor::IncreaseSentence(const string& word,string sentence)
{
	if(cur_database_->SetSentence(word,sentence))
		cout << "increased already" << endl;
	else cout << "SingleWord not found" << endl;
}
