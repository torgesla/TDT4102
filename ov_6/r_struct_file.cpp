#include "r_struct_file.h"
#include "Graph.h"
#include "Simple_window.h"

istream &operator>>(istream &is, Temps &t)
{
    string line;
    if (std::getline(is, line))
    {
        int index_of_tab = line.find('\t');
        t.max = stod(line.substr(0, index_of_tab));
        t.min = stod(line.substr(index_of_tab, line.size()));
    }
    return is;
}
void testTemps()
{
    ifstream temp_file{"temperatures.txt"};
    Temps t;
    temp_file >> t;
    cout << "Max: " << t.max << "\t";
    cout << "Min: " << t.min << endl;
}
vector<Temps> readWholeFile()
{
    ifstream temp_file{"temperatures.txt"};
    Temps temp_object;
    vector<Temps> temp_vector;

    while (!temp_file.eof())
    {
        temp_file >> temp_object;
        temp_vector.push_back(temp_object);
    }
    return temp_vector;
}
void buildGraphs(Graph_lib::Open_polyline &maxline, Graph_lib::Open_polyline &minline, vector<Temps> temps)
{
    int y_offset = 200, x_offset = 70, factor = 2;
    for (int i = 0; i < temps.size(); i++)
    {
        minline.add(Point{factor * i + x_offset, y_offset - factor * (int)round(temps[i].min)});
        maxline.add(Point{factor * i + x_offset, y_offset - factor * (int)round(temps[i].max)});
    }
}
void drawGraph()
{
    using namespace Graph_lib;
    vector<Temps> temps = readWholeFile();

    Simple_window win{Point{100, 100}, 500, 500, "Daglig min-/max temp"};
    Open_polyline maxLine, minLine;
    maxLine.set_color(Color::red);
    minLine.set_color(Color::blue);
    Text max{Point{0, 100}, "Max"};
    max.set_color(Graph_lib::Color::red);
    Text min{Point{0, 150}, "Min"};
    min.set_color(Graph_lib::Color::blue);
    buildGraphs(maxLine, minLine, temps);
    Axis x_axis{Axis::x, Point{50, 200}, 750, 12, "Months:"}; //Axis_orientation, point, length, number_of_notches, label
    Axis y_axis{Axis::y, Point{50, 350}, 300, 10, "Temperature:"};
    vector<Text> x_axis_marks;

    win.attach(max);
    win.attach(min);
    win.attach(x_axis);
    win.attach(y_axis);
    win.attach(maxLine);
    win.attach(minLine);
    win.wait_for_button();
}
