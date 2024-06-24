#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib> 
using namespace std;

void welcomeScreen(){
	    cout<<"\t\t***********************************************************************************************"<<endl;
        cout<<"\t\t*                                   W E L C O M E                                              *"<<endl;
        cout<<"\t\t*                                                                                              *"<<endl;
        cout<<"\t\t*                                        T O                                                   *"<<endl;
        cout<<"\t\t*                                                                                              *"<<endl;
        cout<<"\t\t*                H O T E L   R E C C O M E N D A T I O N   S Y S T E M                         *"<<endl;
        cout<<"\t\t*                                                                                              *"<<endl;
        cout<<"\t\t*                                                                                              *"<<endl;
        cout<<"\t\t***********************************************************************************************"<<endl;
};

struct Hotel {
    string name = "";
    double rating = 0.0;
    int price = 0;
};

void input(vector<Hotel>& hotels);
bool sortByRating(const Hotel& a, const Hotel& b);
bool sortByPrice(const Hotel& a, const Hotel& b);
void displayHotels(const vector<Hotel>& hotels, int budget);

int main() {
    int a;
    int size = 0;
    int budget = 0;
    vector<Hotel> hotels; 

    do {
        system("cls"); 
        welcomeScreen();
        cout <<endl<<endl<<"\t\tWhat You want to do ?" << endl;
        cout << "\t\t1. Enter Hotel details" << endl << "\t\t2. See Hotel Details" << endl <<"\t\t3. Find Hotel"<<endl<< "\t\t4. Press 0 for Exit" << endl;
        cout<<endl<<"====> ";
        cin >> a;
        cin.ignore(); 

        if (a == 1) {
            system("cls"); 
            welcomeScreen();
            cout << "\t\tHow many Hotels?\n";
            cout<<endl<<"====> ";
            cin >> size;
            cin.ignore(); 
            hotels.resize(size);  
            input(hotels);
        } 
		else if (a == 2) {
            system("cls");
            welcomeScreen();
            cout << "\t\tHotels details:" << endl;
            sort(hotels.begin(), hotels.end(), sortByRating);
            cout << "\t\t#" << "  " << "Name" << "\t\t\t\t" << "Rating(S)" << "\t\t\t" << "Price/Night" << endl;
            for (int i = 0; i < size; i++) {
                cout <<"\t\t"<< i + 1 << "  " << hotels[i].name << "\t\t\t\t" << hotels[i].rating << "\t\t\t\t" << hotels[i].price << endl;
            }
            cout<<endl<<endl<<"\t\tPress Enter to continue....";   
            cin.get();
          }
		else if(a==3){
		 	system("cls");
		 	welcomeScreen();
            cout << "\t\tWhat is your budget" << endl;
            cout<<endl<<"====> ";
            cin >> budget;
            cout << "\t\tRecommended Hotels fitting your budget are:\n";
            displayHotels(hotels, budget); 
			cout<<endl<<endl<<"\t\tPress Enter to continue....";   
            cin.get();
             		}  
        else if (a == 0) {
            exit(0);
        				} 
		else {
            cout << "\t\tInvalid Choice";    
        	}
    } while (a != 0);
    
    return 0;
}

void input(vector<Hotel>& hotels) {
    for (int i = 0; i < hotels.size(); i++) {
        cout << "\t\tEnter name: ";
        cout<<endl<<"====> ";
        getline(cin, hotels[i].name);
        cout << "\t\tEnter Rating for this hotel: ";
        cout<<endl<<"====> ";
        cin >> hotels[i].rating;
        cout << "\t\tEnter Price status/budget of this hotel: ";
        cout<<endl<<"====> ";
        cin >> hotels[i].price;
        cin.ignore(); 
    }
}

bool sortByRating(const Hotel& a, const Hotel& b) {
    return a.rating > b.rating;
}

bool sortByPrice(const Hotel& a, const Hotel& b) {
    return a.price > b.price;
}

void displayHotels(const vector<Hotel>& hotels, int budget) {
    cout << "\t\t#  Name\t\t\t\tRate\t\t\t\tPrice/Night\n";
    for (int i = 0; i < hotels.size(); i++) {
        if (hotels[i].price < budget) {
            cout <<"\t\t"<< i + 1 << "  " << hotels[i].name << "\t\t\t\t" << hotels[i].rating << "\t\t\t\t" << hotels[i].price << endl;
        }
    }
    cin.get();
}


