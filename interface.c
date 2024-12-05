#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INPUT(a) scanf("%d",&a);

//adding a record
void addRecord(int roll){
    FILE *fptr;
    fptr = fopen("details.csv", "a");
    char stuname[50], fname[50], mname[50];
    int hosno;
    long long int contact;
    printf("Enter name:");
    scanf("%s", &stuname);
    printf("Enter Father's name:");
    scanf("%s", &fname);
    printf("Enter Mother's name:");
    scanf("%s", &mname);
    printf("Enter contact number:");
    scanf("%lld", &contact);
    printf("Enter room number:");
    INPUT(hosno)
    
    fprintf(fptr, "\n%d,", roll);
    fprintf(fptr, "%s,", stuname);
    fprintf(fptr, "%s,", fname);
    fprintf(fptr, "%s,", mname);
    fprintf(fptr, "%lld,", contact);
    fprintf(fptr, "%d", hosno);
    
    fclose(fptr);
    return;
}

//showing all records
void showRecords(){
    FILE* file= fopen("details.csv","r");
    if (file == NULL) {
        printf("No records insterted\n");
        return;
    }

    // Read and print each character until EOF
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if(ch==','){
            ch='\t';
        }
        putchar(ch);
    }

    // Close the file
    fclose(file);

    return;}

//Searching a record    
void searchRecord(int searchno){
    int rollno, Roomno, found = 0;
    char line[256];  // Buffer to hold each line
    char name[50], Fname[50], Mname[50], Contactno[13];

    // Open file in read mode
    FILE *fptr2 = fopen("details.csv", "r");
    if (fptr2 == NULL){
        printf("NO RECORD INSERTED.\n");
        return;
    }

    // Read lines one by one
    while (fgets(line, sizeof(line), fptr2)) {
        // Parse the line
        if (sscanf(line, "%d,%49[^,],%d,%49[^,],%49[^,],%12s",
                   &rollno, name, &Roomno, Fname, Mname, Contactno) == 6) {
            // Check if this is the record we are looking for
            if (rollno == searchno) {
                printf("Record Found:\n");
                printf("Roll No: %d\n", rollno);
                printf("Name: %s\n", name);
                printf("Room No: %d\n", Roomno);
                printf("Father's Name: %s\n", Fname);
                printf("Mother's Name: %s\n", Mname);
                printf("Contact No: %s\n", Contactno);
                found = 1;
                break;
            }
        } else {
            printf("Warning: Could not parse line: %s", line);
        }
    }

    if (!found) {
        printf("No record found with Roll No: %d\n", searchno);
    }

    // Close the file
    fclose(fptr2);
    return;
}


//adding marks
void addMarks(int roll){
    FILE *fptr2;
    fptr2 = fopen("report.csv","a");
    int PH100Marks;
    int EC100Marks;
    int IT101Marks;
    int HS101Marks;
    int MA101Marks;
    printf("Enter IT101 marks:");
    scanf("%d", &IT101Marks);
    printf("Enter PH100 marks:");
    scanf("%d", &PH100Marks);
    printf("Enter HS101 marks:");
    scanf("%d", &HS101Marks);
    printf("Enter MA101 marks:");
    scanf("%d", &MA101Marks);
    printf("Enter EC100 marks:");
    scanf("%d", &EC100Marks);
    
    fprintf(fptr2, "\n%d,", roll);   
    fprintf(fptr2, "%d,", IT101Marks);
    fprintf(fptr2, "%d,", PH100Marks);
    fprintf(fptr2, "%d,", HS101Marks);
    fprintf(fptr2, "%d,", MA101Marks);
    fprintf(fptr2, "%d", EC100Marks);
    
    fclose(fptr2);
    printf("Marks added successfully\n");
    return;
}

//showing all marks
void showMarks(){
    FILE* file= fopen("report.csv","r");
    if (file == NULL) {
        printf("No records insterted\n");
        return;
    }

    // Read and print each character until EOF
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if(ch==','){
            ch='\t';
        }
        putchar(ch);
    }

    // Close the file
    fclose(file);

    return;
}

//Searching marks of a student
void searchMarks(int roll){
    typedef struct {
    int rollno;
    int IT101;
    int PH100;
    int HS101;
    int MA101;
    int EC100;
    } StudentMarks;

    StudentMarks marks;  // Instance of the structure
    FILE *file = fopen("report.csv", "a");  // Open the file for reading

    if (file==NULL) {
        printf("Error: Could not open marks file.\n");
        return;
    }

    int found = 0;

    // Read data using fscanf in a loop
    while (fscanf(file, "%d,%d,%d,%d,%d,%d", 
                  &marks.rollno, &marks.IT101, &marks.PH100, 
                  &marks.HS101, &marks.MA101, &marks.EC100) == 6) {
        if (marks.rollno == roll) {
            printf("\nMarks Found:\n");
            printf("Roll No: %d\n", marks.rollno);
            printf("IT101: %d\n", marks.IT101);
            printf("PH100: %d\n", marks.PH100);
            printf("HS101: %d\n", marks.HS101);
            printf("MA101: %d\n", marks.MA101);
            printf("EC100: %d\n", marks.EC100);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No marks found for Roll No: %d\n", roll);
    }

    fclose(file);  // Close the file
    return;
}

//main interface
int main(){
    while(1){
        
        while(1){//taking task
            printf("\n=============================\n");
            printf("1.Student details.\n");
            printf("2.Student report.\n");
            printf("3.Close program\n");
            printf("=============================\n");
            int ch;
            printf("Which platform you want to use:");
            scanf("%d",&ch);
            //Student details section
            if(ch==1){
                printf("\n\t\t=============================\n");
                printf("\t\tWelcome to student details section\n");
                printf("\n\t\t=============================\n");
                while(1){
                        //Open student details section
                        printf("\n=============================\n");
                        printf("1. Add Record\n");
                        printf("2. Show all Record\n");
                        printf("3. Search Record\n");
                        printf("0. Exit\n");
                        printf("=============================\n");
                        //taking task
                        int ch;
                        printf("Enter task to perform:");
                        scanf("%d",&ch);

                        //adding record
                        if(ch==1){
                            int rollno;
                            printf("Enter roll number:");
                            scanf("%d",&rollno);
                            addRecord(rollno);
                        }

                        //showing records
                        else if(ch==2){
                            printf("\n\n");
                            showRecords();
                        }

                        //searching record
                        else if(ch==3){
                            int rollno;
                            printf("Enter roll no for search:");
                            scanf("%d", &rollno);
                            searchRecord(rollno);
                        }

                        //Exiting
                        else if(ch==0)
                            break;
                        
                        else{
                            printf("\n\nWrong choice entered\n");
                            continue;
                            }
                }
            }

            //Student report section
            else if(ch==2){
                printf("\n\t\t========================================\n");
                printf("\t\tWelcome to student report section\n");
                printf("\t\t========================================\n");
                while(1){
                    printf("\n=============================\n");
                    printf("1. Add  marks of a student\n");
                    printf("2. Show marks of all students \n");
                    printf("3. Search marks of a studnet\n");
                    printf("0. Exit\n");
                    printf("=============================\n");
                    //taking task
                    int ch;
                    printf("Enter task to perform:");
                    scanf("%d",&ch);  
                    if(ch==1){
                        int rollno;
                        printf("Enter roll number:");
                        INPUT(rollno);
                        addMarks(rollno);
                    }
                    //showing records
                    else if(ch==2){
                        printf("\n\n");
                        showMarks();
                    }
                    
                    //searching record
                    else if(ch==3){
                        int rollno;
                        printf("Enter roll no for search:");
                        INPUT(rollno);
                        searchMarks(rollno);
                    }

                    //Exiting
                    else if(ch==0){
                        break;
                    }

                    else{
                        printf("\n\nWrong choice entered\n");
                        continue;
                    }


                }
               
            }

            //exiting the program
            else if(ch==3){
                break;
            }
            
            else{
                printf("\n\n******Wrong choice entered*****\n\n");
                continue;
            }

            }
            break;
        }
    
    return 0;
}