#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "fixedLengthString.h"
using namespace std;

class Address : public FixedLengthString <5>
	{
    public: 
		             Address      ();
	                 Address      (const Address &);
		             ~Address     ();
		Address  &   operator =   (const Address &);
	                 Address      (string street, string city, string state, string zipCode);
	    string       getStreet    ();
	    string       getCity      ();
	    string       getState     ();
		char     *   getZipCode   ();
	    string       toString     ();
    private:
	    string       street;
	    string       city;
	    string       state;
		string       zip;
    };

class IDNumber: public FixedLengthString<9>
	{
    public:
		             IDNumber      ();
		             IDNumber      (const IDNumber &);
		             ~IDNumber     ();
		IDNumber &   operator =    (const IDNumber &);
	                 IDNumber      (string number);
	    char     *   getNumber     ();
	private:
		string       idnumber;
    };

class PhoneNumber: public FixedLengthString<10>
	{
    public:
		                PhoneNumber    ();
		                PhoneNumber    (const PhoneNumber &);
		                ~PhoneNumber   ();
		PhoneNumber &   operator =     (const PhoneNumber &);
	                    PhoneNumber    (string area, string number);
	    bool            setPhoneNumber (string area, string number);
	    string          toString       ();
	private:
		string          areacode;
		string          digitnumber;
     };

class Name
	{
    public:
		               Name           ();
		               Name           (const Name &);
		               ~Name          ();
		Name    &      operator =     (const Name &);
	                   Name           (string first, string middle, string last);
	    string         getFirstName   ();
	    string         getMiddleName  ();
	    string         getLastName    ();
    private:
	    string         firstName;
	    string         middleName;
	    string         lastName;
    };

class Student
	{
    public:
	                   Student        ();
		               Student        (const Student &);
	                   Student        (Name * name, IDNumber * idNumber, Address * address, PhoneNumber * phoneNumber);
	                   ~Student       ();
		Student  &     operator =     (const Student &);
	    Name     *     getName        ();
	    IDNumber *     getIdNumber    ();
	    PhoneNumber *  getPhoneNumber ();
	    Address *      getAddress     ();
	    void           display        ();
    private:
	    Name        *  name;
	    IDNumber    *  idNumber;
	    Address     *  address;
	    PhoneNumber *  phoneNumber;
     };

#endif
