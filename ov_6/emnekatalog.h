#ifndef EMNEKATALOG
#define EMNEKATALOG
#include "std_lib_facilities.h"

class CourseCatalog
{
private:
    std::map<std::string, std::string> emner_map;

public:
    friend std::ostream &operator<<(std::ostream &, const CourseCatalog &cc);
    void addCourse(string emnekode, string emnenavn); //– legg til et kurs med emnekode og emnenavn.
    void removeCourse(string emnekode);               //– fjern et kurs gitt av emnekoden.
    std::string getCourse(string emnekode);           //- finn emnenavnet til et kurs med en gitt emnekode.
};

void testAddSubjects();
#endif
