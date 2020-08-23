
/* -------------------------------------------
Name:Rohil Khakhar
Student number:109270173
Email:rkkhakhar@myseneca.ca
Section:IPC144O
Date:1st November 2017
----------------------------------------------
Assignment: 1
Milestone:  1
---------------------------------------------- */

// Structure type Name declaration
struct Name {
	char firstName[31];
	char middleInitial[7];
	char lastName[36];
};

// Structure type Address declaration
// Place your code here...
struct Address {
	int streetNumber;
	char street[41];
	int apartmentNumber;
	char postalCode[8];
	char city[41];
};


// Structure type Numbers declaration
// Place your code here...
struct Numbers {
	char cell[21];
	char home[21];
	char business[21];
};

struct Contacts
{
	struct Name name;
	struct Address address;
	struct Numbers numbers;
};

// ====== Milestone 4 =======

// Get and store from standard input the values for Name
// Place your code here...
void getName(struct Name*p_name);

// Get and store from standard input the values for Address
// Place your code here...
void getAddress(struct Address*p_address);

// Get and store from standard input the values for Numbers
// Place your code here...
void getNumbers(struct Numbers*p_numbers);
