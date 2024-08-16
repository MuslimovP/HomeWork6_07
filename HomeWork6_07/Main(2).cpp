#include <iostream>
#include <Windows.h>
using namespace std;

class Passport  // базовый класс
{
protected:
    char* name;
    char* dateOfBirth;
    char* placeOfResidence;
    char* serialNumber;

public:
    Passport();
    Passport(const char*, const char*, const char*, const char*);
    void Output_Passport();
    ~Passport();
};

Passport::Passport()
{
    cout << "Construct Passport\n";
    name = nullptr;
    dateOfBirth = nullptr;
    placeOfResidence = nullptr;
    serialNumber = nullptr;
}

Passport::Passport(const char* Name, const char* DOB, const char* POR, const char* SN)
{
    cout << "Construct Passport\n";

    name = new char[strlen(Name) + 1];
    strcpy_s(name, strlen(Name) + 1, Name);

    dateOfBirth = new char[strlen(DOB) + 1];
    strcpy_s(dateOfBirth, strlen(DOB) + 1, DOB);

    placeOfResidence = new char[strlen(POR) + 1];
    strcpy_s(placeOfResidence, strlen(POR) + 1, POR);

    serialNumber = new char[strlen(SN) + 1];
    strcpy_s(serialNumber, strlen(SN) + 1, SN);
}

void Passport::Output_Passport()
{
    cout << "Output Passport\n";
    cout << "Name: " << name << endl
        << "Date of Birth: " << dateOfBirth << endl
        << "Place of Residence: " << placeOfResidence << endl
        << "Serial Number: " << serialNumber << endl << endl;
}

Passport::~Passport()
{
    if (name != nullptr) 
    {
        delete[] name;
    }
    if (dateOfBirth != nullptr) 
    {
        delete[] dateOfBirth;
    }
    if (placeOfResidence != nullptr) 
    {
        delete[] placeOfResidence;
    }
    if (serialNumber != nullptr) 
    {
        delete[] serialNumber;
    }
    cout << "Destruct Passport\n";
    Sleep(1000);
}

class ForeignPassport : public Passport  // производный класс
{
    char* visaInfo;
    char* foreignPassportNumber;

public:
    ForeignPassport();
    ForeignPassport(const char*, const char*, const char*, const char*, const char*, const char*);
    ~ForeignPassport();
    void Output_ForeignPassport();
};

ForeignPassport::ForeignPassport() : Passport()
{
    cout << "Construct ForeignPassport\n";
    visaInfo = nullptr;
    foreignPassportNumber = nullptr;
}

ForeignPassport::ForeignPassport(const char* Name, const char* DOB, const char* POR, const char* SN, const char* VI, const char* FPN)
    : Passport(Name, DOB, POR, SN)
{
    cout << "Construct ForeignPassport\n";

    visaInfo = new char[strlen(VI) + 1];
    strcpy_s(visaInfo, strlen(VI) + 1, VI);

    foreignPassportNumber = new char[strlen(FPN) + 1];
    strcpy_s(foreignPassportNumber, strlen(FPN) + 1, FPN);
}

ForeignPassport::~ForeignPassport()
{
    if (visaInfo != nullptr) 
    {
        delete[] visaInfo;
    }
    if (foreignPassportNumber != nullptr) 
    {
        delete[] foreignPassportNumber;
    }
    cout << "Destruct ForeignPassport\n";
    Sleep(1000);
}

void ForeignPassport::Output_ForeignPassport()
{
    cout << "Output ForeignPassport\n";
    Output_Passport();  // вывод паспортных данных
    cout << "Visa Info: " << visaInfo << endl
        << "Foreign Passport Number: " << foreignPassportNumber << endl << endl;
}

int main()
{
    ForeignPassport fp("Ivan Ivanov", "01/01/1985", "Kyiv, Ukraine", "AB123456", "Schengen, USA", "FP789012");
    fp.Output_ForeignPassport();

    system("pause");
    return 0;
}
