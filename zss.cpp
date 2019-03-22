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
	cout << "��ţ�" << number << endl;
	cout << "������" << name << endl;
	cout << "���䣺" << age << endl;
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
	cout<<"��Ա��Ϊ����Ա"<<endl; 
	Staff::search();
	cout << "���۶" << sale << endl;
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
	cout<<"��Ա��Ϊ����"<<endl; 
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
	cout << "��Ա��Ϊ���۾���" << endl;
	Staff::search();
	cout << "���۶" << sale << endl;
}
int SalesManager::num_salesmanager=0;

void update(vector <Salesman> &ve){
	cout<<"��������Ҫ������Ϣ��Ա����ţ�";
	int nu;
	cin>>nu;
	for(int i=0;(int)i<ve.size();i++){
		if(nu==ve[i].get_number()){
			cout<<"�������µ�Ա����ţ�";
			int nu;
			cin>>nu; 
			cout<<"�������µ�Ա��������";
			string na;
			cin>>na;
			cout<<"�������µ�Ա�����䣺";
			int a;
			cin>>a;
			cout<<"�������µ�Ա�����۶";
			int s;
			cin>>s;
			ve[i].update(nu,na,a,s);
			return;
		}
	} 
	cout<<"���޴��ˣ�"<<endl;
}

void update(vector <Manager> &ve){
	cout<<"��������Ҫ������Ϣ��Ա����ţ�";
	int nu;
	cin>>nu;
	for(int i=0;i<(int)ve.size();i++){
		if(nu==ve[i].get_number()){
			cout<<"�������µ�Ա����ţ�";
			int nu;
			cin>>nu; 
			cout<<"�������µ�Ա��������";
			string na;
			cin>>na;
			cout<<"�������µ�Ա�����䣺";
			int a;
			cin>>a;
			ve[i].update(nu,na,a);
			return;
		}
	} 
	cout<<"���޴��ˣ�"<<endl;
}
void update(vector <SalesManager> &ve){
	cout<<"��������Ҫ������Ϣ��Ա����ţ�";
	int nu;
	cin>>nu;
	for(int i=0;i<(int)ve.size();i++){
		if(nu==ve[i].get_number()){
			cout<<"�������µ�Ա����ţ�";
			int nu;
			cin>>nu; 
			cout<<"�������µ�Ա��������";
			string na;
			cin>>na;
			cout<<"�������µ�Ա�����䣺";
			int a;
			cin>>a;
			cout<<"�������µ�Ա�����۶";
			int s;
			cin>>s;
			ve[i].update(nu,na,a,s);
			return;
		}
	} 
	cout<<"���޴��ˣ�"<<endl;
}
void add(vector <Salesman> &ve){
	int nu,a,s;
	string na;
	cout<<"���������Ա����ţ�";
	cin>>nu;
	cout<<"���������Ա��������";
	cin>>na;
	cout<<"���������Ա�����䣺";
	cin>>a;
	cout<<"���������Ա�����۶";
	cin>>s;
	Salesman add1(nu,na,a,s);
	ve.push_back(add1);
	cout<<"��ӳɹ���"<<endl;
}
void add(vector <Manager> &ve){
	int nu,a;
	string na;
	cout<<"���������Ա����ţ�";
	cin>>nu;
	cout<<"���������Ա��������";
	cin>>na;
	cout<<"���������Ա�����䣺";
	cin>>a;
	Manager add1(nu,na,a);
	ve.push_back(add1);
	cout<<"��ӳɹ���"<<endl;
}
void add(vector <SalesManager> &ve){
	int nu,a,s;
	string na;
	cout<<"���������Ա����ţ�";
	cin>>nu;
	cout<<"���������Ա��������";
	cin>>na;
	cout<<"���������Ա�����䣺";
	cin>>a;
	cout<<"���������Ա�����۶";
	cin>>s;
	SalesManager add1(nu,na,a,s);
	ve.push_back(add1);
	cout<<"��ӳɹ���"<<endl;
}

template <typename T>
void search(vector <T> &ve){
	cout<<"���������ѯ��Ա����ţ�";
	int nu;
	cin>>nu;
	for(int i=0;i<(int)ve.size();i++) {
		if(nu==ve[i].get_number()){
			ve[i].search();
			return;
		}
	}
	cout<<"���޴��ˣ�"<<endl;
}
template <typename T>
void delet(vector <T> &ve){
	cout<<"��������ɾ����Ա����ţ�";
	int nu;
	cin>>nu;
	for(int i=0;i<(int)ve.size();i++) {
		if(nu==ve[i].get_number()){
			ve[i].delet();
			cout<<"ɾ���ɹ���"<<endl;
			return;
		}
	}
	cout<<"���޴��ˣ�"<<endl;
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
		cout << "�޷���" << endl;
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
		cout << "�޷���" << endl;
		return;
	}
	for (int i = 0;i < (int)ve.size();i++) {
		fp << ve[i];
	}
	fp.close();
	return;
}

void count(){
	cout<<"����Ա������  "<<Salesman::get_SN()<<endl;
	cout<<"����������    "<<Manager::get_MN()<<endl;
	cout<<"���۾���������"<<SalesManager::get_SMN()<<endl;
	cout<<"��������      "<<SalesManager::get_SMN()+Salesman::get_SN()+Manager::get_MN()<<endl;
}
template<typename T>
void choose(vector<T> &ve){
	int in = 7;
	while (in != 0) {
		cout << "1.����Ա����Ϣ" << endl
			 << "2.����Ա����Ϣ" << endl
			 << "3.��ѯԱ����Ϣ" << endl
		 	 << "4.ɾ��Ա����Ϣ" << endl
			 << "5.�����ļ�" << endl
			 << "0.����" << endl;
		cout << "������ѡ��Ĺ��ܣ�";
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
		cout << "1.����Ա" << endl
			 << "2.����" << endl
			 << "3.���۾���" << endl
			 << "4.��ʾ����" << endl
		 	 << "0.�˳�" << endl;
		cout << "ѡ��";
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
