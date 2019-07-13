#include <iostream>	
#include <String>;
using namespace std;

class Human
{
	string name;
	unsigned int age;
public:
	const string& get_name() const
	{
		return this->name;
	}
	unsigned int get_age() const
	{
		return this->age;
	}
	void set_name(string& name)
	{
		this->name = name;
	}
	void set_age(unsigned int age)
	{
		if (age < 1000)
		{
			this->age = age;
		}
	}
	Human(string name, unsigned int age) :name(name), age(age)
	{
		cout << "HConstructor:\t" << this << endl;
	}
	~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}
	void info()
	{
		cout << name << " " << age << "лет\n";
	}
};

class Student :public Human
{
	string speciality;
	unsigned int year;
	int karma;
public:
	const string& get_speciality() const
	{
		return this->speciality;
	}
	unsigned int get_year() const
	{
		return this->year;
	}
	int get_karma() const
	{
		return this->karma;
	}
	const string& set_speciality(const string& speciality)
	{
		return this->speciality = speciality;
	}
	unsigned int set_year(unsigned int year)
	{
		return this->year = year;
	}
	int set_karma(int karma)
	{
		return this->karma = karma;
	}
	Student(const string& name, unsigned int age,
		const string& speciality, unsigned int year = 1, int karma = 0) : Human(name, age)
	{
		this->speciality = speciality;
		this->year = year;
		this->karma = karma;
		cout << "SConstuctor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}
	void info()
	{
		Human::info();
		cout << "Специальность " << speciality <<", " << year << "-й курс, успеваемость " << karma << endl;
	}
};

class Teacher :public Human
{
	string speciality;
	int evil;
	unsigned int xp;
public:
	const string& get_speciality() const
	{
		return this->speciality;
	}
	unsigned int get_xp() const
	{
		return this->xp;
	}
	int get_evil() const
	{
		return this->evil;
	}
	const string& set_speciality(const string& speciality)
	{
		return this->speciality = speciality;
	}
	unsigned int set_xp(unsigned int xp)
	{
		return this->xp = xp;
	}
	int set_evil(int evil)
	{
		return this->evil = evil;
	}
	Teacher (const string& name, unsigned int age,
		const string& speciality, unsigned int xp = 0, int evil = 0) : Human(name, age)
	{
		this->speciality = speciality;
		this->xp = xp;
		this->evil = evil;
		cout << "TConstuctor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}
	void info()
	{
		Human::info();
		cout << "Специальность " << speciality << ", " << xp << "-летний опыт преподавания, злость: " << evil << "%"<< endl;
	}
	class Graduate :public Student
	{
		string diploma_theme;
	public:
		const string& get_diploma_theme() const
		{
			return this->diploma_theme;
		}
		const string& set_diploma_theme(const string& diploma_theme)
		{
			return this->diploma_theme = diploma_theme;
		}

	};
};

void main()
{
	setlocale(LC_ALL, "");
	Human h("Vasiliy", 20);
	h.info();

	Student durko("Дурко Василий", 20, "РПО");
	durko.info();

	Teacher pablo("Pablo Escobar", 40, "Распространение наркотиков", 25, 50);
	pablo.info();
}