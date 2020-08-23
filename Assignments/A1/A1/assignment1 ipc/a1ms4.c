/* -------------------------------------------
Name:Rohil Khakhar
Student number:109270173	
Email:rkkhakhar@myseneca.ca
Section: 144O
Date:8th December 2017
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
// #include your contacts header file on the next line:

#include"contacts.c" 


int main(void)
{
	// Declare variables here:
	struct Name myname = { { 0 },{ 0 },{ 0 } }; //three elements in the struct Name
	struct Address myaddress = { 0 ,{ 0 }, 0 ,{ 0 },{ 0 } }; //five elements in struct Address
	struct Numbers mynumbers = { { 0 },{ 0 },{ 0 } };
	struct Contacts contact = { {0}, {0}, {0} };
	// Create a variable of type Contact and call it something self-describing like "contact"
	// - HINT: Be sure to initialize the values to 0 and empty C strings


	// Display the title
	printf("Contact Management System\n");
	printf("-------------------------\n");

	// Call the Contact function getName to store the values for the Name member
	getName(&myname);

	// Call the Contact function getAddress to store the values for the Address member
	getAddress(&myaddress);

	// Call the Contact function getNumbers to store the values for the Numbers member
	getNumbers(&mynumbers);

	// Display Contact summary details
	printf("Contact Details\n");
	printf("---------------\n");
	printf("Name Details\n");
	printf("First name: %30s\n", contact.name);
	if (optionA == 'y' || optionA == 'Y') {
		printf("Middle initial(s): %s\n", contact.name);
	}
	printf("Last name: %s\n\n", myname.lastName);

	printf("Address Details\n");
	printf("Street number: %d\n", contact.address);
	printf("Street name: %s\n", contact.address);
	if (optionB == 'y' || optionB == 'Y') {
		printf("Apartment: %d\n", contact.address);
	}
	printf("Postal Code: %s\n", contact.address);
	printf("City: %s\n\n", myaddress.city);

	printf("Phone Numbers:\n");
	if (optionC == 'y' || optionC == 'Y') {
		printf("Cell phone number: %s\n", contact.numbers);
	}
	if (optionD == 'y' || optionD == 'Y') {
		printf("Home phone number: %s\n", contact.numbers);
	}
	if (optionE == 'y' || optionE == 'Y') {
		printf("Business phone number: %s\n\n", contact.numbers);
	}


	// Display Completion Message
	printf("Structure test for Contact using functions done!\n");

	return 0;
}

/*  SAMPLE OUTPUT:

Contact Management System
-------------------------
Please enter the contact's first name: Wilma
Do you want to enter a middle initial(s)? (y or n): y
Please enter the contact's middle initial(s): Dino
Please enter the contact's last name: Flintstone
Please enter the contact's street number: 100
Please enter the contact's street name: Bedrock
Do you want to enter an appartment number? (y or n): y
Please enter the contact's appartment number: 14
Please enter the contact's postal code: Z8Z 7R7
Please enter the contact's city: Markham
Do you want to enter a cell phone number? (y or n): Y
Please enter the contact's cell phone number: 647-505-5555
Do you want to enter a home phone number? (y or n): Y
Please enter the contact's home phone number: 905-222-3333
Do you want to enter a business phone number? (y or n): Y
Please enter the contact's business phone number: 416-491-5050

Contact Details
---------------
Name Details
First name: Wilma
Middle initial(s): Dino
Last name: Flintstone

Address Details
Street number: 100
Street name: Bedrock
Apartment: 14
Postal code: Z8Z 7R7
City: Markham

Phone Numbers:
Cell phone number: 647-505-5555
Home phone number: 905-222-3333
Business phone number: 416-491-5050

Structure test for Contact using functions done!
*/