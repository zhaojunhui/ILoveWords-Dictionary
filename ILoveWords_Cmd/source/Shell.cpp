#include "Shell.h"
#include <cstdio>

using namespace std;

const string Shell::q_cmd_ = "-q";
const string Shell::user_cmd_ = "-user";
const int Shell::user_len_ = 5;

Shell::Shell()
{
	cout << "Your username :" ;
	cin >> username_;
	LoadDict();
}

void Shell::LoadDict()
{
	cout << "You can use our dictionary as follow:" << endl
		 << "./dict/CET4.txt" << endl
		 << "./dict/CET6.txt" << endl
		 << "./dict/Graduate.txt" << endl
		 << "./dict/GRE.txt" << endl
		 << "./dict/Toefl.txt" << endl
		 << "./dict/CET4_GBK.txt" << endl
		 << "./dict/CET6_GBK.txt" << endl
		 << "./dict/Graduate_GBK.txt" << endl
		 << "./dict/GRE_GBK.txt" << endl
		 << "./dict/Toefl_GBK.txt" << endl
		 << "Or you can load your own dictionary,please give the complete path of the directory of your dictionary" << endl;
	cout << "Your dictname :";
	cin >> dictname_;
	if(dictname_ == "")
	{
		const char* tmp = "./dict/CET4.txt";
		dictname_ = (string)(tmp);
	}
	cur_processor_ = new Processor(username_, dictname_);
	while(!cur_processor_->GetDataBase()->OpenDic())
	{
		cout << "Failed to open dictionary,please check the path" << endl
			 << "Your dictname :";
		cin >> dictname_;
		cur_processor_ = new Processor(username_,dictname_);
	}
	cout << "Welcome! " << username_ << endl;
	cur_processor_->GetPattern()->Start();
}

void Shell::Quit()
{
	LogOut();
	delete cur_processor_;
}

bool Shell::Isuser_cmd_(const string& cmd)
{
	if(cmd.length() >= user_cmd_.length() + 2) return (cmd.substr(0,user_len_) == user_cmd_);
	else return false;
}

void Shell::LoadCmd ()
{
	string tmp;
    getline(cin, tmp);
	if(tmp == "")
	{
		cout << "command can't be void" << endl;
		LoadCmd();
	}
	size_t str = tmp.find_first_not_of(" ");
	size_t last = tmp.find_last_not_of(" \n");
	tmp = tmp.substr(str, last - str + 1);
	mission_.push(tmp);
	if(tmp == q_cmd_) {
		Quit();
	} else if(Isuser_cmd_(tmp)) {
		LogOut();
		LogIn(tmp.substr(user_len_ + 1));
		LoadCmd();
	}
	else RunCmd(tmp);
}

void Shell::RunCmd (const string& cmd)
{
	cur_processor_->RunCmd(cmd);
	LoadCmd();
}

void Shell::LogOut()
{
	while(!mission_.empty())
		mission_.pop();
}

void Shell::LogIn(const string& username)
{
	username_ = username;
	LoadDict();
}


// void Shell::LogIn()
// {
//  	if(dictname_ == "")
// 	{
//  		dictname_ = "./record/CET4.txt";
// 	}
//     DataBase* database = new DataBase(username_, dictname_);
// 	if(database->OpenDic())
// 	{
// 		cur_processor_->SetDataBase(database);
// 		cout << "Welcome! " << username_ << endl;
// 	}
// 	else 
// }

// void Shell::LogIn(const string& username, const string& dictname)
// {
//  	username_ = username;
// 	if(dictname == "")
// 	{
//  		dictname_ = "./record/CET4.txt";
// 	}
//  	dictname_ = dictname;
// 	DataBase* database = new DataBase(username_, dictname_);
//  	cur_processor_->SetDataBase(database);
// 	cout << "Welcome! " << username_ << endl;
// }

// void Shell::SignUp()
// {
// 	//FILE* tmp =	fopen(username_.c_str(), "w");
//     DataBase* database = new DataBase(username_, cur_processor_->GetDictname_());
// 	cur_processor_->SetDataBase(database);
// 	cout << "Welcome! " << username_ << endl;
// }
