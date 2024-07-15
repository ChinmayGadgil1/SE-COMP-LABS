#include <stdio.h>
#include <string.h>

struct name{
  	char firstName[20];
  	char middleName[20];
  	char lastName[20];
};

struct subjectSchema{
	
	char subjectCode[20];
	float marks;
	char grade;
	int gp;
};

struct semester{
	
	int no_of_subjects;
	float SGPA;
	char grade;
	float CGPA;
	struct subjectSchema sub[10];
	
};

struct studentMarkSheet{

	struct name n;
	int rollNo;
	struct semester sem[8];
	

};

float calcSGPA(int sem, int subjects ,struct studentMarkSheet stud){

	int j;
	float SGPA;
	
		float sum = 0;
		for(j=0;j<subjects; j++){
		
			sum = sum+stud.sem[sem].sub[j].gp ;
		}
		stud.sem[sem].SGPA = sum/stud.sem[sem].no_of_subjects;
	
		return stud.sem[sem].SGPA;

	
	
}

void display(struct studentMarkSheet stud){
	int i;
	printf("\nStudent Name: %s %s %s\n",stud.n.firstName,stud.n.middleName,stud.n.lastName);
	printf("Student rollNo: %d\n",stud.rollNo);
	printf("Student CGPA: %f\n\n",stud.sem[1].CGPA);

	printf("\nsem 1 data: SGPA %f \n",stud.sem[0].SGPA);
	printf("subject_code\tsubject_marks\tsubject_grade\tsubject_gradepoint\n");
	for(i=0;i<stud.sem[0].no_of_subjects; i++){
		printf("%s\t\t%f\t\t%c\t\t%d\n",stud.sem[0].sub[i].subjectCode,stud.sem[0].sub[i].marks,stud.sem[0].sub[i].grade,stud.sem[0].sub[i].gp);
	}	
	

printf("\nsem 2 data: SGPA %f \n",stud.sem[1].SGPA);
	printf("subject_code\tsubject_marks\tsubject_grade\tsubject_gradepoint\n");
	for(i=0;i<stud.sem[1].no_of_subjects; i++){
		printf("%s\t\t%f\t\t%c\t\t%d\n",stud.sem[1].sub[i].subjectCode,stud.sem[1].sub[i].marks,stud.sem[1].sub[i].grade,stud.sem[1].sub[i].gp);
	}	
	





}

int main(){
	
	struct studentMarkSheet stud;
	
	int subjects,i=0,j=0;
	
	printf("Enter the first name: ");
	scanf("%s",stud.n.firstName);
	printf("Enter the middle name: ");
	scanf("%s",stud.n.middleName);
	printf("Enter the last name: ");
	scanf("%s",stud.n.lastName);
	printf("Enter the rollNo: ");
	scanf("%d",&stud.rollNo);
	

	for(j =0; j<2; j++){

	printf("Enter the number of subjects for sem %d: ",j);
	scanf("%d",&subjects);
	stud.sem[j].no_of_subjects = subjects;
	
	for(i=0; i<subjects; i++){
		printf("Enter the subject code: ");
		scanf("%s",stud.sem[j].sub[i].subjectCode);
		printf("Enter the marks : ");
		scanf("%f",&stud.sem[j].sub[i].marks);
		if(stud.sem[j].sub[i].marks <= 100 && stud.sem[j].sub[i].marks >84){
			stud.sem[j].sub[i].grade ='O';
			stud.sem[j].sub[i].gp = 10;
		}else if(stud.sem[j].sub[i].marks <= 84 && stud.sem[j].sub[i].marks >75){
			stud.sem[j].sub[i].grade ='A';
			stud.sem[j].sub[i].gp = 9;
		}else if(stud.sem[j].sub[i].marks <= 75 && stud.sem[j].sub[i].marks >65){
			stud.sem[j].sub[i].grade ='B';
			stud.sem[j].sub[i].gp = 8;
		}else if(stud.sem[j].sub[i].marks <= 65 && stud.sem[j].sub[i].marks >55){
			stud.sem[j].sub[i].grade ='C';
			stud.sem[j].sub[i].gp = 7;
		}else if(stud.sem[j].sub[i].marks <= 55 && stud.sem[j].sub[i].marks >45){
			stud.sem[j].sub[i].grade ='D';
			stud.sem[j].sub[i].gp = 6;
		}else if(stud.sem[j].sub[i].marks <= 45 && stud.sem[j].sub[i].marks >40){
			stud.sem[j].sub[i].grade ='E';
			stud.sem[j].sub[i].gp = 5;
		}else {
			stud.sem[j].sub[i].grade ='F';
			stud.sem[j].sub[i].gp = 4;
		}
	}

	}



	stud.sem[0].SGPA =  calcSGPA(0,stud.sem[0].no_of_subjects,stud);
	stud.sem[1].SGPA =  calcSGPA(1,stud.sem[1].no_of_subjects,stud);
	stud.sem[1].CGPA = (stud.sem[0].SGPA+stud.sem[1].SGPA) / 2.0;

	

	display(stud);
	

	
	return 0;
}
