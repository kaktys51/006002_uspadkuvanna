#include <iostream>
#include <string>
#include <ctime>

using std::cout;
using std::cin;

class Person
{
protected:
	int idNum;
	std::string firstName;
	std::string lastName;
	int passportID;
	std::tm birthday;
	std::string notes;
public:
	Person() {};
	Person(int id, std::string name, std::string last, int passID):
		idNum(id), firstName(name), lastName(last), passportID(passID)
	{
		setBirthday();
	}
	void setID()
	{
		cout << "Enter ID number:" << std::endl;
		cin >> idNum;
	}
	void setFirstName()
	{
		cout << "Enter first name:" << std::endl;
		cin.ignore();
		std::getline(cin, firstName);
	}
	void setLastName()
	{
		cout << "Enter last name:" << std::endl;
		cin.ignore();
		std::getline(cin, lastName);
	}
	void setPassportID()
	{
		cout << "Enter passport id:" << std::endl;
		cin >> passportID;
	}
	void setBirthday()
	{
		int birthDay;
		int birthMonth;
		int birthYear;

		cout << "Enter your day of birth: " << std::endl;
		cin >> birthDay;
		cin.ignore();
		cout << "Enter your month of birth: " << std::endl;
		cin >> birthMonth;
		cin.ignore();
		cout << "Enter your year of birth: " << std::endl;
		cin >> birthYear;

		birthday.tm_year = birthYear - 1900;
		birthday.tm_mon = birthMonth - 1;
		birthday.tm_mday = birthDay;

	}
	void setNotes()
	{
		cout << "Type some notes (optional): " << std::endl;
		cin.ignore();
		std::getline(cin, notes);
	}
	int getID()
	{
		return idNum;
	}
	std::string getFirtName()
	{
		return firstName;
	}
	std::string getLastName()
	{
		return lastName;
	}
	int getPassportID()
	{
		return passportID;
	}
	std::string getBirthday() const
	{
		char bday[100];
		std::strftime(bday, 100, "%d-%m-%Y", &birthday);
		return std::string(bday);
	}
	void printNote()
	{
		cout << notes << std::endl;
	}
};

class Student : public Person
{
protected:
	std::string univName;
	std::string speciality;
	std::string group;
public:
	Student(std::string univ, std::string spec, std::string grp, int id, std::string name, std::string last, int passID):
		 Person(id, name, last, passID), univName(univ), speciality(spec), group(grp)
	{}

	void setUniversity()
	{
		cin.ignore();
		std::getline(cin, univName);
	}
	void setSpeciality()
	{
		cin.ignore();
		std::getline(cin, speciality);
	}
	void setGroup()
	{
		cin.ignore();
		std::getline(cin, group);
	}
	std::string getUniversity()
	{
		return univName;
	}
	std::string getSpecialty()
	{
		return speciality;
	}
	std::string getGroup()
	{
		return group;
	}
};

int main()
{
	//Person valera(2157124, "Valera", "Khvostov", 32215);
	//cout << "Ful name " << valera.getFirtName()<< " " << valera.getLastName() << std::endl;
	//cout << "Date " << valera.getBirthday();

	Student vasa("NMETAU", "Metalurgy", "sg_02_22", 227845, "Vasily" , "Reznov", 146698);
	vasa.setNotes(); 

	cout << std::endl;
	cout << "Name: " << vasa.getFirtName() << " " << vasa.getLastName() << std::endl;
	cout << "Indification number: " << vasa.getID() << std::endl;
	cout << "Passport id: " << vasa.getPassportID() << std::endl;
	cout << "Birth date: " << vasa.getBirthday() << std::endl;
	vasa.printNote();

	return 0;
}