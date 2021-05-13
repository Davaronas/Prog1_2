#include "std_lib_facilities.h"

// g++ ClassDefDrill.cpp -o a2.out

const int year_min = 0;
const int year_max = 150;

void CheckYear(int age)
{
    if (age <= year_min or age >= year_max) 
    {error("Year out of boundary");}
}

void CheckName(string name)
{
    for (int i = 0; i < name.length(); ++i)
    {
        if(!isalpha(name[i])) 
        {error("Name contains an invalid character");} 
    }
}

struct Person
{
private:
    string firstName;
    string surname;
    int age;

public:
	Person(string kn = "Goofy", string vn = "Mickey", int year = 63) : firstName(kn), surname(vn), age(year) 
    {
        CheckYear(age);
        CheckName(firstName);
        CheckName(surname);
    }

    int GetAge() const { return age; }

    string GetFullName() const { return firstName + " " + surname; }

    void SetFirstName(string fn) { firstName = fn; }
    void SetSurname(string sn) { surname = sn; }
    void SetAge(int a ) { age = a; }
};
	
ostream& operator<<(ostream& os, const Person& p)
{
    return os << p.GetFullName() << " " << p.GetAge() << endl;
}

istream& operator>>(istream& is, Person& p)
{
    string text_1;
    string text_2;
    int number;

    is >> text_1;
    CheckName(text_1);
    p.SetFirstName(text_1);
    
    is >> text_2;
    CheckName(text_2);
    p.SetSurname(text_2);
    
    is >> number;
    CheckYear(number);
    p.SetAge(number);
    
    return is;
}

int main()
try{
    
    Person defaultPerson;
    cout<<"Default: "<<defaultPerson<<endl; 
    
    
    cout << "Give first name and surname followed by a year. Do this twice" << endl;
    vector<Person> persons;

    for (int i = 0; i < 2; ++i)
    {
        Person _person;
    	cin >> _person;
    	persons.push_back(_person);
    }
    
    cout << endl;
    for (Person& p : persons) cout << p;

	return 0;
} catch (exception& e){
    cerr << e.what() << endl;
    return 2;
} catch (...){
    cerr << "Error" << endl;
    return 3;
}
