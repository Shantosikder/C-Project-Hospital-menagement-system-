#include<iostream>
#include <string>
#include <conio.h>
#include<bits/stdc++.h>
#include<istream>
#include<fstream>
#include<stdlib.h>
#define ROWV 4
#define MAX_LIMIT 100
#define COLMNV 10
using namespace std;

void admin();
void user();
void admin_login();
void user_login();
void registration(string text, string fileName, void (*login)());
void admin_panel(string username);
void user_panel(string username);
void PatientInformationAdd();
void PatientInformationView();
void DoctorInformationAdd();
void DoctorInformationView();
void DoctorBooking();
void ViewDoctorBookingInformation();
void DeletePatientInformation();
void SearchPatientInformation();


string header = "\t********************************************************";

int main() {
    int choice;
    system("cls");
    cout<<"\t\t\t********************************************************************\n";
    cout<<"\t\t\t*                                                                  *\n";
    cout<<"\t\t\t*             Welcome To Hospital Management System                *\n";
    cout<<"\t\t\t*                                                                  *\n";
    cout<<"\t\t\t********************************************************************\n";
    cout<<"\n\t\t\t==>   Dashboard   <== \n\n";
    for(int i=0; i<=119; i++) cout<<"-";
    cout<<"\n\n\t\t\t1. Admin \n";
    cout<<"\t\t\t2. User\n";
    cout<<"\t\t\t3. Choose an option to continue: ";
    cin>>choice;

    switch (choice) {
        case 1:
            admin();
            break;
        case 2:
            user();
            break;
        default:
            cout<<"Invalid choice";
            main();
    }

    return 0;
}

void admin() {
    int choice;
    system("cls");
    cout<<"*********************************Admin Panel*************************************\n";
    cout<<"\nOptions \n\n";
    for(int i=0; i<=80; i++) cout<<"-";
    cout<<"\n\n\t\t\t1. Login \n";
    cout<<"\t\t\t2. Register \n";
    cout<<"\t\t\t3. Go back \n";
    cout<<"\t\t\t4. Choose an option to continue: ";
    cin>>choice;

    switch (choice) {
        case 1:
            admin_login();
            break;
        case 2:
            registration("Admin", "admin.txt", admin_login);
            break;
        case 3:
            main();
            break;
        default:
            cout<<"Invalid choice";
            admin();
    }
}

void user() {
    int choice;
    system("cls");
    cout<<"********************************User Panel************************************\n";
    cout<<"\nOptions \n\n";
    for(int i=0; i<=80; i++) cout<<"-";
    cout<<"\n\n\t\t\t1. Login \n";
    cout<<"\t\t\t2. Register \n";
    cout<<"\t\t\t3. Go back \n";
    cout<<"\t\t\t4. Choose an option to continue: ";
    cin>>choice;

    switch (choice) {
        case 1:
            user_login();
            break;
        case 2:
            registration("User", "users.txt", user_login);
            break;
        case 3:
            main();
            break;
        default:
            cout<<"Invalid choice";
            user();
    }
}

void admin_login() {
    string username, password, uname, pass;
    int is_exists=0,ch ;
    system("cls");
    cout<<"*********************Admin login*************************\n\n";
    cout<<"Enter username: ";
    cin>>username;
    cout<<"Enter password: ";
    ch=getch();
    while (ch !=13 )

	{
        if(ch!=8 && ch!=46)
        {
            password.push_back(ch);
 cout << '*';


        }

            ch =getch();


	}
	cout<<endl;
   //cin>>password;

    ifstream input("admin.txt");

    while (input>>uname>>pass)
        {
            if(uname == username && pass == password)
            {
                is_exists = 1;
            }
        }
    input.close();

    if (is_exists)
        {
            admin_panel(username);
        }
    else
    {
        cout<<"Invalid Login. Try again !\n";
        cout<<"Press enter to continue\n";
        cin.get();
        cin.get();
        admin_login();
    }
}

void user_login() {
    string username, password, uname, pass;
    int is_exists=0, ch;
    system("cls");
    cout<<"*********************User login*************************\n\n";
    cout<<"Enter username: ";
    cin>>username;
    cout<<"Enter password: ";
    ch=getch();
    while (ch !=13 )

	{
        if(ch!=8 && ch!=46)
        {
            password.push_back(ch);
 cout << '*';


        }

            ch =getch();


	}
	cout<<endl;
   // cin>>password;


    ifstream input("users.txt");

    while (input>>uname>>pass) {
        if(uname == username && pass == password) {
            is_exists = 1;
        }
    }
    input.close();

    if (is_exists)
        {
            user_panel(username);
        }
    else
        {
        cout<<"Invalid credentials. Try again !\n";
        cout<<"Press enter to continue\n";
        cin.get();
        cin.get();
        user_login();
        }
}

void registration(string text, string fileName, void (*login)()) {
    string username, password, email , phone_number;
    system("cls");
    cout<<"********************************"<< text << " " << "Panel************************************\n";
    cout<<"\nChoose a username and password \n\n";
    for(int i=0; i<=119; i++) cout<<"-";
    cout<<"\n\n\t\t\tEnter username: ";
    cin>>username;
    cout << "\t\t\tEnter Email: ";
    cin >> email;
    cout << "\t\t\tEnter Phone Number: ";
    cin >> phone_number;
    cout<<"\t\t\tEnter password: ";
    cin>>password;

    ofstream reg(fileName, ios::app);
    reg << username << " " << password << " " << email << endl;
    reg.close();
    system("cls");
    cout<<"********************************"<< text << " " << "Panel************************************\n";
    cout<<"\nRegistration Successfull\n";
    cout<<"Press enter to login";
    cin.get();
    cin.get();
    (*login)();
}

void admin_panel(string username) {
    int choice;
    system("cls");
    cout<<"*********************Admin panel*************************\n\n";
    cout << "Welcome to the admin portal " << username << ".\n";
    cout << "Options-> \n";
    cout <<"\t1. Add Patient Information \n";
    cout <<"\t2. View Patient Information \n";
    cout <<"\t3. Add Doctor Information \n";
    cout <<"\t4. Search Patient Information \n";
    cout <<"\t5. Delete Patient Information \n";
    cout <<"\t6. View Doctor Booking Information \n";
    cout <<"\t7. Go back \n";
    cout <<"\t8. Choose an option to continue: ";
    cin>>choice;

    switch (choice) {
    case 1:
        PatientInformationAdd();
        break;
    case 2:
        PatientInformationView();
        break;
    case 3:
        DoctorInformationAdd();
        break;
    case 4:
        SearchPatientInformation();
        break;
    case 5:
        DeletePatientInformation();
        break;
    case 6:
        ViewDoctorBookingInformation();
        break;
    case 7:
        main();
        break;
    default:
        cout<<"Invalid choice";
        admin_panel(username);
    }
}

void admin_panel2() {
    int choice;
    system("cls");

    cout << "Options-> \n";
    cout <<"\t1. Add Patient Information \n";
    cout <<"\t2. View Patient Information \n";
    cout <<"\t3. Add Doctor Information \n";
    cout <<"\t4. Search Patient Information \n";
    cout <<"\t5. Delete Patient Information \n";
    cout <<"\t6. View Doctor Booking Information \n";
    cout <<"\t7. Go back \n";
    cout <<"\t8. Choose an option to continue: ";
    cin>>choice;

    switch (choice) {
    case 1:
        PatientInformationAdd();
        break;
    case 2:
        PatientInformationView();
        break;
    case 3:
        DoctorInformationAdd();
        break;
    case 4:
        SearchPatientInformation();
        break;
    case 5:
        DeletePatientInformation();
        break;
    case 6:
        ViewDoctorBookingInformation();
        break;
    case 7:
        main();
        break;
    default:
        cout<<"Invalid choice";
        admin_panel2();
    }
}
void user_panel2() {
    int choice;
    system("cls");

    cout << "Options-> \n";
    cout<<"\t1. View Doctor Information \n";
    cout<<"\t2. Booking \n";
    cout<<"\t3. Go back \n";
    cout<<"\t9. Choose an option to continue: ";
    cin>>choice;

    switch (choice) {
    case 1:
         DoctorInformationView();
        break;
    case 2:
         DoctorBooking();
        break;
    case 3:
        main();
        break;
    default:
        cout<<"Invalid choice";
        user_panel2();
    }
}
void user_panel(string username) {
    int choice;
    system("cls");
    cout<<"*********************User panel*************************\n\n";
    cout << "Welcome to the user " << username << ".\n";
    cout << "Options-> \n";
    cout<<"\t1. View Doctor Information \n";
    cout<<"\t2. Booking \n";
    cout<<"\t3. Go back \n";
    cout<<"\t9. Choose an option to continue: ";
    cin>>choice;

    switch (choice) {
    case 1:
         DoctorInformationView();
        break;
    case 2:
         DoctorBooking();
        break;
    case 3:
        main();
        break;

    default:
        cout<<"Invalid choice";
        user_panel(username);
    }
}




void PatientInformationAdd()
{
    ofstream patientFile("patient.txt", ios::app);
    string patient_name, disease, age, cabin_no, phone_number;
    cout << header << endl;
    cout<<"\t*        Patient Information Add                  *\n";
    cout << header << endl;
    cout << "  " << endl;
    cout << "Enter Patient's Name = " ;
    cin >> patient_name;
    cout << "Enter disease = ";
    cin >> disease;
    cout << "Enter the age =  ";
    cin >> age;
    cout << "Enter cabin no =  ";
    cin >> cabin_no;
    cout << "Enter phone number = ";
    cin >> phone_number;
    patientFile << patient_name << " " << disease << " " << age << " " << cabin_no << " " << phone_number << "\n";

    patientFile.close();

    cout << header << endl;
    cout << "Patient's Information  Data Saved Successfully !!" << endl
         << patient_name << endl;
    cout << header << endl;
    char flag='n';
    cout<<"YOU CAN RETURN MENU OPTION .? Y/N.! :";
    cin>>flag;
    if(flag=='Y' || flag=='y')
    {
        admin_panel2();
    }
}



void PatientInformationView()
{
    ifstream patientFile("patient.txt");
    char ch;
    string patient_name, disease, age, cabin_no, phone_number;
    if (!patientFile)
    {
        cout << "Data File Not Found !" << endl;
        exit(1);
    }
    cout  << endl << endl;
    cout<<"\t\t\t********************************************************************\n";
    cout<<"\t\t\t*            Patient Information View                              *\n";
    cout<<"\t\t\t********************************************************************\n";

    cout << "\t-----------------------------------------------------------------------------------------------" << endl;
    cout << "\tName " << " \t| Disease " << " \t| Age " << " \t| Cabin no " << " \t| Phone Number no " << endl;
    cout << "\t-----------------------------------------------------------------------------------------------" << endl;

    while (patientFile >> patient_name >> disease >> age >> cabin_no >> phone_number)
    {
        //if (patientFile >> patient_name >> disease >> age >> cabin_no >> phone_number)
        {
            cout << "\t" << patient_name << " \t| " << disease << " \t| " << age
                 << "  \t| " << cabin_no << "  \t\t| " << phone_number << endl;
        }
    }
    patientFile.close();
    cout << "\t-------------------------------------------------------------------------------------------------" << endl;
    char flag='n';
    cout<<"YOU CAN RETURN MENU OPTION .? Y/N.! :";
    cin>>flag;
    if(flag=='Y' || flag=='y')
    {
         admin_panel2();
    }

}


void DoctorInformationAdd()
{
    ofstream DoctortFile("Doctor.txt", ios::app);
    string Doctor_name, Speciality, Schedule, Time, phone_number;
    cout << header << endl;
    cout<<"\t*        Doctor Information Add                  *\n";
    cout << header << endl;
    cout << "  " << endl;
    cout << "Enter Doctor's Name = " ;
    cin >> Doctor_name;
    cout << "Enter Speciality = ";
    cin >> Speciality;
    cout << "Enter Schedule =  ";
    cin >> Schedule;
    cout << "Enter Time =  ";
    cin >> Time;
    cout << "Enter phone number = ";
    cin >> phone_number;
    DoctortFile << Doctor_name << " " << Speciality << " " << Schedule << " "  << Time << " "  << phone_number << "\n";

   DoctortFile.close();

    cout << header << endl;
    cout << "Doctort's Information  Data Saved Successfully !!" << endl
         << Doctor_name << endl;
    cout << header << endl;
    char flag='n';
    cout<<"YOU CAN RETURN MENU OPTION .? Y/N.! :";
    cin>>flag;
    if(flag=='Y' || flag=='y')
    {
         admin_panel2();
    }
}



void DoctorInformationView()
{
     ifstream DoctorFile("Doctor.txt");
    char ch;
    string Doctor_name, Speciality, Schedule, Time, phone_number;
    if (!DoctorFile)
    {
        cout << "Data File Not Found !" << endl;
        exit(1);
    }
    cout  << endl << endl;
    cout<<"\t\t\t********************************************************************\n";
    cout<<"\t\t\t*            Doctor Information View                               *\n";
    cout<<"\t\t\t********************************************************************\n";

    cout << "\t-----------------------------------------------------------------------------------------------" << endl;
    cout << "\tName " <<  " \t\t| Speciality " << " \t| Schedule" << " \t| Time" << " \t| Phone Number no " << endl;
    cout << "\t-----------------------------------------------------------------------------------------------" << endl;

    while (DoctorFile >> Doctor_name >> Speciality >> Schedule >> Time >> phone_number)
    {
        //if (DoctorFile >> Doctor_name >> Speciality >> Schedule >> Time >> phone_number)
        {
            cout << "\t" << Doctor_name << " \t| " << Speciality << " \t| " << Schedule
                 << "  \t| " << Time << "  \t| " << phone_number << endl;
        }
    }

    DoctorFile.close();
    cout << "\t------------------------------------------------------------------------------------------------" << endl;
     char flag='n';
    cout<<"YOU CAN RETURN MENU OPTION .? Y/N.! :";
    cin>>flag;
    if(flag=='Y' || flag=='y')
    {
          user_panel2();
    }


}


void DoctorBooking()
{
    ofstream DoctorBookingFile("DoctorBookinginfo.txt", ios::app);
    string Doctor_name, Speciality, Schedule, Time;
    cout << header << endl;
    cout<<"\t*         Doctor Booking Information                *\n";
    cout << header << endl;
    cout << "  " << endl;
    cout << "Enter Doctor Name = " ;
    cin >> Doctor_name;
    cout << "Enter Speciality = ";
    cin >> Speciality;
    cout << "Enter Schedule =  ";
    cin >> Schedule;
    cout << "Enter Time =  ";
    cin >> Time;
    DoctorBookingFile << Doctor_name << " " << Speciality << " " << Schedule << " "  << Time <<  "\n";

   DoctorBookingFile.close();

    cout << header << endl;
    cout << " Doctor Booking Information  Data Saved Successfully !!" << endl
         << Doctor_name << endl;
    cout << header << endl;
     char flag='n';
    cout<<"YOU CAN RETURN MENU OPTION .? Y/N.! :";
    cin>>flag;
    if(flag=='Y' || flag=='y')
    {
    user_panel2();
    }

}



void ViewDoctorBookingInformation()
{
     ifstream DoctorBookinginfoFile("DoctorBookinginfo.txt");
    char ch;
    string Doctor_name, Speciality, Schedule, Time;
    if (!DoctorBookinginfoFile)
    {
    cout << "Data File Not Found !" << endl;
       exit(1);
    }

    cout  << endl << endl;
    cout<<"\t\t\t********************************************************************\n";
    cout<<"\t\t\t*            Doctor Booking Information View                               *\n";
    cout<<"\t\t\t********************************************************************\n";

    cout << "\t-----------------------------------------------------------------------------------------------" << endl;
    cout << "\tName " <<  " \t\t| Speciality " << " \t| Schedule" << " \t| Time"  << endl;
    cout << "\t-----------------------------------------------------------------------------------------------" << endl;

    while (DoctorBookinginfoFile >> Doctor_name >> Speciality >> Schedule >> Time)
    {
        //if (DoctorBookingFile >> Doctor_name >> Speciality >> Schedule >> Time )
        {
            cout << "\t" << Doctor_name << " \t| " << Speciality << " \t| " << Schedule
                 << "  \t| " << Time << endl;
        }
    }

    DoctorBookinginfoFile.close();
    cout << "\t------------------------------------------------------------------------------------------------" << endl;
    char flag='n';
    cout<<"YOU CAN RETURN MENU OPTION .? Y/N.! :";
    cin>>flag;
    if(flag=='Y' || flag=='y')
    {
         admin_panel2();
    }

}

void SearchPatientInformation()
{
   string patient_name, disease, age, cabin_no, phone_number;
    int is_exists=0, ch;
    string pname,pnum;
    system("cls");
    cout<<"*********************Search Patient Information*************************\n\n";
    cout<<"Enter phone_number: ";
    cin>>pnum;


    ifstream patientFile("patient.txt");
 while (patientFile >> patient_name >> disease >> age >> cabin_no >> phone_number)
    {

        if( pnum == phone_number) {
             cout << "\t" << patient_name << " \t| " << disease << " \t| " << age
                 << "  \t| " << cabin_no << "  \t\t| " << phone_number << endl;
                 is_exists=1;
                 break;
        }
    }
    patientFile.close();

    if (!is_exists)
        {

        cout<<"patient not found. Try again !\n";

        }
         char flag='n';
    cout<<"YOU CAN RETURN MENU OPTION .? Y/N.! :";
    cin>>flag;
    if(flag=='Y' || flag=='y')
    {
         admin_panel2();
    }

}


void DeletePatientInformation()

{
   string patient_name, disease, age, cabin_no, phone_number;
    int is_exists=0, ch;
    int k=0;
    string find;
    string line;
    string pname,pnum;
    system("cls");
    cout<<"*********************Delete Patient Information*************************\n\n";
    cout<<"Enter phone_number: ";
    cin>>pnum;
ofstream myfile;
    myfile.open("patient.txt");

    ifstream patientFile("patient.txt");

    while (patientFile >> patient_name >> disease >> age >> cabin_no >> phone_number)
{


       if(pnum==phone_number)
        {

             cout<<"patient u want to Delete "<<endl;
    cin>>find;

    ifstream myfile2; //for reading records
   myfile2.open("patient.txt");

    ofstream temp;
    temp.open("temp.txt");
    while (getline(myfile2, line))
    {
      if (line != find)
        temp << line << endl;
    }
    myfile2.close();
    temp.close();
    rename("temp.txt", "patient.txt");
     remove("patient.txt");

    //Now add new Record to file
    cout<<"enter patient_name "<<endl;
    cin>>patient_name;

    cout<<"enter disease Name"<<endl;
    cin>>disease;

    cout<<"enter age "<<endl;
    cin>>age;
    cout<<"enter cabin_no "<<endl;
    cin>>cabin_no;

    cout<<"enter phone_number "<<endl;
    cin>>phone_number;


    ofstream myfile;
    myfile.open("patient.txt", ios::app | ios::out);
    myfile<<patient_name<<endl;
    myfile<<disease<<endl;
    myfile<<age<<endl;
    myfile<<cabin_no<<endl;
    myfile<<phone_number<<endl<<endl<<endl;

        }
        else{
            patientFile.close();
        }
    }
    char flag='n';
    cout<<"*********************Patient Information Delete!*************************\n\n";
    cout<<"YOU CAN RETURN MENU OPTION .? Y/N.! :";
    cin>>flag;
    if(flag=='Y' || flag=='y')
    {
         admin_panel2();
    }
}




