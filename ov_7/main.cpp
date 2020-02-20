#include "Simple_window.h"
#include "Emoji.h"
#include "Classes.h"
#include "std_lib_facilities.h"

// Size of window and emoji radius
constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = 50;

int main()
{
	/* 	using namespace Graph_lib;

	const Point tl{100, 100};
	const string win_label{"Emoji factory"};
	Simple_window win{tl, xmax, ymax, win_label};
	win.waitforbutton();
 */
	testAnimal();
	keep_window_open();
	/* TODO:
	 *  - initialize emojis
	 *  - connect emojis to window
	 **/
}
