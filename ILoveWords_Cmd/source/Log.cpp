#include <iostream>
#include <algorithm>
#include <fstream>
#include "Log.h"
#include "Word.h"
#include "Query.h"
#include "DataBase.h"

using namespace std;

ostream& operator<< (ostream& out, const Record& rcd)
{
	out << rcd.word;
	return out;
}

Log::Log (const string& filename, Query* query, int num) : 
	filename_ (filename), query_ (query), num_ (num)
{
	Initialize();
}


void Log::Initialize()
{
	ifstream fin ("./record/"+filename_, ifstream::in);
	data_.clear();
	
	//当文件存在时导入历史记录
	string record;
	
	if (fin)
	while (std::getline (fin, record))
	{
		data_.push_back (record);
	}
	fin.close();
	
	//输出时输出最新的num_条记录
	pos_ = data_.size();
	
	//如果历史记录为空则标记为无历史记录
	if (pos_ == 0) pos_ = -1;
}


void Log::ShowHistory (const string& info, bool flag)
{
	//如果没有更多的历史记录就退出
	if (pos_ == -1)
	{
		cout << "No more history. Enter 'q' to exit." << endl;
		return;
	}
	
	//从标记位置开始输出10条记录
	pos_ = max (0, pos_ - num_);
	
	//设置标记位置
	int tail = min (pos_ + num_ - 1, int(data_.size() - 1));
	for (int i = tail, j = 1; i >= pos_; i--, j++)
	{
		cout << '[' << j << ']' << ' ';
		if (flag) 
		{
			SingleWord wrd = query_ -> GetDataBase() -> GetWord (data_[i].word);
			cout << wrd << endl;
		}
		else cout << data_[i] << endl;
	}
	
	//如果历史记录已经全部输出则做标记“无更多历史记录”
	if (pos_ == 0) pos_ = -1;
	cout << info << endl;
	return;
}


void Log::DelRecord (int key)
{
	key--;
	//找到要删除的历史记录在vector中的位置
	int idx = min (pos_ + num_ - 1, int(data_.size() - 1)) - key;
	if (pos_ == -1 && idx == pos_ + num_ - 1 - key) idx++;
	if (idx < data_.size() && idx >= 0 && key < num_) 
	{
		cout << "$Record [" << key + 1 << "] deleted." << endl;
		data_[idx].isSaved = false;
	}
	else cout << "$There is no record [" << key + 1 << "]. Please try again." << endl;
}


void Log::DelAll()
{
	data_.clear(); pos_ = -1;
	cout << "$History cleared." << endl;
}


void Log::Save()
{
	ofstream fout ("./record/"+filename_, ofstream::out);
	int start = (data_.size() > kSize) ? (data_.size() - kSize) : 0;
	for (int i = start; i < data_.size(); i++) if (data_[i].isSaved) 
		fout << data_[i] << endl;
	fout.close();
}
