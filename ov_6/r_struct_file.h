#ifndef R_STRUCT_FILE
#define R_STRUCT_FILE

#include "std_lib_facilities.h"
#include "Graph.h"
struct Temps
{
    double max;
    double min;
};
istream &operator>>(istream &is, Temps &t);
void testTemps();
vector<Temps> readWholeFile();
void drawGraph();
void buildGraphs(Graph_lib::Open_polyline &maxline, Graph_lib::Open_polyline &minline, vector<Temps> temps);
#endif