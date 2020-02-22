#include "MeetingWindow.h"
MeetingWindow::MeetingWindow(Point xy, int w, int h, const string &title) : Window(xy, w, h, title),
                                                                            quitBtn{Point{x_max() - btnW, 0}, btnW, btnH, "QUIIIT", cb_quit},
                                                                            personNewBtn{Point{fieldPad, 3 * pad + 2 * fieldH}, btnW, btnH, "Add person", cb_new_person},
                                                                            personName{Point{fieldPad, pad}, fieldW, fieldH, "Name"},
                                                                            personEmail{Point{fieldPad, 2 * pad + fieldH}, fieldW, fieldH, "Email"}
{
    attach(quitBtn);
    attach(personNewBtn);
    attach(personName);
    attach(personEmail);
}

void MeetingWindow::cb_quit(Address, Address pw)
{
    reference_to<MeetingWindow>(pw).hide();
}
void MeetingWindow::cb_new_person(Address, Address pw)
{
    reference_to<MeetingWindow>(pw).addPerson();
}
void MeetingWindow::addPerson()
{
    people.push_back(new Person{personName.get_string(), personEmail.get_string()});
    personName.clear_value();
    personEmail.clear_value();
}
Vector_ref<Person> MeetingWindow::getPeople() { return people; }