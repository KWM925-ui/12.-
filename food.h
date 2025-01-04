#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include"Material.h"
using namespace std;
#define MATERIAL "原材料信息.txt"
#define cai1 "水煮牛肉出售量.txt"
#define cai2 "猪杂出售量.txt"
#define cai3 "白切鸡出售量.txt"
#define cai4 "开水白菜出售量.txt"
#define cai5 "肉类拼盘出售量.txt"

class Food
{
public:
	Food();
	//保存原材料信息
	void Save_Material();
	virtual bool IFMake() = 0;
	virtual void If_Do_Want() = 0;
	~Food();
};

class WaterBeef :public Food
{
public:
	WaterBeef();
	//查看是否能制作
	bool IFMake();

	//询问是否需要制作一份
	void If_Do_Want();

	static void count1();
	static int Getcount1();
	static int W1;
	~WaterBeef();
};

class Pig_Za :public Food
{
public:
	Pig_Za();
	//查看是否能制作
	bool IFMake();

	//询问是否需要制作一份
	void If_Do_Want();

	static void count2();
	static int Getcount2();
	static int P1;
	~Pig_Za();
};

class Whie_zhiyin :public Food
{
public:
	Whie_zhiyin();
	//查看是否能制作
	bool IFMake();

	//询问是否需要制作一份
	void If_Do_Want();

	static void count3();
	static int Getcount3();
	static int J1;
	~Whie_zhiyin();
};

class BaiCai :public Food
{
public:
	BaiCai();
	//查看是否能制作
	bool IFMake();

	//询问是否需要制作一份
	void If_Do_Want();

	static void count4();
	static int Getcount4();
	static int Cai1;
	~BaiCai();
};

class DifrMeat :public Food
{
public:
	DifrMeat();
	//查看是否能制作
	bool IFMake();

	//询问是否需要制作一份
	void If_Do_Want();

	static void count5();
	static int Getcount5();
	static int D1;
	~DifrMeat();
};