#Real Estate

A console program that computes the taxes due on a set of properties described in a data file. The program prompts the user to enter the location of the data file.  Based on the data in the file, the program reads in the data and displays it with a summary of the taxes due.

###Local Dev Setup
* git clone repo
* running on Mac
    * ensure latest Xcode and Xcode Command Line Tools are installed
    * open Terminal
    * navigate to directory with main.cpp
    * run: g++ main.cpp Commercial.cpp Property.cpp Residential.cpp -o real-estate
    * run: ./real-estate
