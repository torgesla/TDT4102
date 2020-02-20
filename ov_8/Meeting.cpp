#include "Meeting.h"
set<const Meeting *> Meeting::meetings;

ostream &operator<<(ostream &os, const Campus &campus)
{
    os << campus_vec[campus] << endl;
    return os;
}
int Meeting::getDay() const { return day; }
int Meeting::getStartTime() const { return startTime; }
int Meeting::getEndTime() const { return endTime; }
Campus Meeting::getLocation() const { return location; }
string Meeting::getSubject() const { return subject; }
Person Meeting::getLeader() const { return *leader; }
void Meeting::addParticipant(const Person *person) { participants.insert(person); }

Meeting::Meeting(int day, int startTime, int endTime, Campus location, string subject, const Person *leader) : day(day), startTime(startTime), endTime(endTime),
                                                                                                               location(location), subject(subject), leader(leader)
{
    meetings.insert(this);
    addParticipant(leader);
}
Meeting::~Meeting()
{
    meetings.erase(this);
}
vector<string> Meeting::getParticipantList() const
{
    vector<string> participants_vector;
    for (auto participant : participants)
    {
        participants_vector.push_back(participant->getName());
    }
    return participants_vector;
}
string Meeting::printParticipants() const
{
    string out_string = "Participants:\n";
    for (auto it = participants.begin(); it != participants.end(); ++it)
    {
        out_string += "\t" + (*it)->getName() + "\n";
    }
    return out_string;
}
ostream &operator<<(ostream &os, const Meeting &meeting)
{
    os << meeting.getSubject() << campus_vec[meeting.getLocation()] << to_string(meeting.getStartTime()) << to_string(meeting.getEndTime()) << meeting.getLeader().getName() << endl
       << meeting.printParticipants();
    return os;
}
vector<const Person *> Meeting::findPotentialCoDriving() const //skal denne kun finne personer på this som har plass til folk på andre møter,
                                                               //eller sjekke for alle møter? Kunne vært static?
{
    set<const Person *> potentialdrivers;
    for (auto meeting_pointer : meetings)
    {
        for (auto meeting_pointer2 : meetings)
        {
            bool same_location = meeting_pointer->getLocation() == meeting_pointer2->getLocation();
            bool less_than_hour_start = abs(meeting_pointer->getStartTime() - meeting_pointer2->getStartTime()) <= 100; //e.g 1900 - 1800
            bool less_than_hour_end = abs(meeting_pointer->getEndTime() - meeting_pointer2->getEndTime()) <= 100;

            if (same_location && less_than_hour_start && less_than_hour_end)
            {
                for (auto participant_pointer : meeting_pointer->participants)
                {
                    if (participant_pointer->hasAvailableSeats())
                    {
                        potentialdrivers.insert(participant_pointer);
                    }
                }
            }
        }
    }
    vector<const Person *> potential_vector(potentialdrivers.begin(), potentialdrivers.end()); //Convert set to vector to remove duplicates
    return potential_vector;
}