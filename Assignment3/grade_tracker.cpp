#include<iostream>
#include<fstream>
using namespace std;
class Student{//class to store the name & grade array
    public:
       string name[50];//we can store the data of 50 students
       int index1=0,index2=0,index3=0;//index1- name[array], index2- grade[array], index3- saveDataArray[array]
       int grade[250];//array to store the students grades
       string saveDataArray[50];//array to store the concatenated string
       string subject[5]={"English","Mathematics","Physics","Chemistry","Moral Science"};
    int displayMenu(){//function for menu items display
    int choice;
    cout<<"STUDENT GRADE TRACKER MENU"<<endl;
    cout<<"1. Add Student"<<endl;
    cout<<"2. View All Students"<<endl;
    cout<<"3. Calculate Average Grades"<<endl;
    cout<<"4. Find Top Scorer"<<endl;
    cout<<"5. Search for a Student"<<endl;
    cout<<"6. View Subject Wise Performance"<<endl;
    cout<<"7. Display Students with Passing Grade"<<endl;
    cout<<"8. Update Student Information"<<endl;
    cout<<"9. Delete a Student"<<endl;
    cout<<"10. Save Student Details to File"<<endl;
    cout<<"11. Exit"<<endl;
    cout<<"Enter your choice using the number:"<<endl;
    cin>> choice;
    return choice;
}
void data(int i,int j){//this function adds the data to the final array
    saveDataArray[index3++]=(name[i]+"\t\t|"+to_string(grade[j])+"\t"+to_string(grade[j+1]) +"\t"+to_string(grade[j+2]) +"\t"+to_string(grade[j+3]) +"\t"+to_string(grade[j+4])+" |");
}
void student_grade(){//function which helps to take grade input from user
    for(int i=0;i<5;i++){
        cout<<"Enter marks of "<<subject[i]<<endl;
        cin>>grade[index2++];}
}
void addStudent(){//function to add a new student
     cout<<"Enter Student Name: "<<endl;
    cin>>name[index1++];
    student_grade();//this function will take input of grades
    data(index1-1,index2-5);//this function saves the name and grade as a string array
}
void displayAllStudents(){    //function to display information of all students
    cout<<endl<<"Student Data: "<<endl;
    for(int i=0;i<index3;i++){
        cout<<saveDataArray[i]<<endl;}
}
};//class Student block
class GradeTracker:public Student{//concept of inheritance used here
    public:
int return_index(string word){/*function for Returning the index of the name*/
    int pointer=-1;
    for(int i=0;i<index1;i++){
        if(word == name[i]){
            pointer=i;
            break; } //as soon as we find the name in the array the loop terminates
    }
    return pointer;
}
void deleteStudent(){//function to delete a student information
    string changes;
    cout<<"Enter the name of student you want to remove: "<<endl;
    cin>> changes;
    int pointer=return_index(changes);//this function returns the index of the name
    if(pointer == -1){
        cout<<"Name not found! Re-enter the name: "<<endl;
        deleteStudent();}//recursion technique used here
    else{
       //deleting from the saveDataArray
    for(int i=pointer;i<(index3-1);i++){
        saveDataArray[i]=saveDataArray[i+1];
    } index3--;//updating the index after deletion
    //deleting from name[array]
    for(int i=pointer;i<(index1-1);i++){
        name[i]=name[i+1];
    }index1--;//updating the index after deletion
    //deletion from grades[array]
    for(int i=pointer;i<(index2-6);i++){
       grade[i]=grade[i+1];
    } index2-=5; //updating the index after deletion
    } //else block 
}
void calculateAverage(){//function to calculate the average grade
    float avg;int sum=0;
     for(int i=0;i<index2;i++){
      sum+=grade[i];
     }
     avg=sum/index2;
    cout<<endl<<"The Average Grades of all students: "<<avg<<endl;
}
void findTopScorer(){//function to find the top scorer among all students
    int topScore[index2/5];//array to store the total marks of all students
    int sum=0,flag=0,num=0,scorerStudent=0;
    for(int i=0;i<index2;i++){
     sum+=grade[i];flag+=1;//the sum calculates the total marks of each student
     if(flag==5){//flag here is used a pointer for all 5 subjects
        topScore[num++]=sum;//storing the value in the topScore[array]
        sum=0;//reinitializing the value of sum 
        flag=0;}//reinitializing the value of flag
    }
    for(int i=0;i<num;i++){//loop to find the student with the top score
        if(topScore[i]>scorerStudent){
            scorerStudent=topScore[i];
           flag=i;/*it stores the index of the top scoring student*/ }
    }
   cout<<"The Top Scorer is:\t"<<saveDataArray[flag]<<endl;
}
void searchStudent(){//function to search for a student
    string search;
    cout<<"Enter Student Name you want to search: "<<endl;
    cin>>search;
    int pointer=return_index(search);//this function returns the index of the search name
    if(pointer == -1){
        cout<<"Name not found! Re-enter the name: "<<endl;
        searchStudent(); }//recursion technique used here
    else{
        cout<<"Name Found in our data:\t"<<saveDataArray[pointer]<<endl;}
}
int addition(int array[],int pointer){//function to add the elements of an array
    int sum=0;
    for(int i=0;i<pointer;i++){
        sum+=array[i];}
        return sum;
}
void viewSubjectPerformance(){//function to view subject-wise performance
    int english[index2/5];//array to store english marks
    int maths[index2/5];//array to store maths marks
    int physics[index2/5];//array to store physics marks
    int chemistry[index2/5];//array to store chemistry marks
    int moralSc[index2/5];//array to store moral science marks
    int pointer=0;//this will act as the index/size for the subject marks array
    for(int i=0;i<index2;i+=5){//this loop helps us to store the marks of each subject in individual arrays
      english[pointer]=grade[i];
      maths[pointer]=grade[i+1];
      physics[pointer]=grade[i+2];
      chemistry[pointer]=grade[i+3];
      moralSc[pointer]=grade[i+4];
      pointer++;//increament of pointer variable
    }
    cout<<endl<<"The Subject-wise Performance of Students : "<<endl;
    float avgPerformance,sum=0;
    sum=addition(english,pointer);
    avgPerformance=sum/pointer;
    cout<<"English: \t"<<avgPerformance<<endl;
     sum=addition(maths,pointer);
    avgPerformance=sum/pointer;
    cout<<"Mathematics: \t"<<avgPerformance<<endl;
     sum=addition(physics,pointer);
    avgPerformance=sum/pointer;
    cout<<"Physics: \t"<<avgPerformance<<endl;
     sum=addition(chemistry,pointer);
    avgPerformance=sum/pointer;
    cout<<"Chemistry: \t"<<avgPerformance<<endl;
     sum=addition(moralSc,pointer);
    avgPerformance=sum/pointer;
    cout<<"Moral Science: \t"<<avgPerformance<<endl;
}
void displayPassingStudents(){//function to display students with a passing grade
    int studentGrades[index1][5];//a DDA to store the grades of students
    int pointer=0;
    //saving the grades as a DDA to make calculations easier
    for(int row=0;row<index1;row++){
        for(int col=0;col<5;col++){
            studentGrades[row][col]=grade[pointer++];}
    }
    int flag=0;//this variable helps to check if a student has failed in 2 or more subjects 
    cout<<"The Students with a Passing Grade of 35: "<<endl;
     for(int row=0;row<index1;row++){
        for(int col=0;col<5;col++){
            if(studentGrades[row][col]<35){
                flag+=1;
            } }//inner for loop block
        if(flag>=2){
            flag=0;//reinitializing the flag variable
            continue;}//using the continue statement because we want to skip this iteration
        else{//this else block prints the student data who have the passing grade
            cout<<saveDataArray[row]<<endl;
            flag=0; }//reinitialized the value of flag
    }//outer for loop block
}
void updateStudentInfo(){//function to update the student's information
     string search;
    cout<<"Enter Student Name you want to update: "<<endl;
    cin>>search;
    int pointer=return_index(search);//this function returns the index of the name
    if(pointer == -1){
        cout<<"Name not found! Re-enter the name: "<<endl;
        updateStudentInfo();//recursion technique used here
    }
    else{
        int indexing=(pointer*5);//multiply pointer by 5 because we have 5 subjects and to reach the correct index of those grades
        cout<<"Enter Updated Information:"<<endl;
        for(int i=0;i<5;i++){//loop for updating the subect marks
            cout<<"Score in "<<subject[i]<<": "<<endl;
            cin>>grade[indexing++];
        }
        indexing=pointer*5;//reinitializing the value of indexing for re-storing the data in the savedataArray[]
        saveDataArray[pointer]=(name[pointer]+"\t\t|"+to_string(grade[indexing])+"\t"+to_string(grade[indexing+1]) +"\t"+to_string(grade[indexing+2]) +"\t"+to_string(grade[indexing+3]) +"\t"+to_string(grade[indexing+4])+" |");
    }
}
void saveToFile(){//function to save student details to a file
ofstream outputFile;//ofstram is the class and outputFile here is the object
outputFile.open("StudentGrade.txt");//StusdentGrade.txt is the file name and type
if(outputFile.is_open()){//checking if the file is open and creating the file if not
    for(int i=0;i<index3;i++){
        outputFile<<saveDataArray[i]<<endl;//storing the data in the outputFile from the array
    }
    cout<<"Data Saved Sucessfully in 'StudentGrade.txt' File."<<endl;
    outputFile.close();//closing the outputFile
}
else{
    cout<<"File could not be opened."<<endl;
}
}
void process(){//this function is main controller of the whole code with a menu-driven interface
    int choice=displayMenu();
    switch (choice)
 {
    case 1://Adding student name
    addStudent();
    break;
    case 2://display students
    checkCondition();//this checkCondition() checks if the data set array is empty or not
    displayAllStudents();
    break;
    case 3://average grades
    checkCondition();//this checkCondition() checks if the data set array is empty or not
    calculateAverage();
    break;
    case 4://top scorer
    checkCondition();//this checkCondition() checks if the data set array is empty or not
    findTopScorer();
    break;
    case 5://search for a student
    checkCondition();//this checkCondition() checks if the data set array is empty or not
    searchStudent();
    break;
    case 6://subject-wise performance
    checkCondition();//this checkCondition() checks if the data set array is empty or not
    viewSubjectPerformance();
    break;
    case 7://students with passing grade
    checkCondition();//this checkCondition() checks if the data set array is empty or not
    displayPassingStudents();
    break;
    case 8://update student information
    checkCondition();//this checkCondition() checks if the data set array is empty or not
    updateStudentInfo();
    break;
    case 9://delete a student
    checkCondition();//this checkCondition() checks if the data set array is empty or not
    deleteStudent();
    case 10://saving details to a file
    checkCondition();//this checkCondition() checks if the data set array is empty or not
    saveToFile();
    break;
    case 11://exit
    exit(0);//to exit from the code
    break;
    default:cout<<"Invalid Input! Please select the correct number."<<endl;
 }
 if(choice!=11){
    process();}
}
void checkCondition(){//this function checks if the array data is empty and displays an appt. message
    if(index1==0){
        cout<<"Invalid Input as there is no data available."<<endl;
        process();}
}
};//class GradeTracker block
int main()
{ 
    GradeTracker obj;//here 'obj' is the object for the GradeTracker class
    obj.process();//function call for process() which contains the controller code
    return 0;
}