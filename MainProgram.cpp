#include"Admin.cpp"
#include"ID.cpp"
#include"TheTu.cpp"
#include"LishSuID.cpp"
#include<string>
#include<vector>
#include"MenuUser.h"

using namespace std;

const int MAX_ADMIN = 3;
const int mTT = 10;

void LoginUser();
void MenuUser();
void showUser(ID dsid[]);
void RutTien();
void chuyenTien();
void showInfoTransaction();
void ChangePin();
bool checkFileID();
int slIDco();

void XoaTheTu(TheTu t[], string id_muonxoa);
int slTheTudaCo();
ostream& operator <<(ostream& os, ID& x);
bool checkFile();
void menuAdmin(Admin a[], int MAX_ADMIN);
void doc_Admin(Admin a[], int maxAdmin);
void QuanLyTheTu();
void nhapTT(TheTu t[], TheTu k, ID dsid[], ID *id);
void showTheTu(TheTu t[]);
int check_trung_id(TheTu t[], string &a);
void load_fileTT(TheTu t[]);

void Who(Admin a[]);


int main()
{
	Admin a[100];
	
	Who(a);
	system("Pause");
	return 0;
}

void load_fileTT(TheTu t[])
{
	ifstream filein;
	filein.open("TheTu.txt", ios_base::in);
	filein.ignore();
	
	getline(filein, t->id, ',');

	filein.close();
}
void menuAdmin(Admin a[], int Max_Admin)
{
	for (int i = 0; i < 26; i++)
	{
		cout << "*";
	}

	cout << endl;

	cout << "\tDANG NHAP ADMIN\n";

	for (int i = 0; i < 26; i++)
	{
		cout << "*";
	}
	cout << endl;

	doc_Admin(a, MAX_ADMIN);

}

void doc_Admin(Admin a[], int maxAdmin) {
	//Open file to read
	ifstream filein("Admin.txt");
	//Check if file is valid or not
	if (!filein.is_open()) {
		cout<< "Could not open file" << endl;
		return;
	}
	//
	int slAd = 0;
	//
	string line;
	//
	while (getline(filein, line)) {
		// parse the line to get username and password
		size_t comma_pos = line.find(',');
		if (comma_pos == string::npos) {
			continue;
		}
		//Gan gia tri tim duoc o file
		string username = line.substr(0, comma_pos);
		string password = line.substr(comma_pos + 1);

		// check if input is valid
		if (username.empty() || password.empty()) {
			cout << "Invalid username or password" << endl;
			continue;
		}

		// store the admin credentials
		a[slAd].user = username;
		a[slAd].pass = password;
		slAd++;
	}
	filein.close();

	// Yeu cau nhapp tu nguoi Admin
	for (int i = 0; i < 5; i++) {
		string ten, pass;
		cout << "User: ";
		cin >> ten;
		cout << "Pass: ";
		cin >> pass;

		bool found = false;
		for (int j = 0; j < slAd; j++) {
			if (a[j].user == ten && a[j].pass == pass) {
				found = true;
				break;
			}
		}
		if (found) {
			QuanLyTheTu();
			break;
		}
		else {
			cout << "Wrong username or password. Please try again." << endl;
		}
	}
}

void XoaTheTu(TheTu t[], string id_muonxoa)
{
	ifstream filein;
	filein.open("TheTu.txt", ios_base::in );

	vector<string>lines;
	string line;
	
	bool foundID = false;

	while(getline(filein, line))
	{
		//Gan gia tri id cho mot chuoi con
		t->id = line.substr(0, 14);
		t->pass = line.substr(15, line.size() - 15);//Gan pass cho mot chuoi con
		if (t->id == id_muonxoa)
		{
			foundID = true;
		}
		else
			lines.push_back(line);
	}
	filein.close();

	if (!foundID)
	{
		cout << "Id muon xoa khong ton tai\n";
		return;
	}
	ofstream fileout;
	fileout.open("TheTu.txt", ios_base::out | ios::trunc);
	for (const auto& line : lines)
	{
		fileout << line << '\n';
	}
	fileout.close();
	cout << "Xoa file thanh cong\n";
}
void QuanLyTheTu()
{
	ID dsid[mTT];
	ID id;
	TheTu t[mTT];  
	TheTu k;
	int l;
	string id_mx;
	bool check = true;
	while (check)
	{
		for (int i = 0; i < 26; i++)
		{
			std::cout << "*";
		}
		cout << endl;
		std::cout<<"\tMENU\n";
		for (int i = 0; i < 26; i++)
		{
			std::cout << "*";
		}
		std::cout << endl;
		std::cout << "1.Danh Sach Tai Khoan\n";
		std::cout << "2. Them Tai Khoan\n";
		std::cout << "3. Xoa Tai Khoan\n";
		std::cout << "4. Mo Tai Khoan\n";
		std::cout << "5.Thoat\n";
		for (int i = 0; i < 26; i++)
		{
			std::cout << "*";
		}
		std::cout << "\nLua chon: ";
		std::cin >> l;
		switch (l)
		{
		case 1:
			showTheTu(t);
			break;
		case 2:
			if (slTheTudaCo() == mTT)
			{
				cout << "The tu da dat gioi han\n";break;
			}
			else {
				int sltt;
				cout << "Nhap so luong the tu can them: \n";
				cin >> sltt;
				cin.ignore();
				for (int i = 0; i < sltt; i++)
				{
					nhapTT(t, k, dsid, &id);
					cout << endl;
				}
				break;
			}
			
		case 3:
			cin.ignore();
			cout << "Nhap id muon xoa: "; getline(cin, id_mx);
			XoaTheTu(t, id_mx);
			break;
		case 4:
			break;
		case 5:
			check = false;
			break;
		}
	}
}
ostream& operator <<(ostream&os, ID& x)
{

	os << "Id: " << x.id << endl;
	os << "Name: " << x.nameTK << endl;
	os << "Balance: " << x.balance << " " << x.loaiTien << endl;;
	return os;
}


void showTheTu(TheTu t[])
{
		ifstream filein;
		filein.open("TheTu.txt", ios_base::in);
		
		if (!filein.is_open())
		{
			cout<<"Khong the mo file";	
		}
		else if (checkFile())
		{
			cout << "Danh sach rong\n";
		}
		else {
			
			for (int i = 0; i < slTheTudaCo(); i++)
			{
				cout << "----------The tu thu " << i + 1 << "----------: \n";
				getline(filein, t->id, ',');
				cout << "Id: "<<t->id << endl;
				getline(filein, t->pass);
			}
		}
		filein.close();
}


void nhapTT(TheTu t[], TheTu k, ID dsid[], ID* id)
{


	ofstream fileout1;
	fileout1.open("TheTu.txt", ios_base::app | ios_base::in);
	if (!fileout1.is_open()) {
		cout << "Could not open file TheTu.txt" << endl;
		return;
	}
	int kt;

	ofstream fileout2;
	fileout2.open("ID.txt", ios_base::app | ios_base::out);
	if (!fileout2.is_open()) {
		cout << "Could not open file ID.txt" << endl;
		return;
	}
	bool daNhap = false;//Danh dau da nhap

	while (!daNhap)
	{
		cout << "Nhap id: ";
		cin >> k.id;

		kt = check_trung_id(t, k.id);

		if (k.id.size() != 14)
		{
			cout << "Id phai co 14 ky tu\n";
		}
		else if (kt != 0) {
			cout << "Id bi trung - Nhap lai\n";
		}
		else daNhap = true;
	}

	do {
		cout << "Nhap pass: ";
		cin >> k.pass;

		if (k.pass.size() != 6) cout << "Pass phai co 6 ky tu!\n";

	} while (k.pass.size() != 6);
	
	cout << "Nhap ten tai khoan: ";
	cin >> id->nameTK;
	
	cin.ignore();
	cout << "Tao so du ban dau: ";
	cin >> id->balance;
	cin.ignore();
	id->setLT();

	fileout2 << id->nameTK << ','
		<< id->balance << ' ' << id->getLT();

	fileout2.flush();
	fileout2.close();

	if (kt == 0)
	{
		fileout1.seekp(0, ios_base::beg);//Dua con tro file den dau
		fileout1 << k.id << ',' << k.pass << endl;
		fileout1.flush();

		fileout2.seekp(0, ios_base::end);
		fileout2 << endl << k.id << ',';
		fileout2.flush();

		cout << "Da ghi them mot ban ghi vao file.\n";
	}
	else if (kt != -1) {
		cout << "Da ton tai mot ban ghi voi id nay trong file.\n";
	}

	fileout1.close();

}
int check_trung_id(TheTu t[], string &a)
{

	int mTT_max = 0;
	ifstream filein;
	filein.open("TheTu.txt", ios_base::in);
	string line;
	while (getline(filein, line))
	{
		// parse the line to get username and password
		size_t comma_pos = line.find(',');
		if (comma_pos == string::npos) {
			continue;
		}
		//Gan gia tri tim duoc o file
		string id = line.substr(0, comma_pos);

		// check if input is exist
		if (id.empty()) {
			cout << "Khong co id nao trong mang\n";
			continue;
		}
		

		 //store the admin credentials
		t[mTT_max].id = id;
		mTT_max++;
	}
	filein.close();
	bool gan = false;
	for (int i = 0; i < slTheTudaCo(); i++)
	{
		if (_stricmp(a.c_str(), t[i].id.c_str()) == 0)
		{
			gan = true;
			break;
		}
	}
	return gan;
}

int slTheTudaCo()
{
	int count = 0;
	ifstream filein;
	filein.open("TheTu.txt", ios_base::in);
	string line;
	while (getline(filein, line))
	{
		if (!line.empty()) {
			count++;
		}
	}
	filein.close();
	return count;
}

bool checkFile()
{
	ifstream filein;
	filein.open("TheTu.txt", ios_base::in);
	string line;
	
	//Doc tung dong trong file
	while (getline(filein, line))
	{
		
		if (!line.empty())
		{
			return false;
		}
		
	}
	return true;
	filein.close();
}

void Who(Admin a[])
{
	int choose;
	bool open = true;
	while(open)
	{
		for (int i = 0; i < 26; i++)
		{
			cout << "*";
		}

		cout << endl;

		cout << "Ban la: \n";
		cout << "1.Admin.\n";

		cout << "2.User.\n";
		cout << "3. Exit\n";

		cin >> choose;
		switch (choose)
		{
		case 1:		
			menuAdmin(a, MAX_ADMIN);
		case 2:
			/*menuUser();*/
		case 3:
			open = false;
			break;
		}
		
	}
	for (int i = 0; i < 26; i++)
	{
		cout << "*";
	}
	cout << endl;
	
}