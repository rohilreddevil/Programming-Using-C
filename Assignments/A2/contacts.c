/* -------------------------------------------
Name:Rohil Khakhar
Student number: 109270173
Email:rkkhakhar@mysenecac.on.ca
Section:IPC 144O
Date: 22nd December 2017
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+
#include"contactHelpers.h"
#include"contacts.h"

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+

// getName:
void getName(struct Name *ptr_name) {
	char optionA;
	printf("Please enter the contact's first name: ");
	scanf("%30s", (*ptr_name).firstName); // character array member
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf(" %c", &optionA);
	yes();

	if (optionA == 'y' || optionA == 'Y')
	{
		printf("Please enter the contact's middle initial(s): ");
		scanf("%6s", (*ptr_name).middleInitial); //character array member
	}

	else
	{

	}

	printf("Please enter the contact's last name: ");
	scanf("%35s", (*ptr_name).lastName);


}


// getAddress:
void getAddress(struct Address *ptr_address) {
	int optionB;
	printf("Please enter the contact's street number: ");
	//memory location operator needed for the address of non array members
	scanf("%d", &(*ptr_address).streetNumber); //memory location operator needed for the address of non array members
	getInt();
	printf("Please enter the contact's street name: ");
	scanf(" %[^\n]", (*ptr_address).street);
	printf("Do you want to enter an apartment number? (y or n): ");
	clearKeyboard();

	optionB = yes();



	if (optionB == 1) {
		printf("Please enter the contact's apartment number: ");
		scanf("%d", &(*ptr_address).apartmentNumber);
	}

	else {

	}

	printf("Please enter the contact's postal code: ");
	scanf("%[^\n]", (*ptr_address).postalCode);
	printf("Please enter the contact's city: ");
	scanf("%40s", (*ptr_address).city);

}


// getNumbers:

void getNumbers(struct Numbers *ptr_numbers) {
	char optionD, optionE;
	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone((*ptr_numbers).cell);
	
	printf("Do you want to enter a home phone number? (y or n): ");
	scanf(" %c", &optionD);
	if (optionD == 'y' || optionD == 'Y') {
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone((*ptr_numbers).home);
	}

	else
	{

	}

	printf("Do you want to enter a business phone number? (y or n): ");
	scanf(" %c", &optionE);
	if (optionE == 'y' || optionE == 'Y') {
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone((ptr_numbers));
	}

	else
	{

	}

}


// getContact:
void getContact(struct Contact *ptr_contact) {

	getName(&ptr_contact->name);
	getAddress(&ptr_contact->address);
	getNumbers(&ptr_contact->numbers);

}


