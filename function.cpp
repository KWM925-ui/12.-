#include"function.h"

int Function::Sile_Num1 = 0;
int Function::Sile_Num2 = 0;
int Function::Sile_Num3 = 0;
int Function::Sile_Num4 = 0;
int Function::Sile_Num5 = 0;

//构造函数
Function::Function()
{
	ifstream ifs;
	ifs.open(OPEN, ios::in);
	int kk;
	ifs >> kk;
	ifs.close();
	if (kk == 1)
	{
		int choice;
		cout << "是否要开门" << endl;
		cout << "1、是" << endl;
		cout << "2、不开门" << endl;
		cin >> choice;
		if (choice == 1)
		{
			ofstream ofs;
			ofs.open(OPEN, ios::out | ios::trunc);
			if (!ofs.is_open())
			{
				cout << "文件打开失败" << endl;
				return;
			}
			bool a = false;
			ofs << a << endl;
			ofs.close();
		}
		cout << "好的！" << endl;
	}

	if (!StrDate())
	{
		ofstream oooofs;
		oooofs.open(DATE, ios::out);
		if (!oooofs.is_open())
		{
			cout << "文件打开失败！" << endl;
			return ;
		}
		int date = 1;
		oooofs << date << endl;
		oooofs.close();
	}

}

//进入界面
void Function::Choice_Lev()
{
	cout << "******************************" << endl;
	cout << "******请输入您选择的身份******" << endl;
	cout << " *********1、普通员工*********" << endl;
	cout << " *********2、管理员***********" << endl;
	cout << "******************************" << endl;
}

//日期文件是否存在
bool Function::StrDate()
{
	ifstream ifs;
	ifs.open(DATE, ios::in); 
	if (!ifs.is_open())
	{
		ifs.close();
		return false; //不存在
	}
	else
	{
		ifs.close();
		return true; //存在
	}
}

//读日期
int Function::Get_Date()
{
	ifstream ifs; // 创建ifstream对象并打开文件
	ifs.open(DATE, ios::in);
	if (!ifs.is_open())
	{
		return 1; 
	}
	int date;
	ifs >> date; // 读取文件中的整数
	ifs.close(); // 关闭文件

	return date; // 返回读取到的整数
}


//普通员工打卡功能
void Function::DaKa(string name, string id)
{
	if (isPerson1Daka(name))
	{
		ComWorker C1;
		C1.in_Info(name,id);
 	}
	else
	{
		cout << "该员工今日已经打卡了！" << endl;
		cout << "  " << endl;
	}

	// 检查文件中是否已经存在这个人的信息
	if (isPersonInFile(name))
	{
		ofstream ofs;//写文件
		Function::Put_Emp(name, id);
		cout << "成功添加!" << endl; // 输出成功信息
		cout << "  " << endl;
	}
	else
	{
		cout << "该员工已经储存在文件中了！" << endl;
		cout << "  " << endl;
	}
}

bool Function::isPerson1Daka(string name)
{
	string A1 = "1月";
	string A2 = "日打卡成功!";
	string sentence = name + A1 + to_string(Function::Get_Date()) + A2;
	cout << sentence << endl;
	ifstream ifs(DAKA, ios::in);
	if (!ifs)
	{
		return true; //返回true表示没有打卡记录
	}
	string line;
	while (getline(ifs, line))
	{
		if (line == sentence)
		{
			ifs.close();
			return false; // 找到打卡记录，返回false
		}
		//当getline(ifs, line)尝试从文件中读取一行，但已经到达文件末尾（EOF），没有更多的行可以读取时，getline函数会返回false，导致while循环退出。
	}
	ifs.close(); 
	return true; // 没有找到打卡记录，返回true
}

bool Function::isPerson2Daka(string name)
{
	string A1 = "1月";
	string A2 = "日打卡成功!";
	string sentence = name + A1 + to_string(Function::Get_Date()) + A2;

	ifstream ifs;
	ifs.open(Manager_DAKA, ios::in);
	if (!ifs)
	{
		return true; //没有打卡记录，返回false
	}
	string line;
	while (getline(ifs, line))
	{
		if (line == sentence)
		{
			ifs.close();
			return false; // 找到打卡记录，返回false
		}
	}
	ifs.close();
	return true; // 没有找到打卡记录，返回true
}

bool Function::isPersonInFile(string name)
{
	ifstream ifs;
	ifs.open(WORKER, ios::in);
	string line;

	// 逐行读取文件内容，直到找到一样的
	while (getline(ifs, line))
	{
		if (line == name)
		{
			ifs.close();
			return false;
		}
	}
	ifs.close(); // 关闭文件
	return true; // 没有找到这个人的信息，返回true
}


//输入员工信息 
void Function::Put_Emp(string name , string id)
{
	ofstream ofs;//写文件
	ofs.open(WORKER, ios::out | ios::app); //（文件名，打开方式）  以输出的方式打开文件--写文件

	ofs << name << endl
		<< id << endl;

	//关闭文件
	ofs.close();
}

//管理员打卡功能
void Function::DaKa_2(string name, string id)
{
	if (isPerson2Daka(name))
	{
		Manager M1;
		M1.in_Info(name,id);
	}
	else
	{
		cout << "该管理员今日已经打过卡了！" << endl;
		cout << "  " << endl;
	}

		// 检查文件中是否已经存在这个人的信息
		if (isPersonInFile(name))
		{
			Function::Put_Emp(name, id);
			cout << "成功添加" << endl; // 输出成功信息
			cout << "  " << endl;
		}
		else
		{
			cout << "该员工已经储存在文件中了！" << endl; // 输出已存在信息
			cout << "  " << endl;
		}
}


//查询菜品能否制作
void Function::If_Make()
{
	int choice;
	cout << "请输入想查看的菜名编号：" << endl;
	cout << "1、水煮牛肉" << endl;
	cout << "2、猪杂" << endl;
	cout << "3、白切鸡" << endl;
	cout << "4、开水白菜" << endl;
	cout << "5、肉类拼盘" << endl;
	
	while (true)
	{
        cin >> choice;
		if (choice>=1 && choice<=5)
		{
			break;
		}
		cout << "编号输入有误，请重新输入！" << endl;
	}
	//=====================================================
	WaterBeef B1;
	if (choice == 1)
	{
		if (B1.IFMake())
		{
			cout << "水煮牛肉可以制作!" << endl;
			cout << " " << endl;
			cout << "需要做一份吗！" << endl;
			cout << "1、做一份" << endl;
			cout << "2、不用" << endl;
			int If_Want = 0;
			cin >> If_Want;
			if (If_Want == 1)
			{
				B1.If_Do_Want();
				//刷新水煮牛肉出售量
				WaterBeef::count1();
			}
			if (If_Want == 2)
			{
				cout << "好的！" << endl;
			}
			B1.Save_Material();//刷新原材料实时数据
		}
		else
		{
			cout << "水煮牛肉无法制作！" << endl;
		}
		
	}
	//===================================================
	Pig_Za Z1;
	if (choice == 2)
	{
		if (Z1.IFMake())//做客一份猪杂
		{
			cout << "猪杂可以制作!" << endl;
			cout << " " << endl;
			cout << "需要做一份吗！" << endl;
			cout << "1、做一份" << endl;
			cout << "2、不用" << endl;
			int If_Want = 0;
			cin >> If_Want;
			if (If_Want == 1)
			{
				Z1.If_Do_Want();
				cout<<Pig_Za::Getcount2() << endl;
				//刷新猪杂出售量
				Pig_Za::count2();
			}
			if (If_Want == 2)
			{
				cout << "好的！" << endl;
			}
			Z1.Save_Material();//刷新原材料实时数据
		}
		else
		{
			cout << "猪杂无法制作！" << endl;
		}
	}
	//=====================================================
	Whie_zhiyin J1;
	if (choice == 3)
	{
		if (J1.IFMake())//做了一份白切鸡
		{
			cout << "白切鸡可以制作!" << endl;
			cout << " " << endl;
			cout << "需要做一份吗！" << endl;
			cout << "1、做一份" << endl;
			cout << "2、不用" << endl;
			int If_Want = 0;
			cin >> If_Want;
			if (If_Want == 1)
			{
				J1.If_Do_Want();
				//刷新白切鸡出售量
				Whie_zhiyin::count3();
			}
			if (If_Want == 2)
			{
				cout << "好的！" << endl;
			}
			J1.Save_Material();//刷新原材料实时数据
		}
		else
		{
			cout << "白切鸡无法制作！" << endl;
		}
	}
	//======================================================
	BaiCai Cai_1;
	if (choice == 4)
	{
		if (Cai_1.IFMake())//做了一份开水白菜
		{
			cout<< "开水白菜可以制作!" << endl;
			cout << " " << endl;
			cout << "需要做一份吗！" << endl;
			cout << "1、做一份" << endl;
			cout << "2、不用" << endl;
			int If_Want = 0;
			cin >> If_Want;
			if (If_Want == 1)
			{
				Cai_1.If_Do_Want();
				//刷新水煮白菜出售量
				BaiCai::count4();
			}
			if (If_Want == 2)
			{
				cout << "好的！" << endl;
			}
			Cai_1.Save_Material();//刷新原材料实时数据
		}
		else
		{
			cout << "开水白菜无法制作！" << endl;
		}
	}

	DifrMeat D1;
	if (choice == 5)
	{
		if (D1.IFMake())//做了一份肉类拼盘
		{
			cout << "肉类拼盘可以制作!" << endl;
			cout << " " << endl;
			cout << "需要做一份吗！" << endl;
			cout << "1、做一份" << endl;
			cout << "2、不用" << endl;
			int If_Want = 0;
			cin >> If_Want;
			if (If_Want == 1)
			{
				D1.If_Do_Want();
				//刷新肉类拼盘出售量
				DifrMeat::count5();
			}
			if (If_Want == 2)
			{
				cout << "好的！" << endl;
			}
			D1.Save_Material();//刷新原材料实时数据
		}
		else
		{
			cout << "肉类拼盘无法制作！" << endl;
		}
	}
}


//输入今日订单
void Function::In_DingDan()
{
	ofstream ofs;//写文件
	ofs.open(DINGDAN, ios::out|ios::trunc); //（文件名，打开方式）  以输出的方式打开文件--写文件
	if (!ofs.is_open())
	{
		return;
	}
	//录入订单信息,一共五行
	ofs << "水煮牛肉1月" << Get_Date() << "日卖出" <<  WaterBeef::Getcount1()   << "份" << endl;
	ofs << "猪杂1月"     << Get_Date() << "日卖出" <<     Pig_Za::Getcount2()    << "份" << endl;
	ofs << "白切鸡1月"   << Get_Date() << "日卖出" << Whie_zhiyin::Getcount3()  << "份" << endl;
	ofs << "开水白菜1月" << Get_Date() << "日卖出" <<      BaiCai::Getcount4()  << "份" << endl;
	ofs << "肉类拼盘1月" << Get_Date() << "日卖出" <<   DifrMeat::Getcount5()   << "份" << endl;

	//关闭文件
	ofs.close();
	cout << "订单录入成功！" << endl;
}

//查看今日订单信息
void Function::See_DingDan()
{
	ifstream ifs;
	ifs.open(DINGDAN, ios::in);//打开文件---读文件
	if (!ifs.is_open()) 
	{
		cout << "还没有订单信息！" << endl;
		return;
	}

	string line;
	// 读取并打印文件的每一行
	while (getline(ifs, line)) {
		cout << line << endl;
	}
	//关闭文件
	ifs.close();
}


//查看普通员工打卡情况
void Function::See_DaKa()
{
	//查看员工打卡情况（不包括管理员）-------------------------------------------------7

	ifstream ifs;
	ifs.open(DAKA, ios::in);//打开文件---读文件
	if (!ifs.is_open()) {
		cout << "无法打开文件" << endl;
		return;
	}

	string buf;
	while (getline(ifs, buf))
	{
		cout << buf << endl;
	}

	//关闭文件
	ifs.close();
}


//查看原材料剩余数量
void Function::Remain()
{
	//查看原材料剩余数量
	ifstream ifs;
	ifs.open(MATERIAL, ios::in);//打开文件---读文件
	if (!ifs.is_open()) {
		cerr << "无法打开文件" << endl;
		return;
	}

	string buf;
	while (getline(ifs, buf))
	{
		cout << buf << endl;
	}

	//关闭文件
	ifs.close();
}


//修改原材料数量
void Function::Change_Material()
{
	//修改原材料剩余数量
	int NUM1;//鸡肉
	int NUM2;//牛肉
	int NUM3;//猪肉
	int NUM4;//蔬菜
	cout << "请修改要修改的原材料：" << endl;
	cout << "鸡肉改为多少份：" << endl;
	cin >> NUM1;
	cout << "牛肉改为多少份：" << endl;
	cin >> NUM2;
	cout << "猪肉改为多少份：" << endl;
	cin >> NUM3;
	cout << "蔬菜改为多少份：" << endl;
	cin >> NUM4;

	ofstream ofs;//写文件
	ofs.open(MATERIAL, ios::out | ios::trunc);
	if (!ofs.is_open())
	{
		cout << "原材料文件打开失败" << endl;
		return;
	}
	ofs << "鸡肉还剩" << NUM1 << "份" << endl;
	ofs << "牛肉还剩" << NUM2 << "份" << endl;
	ofs << "猪肉还剩" << NUM3 << "份" << endl;
	ofs << "蔬菜还剩" << NUM4 << "份" << endl;

	//关闭文件
	ofs.close();
	//=======================================

	ofs.open(mater_ji, ios::out | ios::trunc);
	if (!ofs.is_open())
	{
		cout << "原材料文件打开失败" << endl;
		return;
	}
	ofs <<NUM1<<endl;

	//关闭文件
	ofs.close();
	//=======================================
	
	ofs.open(mater_niu, ios::out | ios::trunc);
	if (!ofs.is_open())
	{
		cout << "原材料文件打开失败" << endl;
		return;
	}
	ofs << NUM2 << endl;

	//关闭文件
	ofs.close();
	//=======================================

	ofs.open(mater_zhu, ios::out | ios::trunc);
	if (!ofs.is_open())
	{
		cout << "原材料文件打开失败" << endl;
		return;
	}
	ofs << NUM3 << endl;

	//关闭文件
	ofs.close();
	//========================================

	ofs.open(mater_cai, ios::out | ios::trunc);
	if (!ofs.is_open())
	{
		cout << "原材料文件打开失败" << endl;
		return;
	}
	ofs << NUM4 << endl;

	//关闭文件
	ofs.close();
}


//结束营业
//结束营业后员工就只能核实菜品了
//管理员可以查看营业额
void Function::End_Work()
{
	int If_End;
	cout << "确认要关门吗" << endl;
	cout << "1、确定关门！" << endl;
	cout << "2、不关门!" << endl;
	while (true)
	{
		cin >> If_End;
		if (If_End != 1 && 2)
		{
			cout << "输入有误，重新输入！" << endl;
		}
		break;
	}
	if (If_End == 1)
	{
		ofstream ofs;
		ofs.open(OPEN, ios::out | ios::trunc);
		if (!ofs)
		{
			return;
		}
		ofs << 1 << endl;
	}
	else if(If_End == 2)
	{
		return;
	}
}


bool Function::If_End_Work()
{
	ifstream ifs(OPEN,ios::in); 
	if (!ifs.is_open()) 
	{
		return false; 
	}

	int value;
	ifs >> value; 

	// 确保读取的值是0或1，如果不是，则返回false
	if (ifs.fail() || value != 1) 
	{
		return false;
	}
	//如果是1就是true，也就是如果上面选择的是确认关门
	return true; 
}


//核实出售数（结束营业后才可使用）
bool Function::Check_Sile_Num()
{
	int textNum = 0;

	cout << "请输入今日各菜品所有的出售数" << endl;
	while (true)
	{
		cout << "水煮牛肉售出了多少份：" << endl;
		cin >> Function::Sile_Num1;

		if (Function::Sile_Num1 == WaterBeef::Getcount1())
		{
			cout << "核实正确！" << endl;
			textNum++;
			break;
		}
			cout << "核实有误，请重新输入！" << endl;
	}

	while (true)
	{
		cout << "猪杂售出了多少份：" << endl;
		cin >> Function::Sile_Num2;

		if (Function::Sile_Num2 == Pig_Za::Getcount2())
		{
			cout << "核实正确！" << endl;
			textNum++;
			break;
		}
		cout << "核实有误，请重新输入！" << endl;
	}

	while (true)
	{
		cout << "白切鸡售出了多少份：" << endl;
		cin >> Function::Sile_Num3;

		if (Function::Sile_Num3 == Whie_zhiyin::Getcount3())
		{
			cout << "核实正确！" << endl;
			textNum++;
			break;
		}
		cout << "核实有误，请重新输入！" << endl;
	}

	while (true)
	{
		cout << "开水白菜售出了多少份：" << endl;
		cin >> Function::Sile_Num4;
		if (Function::Sile_Num4 == BaiCai::Getcount4())
		{
			cout << "核实正确！" << endl;
			textNum++;
			break;
		}
			cout << "核实有误，请重新输入！" << endl;
	}

	while (true)
	{
		cout << "肉类拼盘售出了多少份：" << endl;
		cin >> Function::Sile_Num5;

		if (Function::Sile_Num5 == DifrMeat::Getcount5())
		{
			cout << "核实正确！" << endl;
			textNum++;
			break;
		}
			cout << "核实有误，请重新输入！" << endl;
	}

	if (textNum == 5)
			{
				cout << "所有都核实正确！" << endl;
				return true;
			}
}


//查看今日营业额，并且存进文件（先结束营业，然后核实正确就可以调用）
void Function::See_Money()
{
	int Total;
	Total = WaterBeef::Getcount1() * 80 + Pig_Za::Getcount2() * 30 + Whie_zhiyin::Getcount3() + BaiCai::Getcount4() + DifrMeat::Getcount5();
	cout << "1月" << Get_Date() << "日的营业额为："<<Total<<"元" << endl;

	ofstream ofs;//写文件
	ofs.open(MONEY, ios::out|ios::app);
	if (!ofs.is_open()) 
	{
		cout << "无法打开文件MONEY进行写入" << endl;
		return;
	}
	ofs << "1月" << Get_Date() << "日的营业额为：" << Total <<"元" << endl;

	//关闭文件
	ofs.close();
	cout << "营业额已记录到文件MONEY" << endl;
}

//查看这个月每天的营业额
void Function::See_Everyday_Money()
{
	ifstream ifs;//读文件
	ifs.open(MONEY, ios::in);
	if (!ifs.is_open())
	{
		return;
	}

	string buf;
	while (getline(ifs, buf))
	{
		cout << buf << endl;
	}

	//关闭文件
	ifs.close();
}


//进入下一天
void Function::Next_Day()
{
	int If_Nextday;
	cout << "确认要进入下一天吗" << endl;
	cout << "1、确定！" << endl;
	cout << "2、不!" << endl;
	while (true)
	{
	cin >> If_Nextday;
		if ( If_Nextday>=1 && If_Nextday<=2 )
		{
			break;
		}
		cout << "输入有误，重新输入！" << endl;
	}
	if (If_Nextday == 1)
	{
		int newDate = Get_Date();//将字符串转换为整数
		newDate++;//日期加一进入下一天
		ofstream ofs;
		ofs.open(DATE, ios::out | ios::trunc);
		if (!ofs.is_open()) 
		{
			cerr << "无法打开文件" << endl;
			return;
		}

		ofs << newDate << endl;
		ofs.close();
		ofs.open(cai1, ios::trunc);
		ofs.close();
		ofs.open(cai2, ios::trunc);
		ofs.close();
		ofs.open(cai3, ios::trunc);
		ofs.close();
		ofs.open(cai4, ios::trunc);
		ofs.close();
		ofs.open(cai5, ios::trunc);
		ofs.close();
		cout << "成功进入下一天！" << endl;
		ExitSystem();
	}
	if (If_Nextday == 2)
	{
		cout << "好的，祝生意兴隆！" << endl;
		return;
	}

}


//退出系统
void Function::ExitSystem()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);//退出函数
}


//结束程序
//所有数据清零
void Function::Finish_All()
{
	ofstream ofs;

	// 打开并清空文件
	ofs.open(WORKER, ios::trunc);
	ofs.close();

	ofs.open(DAKA, ios::trunc);
	ofs.close();

	ofs.open(Manager_DAKA, ios::trunc);
	ofs.close();

	ofs.open(DINGDAN, ios::trunc);
	ofs.close();

	ofs.open(MONEY, ios::trunc);
	ofs.close();

	ofs.open(DATE, ios::trunc);
	ofs.close();

	ofs.open(OPEN, ios::trunc);
	ofs.close();

	ofs.open(MATERIAL, ios::trunc);
	ofs.close();

	ofs.open(cai1, ios::trunc);
	ofs.close();

	ofs.open(cai2, ios::trunc);
	ofs.close();

	ofs.open(cai3, ios::trunc);
	ofs.close();

	ofs.open(cai4, ios::trunc);
	ofs.close();

	ofs.open(cai5, ios::trunc);
	ofs.close();
}


//普通员工
void Function::Nor_Emp()
{
	//打卡
	string name;
	string id;
	cout << "请输入你的姓名：" << endl;
	cin >> name;
	cout << "请输入你的工号：" << endl;
	cin >> id;
	DaKa(name, id);

	int Which;

	while (true)
	{
		cout << "您想使用哪个功能：" << endl;
		cout << "1、查看菜品是否能制作" << endl;
		cout << "2、输入订单" << endl;
		cout << "3、查看今日订单" << endl;
		cout << "4、核实订单" << endl;
		cout << "5、退出系统" << endl;
		cout << "请输入你的选择：" << endl;

		while (true)
		{
			cin >> Which;
			if (Which >= 1 && Which <= 5)
			{
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
		}

		switch (Which)
		{

		case 1://查看菜品是否能制作
		{
			if (!If_End_Work())
			{
				If_Make();
			}
			else
			{
			cout << "今天已经关门了，无法操作！" << endl;
			}
		}
			break;

		case 2://输入订单
		{
			if (!If_End_Work())
			{
				In_DingDan();
			}
			else
			{
				cout << "今天已经关门了，无法操作！" << endl;
			}
		}
		break;

		case 3://查看今日订单
		{
			if (!If_End_Work())
			{
				See_DingDan();
			}
			else
			{
				cout << "今天已经关门了，无法操作！" << endl;
			}
		}
		break;

		case 4://核实订单
		{
			if (If_End_Work())
			{
				Check_Sile_Num();
			}
			else
			{
			cout << "还没结束营业，无法核实订单！" << endl;
			}

		}
		break;

		case 5://退出系统
			ExitSystem();
			break;
		}
		system("pause");
		system("cls");
	}
}



//管理员
void Function::Password()
{
	int password = 0;
	cout << "请管理员输入密码" << endl;
	
	while (true)
	{
        cin >> password;
		if (password == 1111)
		{
			cout << "密码正确！" << endl;
			break;
		}
		cout << "输入错误，请重新输入！" << endl;
	}
}



//========================================================================================
//管理员功能区
void Function::Manager_Emp()
{
	Password();
	int Which;
	
		cout << "************欢迎管理员！************" << endl;
		//打卡
		string name;
		string id;
		cout << "请输入你的姓名：" << endl;
		cin >> name;
		cout << "请输入你的工号：" << endl;
		cin >> id;
		DaKa_2(name, id);
	while (true)
	{
		cout << "您想使用哪个功能：" << endl;
		cout << "1、查看菜品是否能制作" << endl;
		cout << "2、输入订单" << endl;
		cout << "3、查看今日订单" << endl;
		cout << "4、核实订单" << endl;
		cout << "5、查看普通员工的打卡情况" << endl;
		cout << "6、查看原材料剩余数量" << endl;
		cout << "7、修改原材料剩余数量" << endl;
		cout << "8、结束营业" << endl;
		cout << "9、查看今日营业额" << endl;
		cout << "10、查看这个月每天的营业额" << endl;
		cout << "11、进入下一天" << endl;
		cout << "12、退出系统" << endl;
		cout << "13、结束程序" << endl;
		while (true)
		{
			cin >> Which;
			if (Which >= 1 && Which <= 13)
			{
				break;
			}
			else
			{
			cout << "输入有误，请重新输入！" << endl;
			}
		}

		switch (Which)
		{
		case 1://查看菜品是否能制作
		{
			if (!If_End_Work())
			{
				If_Make();
			}
			else
			{
				cout << "今天已经关门了，无法操作！" << endl;
			}
		}
		break;

		case 2://输入订单
		{
			if (!If_End_Work())
			{
				In_DingDan();
			}
			else
			{
				cout << "今天已经关门了，无法操作！" << endl;
			}
		}
		break;

		case 3://查看今日订单
		{
			if (!If_End_Work())
			{
				See_DingDan();
			}
			else
			{
				cout << "今天已经关门了，无法操作！" << endl;
			}
		}
		break;

		case 4://核实订单
		{
			if (If_End_Work())
			{
				Check_Sile_Num();
			}
			else
			{
			cout << "还没结束营业，无法核实订单！" << endl;
			}

		}
		break;

		case 5://查看普通员工的打卡情况
				See_DaKa();
		break;

		case 6://查看原材料剩余数量
				Remain();
		break;

		case 7://修改原材料剩余数量
				Change_Material();
		break;

		case 8://结束营业
			End_Work();
			break;

		case 9://查看今日营业额
			//（结束营业并且员工输入今日各菜品所有出售数后才可使用）
		{
			if (If_End_Work() || Check_Sile_Num())
			{
				See_Money();
			}
			else
			{
			cout << "还没结束营业，无法查看！" << endl;
			}
		}
		break;

		case 10://查看这个月每天的营业额
			See_Everyday_Money();
			break;

		case 11://进入下一天
			Next_Day();
			break;

		case 12://退出系统
			ExitSystem();
			break;

		case 13://结束程序
			Finish_All();
			break;
		}
		system("pause");
		system("cls");
	}
}
Function::~Function()
{ }