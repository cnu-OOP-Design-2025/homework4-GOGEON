#include "student_manager.h"
#include "student.h"

/* StudentManager */
int StudentManager::last_student_id = 1000;

void StudentManager::addStudent(char const* name, float midterm, float final) {
    int id = ++last_student_id;
    /* TODO */
    Student student(name, id, midterm, final);
    students[num_of_students++] = student;

}

void StudentManager::deleteStudent(int id) {
    /* TODO */
    int idx = findStudentByID(id);
    if (idx >= 0) {
        --num_of_students;
        for (int i = idx; i < num_of_students; ++i) {
            students[i] = students[i + 1];
        }
    }
}

void StudentManager::modifyStudent(const Student& student) {
    /* TODO */
    int idx = findStudentByID(student.getID());
    if (idx >= 0) {
        students[idx] = student;
    }
}

int StudentManager::findStudentByID(int id) const {
    /* TODO */
    for (int i = 0; i < num_of_students; i++){
        if(students[i].getID() == id){
            return i;
        }
    }
    return -1;
}

int StudentManager::findBestStudentInMidterm() const {
    /* TODO */
    Student bestStudent;
    bestStudent.updateRecord("", 0.0f, 0.0f);
    for(int i = 0; i < num_of_students; ++i){
        if(students[i].getRecord().getMidterm() > bestStudent.getRecord().getMidterm()){
            bestStudent = students[i];
        }
    }
    return bestStudent.getID();
}

int StudentManager::findBestStudentInFinal() const {
    /* TODO */
    Student bestStudent;
    bestStudent.updateRecord("", 0.0f, 0.0f);
    for(int i = 0; i < num_of_students; ++i){
        if(students[i].getRecord().getFinal() > bestStudent.getRecord().getFinal()){
            bestStudent = students[i];
        }
    }
    return bestStudent.getID();
}

int StudentManager::findBestStudent() const {
    /* TODO */
    Student bestStudent;
    bestStudent.updateRecord("", 0.0f, 0.0f);
    for(int i = 0; i < num_of_students; ++i){
        if(students[i].getRecord().getTotal() > bestStudent.getRecord().getTotal()){
            bestStudent = students[i];
        }
    }
    return bestStudent.getID();
}

float StudentManager::getMidtermAverage() const {
    /* TODO */
    float midtermavg = 0.0f;
    for(int i = 0; i < num_of_students; ++i){
        midtermavg += students[i].getRecord().getMidterm();
    }
    return midtermavg / num_of_students;
}

float StudentManager::getFinalAverage() const {
    /* TODO */
    float finalavg = 0.0f;
    for(int i = 0; i < num_of_students; ++i){
        finalavg += students[i].getRecord().getFinal();
    }
    return finalavg / num_of_students;
}

float StudentManager::getTotalAverage() const {
    /* TODO */
    float totalavg = 0.0f;
    for(int i = 0; i < num_of_students; ++i){
        totalavg += students[i].getRecord().getTotal();
    }
    return totalavg / num_of_students;
}

