/* -------------------------------------------
Name:Rohil Khakhar
Student number:109270173
Email:rkkhakhar@myseneca.ca
Section:IPC144O
Date:15th November 2017
----------------------------------------------
Assignment: 1
Milestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include"contacts.h"


int main(void)
{
	// Declare variables here: 



	struct Name myname = { { 0 },{ 0 },{ 0 } }; //three elements in the struct Name
	struct Address myaddress = { 0 ,{ 0 }, 0 ,{ 0 },{ 0 } }; //five elements in struct Address
	struct Numbers mynumbers = { { 0 },{ 0 },{ 0 } };
	char optionA, optionB, optionC, optionD, optionE; //a few members of the structure are optional values
													  //middleInitial, apartmentNumber, cell, home, business

													  // Display the title
	printf("Contact Management System");
	printf("-------------------------");
	printf("\n");


	// Contact Name Input:
	
	printf("Please Enter the contact's first name:");
	scanf("%30s", myname.firstName); // character array member
	printf("Do you want to enter a middle initial(s)? (y or n):");
	scanf(" %c", &optionA);

	if (optionA == 'y' || optionA == 'Y')
	{
		printf("Please enter the contact's middle initials(s)");
		scanf("%6s", myname.middleInitial); //character array member
	}

	else
	{

	}

	printf("Please enter the contact's last name:");
	scanf("%35s", myname.lastName); //character array member


									// Contact Address Input:
	printf("Please enter the contact's street number:");
	scanf("%d", &myaddress.streetNumber); //memory location operator needed for the address of non array members
	printf("Please enter the contact's street name:");
	scanf("%40s", myaddress.street);//array member
	printf("Do you want to enter an apartment number? (y or n):");
	scanf(" %c", &optionB);

	if (optionB == 'y' || optionB == 'Y') {
		printf("Please enter the contact's apartment number:");
		scanf("%d", &myaddress.apartmentNumber);
	}

	else {

	}

	printf("Please enter the contact's postal code:");
	scanf("%[^\n]", myaddress.postalCode);
	printf("Please enter the contact's city:");
	scanf("%40s", myaddress.city);




	// Contact Numbers Input:
	printf("Do you want to enter a cell phone number? (y or n):");
	scanf(" %c", &optionC);
	if (optionC == 'y' || optionC == 'Y') {
		printf("Please enter the contact's cell phone number:");
		scanf("%20s", mynumbers.cell);
	}

	else {

	}

	printf("Do you want to enter a home phone number? (y or n):");
	scanf(" %c", &optionD);
	if (optionD == 'y' || optionD == 'Y') {
		printf("Please enter the contact's home phone number:");
		scanf("%20s", mynumbers.home);
	}

	else
	{

	}

	printf("Do you want to enter a business phone number? (y or n):");
	scanf(" %c", &optionE);
	if (optionE == 'y' || optionE == 'Y') {
		printf("Please enter the contact's business phone number:");
		scanf("%20s", mynumbers.business);
	}

	else
	{

	}
	// Display Contact Summary Details
	printf("Contact Details\n");
	printf("---------------\n");
	printf("Name Details\n");
	printf("First name: %30s\n", myname.firstName);
	if (optionA == 'y' || optionA == 'Y') {
		printf("Middle initial(s): %s\n", myname.middleInitial);
	}
	printf("Last name: %s\n\n", myname.lastName);
	
	printf("Address Details\n");
	printf("Street number: %d\n", myaddress.streetNumber);
	printf("Street name: %s\n", myaddress.street);
	if (optionB == 'y' || optionB == 'Y') {
		printf("Apartment: %d\n", myaddress.apartmentNumber);
	}
	printf("Postal Code: %s\n", myaddress.postalCode);
	printf("City: %s\n\n", myaddress.city);

	printf("Phone Numbers:\n");
	if (optionC == 'y' || optionC == 'Y') {
		printf("Cell phone number: %s\n", mynumbers.cell);
	}
	if (optionD == 'y' || optionD == 'Y') {
		printf("Home phone number: %s\n", mynumbers.home);
	}
	if (optionE == 'y' || optionE == 'Y') {
		printf("Business phone number: %s\n\n", mynumbers.business);
	}

	// Display Completion Message
	printf("Structure test for Name, Address, and Numbers Done!");


	return 0;
}

/*  SAMPLE OUTPUT:

Contact Management System
-------------------------
Please enter the contact's first name: Tom
Do you want to enter a middle initial(s)? (y or n): y
Please enter the contact's middle initial(s): Wong
Please enter the contact's last name: Song
Please enter the contact's street number: 20
Please enter the contact's street name: Keele
Do you want to enter an appartment number? (y or n): y
Please enter the contact's appartment number: 40
Please enter the contact's postal code: A8A 4J4
Please enter the contact's city: Toronto
Do you want to enter a cell phone number? (y or n): Y
Please enter the contact's cell phone number: 905-111-6666
Do you want to enter a home phone number? (y or n): Y
Please enter the contact's home phone number: 705-222-7777
Do you want to enter a business phone number? (y or n): Y
Please enter the contact's business phone number: 416-333-8888

Contact Details
---------------
Name Details
First name: Tom
Middle initial(s): Wong
Last name: Song

Address Details
Street number: 20
Street name: Keele
Apartment: 40
Postal code: A8A 4J4
City: Toronto

Phone Numbers:
Cell phone number: 905-111-6666
Home phone number: 705-222-7777
Business phone number: 416-333-8888

Structure test for Name, Address, and Numbers Done!
*/