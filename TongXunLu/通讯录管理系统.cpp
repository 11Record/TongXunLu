#include <iostream>
#include <String>

using namespace std;
#define MAX 1000


//封装函数显示界面 void showMenu()
//在maan函数中调用封装好的函数




//联系人结构体
struct Person
	{
	string m_Name;	//姓名
	string m_Sex;		//性别
	int m_Age;		//年龄
	string m_Phone;	//手机号
	string m_Addr;	//住址
	};



//通讯录结构体
struct Addressbooks
	{
	struct Person personArray[MAX];		//通讯录中保存的联系人数组
	int m_Size;		//通讯录中的人员个数
	};



//添加联系人功能
void addPerson( Addressbooks * abs )
	{
	//判断通讯录是否已满
	if (abs->m_Size == MAX)
		{
		cout << "通讯录已满 不能继续添加" << endl;
		return;
		}
		else
		{
		//开始添加
		
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//性别
		string sex;
		cout << "请输入性别（1男 2女）：" << endl;
		cin >> sex;		
		if (sex == "1" && "2")
		{
			abs->personArray[abs->m_Size].m_Sex = sex;
		}
		else
		{
			cout << "请输入正确的数值！" << endl;
			cout << "请输入性别（1男 2女）：" << endl;
			cin >> sex;
		}
		//年龄
		int age;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		//电话
		string phone;
		cout << "请输入手机号：" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//住址
		string addr;
		cout << "请输入住址：" << endl;
		cin >> addr;
		abs->personArray[abs->m_Size].m_Addr = addr;
		//更新通讯录人数
		abs->m_Size++;
		
		cout << "添加成功！" << endl;
		system("pause");
		}
	}


//显示所有联系人
void showPerson(Addressbooks * abs)
{
	//判断通讯录中的人数是否为0，如果为0，提示通讯录为空
	//如果不为0，显示通讯录中信息
	if (abs->m_Size==0)
	{
		cout << "通讯录中没有联系人！" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "*****" << endl;
			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
			cout << "性别：" << (abs->personArray[i].m_Sex == "1" ? "男" : "女") << "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "电话号：" << abs->personArray[i].m_Phone << "\t";
			cout << "住址：" << abs->personArray[i].m_Addr << "\n";
		}
	}
	system("pause");

}


//检测联系人是否存在，如果存在，则将联系人在数组中的下标存入新数组，最后返回新数组长度，不存在忽略
//参数1 通讯录 参数2 查找的参数

struct isexist{
	int t = 0;
	int arr[MAX];
};
isexist isExist(Addressbooks* abs, string name)
{
	isexist is;
	for (int i = 0; i < abs->m_Size; i++)
	{
		
		if (abs->personArray[i].m_Name == name) 
		{
			is.arr[is.t]=i;
			is.t++;
		}
	}
	return is;
}


//删除联系人
void deletePerson(Addressbooks* abs)
{
	cout << "请选择删除的联系人的姓名：" << endl;
	string name;
	cin >> name;

	isexist a = isExist(abs, name);

	if (a.t!=0)
	{
		//执行删除操作
		for (int i = 0; i < a.t; i++)
		{
			//输出查询结果
			cout << "*****" << endl;
			cout << "编号：" << i << "\t";
			cout << "姓名：" << abs->personArray[a.arr[i]].m_Name << "\t";
			cout << "性别：" << (abs->personArray[a.arr[i]].m_Sex == "1" ? "男" : "女") << "\t";
			cout << "年龄：" << abs->personArray[a.arr[i]].m_Age << "\t";
			cout << "电话号：" << abs->personArray[a.arr[i]].m_Phone << "\t";
			cout << "住址：" << abs->personArray[a.arr[i]].m_Addr << "\n";
			
		}
		cout << "请选择删除的联系人的编号：" << endl;
		int ret;
		cin >> ret;

		if (ret < 0 || ret >= a.t) 
		{
			cout << "无效的编号！" << endl;
		}
		else 
		{
			//通讯录数组前移
			int index = a.arr[ret];
			for (int i = index; i < abs->m_Size - 1; i++)
			{
				abs->personArray[index] = abs->personArray[index + 1];
			}
			//更新通讯录大小
			abs->m_Size--;
			cout << "删除成功" << endl;
		}
		
	}
	else
	{
		cout << "未找到此联系人！" << endl;
	}
	system("pause");
}


//修改联系人
//修改联系人信息界面
void updateMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1、修改姓名    *****" << endl;
	cout << "*****  2、修改性别    *****" << endl;
	cout << "*****  3、修改年龄    *****" << endl;
	cout << "*****  4、修改电话    *****" << endl;
	cout << "*****  5、修改住址    *****" << endl;
	cout << "*****  6、退出修改    *****" << endl;
	cout << "***************************" << endl;
}
void updatePerson(Addressbooks* abs)
{
	cout << "请选择修改的联系人的姓名：" << endl;
	string name;
	cin >> name;

	isexist a = isExist(abs, name);

	if (a.t != 0)
	{
		//执行修改操作
		for (int i = 0; i < a.t; i++)
		{
			//输出查询结果
			cout << "*****" << endl;
			cout << "编号：" << i << "\t";
			cout << "姓名：" << abs->personArray[a.arr[i]].m_Name << "\t";
			cout << "性别：" << (abs->personArray[a.arr[i]].m_Sex == "1" ? "男" : "女") << "\t";
			cout << "年龄：" << abs->personArray[a.arr[i]].m_Age << "\t";
			cout << "电话号：" << abs->personArray[a.arr[i]].m_Phone << "\t";
			cout << "住址：" << abs->personArray[a.arr[i]].m_Addr << "\n";

		}
		cout << "请选择修改的联系人的编号：" << endl;
		int ret;
		cin >> ret;

		if (ret < 0 || ret >= a.t)
		{
			cout << "无效的编号！" << endl;
		}
		else
		{
			bool x = true;
			while (x)
			{

				int select;
				while (true)
				{
					system("cls");	//清屏

					updateMenu();		//调用修改联系人信息界面

					cout << "请输入需要修改的编号：";
					cin >> select;	//让用户输入数值

					if (select >= 1 and select < 7)
					{
						break;
					}
					else
					{
						cout << "请输入正确的数值！" << endl;
					}

					cin.clear();
					cin.ignore();

				}



				switch (select)
				{
				case 1:		//修改联系人姓名
				{
					string newname;
					cout << "修改前的姓名为：" << abs->personArray[a.arr[ret]].m_Name << "\n";
					cout << "请输入修改后的新姓名：", cin >> newname;
					abs->personArray[a.arr[ret]].m_Name = newname;
					cout << "\n修改完成！\n修改后的姓名为：" << abs->personArray[a.arr[ret]].m_Name << "\n";
					system("pause");
				}
					break;
				case 2:		//修改联系人性别
				{
					int newsex;
					cout << "修改前的性别为：" << (abs->personArray[a.arr[ret]].m_Sex == "1" ? "男" : "女") << "\n";
					cout << "请输入修改后的新性别（1为男，2为女）：", cin >> newsex;
					abs->personArray[a.arr[ret]].m_Sex = newsex;
					cout << "\n修改完成！\n修改后的性别为：" << (abs->personArray[a.arr[ret]].m_Sex == "1" ? "男" : "女") << "\n";
					system("pause");
				}
					break;
				case 3:		//修改联系人年龄
				{
					int newage;
					cout << "修改前的年龄为：" << abs->personArray[a.arr[ret]].m_Age << "\n";
					cout << "请输入修改后的新年龄：", cin >> newage;
					abs->personArray[a.arr[ret]].m_Age = newage;
					cout << "\n修改完成！\n修改后的年龄为：" << abs->personArray[a.arr[ret]].m_Age << "\n";
					system("pause");
				}
					break;
				case 4:		//修改联系人电话号
				{
					string newphone;
					cout << "修改前的电话号码为：" << abs->personArray[a.arr[ret]].m_Phone << "\n";
					cout << "请输入修改后的新电话号：", cin >> newphone;
					abs->personArray[a.arr[ret]].m_Phone = newphone;
					cout << "\n修改完成！\n修改后的电话号码为：" << abs->personArray[a.arr[ret]].m_Phone << "\n";
					system("pause");
				}
					break;
				case 5:		//修改联系人住址
				{
					string newaddr;
					cout << "修改前的住址为：" << abs->personArray[a.arr[ret]].m_Addr << "\n";
					cout << "请输入修改后的新住址：", cin >> newaddr;
					abs->personArray[a.arr[ret]].m_Addr = newaddr;
					cout << "\n修改完成！\n修改后的住址为：" << abs->personArray[a.arr[ret]].m_Addr << "\n";
					system("pause");
				}
					break;
				case 6:		//退出修改联系人
					x = false;
					break;
				}
			}

		}
	}
	else
	{
		cout << "未找到此联系人！" << endl;
	}
	system("pause");
}



//查找联系人
void findPerson(Addressbooks* abs)
{
	cout << "请输入您要查找的联系人:" << endl;
	string name;
	cin >> name;

	isexist a = isExist(abs, name);

	if (a.t != 0)
	{
		//输出查询结果
		for (int i = 0; i < a.t; i++)
		{
			cout << "*****" << endl;
			cout << "编号：" << i << "\t";
			cout << "姓名：" << abs->personArray[a.arr[i]].m_Name << "\t";
			cout << "性别：" << (abs->personArray[a.arr[i]].m_Sex == "1" ? "男" : "女") << "\t";
			cout << "年龄：" << abs->personArray[a.arr[i]].m_Age << "\t";
			cout << "电话号：" << abs->personArray[a.arr[i]].m_Phone << "\t";
			cout << "住址：" << abs->personArray[a.arr[i]].m_Addr << "\n";
		}
		cout << "查找成功,一共有" << a.t << "条记录" << endl;
	}
	else
	{
		cout << "未找到此联系人！" << endl;
	}
	system("pause");

}


//清空所有联系人
void cleanPerson(Addressbooks* abs)
{
	int A = 0;
	cout << "确认清空所有联系人吗？（1确认）" << endl;
	cin >> A;
	if (A == 1)
	{
		abs->m_Size = 0;
		cout << "通讯录已清空！" << endl;
		system("pause");
	}
}



//菜单界面 void showMenu()
void showMenu()
	{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  7、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
	}



int main() 
	{

	Addressbooks Abs;		//创建通讯录结构体变量
	Abs.m_Size = 0;			//初始化人员个数


	int select;		//用户输入的值


	while (true) 
	{
		
		while (true) 
		{
			system("cls");	//清屏

			showMenu();		//调用菜单界面

			cout << "请输入编号：";
			cin >> select;	//让用户输入数值

			if (select >= 1 and select <= 7)
			{
				break;
			}
			else 
			{
				cout << "请输入正确的数值！" << endl;
			}

			cin.clear();
			cin.ignore();

		}
		
		

		switch (select)
		{
		case 1:		//添加联系人
			addPerson(&Abs);		//地址传递 修饰实参
			break;
		case 2:		//显示联系人
			showPerson(&Abs);
			break;
		case 3:		//删除联系人
			deletePerson(&Abs);
			break;
		case 4:		//查找联系人
			findPerson(&Abs);
			break;
		case 5:		//修改联系人
			updatePerson(&Abs);
			break;
		case 6:		//清空联系人
			cleanPerson(&Abs);
			break;
		case 7:		//退出通讯录
		{
			int A = 0;
			cout << "确认退出吗？（1确认）" << endl;
			cin >> A;
			if (A == 1)
			{
				cout << "欢迎下次使用" << endl;
				system("pause");
				return 0;
			}
			else {
				cin.clear();
				cin.ignore();
			}

			break;
		}
			
		}
		
	}

	


	
	system("pause");
	return 0;
	}
