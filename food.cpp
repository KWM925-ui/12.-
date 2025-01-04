#include"food.h"

int WaterBeef::W1 = WaterBeef::Getcount1();
int Pig_Za::P1 = Pig_Za::Getcount2();
int Whie_zhiyin::J1 = Whie_zhiyin::Getcount3();
int BaiCai::Cai1 = BaiCai::Getcount4();
int DifrMeat::D1 = DifrMeat::Getcount5();

Food::Food()
{}
//保存原材料数据
void Food::Save_Material()
{
    ofstream ofs;//写文件
    ofs.open(MATERIAL, ios::out | ios::trunc);
    if (!ofs)
    {
        cout << "原材料文件打开失败" << endl;
        return;
    }
    ofs << "鸡肉还剩" << AllMater::Having_Ji() << "份" << endl
        << "牛肉还剩" << AllMater::Having_Niu() << "份" << endl
        << "猪肉还剩" << AllMater::Having_Zhu() << "份" << endl
        << "蔬菜还剩" << AllMater::Having_Cai() << "份" << endl;

    //关闭文件
    ofs.close();
}
Food::~Food()
{}

//=============================================

WaterBeef::WaterBeef()
{}
WaterBeef::~WaterBeef()
{}

// 判断水煮牛肉能不能制作
bool WaterBeef::IFMake()
{
    if (AllMater::Having_Niu() >= 4 && AllMater::Having_Cai() >= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//询问是否需要制作一份
void WaterBeef::If_Do_Want()
{
    WaterBeef::W1++;

    int B, D;

    ifstream ifs;
    ifs.open(mater_niu, ios::in);
    ifs >> B;
    ifs.close();
    B = B - 4;
    ofstream ofs;
    ofs.open(mater_niu, ios::out | ios::trunc);
    ofs << B;
    ofs.close();

    ifs.open(mater_cai, ios::in);
    ifs >> D;
    ifs.close();
    D = D - 1;

    ofs.open(mater_cai, ios::out | ios::trunc);
    ofs << D;
    ofs.close();
}

void WaterBeef::count1()
{
    ofstream ofs;
    ofs.open(cai1, ios::out | ios::trunc);
    if (!ofs)
    {
        return;
    }
    ofs << WaterBeef::W1 << endl;
    ofs.close();
}

int WaterBeef::Getcount1()
{
    int num = 0;
    ifstream ifs;
    ifs.open(cai1, ios::in);
    if (!ifs)
    {
        return 0;
    }
    ifs >> num;
    ifs.close();
    return num;
}


//================================================
Pig_Za::Pig_Za()
{}
Pig_Za::~Pig_Za()
{}

// 判断猪杂能不能制作，能就制作一份
bool Pig_Za::IFMake()
{
    if (AllMater::Having_Zhu() >= 2)
    {

        return true;
    }
    else
    {
        return false;
    }
}

//询问是否需要制作一份
void Pig_Za::If_Do_Want()
{
    Pig_Za::count2();
    Pig_Za::P1 = Pig_Za::Getcount2();
    Pig_Za::P1++;

    int C;
    ifstream ifs;
    ifs.open(mater_zhu, ios::in);
    ifs >> C;
    ifs.close();
    C = C - 2;
    ofstream ofs;
    ofs.open(mater_zhu, ios::out | ios::trunc);
    ofs << C;
    ofs.close();
}

void Pig_Za::count2()
{
    ofstream ofs;
    ofs.open(cai2, ios::out | ios::trunc);
    if (!ofs)
    {
        return;
    }
    ofs << Pig_Za::P1 << endl;
    ofs.close();
}

int Pig_Za::Getcount2()
{
    int num = 0;
    ifstream ifs;
    ifs.open(cai2, ios::in);
    if (!ifs)
    {
        return 0;
    }
    ifs >> num;
    ifs.close();
    return num;
}
//=============================================

Whie_zhiyin::Whie_zhiyin()
{}
Whie_zhiyin::~Whie_zhiyin()
{}

// 判断白切鸡能不能制作，能就制作一份
bool Whie_zhiyin::IFMake()
{
    if (AllMater::Having_Ji() >= 3)
    {
        return true;
    }
    else
    {
        return false;
    }
}


//询问是否需要制作一份
void Whie_zhiyin::If_Do_Want()
{
    Whie_zhiyin::count3();
    Whie_zhiyin::J1 = Whie_zhiyin::Getcount3();
    Whie_zhiyin::J1++;

    int A;
    ifstream ifs;
    ifs.open(mater_ji, ios::in);
    ifs >> A;
    ifs.close();
    A = A - 3;
    ofstream ofs;
    ofs.open(mater_ji, ios::out | ios::trunc);
    ofs << A;
    ofs.close();
}

void Whie_zhiyin::count3()
{
    ofstream ofs;
    ofs.open(cai3, ios::out | ios::trunc);
    if (!ofs)
    {
        return;
    }
    ofs << Whie_zhiyin::J1 << endl;
    ofs.close();
}

int Whie_zhiyin::Getcount3()
{
    int num = 0;
    ifstream ifs;
    ifs.open(cai3, ios::in);
    if (!ifs)
    {
        return 0;
    }
    ifs >> num;
    ifs.close();
    return num;
}

//=============================================

BaiCai::BaiCai()
{}
BaiCai::~BaiCai()
{}

// 判断开水白菜能不能制作，能就制作一份
bool BaiCai::IFMake()
{
    if (AllMater::Having_Cai() >= 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//询问是否需要制作一份
void BaiCai::If_Do_Want()
{
    BaiCai::count4();
    BaiCai::Cai1 = BaiCai::Getcount4();
    BaiCai::Cai1++;

    int D;
    ifstream ifs;
    ifs.open(mater_cai, ios::in);
    ifs >> D;
    ifs.close();
    D = D - 2;
    ofstream ofs;
    ofs.open(mater_cai, ios::out | ios::trunc);
    ofs << D;
    ofs.close();
}

void BaiCai::count4()
{
    ofstream ofs;
    ofs.open(cai4, ios::out | ios::trunc);
    if (!ofs)
    {
        return;
    }
    ofs << BaiCai::Cai1 << endl;
    ofs.close();
}

int BaiCai::Getcount4()
{
    int num = 0;
    ifstream ifs;
    ifs.open(cai4, ios::in);
    if (!ifs)
    {
        return 0;
    }
    ifs >> num;
    ifs.close();
    return num;
}

//=============================================

DifrMeat::DifrMeat()
{}
DifrMeat::~DifrMeat()
{}

// 判断肉类拼盘能不能制作，能就制作一份
bool DifrMeat::IFMake()
{
    if (AllMater::Having_Ji() >= 2 && AllMater::Having_Niu() >= 3 && AllMater::Having_Zhu() >= 2 && AllMater::Having_Cai() >= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//询问是否需要制作一份
void DifrMeat::If_Do_Want()
{
    DifrMeat::count5();
    DifrMeat::D1 = DifrMeat::Getcount5();
    DifrMeat::D1++;

    int A, B, C, D;

    ifstream ifs;
    ifs.open(mater_niu, ios::in);
    ifs >> B;
    ifs.close();
    B = B - 3;
    ofstream ofs;
    ofs.open(mater_niu, ios::out | ios::trunc);
    ofs << B;
    ofs.close();


    ifs.open(mater_cai, ios::in);
    ifs >> D;
    ifs.close();
    D = D - 1;

    ofs.open(mater_cai, ios::out | ios::trunc);
    ofs << D;
    ofs.close();


    ifs.open(mater_ji, ios::in);
    ifs >> A;
    ifs.close();
    A = A - 2;

    ofs.open(mater_ji, ios::out | ios::trunc);
    ofs << A;
    ofs.close();


    ifs.open(mater_zhu, ios::in);
    ifs >> C;
    ifs.close();
    C = C - 2;

    ofs.open(mater_zhu, ios::out | ios::trunc);
    ofs << C;
    ofs.close();
}

//更新拼盘出售量
void DifrMeat::count5()
{
    ofstream ofs;
    ofs.open(cai5, ios::out | ios::trunc);
    if (!ofs)
    {
        return;
    }
    ofs << DifrMeat::D1 << endl;
    ofs.close();
}

int  DifrMeat::Getcount5()
{
    int num = 0;
    ifstream ifs;
    ifs.open(cai5, ios::in);
    if (!ifs)
    {
        return 0;
    }
    ifs >> num;
    ifs.close();
    return num;
}