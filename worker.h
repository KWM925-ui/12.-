#pragma once
#include <iostream>
#include <string>
using namespace std;
//因为这个抽象类只是为子类多态提供的，不需要实例化或者做什么实现，不需要cpp文件

//职工抽象基类
class Worker
{
public:

	//录入个人信息
	virtual void in_Info(string name , string id) = 0;

};