
#ifndef TICKETMASTER_H
#define TICKETMASTER_H
#include <iostream>
#include <iomanip>
using namespace std;

const int Max_Rows = 15;
const int Max_Cols = 30;

class TicketMaster {
 private:
  struct SeatStructures {
    bool seatsold;
    float seatprice;
    SeatStructures(bool sold=false, float price = 0.0){
      seatsold = sold;
      seatprice = price;
    };
  };
  SeatStructures auditorium[Max_Rows][Max_Cols];

 public:
  // a getter for seat availability 
  bool isSeatSold(int row, int col){
    return auditorium[row][col].seatsold;
  }
  // a bounds checker
  bool insideSS(int row, int col){
    if ((row < 0) || (row >= Max_Rows)) {return false;};
    if ((col < 0) || (row >= Max_Cols)) {return false;};
    return true;
  }
  // get the price of the seat
  float getSeatPrice(int row, int col){
    return auditorium[row][col].seatprice;
  }

  void setSeatPrice(int row, int col,float price){
    auditorium[row][col].seatprice = price;
  }
  
  bool sellSeat(int row, int col){
    // In a later C++ program we would probably raise an exception
    // if we could not sell the seat but in this case we will
    // return a false if we could not sell seat.
    if (isSeatSold(row,col) == true) {
      auditorium[row][col].seatsold = true;
      return true;
    } else {
      return false;
    }
  }
  
  void displaySeats() {
    cout << "     Seats" << endl;
    int numX = Max_Cols / 10; // work out the number of rows
    int remX = Max_Cols % 10; // work out the left over
    cout << "   ";
    for (int c = 0; c < numX; c++){
      for (int i = 1; i < 10; i++){
	cout << i;
      };
      cout << "0";
    }
    for (int i=1; i<=remX; i++){
      cout << i;
    };
    cout << endl;
    // print the rows.
    for (int r = 0; r < Max_Rows; r++){
      cout << setw(2)  << (r+1) << " ";
      for (int c = 0; c < Max_Cols; c++){
	if (isSeatSold(r,c)){
	  cout << "*";
	} else {
	  cout << "#";
	};
      };
      cout << endl;
    };
  }

  void requestTicekts() {
    cout << "requestTicekts\n";
  }
  
  void purchaseTickets() {
    cout << "purchaseTickets\n";
  }
  
  void salesReport() {
    cout << "salesReport\n";
  }
	
};



// TicketMaster::TicketMaster () {
// 	// read data from files
// 	// set up array
// }
#endif
