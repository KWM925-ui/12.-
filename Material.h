#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
#define mater_ji "����ʣ����.txt"
#define mater_niu "ţ��ʣ����.txt"
#define mater_zhu "����ʣ����.txt"
#define mater_cai "�߲�ʣ����.txt"

class AllMater
{
public:
	static int Having_Ji();
	static int Having_Niu();
	static int Having_Zhu();
	static int Having_Cai();
};
