
#ifndef TICKETMASTER_H
#define TICKETMASTER_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
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
    if (auditorium[row][col].seatstatus == SeatAvail){
      // cout << auditorium[row][col].seatstatus << endl;
      return true;
    }
    else
      return false;
  }

  // a bounds checker
  bool insideSS(int ,int ); //defined below

  // get the price of the seat
  float getSeatPrice(int row){
    return auditorium[row][0].seatprice;
  }

  void setSeatPrice(int row, int col,float price){
    auditorium[row][col].seatprice = price;
  }

  void markSold(int row, int col){
    auditorium[row][col].seatstatus = SeatTaken;
  }

  char getSeat(int row, int col){
    return auditorium[row][col].seatstatus;
  }
  
  void displaySeats();

  int requestTickets(int, int, int);
  
  string purchaseTickets(int, int, int, float);
  
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
      	if (char(tempData[col]) == SeatTaken) {
      	  markSold(row,col);
      	}
      	col++;
      };
      row++;
    }
  }
}

// Bounds checking
bool TicketMaster::insideSS(int row, int col) {
  if ((row < 0) || (row >= Max_Rows)) {return false;};
  if ((col < 0) || (row >= Max_Cols)) {return false;};
  return true;
}

// Display seating chart
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
  cout << endl;
}

// Check if tickets are available
int TicketMaster::requestTickets(int seats, int row, int start) {

  for (int i = start; i < start + seats; i++) {
    if (!isSeatSold(row, i)) {
      return 1;
    }
  }
return 0;
}

// purchase tickets
string TicketMaster::purchaseTickets(int seats, int row, int start, float price) {
  float payment = 0.0;
  char retry = ' ';

  // Validate and accept money input
  while (true) {
    cout << "How much will you be paying with? ";
    cin >> payment;
    if (payment < price) {
      while (true) {
        cout << "Not enough funds to continue the transaction. Would you like to try again? (Y or N) ";
        cin >> retry;
        if (retry != 'y' && retry != 'Y' && retry != 'n' && retry != 'N') {
          cout << "Invalid entry, please choose Y or N.\n";
        } else if (retry == 'N' || retry == 'n')
            return "Transaction Canceled.\n\n";
          else 
            break;
      }
    } else {
        cout << "You will get $" << fixed << setprecision(2) << payment - price << " in change.\n";
        break;
      }
  }

  // Mark seats as sold
  



  return " purchasing\n";
}


#endif
