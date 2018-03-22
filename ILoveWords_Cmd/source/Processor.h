#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <vector>
#include <stack>
#include <string>
#include "DataBase.h"

class Pattern;

class Processor
{
public:
	Processor (const std::string& user, const std::string& dict = "dictionary.txt");

	~Processor();
	
   	void RunCmd (const std::string& cmd);

	//选择模式：类似命令行，通过cmd进入新的活动
	void GotoPattern (int i);
	
	//获取DataBase;
	void SetDataBase(DataBase* database);
	
	DataBase* GetDataBase();

	void SetPattern(Pattern* pattern);

	Pattern* GetPattern();
	
	//获取Dictname_;
	const std::string& GetDictname_();

	void SetDictname_(const std::string& dictname);

	void SetUsername_(const std::string& username);

	const std::string& GetUsername_();
	
private:
	static const int patterns_nums_ = 4;
	static const int switch_len_ = 9;
	static const std::string switch_cmd_;
	static const std::string quit_cmd_;
	static const std::string dict_cmd_;
	static const std::string increase_cmd_;
	static const std::string help_cmd_;
	
private:

	//返回上一模式，_mission退栈
	void PrevPattern();
	
	//更换正在背诵的词典，之前需要终止并清空当前的一切任务，重新建立数据库和各种设备，//并给_patterns[]中的指针赋值
	void ChangeDict (const std::string& dictname);

	//显示命令
	void ShowCmd();

	void IncreaseSentence(const std::string& word,std::string sentence);

	bool Isswitch_cmd_(const std::string& cmd);

	bool Isdict_cmd_(const std::string& cmd);

	bool Isincrease_cmd_(const std::string& cmd);
	
	//终止并清空当前所有任务，delete掉_patterns[]中所有指针
	//void Clear();
	
private:
	//用户名和当前的词典名
	std::string username_;
	std::string dictname_;

	//当前正在进行的模式，指向候选模式中的某一个
	Pattern* cur_pattern_;

	//
	DataBase* cur_database_;
	
	//个人觉得可以加一个栈，这样可以方便在完成某一任务之后直接回到上一任务
	std::vector<Pattern*> mission_;
	//stack<const std::string> mission_;
	
	//候选的模式
	Pattern* patterns_[patterns_nums_ + 1];
};



#endif

