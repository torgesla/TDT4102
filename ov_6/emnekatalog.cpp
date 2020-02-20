#include "std_lib_facilities.h"
#include "emnekatalog.h"

std::ostream &operator<<(std::ostream &os, const CourseCatalog &cc)
{
    for (auto fag : cc.emner_map)
    {
        os << fag.first << ": " << fag.second << endl; //Write to output stream
    }
    return os;
}
void CourseCatalog::addCourse(string emnekode, string emnenavn)
{
    emner_map.insert(make_pair(emnekode, emnenavn));
}
void CourseCatalog::removeCourse(string emnekode)
{
    emner_map.erase(emnekode);
}
std::string CourseCatalog::getCourse(string emnekode)
{
    return emner_map[emnekode];
}
void testAddSubjects()
{
    CourseCatalog cc = CourseCatalog();
    cc.addCourse("TDT4110", "Informasjonsteknologi grunnkurs");
    cc.addCourse("TDT4102", "Prosedyre- og objektorientert programmering");
    cc.addCourse("TMA4100", "Matematikk 1");

    cc.addCourse("TDT4102", "C++");

    cout << cc;
}
