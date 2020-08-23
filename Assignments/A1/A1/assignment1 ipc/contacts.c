/* -------------------------------------------
Name:Rohil Khakhar
Student number:10927073
Email:rkkhakhar
Section:144O
Date:5th December 2017
----------------------------------------------
Assignment: 1
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line
#include"contacts.h"


char optionA, optionB, optionC, optionD, optionE;
// Get and store from standard input the values for Name
// Put your code here that defines the Contact getName function:
void getName(struct Name*p_name) {

	printf("Please Enter the contact's first name:");
	scanf("%30s", (*p_name).firstName); // character array member
	printf("Do you want to enter a middle initial(s)? (y or n):");
	scanf(" %c", &optionA);

	if (optionA == 'y' || optionA == 'Y')
	{
		printf("Please enter the contact's middle initials(s)");
		scanf("%6s", (*p_name).middleInitial); //character array member
	}

	else
	{

	}

	printf("Please enter the contact's last name:");
	scanf("%35s", (*p_name).lastName);

	return;
}


// Get and store from standard input the values for Address
// Put your code here that defines the Contact getAddress function:
void getAddress(struct Address*p_address) {

	printf("Please enter the contact's street number:");
	scanf("%d", (*p_address).streetNumber); //memory location operator needed for the address of non array members
	printf("Please enter the contact's street name:");
	scanf("%40s", (*p_address).street);//array member
	printf("Do you want to enter an apartment number? (y or n):");
	scanf(" %c", &optionB);

	if (optionB == 'y' || optionB == 'Y') {
		printf("Please enter the contact's apartment number:");
		scanf("%d", (*p_address).apartmentNumber);
	}

	else {

	}

	printf("Please enter the contact's postal code:");
	scanf("%[^\n]", (*p_address).postalCode);
	printf("Please enter the contact's city:");
	scanf("%40s", (*p_address).city);

	return;
}



// Get and store from standard input the values for Numbers
// Put your code here that defines the Contact getNumbers function:
void getNumbers(struct Numbers*p_numbers) {
	
	printf("Do you want to enter a cell phone number? (y or n):");
	scanf(" %c", &optionC);
	if (optionC == 'y' || optionC == 'Y') {
		printf("Please enter the contact's cell phone number:");
		scanf("%20s", (*p_numbers).cell);
	}

	else {

	}

	printf("Do you want to enter a home phone number? (y or n):");
	scanf(" %c", &optionD);
	if (optionD == 'y' || optionD == 'Y') {
		printf("Please enter the contact's home phone number:");
		scanf("%20s", (*p_numbers).home);
	}

	else
	{

	}

	printf("Do you want to enter a business phone number? (y or n):");
	scanf(" %c", &optionE);
	if (optionE == 'y' || optionE == 'Y') {
		printf("Please enter the contact's business phone number:");
		scanf("%20s", (*p_numbers).business);
	}

	else
	{

	}

	return;
}
