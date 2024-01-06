#include<iostream>
#include<fstream>
using namespace std;
class Student{
    public:
       string name[50];
       int index1=0,index2=0,index3=0;
       int grade[250];
       string saveDataArray[100];
       string subject[5]={"English","Mathematics","Physics","Chemistry","Moral Science"};
    int displayMenu(){
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
void student_grade(){
    for(int i=0;i<5;i++){
        cout<<"Enter marks of "<<subject[i]<<endl;
        cin>>grade[index2++];}
}
void addStudent(){
     cout<<"Enter Student Name: "<<endl;
    cin>>name[index1++];
    student_grade();
    data(index1-1,index2-5);
}
void displayAllStudents(){    
    cout<<endl<<"Student Data: "<<endl;
    for(int i=0;i<index3;i++){
        cout<<saveDataArray[i]<<endl;}
}
};//class Student
class GradeTracker:public Student{
    public:
/*Returning the index of the name*/
int return_index(string word){
    int pointer=-1;
    for(int i=0;i<index1;i++){
        if(word == name[i]){
            pointer=i;
            break; }
    }
    return pointer;
}
void deleteStudent(){
    string changes;
    cout<<"Enter the name of student you want to remove: "<<endl;
    cin>> changes;
    int pointer=return_index(changes);
    if(pointer == -1){
        cout<<"Name not found! Re-enter the name: "<<endl;
        deleteStudent();}
    else{
       //deleting from the saveDataArray
    for(int i=pointer;i<(index3-1);i++){
        saveDataArray[i]=saveDataArray[i+1];
    }
    index3--;//updating the index after deletion
    //deleting from name[array]
    for(int i=pointer;i<(index1-1);i++){
        name[i]=name[i+1];
    }
    index1--;
    //deletion from grades[array]
    for(int i=pointer;i<(index2-6);i++){
       grade[i]=grade[i+1];
    }
    index2-=5; } //else block 
}
float calculateAverage(){
    float avg;int sum=0;
     for(int i=0;i<index2;i++){
      sum+=grade[i];
     }
     avg=sum/index2;
     return avg;
}
void findTopScorer(){
    int topScore[index2/5];
    int sum=0,flag=0,num=0,scorerStudent=0;
    for(int i=0;i<index2;i++){
     sum+=grade[i];flag+=1;
     if(flag==5){
        topScore[num++]=sum;
        sum=0;
        flag=0;}
    }
    for(int i=0;i<num;i++){
        if(topScore[i]>scorerStudent){
            scorerStudent=topScore[i];
           flag=i;/*it stores the index of the top scoring student*/ }
    }
   cout<<"The Top Scorer is:"<<endl;
   cout<<saveDataArray[flag]<<endl;
}
void searchStudent(){
    string search;
    cout<<"Enter Student Name you want to search: "<<endl;
    cin>>search;
    int pointer=return_index(search);
    if(pointer == -1){
        cout<<"Name not found! Re-enter the name: "<<endl;
        searchStudent(); }
    else{
        cout<<"Name Found in our data: "<<endl;
        cout<<saveDataArray[pointer]<<endl;}
}
int addition(int array[],int pointer){
    int sum=0;
    for(int i=0;i<pointer;i++){
        sum+=array[i];}
        return sum;
}
void viewSubjectPerformance(){
    int english[index2/5];
    int maths[index2/5];
    int physics[index2/5];
    int chemistry[index2/5];
    int moralSc[index2/5];
    int pointer=0;
    for(int i=0;i<index2;i+=5){
      english[pointer]=grade[i];
      maths[pointer]=grade[i+1];
      physics[pointer]=grade[i+2];
      chemistry[pointer]=grade[i+3];
      moralSc[pointer]=grade[i+4];
      pointer++;
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
void displayPassingStudents(){
    int studentGrades[index1][5];
    int pointer=0;
    //saving the grades as a DDA to make calculations easier
    for(int row=0;row<index1;row++){
        for(int col=0;col<5;col++){
            studentGrades[row][col]=grade[pointer++];}
    }
    int flag=0;
    cout<<"The Students with a Passing Grade of 35: "<<endl;
     for(int row=0;row<index1;row++){
        for(int col=0;col<5;col++){
            if(studentGrades[row][col]<35){
                flag+=1;
            }
        }
        if(flag>=2){
            flag=0;
            continue;}
        else{
            cout<<saveDataArray[row]<<endl;
            flag=0; }
    }
}
void updateStudentInfo(){
     string search;
    cout<<"Enter Student Name you want to update: "<<endl;
    cin>>search;
    int pointer=return_index(search);
    if(pointer == -1){
        cout<<"Name not found! Re-enter the name: "<<endl;
        updateStudentInfo();
    }
    else{
        int indexing=(pointer*5);
        cout<<"Enter Updated Information:"<<endl;
        for(int i=0;i<5;i++){
            cout<<"Score in "<<subject[i]<<": "<<endl;
            cin>>grade[indexing++];
        }
        indexing=pointer*5;
        saveDataArray[pointer]=(name[pointer]+"\t\t|"+to_string(grade[indexing])+"\t"+to_string(grade[indexing+1]) +"\t"+to_string(grade[indexing+2]) +"\t"+to_string(grade[indexing+3]) +"\t"+to_string(grade[indexing+4])+" |");
    }
}
void saveToFile(){
ofstream outputFile;
outputFile.open("StudentGrade.txt");
if(outputFile.is_open()){
    for(int i=0;i<index3;i++){
        outputFile<<saveDataArray[i]<<endl;
    }
    cout<<"Data Saved Sucessfully in 'StudentGrade.txt' File."<<endl;
}
else{
    cout<<"File could not be opened."<<endl;
}
outputFile.close();
}
void process(){
    int choice=displayMenu();
    float averageGrade;
    switch (choice)
 {
    case 1://Adding student name
    addStudent();
    break;
    case 2://display students
    checkCondition();
    displayAllStudents();
    break;
    case 3://average grades
    checkCondition();
    averageGrade=calculateAverage();
    cout<<endl<<"The Average Grades of all students: "<<averageGrade<<endl;
    break;
    case 4://top scorer
    checkCondition();
    findTopScorer();
    break;
    case 5://search for a student
    checkCondition();
    searchStudent();
    break;
    case 6://subject-wise performance
    checkCondition();
    viewSubjectPerformance();
    break;
    case 7://students with passing grade
    checkCondition();
    displayPassingStudents();
    break;
    case 8://update student information
    checkCondition();
    updateStudentInfo();
    break;
    case 9://delete a student
    checkCondition();
    deleteStudent();
    case 10://saving details to a file
    checkCondition();
    saveToFile();
    break;
    case 11://exit
    exit(0);//to exit from the code
    break;
    default:cout<<"Invalid Input! Please select the correct number."<<endl;
    break;
 }
 if(choice!=11){
    process();}
}
void checkCondition(){//this function checks if the array data is empty and displays an appt. message
    if(index1==0){
        cout<<"Invalid Input as there is no data available."<<endl;
        process();}
}
};
int main()
{ 
    GradeTracker obj2;
    obj2.process();
    return 0;
}