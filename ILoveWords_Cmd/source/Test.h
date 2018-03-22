#ifndef TEST_H
#define TEST_H

#include <iostream>
#include "Word.h"

class Quiz;

class Test
{
private:
	virtual void Print(std::ostream &o) = 0;
	
protected:
	Quiz *quiz_;
	std::string ans_;
	SingleWord cur_word_;
	Test(Quiz*, SingleWord&);
	
public:
	virtual int CheckResponse(const std::string &) {}
	void ShowAns();

friend std::ostream& operator<< (std::ostream& o, Test &test);
};


class Test1 : public Test
{
	const int sum = 3;
	std::vector<SingleWord> list_;
	
	void CreateProb();
	
	virtual void Print(std::ostream &o);
	
public:
	Test1(Quiz* quiz, SingleWord& word);

	virtual int CheckResponse(const std::string &);
};

class Test2 : public Test
{
	const int sum = 3;
	std::vector<SingleWord> list_;
	
	void CreateProb();
	
	virtual void Print(std::ostream &o);
	
public:
	Test2(Quiz* quiz, SingleWord& word);

	virtual int CheckResponse(const std::string &);
};

class Test3 : public Test
{	
	virtual void Print(std::ostream &o);

public:
	Test3(Quiz* quiz, SingleWord& word) : Test(quiz, word) {ans_ = cur_word_.GetWord();}

	virtual int CheckResponse(const std::string &);
};


#endif