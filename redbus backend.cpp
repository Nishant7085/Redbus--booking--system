#include <iostream>
#include <string>
using namespace std;

class Bus
{
public:
    int busNo;
    string busName;
    string source;
    string destination;
    int fare;
    bool seats[5];

    // Constructor
    Bus(int no, string name, string from,
        string to, int f)
    {
        busNo = no;
        busName = name;
        source = from;
        destination = to;
        fare = f;

        int i = 0;
        while (i < 5)
        {
            seats[i] = false;
            i++;
        }
    }

    // Display bus details and seats
    void display()
    {
        cout << "\nBus Number: " << busNo;
        cout << "\nBus Name: " << busName;
        cout << "\nRoute: " << source << " to " << destination;
        cout << "\nFare: Rs. " << fare << endl;

        cout << "Seats: ";

        int i = 0;
        while (i < 5)
        {
            if (seats[i] == false)
                cout << "[" << i + 1 << "] ";
            else
                cout << "[X] ";

            i++;
        }

        cout << endl;
    }

    // Book ticket
    void bookTicket()
    {
        int seatNo;

        display();

        cout << "\nEnter seat number (1-5): ";
        cin >> seatNo;

        if (seatNo < 1 || seatNo > 5)
        {
            cout << "Invalid seat number!\n";
        }
        else if (seats[seatNo - 1] == true)
        {
            cout << "Sorry! This seat is already booked.\n";
        }
        else
        {
            seats[seatNo - 1] = true;

            cout << "\nBooking Successful!";
            cout << "\nBus: " << busName;
            cout << "\nSeat Number: " << seatNo;
            cout << "\nFare: Rs. " << fare << endl;
        }
    }
};

int main()
{
    Bus b1(101, "Rajasthan Express",
           "Jaipur", "Delhi", 500);

    Bus b2(102, "Royal Travels",
           "Jaipur", "Delhi", 600);

    int choice = 0;

    while (choice != 3)
    {
        cout << "\n===== REDBUS BOOKING SYSTEM =====\n";
        cout << "1. Display Buses and Seats\n";
        cout << "2. Book Ticket\n";
        cout << "3. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            b1.display();
            b2.display();
        }
        else if (choice == 2)
        {
            int busNo;

            cout << "Enter Bus Number (101 or 102): ";
            cin >> busNo;

            if (busNo == 101)
                b1.bookTicket();
            else if (busNo == 102)
                b2.bookTicket();
            else
                cout << "Invalid Bus Number!\n";
        }
        else if (choice == 3)
        {
            cout << "Thank you for using RedBus!\n";
        }
        else
        {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
