#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void assign_student_values(struct Student *p, FILE *q);
int add_marks(struct Student *p);
int calculate_highest(int *p);
int calculate_lowest(int *p);
int top_mark(struct Student *p);

struct Student {
	char id[9];
	int marks[5];	
};

int main()
{	
	int i;
	int *totals = (int *)malloc(5*sizeof(int));
	int *topMarks = (int *)malloc(5*sizeof(int));
	FILE *f;
	f = fopen("student.txt", "r");
	struct Student *students = (Student *)malloc(5*sizeof(Student));	
	
	for(i = 0; i < 5; i++)
	{
		assign_student_values(&students[i], f);
	}	
	for(i = 0; i < 5; i++)
	{
		totals[i] = add_marks(&students[i]);
	}
	for(i = 0; i < 5; i++)
	{
		topMarks[i] = top_mark(&students[i]);
	}	
	
	int highest = calculate_highest(totals);
	int lowest = calculate_lowest(totals);
	free(totals);
	int single = calculate_highest(topMarks);
	free(topMarks);
	printf("%s %d\n",students[lowest].id, add_marks(&students[lowest]));
	printf("%s %d\n",students[highest].id, add_marks(&students[highest]));	
	printf("%s %d\n",students[single].id, top_mark(&students[single]));	
	free(students);
}

void assign_student_values(struct Student *p, FILE *q)
{	
	int i;
	fscanf(q, "%s", p->id);
	for(i = 0; i < 5; i++)
	{
		fscanf(q, "%d", &p->marks[i]);
	}
}

int add_marks(struct Student *p)
{
	int totalMark = 0;
	int i;
	for(i = 0; i < 5; i++)
	{
		totalMark += p->marks[i];
	}
	return totalMark;
}

int calculate_highest(int *p)
{
	int high = 0, i = 0, temp = p[i];
	while(i < 4)
	{
		if(temp < p[i + 1])
		{
			temp = p[i + 1];
			high = i + 1;
		}
		i++;
	}	
	return high;
}

int calculate_lowest(int *p)
{
	int high = 0, i = 0, temp = p[i];
	while(i < 4)
	{
		if(temp > p[i + 1])
		{
			temp = p[i + 1];
			high = i + 1;
		}
		i++;
	}	
	return high;
}

int top_mark(struct Student *p)
{
	int i = 0, temp = p->marks[i];
	while(i < 4)
	{
		if(temp < p->marks[i + 1])
		{
			temp = p->marks[i + 1];			
		}
		i++;
	}	
	return temp;
}