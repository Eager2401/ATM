#include"Admin.cpp"
#include"ID.cpp"
#include"TheTu.cpp"
#include"LishSuID.cpp"
#include<string>
using namespace std;
const int MAX_ADMIN = 3;
const int mTT = 10;

void menuAdmin(Admin a[], int MAX_ADMIN);
void doc_File(Admin a[], int maxAdmin);
void QuanLyTheTu();
void nhapTheTu(TheTu t[], int maxTT);
void showTheTu(TheTu t[], int maxTheTu);


int main()
{
	Admin a[100];
	menuAdmin(a, MAX_ADMIN);
	system("Pause");
	return 0;
}

void menuAdmin(Admin a[], int Max_Admin)
{
	for (int i = 0; i < 20; i++)
	{
		cout << "*";
	}

	cout << endl;

	cout << "DANG NHAP ADMIN\n";

	for (int i = 0; i < 20; i++)
	{
		cout << "*";
	}
	cout << endl;

	doc_File(a, MAX_ADMIN);

}

void doc_File(Admin a[], int maxAdmin)
{
	//khoi tao bien
	int slAd = 0;
	//Yeu cau nhap cho dung, gioi han 5 laan nhap
	for (int i = 0; i < maxAdmin; i++)
	{
		
		//Khoi tao cac doi tuong ten va pass
		string ten, pass;
		cout << "User: "; cin >> ten;;
		cout << "Pass: "; cin >> pass;
		

		//Khai bao bien
		ifstream filein;

		//Mo file ra de doc
		filein.open("ATMAdmin.txt", ios_base::in);
		while (!filein.eof())
		{

			getline(filein, a[slAd].user, ',');
			
			getline(filein, a[slAd].pass);
			
			//Kiem tra 
			if (ten!= a[slAd].user)
			{
				cout << "Sai tai khoan\n";
				cout << "Nhap lai: \n";
			}
			else if (ten == a[slAd].user)
			{
				if (a[slAd].pass != pass)
				{
					cout << "Sai mat khau\n";
					cout << "Nhap lai: \n";
					
					slAd++;
				}
				else
				{
					QuanLyTheTu();
				}
			}
		}
		
		filein.close();
	}

}

void QuanLyTheTu()
{
	TheTu t[mTT];
	int l;
	while (true)
	{
		for (int i = 0; i < 10; i++)
		{
			std::cout << "*";
		}
		cout << endl;
		std::cout<<"MENU\n";
		for (int i = 0; i < 10; i++)
		{
			std::cout << "*";
		}
		std::cout << endl;
		std::cout << "1.Danh Sach Tai Khoan\n";
		std::cout << "2. Them Tai Khoan\n";
		std::cout << "3. Xoa Tai Khoan\n";
		std::cout << "4. Mo Tai Khoan\n";
		for (int i = 0; i < 26; i++)
		{
			std::cout << "*";
		}
		std::cout << "\nLua chon: ";
		std::cin >> l;
		switch (l)
		{
		case 1:
			/*showTheTu();*/
			break;
		case 2:
			nhapTheTu(t, mTT);
			break;
		}
	}
}
ostream& operator <<(ostream&os, ID& x)
{

	os << "Id: " << x.getId() << endl;
	os << "Name: " << x.getName() << endl;
	os << "Balance: " << x.getBalance() << " " << x.getLT() << endl;;
	return os;
}




void nhapTheTu(TheTu t[], int maxTT)
{
	
	//Nhap thong tin cua tung the tu
	for (int i = 0; i < maxTT; i++)
	{
		cout << "Nhap id: ";
		t[i].setId();
		cout << "Nhap Pass: ";
		t[i].setPass();

		//Ghi thong tin the tu vao file TheTu.txt
		ofstream outFile("TheTu.txt", ios::app);
		if (outFile.is_open())
		{
			outFile << t[i].getId() << " " << t[i].getPass();
			outFile.close();
		}
		break;
		if (i == maxTT - 1)
		{
			cout << "So luong the tu da day";
			break;
		}
	}
}

void showTheTu(TheTu t[], int maxTheTu)
{

}