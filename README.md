# Student Performance Management System
A console-based **C++** application for managing student academic records — from adding students and entering marks, to automatically calculating totals, assigning grades, identifying toppers, and persisting everything to file.

Built as a semester 1 project to practice core C++ concepts: structs, arrays, file I/O, input validation, and modular program design.

## Features

- **Add Students** — Register new students with Name, Roll Number, and Section (with input validation for duplicates and invalid characters).
- **Add / Update Marks** — Enter marks for 3 quizzes, 2 assignments, a mid exam, and a final exam, each validated against realistic ranges.
- **Automatic Total Calculation** — Computes total marks from quizzes, assignments, mid, and final.
- **Grade Assignment** — Assigns letter grades (A–F) based on total marks.
- **Delete Records** — Remove a student record by Roll Number.
- **Search by Roll Number** — Quickly look up a student's Name and Section.
- **Class Statistics** — View total student count, class average, number of students above average, and the class topper.
- **Formatted Record Table** — Displays all student records in a clean, aligned table.
- **File Persistence** — Automatically saves records to `students.txt` and reloads them on the next run, so no data is lost between sessions.

## How It Works

Student data is stored in a `students` struct using parallel arrays (Roll Number, Name, Section, Marks, Grade), each indexed by student position. Records are saved to a pipe-delimited (`|`) text file (`students.txt`) after every modification and reloaded automatically on startup.

## Marking Scheme

| Component     | Max Marks | Count |
|----------------|-----------|-------|
| Quizzes        | 10 each   | 3     |
| Assignments    | 30 each   | 2     |
| Mid Exam       | 50        | 1     |
| Final Exam     | 100       | 1     |

**Grading Scale:**

| Total Marks | Grade |
|-------------|-------|
| ≥ 90        | A     |
| ≥ 80        | B     |
| ≥ 70        | C     |
| ≥ 60        | D     |
| ≥ 50        | E     |
| < 50        | F     |

## Getting Started

### Prerequisites

- A C++ compiler (e.g., `g++`, MSVC, or any standard-compliant compiler)

### Build & Run

```bash
g++ -o student_management main.cpp
./student_management
```

On Windows (using MSVC in the Developer Command Prompt):

```bash
cl main.cpp
student_management.exe
```

### Usage

Once running, you'll see a menu with the following options:

```
1. Add a new student
2. Add Marks
3. Delete record
4. Calculate Grade
5. Find Topper
6. Update existing Marks
7. Show Statistics
8. Store records
9. Load records
10. Calculate Total Marks
11. Exit
```

Records are automatically saved to `students.txt` on exit, and loaded automatically when the program starts.

## Project Structure

```
├── main.cpp        # Full source code
├── students.txt     # Auto-generated data file (created on first run)
└── README.md
```

## Authors

- 25L-0528
- 25L-0516

## Notes

This project was built early in a Computer Science degree as a way to practice fundamental C++ concepts (structs, file handling, input validation) through a practical, data-driven application. Contributions, suggestions, or refactors are welcome!
