# Library-Management

The basic features the library management system must include are:
 Admin Access
Create Separate Records/files for Students and Books
 In Students File, store: Student Name, Admission Number, Class, No
of Books Issued.
 In Books File, store: Book Number, Author name, Book Title,
Domain, Edition and No of Copies Available.
The admin has access to:
 Add new Student and Book records.
 Modify any Student or Book record.
 Delete any Student or Book record.
 View any Specific or Whole Student record and Book record.
 Book Issue: Used at time of Issuing A book. Takes in input as Book
Number and Issuer’s Admission number, issue date. Adds that detail to
the student record that the specific Student has issued a book. Create a
file which stores this record of Book Issue.
 Book Deposit: When Student returns the book, it uses student Admission
Number and Book Number to modify the record of Book issued by the
student. Create a file which stores this record of Book Deposit.
Note: A book Cannot be issued if there are no more copies available and
a student can only issue 1 copy of a book and at max 3 books at a time.
A book can only be issued for 15 days at once. After that it needs to be
re-issued. If the book is deposited after 15 days of issue, a fine is imposed
on per day basis.
