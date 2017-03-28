

/* 
 * File:   classRoom.cpp
 * Author: Nicole
 * 
 * Created on January 24, 2017, 6:25 PM
 */

#include "classRoom.h"
#include <iostream>

//Constructor
classRoom::classRoom() {
    seats =  new bool[8*256];    //seat numbers 0-255. classrooms 0-7.
    openSeats =  new short[8];	 //keeps track of the number of open seats per class
    for(short i=0; i<8; i++) {
        openSeats[i]=256;
    }
}

classRoom::classRoom(const classRoom& orig) {
}

//Destructor
classRoom::~classRoom() {
    delete[]seats;
    delete[]openSeats;
}

//Reserves a seat for a student

bool classRoom::reserveSeat(short classNumber, short seatNumber){
	if (classNumber>7 || classNumber<0 || seatNumber>255 || seatNumber<0 ) {
		throw false;
		return false;
		//out of bounds 
	}

     if (!isOccupied(classNumber, seatNumber)){
        seats[256*classNumber + seatNumber] = true;
        openSeats[classNumber]--;
        return true;
    } else {
        std::cout << "Seat already taken" << std::endl;
        return (false);              //if false, the seat is already reserved
      }
}

//Frees a seat for a student 

bool classRoom::availSeat(short classNumber, short seatNumber){

    if (classNumber>7 || classNumber<0 || seatNumber>255 || seatNumber<0 ) {
		throw false;
		return false;
		//out of bounds 
	}

    if (isOccupied(classNumber, seatNumber)){
        seats[256*classNumber + seatNumber] = false;
        openSeats[classNumber]++;
        return true;
    } else  {
    std::cout << "Seat already available" << std::endl;
    return false;                   //if false, seat is already available
   }
}

    
    //Checks if a specific seat is occupied in a certain class
bool classRoom::isOccupied(short classNumber, short seatNumber) {

    if (classNumber>7 || classNumber<0 || seatNumber>255 || seatNumber<0 ) {
		throw false;
		return false;
		//out of bounds 
	}

    if (seats[256*classNumber + seatNumber] ==true){
        return true;            //seat is occupied
    }
    return false;               //seat is not occupied
}
    
    //returns the number of available seats in a class
short classRoom::nAvailableSeats(short classNumber) {
	if (classNumber < 0 || classNumber >7) {
		throw(-1);
		return -1;
	}
    return openSeats[classNumber];
}
    
    //inquires about location of a student
short classRoom::studentLocation(short id) {
	if (id < 0 || id >255 ) {
		throw(-1);
		return -1;
	}
    for(short i=0; i<8; i++) {
        if (isOccupied(i, id)){
            return i;   //student is at returned classnumber
        }
    }
    throw(-2);
    return -1;           //student is nowhere
}

bool& classRoom::index(short roomNumber, short seatNumber) {
    return seats[256*roomNumber + seatNumber];
}
