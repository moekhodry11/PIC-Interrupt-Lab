# PIC16F877A-Interrupt-Lab
  This code implements a garage security system that uses a password-protected keypad to control the opening and closing of a garage door motor. The motor runs for 4 seconds after the correct password is entered, regulated by timer interrupts.
 
 
# Getting started
To run the code in this repository, you will need the following:

- A PIC16F877A microcontroller
- A programmer (such as a PICkit or ICD3)
- The mikroC IDE (available from mikroC website)
- A breadboard and other basic electronic components (such as LEDs and resistors)

Once you have these items, you can clone this repository to your local machine:
```
git clone https://github.com/moekhodry11/PIC-Interrupt-Lab.git
```
# Hardware Requirements
- PIC16F877A microcontroller
- Keypad module
- LCD module
- Motor
- Relay Module
- 9V battery 

# Implementation

The code initializes the hardware components and sets up the timer interrupt. The user is prompted to enter the password using the keypad, and the system checks if the entered password is correct. If the password is correct, the motor turns on and runs for 4 seconds before turning off. The timer interrupt is used to regulate the motor's operation and ensure that it runs for the correct amount of time.

If an incorrect password is entered, the system displays a message indicating that the password is incorrect. The user can reset the password by pressing the "*" key on the keypad. The LCD display is also updated to show the entered password as a series of asterisks for added security.

# Usage
- Connect the hardware components to the microcontroller as specified in the code.
- Compile and upload the code to the microcontroller using the mikroC IDE.
- Enter the correct password on the keypad to activate the motor and open the garage door.
- Press the "*" key to reset the password.
- Observe the LCD display for feedback on the system's status.

# Contents
This repository contains several example programs that demonstrate different types of interrupts in the PIC16F877A microcontroller. Each program is located in a separate folder and includes a README file that explains how it works.

The following programs are included:
-External_Interrupt: Demonstrates how to use an external interrupt to detect a button press and toggle an LED.

# Circuit Diagram 
![photo_2023-05-15_20-47-07](https://github.com/alaawahba13/Garage-lock/assets/101985923/6c8bbfe5-74c2-4eea-ac70-2ff0dcfbb766)


# Simulation 
https://github.com/alaawahba13/Garage-lock/assets/101985923/ca4aafa2-d9e1-497d-a083-309d5cdf9e14



# Authors
This code was developed by 
- [@Alaa Wahba](https://github.com/alaawahba13)
- [@Ahmed Atef](https://github.com/AhmedAtef283)
- [@Mohamed Abdullhaleam](https://github.com/Mohamedabdullhaleam)
- [@Fareda Elsayed]( https://github.com/FaredaElsayed)
- [@Gehad Alaa ](https://github.com/Gehad799)
- [@Roaa Gawish ](https://github.com/roaagawish)
- [@Mohamed Khodary](https://github.com/moekhodry11)
- [@Mohamed Abdelzaher](https://github.com/Mohamed991-1) 
- [@Hagar Tarek](https://github.com/Hager706)
- [@Islam Morgan](https://github.com/retrogradex)


