#ifndef SHELL_H
#define SHELL_H
#include"Processor.h"
#include"Pattern.h"

class Shell 
{
public:
	//登入、登出
	//void LogIn();
	void LogIn(const std::string& username);
	void LogOut();
	
	//注册
	//void SignUp();

	void Quit();
	
	//读入指令
	void LoadCmd();

	//构造函数
	Shell();
	Shell(const std::string& username, const std::string& dictname);
	
	//通过这个函数与Processor通信
	void RunCmd (const std::string& cmd);
private:
	const static std::string q_cmd_;
	const static std::string user_cmd_;
	const static int user_len_;

private:
	void LoadDict();

	bool Isuser_cmd_(const std::string& cmd);
	
private:
	std::string username_;
	std::string dictname_;
	std::stack<std::string> mission_;
	Processor* cur_processor_;
};

#endif
