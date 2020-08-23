/* -------------------------------------------
Name:Rohil Khakhar
Student number: 109270173
Email: rkkhakhar@mysenecac.on.ca
Section: IPC 144O
Date:22nd December
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h> 


// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:
#include"contactHelpers.h"
#include"contacts.h" 




// ----------------------------------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}


// pause:
void pause(void) {
	printf("(Press Enter to continue)");
	clearKeyboard();
}


// getInt:
int getInt(void) {
	char NL = 'x';
	int Value = 0;

	scanf("%d%c", &Value, &NL);
	while (NL != '\n') {
		printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		clearKeyboard();
		scanf("%d%c", &Value, &NL);
	}
	return Value;

}

// getIntInRange:
int getIntInRange(int n1, int n2) {
	int a = 0;
	a = getInt();
	while (a < n1 || a > n2) {
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", n1, n2);
		scanf("%d", &a);
	}
	return a;
}

// yes:
int yes(void) {
	int value = 0;
	char ch = 'r';
	char ch1 = ' ';
	scanf("%c%c", &ch, &ch1);
	while ((ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N') || (ch1 != '\n')) {
		clearKeyboard();
		printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		scanf("%c%c", &ch, &ch1);
	}

	if (ch == 'y' || ch == 'Y') {
		value = 1;
	}
	return value;
}


// menu:
int menu(void) {
	int choice = 0;
	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n\n");
	printf("Select an option:>");
	scanf("%d", &choice);
	while (choice > 6 || choice < 0) {
		printf("*** OUT OF RANGE *** <Enter a number between 0 and 6>: ");
		scanf("%d", &choice);
	}
	return choice;
}


// ContactManagerSystem:
void ContactManagerSystem(void) {
	struct Contact contacts[MAXCONTACTS] = { { { "Rick",{ '\0' }, "Grimes" },{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },{ "4161112222", "4162223333", "4163334444" } },
	{ { "Maggie", "R.", "Greene" },{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },{ "9051112222", "9052223333", "9053334444" } },
	{ { "Morgan", "A.", "Jones" },{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },{ "7051112222", "7052223333", "7053334444" } },
	{ { "Sasha",{ '\0' }, "Williams" },{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },{ "9052223333", "9052223333", "9054445555" } }, };

	char option = 'n';
	int choice = 0;
	do
	{

		choice = menu();
		clearKeyboard();
		switch (choice) {
		case 1:

			displayContacts(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			ContactManagerSystem();
			break;


		case 2:

			addContact(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			ContactManagerSystem();
			break;

		case 3:
			updateContact(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			ContactManagerSystem();
			break;


		case 4:
			deleteContact(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			ContactManagerSystem();
			break;

		case 5:
			searchContacts(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			ContactManagerSystem();
			break;

		case 6:
			sortContacts(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			ContactManagerSystem();
			break;

		case 0:
			printf("\nExit the program? (Y)es/(N)o:");
			scanf(" %c", &option);
			break;
		}
		printf("\n");
	} while ((option == 'n') || (option == 'N'));

	if (option == 'y' || option == 'Y') {
		printf("Contact Management System: terminated\n");
	}
}


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:
void getTenDigitPhone(char telNum[11])
{
	int needInput = 1;

	while (needInput == 1) {
		scanf("%10s", telNum);
		clearKeyboard();

		// (String Length Function: validate entry of 10 characters)
		if (strlen(telNum) == 10)
			needInput = 0;
		else
			printf("Enter a 10-digit phone number: ");
	}
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int contact_size, const char cellNum[])
{
	int i = 0;
	int exit = -1;
	for (i = 0; i < contact_size; i++) {
		if (!strcmp(contacts[i].numbers.cell, cellNum)) {
			exit = 1; 
		}
			

	}
	return exit;
}

// displayContactHeader
void displayContactHeader(void) {
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
	printf("\n");
}

// displayContactFooter
void displayContactFooter(int size) {
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", size);
}

// displayContact:
void displayContact(const struct Contact *contact) {
	if ((contact)->name.middleInitial[0] = '\0') {
		printf(" %s %s", contact->name.firstName, contact->name.lastName);
	}
	else if ((contact)->name.middleInitial[0] != '\0' && (contact)->name.firstName[0] != '\0') {
		printf(" %s %s %s\n", contact->name.firstName, contact->name.middleInitial, contact->name.lastName);
	}
	if ((contact)->numbers.cell[0] != '\0') {
		printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
	}
	if ((contact)->address.apartmentNumber > 0 && (contact)->address.street[0] != '\0') {
		printf("       %d %s, Apt# %d, %s, %s\n", (contact)->address.streetNumber, contact->address.street, (contact)->address.apartmentNumber, contact->address.city, contact->address.postalCode);
	}
	else if ((contact)->address.apartmentNumber <= 0 && (contact)->address.street[0] != '\0') {
		printf("       %d %s, %s, %s\n", (contact)->address.streetNumber, contact->address.street, contact->address.city, contact->address.postalCode);
	}
}
	// displayContacts:
	void displayContacts(const struct Contact contacts[], int contact_size) {
		displayContactHeader();
		int i;
		for (i = 0; i < contact_size; i++) {
			displayContact(&contacts[i]);
		}
		displayContactFooter(contact_size);



	}

	// searchContacts:
	void searchContacts(const struct Contact contacts[], int contact_size) {
		int i, outcome;
		char number[11];
		int flag=0;
		do {
			printf("Enter the cell number for the contact: ");
			getTenDigitPhone(number);
		} while (strlen(number) != 10);
		
		outcome=findContactIndex(contacts, contact_size, number);
		if (strcmp(number, contacts[i].numbers.cell))
			{
			displayContact(&contacts);
			}
		 if(outcome=-1) {
				flag = 1;
				printf("*** Contact NOT FOUND ***\n");
		}
		
		return;
		
}


	// addContact:
	void addContact(struct Contact contacts[], int contact_size) {
		int i;
		for (i = 0; i < contact_size; i++) {
			if (strlen(contacts[i].numbers.cell == 0)) {
				getContact(&contacts[i]);
				printf("--- New contact added! ---\n");
			}
			else if(strlen(contacts[i].numbers.cell == (contact_size-1))) {
				printf("*** ERROR: The contact list is full! ***\n");
				printf("\n");
			}
		}
	}
	// updateContact:
	void updateContact(struct Contact contacts[], int contact_size) {
		int search, optionA, optionB, optionC;
		char cellno[11];
		getTenDigitPhone(cellno);
		search= findContactIndex(contacts, contact_size, cellno);
		
		if (search = -1) {
			printf("*** Contact NOT FOUND ***\n");
		}
		do {
			printf("\nContact found:\n");
			displayContact(&contacts[search]);
			printf("\nDo you want to update the name? (y or n): ");
			optionA = yes();
			if (optionA == 1) {
				getName(&contacts[search].name);
			}
			clearKeyboard();
			printf("Do you want to update the address? (y or n): ");
			optionB = yes();
			if (optionB == 1) {
				getAddress(&contacts[search].address);
			}
			clearKeyboard();
			printf("Do you want to update the numbers? (y or n): ");
			optionC = yes();
			if (optionC == 1) {
				getNumbers(&contacts[search].numbers);
				
			}
		} while (search != -1);
		printf("--- Contact Updated! ---\n");
	}

	// deleteContact:
	void deleteContact(struct Contact contacts[], int contact_size) {
		char cellno[11];
		int value,optionA;
		value = findContactIndex(contacts, contact_size, cellno);
		if (value = -1) {
			printf("*** Contact NOT FOUND ***\n");
		}
		else
		{
			printf("\n");
			printf("Contact found:\n");
		}
		displayContact(&contacts);
		printf("\n");
		printf("CONFIRM: Delete this contact? (y or n): ");
		optionA = yes();
		if (optionA == 1) {
			contacts[value].numbers.cell[0] = '\0';
		} 
		printf("--- Contact deleted! ---\n");
	}


	// sortContacts:
	void sortContacts(struct Contact contacts[], int contact_size) {
		printf("<<< Feature to sort is unavailable >>>\n");
	}