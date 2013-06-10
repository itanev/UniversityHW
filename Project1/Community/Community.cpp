#include <stdexcept>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include "Community.h"

using namespace std;

Community::Community(const char* communityName, const char* foundationDate,
                     Person& founder, long maxMembersCount)
{
    setName(communityName);

    validateString(foundationDate);
    this->foundationDate = new char[strlen(foundationDate) + 1];
    strcpy(this->foundationDate, foundationDate);

    setFounder(founder);

    validateNumber(maxMembersCount);

    this->maxMembersCount = maxMembersCount;
    this->membersCount = 0;
}

Community::Community(const Community& anotherCommunity)
{
    swapFields(anotherCommunity);
}

Community& Community::operator=(const Community& anotherCommunity)
{
    if(this != &anotherCommunity)
        swapFields(anotherCommunity);

    return *this;
}

void Community::validateString(const char* str) const
{
    if(!str)
        throw invalid_argument("You can not pass NULL as string value!");
}

void Community::validateNumber(long num) const
{
    if(num < 0)
        throw range_error("Members count can not be negative!");
}

void Community::validatePeople(const Person* setOfPeople) const
{
    if(!setOfPeople)
        throw invalid_argument("You can not pass NULL as person value!");
}

void Community::swapFields(const Community& anotherCommunity)
{
    this->communityName = new char[strlen(anotherCommunity.communityName) + 1];
    strcpy(this->communityName, anotherCommunity.communityName);

    this->foundationDate = new char[strlen(anotherCommunity.foundationDate) + 1];
    strcpy(this->foundationDate, anotherCommunity.foundationDate);

    this->founder = anotherCommunity.founder;
    this->maxMembersCount = anotherCommunity.maxMembersCount;
    this->membersCount = anotherCommunity.membersCount;
}

char* Community::getName() const
{
    return (char*)this->communityName;
}

char* Community::getFoundationDate() const
{
    return (char*)this->foundationDate;
}

Person Community::getFounder() const
{
    return *founder;
}

long Community::getMaxMembersCount() const
{
    return this->maxMembersCount;
}

long Community::getMembersCount() const
{
    return this->membersCount;
}

vector<Person> Community::getMembers() const
{
    vector<Person> listOfMembers;

    map<char*, Person>::const_iterator iter;
    for (iter = members.begin(); iter != members.end(); ++iter)
        listOfMembers.push_back(iter->second);

    return listOfMembers;
}

void Community::setName(const char* newName)
{
    validateString(newName);
    this->communityName = new char[strlen(newName) + 1];
    strcpy(this->communityName, newName);
}

void Community::setFounder(Person& theFounder)
{
    validatePeople(&theFounder);
    founder = &theFounder;
}

bool Community::isFull() const
{
    if(this->membersCount == maxMembersCount)
        return true;

    return false;
}

bool Community::isMember(const Person& person) const
{
    validatePeople(&person);
    return isMember(person.getEGN());
}

bool Community::isMember(const char* EGN) const
{
    validateString(EGN);
    if(members.count((char*)EGN) > 0)
        return true;
    return false;
}

bool Community::addMember(const Person& person)
{
    validatePeople(&person);
    if(members.count(person.getEGN()) == 0 && !isFull())
    {
        membersCount++;
        members.insert(std::pair<char*, Person>(person.getEGN(), person));
        return true;
    }

    return false;
}

bool Community::removeMember(const char* EGN)
{
    validateString(EGN);
    if(members.erase((char*)EGN))
    {
        membersCount--;
        return true;
    }

    return false;
}

void Community::information(ostream& out = cout) const
{
    out << this->communityName << endl;
    out << this->foundationDate << endl;
    out << *founder << endl;
    map<char*, Person>::const_iterator iter;

    for (iter = members.begin(); iter != members.end(); ++iter)
        out << iter->second << endl;
}

void Community::operator+=(const Person& other)
{
    addMember(other);
}

void Community::operator-=(const Person& other)
{
    removeMember(other.getEGN());
}

vector<Person> Community::operator +(const Community& other)
{
    vector<Person> resultMembers;

    map<char*, Person>::const_iterator iter;
    for (iter = members.begin(); iter != members.end(); ++iter)
        resultMembers.push_back(iter->second);

    for (iter = other.members.begin(); iter != other.members.end(); ++iter)
    {
        if(!isMember(iter->second))
            resultMembers.push_back(iter->second);
    }

    return resultMembers;
}

vector<Person> Community::operator -(const Community& other)
{
    vector<Person> resultMembers;

    map<char*, Person>::const_iterator iter;
    for (iter = members.begin(); iter != members.end(); ++iter)
    {
        if(!other.isMember(iter->second))
            resultMembers.push_back(iter->second);
    }

    for (iter = other.members.begin(); iter != other.members.end(); ++iter)
    {
        if(!isMember(iter->second))
            resultMembers.push_back(iter->second);
    }

    return resultMembers;
}

vector<Person> Community::operator /(const Community& other)
{
    vector<Person> resultMembers;

    map<char*, Person>::const_iterator iter;
    for (iter = members.begin(); iter != members.end(); ++iter)
    {
        if(other.isMember(iter->second))
            resultMembers.push_back(iter->second);
    }

    return resultMembers;
}

vector<Person> Community::operator *(const Community& other)
{
    vector<Person> resultMembers;

    map<char*, Person>::const_iterator iter;
    for (iter = other.members.begin(); iter != other.members.end(); ++iter)
    {
        if(!isMember(iter->second))
            resultMembers.push_back(iter->second);
    }

    return resultMembers;
}

bool Community::operator ==(const Community& other)
{
    if(other.membersCount != membersCount) return false;

    map<char*, Person>::const_iterator iter;
    for (iter = members.begin(); iter != members.end(); ++iter)
    {
        if(!other.isMember(iter->second))
            return false;
    }

    return true;
}

bool Community::operator <(const Community& other)
{
    map<char*, Person>::const_iterator iter;
    for (iter = members.begin(); iter != members.end(); ++iter)
    {
        if(!other.isMember(iter->second))
            return false;
    }

    return true;
}

ostream& operator <<(ostream& out, const Community& other)
{
    other.information(out);
    return out;
}

Community::~Community()
{
    delete[] communityName;
    delete[] foundationDate;
}
