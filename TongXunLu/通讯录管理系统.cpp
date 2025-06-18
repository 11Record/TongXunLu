#include <iostream>
#include <String>

using namespace std;
#define MAX 1000


//��װ������ʾ���� void showMenu()
//��maan�����е��÷�װ�õĺ���




//��ϵ�˽ṹ��
struct Person
	{
	string m_Name;	//����
	string m_Sex;		//�Ա�
	int m_Age;		//����
	string m_Phone;	//�ֻ���
	string m_Addr;	//סַ
	};



//ͨѶ¼�ṹ��
struct Addressbooks
	{
	struct Person personArray[MAX];		//ͨѶ¼�б������ϵ������
	int m_Size;		//ͨѶ¼�е���Ա����
	};



//�����ϵ�˹���
void addPerson( Addressbooks * abs )
	{
	//�ж�ͨѶ¼�Ƿ�����
	if (abs->m_Size == MAX)
		{
		cout << "ͨѶ¼���� ���ܼ������" << endl;
		return;
		}
		else
		{
		//��ʼ���
		
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//�Ա�
		string sex;
		cout << "�������Ա�1�� 2Ů����" << endl;
		cin >> sex;		
		if (sex == "1" && "2")
		{
			abs->personArray[abs->m_Size].m_Sex = sex;
		}
		else
		{
			cout << "��������ȷ����ֵ��" << endl;
			cout << "�������Ա�1�� 2Ů����" << endl;
			cin >> sex;
		}
		//����
		int age;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		//�绰
		string phone;
		cout << "�������ֻ��ţ�" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//סַ
		string addr;
		cout << "������סַ��" << endl;
		cin >> addr;
		abs->personArray[abs->m_Size].m_Addr = addr;
		//����ͨѶ¼����
		abs->m_Size++;
		
		cout << "��ӳɹ���" << endl;
		system("pause");
		}
	}


//��ʾ������ϵ��
void showPerson(Addressbooks * abs)
{
	//�ж�ͨѶ¼�е������Ƿ�Ϊ0�����Ϊ0����ʾͨѶ¼Ϊ��
	//�����Ϊ0����ʾͨѶ¼����Ϣ
	if (abs->m_Size==0)
	{
		cout << "ͨѶ¼��û����ϵ�ˣ�" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "*****" << endl;
			cout << "������" << abs->personArray[i].m_Name << "\t";
			cout << "�Ա�" << (abs->personArray[i].m_Sex == "1" ? "��" : "Ů") << "\t";
			cout << "���䣺" << abs->personArray[i].m_Age << "\t";
			cout << "�绰�ţ�" << abs->personArray[i].m_Phone << "\t";
			cout << "סַ��" << abs->personArray[i].m_Addr << "\n";
		}
	}
	system("pause");

}


//�����ϵ���Ƿ���ڣ�������ڣ�����ϵ���������е��±���������飬��󷵻������鳤�ȣ������ں���
//����1 ͨѶ¼ ����2 ���ҵĲ���

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


//ɾ����ϵ��
void deletePerson(Addressbooks* abs)
{
	cout << "��ѡ��ɾ������ϵ�˵�������" << endl;
	string name;
	cin >> name;

	isexist a = isExist(abs, name);

	if (a.t!=0)
	{
		//ִ��ɾ������
		for (int i = 0; i < a.t; i++)
		{
			//�����ѯ���
			cout << "*****" << endl;
			cout << "��ţ�" << i << "\t";
			cout << "������" << abs->personArray[a.arr[i]].m_Name << "\t";
			cout << "�Ա�" << (abs->personArray[a.arr[i]].m_Sex == "1" ? "��" : "Ů") << "\t";
			cout << "���䣺" << abs->personArray[a.arr[i]].m_Age << "\t";
			cout << "�绰�ţ�" << abs->personArray[a.arr[i]].m_Phone << "\t";
			cout << "סַ��" << abs->personArray[a.arr[i]].m_Addr << "\n";
			
		}
		cout << "��ѡ��ɾ������ϵ�˵ı�ţ�" << endl;
		int ret;
		cin >> ret;

		if (ret < 0 || ret >= a.t) 
		{
			cout << "��Ч�ı�ţ�" << endl;
		}
		else 
		{
			//ͨѶ¼����ǰ��
			int index = a.arr[ret];
			for (int i = index; i < abs->m_Size - 1; i++)
			{
				abs->personArray[index] = abs->personArray[index + 1];
			}
			//����ͨѶ¼��С
			abs->m_Size--;
			cout << "ɾ���ɹ�" << endl;
		}
		
	}
	else
	{
		cout << "δ�ҵ�����ϵ�ˣ�" << endl;
	}
	system("pause");
}


//�޸���ϵ��
//�޸���ϵ����Ϣ����
void updateMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1���޸�����    *****" << endl;
	cout << "*****  2���޸��Ա�    *****" << endl;
	cout << "*****  3���޸�����    *****" << endl;
	cout << "*****  4���޸ĵ绰    *****" << endl;
	cout << "*****  5���޸�סַ    *****" << endl;
	cout << "*****  6���˳��޸�    *****" << endl;
	cout << "***************************" << endl;
}
void updatePerson(Addressbooks* abs)
{
	cout << "��ѡ���޸ĵ���ϵ�˵�������" << endl;
	string name;
	cin >> name;

	isexist a = isExist(abs, name);

	if (a.t != 0)
	{
		//ִ���޸Ĳ���
		for (int i = 0; i < a.t; i++)
		{
			//�����ѯ���
			cout << "*****" << endl;
			cout << "��ţ�" << i << "\t";
			cout << "������" << abs->personArray[a.arr[i]].m_Name << "\t";
			cout << "�Ա�" << (abs->personArray[a.arr[i]].m_Sex == "1" ? "��" : "Ů") << "\t";
			cout << "���䣺" << abs->personArray[a.arr[i]].m_Age << "\t";
			cout << "�绰�ţ�" << abs->personArray[a.arr[i]].m_Phone << "\t";
			cout << "סַ��" << abs->personArray[a.arr[i]].m_Addr << "\n";

		}
		cout << "��ѡ���޸ĵ���ϵ�˵ı�ţ�" << endl;
		int ret;
		cin >> ret;

		if (ret < 0 || ret >= a.t)
		{
			cout << "��Ч�ı�ţ�" << endl;
		}
		else
		{
			bool x = true;
			while (x)
			{

				int select;
				while (true)
				{
					system("cls");	//����

					updateMenu();		//�����޸���ϵ����Ϣ����

					cout << "��������Ҫ�޸ĵı�ţ�";
					cin >> select;	//���û�������ֵ

					if (select >= 1 and select < 7)
					{
						break;
					}
					else
					{
						cout << "��������ȷ����ֵ��" << endl;
					}

					cin.clear();
					cin.ignore();

				}



				switch (select)
				{
				case 1:		//�޸���ϵ������
				{
					string newname;
					cout << "�޸�ǰ������Ϊ��" << abs->personArray[a.arr[ret]].m_Name << "\n";
					cout << "�������޸ĺ����������", cin >> newname;
					abs->personArray[a.arr[ret]].m_Name = newname;
					cout << "\n�޸���ɣ�\n�޸ĺ������Ϊ��" << abs->personArray[a.arr[ret]].m_Name << "\n";
					system("pause");
				}
					break;
				case 2:		//�޸���ϵ���Ա�
				{
					int newsex;
					cout << "�޸�ǰ���Ա�Ϊ��" << (abs->personArray[a.arr[ret]].m_Sex == "1" ? "��" : "Ů") << "\n";
					cout << "�������޸ĺ�����Ա�1Ϊ�У�2ΪŮ����", cin >> newsex;
					abs->personArray[a.arr[ret]].m_Sex = newsex;
					cout << "\n�޸���ɣ�\n�޸ĺ���Ա�Ϊ��" << (abs->personArray[a.arr[ret]].m_Sex == "1" ? "��" : "Ů") << "\n";
					system("pause");
				}
					break;
				case 3:		//�޸���ϵ������
				{
					int newage;
					cout << "�޸�ǰ������Ϊ��" << abs->personArray[a.arr[ret]].m_Age << "\n";
					cout << "�������޸ĺ�������䣺", cin >> newage;
					abs->personArray[a.arr[ret]].m_Age = newage;
					cout << "\n�޸���ɣ�\n�޸ĺ������Ϊ��" << abs->personArray[a.arr[ret]].m_Age << "\n";
					system("pause");
				}
					break;
				case 4:		//�޸���ϵ�˵绰��
				{
					string newphone;
					cout << "�޸�ǰ�ĵ绰����Ϊ��" << abs->personArray[a.arr[ret]].m_Phone << "\n";
					cout << "�������޸ĺ���µ绰�ţ�", cin >> newphone;
					abs->personArray[a.arr[ret]].m_Phone = newphone;
					cout << "\n�޸���ɣ�\n�޸ĺ�ĵ绰����Ϊ��" << abs->personArray[a.arr[ret]].m_Phone << "\n";
					system("pause");
				}
					break;
				case 5:		//�޸���ϵ��סַ
				{
					string newaddr;
					cout << "�޸�ǰ��סַΪ��" << abs->personArray[a.arr[ret]].m_Addr << "\n";
					cout << "�������޸ĺ����סַ��", cin >> newaddr;
					abs->personArray[a.arr[ret]].m_Addr = newaddr;
					cout << "\n�޸���ɣ�\n�޸ĺ��סַΪ��" << abs->personArray[a.arr[ret]].m_Addr << "\n";
					system("pause");
				}
					break;
				case 6:		//�˳��޸���ϵ��
					x = false;
					break;
				}
			}

		}
	}
	else
	{
		cout << "δ�ҵ�����ϵ�ˣ�" << endl;
	}
	system("pause");
}



//������ϵ��
void findPerson(Addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ��:" << endl;
	string name;
	cin >> name;

	isexist a = isExist(abs, name);

	if (a.t != 0)
	{
		//�����ѯ���
		for (int i = 0; i < a.t; i++)
		{
			cout << "*****" << endl;
			cout << "��ţ�" << i << "\t";
			cout << "������" << abs->personArray[a.arr[i]].m_Name << "\t";
			cout << "�Ա�" << (abs->personArray[a.arr[i]].m_Sex == "1" ? "��" : "Ů") << "\t";
			cout << "���䣺" << abs->personArray[a.arr[i]].m_Age << "\t";
			cout << "�绰�ţ�" << abs->personArray[a.arr[i]].m_Phone << "\t";
			cout << "סַ��" << abs->personArray[a.arr[i]].m_Addr << "\n";
		}
		cout << "���ҳɹ�,һ����" << a.t << "����¼" << endl;
	}
	else
	{
		cout << "δ�ҵ�����ϵ�ˣ�" << endl;
	}
	system("pause");

}


//���������ϵ��
void cleanPerson(Addressbooks* abs)
{
	int A = 0;
	cout << "ȷ�����������ϵ���𣿣�1ȷ�ϣ�" << endl;
	cin >> A;
	if (A == 1)
	{
		abs->m_Size = 0;
		cout << "ͨѶ¼����գ�" << endl;
		system("pause");
	}
}



//�˵����� void showMenu()
void showMenu()
	{
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  7���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
	}



int main() 
	{

	Addressbooks Abs;		//����ͨѶ¼�ṹ�����
	Abs.m_Size = 0;			//��ʼ����Ա����


	int select;		//�û������ֵ


	while (true) 
	{
		
		while (true) 
		{
			system("cls");	//����

			showMenu();		//���ò˵�����

			cout << "�������ţ�";
			cin >> select;	//���û�������ֵ

			if (select >= 1 and select <= 7)
			{
				break;
			}
			else 
			{
				cout << "��������ȷ����ֵ��" << endl;
			}

			cin.clear();
			cin.ignore();

		}
		
		

		switch (select)
		{
		case 1:		//�����ϵ��
			addPerson(&Abs);		//��ַ���� ����ʵ��
			break;
		case 2:		//��ʾ��ϵ��
			showPerson(&Abs);
			break;
		case 3:		//ɾ����ϵ��
			deletePerson(&Abs);
			break;
		case 4:		//������ϵ��
			findPerson(&Abs);
			break;
		case 5:		//�޸���ϵ��
			updatePerson(&Abs);
			break;
		case 6:		//�����ϵ��
			cleanPerson(&Abs);
			break;
		case 7:		//�˳�ͨѶ¼
		{
			int A = 0;
			cout << "ȷ���˳��𣿣�1ȷ�ϣ�" << endl;
			cin >> A;
			if (A == 1)
			{
				cout << "��ӭ�´�ʹ��" << endl;
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
