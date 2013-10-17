#ifndef COMMUNITY
#define COMMUNITY

#include <map>
#include "../Person/Person.h";

struct cmp_str
{
   bool operator()(char *a, char *b) const
   {
      return std::strcmp(a, b) < 0;
   }
};

class Community
{
private:
    char* communityName;
    char* foundationDate;
    Person* founder;
    long maxMembersCount;
    long membersCount;
    map<char*, Person, cmp_str> members;

    void validateString(const char* str) const;
    void validatePeople(const Person* setOfPeople) const;
    void validateNumber(long num) const;
    void swapFields(const Community& anotherCommunity);
public:
    Community(const char* communityName, const char* foundationDate, Person& founder, long maxMembersCount = 2);
    Community(const Community& anotherCommunity);
    Community& operator=(const Community& anotherCommunity);
    ~Community();

    char* getName() const;
    char* getFoundationDate() const;
    Person getFounder() const;
    long getMaxMembersCount() const;
    long getMembersCount() const;
    int getNumCommunities() const;
    vector<Person> getMembers() const;

    void setName(const char* newName);
    void setFounder(Person& theFounder);

    bool addMember(const Person& person);
    bool removeMember(const char* EGN);
    bool isFull() const;
    bool isMember(const Person& person) const;
    bool isMember(const char* EGN) const;
    void information(ostream& out) const;

    void operator +=(const Person& other);
    void operator -=(const Person& other);
    bool operator ==(const Community& other);
    bool operator <(const Community& other);
    vector<Person> operator +(const Community& other);
    vector<Person> operator -(const Community& other);
    vector<Person> operator *(const Community& other);
    vector<Person> operator /(const Community& other);
};

ostream& operator <<(ostream& out, const Community& other);

#endif // COMMUNITY
