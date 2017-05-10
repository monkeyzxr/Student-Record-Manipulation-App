/***************************************
Class     : COSC 1437.3S7
Assignment: Semester Project
Author    : Xiangru Zhou
Date      : 08-06-2015
***************************************/
#include <iostream>
#include "student.h"
using namespace std;

Name * newName ()
	{
	string first, middle, last;
	cout << "enter first name:";
	cin >> first;
	cout << "enter middle name:";
	cin >> middle;
	cout << "enter last name:";
	cin >> last;
	Name * name = new Name (first, middle, last);
	return name;
    }

IDNumber * newIDNumber ()
	{
	while (1)
		{
		string id;
		cout << "enter ID number (9 numeric digits, cannot be more or less):";
		cin >> id;
		int flag = 1;
		int length = id.length();
		for (int i = 0; i < length; i++)
			{
			if(!(id[i] >= '0' && id[i] <= '9'))
				{
				flag = 0;
				break;
				}
			}
		if (flag && length == 9)
			{
			return new IDNumber(id);
		    }
		else
			{
			cout << "error!enter again!" << endl;
		    }
	     }
     }

bool check_digits (string digits, int length)
	{
	if(digits.length() != length)
		return false;
	for(int i=0; i<length; i++)
		{
		if(digits[i] < '0' || digits[i] > '9')
			return false;
	    }
	return true;
    }

PhoneNumber * newPhoneNumber ()
	{
	string area, number;
	cout << "enter area(3 digits):";
	cin >> area;
	while (!check_digits(area, 3))
		{
		cout<<"wrong digits, please enter area(3 digits) again: ";
		cin>>area;
	    }
	cout << "enter number(7 digits):";
	cin >> number;
	while (!check_digits(number, 7))
		{
		cout<<"wrong digits, please enter number(7 digits) again: ";
		cin>>number;
	    }
	return new PhoneNumber (area, number);
    }

Address * newAddress ()
	{
	string street, city, state, zipCode; 
	cout << "enter street of address:";
	cin >> street;
	cout << "enter city of address:";
	cin >> city;
	cout << "enter state of address:";
	cin >> state;
	while (1)
		{
		cout << "enter zip code of address(5 digit):";
		cin >> zipCode;
		int length = zipCode.length();
		int flag = 1;
		for (int i = 0; i < length; i++)
			{
			if(!(zipCode[i] >= '0' && zipCode[i] <= '9'))
				{
			     flag = 0;
			     break;
			    }
		     }
		if(flag && length == 5)
			{
			return new Address (street, city, state, zipCode);
		    }
		else
			{
			cout << "error!enter zip code again!" << endl;
		    }
	    }
    }

void sortByName (Student students[], int count)
	{
	Student temp;
	for(int i = 1; i < count; i++)
		{
		for(int j = count - 1; j >= i; j--)
			{
			string jName = students[j].getName()->getLastName()+students[j].getName()->getFirstName()+students[j].getName()->getMiddleName();
			string iName = students[j-1].getName()->getLastName()+students[j-1].getName()->getFirstName()+students[j-1].getName()->getMiddleName();
			if(jName.compare(iName) < 0)
				{
				temp          = students[j-1];
				students[j-1] = students[j];
				students[j]   = temp;
				}
			}
		}
	}			

void sortById (Student students[], int count)
	{
	Student temp;
	for(int i = 1; i < count; i++)
		{
		for(int j = count - 1; j >= i; j--)
			{
			if(strcmp(students[j].getIdNumber()->getNumber(), students[j-1].getIdNumber()->getNumber()) < 0)
				{
				temp          = students[j-1];
				students[j-1] = students[j];
				students[j]   = temp;
				}
			}
		}
	}
		
void readFile (Student students[], int& count)
	{
	string fileName;
	cout << "enter file name:";
	cin >> fileName;
	FILE *fp;
	fp = fopen(fileName.c_str(),"r");
	if(fp != NULL)
		{	
		while (!feof(fp))
			{
			char first[50] = {0};
			char middle[50] = {0};
			char last[10] = {0};
			char idNumber[100] = {0};
			char street[50] = {0};
			char city[50] = {0};
			char state[50] = {0};
			char zipcode[50] = {0};
			char area[50]={0};
			char number[50]={0};
			fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s-%s\n",&first, &middle, &last, &idNumber, &street, &city, &state, &zipcode, &area, &number); 
			Name * name         = new Name(first, middle, last);
			IDNumber * id       = new IDNumber(idNumber);
			Address * address   = new Address(street, city, state, zipcode);
			PhoneNumber * phone = new PhoneNumber(area, number);
			Student stu(name, id, address, phone);
			students[count] = stu;
			count++;
			}
		fclose(fp);
		cout << "read the records from the file." << endl;
		}
	else
		{
		cout << "the file not exit." << endl;
		}
	}


void writeFile (Student students[], int count) 
	{
	string fileName;
	cout << "enter file name:";
	cin >> fileName;
	FILE *fp;
	fp = fopen(fileName.c_str(),"w");
	if(fp != NULL)
		{
		if(fp != NULL)
			{
			for(int i = 0; i < count; i++)
				fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
					students[i].getName()->getFirstName().c_str(),
					students[i].getName()->getMiddleName().c_str(),
					students[i].getName()->getLastName().c_str(),
					students[i].getIdNumber()->getNumber(),
					students[i].getAddress()->getStreet().c_str(),
					students[i].getAddress()->getCity().c_str(),
					students[i].getAddress()->getState().c_str(),
					students[i].getAddress()->getZipCode(),
					students[i].getPhoneNumber()->toString());
			}
		fclose(fp);
		cout << "save the records to the file!" << endl;
		}
	}


const int max_students = 25;

void main ()
	{
	Student students[max_students];
	int count  = 0;
	int choice = 1;
	while(choice)
		{
		cout << "**********************"<< endl;
		cout << "1.enter records." << endl;
		cout << "2.sort records by last name" << endl;
		cout << "3.sort records by ID" << endl;
		cout << "4.read the records from a disk file" << endl;
		cout << "5.save the records to a disk file" << endl;
		cout << "0.exit" << endl;
		cout << "**********************"<< endl;
		cout << "enter your choice:";
		cin >> choice;
		switch(choice)
			{
		    case 1:
				{
				Name * name         = newName();
				IDNumber * id       = newIDNumber();
				Address * address   = newAddress();
				PhoneNumber * phone = newPhoneNumber();
				Student stu(name, id, address, phone);
				students[count] = stu;
				count++;
				}
			    break;

		    case 2:
				{
				sortByName (students, count);
				for(int i = 0; i < count; i++)
					students[i].display();
				}			
			    break; 

		    case 3:
				{
				sortById (students, count);
				for(int i = 0; i < count; i++)
					students[i].display();
				}
			    break;

		    case 4:
			    readFile (students, count);
			    break;

		    case 5:
			    writeFile (students, count);
			    break;

		    case 0:
			    break;
			}
		}
	}

