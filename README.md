# ATM//VAULT

### Secure Banking Simulator in C

ATM//VAULT is a console-based ATM simulation developed in C.
The project simulates common ATM operations while focusing on authentication, transaction handling, account management, and input validation.

## Features

* PIN-based authentication
* Three PIN attempts
* Balance inquiry
* Cash withdrawal
* Cash deposit
* Daily withdrawal limit
* Minimum balance requirement
* Mini statement
* Transaction history
* PIN change
* Account profile
* Input validation
* Clean menu-driven interface

## Project Structure

```text
ATM Simulation/
│
├── main.c
├── atm.c
├── atm.h
├── transactions.c
├── transactions.h
├── README.md
├── .gitignore
└── screenshots/
```

## Default Test Account

```text
Account Holder : Rahul Kumar
Account Number : 10010001
PIN            : 1234
Balance        : Rs. 25000.00
```

> This is a simulation account for testing purposes only. It is not connected to any real banking system.

## ATM Rules

* Maximum 3 incorrect PIN attempts
* Daily withdrawal limit: Rs. 20000
* Minimum account balance: Rs. 500
* PIN must contain exactly 4 digits
* Invalid transaction amounts are rejected
* Up to 20 recent transactions are stored during a session

## How to Compile

Make sure GCC is installed and available in the terminal.

Run:

```bash
gcc main.c atm.c transactions.c -o atmvault.exe
```

## How to Run

On Windows:

```bash
atmvault.exe
```

## Technologies Used

* C
* GCC
* Visual Studio Code
* Git
* GitHub

## Concepts Used

This project demonstrates:

* Structures
* Functions
* Header files
* Multiple source files
* Arrays
* Pointers
* Conditional statements
* Loops
* Input validation
* Modular programming

## Project Goal

The goal of ATM//VAULT is to practice building a multi-file C application with a realistic user flow while improving understanding of modular programming and basic transaction management.

## Author

Rahul Kumar

Computer Engineering Student
