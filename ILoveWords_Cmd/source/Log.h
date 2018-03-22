#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::ostream;
using std::endl;

struct Record
{
	string word;
	bool isSaved;
	
	Record (const string& wrd, bool save = true) : 
		word (wrd), isSaved (save) {}
};

ostream& operator<< (ostream& out, const Record& rcd);

class Query;

class Log
{
public:
	Log (const string& filename, Query* query, int num = 10);
	~Log() {}
	
public:
	//用于函数返回值表示需要处理当前全部数据
	const static int ALL = 0x1f1f1f;
	
	//每次显示的历史记录数量的上限
	const static int MAX = 200;
	
	//设置每次显示的记录数量
	void SetNum (int num) { num_ = num; }
	
	//当前每次显示的记录数量
	int GetNum() const { return num_; }
	
	//显示历史记录，flag表示是否输出详细信息
	void ShowHistory (const string& info = "", bool flag = false);
	
	//增加历史记录
	void AddRecord (const string& word) 
		{ data_.push_back (Record (word)); }
	
	//删除历史记录key
	void DelRecord (int key);
	
	//删除全部历史记录
	void DelAll();

	//初始化
	void Initialize();
	
	//将历史记录保存
	void Save();
	
private:
	//只保存最近1000条历史记录
	const int kSize = 1000;	
	
	//每次显示的数量
	int num_;
private:

	string filename_;
	vector<Record> data_;
	
	//调用它的Query
	Query* query_;
	
	//上次查询到的位置，每次退出查询时重新设定为开头
	int pos_;
	
};




#endif //LOG_H