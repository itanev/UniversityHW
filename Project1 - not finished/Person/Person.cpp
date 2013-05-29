#include <iostream>
#include <stdlib.h>
#include <stdexcept>
#include <cstring>
#include "Person.h"

using namespace std;

Person::Person()
{
}

Person::Person(const char *name, const char* EGN, const char* address = "",
               Profession profession = Unemployed, double income = 0)
{
	setName(name);

	validateEGN(EGN);
	this->EGN = new char[strlen(EGN)];
	strcpy(this->EGN, EGN);

	setAddress(address);
	this->age = getAgeFromEGN();
	this->sex = getSexFromEGN();
	setProfession(profession);
	setIncome(income);
}

Person::Person(const Person& anotherPerson)
{
	swapFields(anotherPerson);
}

Person& Person::operator=(const Person& anotherPerson)
{
	if(this != &anotherPerson)
		swapFields(anotherPerson);

	return *this;
}

ostream& operator<<(ostream& out, const Person& person)
{
	person.information(out);

	return out;
}

Person::~Person()
{
	delete[] name;
	delete[] EGN;
	delete[] address;
}

void Person::swapFields(const Person& anotherPerson)
{
	this->name = anotherPerson.name;
	this->EGN = anotherPerson.EGN;
	this->address = anotherPerson.address;
	this->age = anotherPerson.age;
	this->sex = anotherPerson.sex;
	this->profession = anotherPerson.profession;
	this->income = anotherPerson.income;
}

void Person::validateString(const char* str) const
{
    if(!str)
        throw invalid_argument("You can not pass NULL as string value!");
}

void Person::validateIncome(double income) const
{
    if(income < 0)
        throw range_error("Income can not be negative!");
}

void Person::validateEGN(const char* EGN) const
{
    // Validate for NULL.
    validateString(EGN);
    // Validate length.
    short EGNLen = strlen(EGN);
    if(EGNLen != 10)
        throw length_error("EGN must be exactly 10 numbers long!");
    // Validate format. Checks if EGN is only numbers.
    for(short i = 0; i < EGNLen; ++i)
    {
        if(EGN[i] < '0' || EGN[i] > '9')
        {
            throw invalid_argument("EGN must be composed only by numbers!");
        }
    }
}

char* Person::getProfessionAsString() const
{
    switch(profession)
    {
        case Artist:
            return "Artist";
        case Musician:
            return "Musician";
        case Programmer:
            return "Programmer";
        case Doctor:
            return "Doctor";
        case Farmer:
            return "Farmer";
        case Mathematician:
            return "Mathematician";
        case Lawyer:
            return "Lawyer";
        default:
            return "Unemployed";
    }
}

void Person::setName(const char* name)
{
    validateString(name);
    this->name = new char[strlen(name)];
    strcpy(this->name, name);
}

void Person::setAddress(const char* address)
{
    validateString(address);
    this->address = new char[strlen(address)];
    strcpy(this->address, address);
}

void Person::setProfession(Profession profession)
{
	this->profession = profession;
}

void Person::setIncome(double income)
{
    validateIncome(income);
	this->income = income;
}

char* Person::getName() const
{
	return name;
}

char* Person::getEGN() const
{
    return EGN;
}

char* Person::getAddress() const
{
	return address;
}

Profession Person::getProfession() const
{
	return profession;
}

double Person::getIncome() const
{
	return income;
}

unsigned short Person::getAgeFromEGN() const
{
	short year = (short)(EGN[0] - '0') * 10 + (short)(EGN[1] - '0');

	return 100 - year + 13;
}

Sex Person::getSexFromEGN() const
{
	short number = (short)EGN[8];

	if(number % 2 == 0)
	{
		return Male;
	}

	return Female;
}

void Person::information(ostream& out = cout) const
{
	out << "Name: " << name << endl;
	out << "Age: " << age << endl;
	out << "Address: " << address << endl;
	out << "Sex: " << (sex == 0 ? "Male" : "Female") << endl;
	out << "EGN: " << EGN << endl;
	out << "Profession: " << getProfessionAsString() << endl;
	out << "Income: " << income << endl;
}
