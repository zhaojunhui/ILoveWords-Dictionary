#ifndef WORD_H
#define WORD_H

#include <iostream>
#include <cstring>
#include <vector>
#include <ctime>

class SingleWord
{
	const int stdTimes[6] = {1, 2, 4, 7, 15, 0};
	const int SumTimes = 6;
	
private:
	std::string word_;
	std::string pronnounce_;
	std::string meaning_;
	std::vector<std::string> sentence_;
	
private:
	struct tm credit_;//
	int feature_;
	int period_;
	int times_;
	
public:
	SingleWord() {}
	SingleWord(std::string word, std::string pronnounce, std::string meaning, struct tm credit, int feature) :
		word_(word), pronnounce_(pronnounce), meaning_(meaning), credit_(credit), feature_(feature), period_(0), times_(0) {}

	void AddSentence(std::string sentence);
	
	struct tm GetCredit();
	
	int GetFeature();//0代表生词
	
	int GetPeriod();
	
	std::string GetWord();
	
	std::string GetPronnounce();
	
	std::string GetMeaning();
	
	int GetSentenceNum();
	
	std::string GetSentence();
	
	void SetCredit(struct tm credit);
	
	void ChangeCredit(struct tm credit);
	
	void SetFeature(int feature);
	
	void SetPeriod(int period);

	void SetWord(const std::string& word);
	
	void IncTimes();
	
	bool Finish();
	
	void CreateHistory(std::ostream &o);
	
	void PrintSentence(std::ostream &o);
	
	SingleWord& operator= (const SingleWord &word);
	
friend bool operator< (const SingleWord&, const SingleWord&);
 
friend bool operator> (const SingleWord&, const SingleWord&);
	
friend std::ostream& operator<< (std::ostream&, const SingleWord&);

friend std::istream& operator>> (std::istream&, SingleWord&);
};




bool operator< (const struct tm &t1, const struct tm &t2);

bool operator> (const struct tm &t1, const struct tm &t2);

std::ostream& operator<< (std::ostream&, const struct tm &);

std::istream& operator>> (std::istream&, struct tm &);

struct tm operator+ (struct tm t, int num);

#endif
