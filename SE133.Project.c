#include<stdio.h>
#include<conio.h>
#include<windows.h>
int option,compare1,compare2,compare3,flag,row;
char username[20],password[20],first_name1[20],last_name1[20],email[30];
struct information
{
    int ward_cost;
    int medicine_cost;
    int operation_cost;
    int total_cost;
    int total_paid;
    int total_due;
	int age;
	char gender[10];
	char first_name[20];
	char last_name[20];
	char contact_no[20];
	char address[30];
	char email[30];
	char problem[20];
	char medicine_name[20];
	char operation_date[15];
	char operation_name[20];
}patient,doctor,surgeon;
COORD coord = {0,0};
void gotoxy(int x,int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void title();
void showWelcomeMessage();
void showHospitalInformation();
void chooseCreateAccountOrLogIn();
void createAccount();
void logIn();
void mainMenu();
//doctor
void showMenuOfDoctor();
void addMedicalRecord();
void listOfMedicalRecord();
void sheduleOperation();
void listOfOperationDetails();
//staff
void showMenuOfStaff();
void addPatientInformation();
void listOfPatientInformation();
void searchPatientInformation();
void editPatientInformation();
void deletePatientInformation();
void addpaymentdetails();
void listOfpaymentdetails();
void logOut();
int main()
{
    showWelcomeMessage();
    showHospitalInformation();
    chooseCreateAccountOrLogIn();
    createAccount();
    logIn();
}
void title()
{
    printf("\t---------------------------------------------------------------------------------------------------------");
    printf("\t\t\t\t\t\t\t\tBangladesh Hospital\n");
    printf("\t---------------------------------------------------------------------------------------------------------");
}
void showWelcomeMessage()
{
    printf("\n\n\n\n\n\n\n\n\n\t\t\t\t*********************************************************");
    printf("\n\t\t\t\t*\t\t\t\t\t\t\t*");
    printf("\n\t\t\t\t*\t\t\t WELCOME TO \t\t\t*");
    printf("\n\t\t\t\t*\t BANGLADESH HOSPITAL MANAGEMENT SYSTEM \t\t*");
    printf("\n\t\t\t\t*\t\t\t\t\t\t\t*");
    printf("\n\t\t\t\t*********************************************************");
    printf("\n\n\n\n\n\t\t\t\t\tPress any key to continue.........");
    getch();

}
void showHospitalInformation()
{
    system("cls");
    title();
    printf("\n\n\n\t\tAddress : Dhaka , Bangladesh");
    printf("\n\n\t\tHour : 24 hours");
    printf("\n\n\t\tContact Number : 01765486593 ");
    printf("\n\n\t\tList of Services Offered by Bangladesh Hospital :");
    printf("\n\n\t\t # Ward Facilities");
    printf("\n\n\t\t # Nursing");
    printf("\n\n\t\t # Out patient Department( OPD)");
    printf("\n\n\t\t # Intensive Care Unit(ICU)");
    printf("\n\n\t\t # Pharmacy and Diagnosis");
    printf("\n\n\t\t # Operation Facilities");
    printf("\n\n\t\t\t\t........!!!!!!!Your Health Is Our Responsibility!!!!!!!........");
    printf("\n\n\t\t\t\t\t  Press any key to continue.........");
    getch();
}
void chooseCreateAccountOrLogIn()
{
    A:
    system("cls");
    title();
    printf("\n\n\n\n   ......!!!!!!If have an account then log in the system or create an account with username and password!!!!!!...... ");
    printf("\n\n\n\n\t\t\t\t  1)Create an account\t\t 2)Log in");
    printf("\n\n\n\n\t\t\t\t\t     Enter your choice : ");
    scanf("%d",&option);
    switch(option)
    {
        case 1 :
        {
           createAccount();
        }
        break;
        case 2 :
        {
            logIn();
        }
        break;
        default :
        {
            printf("\n\n\n\t\t\t\t\t  Invalid entry,Try Again.....");
            getch();
            goto A;
        }
        break;
    }
}
void createAccount()
{
   system("cls");
   title();
   FILE *login_system;
   login_system=fopen("AccountInformation.txt","a");
   printf("\n\n\n\t\t\t   .....!!!!!Enter username and password to create an account!!!!!..... ");
   printf("\n\n\n\t\t\tUsrename : ");
   scanf("%s",&username);
   printf("\n\n\t\t\tPassword : ");
   scanf("%s",&password);
   fprintf(login_system," %s %s \n",username,password);
   fclose(login_system);
   printf("\n\n\t\t\t\t\t  Account created successfully.........");
   getch();
   chooseCreateAccountOrLogIn();
}
void logIn()
{
    A:
    system("cls");
    title();
    FILE *login_system;
    login_system=fopen("AccountInformation.txt","r");
    char username_login[20],password_login[20];
    printf("\n\n\n\t\t   .....!!!!!You can log in the system with your username and password!!!!!..... ");
    printf("\n\n\n\t\t\tUsrename : ");
    scanf("%s",&username_login);
    printf("\n\n\t\t\tPassword : ");
    scanf("%s",&password_login);
    while(fscanf(login_system,"%s %s\n",&username,&password)!=EOF)
    {
       compare1=strcmp(username,username_login) ;
       compare2=strcmp(password,password_login) ;
       if(compare1==0&&compare2==0)
       {
           flag=1;
           break;
       }
       else
       {
           flag=0;
       }
    }
    fclose(login_system);
    if(flag==1)
    {
        printf("\n\n\t\t\t\t\t\tLogin successfully.......");

        getch();
        mainMenu();
    }
    else
    {
        printf("\n\n\t\t\t\t    Incorrect username or password,Try Again.........");
        getch();
        goto A;
    }

}
void mainMenu()
{
    A:
    system("cls");
    title();
    printf("\n\n\n\t\t\t\t\t\tAre you a.........");
    printf("\n\n\n\n\t\t\t\t\t 1)Doctor\t\t 2)Staff ");
    printf("\n\n\n\n\t\t\t\t\t\t Enter your choice : ");
    scanf("%d",&option);
    switch(option)
    {
        case 1 :
        {
           showMenuOfDoctor();
        }
        break;
        case 2 :
        {
           showMenuOfStaff();
        }
        break;
        default :
        {
            printf("\n\n\n\t\t\t\t\t    Invalid entry,Try Again......");
            getch();
            goto A;
        }
        break;
    }
}
//Doctor
void showMenuOfDoctor()
{
    A:
    system("cls");
    title();
    printf("\n\n\n\t\t\t 1)Add medical record of the patient");
    printf("\n\n\t\t\t 2)List of medical record of the patient");
    printf("\n\n\t\t\t 3)Schedule operation date for the patient");
    printf("\n\n\t\t\t 4)List of the operation details of the patient");
    printf("\n\n\t\t\t 5)Log out");
    printf("\n\n\n\n\t\t\t\t Enter your choice : ");
    scanf("%d",&option);
    switch(option)
    {
        case 1 :
        {
            addMedicalRecord();
        }
        break;
        case 2 :
        {
            listOfMedicalRecord();
        }
        break;
        case 3 :
        {
            sheduleOperation();
        }
        break;
        case 4 :
        {
            listOfOperationDetails();
        }
        break;
        case 5 :
        {
            logOut();
        }
        break;
        default :
        {
            printf("\n\n\n\t\t\t\t Invalid entry,Try Again.....");
            getch();
            goto A;
        }
        break;
    }
}
void addMedicalRecord()
{
    system("cls");
    title();
    A:
    printf("\n\n\t\t\t\t\t.....!!!!!Add Patient's Medical Record!!!!!.....");
    FILE *medical_record;
    medical_record=fopen("MedicalRecordInformation.txt","a");
    printf("\n\n\n\n\n\t\t\tFirst Name : ");
    scanf("%s",&patient.first_name);
    printf("\n\t\t\tLast Name : ");
    scanf("%s",&patient.last_name);
    printf("\n\t\t\tProblem : ");
    scanf("%s",&patient.problem);
    printf("\n\t\t\tPrescribed Doctor's First Name : ");
    scanf("%s",&doctor.first_name);
    printf("\n\t\t\tPrescribed Doctor's Last Name : ");
    scanf("%s",&doctor.last_name);
    printf("\n\t\t\tMedicine Name : ");
    scanf("%s",&patient.medicine_name);
    fprintf(medical_record,"%s %s  %s  %s %s %s\n",patient.first_name,patient.last_name,patient.problem,doctor.first_name,doctor.last_name,patient.medicine_name);
    printf("\n\n\t\t\tPatient's medical record added successfully.....");
    fclose(medical_record);
    B:
    getch();
    printf("\n\n\n\n\n\t\t\tDo you want to add more ???? ");
    printf("\n\n\n\n\t\t\t 1.Yes  \t\t  2.No");
    printf("\n\n\n\n\t\t\tEnter your choice : ");
    scanf("%d",&option);
    switch(option)
    {
        case 1 :
        {
            printf("\n\n");
            goto A;
        }
        break;
        case 2 :
        {
            showMenuOfDoctor();
        }
        break;
        default :
        {
            printf("\n\n\n\t\t\tInvalid entry,Try Again....");
            getch();
            goto B;
        }
    }
}
void listOfMedicalRecord()
{
    system("cls");
    title();
    printf("\n\n\t\t\t\t  .....!!!!!List of Patient's Medical Record!!!!!.....");
    FILE *medical_record;
    medical_record=fopen("MedicalRecordInformation.txt","r");
    gotoxy(2,10);
    printf("====================================================================================================================");
    gotoxy(2,11);
    printf("| Full Name");
    gotoxy(32,11);
    printf("| Problem");
    gotoxy(52,11);
    printf("| Prescribed Doctor");
    gotoxy(82,11);
    printf("| Medicine Name");
    gotoxy(117,11);
    printf("|");
    gotoxy(2,12);
    printf("====================================================================================================================");
    row=13;
    while(fscanf(medical_record,"%s %s  %s  %s %s %s\n",&patient.first_name,&patient.last_name,&patient.problem,&doctor.first_name,&doctor.last_name,&patient.medicine_name)!=EOF)
    {
        gotoxy(2,row);
        printf("| %s %s",patient.first_name,patient.last_name);
        gotoxy(32,row);
        printf("| %s",patient.problem);
        gotoxy(52,row);
        printf("| %s %s",doctor.first_name,doctor.last_name);
        gotoxy(82,row);
        printf("| %s",patient.medicine_name);
        gotoxy(117,row);
        printf("|");
        row++;
        gotoxy(2,row);
        printf("--------------------------------------------------------------------------------------------------------------------");
        row++;
    }
    fclose(medical_record);
    printf("\n\n\t\t\t\t\t  Press any key to continue.........");
    getch();
    showMenuOfDoctor();
}
void sheduleOperation()
{
    system("cls");
    title();
    A:
    printf("\n\n\t\t\t\t\t.....!!!!!Add Patient's Operation Details!!!!!.....");
    FILE *operation_details;
    operation_details=fopen("OperationInformation.txt","a");
    printf("\n\n\n\n\n\t\t\tFirst Name : ");
    scanf("%s",&patient.first_name);
    printf("\n\t\t\tLast Name : ");
    scanf("%s",&patient.last_name);
    printf("\n\t\t\tProblem : ");
    scanf("%s",&patient.problem);
    printf("\n\t\t\tOperation Name : ");
    scanf("%s",&patient.operation_name);
    printf("\n\t\t\tOperation Date [Date-Month-Year] : ");
    scanf("%s",&patient.operation_date);
    printf("\n\t\t\tSurgeon's First Name : ");
    scanf("%s",&surgeon.first_name);
    printf("\n\t\t\tSurgeon's Last Name : ");
    scanf("%s",&surgeon.last_name);
    fprintf(operation_details,"%s %s  %s  %s %s %s %s\n",patient.first_name,patient.last_name,patient.problem,patient.operation_name,patient.operation_date,surgeon.first_name,surgeon.last_name);
    printf("\n\n\t\t\tOperation details added successfully.......");
    fclose(operation_details);
    getch();
    B:
    printf("\n\n\n\n\n\t\t\tDo you want to add more ???? ");
    printf("\n\n\n\n\t\t\t 1.Yes  \t\t  2.No");
    printf("\n\n\n\n\t\t\tEnter your choice : ");
    scanf("%d",&option);
    switch(option)
    {
        case 1 :
        {
            printf("\n\n");
            goto A;
        }
        break;
        case 2 :
        {
            showMenuOfDoctor();
        }
        break;
        default :
        {
            printf("\n\n\n\t\t\tInvalid entry,Try Again....");
            getch();
            goto B;
        }
    }
}
void listOfOperationDetails()
{
    system("cls");
    title();
    printf("\n\n\t\t\t\t  .....!!!!!List of Operation Deatails!!!!!.....");
    FILE *operation_details;
    operation_details=fopen("OperationInformation.txt","r");
    gotoxy(2,10);
    printf("====================================================================================================================");
    gotoxy(2,11);
    printf("| Full Name");
    gotoxy(32,11);
    printf("| Problem");
    gotoxy(49,11);
    printf("| Operation Name");
    gotoxy(67,11);
    printf("| Operation Date");
    gotoxy(87,11);
    printf("| Surgeon");
    gotoxy(117,11);
    printf("|");
    gotoxy(2,12);
    printf("====================================================================================================================");
    row=13;
    while(fscanf(operation_details,"%s %s  %s  %s %s %s %s\n",&patient.first_name,&patient.last_name,&patient.problem,&patient.operation_name,&patient.operation_date,&surgeon.first_name,&surgeon.last_name)!=EOF)
    {
        gotoxy(2,row);
        printf("| %s %s",patient.first_name,patient.last_name);
        gotoxy(32,row);
        printf("| %s",patient.problem);
        gotoxy(49,row);
        printf("| %s ",patient.operation_name);
        gotoxy(67,row);
        printf("| %s ",patient.operation_date);
        gotoxy(87,row);
        printf("| %s %s",surgeon.first_name,surgeon.last_name);
        gotoxy(117,row);
        printf("|");
        row++;
        gotoxy(2,row);
        printf("--------------------------------------------------------------------------------------------------------------------");
        row++;
    }
    fclose(operation_details);
    printf("\n\n\t\t\t\t\t  Press any key to continue.........");
    getch();
    showMenuOfDoctor();
}
//staff
void showMenuOfStaff()
{
    A:
    system("cls");
    title();
    printf("\n\n\n\n\n\t\t\t 1)Add information of the patient");
    printf("\n\n\t\t\t 2)List of the patient's information");
    printf("\n\n\t\t\t 3)Search the information of the patient ");
    printf("\n\n\t\t\t 4)Edit the information of the patient");
    printf("\n\n\t\t\t 5)Delete the information of the patient");
    printf("\n\n\t\t\t 6)Add payment details of the patient");
    printf("\n\n\t\t\t 7)List of payment details of the patient");
    printf("\n\n\t\t\t 8)Log out");
    printf("\n\n\n\n\t\t\t\t Enter your choice : ");
    scanf("%d",&option);
    switch(option)
    {
        case 1 :
        {
            addPatientInformation();
        }
        break;
        case 2 :
        {
            listOfPatientInformation();
        }
        break;
        case 3 :
        {
            searchPatientInformation();
        }
        break;
        case 4 :
        {
            editPatientInformation();
        }
        break;
        case 5 :
        {
            deletePatientInformation();
        }
        break;
        case 6 :
        {
            addpaymentdetails();
        }
        break;
        case 7 :
        {
            listOfpaymentdetails();
        }
        break;
        case 8 :
        {
            logOut();
        }
        break;
        default :
        {
            printf("\n\n\n\t\t\tInvalid entry,Try Again....");
            getch();
            goto A;
        }
        break;
    }
}
void addPatientInformation()
{
    system("cls");
    title();
    A:
    printf("\n\n\t\t\t\t\t.....!!!!!Add Patient's Information!!!!!.....");
    FILE *patient_information;
    patient_information=fopen("PatientInformation.txt","a");
    printf("\n\n\n\n\n\t\t\tFirst Name : ");
    scanf("%s",&patient.first_name);
    printf("\n\t\t\tLast Name : ");
    scanf("%s",&patient.last_name);
    printf("\n\t\t\tGender[Female/Male] : ");
    scanf(" %s",&patient.gender);
    printf("\n\t\t\tAge : ");
    scanf(" %d",&patient.age);
    printf("\n\t\t\tAddress : ");
    scanf("%s",&patient.address);
    printf("\n\t\t\tContact no : ");
    scanf("%s",&patient.contact_no);
    printf("\n\t\t\tEmail : ");
    scanf("%s",&patient.email);
    fprintf(patient_information,"%s %s  %s %d %s %s %s \n",patient.first_name,patient.last_name,patient.gender,patient.age,patient.address,patient.contact_no,patient.email);
    printf("\n\n\t\t\tInformation added successfully!!!!!.....");
    fclose(patient_information);
    getch();
    B:
    printf("\n\n\n\n\n\t\t\tDo you want to add more ???? ");
    printf("\n\n\n\n\t\t\t 1.Yes  \t\t  2.No");
    printf("\n\n\n\n\t\t\tEnter your choice : ");
    scanf("%d",&option);
    switch(option)
    {
        case 1 :
        {
            printf("\n\n");
            goto A;
        }
        break;
        case 2 :
        {
            showMenuOfStaff();
        }
        break;
        default :
        {
            printf("\n\n\n\t\t\tInvalid entry,Try Again....");
            getch();
            goto B;
        }
    }
}
void listOfPatientInformation()
{
    system("cls");
    title();
    printf("\n\n\t\t\t\t\t.....!!!!!List of Patient's Information!!!!!.....");
    FILE *patient_information;
    patient_information=fopen("PatientInformation.txt","r");
    gotoxy(2,10);
    printf("====================================================================================================================");
    gotoxy(2,11);
    printf("| Full Name");
    gotoxy(27,11);
    printf("| Gender");
    gotoxy(37,11);
    printf("| Age");
    gotoxy(44,11);
    printf("| Address");
    gotoxy(72,11);
    printf("| Contact No");
    gotoxy(87,11);
    printf("| Email");
    gotoxy(117,11);
    printf("|");
    gotoxy(2,12);
    printf("====================================================================================================================");
    row=13;
    while(fscanf(patient_information," %s %s  %s %d %s %s %s \n",&patient.first_name,&patient.last_name,&patient.gender,&patient.age,&patient.address,&patient.contact_no,&patient.email)!=EOF)
    {
        gotoxy(2,row);
        printf("| %s %s",patient.first_name,patient.last_name);
        gotoxy(27,row);
        printf("| %s",patient.gender);
        gotoxy(37,row);
        printf("| %d",patient.age);
        gotoxy(44,row);
        printf("| %s",patient.address);
        gotoxy(72,row);
        printf("| %s",patient.contact_no);
        gotoxy(87,row);
        printf("| %s",patient.email);
        gotoxy(117,row);
        printf("|");
        row++;
        gotoxy(2,row);
        printf("--------------------------------------------------------------------------------------------------------------------");
        row++;
    }
    fclose(patient_information);
    printf("\n\n\t\t\t\t\t  Press any key to continue.........");
    getch();
    showMenuOfStaff();
}
void searchPatientInformation()
{
    system("cls");
    title();
    A:
    printf("\n\n\t\t\t\t\t.....!!!!!Search Patient's Information!!!!!.....");
    FILE *patient_information;
    patient_information=fopen("PatientInformation.txt","r");
    printf("\n\n\n\t\t\tEnter Patient Name to be searched.......");
    printf("\n\n\t\t\tFirst name : ");
    scanf("%s",&first_name1);
    printf("\n\t\t\tLast Name : ");
    scanf("%s",&last_name1);
    while(fscanf(patient_information," %s %s  %s %d %s %s %s \n",&patient.first_name,&patient.last_name,&patient.gender,&patient.age,&patient.address,&patient.contact_no,&patient.email)!=EOF)
    {
        compare1=strcmp(first_name1,patient.first_name);
        compare2=strcmp(last_name1,patient.last_name);
        if(compare1==0&&compare2==0)
        {
            flag=1;
            break;
        }
        else
        {
            flag=0;
        }
    }
    if(flag==1)
    {
        printf("\n\n\t\t\t\t\t     .....!!!!!Patient's Information!!!!!.....");
        printf("\n\n\n\n\n\t\t\tName : %s %s ",patient.first_name,patient.last_name);
        printf("\n\n\t\t\tGender[Female/Male] : %s",patient.gender);
        printf("\n\n\t\t\tAge : %d",patient.age);
        printf("\n\n\t\t\tAddress : %s",patient.address);
        printf("\n\n\t\t\tContact no : %s",patient.contact_no);
        printf("\n\n\t\t\tEmail : %s",patient.email);
    }
    if(flag==0)
    {
        printf("\n\n\n\t\t\tInformation not found,Try Again......");
        getch();
        printf("\n\n");
        goto A;
    }
    fclose(patient_information);
    B:
    printf("\n\n\n\t\t\tDo you want to search more??");
    printf("\n\n\n\t\t\t 1.Yes  \t\t  2.No");
    printf("\n\n\n\t\t\t Enter your choice : ");
    scanf("%d",&option);
    if(option==1)
    {
        goto A;
    }
    else if(option==2)
    {
        showMenuOfStaff();
    }
    else
    {
        printf("\n\n\n\t\t\tInvalid entry,Try Again....");
        getch();
        goto B;
    }
}
void editPatientInformation()
{
    system("cls");
    title();
    A:
    printf("\n\n\t\t\t\t\t.....!!!!!Edit Patient's Information!!!!!.....");
    FILE *patient_information;
    patient_information=fopen("PatientInformation.txt","r");
    printf("\n\n\n\t\t\tEnter Patient Name to be edited.......");
    printf("\n\n\t\t\tFirst name : ");
    scanf("%s",&first_name1);
    printf("\n\t\t\tLast Name : ");
    scanf("%s",&last_name1);
    while(fscanf(patient_information," %s %s  %s %d %s %s %s \n",&patient.first_name,&patient.last_name,&patient.gender,&patient.age,&patient.address,&patient.contact_no,&patient.email)!=EOF)
    {
        compare1=strcmp(first_name1,patient.first_name);
        compare2=strcmp(last_name1,patient.last_name);
        if(compare1==0&&compare2==0)
        {
            flag=1;
            strcpy(email,patient.email);
            break;
        }
        else
        {
            flag=0;
        }
    }
    if(flag==0)
    {
        printf("\n\n\n\t\t\tInformation not found,Try Again......");
        getch();
        printf("\n\n");
        goto A;
    }
    fclose(patient_information);
    if(flag==1)
    {
        FILE *patient_information;
        FILE *temporary_patient_information;
        patient_information=fopen("PatientInformation.txt","r");
        temporary_patient_information=fopen("TemporaryPatientInformation.txt","a");
        while(fscanf(patient_information," %s %s  %s %d %s %s %s \n",&patient.first_name,&patient.last_name,&patient.gender,&patient.age,&patient.address,&patient.contact_no,&patient.email)!=EOF)
        {
            compare3=strcmp(email,patient.email);
            if(compare3!=0)
            {
                fprintf(temporary_patient_information,"%s %s  %s %d %s %s %s \n",patient.first_name,patient.last_name,patient.gender,patient.age,patient.address,patient.contact_no,patient.email);
            }
            else
            {
                printf("\n\n\t\t\t\t\t  .....!!!!!Existing Patient's Information!!!!!.....");
                printf("\n\n\n\n\n\t\t\tName : %s %s ",patient.first_name,patient.last_name);
                printf("\n\n\t\t\tGender[Female/Male] : %s",patient.gender);
                printf("\n\n\t\t\tAge : %d",patient.age);
                printf("\n\n\t\t\tAddress : %s",patient.address);
                printf("\n\n\t\t\tContact no : %s",patient.contact_no);
                printf("\n\n\t\t\tEmail : %s",patient.email);
                printf("\n\n\n\n\t\t\t\t\t.....!!!!!Enter Patient's Updated Information!!!!!.....");
                printf("\n\n\n\n\n\t\t\tFirst Name : ");
                scanf("%s",&patient.first_name);
                printf("\n\t\t\tLast Name : ");
                scanf("%s",&patient.last_name);
                printf("\n\t\t\tGender[Female/Male] : ");
                scanf(" %s",&patient.gender);
                printf("\n\t\t\tAge : ");
                scanf(" %d",&patient.age);
                printf("\n\t\t\tAddress : ");
                scanf("%s",&patient.address);
                printf("\n\t\t\tContact no : ");
                scanf("%s",&patient.contact_no);
                printf("\n\t\t\tEmail : ");
                scanf("%s",&patient.email);
                fprintf(temporary_patient_information,"%s %s  %s %d %s %s %s \n",patient.first_name,patient.last_name,patient.gender,patient.age,patient.address,patient.contact_no,patient.email);
                flag=3;
            }
        }
        if(flag==3)
        {
            fclose(patient_information);
            fclose(temporary_patient_information);
            remove("PatientInformation.txt");
            rename("TemporaryPatientInformation.txt","PatientInformation.txt");
            printf("\n\n\n\t\t\tInformation edited successfully........");
            getch();
            showMenuOfStaff();
       }
    }
}
void deletePatientInformation()
{
    system("cls");
    title();
    A:
    printf("\n\n\t\t\t\t\t.....!!!!!Delete Patient's Information!!!!!.....");
    FILE *patient_information;
    patient_information=fopen("PatientInformation.txt","r");
    printf("\n\n\n\t\t\tEnter Patient Name to be deleted.......");
    printf("\n\n\t\t\tFirst name : ");
    scanf("%s",&first_name1);
    printf("\n\t\t\tLast Name : ");
    scanf("%s",&last_name1);
    while(fscanf(patient_information," %s %s  %s %d %s %s %s \n",&patient.first_name,&patient.last_name,&patient.gender,&patient.age,&patient.address,&patient.contact_no,&patient.email)!=EOF)
    {
        compare1=strcmp(first_name1,patient.first_name);
        compare2=strcmp(last_name1,patient.last_name);
        if(compare1==0&&compare2==0)
        {
            printf("\n\n\t\t\t\t\t.....!!!!!Existing Patient's Information!!!!!.....");
            printf("\n\n\n\n\n\t\t\tName : %s %s ",patient.first_name,patient.last_name);
            printf("\n\n\t\t\tGender[Female/Male] : %s",patient.gender);
            printf("\n\n\t\t\tAge : %d",patient.age);
            printf("\n\n\t\t\tAddress : %s",patient.address);
            printf("\n\n\t\t\tContact no : %s",patient.contact_no);
            printf("\n\n\t\t\tEmail : %s",patient.email);
            flag=1;
            strcpy(email,patient.email);
            break;
        }
        else
        {
            flag=0;
        }
    }
    if(flag==0)
    {
        printf("\n\n\n\t\t\tInformation not found,Try Again......");
        printf("\n\n");
        getch();
        goto A;
    }
    fclose(patient_information);
    C:
    printf("\n\n\n\n\t\t\tAre you sure you want to delete this information ???");
	printf("\n\n\n\n\t\t\t 1.Yes  \t\t  2.No");
	printf("\n\n\n\n\t\t\tEnter your choice : ");
	scanf("%d",&option);
    switch(option)
    {
        case 1 :
        {
            goto B;
        }
        break;
        case 2 :
        {
            showMenuOfStaff();
        }
        break;
        default :
        {
            printf("\n\n\n\t\t\tInvalid entry,Try Again....");
            getch();
            goto C;
        }
        break;
    }
    B:
    if(flag==1)
    {
        FILE *patient_information;
        FILE *temporary_patient_information;
        patient_information=fopen("PatientInformation.txt","r");
        temporary_patient_information=fopen("TemporaryPatientInformation.txt","a");
        while(fscanf(patient_information," %s %s  %s %d %s %s %s \n",&patient.first_name,&patient.last_name,&patient.gender,&patient.age,&patient.address,&patient.contact_no,&patient.email)!=EOF)
        {
            compare3=strcmp(email,patient.email);
            if(compare3!=0)
            {
                fprintf(temporary_patient_information,"%s %s  %s %d %s %s %s \n",patient.first_name,patient.last_name,patient.gender,patient.age,patient.address,patient.contact_no,patient.email);
            }
            else
            {
                fclose(patient_information);
                fclose(temporary_patient_information);
                remove("PatientInformation.txt");
                rename("TemporaryPatientInformation.txt","PatientInformation.txt");
                printf("\n\n\n\t\t\tInformation deleted successfully.....");
                getch();
                showMenuOfStaff();
            }
        }
    }
}
void addpaymentdetails()
{
    system("cls");
    title();
    A:
    printf("\n\n\t\t\t\t\t.....!!!!!Add Payment Details of Patients!!!!!.....");
    FILE *payment_information;
    payment_information=fopen("PaymentInformation.txt","a");
    printf("\n\n\n\n\n\t\t\tFirst Name : ");
    scanf("%s",&patient.first_name);
    printf("\n\t\t\tLast Name : ");
    scanf("%s",&patient.last_name);
    printf("\n\t\t\tWard Cost[tk] : ");
    scanf(" %d",&patient.ward_cost);
    printf("\n\t\t\tMedicine Cost[tk] : ");
    scanf(" %d",&patient.medicine_cost);
    printf("\n\t\t\tOperation Cost[tk] : ");
    scanf(" %d",&patient.operation_cost);
    patient.total_cost=patient.ward_cost+patient.medicine_cost+patient.operation_cost;
    printf("\n\t\t\tTotal Cost[tk] : %d \n",patient.total_cost);
    printf("\n\t\t\tTotal paid[tk] : ");
    scanf("%d",&patient.total_paid);;
    patient.total_due=patient.total_cost-patient.total_paid;
    printf("\n\t\t\tTotal due[tk] : %d ",patient.total_due);
    fprintf(payment_information,"%s %s %d %d %d %d %d %d \n",patient.first_name,patient.last_name,patient.ward_cost,patient.medicine_cost,patient.operation_cost,patient.total_cost,patient.total_paid,patient.total_due);
    printf("\n\n\n\t\t\tPayment details added successfully!!!!!.....");
    fclose(payment_information);
    getch();
    B:
    printf("\n\n\n\n\n\t\t\tDo you want to add more ???? ");
    printf("\n\n\n\n\t\t\t 1.Yes  \t\t  2.No");
    printf("\n\n\n\n\t\t\tEnter your choice : ");
    scanf("%d",&option);
    switch(option)
    {
        case 1 :
        {
            printf("\n\n");
            goto A;
        }
        break;
        case 2 :
        {
            showMenuOfStaff();
        }
        break;
        default :
        {
            printf("\n\n\n\t\t\tInvalid entry,Try Again....");
            getch();
            goto B;
        }
    }

}
void listOfpaymentdetails()
{
    system("cls");
    title();
    printf("\n\n\t\t\t\t  .....!!!!!List of Payment Details of Patients!!!!!.....");
    FILE *payment_information;
    payment_information=fopen("PaymentInformation.txt","r");
    gotoxy(2,10);
    printf("====================================================================================================================");
    gotoxy(2,11);
    printf("| Full Name");
    gotoxy(25,11);
    printf("| Ward Cost");
    gotoxy(39,11);
    printf("| Medicine Cost");
    gotoxy(57,11);
    printf("| Operation Cost");
    gotoxy(75,11);
    printf("| Total Cost");
    gotoxy(89,11);
    printf("| Total paid");
    gotoxy(103,11);
    printf("| Total due");
    gotoxy(117,11);
    printf("|");
    gotoxy(2,12);
    printf("====================================================================================================================");
    row=13;
    while(fscanf(payment_information,"%s %s %d %d %d %d %d %d \n",&patient.first_name,&patient.last_name,&patient.ward_cost,&patient.medicine_cost,&patient.operation_cost,&patient.total_cost,&patient.total_paid,&patient.total_due)!=EOF)
    {
       gotoxy(2,row);
        printf("| %s %s",patient.first_name,patient.last_name);
        gotoxy(25,row);
        printf("| %d tk",patient.ward_cost);
        gotoxy(39,row);
        printf("| %d tk",patient.medicine_cost);
        gotoxy(57,row);
        printf("| %d tk",patient.operation_cost);
        gotoxy(75,row);
        printf("| %d tk",patient.total_cost);
        gotoxy(89,row);
        printf("| %d tk",patient.total_paid);
        gotoxy(103,row);
        printf("| %d tk",patient.total_due);
        gotoxy(117,row);
        printf("|");
        row++;
        gotoxy(2,row);
        printf("--------------------------------------------------------------------------------------------------------------------");
        row++;
    }
    fclose(payment_information);
    printf("\n\n\t\t\t\t\t  Press any key to continue.........");
    getch();
    showMenuOfStaff();
}
void logOut()
{
    A:
    system("cls");
	title();
	printf("\n\n\n\n\t\t\t\t\tAre you sure you want to Log Out............");
	printf("\n\n\n\n\t\t\t\t\t     1.Yes  \t\t  2.No");
	printf("\n\n\n\n\t\t\t\t\t\t Enter your choice : ");
	scanf("%d",&option);
	switch(option)
	{
	    case 1 :
	    {
	        printf("\n\n\n\t\t\t\t\t\t   Logging Out....");
	        getch();
	        system("cls");
	        title();
	        printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t........!!!!!!!!Thank You For Visiting!!!!!!!!........");
            getch();
            system("cls");
            exit(0);
	    }
	    break;
	    case 2:
        {
            mainMenu();
        }
        break;
        default :
        {
            printf("\n\n\n\t\t\t\t\t      Invalid entry,Try Again.....");
            getch();
            goto A;
        }
        break;
	}
}


