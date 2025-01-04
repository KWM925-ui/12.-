#include"Material.h"

int AllMater::Having_Ji()
{
	ifstream ifs;
	ifs.open(mater_ji, ios::in);
	if (!ifs)
	{
		ofstream ofs;
		ofs.open(mater_ji, ios::out);
		ofs << 50 << endl;
		return 50;
	}
	int num = 0;
	ifs >> num;
	ifs.close();
	return num;
}

int AllMater::Having_Niu()
{
	ifstream ifs;
	ifs.open(mater_niu, ios::in);
	if (!ifs)
	{
		ofstream ofs;
		ofs.open(mater_niu, ios::out);
		ofs << 50 << endl;
		return 50;
	}
	int num = 0;
	ifs >> num;
	ifs.close();
	return num;
}

int AllMater::Having_Zhu()
{
	ifstream ifs;
	ifs.open(mater_zhu, ios::in);
	if (!ifs)
	{
		ofstream ofs;
		ofs.open(mater_zhu, ios::out);
		ofs << 50 << endl;
		return 50;
	}
	int num = 0;
	ifs >> num;
	ifs.close();
	return num;
}

int AllMater::Having_Cai()
{
	ifstream ifs;
	ifs.open(mater_cai, ios::in);
	if (!ifs)
	{
		ofstream ofs;
		ofs.open(mater_cai, ios::out);
		ofs << 50 << endl;
		return 50;
	}
	int num = 0;
	ifs >> num;
	ifs.close();
	return num;
}