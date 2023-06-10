/*========================
	CEF346 JAVA PROJECT
	SCHOOL LIBRARY SYSTEM
========================*/

-- =======================================
-- ============Student Database===========
-- =======================================
drop database studentsdb;
CREATE DATABASE studentsdb ;

-- creating admin table
create table studentsdb.admin(
		admin_username	varchar(5),
        admin_password	varchar(5),
        secret_code		varchar(6)
);

-- creating student table
create table studentsdb.students(
		student_id			int auto_increment not null,
		student_name		VARCHAR(100) not null,
        student_username	varchar(10) unique not null,
        student_matricule	varchar(10) unique,
		student_department	VARCHAR(25),
		student_tel			varchar(9) unique,
        student_password	varchar(16) not null,
		PRIMARY KEY(student_id)
);

-- creating a table to store records of students owing books
create table studentsdb.owings(
		student_id			int,
        student_name		varchar(100),
        student_tel			varchar(9),
        foreign key(student_id) references students(student_id)
);

-- creating a table for students who have returned borrowed books
create table studentsdb.returns(
		student_id			int,
        student_name		varchar(100),
        student_tel			varchar(9),
        foreign key(student_id) references students(student_id)
);

-- creating a table to store the records of waiting students
create table studentsdb.waiting_students(
		student_id			int,
        student_name		varchar(100),
        foreign key(student_id) references students(student_id)
);

-- creating a table to store the records of levied students
create table studentsdb.levied_students(
		student_id			int,
        fine				long,
        levy_message		varchar(1000),
        foreign key(student_id) references students(student_id)
);
-- inserting admin data
insert into studentsdb.admin (admin_username, admin_password, secret_code) value ('admin', 'admin', 'qwerty');



-- ======================================
-- =============Book Database============
-- ======================================
drop database booksdb;
create database booksdb;

-- creating book table
create table booksdb.books(
		book_id		        int auto_increment not null,
		book_title          varchar(100) not null,
		book_publisher      varchar(100),
		book_isbn           varchar(100) unique not null,
		book_author 		varchar(100),
        date_added			date,
		PRIMARY key(book_id)
);

-- creating a table to store records of lended books
create table booksdb.lended_books(
		book_id		        int,
		book_title          varchar(100),
        date_lended			datetime,
        return_deadline		datetime,
        foreign key(book_id) references books(book_id)
);

-- creating a table to store records of books that are returned
create table booksdb.returned_books(
		book_id		        int,
		book_title          varchar(100),
        date_returned		datetime,
        foreign key(book_id) references books(book_id)
);

-- creating a table to store records of books booked in advance
create table booksdb.booked_books(
		book_id		        int,
		book_title          varchar(100),
        date_booked			date,
        foreign key(book_id) references books(book_id)
);
        
        
-- inserting records into book table
INSERT INTO booksdb.books (book_title, book_publisher, book_isbn, book_author, date_added)
VALUES
  ('The Alchemist', 'HarperOne', '9780062293991', 'Paulo Coelho', '2023-06-08'),
  ('To Kill a Mockingbird', 'HarperCollins', '9780061924914', 'Harper Lee', '2023-06-08'),
  ('1984', 'Signet Classics', '9780451524932', 'George Orwell', '2023-06-08'),
  ('The Lord of the Rings', 'HarperCollins', '9780061725221', 'J.R.R. Tolkien', '2023-06-08'),
  ('The Hitchhiker''s Guide to the Galaxy', 'Del Rey', '9780345445714', 'Douglas Adams', '2023-06-08'),
  ('The Great Gatsby', 'Scribner', '9781501141540', 'F. Scott Fitzgerald', '2023-06-08'),
  ('Pride and Prejudice', 'Penguin Classics', '9780141335538', 'Jane Austen', '2023-06-08'),
  ('The Catcher in the Rye', 'Penguin Books', '9780143106382', 'J.D. Salinger', '2023-06-08'),
  ('Invisible Man', 'Random House', '9780307276453', 'Ralph Ellison', '2023-06-08'),
  ('The Book Thief', 'Penguin Books', '9780143125546', 'Markus Zusak', '2023-06-08'),
  ('The Kite Runner', 'Riverhead Books', '9781594485391', 'Khaled Hosseini', '2023-06-08'),
  ('The Hunger Games', 'Scholastic Press', '9780439023855', 'Suzanne Collins', '2023-06-08'),
  ('Divergent', 'Katherine Tegen Books', '9780062024567', 'Veronica Roth', '2023-06-08'),
  ('The Fault in Our Stars', 'Little, Brown and Company', '9780316206852', 'John Green', '2023-06-08'),
  ('All the Light We Cannot See', 'Little, Brown and Company', '9780316208131', 'Anthony Doerr', '2023-06-08'),
  ('Where the Crawdads Sing', 'Penguin Random House', '9780593084537', 'Delia Owens', '2023-06-08'),
  ('The Midnight Library', 'Penguin Random House', '9780593137642', 'Matt Haig', '2023-06-08'),
  ('The Catcher in the Rye', 'Little, Brown and Company', '9780316769488', 'J.D. Salinger', '2021-12-01'),
  ('The Hitchhiker''s Guide to the Galaxy', 'Pan Books', '9780330258647', 'Douglas Adams', '2021-11-30'),
  ('The Lord of the Rings', 'Allen & Unwin', '9780261103252', 'J.R.R. Tolkien', '2021-11-29'),
  ('Harry Potter and the Philosopher''s Stone', 'Bloomsbury Publishing', '9780747532699', 'J.K. Rowling', '2021-11-28'),
  ('Nineteen Eighty-Four', 'Secker & Warburg', '9780452284234', 'George Orwell', '2021-11-27'),
  ('To Kill a Mockingbird', 'J.B. Lippincott & Co.', '9780060935467', 'Harper Lee', '2021-11-26'),
  ('The Da Vinci Code', 'Doubleday', '9780385504201', 'Dan Brown', '2021-11-25'),
  ('The Hunger Games', 'Scholastic Press', '9780439023481', 'Suzanne Collins', '2021-11-24'),
  ('The Girl with the Dragon Tattoo', 'Norstedts Förlag', '9780307269751', 'Stieg Larsson', '2021-11-23'),
  ('The Kite Runner', 'Riverhead Books', '9781594480003', 'Khaled Hosseini', '2021-11-22'),
  ('The Fault in Our Stars', 'Dutton Books', '9780525478812', 'John Green', '2021-11-21'),
  ('Gone Girl', 'Crown Publishing Group', '9780307588364', 'Gillian Flynn', '2021-11-20'),
  ('The Girl on the Train', 'Riverhead Books', '9781594633669', 'Paula Hawkins', '2021-11-19'),
  ('The Alchemist', 'HarperCollins Publishers Ltd.', 	'9780061122415','Paulo Coelho','2021-11-18'),
  ('Pride and Prejudice','T. Egerton','9780141439518','Jane Austen','2021-11-17'),
  ('Frankenstein','Lackington, Hughes, Harding, Mavor & Jones','9780141439471','Mary Shelley','2021-11-16'),
  ('Dracula','Archibald Constable and Company','9780141439846','Bram Stoker','2021-11-15'),
  ('The Adventures of Sherlock Holmes','George Newnes','9780140439083','Arthur Conan Doyle','2021-11-14'),
  ('Alice''s Adventures in Wonderland','Macmillan Publishers','9780141439761','Lewis Carroll','2021-11-13'),
  ('The Little Prince','Reynal & Hitchcock','9780156012195','Antoine de Saint-Exupéry','2021-11-12'),
  ('The Da Vinci Code', 'Doubleday', '9780385503322', 'Dan Brown', '2023-06-08'),
  ('The Girl with the Dragon Tattoo', 'Knopf', '9780307275488', 'Stieg Larsson', '2023-06-08'),
  ('The Help', 'Penguin Books', '9780143124538', 'Kathryn Stockett', '2023-06-08'),
  ('Gone Girl', 'Crown', '9780307588339', 'Gillian Flynn', '2023-06-08'),
  ('The Martian', 'Crown', '9780307588909', 'Andy Weir', '2023-06-08'),
  ('The Girl on the Train', 'Penguin Books', '9780143126534', 'Paula Hawkins', '2023-06-08'),
  ('The Woman in the Window', 'Atria Books', '9781501179275', 'A.J. Finn', '2023-06-08'),
  ('Where the Wind Leads', 'Penguin Random House', '9780593134020', 'Mia Sheridan', '2023-06-08'),
  ('The Shack', 'Windblown Media', '9780310339166', 'William P. Young', '2023-06-08');
