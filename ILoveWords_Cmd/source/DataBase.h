#ifndef DATABASE_H
#define DATABASE_H

#include "Word.h"
#include <fstream>
#include <ctime>

class DataBase
{
	const int INF = 0x7fffffff;
	const int NewWordMark = 0;//!in DataBase or in Word?
	const int ReciteInitialSetting = 100;//每天新单词数量初始设置
	const int FeatureInitialSetting = 0;
	const struct tm LastVisitInitialSetting = {0, 0, 0, 1, 1, 1900, 0, 0, 0};//last_visit_初始设置
	const struct tm CreditInitialSetting = {0, 0, 0, 1, 1, 3000, 0, 0, 0};//credit_初始设置
	const struct tm FinishSetting = {0, 0, 0, 1, 1, 5000, 0, 0, 0};//某个单词背完的标志
	static bool cmp(const SingleWord &w1, const SingleWord &w2);
	
private:
	std::string username_;//用户名
	std::string dictname_;//字典名
	std::string filename_;//用户—字典历史记录的文件名
	std::vector<SingleWord> wordlist_;//单词表
	
	int new_word_;//正在背的单词数
	int last_word_;//剩余未背单词数
	int new_word_per_day_;//每天要背的新单词数
	struct tm last_visit_;//该用户上次访问（背）该词典的时间
	bool open_dic_;
	
private:
	bool SameDate(const struct tm &t1, const struct tm &t2);//检验两个时间是否同时同日期
	int GetSimilar(const std::string &word1, const std::string &word2);
	
private:
	void ReadHistory(std::istream &ist);//读取历史文件，从历史文件中加载单词信息
	bool ReadDict(const std::string &dictname);//读取词典文件，从词典文件中加载单词信息
	
public:
	DataBase(const std::string &username, const std::string &dictname);//构造函数
	~DataBase();//!public or private?//析构函数，并且将当前状态存入历史文件
	
public:
	void SetNewWord();//准备今天的所有正在背的单词，如果开始背单词操作要先调用该函数
	void SetNewWordPerDay(int num);//设置每日新单词数,次日生效
	bool CheckFinish();//检查该词典是否背完，背完返回true
	bool CheckTodayFinish(struct tm t);//检查当前要背的单词是否背完，背完返回true
	SingleWord GetReciteWord(struct tm t);//获得一个目前要背的单词
	void SetWordPeriod(int num, struct tm t);
	void Undo();
	bool OpenDic();//如果该单词书名存在返回真，否则返回假
	void AddFeature(int num);//wordlist_[0]的feature值+num
	bool AddWord(std::string word, std::string pronnonce, std::string meaning);
	//如果单词已经存在返回false
public:
	bool CheckWord(const std::string &word);//检查word是否在该词典中，在返回true
	SingleWord GetWord(const std::string &word);//获得word单词的资料
	int GetReciteNum();
	SingleWord RandWord();
	SingleWord RandReciteWord();
	void Similar(const std::string &word, std::vector<SingleWord> &vec);
	
public:
	bool SetSentence(const std::string &word, std::string sentence);

public:
	void Check();
};


#endif