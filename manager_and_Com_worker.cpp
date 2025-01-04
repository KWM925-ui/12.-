#include"manager_and_Com_worker.h"
#include"function.h"


 void Manager::in_Info(string name, string id)
{
	 ofstream ofs;//写文件
	 ofs.open(Manager_DAKA, ios::out | ios::app); //（文件名，打开方式）  以输出的方式打开文件--写文件
	 if (!ofs.is_open())
	 {
		 return;
	 }
	 //将每一个人打卡的数据写到文件当中
	 ofs << name << "1月" << to_string(Function::Get_Date()) << "日打卡成功!" << endl;;
	 //关闭文件
	 ofs.close();
	 cout << "管理员打卡成功!" << endl;
	 cout << "  " << endl;
}

 void ComWorker::in_Info(string name, string id)
 {
	 ofstream ofs;//写文件
	 ofs.open(DAKA, ios::out | ios::app); //（文件名，打开方式）  以输出的方式打开文件--写文件

	 //将每一个人打卡的数据写到文件当中
	 ofs << name << "1月" << to_string(Function::Get_Date()) << "日打卡成功!" << endl;
	 //关闭文件
	 ofs.close();
	 cout << "普通员工打卡成功!" << endl;
	 cout << "  " << endl;
 }
