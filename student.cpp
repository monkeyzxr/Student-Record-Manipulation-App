#include <iostream>
#include <string>
#include "student.h"
using namespace std;

//**********************************************************************************
Address::Address ()
	{
	}

Address::Address (const Address & A)
	{
	street = A.street;
	city   = A.city;
	state  = A.state;
	zip    = A.zip;
	}

Address::~Address ()
	{
	}

Address & Address::operator = (const Address & A)
	{
	street = A.street;
	city   = A.city;
	state  = A.state;
	zip    = A.zip;
	return *this;
	}

Address::Address (string street, string city, string state, string zipCode) : FixedLengthString(zipCode.c_str())
	{
	this->street = street;
	this->city   = city;
	this->state  = state;
	this->zip    = zipCode;
    }

string Address::getStreet()
	{
	return street;
    }

string Address::getCity()
	{
	return city;
    }
string Address::getState()
	{
	return state;
    }
char* Address::getZipCode()
	{
	return getValue();
    }
string Address::toString()
	{
	return street + " " + city + " " + state + " " + getValue();
    }

//***************************************************************************************
IDNumber::IDNumber ()
	{
	}

IDNumber::IDNumber (const IDNumber & id)
	{
	idnumber = id.idnumber;
	}

IDNumber::~IDNumber ()
	{
	}

IDNumber & IDNumber::operator = (const IDNumber & id)
	{
	idnumber = id.idnumber;
	return *this;
	}

IDNumber::IDNumber(string number) : FixedLengthString(number.c_str())
	{	
    }

char* IDNumber::getNumber()
	{
	return getValue();
    }

//********************************************************************************
PhoneNumber::PhoneNumber ()
	{
	}

PhoneNumber::PhoneNumber (const PhoneNumber & phon)
	{
	areacode    = phon.areacode;
	digitnumber = phon.digitnumber;
	}

PhoneNumber::~PhoneNumber ()
	{
	}

PhoneNumber & PhoneNumber::operator = (const PhoneNumber & pho)
	{
	areacode    = pho.areacode;
	digitnumber = pho.digitnumber;
	return *this;
	}

PhoneNumber::PhoneNumber(string area, string number)
	{
	setPhoneNumber(area, number);
    }

bool PhoneNumber::setPhoneNumber(string area, string number)
	{
	if(area.length()==3 && number.length()==7)
		{
		string tmp = area + number;
		setValue(tmp.c_str(), 10);
		return true;
	    }
	return false;
   }

string PhoneNumber::toString()
	{
	char * buf = getValue();
	string s;
	s.append(buf, 3).append("-").append(buf+3, 7);
	return s;
    }

//********************************************************************************************
Name::Name ()
	{
	}

Name::Name (const Name & n)
	{
	firstName  = n.firstName;
	middleName = n.middleName;
	lastName   = n.lastName;
	}

Name::~Name ()
	{
	}

Name & Name::operator = (const Name & n)
	{
	firstName  = n.firstName;
	middleName = n.middleName;
	lastName   = n.lastName;
	return *this;
	}

Name::Name(string first, string middle, string last)
	{
	this->firstName  = first;
	this->middleName = middle;
	this->lastName   = last;
    }

string Name::getFirstName()
	{
	return firstName;
    }  

string Name::getMiddleName()
	{
	return middleName;
    }

string Name::getLastName()
	{
	return lastName;
    }

//************************************************************************************
Student::Student()
	{
	this->name        = NULL;
	this->idNumber    = NULL;
	this->address     = NULL;
	this->phoneNumber = NULL;
    }

Student & Student::operator = (const Student & stu)
	{
	name        = stu.name;
	idNumber    = stu.idNumber;
	address     = stu.address;
	phoneNumber = stu.phoneNumber;
	return *this;
	}

Student::Student (const Student & stu)
	{
    name        = stu.name;
	idNumber    = stu.idNumber;
	address     = stu.address;
	phoneNumber = stu.phoneNumber;
	}

Student::Student(Name * name, IDNumber * idNumber, Address * address, PhoneNumber * phoneNumber)
	{
	this->name        = name;
	this->idNumber    = idNumber;
	this->address     = address;
	this->phoneNumber = phoneNumber;
    }

Name * Student::getName()
	{
	return name;
    }

IDNumber * Student::getIdNumber()
	{
	return idNumber;
    }

Address * Student::getAddress()
	{
	return address;
    }

PhoneNumber * Student::getPhoneNumber()
	{
	return phoneNumber;
    }

void Student::display()
	{
	cout << "Name:" << name->getFirstName() << " " << name->getMiddleName() << " " << name->getLastName() << ", "
		<< "ID Number:" << idNumber->getNumber() << ", " << "Address:" << address->toString()<<", "
		<< "Phone Number: " << phoneNumber->toString() << endl;
     }

Student::~Student()
	{
    }  