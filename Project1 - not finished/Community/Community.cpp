#include <stdexcept>
#include <cstring>
#include <stdlib.h>
#include "Community.h"

Community::Community(const char* communityName, const char* foundationDate,
                      const Person& founder, long maxMembersCount)
{
    setName(communityName);

    validateString(foundationDate);
    this->foundationDate = new char[strlen(foundationDate)];
    strcpy(this->foundationDate, foundationDate);

    setFounder(founder);

    validateNumber(maxMembersCount);
    this->maxMembersCount = maxMembersCount;

    this->members = new Person[maxMembersCount];
}

Community::Community(const Community& anotherCommunity)
{
    swapFields(anotherCommunity);
}

Community& Community::operator=(const Community& anotherCommunity)
{
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
    this->communityName = anotherCommunity.communityName;
    this->foundationDate = anotherCommunity.foundationDate;
    this->founder = anotherCommunity.founder;
    this->maxMembersCount = anotherCommunity.maxMembersCount;
    this->membersCount = anotherCommunity.membersCount;
    this->members = anotherCommunity.members;
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
    return this->founder;
}

long Community::getMaxMembersCount() const
{
    return this->maxMembersCount;
}

long Community::getMembersCount() const
{
    return this->membersCount;
}

Person* Community::getMembers() const
{
    return this->members;
}

void Community::setName(const char* newName)
{
    validateString(newName);
    this->communityName = new char[strlen(newName)];
    strcpy(this->communityName, newName);
}

void Community::setFounder(const Person& theFounder)
{
    validatePeople(&theFounder);
    this->founder = theFounder;
}

void Community::setMembers(Person* members)
{
    validatePeople(members);
    this->members = members;
}

bool Community::isFull() const
{
    if(this->membersCount == maxMembersCount)
        return true;

    return false;
}

bool Community::doesElementExist(const char* EGN) const
{
    int imin = 0,
        imax = this->membersCount;

    int egn = atoi(EGN);

    while(true)
    {
        int imid = (imin + imax) / 2;
        unsigned currEGN = atoi(this->members[imid].getEGN());

        if(currEGN < egn)
            imin = imid + 1;
        else if(currEGN > egn)
            imax = imid - 1;
        else
            return true;
    }

    return false;
}

long Community::findSuitableIndex(const char* EGN) const
{
    int imin = 0,
        imax = this->membersCount;

    int egn = atoi(EGN);
    unsigned neighbourElement = 0;
    long neighbourElementIndex = 0;

    while(true)
    {
        int imid = (imin + imax) / 2;
        unsigned centralMemberEGN = atoi(this->members[imid].getEGN());

        if(centralMemberEGN < egn)
        {
            neighbourElement = atoi(this->members[imid+1].getEGN());
            if(fits(centralMemberEGN, neighbourElement, egn))
                return imid + 1;
        }
        else
        {
            neighbourElement = atoi(this->members[imid-1].getEGN());

            if(fits(neighbourElement, centralMemberEGN, egn))
                return imid;
        }
    }

    return 0;
}

bool Community::fits(unsigned left, unsigned right, unsigned value) const
{
    if(value >= left && value <= right)
        return true;
    else
        return false;
}

bool Community::isMember(const Person* person) const
{
    return doesElementExist(person->getEGN());
}

bool Community::isMember(const char* EGN) const
{
    return doesElementExist(EGN);
}

bool Community::addMember(const Person& person)
{
    if(isMember(person.getEGN()))
        return false;

    if(isFull())
    {
        Person* people = members;
        this->maxMembersCount *= 2;

        this->members = new Person[maxMembersCount];

        for(long i = 0; i < this->membersCount; ++i)
        {
            members[i] = people[i];
        }

        delete[] people;
    }

    if(membersCount == 1)
    {
        Person currMember = members[0];
        if(atoi(currMember.getEGN()) > atoi(person.getEGN()))
        {
            Person* people = members;
            members = new Person[maxMembersCount];

            people[0] = person;
            people[1] = currMember;
        }
    }
    else
    {
        Person* people = members;
        members = new Person[maxMembersCount];

        long index = findSuitableIndex(person.getEGN());

        for(long i = 0; i < index; ++i)
            members[i] = people[i];

        members[index] = person;

        for(long i = index + 1; i <= membersCount; ++i)
            members[i] = people[i];

        delete[] people;
    }
}

Community::~Community()
{
    delete[] communityName;
    delete[] foundationDate;
    delete[] members;
}
