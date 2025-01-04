#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"worker.h"
#include"manager_and_Com_worker.h"
#include"food.h"
#include"Material.h"
using namespace std;
#define WORKER "员工信息.txt"
#define DAKA "普通员工打卡信息.txt"
#define Manager_DAKA "管理员打卡信息.txt"
#define DINGDAN "订单信息.txt"
#define MONEY "营业额.txt"
#define DATE "日期.txt"
#define OPEN "是否营业.txt"

class Function
{
public:
	//构造函数
	Function();

	static int Sile_Num1;//水煮牛肉
	static int Sile_Num2;//猪杂
	static int Sile_Num3;//白切鸡
	static int Sile_Num4;//开水白菜
	static int Sile_Num5;//肉类拼盘

	//进入界面
	void Choice_Lev();

	//管理员打卡功能
	void DaKa_2(string name, string id);

    //普通员工打卡功能
	void DaKa(string name, string id);

	//输入员工信息 
	static void Put_Emp(string name , string id);

	//检测员工文件中是否已经存在该员工
	bool isPersonInFile(string name);

	//查询菜品能否制作
	void If_Make();

	//输入今日订单
	void In_DingDan();

	//查看今日订单信息
	void See_DingDan();

	//管理员入口
	void Password();

	//查看普通员工打卡情况
	void See_DaKa();

	//查看员工是否已经打卡
	bool isPerson1Daka(string name);

	//查看员工是否已经打卡
	bool isPerson2Daka(string name);

	//查看原材料剩余数量
	void Remain();

	//修改原材料数量
	void Change_Material();

	//核实出售数
	bool Check_Sile_Num();

	//查看今日营业额
	void See_Money();

	//结束营业
	void End_Work();

	//判断当天是否结束营业
	bool If_End_Work();

	//查看这个月每天的营业额
	void See_Everyday_Money();

	//进入下一天
	void Next_Day();

	//读日期
	static int Get_Date();

	//日期文件是否存在
	bool StrDate();

	//退出系统
	void ExitSystem();

	//结束程序
	void Finish_All();

	//普通员
	void Nor_Emp();

	//管理员
	void Manager_Emp();

	//析构函数
	~Function();
};

