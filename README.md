![2](https://user-images.githubusercontent.com/98077136/206533707-15165d5f-adac-40e7-a8f0-641ef7c40ef4.png)
# HospitalManagementSystem
This Hospital Management System has following functionalities:
1- Admits a Patient
2- Provision for both Emergency and Non-Emergency Admission is there.
3- Prints details of a patient already admitted
4- Discharges a patient
5- Calculates and prints the bill of the discharged patient
6- Sends Ambulance to input address if required.

Assumptions:
1- This hospital has 100 beds available for non-emergency admission but in case of emergency admission, if beds are full, it transfers the patient to a different hospital. Hence, any number of Emergency Admissions can take place.

Input Data:
1- Details of Hospital such as name, address, Doctor count, staff count, bed count,  is already fed into the program.
2- Program reads list of already admitted patients from a text file ( which acts as a database )

Sample Database:
PATIENT_NAME             PATIENT_ID        ROOM_NO                BLOODGRP.                CONTACT_INFO 
Lionel Messi             HMS2022_1            1                      O+                   +91-9435668940 
Neymar Jr.               HMS2022_3            2                      AB+                  +91-8765453345

How to Run:

1- The program provides a set of functionalities to choose from such as admission, discharge, ambulance service etc.
2- Choose the required service and enter the details accordingly.
     a) For admitting a patient, enter patient details. Patient id and room no. will be allotted accordingly.
         Bed Count and Bed price is available as information.
     b) While collecting a discharges patient, enter patient name. Patient details will be printed along with the bill.
     c)  While availing ambulance service, enter address to where you want the ambulance
3- Details will be printed on the screen accordingly.

Program Details:

1- Program has been made while adhering to concepts of Object-Oriented Programming as much as possible.
2- Multiple classes have been used to promote encapsulation and data members and functions have been put in private and       protected scope accordingly to encourage data abstraction.
3- < Patient> Class inherits the Hospital Class.
4- <AvailService> class is a friend of Hospital Class.
5-  <admitPatient> function of class Patient makes use of <bedcount> function of class Bed.

UML
     
![UML](https://user-images.githubusercontent.com/98077136/206532717-aca1a227-c75c-4d57-bbab-03c22249a120.jpeg)


Sample INPUT and OUTPUT 
![1](https://user-images.githubusercontent.com/98077136/206532850-75aa6960-b002-472b-9994-677ab5b28866.png)
![2](https://user-images.githubusercontent.com/98077136/206533707-15165d5f-adac-40e7-a8f0-641ef7c40ef4.png)


PROJECT MEMBERS
a) Rishabh Lalwani ( 211130 , CSE 2ndYear)
b) Kshitij Verma   ( 211118, CSE 2nd Year) 

