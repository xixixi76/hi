#include<iostream>
#include<string>
#include<fstream>
#include <vector>
#include <typeinfo>
using namespace std;

class Staff {
protected:
	int number;
	string name;
	int age;
	bool tap;
public:
	Staff(){}
	Staff(int nu, string na, int a,bool tap=false)
		:number(nu), name (na) ,age(a) {}
	~Staff(){} 
	int get_number() { return number; }
	string get_name() { return name; }
	int get_age() { return age; }
	bool get_tap() { return tap; }
	void delet();
	void update(int nu, string na, int a);
	void search();
};
void Staff::delet() {
	tap = true;
}
void Staff::update(int nu, string na, int a) {
	number = nu;
	name = na;
	age = a;
}
void Staff::search() {
	cout << "编号：" << number << endl;
	cout << "姓名：" << name << endl;
	cout << "年龄：" << age << endl;
}

class Salesman :virtual public Staff {
protected:
	static int num_salesman;
	int sale;
public:
	Salesman(){}
	Salesman(int nu, string na, int a, int s)
		:Staff(nu, na, a), sale(s) {
		num_salesman++;
	}
	~Salesman() {}
	static int get_SN() { return num_salesman; }
	int get_sale() { return sale; }
	void inc_cn(){ num_salesman++; }
	void update(int nu, string na, int a,int s);
	void delet();
	void search();
	friend ostream & operator<<(ostream &os,Salesman &s){
		os<<s.number<<" "<<s.name<<" "<<s.age<<" "<<s.sale<<"\n";
		return os;
	}
	friend istream & operator>>(istream &is,Salesman &s){
		is>>s.number>>s.name>>s.age>>s.sale;
		return is;
	}
};
void Salesman::update(int nu, string na, int a,int s) {
	Staff::update(nu,na,a);
	sale=s;
}
void Salesman::delet(){
	Staff::delet();
	num_salesman--;
}
void Salesman::search(){
	cout<<"该员工为销售员"<<endl; 
	Staff::search();
	cout << "销售额：" << sale << endl;
}
int Salesman::num_salesman = 0;

class Manager : virtual public Staff {
protected:
	static int num_manager;
public:
	Manager() {}
	Manager(int nu, string na, int a)
		:Staff(nu, na, a) {
		num_manager++;
	}
	~Manager() {}
	static int get_MN() { return num_manager; }
	void inc_cn(){ num_manager++; }
	void delet();
	void search();
	friend ostream & operator<<(ostream &os,Manager &m){
		os<<m.number<<" "<<m.name<<" "<<m.age<<" "<<"\n";
		return os;
	}
	friend istream & operator>>(istream &is,Manager &m){
		is>>m.number>>m.name>>m.age;
		return is;
	}
};
void Manager::delet(){
	Staff::delet();
	num_manager--;
}
void Manager::search(){
	cout<<"该员工为经理"<<endl; 
	Staff::search();	 
}
int Manager::num_manager=0;

class SalesManager : public Salesman,public Manager {
protected:
	static int num_salesmanager;
public:
	SalesManager(){}
	SalesManager(int nu,string na,int a,int s)
		:Salesman(), Manager(), Staff(nu, na, a) {
			sale=s;
			num_salesmanager++;
	}
	~SalesManager() {}
	static int get_SMN() { return num_salesmanager; }
	void inc_cn(){ num_salesmanager++; }
	void update(int nu, string na, int a,int s);
	void delet();
	void search();
	friend ostream & operator<<(ostream &os,SalesManager &m){
		os<<m.number<<" "<<m.name<<" "<<m.age<<"\n";
		return os;
	}
	friend istream & operator>>(istream &is,SalesManager &m){
		is>>m.number>>m.name>>m.age;
		return is;
	}
};
void SalesManager::update(int nu, string na, int a,int s) {
	Staff::update(nu,na,a);
	sale=s;
}
void SalesManager::delet(){
	Staff::delet();
	num_salesmanager--;
}
void SalesManager::search() {
	cout << "该员工为销售经理" << endl;
	Staff::search();
	cout << "销售额：" << sale << endl;
}
int SalesManager::num_salesmanager=0;

void update(vector <Salesman> &ve){
	cout<<"请输入需要更新信息的员工编号：";
	int nu;
	cin>>nu;
	for(int i=0;(int)i<ve.size();i++){
		if(nu==ve[i].get_number()){
			cout<<"请输入新的员工编号：";
			int nu;
			cin>>nu; 
			cout<<"请输入新的员工姓名：";
			string na;
			cin>>na;
			cout<<"请输入新的员工年龄：";
			int a;
			cin>>a;
			cout<<"请输入新的员工销售额：";
			int s;
			cin>>s;
			ve[i].update(nu,na,a,s);
			return;
		}
	} 
	cout<<"查无此人！"<<endl;
}

void update(vector <Manager> &ve){
	cout<<"请输入需要更新信息的员工编号：";
	int nu;
	cin>>nu;
	for(int i=0;i<(int)ve.size();i++){
		if(nu==ve[i].get_number()){
			cout<<"请输入新的员工编号：";
			int nu;
			cin>>nu; 
			cout<<"请输入新的员工姓名：";
			string na;
			cin>>na;
			cout<<"请输入新的员工年龄：";
			int a;
			cin>>a;
			ve[i].update(nu,na,a);
			return;
		}
	} 
	cout<<"查无此人！"<<endl;
}
void update(vector <SalesManager> &ve){
	cout<<"请输入需要更新信息的员工编号：";
	int nu;
	cin>>nu;
	for(int i=0;i<(int)ve.size();i++){
		if(nu==ve[i].get_number()){
			cout<<"请输入新的员工编号：";
			int nu;
			cin>>nu; 
			cout<<"请输入新的员工姓名：";
			string na;
			cin>>na;
			cout<<"请输入新的员工年龄：";
			int a;
			cin>>a;
			cout<<"请输入新的员工销售额：";
			int s;
			cin>>s;
			ve[i].update(nu,na,a,s);
			return;
		}
	} 
	cout<<"查无此人！"<<endl;
}
void add(vector <Salesman> &ve){
	int nu,a,s;
	string na;
	cout<<"请输入添加员工编号：";
	cin>>nu;
	cout<<"请输入添加员工姓名：";
	cin>>na;
	cout<<"请输入添加员工年龄：";
	cin>>a;
	cout<<"请输入添加员工销售额：";
	cin>>s;
	Salesman add1(nu,na,a,s);
	ve.push_back(add1);
	cout<<"添加成功！"<<endl;
}
void add(vector <Manager> &ve){
	int nu,a;
	string na;
	cout<<"请输入添加员工编号：";
	cin>>nu;
	cout<<"请输入添加员工姓名：";
	cin>>na;
	cout<<"请输入添加员工年龄：";
	cin>>a;
	Manager add1(nu,na,a);
	ve.push_back(add1);
	cout<<"添加成功！"<<endl;
}
void add(vector <SalesManager> &ve){
	int nu,a,s;
	string na;
	cout<<"请输入添加员工编号：";
	cin>>nu;
	cout<<"请输入添加员工姓名：";
	cin>>na;
	cout<<"请输入添加员工年龄：";
	cin>>a;
	cout<<"请输入添加员工销售额：";
	cin>>s;
	SalesManager add1(nu,na,a,s);
	ve.push_back(add1);
	cout<<"添加成功！"<<endl;
}

template <typename T>
void search(vector <T> &ve){
	cout<<"请输入需查询的员工编号：";
	int nu;
	cin>>nu;
	for(int i=0;i<(int)ve.size();i++) {
		if(nu==ve[i].get_number()){
			ve[i].search();
			return;
		}
	}
	cout<<"查无此人！"<<endl;
}
template <typename T>
void delet(vector <T> &ve){
	cout<<"请输入需删除的员工编号：";
	int nu;
	cin>>nu;
	for(int i=0;i<(int)ve.size();i++) {
		if(nu==ve[i].get_number()){
			ve[i].delet();
			cout<<"删除成功！"<<endl;
			return;
		}
	}
	cout<<"查无此人！"<<endl;
}
template <typename T>
void restruct(vector <T> &ve){
	typename vector<T>::iterator p; 
	p=ve.begin();
	while(p!=ve.end()){
		if(p->get_tap()) p=ve.erase(p);
		p++;
	}
}

template<typename T>
void read(vector<T> &ve){
	fstream fp;
	if(typeid(T) == typeid(Salesman))
		fp.open("E:\\C++\\oop4\\salesman.txt",ios::in);
	else if(typeid(T) == typeid(SalesManager))
		fp.open("E:\\C++\\oop4\\salesmanager.txt",ios::in);
	else if(typeid(T) == typeid(Manager))
		fp.open("E:\\C++\\oop4\\manager.txt",ios::in);
	if (!fp) {
		cout << "无法打开" << endl;
		return;
	}
	T ele;
	while (fp >> ele) {
		ele.inc_cn();
		ve.push_back(ele);
	}
	fp.close();
	return;
}
template<typename T>
void write(vector<T> &ve){
	fstream fp;
	if (typeid(T) == typeid(Salesman))
		fp.open("E:\\C++\\oop4\\salesman.txt", ios::out);
	else if (typeid(T) == typeid(SalesManager))
		fp.open("E:\\C++\\oop4\\salesmanager.txt", ios::out);
	else if (typeid(T) == typeid(Manager))
		fp.open("E:\\C++\\oop4\\manager.txt", ios::out);
	if (!fp) {
		cout << "无法打开" << endl;
		return;
	}
	for (int i = 0;i < (int)ve.size();i++) {
		fp << ve[i];
	}
	fp.close();
	return;
}

void count(){
	cout<<"销售员人数：  "<<Salesman::get_SN()<<endl;
	cout<<"经理人数：    "<<Manager::get_MN()<<endl;
	cout<<"销售经理人数："<<SalesManager::get_SMN()<<endl;
	cout<<"总人数：      "<<SalesManager::get_SMN()+Salesman::get_SN()+Manager::get_MN()<<endl;
}
template<typename T>
void choose(vector<T> &ve){
	int in = 7;
	while (in != 0) {
		cout << "1.增加员工信息" << endl
			 << "2.更新员工信息" << endl
			 << "3.查询员工信息" << endl
		 	 << "4.删除员工信息" << endl
			 << "5.重组文件" << endl
			 << "0.返回" << endl;
		cout << "请输入选择的功能：";
		cin >> in;
		if (in == 1)add(ve);
		else if (in == 2)update(ve);
		else if (in == 3)search(ve);
		else if (in == 4)delet(ve);
		else if (in == 5)restruct(ve);
	}
	return;
}

int main(){
	vector<Salesman> Sman;
	vector<Manager> Man;
	vector<SalesManager> SMan;
	read(Sman);
	read(Man);
	read(SMan);
	int who = 5;
	while (who != 0) {
		cout << "1.销售员" << endl
			 << "2.经理" << endl
			 << "3.销售经理" << endl
			 << "4.显示人数" << endl
		 	 << "0.退出" << endl;
		cout << "选择：";
		cin >> who;
		if (who == 1)choose(Sman);
		else if (who == 2)choose(Man);
		else if (who == 3)choose(SMan);
		else if (who == 4)count();
	}
	write(Sman);
	write(Man);
	write(SMan);
	return 0;
} 
