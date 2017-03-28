/* 
 * NICOLE KYRIAKOPOULOS
 * HW 2 Problem 1 
 * Created on January 24, 2017, 6:14 PM
 */

#include <cstdlib>
#include <iostream>
#include "classRoom.h"


int main(int argc, char** argv) {


    //creates the set of 8 classrooms with 256 seats each
    //demonstrates initializer 
    classRoom engineering;
    
    
    //demonstrates reserve seat method
    //reserve a seat for students 30, 25, 87 in classroom 2
    //

    engineering.reserveSeat(2, 30);
    engineering.reserveSeat(2, 25);
    engineering.reserveSeat(2, 87);
    std::cout<<"Reserved a seat for students 30, 25, 87 in classroom 2"
	 <<std::endl;
    //reserve a seat for students, 11, 12, 13 in classroom 0
    engineering.reserveSeat(0, 11);
    engineering.reserveSeat(0, 12);
    engineering.reserveSeat(0, 13);
    std::cout<<"Reserved a seat for students 11, 12, 13 in classroom 0"
	 <<std::endl;
    
    //demonstrates free seat method
    std::cout<<"Availed a seat fot 11 in class 0 and 30 in class 2" << std::endl;
    engineering.availSeat(0, 11);
    engineering.availSeat(2, 30);
    //note: Classes 0 and 2 have 254 seats each now 
  try {  
    std::cout<<"Availing an already available seat and one out of bounds"<<std::endl;
    engineering.availSeat(7, 7);        //already available
    engineering.availSeat(8, 0);        //out of bounds
    }catch (bool e) {
	std::cout << "Out of bounds!" << std::endl;
}

    //demonstrates isOccupied 
   bool w = engineering.isOccupied(2, 25);   //should be occupied 
   bool x = engineering.isOccupied(0, 13);  //should be occupied
   bool y =engineering.isOccupied(2, 31);  //should not be occupied
   bool z = engineering.isOccupied(2, 30);  //should not be occupied(availed)
   std::cout<<"Is seat 13 at class 0 occupied? " << x <<
	 std::endl;             //1
   std::cout <<"Is seat 31 at class 2 occupied? "
	<< y << std::endl;             //0
   std::cout<<"Is seat 25 at class 2 occupied? "
	<< w << std::endl;		//should be 1
   std::cout <<"Is seat 30 at class 2 occupied? "
	<< z << std::endl;             //should return 0

   //demonstrates nAvailableSeats method
   int a= engineering.nAvailableSeats(0);
   int b= engineering.nAvailableSeats(1);
   int c = engineering.nAvailableSeats(2);
   int d = engineering.nAvailableSeats(3);  
    //prints number of available seats for classes 0-3
   
   std::cout<<"Number Available Seats for first 4 classrooms: "
           <<a<<", "<<b<<", "<<c<<", "<<d<<std::endl;
    int f= engineering.studentLocation(12);      //should be in class 0
   int g = engineering.studentLocation(13);     //class 0
  

  try{
   //demonstrates studentLocation
   int e= engineering.studentLocation(11);      //should throw
   int h = engineering.studentLocation(87);     //class 2
   //prints locations for above students
   std::cout<<"Locations for student 11, 12, 13, 87: ";
   std::cout<<e<<", ";
   std::cout<<f<<", ";
   std::cout<<g<<", ";
   std::cout<<h<<std::endl;
} catch (int e ) {
	if (e==-1) {
		std::cout<<"student is not in a class" << std::endl;
	} else {
		std::cout<<"Invalid Input" << std::endl;
	} 
} catch(...) {
	std::cout<<"Invalid Input"<<std::endl;
}

   //demonstrates out of bounds for finding location
 try{
   std::cout<<"Finding location for student 277: "<<std::endl;
   int j = engineering.studentLocation(277);    //this isnt a student number!
   std::cout <<j<<std::endl;

   }catch (bool e) {
	std::cout << "Input error!" << std::endl;
} catch (int i) {
	std::cout << "Input error!" << std::endl;
}catch(...) {
	std::cout << "Unknown Error!" << std::endl;
}

   
    return 0;
}

