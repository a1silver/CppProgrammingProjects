# Classes and Inheritance (Assignment)
 

Create a media database.

 

Create a database that includes video games, music, and movies.

 

Implementation:

You will have a parent class for all digital media. It should have methods for the fields the child classes have in common.

Video games must have the fields: title, year, publisher, rating.

Music must have the fields: title, artist, year, duration, publisher.

Movies must have the fields: title, director, year, duration, rating. (30 points)

Learn how virtual functions work! That will make your life easier.

You might need to cast the media pointer in the main class to the corresponding child pointer, and therefore use its corresponding method. There is a static cast command in C++ that will allow that.

There should be methods in the child classes that access the fields in that class. For example, video games should have a “getRating()” method.  If necessary, you can create methods that overwrite the parent methods.

 

MAIN METHOD:

In your main class, create a vector containing the parent class. Allow the user to ask for the following information.

ADD:  The user should be able to add each kind of media, including the information in each field. (10 points)

SEARCH:  The user should be able to search for and print objects currently in the media database by searching for the title or the year.  If multiple objects match, list them all. (20 points)

DELETE: The user should be able to delete an item. Use the same functionality as the search method, then have the user confirm whether they want to delete those objects. USE A DESTRUCTOR. (10 points)

Note: By the time you are done, you will have four .h files and five .cpp files.  (One parent class, three child classes, and one main .cpp file.) Also, include a "QUIT" command, too.

Comments! (10 points)

 

Total: 80 points