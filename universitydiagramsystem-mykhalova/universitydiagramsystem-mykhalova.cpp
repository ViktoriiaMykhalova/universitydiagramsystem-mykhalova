#include <iostream>   // ��������� ���/����
#include <vector>     // ��������� vector
#include <string>     // ��������� string
using namespace std;  // ������������� ������ ���� std

// ���� ������ �����
class Person {
protected:
    string name; int age; // ��'� �� ��
public:
    Person(const string& n, int a) :name(n), age(a) {} // �����������
    virtual ~Person() {} // ���������� ����������
    virtual void getDetails()const { cout << "Name:" << name << ",Age:" << age << endl; } // ����� �������
    const string& getName()const { return name; } // ������� ��'�
};

// ���� ��������
class Student :public Person {
    int studentID; string major; // id �� ������������
public:
    Student(const string& n, int a, int id, const string& m) :Person(n, a), studentID(id), major(m) {} // �����������
    void registerForCourse(const string& c)const { cout << getName() << " registered for " << c << endl; } // ��������� �� ����
    void viewSchedule()const { cout << getName() << "'s schedule:[Software Engineering,Programming]" << endl; } // �������
    void getDetails()const override { cout << "Name:" << getName() << ",Age:" << age << ",ID:" << studentID << ",Major:" << major << endl; } // �����
};

// ���� ���������
class Teacher :public Person {
    string post; vector<string> courses; // ������ �� ������ �����
public:
    Teacher(const string& n, int a, const string& p) :Person(n, a), post(p) {} // �����������
    void assignCourse(const string& c) { courses.push_back(c); cout << getName() << " assigned to " << c << endl; } // ����������� �����
    void getDetails()const override { cout << "Name:" << getName() << ",Age:" << age << ",Post:" << post << endl; } // �����
};

// ���� �����
class Course {
    int courseID; string courseName; vector<string> enrolled; // id, �����, ������ ��������
public:
    Course(int i, const string& n) :courseID(i), courseName(n) {} // �����������
    void addStudent(const string& s) { enrolled.push_back(s); cout << "Student " << s << " added to " << courseName << endl; } // ������ ��������
    const string& getCourseName()const { return courseName; } // ������� �����
};

// ���� �����������
class University {
    string name; vector<Student> students; vector<Teacher> teachers; vector<Course> courses; // �����, ��������, ���������, �����
public:
    University(const string& n) :name(n) {} // �����������
    void addStudent(const Student& s) { students.push_back(s); cout << "Student " << s.getName() << " added." << endl; } // ������ ��������
    void addTeacher(const Teacher& t) { teachers.push_back(t); cout << "Teacher " << t.getName() << " added." << endl; } // ������ ���������
    void addCourse(const Course& c) { courses.push_back(c); cout << "Course " << c.getCourseName() << " added." << endl; } // ������ ����
    void showDetails()const {
        cout << "University:" << name << "\nTotal Students:" << students.size()
            << "\nTotal Teachers:" << teachers.size()
            << "\nTotal Courses:" << courses.size() << endl;
    } // �������� ������� ���
};

int main() {
    University uni("Kherson State University"); // ��������� ����������
    Student s1("Viktoriia", 20, 101, "CS"), s2("Margo", 21, 102, "Physics"); // ��������
    Teacher t1("Dr. Poltoracliy", 45, "Professor"), t2("Dr. Lvov", 50, "Lecturer"); // ���������
    Course c1(1, "Software Engineering"), c2(2, "Programming"); // �����
    uni.addStudent(s1); uni.addStudent(s2); // ������ ��������
    uni.addTeacher(t1); uni.addTeacher(t2); // ������ ����������
    uni.addCourse(c1); uni.addCourse(c2);   // ������ �����
    s1.registerForCourse("Software Engineering"); // �������� �������� �� ����
    s2.registerForCourse("Programming");          // �������� �������� �� ����
    t1.assignCourse("Software Engineering");       // �������� ������������ �� ����
    t2.assignCourse("Programming");                // �������� ������������ �� ����
    s1.viewSchedule(); s2.viewSchedule();          // �������� �������
    uni.showDetails(); // �������� ���������� ��� ����������
    return 0;
}