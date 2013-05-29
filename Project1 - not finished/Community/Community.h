#ifndef COMMUNITY
#define COMMUNITY

#include "../Person/Person.h";

class Community
{
private:
    char* communityName;
    char* foundationDate;
    Person founder;
    long maxMembersCount;
    long membersCount;
    Person* members;

    void validateString(const char* str) const;
    void validatePeople(const Person* setOfPeople) const;
    void validateNumber(long num) const;
    void swapFields(const Community& anotherCommunity);
    bool doesElementExist(const char* EGN) const;
    long findSuitableIndex(const char* EGN) const;
    bool fits(unsigned left, unsigned right, unsigned value) const;
public:
    Community(const char* communityName, const char* foundationDate, const Person& founder, long maxMembersCount = 2);
    Community(const Community& anotherCommunity);
    Community& operator=(const Community& anotherCommunity);
    ~Community();

    char* getName() const;
    char* getFoundationDate() const;
    Person getFounder() const;
    long getMaxMembersCount() const;
    long getMembersCount() const;
    Person* getMembers() const;
    int getNumCommunities() const;

    void setName(const char* newName);
    void setFounder(const Person& theFounder);
    void setMembers(Person* members);

    bool addMember(const Person& person);
    bool removeMember(const char* EGN);
    bool isFull() const;
    bool isMember(const Person* person) const;
    bool isMember(const char* EGN) const;
    void information(ostream& out) const;
};

#endif // COMMUNITY
