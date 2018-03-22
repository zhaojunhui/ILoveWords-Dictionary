#include <iostream>
#include <cstring>
#include <vector>
#include <ctime>
#include "Word.h"

using namespace std;

void SingleWord::AddSentence(std::string sentence)
{
    sentence_.push_back(sentence);
}

struct tm SingleWord::GetCredit()
{
    return credit_;
}

int SingleWord::GetFeature()
{
    return feature_;
}

string SingleWord::GetWord()
{
    return word_;
}

int SingleWord::GetPeriod()
{
    return period_;
}

string SingleWord::GetPronnounce()
{
    return pronnounce_;
}

string SingleWord::GetMeaning()
{
    return meaning_;
}

int SingleWord::GetSentenceNum()
{
    return sentence_.size();
}

void SingleWord::SetCredit(struct tm credit)
{
    credit_ = credit;
}

void SingleWord::ChangeCredit(struct tm credit)
{
    credit_ = credit + stdTimes[times_];
}

void SingleWord::SetFeature(int feature)
{
    feature_ = feature;
}

void SingleWord::SetPeriod(int period)
{
    period_ = period;
}

void SingleWord::IncTimes()
{
    times_++;
}

bool SingleWord::Finish()
{
    return (times_ >= SumTimes);
}

void SingleWord::PrintSentence(ostream &o)
{
    for (int i = 0; i != sentence_.size(); ++i) o << sentence_[i] << endl;
}

void SingleWord::CreateHistory(ostream &o)
{
    o << word_ << pronnounce_ << endl;
    o << meaning_ << endl;
    o << credit_ << ' ' << feature_ << ' ' << times_ << ' ' << sentence_.size() << endl;
    for (int i = 0; i != sentence_.size(); ++i) o << sentence_[i] << endl;
}

SingleWord& SingleWord::operator= (const SingleWord &word)
{
    word_ = word.word_; pronnounce_ = word.pronnounce_; meaning_ = word.meaning_;
    sentence_ = word.sentence_;
    credit_ = word.credit_; feature_ = word.feature_; period_ = word.period_; times_ = word.times_;
    return *this;
}

string SingleWord::GetSentence()
{
    string str = "";
    for (int i = 0; i != sentence_.size(); ++i) str += sentence_[i] + "\n";
    return str;
}

string SingleWord::GetInfo()
{
    string info;
    info = word_ + pronnounce_ + '\n' + meaning_ + '\n';
    for (int i = 0; i != sentence_.size(); ++i) info += sentence_[i] + '\n';
    return info;
}

ostream& operator<< (ostream &o, const SingleWord &word)
{
    o << word.word_ << word.pronnounce_ << endl
      << word.meaning_ << endl;
    for (int i = 0; i != word.sentence_.size(); ++i) o << word.sentence_[i] << endl;
    return o;
}

istream& operator>> (istream &ist, SingleWord &word)
{
    int cnt;
    ist >> word.word_;
    getline(ist, word.pronnounce_);
    getline(ist, word.meaning_);
    ist >> word.credit_ >> word.feature_ >> word.times_ >> cnt;
    char ch; if (cnt != 0) ist >> ch;
    //cout << cnt << endl;
    word.sentence_.clear();
    for (int i = 0; i < cnt; ++i)
    {
        string sentence;
        getline(ist, sentence);
        //cout << sentence;
        word.sentence_.push_back(sentence);
    }
    return ist;
}

bool operator<  (const SingleWord &w1, const SingleWord &w2)
{
    if (w1.credit_ < w2.credit_) return true;
    return false;
}

bool operator>  (const SingleWord &w1, const SingleWord &w2)
{
    if (w1.credit_ > w2.credit_) return true;
    return false;
}

bool operator< (const struct tm &t1, const struct tm &t2)//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!new
{
    if (t1.tm_year != t2.tm_year) return (t1.tm_year < t2.tm_year);
    if (t1.tm_yday != t2.tm_yday) return (t1.tm_yday < t2.tm_yday);
    if (t1.tm_hour != t2.tm_hour) return (t1.tm_hour < t2.tm_hour);
    if (t1.tm_min != t2.tm_min) return (t1.tm_min < t2.tm_min);
    if (t1.tm_sec != t2.tm_sec) return (t1.tm_sec < t2.tm_sec);
    return false;
}

bool operator> (const struct tm &t1, const struct tm &t2)//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!new
{
    if (t1.tm_year != t2.tm_year) return (t1.tm_year > t2.tm_year);
    if (t1.tm_yday != t2.tm_yday) return (t1.tm_yday > t2.tm_yday);
    if (t1.tm_hour != t2.tm_hour) return (t1.tm_hour > t2.tm_hour);
    if (t1.tm_min != t2.tm_min) return (t1.tm_min > t2.tm_min);
    if (t1.tm_sec != t2.tm_sec) return (t1.tm_sec > t2.tm_sec);
    return false;
}

ostream& operator<< (ostream& o, const struct tm &t)
{
    o << t.tm_sec << ' ' << t.tm_min << ' ' << t.tm_hour << ' ' << t.tm_mday << ' ' << t.tm_mon << ' ' << t.tm_year << ' ' << t.tm_wday << ' ' << t.tm_yday << ' ' << t.tm_isdst;
    return o;
}

istream& operator>> (istream &ist, struct tm &t)
{
    ist >> t.tm_sec >> t.tm_min >> t.tm_hour >> t.tm_mday >> t.tm_mon >> t.tm_year >> t.tm_wday >> t.tm_yday >> t.tm_isdst;
    return ist;
}

struct tm operator+ (struct tm t, int num)
{
    t.tm_yday = t.tm_yday + num;
    int days, year = 1900 + t.tm_year;
    if ((year % 100 == 0 && year % 400 == 0) || (year % 100 != 0 && year % 4 == 0)) days = 366;
    else days = 365;
    t.tm_year += t.tm_yday / days;
    t.tm_yday %= days;
    return t;
}
