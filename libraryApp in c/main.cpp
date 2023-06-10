#include <windows.h>
#include <mysql.h>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
//#include</LoginSystem.h>

using namespace std;
MYSQL* connection;

void connectToDatabase() {
    connection = mysql_init(0);
    if (mysql_real_connect(connection, "localhost", "root", "root", "library", 0, NULL, 0)) {
        cout << "Connected to MySQL server." << endl;
    } else {
        cout << "Failed to connect to MySQL server: " << mysql_error(connection) << endl;
    }
}

void disconnectFromDatabase() {
    mysql_close(connection);
    cout << "Disconnected from MySQL server." << endl;
}

class Book {
private:
    int id;
    string title;
    string author;
    bool borrowed;
    time_t returnDate;

public:
    Book(int id, string title, string author) : id(id), title(title), author(author), borrowed(false) {}

    int getId() const {
        return id;
    }

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    bool isBorrowed() const {
        return borrowed;
    }

    void setBorrowed(bool status) {
        borrowed = status;
    }

    void setReturnDate(time_t date) {
        returnDate = date;
    }

    time_t getReturnDate() const {
        return returnDate;
    }
};

class StudentInfo {
private:
    int yearEnrolled;
    string department;
    int studentNumber;

public:
    StudentInfo(int yearEnrolled, string department, int studentNumber)
        : yearEnrolled(yearEnrolled), department(department), studentNumber(studentNumber) {}

    string generateMatricule() const {
        string matricule = "FE" + to_string(yearEnrolled).substr(2) + department + to_string(studentNumber);
        return matricule;
    }
};

class Student {
private:
    string matricule;
    string name;
    vector<Book*> borrowedBooks;

public:
    Student(string matricule, string name) : matricule(matricule), name(name) {}

    string getMatricule() const {
        return matricule;
    }

    string getName() const {
        return name;
    }

    void borrowBook(Book* book) {
        borrowedBooks.push_back(book);
        book->setBorrowed(true);
        time_t currentTime = time(nullptr);
        book->setReturnDate(currentTime + 604800); // Set return date to 7 days from now

        // Insert borrow record into borrow_books table
        string insertQuery = "INSERT INTO borrow_books (student_matricule, book_id, borrow_date, return_date) VALUES ('"
                             + matricule + "', "
                             + to_string(book->getId()) + ", "
                             + "NOW(), "
                             + "FROM_UNIXTIME(" + to_string(book->getReturnDate()) + "))";
        if (mysql_query(connection, insertQuery.c_str()) != 0) {
            cout << "Failed to insert borrow record: " << mysql_error(connection) << endl;
        }
    }

    void returnBook(Book* book) {
        vector<Book*>::iterator it = borrowedBooks.begin();
        while (it != borrowedBooks.end()) {
            if (*it == book) {
                borrowedBooks.erase(it);
                book->setBorrowed(false);

                // Delete borrow record from borrow_books table
                string deleteQuery = "DELETE FROM borrow_books WHERE student_matricule = '"
                                     + matricule + "' AND book_id = " + to_string(book->getId());
                if (mysql_query(connection, deleteQuery.c_str()) != 0) {
                    cout << "Failed to delete borrow record: " << mysql_error(connection) << endl;
                }

                break;
            }
            ++it;
        }
    }

    vector<Book*> getBorrowedBooks() const {
        return borrowedBooks;
    }
};

void insertSampleData() {
     // Insert sample books
    string insertBookQuery = "INSERT INTO books (id, title, author, borrowed) VALUES "
                             "(1, 'Book 1', 'Author 1', 0), "
                             "(2, 'Book 2', 'Author 2', 0), "
                             "(3, 'Book 3', 'Author 3', 0)";
    if (mysql_query(connection, insertBookQuery.c_str()) != 0) {
        cout << "Failed to insert sample books: " << mysql_error(connection) << endl;
        return;
    }
    // Create students table
    string createStudentsTableQuery = "CREATE TABLE IF NOT EXISTS students ("
                                      "id INT AUTO_INCREMENT,"
                                      "matricule VARCHAR(20) NOT NULL,"
                                      "name VARCHAR(100) NOT NULL,"
                                      "year_enrolled INT NOT NULL,"
                                      "department VARCHAR(10) NOT NULL,"
                                      "PRIMARY KEY (id)"
                                      ")";
    if (mysql_query(connection, createStudentsTableQuery.c_str()) != 0) {
        cout << "Failed to create students table: " << mysql_error(connection) << endl;
        return;
    }

    // Insert sample students
    string insertStudentQuery = "INSERT INTO students (matricule, name, year_enrolled, department) VALUES "
                                "('FE21A316', 'John', 2021, 'FET'), "
                                "('FE22A007', 'Alice', 2022, 'FET'), "
                                "('FE22A123', 'Bob', 2022, 'FET')";
    if (mysql_query(connection, insertStudentQuery.c_str()) != 0) {
        cout << "Failed to insert sample students: " << mysql_error(connection) << endl;
        return;
    }

    cout << "Sample data inserted successfully." << endl;
}

void createStudent() {
    string matricule;
    string name;
    int yearEnrolled;
    string department;

    cout << "Enter Matricule: ";
    cin >> matricule;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Year Enrolled: ";
    cin >> yearEnrolled;
    cout << "Enter Department: ";
    cin >> department;

    string insertStudentQuery = "INSERT INTO students (matricule, name, year_enrolled, department) VALUES "
                                "('" + matricule + "', '" + name + "', " + to_string(yearEnrolled) + ", '" + department + "')";
    if (mysql_query(connection, insertStudentQuery.c_str()) != 0) {
        cout << "Failed to insert student record: " << mysql_error(connection) << endl;
    } else {
        cout << "Student record inserted successfully." << endl;
    }
}
// viewing borrowed books
void viewAllBorrowedBooks() {
    string selectQuery = "SELECT * FROM borrow_books";
    if (mysql_query(connection, selectQuery.c_str()) != 0) {
        cout << "Failed to fetch borrowed books: " << mysql_error(connection) << endl;
    } else {
        MYSQL_RES* resultSet = mysql_store_result(connection);
        if (resultSet != NULL) {
            int numFields = mysql_num_fields(resultSet);
            MYSQL_ROW row;

            cout << "Borrowed Books:" << endl;
            while ((row = mysql_fetch_row(resultSet))) {
                for (int i = 0; i < numFields; ++i) {
                    cout << row[i] << "\t";
                }
                cout << endl;
            }
            mysql_free_result(resultSet);
        }
    }
}

void viewStudentBorrowedBooks(const string& matricule) {
    string selectQuery = "SELECT * FROM borrow_books WHERE student_matricule = '" + matricule + "'";
    if (mysql_query(connection, selectQuery.c_str()) != 0) {
        cout << "Failed to fetch borrowed books: " << mysql_error(connection) << endl;
    } else {
        MYSQL_RES* resultSet = mysql_store_result(connection);
        if (resultSet != NULL) {
            int numFields = mysql_num_fields(resultSet);
            MYSQL_ROW row;

            cout << "Borrowed Books:" << endl;
            while ((row = mysql_fetch_row(resultSet))) {
                for (int i = 0; i < numFields; ++i) {
                    cout << row[i] << "\t";
                }
                cout << endl;
            }
            mysql_free_result(resultSet);
        }
    }
}

bool authenticateUser(const string& username, const string& password, string& role) {
    string selectQuery = "SELECT role FROM users WHERE username = '" + username + "' AND password = '" + password + "'";
    if (mysql_query(connection, selectQuery.c_str()) != 0) {
        cout << "Failed to authenticate user: " << mysql_error(connection) << endl;
        return false;
    } else {
        MYSQL_RES* resultSet = mysql_store_result(connection);
        if (resultSet != NULL) {
            MYSQL_ROW row = mysql_fetch_row(resultSet);
            if (row != NULL) {
                role = row[0];
                mysql_free_result(resultSet);
                return true;
            }
            mysql_free_result(resultSet);
        }
    }
    return false;
}
int main() {
    connectToDatabase();

    // Create borrow_books table
    string createTableQuery = "CREATE TABLE IF NOT EXISTS borrow_books ("
                              "id INT AUTO_INCREMENT PRIMARY KEY,"
                              "student_matricule VARCHAR(20),"
                              "book_id INT,"
                              "borrow_date DATETIME,"
                              "return_date DATETIME)";
    if (mysql_query(connection, createTableQuery.c_str()) != 0) {
        cout << "Failed to create table: " << mysql_error(connection) << endl;
        disconnectFromDatabase();
        return 0;
    }

    // Insert sample data
    insertSampleData();

    // Authentication
    string username, password;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    string role;
    if (!authenticateUser(username, password, role)) {
        cout << "Failed to authenticate user. Exiting..." << endl;
        disconnectFromDatabase();
        return 0;
    }

    cout << "Library Management System" << endl;

    if (role == "admin") {
        // Admin menu
        while (true) {
            cout << "1. Create Student" << endl;
            cout << "2. View All Borrowed Books" << endl;
            cout << "3. Exit" << endl;
            cout << "Enter option: ";

            int option;
            cin >> option;

            if (option == 1) {
                // Create student
                createStudent();
            } else if (option == 2) {
                // View all borrowed books (admin only)
                viewAllBorrowedBooks();
            } else if (option == 3) {
                // Exit
                break;
            } else {
                cout << "Invalid option. Please try again." << endl;
            }
        }
    } else if (role == "student") {
        // Student menu
        string matricule;
        cout << "Matricule: ";
        cin >> matricule;

        while (true) {
            cout << "1. View Available Books" << endl;
            cout << "2. View Borrowed Books" << endl;
            cout << "3. Borrow a Book" << endl;
            cout << "4. Return a Book" << endl;
            cout << "5. Exit" << endl;
            cout << "Enter option: ";

            int option;
            cin >> option;

            if (option == 1) {
                // Retrieve available books
               string query = "SELECT * FROM books WHERE borrowed = 0";
            if (mysql_query(connection, query.c_str()) == 0) {
                MYSQL_RES* result = mysql_store_result(connection);
                if (result) {
                    cout << "Available Books:" << endl;
                    MYSQL_ROW row;
                    while ((row = mysql_fetch_row(result))) {
                        int id = stoi(row[0]);
                        string title = row[1];
                        string author = row[2];
                        cout << "ID: " << id << ", Title: " << title << ", Author: " << author << endl;
                    }
                    mysql_free_result(result);
                }
            } else {
                cout << "Failed to execute query: " << mysql_error(connection) << endl;
            }
            } else if (option == 2) {
                // Retrieve borrowed books
                 // Retrieve borrowed books
            string query = "SELECT b.id, b.title, b.author, s.name, s.matricule FROM books b "
                           "JOIN borrow_books bb ON b.id = bb.book_id "
                           "JOIN students s ON bb.student_matricule = s.matricule";
            if (mysql_query(connection, query.c_str()) == 0) {
                MYSQL_RES* result = mysql_store_result(connection);
                if (result) {
                    cout << "Borrowed Books:" << endl;
                    MYSQL_ROW row;
                    while ((row = mysql_fetch_row(result))) {
                        int bookId = stoi(row[0]);
                        string bookTitle = row[1];
                        string bookAuthor = row[2];
                        string studentName = row[3];
                        string studentMatricule = row[4];
                        cout << "Book ID: " << bookId << ", Title: " << bookTitle << ", Author: " << bookAuthor
                             << ", Student Name: " << studentName << ", Matricule: " << studentMatricule << endl;
                    }
                    mysql_free_result(result);
                }
            } else {
                cout << "Failed to execute query: " << mysql_error(connection) << endl;
            }
            } else if (option == 3) {
                // Borrow a book
                 // Borrow a book
            int bookId;
            string studentMatricule;
            cout << "Enter Book ID: ";
            cin >> bookId;
            cout << "Enter Student Matricule: ";
            cin >> studentMatricule;

            // Check if the book is available
            string availabilityQuery = "SELECT borrowed FROM books WHERE id = " + to_string(bookId);
            if (mysql_query(connection, availabilityQuery.c_str()) == 0) {
                MYSQL_RES* result = mysql_store_result(connection);
                if (result) {
                    MYSQL_ROW row = mysql_fetch_row(result);
                    if (row && stoi(row[0]) == 0) {
                        // Book is available, proceed to borrow
                        string studentQuery = "SELECT name FROM students WHERE matricule = '" + studentMatricule + "'";
                        if (mysql_query(connection, studentQuery.c_str()) == 0) {
                            MYSQL_RES* studentResult = mysql_store_result(connection);
                            if (studentResult) {
                                MYSQL_ROW studentRow = mysql_fetch_row(studentResult);
                                if (studentRow) {
                                    string studentName = studentRow[0];

                                    // Create Student object
                                    Student student(studentMatricule, studentName);

                                    // Create Book object
                                    Book* book = new Book(bookId, "", "");

                                    // Borrow the book
                                    student.borrowBook(book);
                                    cout << "Book borrowed successfully." << endl;
                                } else {
                                    cout << "Student with matricule '" << studentMatricule << "' not found." << endl;
                                }
                                mysql_free_result(studentResult);
                            }
                        } else {
                            cout << "Failed to execute query: " << mysql_error(connection) << endl;
                        }
                    } else {
                        cout << "Book with ID " << bookId << " is not available." << endl;
                    }
                    mysql_free_result(result);
                }
            } else {
                cout << "Failed to execute query: " << mysql_error(connection) << endl;
            }
            } else if (option == 4) {
                // Return a book
                int bookId;
            string studentMatricule;
            cout << "Enter Book ID: ";
            cin >> bookId;
            cout << "Enter Student Matricule: ";
            cin >> studentMatricule;

            // Check if the book is borrowed by the student
            string returnQuery = "SELECT * FROM borrow_books WHERE student_matricule = '" + studentMatricule
                                 + "' AND book_id = " + to_string(bookId);
            if (mysql_query(connection, returnQuery.c_str()) == 0) {
                MYSQL_RES* result = mysql_store_result(connection);
                if (result) {
                    MYSQL_ROW row = mysql_fetch_row(result);
                    if (row) {
                        // Book is borrowed by the student, proceed to return
                        string studentQuery = "SELECT name FROM students WHERE matricule = '" + studentMatricule + "'";
                        if (mysql_query(connection, studentQuery.c_str()) == 0) {
                            MYSQL_RES* studentResult = mysql_store_result(connection);
                            if (studentResult) {
                                MYSQL_ROW studentRow = mysql_fetch_row(studentResult);
                                if (studentRow) {
                                    string studentName = studentRow[0];

                                    // Create Student object
                                    Student student(studentMatricule, studentName);

                                    // Create Book object
                                    Book* book = new Book(bookId, "", "");

                                    // Return the book
                                    student.returnBook(book);
                                    cout << "Book returned successfully." << endl;
                                } else {
                                    cout << "Student with matricule '" << studentMatricule << "' not found." << endl;
                                }
                                mysql_free_result(studentResult);
                            }
                        } else {
                            cout << "Failed to execute query: " << mysql_error(connection) << endl;
                        }
                    } else {
                        cout << "Book with ID " << bookId << " is not borrowed by the student." << endl;
                    }
                    mysql_free_result(result);
                }
            } else {
                cout << "Failed to execute query: " << mysql_error(connection) << endl;
            }
            } else if (option == 5) {
                // Exit
                break;
            } else {
                cout << "Invalid option. Please try again." << endl;
            }
        }
    }

   // disconnectFromDatabase();
    return 0;
}
