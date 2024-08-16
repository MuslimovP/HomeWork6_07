#include<iostream>
#include<Windows.h>
using namespace std;

class Student  // base class
{
protected:
	char* name; 
	int age; 
	int groupNumber; 
	char* specialty; 
public:
	Student();
	Student(const char*, int, int, const char*);
	void Output_Student(); 
	~Student();  
};

Student::Student()
{
	cout << "Construct Student\n"; 
	name = nullptr;
	age = 0;
	groupNumber = 0; 
	specialty = nullptr; 
}

Student::Student(const char* Name, int Age, int GroupNumber, const char* Specialty)
{
	cout << "Construct Student\n";
	name = new char[strlen(Name) + 1];
	strcpy_s(name, strlen(Name) + 1, Name);
	age = Age; 
	groupNumber = GroupNumber; 
	specialty = new char[strlen(Specialty) + 1];
	strcpy_s(specialty, strlen(Specialty) + 1, Specialty);  
}
void Student::Output_Student() 
{
	cout << "Output Student\n";
	cout << "Name: " << name << endl
		<< "Age: " << age << endl << "GroupNumber: " << groupNumber << endl << "Specialty: " << specialty << endl << endl;
}
Student::~Student()
{
	if (name != nullptr)
	{
		delete[] name;
	}
	if (specialty != nullptr)
	{
		delete[] specialty; 
	}
	cout << "Destruct Student\n";
	Sleep(1000);
}

class Aspirant : public Student //  potomok 
{
	char* nameCandidatPaper;
	double Scholarship;
public:
	Aspirant();
	Aspirant(const char* n, int a, int g, const char* s, const char* NCP, double S);
	~Aspirant();
	void Output();
};
Aspirant::Aspirant()/*:Student()*/ 
{
	cout << "Construct Aspirant\n";
	name = nullptr;
	age = 0;
	nameCandidatPaper = nullptr;
	Scholarship = 0;

}
Aspirant::Aspirant(const char* n, int a, int g, const char* s, const char* NCP, double S) :Student(n, a, g, s)
{
	cout << "Construct Aspirant\n";
	Scholarship = S;
	nameCandidatPaper = new char[strlen(NCP) + 1]; 
	strcpy_s(nameCandidatPaper, strlen(NCP) + 1, NCP);  
}

Aspirant::~Aspirant()
{ 
	if (nameCandidatPaper != nullptr) 
	{
		delete[] nameCandidatPaper; 
	}
	cout << "Destruct Aspirant\n";
	Sleep(1000);

}
void Aspirant::Output()
{
	cout << "Output Aspirant\n";
	Output_Student();  
	cout << "NameCandidatPaper: " << nameCandidatPaper << endl 
		<< "Scholarship: " << Scholarship << endl << endl;
}


int main()
{
	Aspirant a("Oleg", 25, 12, "Itstep", "C++", 2000);
	a.Output();


	system("pause");
}