// myjob.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "json.hpp"
#include <iostream>
#include <fstream>
#include <streambuf>

using namespace std;
using json::JSON;

int main()
{
	string contents;
	ifstream input("C:/Users/时空/Desktop/SimpleJSON-master/SimpleJSON-master/test/cases/test1.json");
	input.seekg(0, ios::end);
	contents.reserve(input.tellg());
	input.seekg(0, ios::beg);

	contents.assign((istreambuf_iterator<char>(input)),
		istreambuf_iterator<char>());

	JSON obj = JSON::Load(contents);


	ofstream output("C:/Users/时空/Desktop/SimpleJSON-master/SimpleJSON-master/test/cases/out.json");
	output << obj << endl;
	system("pause");
}


