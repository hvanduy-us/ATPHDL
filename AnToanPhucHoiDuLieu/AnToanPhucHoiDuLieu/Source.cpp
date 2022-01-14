#include<iostream>
#include<fstream>
#include<vector>
#include<ctime>
#include"SHA1.h"
#include"Encrypt.h"
#include"Device_File.h"
//#define Out_FileName "output.txt"
using namespace std;
void Encrypt()
{
	string FileName = "input";
	string key;

	int cn = 0;

	do
	{
		cout << " \n\n1: Ma hoa file input.txt ra file output.txt" << endl;
		cout << "2: Giai ma file output.txt ra file output1.txt" << endl;
		cout << "-1: ket thuc" << endl;
		cout << "\tchon chuc nang: ";
		cin >> cn;

		if (cn == -1)
		{
			break;
		}
		switch (cn)
		{
		case 1:
		{
			////// ma hoa
			cout << "nhap ten file: ";
			cin >> FileName;

			cout << "nhap khoa: ";
			cin >> key;
			char* k = new char[sha1(key).size() + 1];

			strcpy(k, sha1(key).c_str());
			cout << " Key duoc hash: " << k << endl;
			File_ENCRYPT(FileName, k);
			break;
		}
		case 2:
		{
			//////giai ma
			cout << "nhap ten file: ";
			cin >> FileName;

			cout << "nhap khoa: ";
			cin >> key;
			char* k = new char[sha1(key).size() + 1];

			strcpy(k, sha1(key).c_str());
			cout << " Key duoc hash: " << k << endl;

			File_DECRYPT(FileName, k);
			break;
		}
		default:
		{
			cout << "Ban khong chon chuc nang!" << endl;
			cout << "Ket thuc chuong trinh" << endl;
			break;
		}
		}
	} while (1);
}

void Devide_file()
{
	string filename;
	int num_file;

	cout << "nhap ten file: ";
	cin >> filename;
	cout << "nhap so luong file can chia: ";
	cin >> num_file;

	Divided(filename, num_file);
}
void Join_File()
{
	string filename;
	int num_file;

	cout << "nhap ten file: ";
	cin >> filename;
	cout << "nhap so luong file can chia: ";
	cin >> num_file;

	Join(filename, num_file);
}
int main()
{

	//Encrypt();
	//Devide_file();
	//Join("a",3);

	return 0;
}

