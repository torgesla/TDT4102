#include "std_lib_facilities.h"
#include "Objects.h"
#include "Meeting.h"

int main()
{
	const Person torgeir("Torgeir", "email"); // Leader
	const Person sigurd("Sigurd", "email2");
	const Person joffa("Joffa", "email3");
	Meeting meeting(3, 1200, 1300, Trondheim, "Mote", &torgeir);
	meeting.addParticipant(&sigurd);
	meeting.addParticipant(&joffa);
	cout << meeting;

	keep_window_open();
}