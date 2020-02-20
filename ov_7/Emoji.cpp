/* #include "Emoji.h"
#include "std_lib_facilities.h"
*/
#include "Emoji.h"
#include "std_lib_facilities.h"
Face::Face(Point c, int r, Color color)
{
    face.set_fill_color(color);
}
void Face::attach_to(Graph_lib::Window &window)
{
    window.attach(face);
}