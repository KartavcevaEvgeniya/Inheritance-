#include <iostream>
#include <cstring>
using namespace std;

class Person
{
protected:
    char* name = nullptr;
    int age = 0;

public:
    Person() = default;
    Person(const char* Name, int Age)
    {
        cout << "Construct Person\n";
        name = new char[strlen(Name) + 1];
        strcpy(name, Name);
        age = Age;
    }

    void Print() const
    {
        cout << "Output Person\n";
        cout << "Name: " << (name ? name : "") << endl;
        cout << "Age: " << age << endl;
    }

    void Input()
    {
        char buff[20];
        cin.getline(buff, 20);
        delete[] name;
        name = new char[strlen(buff) + 1];
        strcpy(name, buff);

        cin >> age;
    }

    ~Person()
    {
        if (name != nullptr)
		{
			delete[] name;
		}
        cout << "Destruct Person\n";
    }

    Person(const Person&) = delete;
    Person& operator=(const Person&) = delete;
};

class Student : public Person
{
char* Univer;
public:
    Student()= default;
    Student(const char* n, int a, const char* u) : Person(n,a)
    {
        cout << "Construct Student\n";
        Univer = new char[strlen(u)+1];
        strcpy(Univer, u);
    }
    ~Student()
    {
        delete[]Univer;
        cout << "Destruct Student\n";
    }
    void Print() const
    {
        cout << "Output Student\n";
        //cout << "Name: " << name << endl;
        //cout << "Age: " << age << endl;
        Person::Print();
        cout << "University: " << Univer << endl;
    }

    void Input(const char* u)
    {
        delete[]Univer;
        Univer = new char[strlen(u)+1];
        strcpy(Univer, u);
        Person::Input();
    }
};

//Aspirant
class Aspirant : public Student
{
    char* topic = nullptr;
public:
    Aspirant() = default;
    Aspirant(const char* n, int a, const char* u, const char* t) : Student(n, a, u)
    {
        cout << "Construct Aspirant\n";
        topic = new char[strlen(t) + 1];
        strcpy(topic, t);
    }
    
    ~Aspirant()
    {
        delete[] topic;
        cout << "Destruct Aspirant\n";
    }

    void Print() const
    {
        cout << "Output Aspirant\n";
        Student::Print();
        cout << "Dissertation topic: " << (topic ? topic : "") << endl;
    }

    void Input(const char* t)
    {
        delete[] topic;
        topic = new char[strlen(t) + 1];
        strcpy(topic, t);
    }
};

//Закордонний паспорт Passport
class ForeignPassport : public Passport
{
    char* foreignNumber;
    char* visa;

public:
    ForeignPassport()
    {
        foreignNumber = nullptr;
        visa = nullptr;
    }

    ForeignPassport(const char* n, const char* s, const char* b, const char* num, const char* fn, const char* v) : Passport(n, s, b, num)
    {
        cout << "Construct ForeignPassport\n";

        foreignNumber = new char[strlen(fn) + 1];
        strcpy(foreignNumber, fn);

        visa = new char[strlen(v) + 1];
        strcpy(visa, v);
    }

    void Print() const
    {
        cout << "Output ForeignPassport\n";
        Passport::Print();
        cout << "Foreign passport number: " << (foreignNumber ? foreignNumber : "") << endl;
        cout << "Visa: " << (visa ? visa : "") << endl;
    }

    ~ForeignPassport()
    {
        delete[] foreignNumber;
        delete[] visa;

        cout << "Destruct ForeignPassport\n";
    }
};

int main()
{
    Person a("Oleg", 19);
    a.Print();
    cout << endl;

    Student b("Anna", 20, "Politex");
    b.Print();
    cout << endl;

    Aspirant c("Ivan", 25, "ONU", "Artificial Intelligence");
    c.Print();
    cout << endl;

    return 0;
}