#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class car{
    //creating a car class
    private:

    string brand;
    string model;
    int mileage = 0;

    public:
    //this is the blue print of the car
    car(string brand2, string model2){
        brand = brand2;
        model = model2;
        mileage = 0;
    }
    car(string brand2, string model2, int mileage2){
        brand = brand2;
        model = model2; 
        mileage = mileage2;
    }
    //key for getting the name of the brand
    string getbrand()const {
        return brand;
    }
    //and for the model
    string getmodel()const {
        return model;
    }
    //and for the mileage
    int getmileage()const {
        return mileage;
    }

    //Function that sets your car on a ride
    void driving(int distance){
        mileage += distance;
        cout<<"Vroom Vroom! Your car went on a "<< distance <<" km long drive!"<<endl;
    }


};

int main(){

    int active = 1;

    //your garage
    vector<car> garage;

    string loadbrand;
    string loadmodel;
    int loadmileage;

    ifstream loadfile("garage.txt");

    if (loadfile.is_open()){
        string loadbrand;
        string loadmodel;
        int loadmileage;
        
        while(loadfile >> loadbrand >> loadmodel >> loadmileage){
            car car1(loadbrand, loadmodel, loadmileage);
            garage.push_back(car1);

        }
        loadfile.close();
    }

    while (active == 1){
        
        int choice;

        //Here you choose what you want to do
        cout<<"What do you want to do today sir? Type 1 to view garage, 2 to drive a car, 3 to buy a new one, 4 to exit"<<endl;
        cin>>choice;
        system("cls");

        //view garage 
        if (choice ==1 ){
            cout<<"Here is your garage sir: "<<endl;
            cout<<"--------------------------"<<endl;
            for (int i = 0; i < garage.size(); i++){
                cout<<"Car "<< i+1 <<" Brand: "<< garage[i].getbrand()<<"\nModel: "<< garage[i].getmodel()<<"\nMileage: "<< garage[i].getmileage()<<" KM"<<endl;
                cout<<"============================="<<endl;
        }
            system("pause");
            system("cls");
        }
        
        
        
        
        //Drive a car
        else if (choice == 2){
            cout<<"Which car do you want to set on a ride?\n--------------------------------------"<<endl;
            for (int i = 0; i < garage.size(); i++){
                cout<<"Car "<< i+1 <<" Brand: "<< garage[i].getbrand()<<"\nModel: "<< garage[i].getmodel()<<"\nMileage: "<< garage[i].getmileage()<<" KM"<<endl;
                cout<<"============================="<<endl;
        }
            cout<<"Type the number of the car you want to drive!\n--------------------------------------------"<<endl;

            //Variables for when choosing a car
            int readycar;
            cin>>readycar;
            int chosencar = readycar -1;
            
            if (chosencar < 0 || chosencar >= garage.size()){
                cout<<"Invalid choice, try again!"<<endl;
                system("pause");
                system("cls");
                continue;

            }
            else{
                cout << garage[chosencar].getbrand() <<" "<< garage[chosencar].getmodel()<<endl;
                cout<<"Now type how far you want the car to go!"<<endl;
                
                int distance;
                cin>>distance;

                if(distance < 1){
                    cout<<"Invalid number, I guess the car is going nowhere, try a different number next time!"<<endl;
                    system("pause");
                }
                else{
                    garage[chosencar].driving(distance);
                    system("pause");
                    system("cls");
                }

                
            }
            
        }
        //Buy a new car
        else if (choice == 3){
            cout<<"Type the brand you want to buy"<<endl;
            string newbrand;
            cin>>newbrand;
            cout<<"Type the model"<<endl;
            string newmodel;
            cin>>newmodel;

            car newcar(newbrand, newmodel);
            garage.push_back(newcar);

            cout<< newbrand <<" "<< newmodel <<" Has been added to your garage"<<endl;

            

        }
        
        //exit the program and save
        else if (choice == 4){
            cout<<"Saving changes..."<<endl;
            
            ofstream saveFile("garage.txt");

            if (saveFile.is_open()){
                for (int i = 0; i < garage.size(); i++){
                    saveFile << garage[i].getbrand() << " " << garage[i].getmodel() <<" "<< garage[i].getmileage()<<endl;
                }
            }
            saveFile.close();
            cout<<"Garage saved!"<<"Exiting garage"<<endl;
            system("pause");
            return 0;
        }
        else{
            cout<<"Invalid choice, try again!"<<endl;
        }

}

    return 0;
}