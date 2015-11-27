#include "stdio.h"
#include "stdlib.h"

#include "functions.h"

// Student Struct
typedef struct student{
    char first_name[50]; //change to string
    char last_name[50]; //change to string
    int id;
    float math_grade;
    float music_grade;
    float pe_grade;
} Student;

Student student_array[100];

int i = 0;
int i_max = 0;
//int stud_id;

void read_data(int i_max); /* dummy test function*/
//void delete();
//void export();
//void goodstanding();
//void import();
void list_data(int i_max); /* dummy test function*/
void print_data(int stud_id);
void search();

int main(void) {
    
    char choice;
    
    for(;;){
    scanf("%1c", &choice);
    
    switch(choice){
        case 'A':
            i_max = i;
            i++;
            read_data(i_max);
            break;
        /*case 'D':
            delete();
            break;*/
        /*case 'E':
            export();
            break;*/
        /*case 'G':
            goodstanding();
            break;*/
        /*case 'I':
            import();
            break;*/
        case 'L':
            list_data(i_max);
            break;
        /*case 'M':
            mean();
            break;*/
        /*case 'P':
            print_data(stud_id);
            break;*/
        case 'Q':
            goto quit;
            break;
        /*case 'S':
            search();
            break;*/
        }
    
        /*if(choice == 'A'){
         scanf(" %s %s %d %d %d %d", student_array[i].first_name, student_array[i].last_name, &student_array[i].id, &student_array[i].math_grade, &student_array[i].music_grade, &student_array[i].pe_grade);
         printf("\n%s %s %d %d %d %d\n", student_array[i].first_name, student_array[i].last_name, student_array[i].id, student_array[i].math_grade, student_array[i].music_grade, student_array[i].pe_grade);
         }*/
    }

quit: ;
    
    return 0;
}

void read_data(int i_max)
{
    //int i = 0;
    
    scanf(" %s %s %d %f %f %f", student_array[i_max].first_name, student_array[i_max].last_name, &student_array[i_max].id, &student_array[i_max].math_grade, &student_array[i_max].music_grade, &student_array[i_max].pe_grade);
}

void list_data(int i_max)
{
    //int i = 0;
    
    for(i = 0; i <= i_max; i++){
        printf("%s %s [%d]:\n", student_array[i].first_name, student_array[i].last_name, student_array[i].id);
        printf("        MATH:   %4.2f\n", student_array[i].math_grade);
        printf("        MUSIC:  %4.2f\n", student_array[i].music_grade);
        printf("        PE:     %4.2f\n", student_array[i].pe_grade);
        printf("                %4.2f\n", (student_array[i].math_grade + student_array[i].music_grade + student_array[i].pe_grade)/3.0f);
    }
    
    
    /*printf("\n%s %s %d %d %d %d\n", student_array[i].first_name, student_array[i].last_name, student_array[i].id, student_array[i].math_grade, student_array[i].music_grade, student_array[i].pe_grade);*/
}
