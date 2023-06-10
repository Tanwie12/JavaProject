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
            cout << "3. Switch to Student User" << endl;  // New option
            cout << "4. Exit" << endl;
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
                // Switch to student user
                string studentUsername, studentPassword;
                cout << "Student Username: ";
                cin >> studentUsername;
                cout << "Student Password: ";
                cin >> studentPassword;

                string studentRole;
                if (!authenticateUser(studentUsername, studentPassword, studentRole) || studentRole != "student") {
                    cout << "Failed to switch to student user. Invalid credentials or user not found." << endl;
                } else {
                    cout << "Switched to student user successfully!" << endl;
                    // Perform student-specific operations here
                    // ...
                }
            } else if (option == 4) {
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
            cout << "5. Switch to Admin User" << endl;  // New option
            cout << "6. Exit" << endl;
            cout << "Enter option: ";

            int option;
            cin >> option;

            if (option == 1) {
                // Retrieve available books
                string query = "SELECT * FROM books WHERE borrowed = 0";
                if (mysql_query(connection, query.c_str()) != 0) {
                    cout << "Failed to retrieve books: " << mysql_error(connection) << endl;
                } else {
                    displayBooks();
                }
            } else if (option == 2) {
                // Retrieve borrowed books for the student
                string query = "SELECT books.* FROM books JOIN borrow_books ON books.id = borrow_books.book_id WHERE borrow_books.student_matricule = '" + matricule + "'";
                if (mysql_query(connection, query.c_str()) != 0) {
                    cout << "Failed to retrieve borrowed books: " << mysql_error(connection) << endl;
                } else {
                    displayBooks();
                }
            } else if (option == 3) {
                // Borrow a book
                borrowBook(matricule);
            } else if (option == 4) {
                // Return a book
                returnBook(matricule);
            } else if (option == 5) {
                // Switch to admin user
                string adminUsername, adminPassword;
                cout << "Admin Username: ";
                cin >> adminUsername;
                cout << "Admin Password: ";
                cin >> adminPassword;

                string adminRole;
                if (!authenticateUser(adminUsername, adminPassword, adminRole) || adminRole != "admin") {
                    cout << "Failed to switch to admin user. Invalid credentials or user not found." << endl;
                } else {
                    cout << "Switched to admin user successfully!" << endl;
                    // Perform admin-specific operations here
                    // ...
                }
            } else if (option == 6) {
                // Exit
                break;
            } else {
                cout << "Invalid option. Please try again." << endl;
            }
        }
    }

    disconnectFromDatabase();
    return 0;
}
