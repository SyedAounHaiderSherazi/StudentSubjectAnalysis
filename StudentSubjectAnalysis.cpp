#include <iostream>
#include<fstream>
#include<iomanip>
using namespace std;
//q3 functions
void Input(char name[], int subject1[], int subject2[], int subject3[], const int maximum_size, const int records)
{
	ifstream filein("grades.txt");          // Open the file for reading
	if (filein.fail())             // Check if the file opening is successful
	{
		cout << "Could not open file!";
		system("pause");
		exit(0);
	}

	int temp;
	// Read the total number of records from the file
	filein >> temp;

	char chr;
	filein.get(chr);
	for (int i = 0; i < records; i++)
	{
		// Read and store student names
		filein.get(chr);
		for (int j = 0; chr != ','; j++)
		{
			name[i * maximum_size + j] = chr;
			filein.get(chr);
		}

		// Read and store Subject 1 grades
		filein.get(chr);
		while (chr != ',')
		{
			subject1[i] = subject1[i] * 10 + (int)(chr - '0');
			filein.get(chr);
		}

		// Read and store Subject 2 grades
		filein.get(chr);
		while (chr != ',')
		{
			subject2[i] = subject2[i] * 10 + (int)(chr - '0');
			filein.get(chr);
		}

		// Read and store Subject 3 grades
		filein >> subject3[i];

		filein.get(chr);
	}
	filein.close();
}
void Output(char name[], int subject1[], int subject2[], int subject3[], const int maximum_size, const int records)
{
	cout << left << "RECORD  NAME           SUBJECT1  SUBJECT2  SUBJECT3\n";
	for (int i = 0; i < records; i++)
	{
		cout << setw(8) << i + 1;
		for (int j = 0; j < maximum_size; j++)
			cout << name[i * maximum_size + j];
		cout << setw(10) << subject1[i] << setw(10) << subject2[i] << subject3[i] << "\n\n";
	}
}
void Students_average(char name[], int subject1[], int subject2[], int subject3[], const int maximum_size, const int records)
{
	cout << left << "RECORD  NAME           AVERAGE\n";
	for (int i = 0; i < records; i++)
	{
		cout << setw(8) << i + 1;
		for (int j = 0; j < maximum_size; j++) cout << name[i * maximum_size + j];
		cout << fixed << setprecision(3) << showpoint << (subject1[i] + subject2[i] + subject3[i]) / 3.0 << "\n\n";
	}
}
void Subjects_average(int subject1[], int subject2[], int subject3[], const int records)
{
	cout << "Subject 1: ";
	double average = 0;
	for (int i = 0; i < records; i++)average += subject1[i];
	cout << fixed << setprecision(3) << showpoint << average / records;
	cout << "\nSubject 2: ";
	average = 0;
	for (int i = 0; i < records; i++)average += subject2[i];
	cout << fixed << setprecision(3) << showpoint << average / records;
	cout << "\nSubject 3: ";
	average = 0;
	for (int i = 0; i < records; i++)average += subject3[i];
	cout << fixed << setprecision(3) << showpoint << average / records << "\n\n";
}
// Function to find and display student with the highest average and subject with the lowest average
void Highest_and_lowest_average(char name[], int subject1[], int subject2[], int subject3[], const int maximum_size, const int records)
{
	cout << "Student with Highest Average:\n\n";
	int highest_index = 0;
	double highest = -1;
	for (int i = 0; i < records; i++)
		if ((subject1[i] + subject2[i] + subject3[i]) / 3.0 > highest)
		{
			highest = (subject1[i] + subject2[i] + subject3[i]) / 3.0;
			highest_index = i;
		}
	cout << left << "RECORD  NAME           AVERAGE\n";
	cout << setw(8) << highest_index + 1;
	for (int j = 0; j < maximum_size; j++)
		cout << name[highest_index * maximum_size + j];
	cout << fixed << setprecision(3) << showpoint << highest << "\n\n";
	cout << "Subject with Lowest Average:\n\n";
	int lowest_number = 0;
	double lowest = 100, tempr = 0;
	for (int i = 0; i < records; i++)tempr = tempr + subject1[i];
	if (tempr / records < lowest) { lowest = tempr / records; lowest_number = 1; }
	tempr = 0;
	for (int i = 0; i < records; i++)tempr = tempr + subject2[i];
	if (tempr / records < lowest) { lowest = tempr / records; lowest_number = 2; }
	tempr = 0;
	for (int i = 0; i < records; i++)tempr = tempr + subject3[i];
	if (tempr / records < lowest) { lowest = tempr / records; lowest_number = 3; }
	cout << "SUBJECT  AVERAGE\n";
	cout << setw(9) << lowest_number << fixed << setprecision(2) << showpoint << lowest << "\n\n";
}
// Function to perform various analyses and write results to "analysis.txt"
void Analysis(char name[], int subject1[], int subject2[], int subject3[], const int maximum_size, const int records)
{
	ofstream fileout("analysis.txt");
	fileout << "Grades:\n\n";
	fileout << left << "RECORD  NAME           SUBJECT1  SUBJECT2  SUBJECT3\n";
	for (int i = 0; i < records; i++)
	{
		fileout << setw(8) << i + 1;
		for (int j = 0; j < maximum_size; j++) fileout << name[i * maximum_size + j];
		fileout << setw(10) << subject1[i] << setw(10) << subject2[i] << subject3[i] << "\n\n";
	}
	fileout << "\nAverage of Students:\n\n";
	fileout << left << "RECORD  NAME           AVERAGE\n";
	for (int i = 0; i < records; i++)
	{
		fileout << setw(8) << i + 1;
		for (int j = 0; j < maximum_size; j++) fileout << name[i * maximum_size + j];
		fileout << setw(10) << fixed << setprecision(3) << showpoint << (subject1[i] + subject2[i] + subject3[i]) / 3.0 << "\n\n";
	}
	fileout << "\nAverage of Subjects:\n\n";
	fileout << "Subject 1: ";
	double average = 0;
	for (int i = 0; i < records; i++)average = average + subject1[i];
	fileout << fixed << setprecision(3) << showpoint << average / records;
	fileout << "\nSubject 2: ";
	average = 0;
	for (int i = 0; i < records; i++)average = average + subject2[i];
	fileout << fixed << setprecision(3) << showpoint << average / records;
	fileout << "\nSubject 3: ";
	average = 0;
	for (int i = 0; i < records; i++)average = average + subject3[i];
	fileout << fixed << setprecision(3) << showpoint << average / records << "\n\n";
	fileout << endl;
	fileout << "Student with teh Highest Average:\n\n";
	int highest_index = 0;
	double highest = -1;
	for (int i = 0; i < records; i++) if ((subject1[i] + subject2[i] + subject3[i]) / 3.0 > highest) { highest = (subject1[i] + subject2[i] + subject3[i]) / 3.0; highest_index = i; }
	fileout << left << "RECORD  NAME           AVERAGE\n";
	fileout << setw(8) << highest_index + 1;
	for (int j = 0; j < maximum_size; j++) fileout << name[highest_index * maximum_size + j];
	fileout << fixed << setprecision(2) << showpoint << highest << "\n\n";
	fileout << "Subject with Lowest Average:\n\n";
	int lowest_number = 0;
	double lower = 100, tempr = 0;
	for (int i = 0; i < records; i++)tempr = tempr + subject1[i];
	if (tempr / records < lower)
	{
		lower = tempr / records; lowest_number = 1;
	}
	tempr = 0;
	for (int i = 0; i < records; i++)tempr = tempr + subject2[i];
	if (tempr / records < lower)
	{
		lower = tempr / records; lowest_number = 2;
	}
	tempr = 0;
	for (int i = 0; i < records; i++)tempr = tempr + subject3[i];
	if (tempr / records < lower)
	{
		lower = tempr / records; lowest_number = 3;
	}
	fileout << "SUBJECT  AVERAGE\n";
	fileout << setw(9) << lowest_number << fixed << setprecision(2) << showpoint << lower << "\n\n";
	fileout.close();
}
// Function to calculate and store average of students in an array
void Store_student_average(int subject1[], int stubject2[], int stubject3[], const int records, double Students_avg[])
{
	for (int i = 0; i < records; i++)
		Students_avg[i] = (subject1[i] + stubject2[i] + stubject3[i]) / 3.0;
}
// Function to calculate and store average of each subject in an array
void Store_subject_average(int Subject1[], int Subject2[], int Subject3[], const int records, double AverageSubjects[])
{
	double average = 0;
	for (int i = 0; i < records; i++)
		average = average + Subject1[i];
	AverageSubjects[0] = average / records;
	average = 0;
	for (int i = 0; i < records; i++)
		average = average + Subject2[i];
	AverageSubjects[1] = average / records;
	average = 0;
	for (int i = 0; i < records; i++)
		average = average + Subject3[i];
	AverageSubjects[2] = average / records;
}
// Function to write student averages to "student_averages.txt"
void Writing_average_of_student_to_file(char name[], const int maximum_size, const int records, double Students_average[])
{
	ofstream fout("student_averages.txt");
	fout << "NAME           AVERAGE\n";
	for (int i = 0; i < records; i++)
	{
		for (int j = 0; j < maximum_size; j++) fout << name[i * maximum_size + j];
		fout << fixed << setprecision(2) << showpoint << Students_average[i] << endl;
	}
	fout.close();
}
// Function to write subject averages to "subject_averages.txt"
void Writing_average_of_subject_to_file(double Subjects_average[])
{
	ofstream fout("subject_averages.txt");
	fout << "Subject 1: " << fixed << setprecision(3) << showpoint << Subjects_average[0] << endl;
	fout << "Subject 2: " << fixed << setprecision(3) << showpoint << Subjects_average[1] << endl;
	fout << "Subject 3: " << fixed << setprecision(3) << showpoint << Subjects_average[2] << endl;
	fout.close();
}

int main()
//q3
{
	cout << ".......................Q3............................" << endl;

	const int maximum_size = 20, maximum_students = 100;
	int records, student1[maximum_students] = { 0 }, student2[maximum_students] = { 0 }, student3[maximum_students] = { 0 };
	char name[maximum_students * maximum_size];
	for (char& ch : name)ch = ' ';

	ifstream fin("grades.txt");
	if (fin.fail()) //Check
	{
		cout << "Could not open file!";
		system("pause");
		return 0;
	}
	fin >> records;
	fin.close();
	Input(name, student1, student2, student3, maximum_size, records);

	cout << "Grades:\n\n";
	Output(name, student1, student2, student3, maximum_size, records);
	cout << "\nAverage of Students:\n\n";
	Students_average(name, student1, student2, student3, maximum_size, records);
	cout << "\nAverage of Subjects:\n\n";
	Subjects_average(student1, student2, student3, records);
	cout << endl;
	Highest_and_lowest_average(name, student1, student2, student3, maximum_size, records);
	Analysis(name, student1, student2, student3, maximum_size, records);
	double Students_avg[maximum_students] = { 0 };
	Store_student_average(student1, student2, student3, records, Students_avg);
	double subjects_average[3] = { 0 };
	Store_subject_average(student1, student2, student3, records, subjects_average);
	Writing_average_of_student_to_file(name, maximum_size, records, Students_avg);
	Writing_average_of_subject_to_file(subjects_average);
}