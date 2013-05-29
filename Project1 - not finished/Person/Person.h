#ifndef PERSON
#define PERSON

#include "Sex.h"
#include "Profession.h"

using namespace std;

class Person
{
private:
	char* name;
	char* EGN;
	char* address;
	unsigned short age;
	Sex sex;
	Profession profession;
	double income;

	unsigned short getAgeFromEGN() const;
	Sex getSexFromEGN() const;
	void swapFields(const Person& anotherPerson);
	char* getProfessionAsString() const;
	void validateEGN(const char* EGN) const;
	void validateIncome(double income) const;
	void validateString(const char* str) const;
public:
    Person();
	Person(const char *name, const char* EGN, const char* address, Profession profession, double income);
	Person(const Person& anotherPerson);
	Person& operator=(const Person& anotherPerson);
	friend ostream& operator<<(ostream& out, const Person& person);
	~Person();

	void setName(const char* name);
	void setAddress(const char* address);
	void setProfession(Profession profession);
	void setIncome(double income);

	char* getName() const;
	char* getEGN() const;
	char* getAddress() const;
	Profession getProfession() const;
	double getIncome() const;

	void information(ostream& out) const;
};

#endif
