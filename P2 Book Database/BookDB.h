// Author:          Yucheng Qiu
// Wisc id:         yqiu56
// Description:     This file is the header of BookDB.cpp . It also declares a
//                  struct named Book.
#ifndef Book_DB
#define Book_DB

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

/**
 * This sturcture implements a book.
 * 
 * @param ID - a unique id of the book
 * @param year - publication year
 * @param rating - rating of the book
 */
struct Book
{
    int ID;
    int year;
    double rating;
};

/**
 * This method adds a book into a std::vector<book> data structure.
 * 
 * @param bookID - the id of the book
 * @param year - publication year of the book
 * @param rating - rating of the book
 * @param db - the vector to store the books
 * @return 1 if there is already an entry with the given bookID, 0 if no such
 * entry is found
 */
int addBook(int bookID, int year, double rating, std::vector<Book> &db);

/**
 * This method updates a book with given data.
 * 
 * @param bookID - the id of the book
 * @param year - publication year of the book
 * @param rating - rating of the book
 * @param db - the vector to store the books
 * @return 0 if update succeeds, 1 if no such Book is found
 */
int updateBook(int bookID, int year, double rating, std::vector<Book> &db);

/**
 * This method deletes a book with given id.
 * 
 * @param bookID - the id of the book
 * @param db - the vector to store the books
 * @return 0 if delete succeeds, 1 if no entry is found
 */
int deleteBook(int bookID, std::vector<Book> &db);

/**Returns a pointer to the vector of Books published in the year specified
 * by the argument. Don’t forget to allocate and free heap memory for the
 * vector!
 * 
 * @param year - publication year
 * @param db - the vector to store the books
 * @return a vectore pointer contains all the book found
 */
std::vector<Book>* findBooks(int year, const std::vector<Book> &db);

/**
 * Calculate and print the average rating of all the books in the database.
 * 
 * @param db - given Books
 * @return the average rating
 */
double calculateAverageRating(const std::vector<Book> &db);

/**
 * Prints the contents of the database in the format
 * specified in the description above to cout. DO NOT check for an empty list
 * here– check first before calling this function.
 * 
 * @param db - Books to print
 */
void print(const std::vector<Book> &db);

/**
 * This functions should take two arguments: the book database and the
 * user-specified sorting behavior choice. After calling thisfunction, a call
 * to print() from main() should produce a sorted output. 
 * 
 * @param db - vector that contains books
 * @param sortingMethod - 1: Sort the books in order of increasing ID number.
 *                        2: Sort the books in order of increasing year. Break
 *                           ties by putting smaller IDs before larger ones.
 *                        3: Sort the books in order of increasing rating.
 *                           Break ties by putting smallerbook IDs before
 *                           larger ones.
 * @return If the user enters something other than the three possible numbers
 *         for the sort option, return 1. Otherwise return 0.
 */
int sortDB(std::vector<Book> &db, int sortingMethod);
#endif
