#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// Student Struct
typedef struct student{
    char first_name[50]; //change to string
    char last_name[50]; //change to string
    int id;
    float math_grade;
    float music_grade;
    float pe_grade;
} Student;


/*----Globals----*/
Student student_array[100];

int student_count = 0;
/*---------------*/


/*---Functions--*/
void add_student(char first_name[50] , char last_name[50], int id,
                 float math_grade, float music_grade, float pe_grade);
void export_data();
void goodstanding();
void import_data();
void list_students(); /* dummy test function*/
void mean();
void print_data(int stud_id);
void read_data(int i_max); /* dummy test function*/
void remove();
void search();
/*--------------*/

int main(void) {

    char choice;

    for(;;) {

    scanf("%1c", &choice);

    switch(choice){
        case 'A':
            char first_name[50];
            char last_name[50];
            int id;
            float math_grade;
            float music_grade;
            float pe_grade;
            scanf(" %s %s %d %f %f %f", first_name, last_name, &id,
                                        &math_grade, &music_grade, &pe_grade
                 );

            add_student(first_name, last_name, id, math_grade, music_grade, pe_grade);
            break;
        /*case 'D':*/
            /*remove();*/
            /*break;*/
        /*case 'E':*/
            /*export_data();*/
            /*break;*/
        /*case 'G':*/
            /*goodstanding();*/
            /*break;*/
        /*case 'I':*/
            /*import_data();*/
            /*break;*/
        case 'L':
            list_students();
            break;
        /*case 'M':*/
            /*mean();*/
            /*break;*/
        /*case 'P':*/
            /*print_data(stud_id);*/
            /*break;*/
        case 'Q':
            goto quit;
            break;
        /*case 'S':*/
            /*search();*/
            /*break;*/
        }
    }

quit: ;

    return 0;
}

// Create new student and add to student array
void add_student(char first_name[50] , char last_name[50], int id,
                 float math_grade, float music_grade, float pe_grade) {

    strcpy(student_array[student_count].first_name, first_name);
    strcpy(student_array[student_count].last_name, last_name);
    student_array[student_count].id = id;
    student_array[student_count].math_grade = math_grade;
    student_array[student_count].music_grade = music_grade;
    student_array[student_count].pe_grade = pe_grade;

    student_count++;

}

void list_students() {
    for(int i = 0; i < student_count; i++){
        printf("%s %s [%d]:\n", student_array[i].first_name, student_array[i].last_name, student_array[i].id);
        printf("        MATH:   %4.2f\n", student_array[i].math_grade);
        printf("        MUSIC:  %4.2f\n", student_array[i].music_grade);
        printf("        PE:     %4.2f\n", student_array[i].pe_grade);
        printf("                %4.2f\n", (student_array[i].math_grade + student_array[i].music_grade + student_array[i].pe_grade)/3.0f);
    }
}

void export_data() {}
void goodstanding() {}
void import_data() {}
void print_data() {}
void remove() {}
void search() {}
