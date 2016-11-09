
#ifndef TICKETMASTER_H
#define TICKETMASTER_H
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int Max_Rows = 15;
const int Max_Cols = 30;

const char SeatAvail = '#';
const char SeatTaken = '*';

class TicketMaster {
 private:
  struct SeatStructures {
    char  seatstatus;
    float seatprice;
    SeatStructures(char sold=SeatAvail, float price = 0.0){
      seatstatus = sold;
      seatprice = price;
    };
  };
  SeatStructures auditorium[Max_Rows][Max_Cols];

 public:
  TicketMaster();
  
  // a getter for seat availability 
  bool isSeatSold(int row, int col){
    if (auditorium[row][col].seatstatus = SeatAvail){
      cout << auditorium[row][col].seatstatus << endl;
      return true;
    }
    else
      return false;
  }

  // a bounds checker
  bool insideSS(int ,int ); //defined below

  // get the price of the seat
  float getSeatPrice(int row, int col){
    return auditorium[row][col].seatprice;
  }

  void setSeatPrice(int row, int col,float price){
    auditorium[row][col].seatprice = price;
  }

  void sellSeat(int row, int col){
    auditorium[row][col].seatstatus = SeatTaken;
  }

  char getSeat(int row, int col){
    return auditorium[row][col].seatstatus;
  }
  
  void displaySeats();

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

TicketMaster::TicketMaster() {
  // Read the price file and fill in data.
  ifstream PriceFile;
  ifstream SeatsFile;

  // Set up the prices for each row of seats.
  float tempPrice = 0.0;
  string tempData ="";
  int row = 0;
  int col = 0;
  PriceFile.open("SeatPrices.dat");
  if (!PriceFile)
    cout << "Not able to read price file";
  else {
    while ((row < Max_Rows) && (PriceFile >> tempPrice)){
      for (col=0; col< Max_Cols; col++){
	setSeatPrice(row,col,tempPrice);
      }
      row++;
    }
  };
  PriceFile.close();

  // Set up the taken seats in auditorium
  row = 0;
  SeatsFile.open("SeatAvailability.dat");
  if (!SeatsFile)
    cout << "Not able to read available seats file";
  else {
    while ((row < Max_Rows) && (SeatsFile >> tempData)){
      col = 0;
      while (col < Max_Cols){
	if (tempData[col] == SeatTaken) {
	  sellSeat(row,col);
	}
	col++;
      };
      row++;
    }
  }
}

bool TicketMaster::insideSS(int row, int col) {
  if ((row < 0) || (row >= Max_Rows)) {return false;};
  if ((col < 0) || (row >= Max_Cols)) {return false;};
  return true;
}

void TicketMaster::displaySeats() {
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
      cout << getSeat(r,c);
    };
    cout << endl;
  };
}



#endif
