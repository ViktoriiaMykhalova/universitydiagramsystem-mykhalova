#include <iostream>   // підключаємо ввід/вивід
#include <vector>     // підключаємо vector
#include <string>     // підключаємо string
using namespace std;  // використовуємо простір імен std

// клас базової особи
class Person {
protected:
    string name; int age; // ім'я та вік
public:
    Person(const string& n, int a) :name(n), age(a) {} // конструктор
    virtual ~Person() {} // віртуальний деструктор
    virtual void getDetails()const { cout << "Name:" << name << ",Age:" << age << endl; } // показ деталей
    const string& getName()const { return name; } // повертає ім'я
};

// клас студента
class Student :public Person {
    int studentID; string major; // id та спеціальність
public:
    Student(const string& n, int a, int id, const string& m) :Person(n, a), studentID(id), major(m) {} // конструктор
    void registerForCourse(const string& c)const { cout << getName() << " registered for " << c << endl; } // реєстрація на курс
    void viewSchedule()const { cout << getName() << "'s schedule:[Software Engineering,Programming]" << endl; } // розклад
    void getDetails()const override { cout << "Name:" << getName() << ",Age:" << age << ",ID:" << studentID << ",Major:" << major << endl; } // деталі
};

// клас викладача
class Teacher :public Person {
    string post; vector<string> courses; // посада та список курсів
public:
    Teacher(const string& n, int a, const string& p) :Person(n, a), post(p) {} // конструктор
    void assignCourse(const string& c) { courses.push_back(c); cout << getName() << " assigned to " << c << endl; } // призначення курсу
    void getDetails()const override { cout << "Name:" << getName() << ",Age:" << age << ",Post:" << post << endl; } // деталі
};

// клас курсу
class Course {
    int courseID; string courseName; vector<string> enrolled; // id, назва, список студентів
public:
    Course(int i, const string& n) :courseID(i), courseName(n) {} // конструктор
    void addStudent(const string& s) { enrolled.push_back(s); cout << "Student " << s << " added to " << courseName << endl; } // додати студента
    const string& getCourseName()const { return courseName; } // повертає назву
};

// клас університету
class University {
    string name; vector<Student> students; vector<Teacher> teachers; vector<Course> courses; // назва, студенти, викладачі, курси
public:
    University(const string& n) :name(n) {} // конструктор
    void addStudent(const Student& s) { students.push_back(s); cout << "Student " << s.getName() << " added." << endl; } // додати студента
    void addTeacher(const Teacher& t) { teachers.push_back(t); cout << "Teacher " << t.getName() << " added." << endl; } // додати викладача
    void addCourse(const Course& c) { courses.push_back(c); cout << "Course " << c.getCourseName() << " added." << endl; } // додати курс
    void showDetails()const {
        cout << "University:" << name << "\nTotal Students:" << students.size()
            << "\nTotal Teachers:" << teachers.size()
            << "\nTotal Courses:" << courses.size() << endl;
    } // показати загальні дані
};

int main() {
    University uni("Kherson State University"); // створюємо університет
    Student s1("Viktoriia", 20, 101, "CS"), s2("Margo", 21, 102, "Physics"); // студенти
    Teacher t1("Dr. Poltoracliy", 45, "Professor"), t2("Dr. Lvov", 50, "Lecturer"); // викладачі
    Course c1(1, "Software Engineering"), c2(2, "Programming"); // курси
    uni.addStudent(s1); uni.addStudent(s2); // додаємо студентів
    uni.addTeacher(t1); uni.addTeacher(t2); // додаємо викладачів
    uni.addCourse(c1); uni.addCourse(c2);   // додаємо курси
    s1.registerForCourse("Software Engineering"); // реєструємо студента на курс
    s2.registerForCourse("Programming");          // реєструємо студента на курс
    t1.assignCourse("Software Engineering");       // викладач призначається на курс
    t2.assignCourse("Programming");                // викладач призначається на курс
    s1.viewSchedule(); s2.viewSchedule();          // показуємо розклад
    uni.showDetails(); // показуємо інформацію про університет
    return 0;
}