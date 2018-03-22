#ifndef QUIZ_H
#define QUIZ_H


#include <iostream>
#include <string>
#include <vector>
#include "Pattern.h"

using std::string;
using std::vector;


class Test;
class DataBase;
class Processor;

class Quiz : public Pattern
{
public:
	Quiz (const string& username, const string& dictname, Processor* proc);
	~Quiz();
	
	virtual void Start();
	virtual void Quit();
	
	virtual void RunCmd (const string& cmd);
	
	DataBase* GetDataBase() const;
	
private:
	//接受用户输入的指令并处理异常
	bool Input (int i);
	
	//生成题目
	void Create (int i);
	
	//输出结果
	void Info() const;
	
private:
	//所有的试题
	vector<Test*> test_;
	
	//3种test的数目
	int num_[4];
	
	//题目总数
	int sum_;
	
	//当前测试到的位置
	int pos_;
	
	//正确、错误题目的数量
	int correct_, wrong_;
};


#endif //QUIZ_H