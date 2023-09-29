#include <string.h>
#include <string>
#include <iostream>

using namespace std;

enum Gender
{
    MALE,
    FEMALE
};

class Man
{
protected:
    string name;
    int age;
    Gender gender;
    int weight;
public:
    Man()
    {
        name = "";
        age = 1;
        gender = MALE;
        weight = 1;
    }

    Man(string name_, int age_, Gender gender_, int weight_)
    {
        name = name_;
        age = age_;
        gender = gender_;
        weight = weight_;
    }

    string GetName()
    {
        return name;
    }

    int GetAge()
    {
        return age;
    }

    Gender GetGender()
    {
        return gender;
    }

    int GetWeight()
    {
        return weight;
    }

    void SetName(string name_)
    {
        name = name_;
    }

    void SetAge(int age_)
    {
        age = age_;
    }

    void SetGender(Gender gender_)
    {
        gender = gender_;
    }

    void SetWeight(int weight_)
    {
        weight = weight_;
    }

    virtual void Read()
    {
        string gInfo;
        cin >> name >> age >> gInfo;
        if (gInfo == "F") gender = FEMALE;
        else if (gInfo == "M") gender = MALE;
        cin >> weight;
    }
};

class Student : public Man
{
private:
    int studyYear;
public:
    Student()
    {
        studyYear = 1;
    }

    Student(string name_, int age_, Gender gender,
        int weight_, int studyYear_) : Man(name_, age_, gender, weight_)
    {
        studyYear = studyYear_;
    }

    int GetStudyYear()
    {
        return studyYear;
    }

    void SetStudyYear(int studyYear_)
    {
        studyYear = studyYear_;
    }

    void Read() override
    {
        Man::Read();
        cin >> studyYear;
    }

    void UpYear()
    {
        studyYear += 1;
    }
};

string manToString(Man man)
{
    char g = (man.GetGender() == MALE) ? 'M' : 'F';
    return man.GetName() + ' ' + to_string(man.GetAge()) + ' ' + g + ' ' + to_string(man.GetWeight());
}

string studentToString(Student student)
{
    return manToString((Man)student) + ' ' + to_string(student.GetStudyYear());
}

int main()
{
    Man man;
    Student student;

    man.Read();
    student.Read();

    cout << manToString(man) + '\n';
    cout << studentToString(student) + '\n';

    while (true)
    {
        int op;
        cin >> op;
        if (op == 8)
        {
            student.UpYear();
            cout << studentToString(student) + '\n';
            continue;
        }
        else if (op == 0)
        {
            break;
        }

        string arg;
        cin >> arg;

        switch (op)
        {
        case 1:
            man.SetName(arg);
            break;
        case 2:
            man.SetAge(stoi(arg));
            break;
        case 3:
            man.SetWeight(stoi(arg));
            break;
        case 4:
            student.SetName(arg);
            break;
        case 5:
            student.SetAge(stoi(arg));
            break;
        case 6:
            student.SetWeight(stoi(arg));
            break;
        case 7:
            student.SetStudyYear(stoi(arg));
            break;
        };
        if (op <= 3) cout << manToString(man) + '\n';
        else cout << studentToString(student) + '\n';
    }
}
