#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include "DataBase.h"

using namespace std;

/*update:
	add several lines in SetNewWord()
	add several lines in SetWordPeriod() (between two "//new"s)
		p.s.其实只是加了15min，但是由于之前的重载+是针对日期操作的，感觉再加一个函数的话结构不太好看，所以就直接写进去了
*/


struct myrand
{
	int a, b, c;
	long long last;
	int rand(){return (last = (a * last + b) % c);}
	myrand(int y, int z, int w) : b (y), c (z), last (w) { srand (time (NULL)); a = rand(); }
} ran(1102, 1992122981, 617);



bool DataBase::cmp(const SingleWord &w1, const SingleWord &w2) {return w1 > w2;}

bool DataBase::SameDate(const struct tm &t1, const struct tm &t2)
{
	if (t1.tm_year == t2.tm_year && t1.tm_yday == t2.tm_yday) return true;
	return false;
}

int DataBase::GetSimilar(const string &word1, const string &word2)
{
	int len1 = word1.length(), len2 = word2.length();
	vector<vector<int> > a(len1);
	for (int i = 0; i < a.size(); ++i) a[i].resize(len2);
	for (int i = 0; i != len1; ++i)
		for (int j = 0; j != len2; ++j)
		{
			a[i][j] = (word1[i] == word2[j]);
			if (i != 0) a[i][j] = max(a[i][j], a[i - 1][j]);
			if (j != 0) a[i][j] = max(a[i][j], a[i][j - 1]);
			if (i != 0 && j != 0) a[i][j] = max(a[i][j], a[i - 1][j - 1] + (word1[i] == word2[j]));
		}
	int num = 0;
	for (int i = 0; i < min(len1, len2); ++i) if (word1[i] != word2[i]) num++;
	return len1 + len2 - a[len1 - 1][len2 - 1] * 2 + abs(len1 - len2) + num;
}

DataBase::DataBase(const string &username, const string &dictname) : username_(username)
{
	open_dic_ = true;
	
	int l = 0, r = dictname.size() - 1;
	for (int i = dictname.size() - 1; i >= 0; --i) if (dictname[i] == '/')
	{
		l = i + 1;
		break;
	}
	for (int i = dictname.size() - 1; i >= 0; --i) if (dictname[i] == '.')
	{
		r = i - 1;
		break;
	}
	dictname_ = dictname.substr(l, r - l + 1);
	
	filename_ = username_ + '_' + dictname_;
	ifstream fin(("./record/" + filename_).c_str(), ios::in);
	wordlist_.clear();
	if (fin) 
	{
		ReadHistory(fin);
		fin.close();
	} else
	{
		fin.close();
		if (!ReadDict(dictname)) open_dic_ = false;;
	}
	//SetNewWord();
}

void DataBase::ReadHistory(istream &ist)
{
	ist >> new_word_ >> last_word_ >> new_word_per_day_;
	ist >> last_visit_;
	SingleWord word;
	while (ist >> word)
	{
		word.SetPeriod(0);
		wordlist_.push_back(word);
	}
}

bool DataBase::ReadDict(const string &dictname)
{
	new_word_ = 0; last_word_ = 0; new_word_per_day_ = ReciteInitialSetting;
	last_visit_ = LastVisitInitialSetting;
	ifstream fin(dictname.c_str(), ios::in);
	if (!fin)
	{
		cout << "This dictionary doesn't exist!" << endl << endl;
		return false;
	}
	string word, pronnounce, meaning;
	time_t curtime;
	time(&curtime);
	struct tm *cur_time_ = localtime(&curtime);
	while (fin >> word)
	{
		getline(fin, pronnounce);
		getline(fin, meaning);
		SingleWord word_(word, pronnounce, meaning, CreditInitialSetting, FeatureInitialSetting);
		wordlist_.push_back(word_);
		last_word_ ++;
	}
	random_shuffle(wordlist_.begin(), wordlist_.end());
	fin.close();
	return true;
}

void DataBase::SetNewWord()
{
	time_t curtime;
	time(&curtime);
	struct tm *cur_time_ = localtime(&curtime);
	cur_time_ -> tm_hour = 0; cur_time_ -> tm_min = 0; cur_time_ -> tm_sec = 0; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!new
	if (SameDate(*cur_time_, last_visit_)) return;
	last_visit_ = *cur_time_;
	
	for (int i = new_word_ ; i <= min(last_word_, new_word_per_day_) + new_word_ - 1; ++i) wordlist_[i].SetCredit(*cur_time_);
	new_word_ += min(last_word_, new_word_per_day_);
	last_word_ = max(0, last_word_ - new_word_per_day_);
	
	//new
	struct tm t0 = *cur_time_;
	for (int i = 0; i < new_word_; ++i)
	{
		struct tm tt = wordlist_[i].GetCredit();
		if ((tt.tm_year < cur_time_ -> tm_year) || (tt.tm_year == cur_time_ -> tm_year && tt.tm_yday <= cur_time_ -> tm_yday))
		{
			wordlist_[i].SetCredit(t0);
			t0.tm_min += 2;
			if (t0.tm_min >= 60)
			{
				t0.tm_min -= 60; t0.tm_hour += 1;
			}			
		}
	}
	//new
	
	if (new_word_ != 0) make_heap(&wordlist_[0], &wordlist_[new_word_], cmp);
}

DataBase::~DataBase()
{
	ofstream fout(("./record/" + filename_).c_str());
	fout << new_word_ << ' ' << last_word_ << ' ' << new_word_per_day_ << endl;
	fout << last_visit_ << endl;
	for (int i = 0; i != wordlist_.size(); ++i) wordlist_[i].CreateHistory(fout);
	fout.close();
}

void DataBase::SetNewWordPerDay(int num)
{
	new_word_per_day_ = num;
}

bool DataBase::CheckFinish()
{
	if (new_word_ == 0 && last_word_ == 0) return true;
	return false;
}

bool DataBase::CheckTodayFinish(struct tm t)
{
	if (new_word_ == 0) return true;
	struct tm t0 = wordlist_[0].GetCredit();
	if ((t0.tm_year > t.tm_year) || (t0.tm_year == t.tm_year && t0.tm_yday > t.tm_yday)) return true;
	return false;
}

SingleWord DataBase::GetReciteWord(struct tm t)
{
	return wordlist_[0];
}

void DataBase::SetWordPeriod(int num, struct tm t)
{
	wordlist_[0].SetPeriod(num);
	
	//new
	struct tm t0 = wordlist_[0].GetCredit();
	if (t0.tm_hour == 23 && t0.tm_min >= 49)
	{
		t0.tm_min = 59; t0.tm_sec = 59;
	} else
	{
		t0.tm_min = t0.tm_min + 10;
		if (t0.tm_min >= 60)
		{
			t0.tm_min -= 60;
			t0.tm_hour += 1;
		}
	}
	wordlist_[0].SetCredit(t0);
	//new
	
	
	if (num == 2)
	{
		wordlist_[0].SetPeriod(0);
		wordlist_[0].ChangeCredit(t);
		wordlist_[0].IncTimes();
		if (wordlist_[0].Finish())
		{
			SingleWord word = wordlist_[0];
			for (int i = 0; i != wordlist_.size() - 1; ++i) wordlist_[i] = wordlist_[i + 1];
			wordlist_[wordlist_.size() - 1] = word;
			new_word_ --;
		}
	}
	if (new_word_ != 0) make_heap(&wordlist_[0], &wordlist_[new_word_], cmp);
}

void DataBase::Undo()
{
	SingleWord word = wordlist_[wordlist_.size() - 1];
	for (int i = 0; i != wordlist_.size() - 1; ++i) wordlist_[i + 1] = wordlist_[i];
	wordlist_[0] = word;
	new_word_ ++;
	make_heap(&wordlist_[0], &wordlist_[new_word_], cmp);
}

bool DataBase::OpenDic()
{
	return open_dic_;
}

void DataBase::AddFeature(int num)
{
	int ini = wordlist_[0].GetFeature();
	wordlist_[0].SetFeature(max(0, ini + num));
}

bool DataBase::AddWord(string word, string pronnounce, string meaning)
{
	if (CheckWord(word)) return false;
	SingleWord word_(word, pronnounce, meaning, CreditInitialSetting, FeatureInitialSetting);
	wordlist_.push_back(word_);
	for (int i = wordlist_.size() - 2; i >= new_word_ + last_word_; --i) wordlist_[i + 1] = wordlist_[i];
	wordlist_[new_word_ + last_word_] = word_;
	last_word_ ++;
	return true;
}

bool DataBase::CheckWord(const string &word)
{
	for (int i = 0; i != wordlist_.size(); ++i) if (wordlist_[i].GetWord() == word) return true;
	return false;
}

SingleWord DataBase::GetWord(const string &word)
{
	SingleWord ans = wordlist_[0];
	for (int i = 0; i != wordlist_.size(); ++i) if (wordlist_[i].GetWord() == word) ans = wordlist_[i];
	return ans;
}

int DataBase::GetReciteNum()
{
	return wordlist_.size() - last_word_;
}

SingleWord DataBase::RandWord()
{
	return wordlist_[ran.rand() % wordlist_.size()];
}

SingleWord DataBase::RandReciteWord()
{
	int p = ran.rand() & 1, cnt = wordlist_.size() - new_word_ - last_word_;
	if (p == 0 || cnt == 0) return wordlist_[ran.rand() % new_word_];
	return wordlist_[ran.rand() % cnt + new_word_ + last_word_];
}

void DataBase::Similar(const string &word, vector<SingleWord> &vec)
{
	int cnt1 = INF, cnt2 = INF, cnt3 = INF, cnt4 = INF; 
	SingleWord word1, word2, word3, word4;
	for (int i = 0; i != wordlist_.size(); ++i)
	{
		string word0 = wordlist_[i].GetWord();
		int diff = GetSimilar(word, word0);
		if (diff < cnt1)
		{
			word4 = word3; word3 = word2; word2 = word1; word1 = wordlist_[i];
			cnt4 = cnt3; cnt3 = cnt2; cnt2 = cnt1; cnt1 = diff;
		} else if (diff < cnt2)
		{
			word4 = word3; word3 = word2; word2 = wordlist_[i];
			cnt4 = cnt3; cnt3 = cnt2; cnt2 = diff;
		} else if (diff < cnt3)
		{
			word4 = word3; word3 = wordlist_[i];
			cnt4 = cnt3; cnt3 = diff;
		} else if (diff < cnt4)
		{
			word4 = wordlist_[i]; cnt4 = diff;
		}
	}
	vec.clear(); vec.push_back(word1); vec.push_back(word2); vec.push_back(word3); vec.push_back(word4);
}

bool DataBase::SetSentence(const string &word, string sentence)
{
	for (int i = 0; i != wordlist_.size(); ++i) if (wordlist_[i].GetWord() == word)
	{
		wordlist_[i].AddSentence(sentence);
		return true;
	}
	return false;
}

void DataBase::Check()
{
	ofstream fout("check.txt");
	for (int i = 0; i != wordlist_.size(); ++i)
	{
		fout << wordlist_[i].GetWord() << endl;
	}
	fout << endl;
	for (int i = 0; i != wordlist_.size(); ++i)
	{
		fout << wordlist_[i].GetPronnounce() << endl;
	}
	fout << endl;
	for (int i = 0; i != wordlist_.size(); ++i)
	{
		fout << wordlist_[i].GetMeaning() << endl;
	}
	fout.close();
}
