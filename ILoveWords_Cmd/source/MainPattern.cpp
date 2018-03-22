#include<iostream>
#include<string>
#include "MainPattern.h"
#include "Processor.h"
using namespace std;

void MainPattern::Start()
{
	cout << "Please choose a pattern:" << endl
		 << "0: MainPattern" << endl
		 << "1: Quiz" << endl
		 << "2: Query" << endl
		 << "3: Recite" << endl;
}

bool MainPattern::Judge(const string& cmd)
{
	if(cmd.length() != 1){
 		cout << "Error!" << endl;
 		return false;
 	} else{
 	    if(cmd[0] < '0' || cmd[0] >= '4'){
 			cout << "Error@" << endl;
 			return false;
 		}
 	}
 	return true;
}


void MainPattern::RunCmd(const string& cmd)
{
	if(Judge(cmd))
		processor_->GotoPattern((int)(cmd[0] - '0'));
	
}
