//// Students Performence Management System
//// Project done by : 25L-0528 and 25L-0516
//
//#include <iostream>
//#include <cstring>
//#include <string>
//#include<cctype>
//#include <fstream>
//#include <iomanip>
//using namespace std;
//
//struct students {
//	int RollNum[100];
//	string Name[100];
//	string section[100];
//	double TotalMarks[100] = { -1 };
//	char grade[100];
//
//	double quiz[100][3] = { -1 };        // Max Final Marks = 100
//	double assignment[100][2] = { -1 }; // Max assignment marks = 30
//	double mid[100] = { -1 };           // Max Mid marks = 50
//	double final[100] = { -1 };        // Max Final marks = 100
//};
//
//void SaveRecords(students& s, int NoofStudents) {
//	ofstream store("students.txt");
//	for (int i = 0; i < NoofStudents; i++) {
//		store << s.RollNum[i] << "|"
//			<< s.Name[i] << "|"
//			<< s.section[i] << "|"
//			<< s.assignment[i][0] << "|"
//			<< s.assignment[i][1] << "|"
//			<< s.quiz[i][0] << "|"
//			<< s.quiz[i][1] << "|"
//			<< s.quiz[i][2] << "|"
//			<< s.mid[i] << "|"
//			<< s.final[i] << "|"
//			<< s.TotalMarks[i] << "|"
//			<< s.grade[i] << endl;
//	}
//	store.close();
//}
//
//void AddStudent(students& s, int& NoofStudents) {
//	cin.ignore();
//label:	cout << "Enter Name: ";
//	getline(cin, s.Name[NoofStudents]);
//	if (s.Name[NoofStudents].empty()) {
//		cout << "Name cannot be empty!" << endl;
//		goto label;
//	}
//	for (int i = 0; s.Name[NoofStudents][i] != '\0'; i++) {
//		if (!isalpha(s.Name[NoofStudents][i]) && !isspace(s.Name[NoofStudents][i])) {
//			cout << "Invalid input! Name should only contain letters." << endl;
//			goto label;
//		}
//	}
//
//	bool check = false;
//	do {
//		cout << "Enter Roll No: ";
//		cin >> s.RollNum[NoofStudents];
//		while (s.RollNum[NoofStudents] < 1 || s.RollNum[NoofStudents]>100 || cin.fail())
//		{
//			cin.clear();
//			cin.ignore(1000, '\n');
//			cout << "Invalid value! Roll No must be between 1-100." << endl;
//			cout << "Enter Roll No: ";
//			cin >> s.RollNum[NoofStudents];
//		}
//		check = false;
//		for (int i = 0; i < NoofStudents; i++) {
//			if (s.RollNum[NoofStudents] == s.RollNum[i]) {
//				cout << "Roll No already exists! Enter a unique Roll No." << endl;
//				check = true;
//				break;
//			}
//		}
//	} while (check);
//
//	cin.ignore();
//section:
//	cout << "Enter Section: ";
//	getline(cin, s.section[NoofStudents]);
//	if (s.section[NoofStudents].empty()) {
//		cout << "Section cannot be empty!" << endl;
//		goto section;
//	}
//	for (int i = 0; i < s.section[NoofStudents].length(); i++) {
//		if (!isalpha(s.section[NoofStudents][i])) {
//			cout << "Invalid Input! Section should only contain letters." << endl;
//			goto section;
//		}
//	}
//
//	NoofStudents++;
//	cout << "Student Added!" << endl;
//	SaveRecords(s, NoofStudents);
//}
//
//void AddTotalMarks(students& s, int NoofStudents) {
//	int temproll;
//	cout << "Enter Roll Number: ";
//	cin >> temproll;
//	while (cin.fail()) {
//		cin.clear();
//		cin.ignore(1000, '\n');
//		cout << "Invalid input! Enter a valid Roll Number: ";
//		cin >> temproll;
//	}
//
//	int index = -1;
//	for (int i = 0; i < NoofStudents; i++) {
//		if (s.RollNum[i] == temproll) {
//			index = i;
//			break;
//		}
//	}
//
//	if (index == -1) {
//		cout << "Roll Number not found!" << endl;
//		return;
//	}
//
//	bool marks_missing = false;
//	for (int i = 0; i < 3; i++) {
//		if (s.quiz[index][i] == -1) {
//			marks_missing = true;
//			break;
//		}
//	}
//	for (int i = 0; i < 2; i++) {
//		if (s.assignment[index][i] == -1) {
//			marks_missing = true;
//			break;
//		}
//	}
//	if (s.mid[index] == -1) {
//		marks_missing = true;
//	}
//	if (s.final[index] == -1) {
//		marks_missing = true;
//	}
//
//	if (!marks_missing) {
//		cout << "Marks already entered! Calculating automatically.." << endl;
//		return;
//	}
//
//	if (marks_missing) {
//		do {
//			for (int i = 0; i < 2; i++) {
//				cout << "Enter marks for assignment " << i + 1 << ": ";
//				cin >> s.assignment[index][i];
//				while (cin.fail()) {
//					cin.clear();
//					cin.ignore(1000, '\n');
//					cout << "Invalid input! Enter a number: ";
//					cin >> s.assignment[index][i];
//				}
//				if (s.assignment[index][i] < 0 || s.assignment[index][i] > 30) {
//					cout << "Invalid input! Marks should be from 0-30" << endl;
//				}
//			}
//		} while (s.assignment[index][0] < 0 || s.assignment[index][0] > 30 ||
//			s.assignment[index][1] < 0 || s.assignment[index][1] > 30);
//
//		do {
//			for (int i = 0; i < 3; i++) {
//				cout << "Enter marks for quiz " << i + 1 << ": ";
//				cin >> s.quiz[index][i];
//				while (cin.fail()) {
//					cin.clear();
//					cin.ignore(1000, '\n');
//					cout << "Invalid input! Enter a number: ";
//					cin >> s.quiz[index][i];
//				}
//				if (s.quiz[index][i] < 0 || s.quiz[index][i] > 10) {
//					cout << "Invalid input: Marks should be from 0-10" << endl;
//				}
//			}
//		} while (s.quiz[index][0] < 0 || s.quiz[index][0] > 10 ||
//			s.quiz[index][1] < 0 || s.quiz[index][1] > 10 ||
//			s.quiz[index][2] < 0 || s.quiz[index][2] > 10);
//
//		do {
//			cout << "Enter Mid marks: ";
//			cin >> s.mid[index];
//			while (cin.fail()) {
//				cin.clear();
//				cin.ignore(1000, '\n');
//				cout << "Invalid input! Enter a number: ";
//				cin >> s.mid[index];
//			}
//			if (s.mid[index] < 0 || s.mid[index] > 50) {
//				cout << "Invalid input: Mid marks should be from 0-50" << endl;
//			}
//		} while (s.mid[index] < 0 || s.mid[index] > 50);
//
//		do {
//			cout << "Enter Final marks: ";
//			cin >> s.final[index];
//			while (cin.fail()) {
//				cin.clear();
//				cin.ignore(1000, '\n');
//				cout << "Invalid input! Enter a number: ";
//				cin >> s.final[index];
//			}
//			if (s.final[index] < 0 || s.final[index] > 100) {
//				cout << "Invalid Input! Final Marks must be from 0-100" << endl;
//			}
//		} while (s.final[index] < 0 || s.final[index] > 100);
//
//		cout << "Marks added successfully!" << endl;
//
//		SaveRecords(s, NoofStudents);
//	}
//}
//
//double TotalMarksCalculator(students& s, int NoofStudents) {
//	int temproll;
//	int index = -1;
//	double total = 0;
//
//	cout << "Enter Roll No: ";
//	cin >> temproll;
//	while (cin.fail()) {
//		cin.clear();
//		cin.ignore(1000, '\n');
//		cout << "Invalid input! Enter a valid Roll No: ";
//		cin >> temproll;
//	}
//
//	for (int i = 0; i < NoofStudents; i++) {
//		if (temproll == s.RollNum[i]) {
//			index = i;
//			break;
//		}
//	}
//	if (index == -1) {
//		cout << "Roll Number not found!" << endl;
//		return -1;
//	}
//
//	bool marks_missing = false;
//	for (int i = 0; i < 3; i++) {
//		if (s.quiz[index][i] == -1) {
//			marks_missing = true;
//			break;
//		}
//	}
//
//	if (!marks_missing) {
//		for (int i = 0; i < 2; i++) {
//			if (s.assignment[index][i] == -1) {
//				marks_missing = true;
//				break;
//			}
//		}
//	}
//
//	if (!marks_missing && s.mid[index] == -1) marks_missing = true;
//	if (!marks_missing && s.final[index] == -1) marks_missing = true;
//
//	if (marks_missing) {
//		cout << "Marks not entered yet! Please add marks first using option 2." << endl;
//		return -1;
//	}
//	else {
//		cout << "Calculating Total Marks..." << endl;
//	}
//
//	total = 0.0;
//	for (int i = 0; i < 3; i++) total += s.quiz[index][i];
//	for (int i = 0; i < 2; i++) total += s.assignment[index][i];
//	total += s.mid[index];
//	total += s.final[index];
//
//	s.TotalMarks[index] = total;
//	cout << "Total marks for RollNum " << s.RollNum[index] << " = " << total << endl;
//	SaveRecords(s, NoofStudents);
//	return total;
//}
//
//char GradeAssigner(students& s, int NoofStudents) {
//	int tempRollNo;
//	cout << "Enter Roll No: ";
//	cin >> tempRollNo;
//	while (cin.fail()) {
//		cin.clear();
//		cin.ignore(1000, '\n');
//		cout << "Invalid input! Enter a valid Roll No: ";
//		cin >> tempRollNo;
//	}
//
//	int index = -1;
//	for (int i = 0; i < NoofStudents; i++) {
//		if (s.RollNum[i] == tempRollNo) {
//			index = i;
//			break;
//		}
//	}
//	if (index == -1) {
//		cout << "Roll No not found!" << endl;
//		return ' ';
//	}
//
//	double tempTotal;
//
//	if (s.TotalMarks[index] != -1 && s.TotalMarks[index] != 0) {
//		tempTotal = s.TotalMarks[index];
//	}
//	else {
//		cout << "Total marks not calculated yet! Please calculate total marks first using option 3." << endl;
//		return ' ';
//	}
//
//	char Grade;
//	if (tempTotal >= 90) {
//		Grade = 'A';
//	}
//	else if (tempTotal >= 80) {
//		Grade = 'B';
//	}
//	else if (tempTotal >= 70) {
//		Grade = 'C';
//	}
//	else if (tempTotal >= 60) {
//		Grade = 'D';
//	}
//	else if (tempTotal >= 50) {
//		Grade = 'E';
//	}
//	else {
//		Grade = 'F';
//	}
//
//	s.grade[index] = Grade;
//	cout << "Grade for Roll No " << s.RollNum[index] << " is '" << Grade << "'" << endl;
//	SaveRecords(s, NoofStudents);
//	return Grade;
//}
//
//void UpdateRecord(students& s, int NoofStudents) {
//	int temproll;
//	int index = -1;
//	cout << "Enter Roll No: ";
//	cin >> temproll;
//	while (cin.fail()) {
//		cin.clear();
//		cin.ignore(1000, '\n');
//		cout << "Invalid input! Enter a valid Roll No: ";
//		cin >> temproll;
//	}
//
//	for (int i = 0; i < NoofStudents; i++) {
//		if (temproll == s.RollNum[i]) {
//			index = i;
//			break;
//		}
//	}
//	if (index == -1) {
//		cout << "Roll No not found!" << endl;
//		return;
//	}
//
//	int update;
//	cout << "Enter marks to update: " << endl;
//	cout << "1.Quiz" << endl;
//	cout << "2.Assignment" << endl;
//	cout << "3.Mid" << endl;
//	cout << "4.Final" << endl;
//	cin >> update;
//	while (cin.fail() || update < 1 || update > 4) {
//		cin.clear();
//		cin.ignore(1000, '\n');
//		cout << "Invalid choice! Enter 1-4: ";
//		cin >> update;
//	}
//
//	if (update == 1) {
//		do {
//			for (int i = 0; i < 3; i++) {
//				cout << "Enter marks for Quiz " << i + 1 << " : ";
//				cin >> s.quiz[index][i];
//				while (cin.fail()) {
//					cin.clear();
//					cin.ignore(1000, '\n');
//					cout << "Invalid input! Enter a number: ";
//					cin >> s.quiz[index][i];
//				}
//				if (s.quiz[index][i] < 0 || s.quiz[index][i] > 10) {
//					cout << "Invalid! Marks should be 0-10." << endl;
//				}
//			}
//		} while (s.quiz[index][0] < 0 || s.quiz[index][0] > 10 ||
//			s.quiz[index][1] < 0 || s.quiz[index][1] > 10 ||
//			s.quiz[index][2] < 0 || s.quiz[index][2] > 10);
//	}
//	if (update == 2) {
//		do {
//			for (int i = 0; i < 2; i++) {
//				cout << "Enter marks for assignment " << i + 1 << " : ";
//				cin >> s.assignment[index][i];
//				while (cin.fail()) {
//					cin.clear();
//					cin.ignore(1000, '\n');
//					cout << "Invalid input! Enter a number: ";
//					cin >> s.assignment[index][i];
//				}
//				if (s.assignment[index][i] < 0 || s.assignment[index][i] > 30) {
//					cout << "Invalid! Marks should be 0-30." << endl;
//				}
//			}
//		} while (s.assignment[index][0] < 0 || s.assignment[index][0] > 30 ||
//			s.assignment[index][1] < 0 || s.assignment[index][1] > 30);
//	}
//	if (update == 3) {
//		do {
//			cout << "Enter Mid marks: ";
//			cin >> s.mid[index];
//			while (cin.fail()) {
//				cin.clear();
//				cin.ignore(1000, '\n');
//				cout << "Invalid input! Enter a number: ";
//				cin >> s.mid[index];
//			}
//			if (s.mid[index] < 0 || s.mid[index] > 50) {
//				cout << "Invalid! Mid marks should be 0-50." << endl;
//			}
//		} while (s.mid[index] < 0 || s.mid[index] > 50);
//	}
//	if (update == 4) {
//		do {
//			cout << "Enter Final marks: ";
//			cin >> s.final[index];
//			while (cin.fail()) {
//				cin.clear();
//				cin.ignore(1000, '\n');
//				cout << "Invalid input! Enter a number: ";
//				cin >> s.final[index];
//			}
//			if (s.final[index] < 0 || s.final[index] > 100) {
//				cout << "Invalid! Final marks should be 0-100." << endl;
//			}
//		} while (s.final[index] < 0 || s.final[index] > 100);
//	}
//
//	cout << "Marks Updated!" << endl;
//	SaveRecords(s, NoofStudents);
//}
//
//void TopperIdentifier(students& s, int NoofStudents) {
//	if (NoofStudents == 0) {
//		cout << "No students available!" << endl;
//		return;
//	}
//	int index = 0;
//	double maxMarks = s.TotalMarks[0];
//
//	for (int i = 1; i < NoofStudents; i++) {
//		if (s.TotalMarks[i] > maxMarks) {
//			maxMarks = s.TotalMarks[i];
//			index = i;
//		}
//	}
//	cout << "Topper is Roll No " << s.RollNum[index] << " with Total Marks " << s.TotalMarks[index] << endl;
//}
//
//double average(students& s, int NoofStudents) {
//	double average = 0;
//	for (int i = 0; i < NoofStudents; i++) {
//		average += s.TotalMarks[i];
//	}
//	average /= NoofStudents;
//	return average;
//}
//
//void ShowStatistics(students& s, int NoofStudents) {
//	if (NoofStudents == 0) {
//		cout << "No students!" << endl;
//		return;
//	}
//	double avg;
//	int aboveAvg = 0;
//	cout << "Total Students: " << NoofStudents << endl;
//	avg = average(s, NoofStudents);
//	cout << "Average: " << avg << endl;
//	for (int i = 0; i < NoofStudents; i++) {
//		if (s.TotalMarks[i] > avg) {
//			aboveAvg++;
//		}
//	}
//	cout << "No of Students above average: " << aboveAvg << endl;
//	TopperIdentifier(s, NoofStudents);
//	cout << "\n========== STUDENT RECORDS ==========\n" << endl;
//	cout << setfill('-') << setw(95) << "" << endl;
//	cout << setfill(' ');
//
//	cout << "| " << left << setw(20) << "Name"
//		<< "| " << setw(12) << "Roll No"
//		<< "| " << setw(10) << "Section"
//		<< "| " << setw(15) << "Total Marks"
//		<< "| " << setw(8) << "Grade" << " |" << endl;
//
//	cout << setfill('-') << setw(95) << "" << endl;
//	cout << setfill(' ');
//
//	for (int i = 0; i < NoofStudents; i++) {
//		cout << "| " << left << setw(20) << s.Name[i]
//			<< "| " << setw(12) << s.RollNum[i]
//			<< "| " << setw(10) << s.section[i]
//			<< "| " << right << setw(15) << fixed << setprecision(2) << s.TotalMarks[i]
//			<< " | " << left << setw(8) << s.grade[i] << " |" << endl;
//	}
//
//	cout << setfill('-') << setw(95) << "" << endl;
//	cout << setfill(' ') << endl;
//}
//
//void DeleteRecord(students& s, int& NoofStudents) {
//	if (NoofStudents == 0) {
//		cout << "No records to delete!" << endl;
//		return;
//	}
//	int temproll, index = -1;
//	cout << "Enter Roll No to delete: ";
//	cin >> temproll;
//	while (cin.fail()) {
//		cin.clear();
//		cin.ignore(1000, '\n');
//		cout << "Invalid input! Enter a valid Roll No: ";
//		cin >> temproll;
//	}
//
//	for (int i = 0; i < NoofStudents; i++) {
//		if (s.RollNum[i] == temproll) {
//			index = i;
//			break;
//		}
//	}
//	if (index == -1) {
//		cout << "Roll number not found!" << endl;
//		return;
//	}
//
//	for (int i = index; i < NoofStudents - 1; i++) {
//		s.RollNum[i] = s.RollNum[i + 1];
//		s.Name[i] = s.Name[i + 1];
//		s.section[i] = s.section[i + 1];
//		s.TotalMarks[i] = s.TotalMarks[i + 1];
//		s.grade[i] = s.grade[i + 1];
//
//		for (int j = 0; j < 3; j++)
//			s.quiz[i][j] = s.quiz[i + 1][j];
//
//		for (int j = 0; j < 2; j++)
//			s.assignment[i][j] = s.assignment[i + 1][j];
//
//		s.mid[i] = s.mid[i + 1];
//		s.final[i] = s.final[i + 1];
//	}
//
//	NoofStudents--;
//	cout << "Record deleted successfully!" << endl;
//	SaveRecords(s, NoofStudents);
//}
//
//void SearchByRollNo(students& s, int NoofStudents) {
//	int temproll, index = -1;
//	cout << "Enter Roll No: ";
//	cin >> temproll;
//	while (cin.fail()) {
//		cin.clear();
//		cin.ignore(1000, '\n');
//		cout << "Invalid input! Enter a valid Roll No: ";
//		cin >> temproll;
//	}
//
//	for (int i = 0; i < NoofStudents; i++) {
//		if (temproll == s.RollNum[i]) {
//			index = i;
//			break;
//		}
//	}
//	if (index == -1) {
//		cout << "Roll No not found!" << endl;
//		return;
//	}
//	cout << "Name: " << s.Name[index] << endl;
//	cout << "Section: " << s.section[index] << endl;
//}
//
//void LoadRecords(students& s, int& NoofStudents) {
//	ifstream fin("students.txt");
//	if (!fin) {
//		return;
//	}
//
//	NoofStudents = 0;
//	string line;
//
//	while (getline(fin, line)) {
//		if (line.empty()) continue;
//
//		int pos = 0;
//		int nextPos;
//
//		nextPos = line.find('|', pos);
//		s.RollNum[NoofStudents] = stoi(line.substr(pos, nextPos - pos));
//		pos = nextPos + 1;
//
//		nextPos = line.find('|', pos);
//		s.Name[NoofStudents] = line.substr(pos, nextPos - pos);
//		pos = nextPos + 1;
//
//		nextPos = line.find('|', pos);
//		s.section[NoofStudents] = line.substr(pos, nextPos - pos);
//		pos = nextPos + 1;
//
//		nextPos = line.find('|', pos);
//		s.assignment[NoofStudents][0] = stod(line.substr(pos, nextPos - pos));
//		pos = nextPos + 1;
//
//		nextPos = line.find('|', pos);
//		s.assignment[NoofStudents][1] = stod(line.substr(pos, nextPos - pos));
//		pos = nextPos + 1;
//
//		nextPos = line.find('|', pos);
//		s.quiz[NoofStudents][0] = stod(line.substr(pos, nextPos - pos));
//		pos = nextPos + 1;
//
//		nextPos = line.find('|', pos);
//		s.quiz[NoofStudents][1] = stod(line.substr(pos, nextPos - pos));
//		pos = nextPos + 1;
//
//		nextPos = line.find('|', pos);
//		s.quiz[NoofStudents][2] = stod(line.substr(pos, nextPos - pos));
//		pos = nextPos + 1;
//
//		nextPos = line.find('|', pos);
//		s.mid[NoofStudents] = stod(line.substr(pos, nextPos - pos));
//		pos = nextPos + 1;
//
//		nextPos = line.find('|', pos);
//		s.final[NoofStudents] = stod(line.substr(pos, nextPos - pos));
//		pos = nextPos + 1;
//
//		nextPos = line.find('|', pos);
//		s.TotalMarks[NoofStudents] = stod(line.substr(pos, nextPos - pos));
//		pos = nextPos + 1;
//
//		s.grade[NoofStudents] = line[pos];
//
//		NoofStudents++;
//	}
//
//	fin.close();
//}
//
//void HighestandLowest(students& s, int NoofStudents) {
//	double highest = s.TotalMarks[0];
//	for (int i = 0; i < NoofStudents; i++) {
//		if (s.TotalMarks[i] > highest) {
//			highest = s.TotalMarks[i];
//		}
//	}
//
//	double lowest = s.TotalMarks[0];
//	for (int i = 0; i < NoofStudents; i++) {
//		if (s.TotalMarks[i] < lowest) {
//			lowest = s.TotalMarks[i];
//		}
//	}
//
//	cout << "Highest marks are " << highest << endl;
//	cout << "Lowest marks are " << lowest << endl;
//}
//
//int main() {
//	students s;
//	int NoofStudents = 0;
//	int user_input;
//
//	LoadRecords(s, NoofStudents);
//
//	cout << "----Welcome to Student Performence Management System----" << endl;
//	if (NoofStudents > 0) {
//		cout << "Loaded " << NoofStudents << " student records from file." << endl;
//	}
//	do {
//		cout << "\nChoose a desired option" << endl;
//		cout << "1.Add a new student" << endl;
//		cout << "2.Add Marks" << endl;
//		cout << "3.Delete record" << endl;
//		cout << "4.Calculate Grade" << endl;
//		cout << "5.Find Topper" << endl;
//		cout << "6.Update existing Marks" << endl;
//		cout << "7.Show Statistics" << endl;
//		cout << "8.Store records" << endl;
//		cout << "9.Load records" << endl;
//		cout << "10.Calculate Total Marks" << endl;
//		cout << "11.Exit" << endl;
//		cin >> user_input;
//
//		while (cin.fail() || user_input < 1 || user_input > 10) {
//			cin.clear();
//			cin.ignore(1000, '\n');
//			cout << "Invalid choice! Enter 1-10: ";
//			cin >> user_input;
//		}
//
//		if (user_input == 1) {
//			AddStudent(s, NoofStudents);
//		}
//		if (user_input == 2) {
//			AddTotalMarks(s, NoofStudents);
//		}
//		if (user_input == 3) {
//			DeleteRecord(s,NoofStudents);
//		}
//		if (user_input == 4) {
//			GradeAssigner(s, NoofStudents);
//		}
//		if (user_input == 5) {
//			TopperIdentifier(s, NoofStudents);
//		}
//		if (user_input == 6) {
//			UpdateRecord(s, NoofStudents);
//		}
//		if (user_input == 7) {
//			ShowStatistics(s, NoofStudents);
//		}
//		if (user_input == 8) {
//			SaveRecords(s, NoofStudents);
//			cout << "Records saved succesfully!" << endl;
//		}
//		if (user_input == 9) {
//			LoadRecords(s, NoofStudents);
//			cout << "Records loaded succesfully!" << endl;
//		}
//		if (user_input == 10) {
//			TotalMarksCalculator(s, NoofStudents);
//		}
//	} while (user_input != 11);
//
//	if (user_input == 11) {
//		SaveRecords(s, NoofStudents);
//		cout << "Records saved automatically. Thanks for using :)" << endl;
//	}
//
//	return 0;
//}
//
