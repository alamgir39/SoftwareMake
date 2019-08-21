This is a execution file creation instruction
https://thoughtbot.com/blog/the-magic-behind-configure-make-make-install

Source file saved as "main.cpp"
////////////

#include <iostream>
using namespace std;

int main() {
  cout<<"Hello World!"<<endl;
  return 0;
}
//////////////////
At first create "Makefile.am"

//////////////
AUTOMAKE_OPTIONS = foreign   //First, we need to set some options to tell automake about the layout of the project. Since we’re not following the standard layout of a GNU project,
                              //we warn automake that this is a foreign project:
bin_PROGRAMS = helloworld   // It is execution file name
helloworld_SOURCES = main.cpp  // source file name here is main.cpp

///////////

Then create "configure.ac"
/////////////////////////////
AC_INIT([helloworld], [0.1], [alamgir39@gmail.com])   // The program is call helloworld, the version say 0.1, maintainer email id
AM_INIT_AUTOMAKE                                   //For automake, "AM_INIT_AUTOMAKE" macro is used
AC_PROG_CXX                                   // It is for cpp, for c "AC_PROG_CC" //If there were other dependencies, then we’d use other m4 macros here to discover them;
                                                                                  //for example the AC_PATH_PROG macro looks for a given program on the user’s PATH.
AC_CONFIG_FILES([Makefile])   // This macro find a file called Makefile.in , substitute placeholders like @PACKAGE_VERSION@ with values like 0.1, and write the results to Makefile
AC_OUTPUT                   // Finally, having told autoconf everything our configure script needs to do, we can call the AC_OUTPUT macro to output the script:


/////////////////////

//On the maintainer’s system: run this script from ubuntu terminal one by one
////////////////////
aclocal # Set up an m4 environment
autoconf # Generate configure from configure.ac
automake --add-missing # Generate Makefile.in from Makefile.am
./configure # Generate Makefile from Makefile.in
make distcheck # Use Makefile to build and test a tarball to distribute


// On the end-user’s system: To install this run this from ubuntu terminal

./configure # Generate Makefile from Makefile.in
make # Use Makefile to build the program
make install # Use Makefile to install the program


./configure # Generate Makefile from Makefile.in
make # Use Makefile to build the program
make install # Use Makefile to install the program

./configure # Generate Makefile from Makefile.in
make # Use Makefile to build the program
make install # Use Makefile to install the program
