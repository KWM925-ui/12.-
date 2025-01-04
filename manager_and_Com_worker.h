#pragma once
#include <iostream>
#include "string"
#include "worker.h"
using namespace std;


class Manager :public Worker
{
public:

	//录入信息
	virtual void in_Info(string name ,string id);
};

class ComWorker :public Worker
{
public:

	//录入信息
	virtual void in_Info(string name, string id);
};