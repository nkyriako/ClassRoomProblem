
/* 
 * File:   classRoom.h
 * Author: Nicole
 *
 * Created on January 24, 2017, 6:25 PM
 */

#ifndef CLASSROOM_H
#define CLASSROOM_H

class classRoom {
public:
    classRoom();
    classRoom(const classRoom& orig);
    virtual ~classRoom();
    bool reserveSeat(short classNumber, short seatNumber);
    bool availSeat(short classNumber, short seatNumber);
    
    //Checks if a specific seat is occupied in a certain class
    bool isOccupied(short classNumber, short seatNumber);
    
    //returns the number of available seats in a class
    short nAvailableSeats(short classNumber);
    
    //inquires about location of a student
    short studentLocation(short id);
    
    
private:
    bool* seats;
    short* openSeats; //array of open seats at each classroom
    
     //indexes array , simulating 2D 
    bool& index(short roomNumber, short seatNumber);


};

#endif /* CLASSROOM_H */

