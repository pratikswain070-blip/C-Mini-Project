#include <iostream>
#include <string>
using namespace std;


class Hotel {
private:
    string type[3] = {"Single","Double","Deluxe"};
    int price[3] = {2000,4000,7000};
    int available[3] = {5,8,3};
    int occupied[3] = {0,0,0};
    int nights[3] = {0,0,0};
    double taxRate = 0.10;  

public:

    void bookRoom() {
        cout << "\n--- Available Rooms ---\n";
        for(int i=0;i<3;i++){
            cout << i+1 << ". " << type[i]
                 << " | Rs." << price[i]
                 << " | Available: " << available[i] << endl;
        }
        int c,q,n;
        cout << "\nSelect room type (1-3): ";
        cin >> c;
        c--;
        if(c < 0 || c > 2){
            cout << "Invalid selection\n\n";
            return;
        }
        if(available[c] == 0){
            cout << "No rooms available in this category.\n\n";
            return;
        }
        cout << "Number of rooms: ";
        cin >> q;
        if(q > available[c]){
            cout << "Only " << available[c]
                 << " rooms available.\n\n";
            return;
        }

        cout << "Number of nights: ";
        cin >> n;

        if(n <= 0){
            cout << "Invalid number of nights.\n\n";
            return;
        }
        occupied[c] += q;
        available[c] -= q;
        nights[c] = n;
        double subtotal = price[c] * q * n;
        double tax = subtotal * taxRate;
        double total = subtotal + tax;

        cout << "\n============= HOTEL BILL =============\n";
        cout << "Room Type     : " << type[c] << endl;
        cout << "Price/Night   : Rs." << price[c] << endl;
        cout << "Rooms Booked  : " << q << endl;
        cout << "Nights        : " << n << endl;
        cout << "--------------------------------------\n";
        cout << "Subtotal      : Rs." << subtotal << endl;
        cout << "Tax (10%)     : Rs." << tax << endl;
        cout << "--------------------------------------\n";
        cout << "Grand Total   : Rs." << total << endl;
        cout << "======================================\n\n";
    }


    
    void guestCheckout() {

        cout << "\n--- Guest Checkout ---\n";

        bool found = false;
        for(int i=0;i<3;i++){
            if(occupied[i] > 0){
                cout << i+1 << ". " << type[i]
                     << " | Rooms Occupied: " << occupied[i] << endl;
                found = true;
            }
        }

        if(!found){
            cout << "No guests to checkout.\n\n";
            return;
        }

        int c,q;
        cout << "Select room type (1-3): ";
        cin >> c;
        c--;

        if(c<0 || c>2 || occupied[c]==0){
            cout << "Invalid selection.\n\n";
            return;
        }
        cout << "Number of rooms to checkout: ";
        cin >> q;
        if(q > occupied[c]){
            cout << "Only " << occupied[c] << " rooms occupied.\n\n";
            return;
        }
        occupied[c] -= q;
        available[c] += q;
        cout << "Checkout successful. Room(s) now available.\n\n";
    }

    
    void showOccupied() {
        cout << "\n--- Occupied Rooms ---\n";
        bool empty = true;
        for(int i=0;i<3;i++){
            if(occupied[i] > 0){
                cout << i+1 << ". " << type[i]
                     << " | Rooms: " << occupied[i]
                     << " | Nights: " << nights[i] << endl;
                empty = false;
            }
        }
        if(empty)
            cout << "No rooms currently occupied.\n";

        cout << endl;
    }
};
int main() {
    Hotel h;
    int choice;
    do{
        cout<<"\n====================================\n";
        cout << "===== Hotel Booking System =====\n";
        cout << "1. Book Room\n";
        cout << "2. Guest Checkout\n";
        cout << "3. Show Occupied Rooms\n";
        cout << "4. Exit\n";
        cout << "====================================\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice){
            case 1: h.bookRoom(); break;
            case 2: h.guestCheckout(); break;
            case 3: h.showOccupied(); break;
            case 4: cout << "Thank you!\n"; break;
            default: cout << "Invalid choice\n";
        }
    }while(choice != 4);
    return 0;
}
