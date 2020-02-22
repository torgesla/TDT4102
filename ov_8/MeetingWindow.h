#ifndef GUI
#define GUI
#include "std_lib_facilities.h"
#include "Objects.h"
#include "GUI.h"
#include "Graph.h"
#include "Window.h"

using namespace Graph_lib;

class MeetingWindow : public Window
{
private:
    Button quitBtn;
    Button personNewBtn;

    In_box personName, personEmail;
    Vector_ref<Person> people;

    static constexpr int pad = 20;
    static constexpr int btnW = 100;
    static constexpr int btnH = 20;
    static constexpr int fieldW = 100;
    static constexpr int fieldH = 40;
    static constexpr int fieldPad = 50;

public:
    MeetingWindow(Point xy, int w, int h, const string &title);
    static void cb_quit(Address, Address pw);
    static void cb_new_person(Address, Address pw);
    void runWindow();
    void addPerson();
    Vector_ref<Person> getPeople();
};
#endif