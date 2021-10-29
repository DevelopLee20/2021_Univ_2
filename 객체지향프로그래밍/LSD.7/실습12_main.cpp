#include "실습12_student.h"
#include "실습12_lab.h"

int main(void){
    Lab lab("영상처리");
    Student *p = new Student("김철수", "011-123-4567");

    lab.setChief(p);
    lab.setManager(p);
    lab.print();

    delete p;

    return 0;
}