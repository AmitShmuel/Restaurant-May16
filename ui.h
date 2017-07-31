/* 
User interface module:: 
handling input output and main menu cases. */

#ifndef _UI_
#define _UI_
#include "Restaurant.h"

static string input; //static user's input variable

void userMenu(); 
void goodByeMsg();
void pause();
void Case1(Restaurant& r);
void Case2(Restaurant& r);
void Case5(Restaurant& r);
bool isNumber(const string& s);
string yesOrNo();
string getChoice();
string getChoiceMain();

#endif //_UI_