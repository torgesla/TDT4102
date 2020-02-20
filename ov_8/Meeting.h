#ifndef MEETING
#define MEETING
#include "std_lib_facilities.h"
#include "Objects.h"
enum Campus
{
    Trondheim,
    Ålesund,
    Gjøvik
};
const vector<string> campus_vec{"Trondheim", "Ålesund", "Gjøvik"};
class Meeting
{
private:
    int day;
    int startTime;
    int endTime;
    Campus location;
    string subject;
    const Person *leader;
    set<const Person *> participants;
    static set<const Meeting *> meetings;

public:
    int getDay() const, getStartTime() const, getEndTime() const;
    Campus getLocation() const;
    string getSubject() const;
    Person getLeader() const;
    void addParticipant(const Person *person);
    Meeting(int day, int startTime, int endTime, Campus location, string subject, const Person *leader);
    ~Meeting();
    vector<string> getParticipantList() const;
    string Meeting::printParticipants() const;
    vector<const Person *> findPotentialCoDriving() const;
};
ostream &operator<<(ostream &os, const Campus &campus);
ostream &operator<<(ostream &os, const Meeting &meeting);
#endif