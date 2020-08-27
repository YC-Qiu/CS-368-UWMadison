# Description of My Program
## Yucheng (YC) Qiu
### CS @ UW-Madison
My book database consist of 3 files: BookDB.h, BookDB.cpp, and demo.cpp. The first being the header file, the second being the implementation of the database modification functions, and the third being the main() function implementation.

Each function have Javadoc style function header comments.

In BookDB.h, sturct Book is defined:
1. Book ID (int)
2. Publication Year (int)
3. Rating (double)


Command Format Description

<p> Print the current contents of the database: for each book in the database, print its ID, publication year, and rating (separated by commas) on a new line. If no entries are in the DB, print "No entries" to cout.

<a> <ID> <year> <rating>
Add a book to the database with the given fields. Print "Book <ID> added" if
successful.

<d> <ID> Delete the book with the given ID. Print "Book <ID> removed" if successful.

<u> <ID> <year> <rating>
Locate the book with the given ID and update the value of its year and rating. Print "Book <ID> updated" if successful.

<c> Calculate and print the average rating of all the books in the database in the format "Average rating = <rating>".

<f> <year> Find and print all books in the database that were published in the given year in the format specified by the p command above. If no entries are found, print "No entries" to cout.

s <sort option>
Sort your book database in different ways so that print() displays the books in
different orders. The valid sort options are 1, 2, or 3. The sort behavior is as follows:
• 1: Sort the books in order of increasing ID number.
• 2: Sort the books in order of increasing year. Break ties by putting smaller
book IDs before larger ones.
• 3: Sort the books in order of increasing rating. Break ties by putting smaller
book IDs before larger ones.

<q> Quit the application.