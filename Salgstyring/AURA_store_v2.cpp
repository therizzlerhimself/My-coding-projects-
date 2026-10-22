#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

// Oppgradert: Bruker nå en Klasse (OOP) i stedet for en struct for bedre datasikkerhet (encapsulation)
class Product {
    private:
        // Private variabler som kun kan nås eller endres via klassens egne funksjonerwq
        string name;
        double price;
        int id;
        int stock;
    public:
        // Konstruktør for å enkelt opprette et nytt produkt-objekt med startverdier
        Product(string startname, double startprice, int startid, int startstock){
            name = startname;
            price = startprice;
            id = startid;
            stock = startstock;
        }
        
        // "Getter"-funksjoner for å hente ut de private dataene på en trygg måte
        string getname()const{
            return name;
        }
        double getprice()const{
            return price;
        }
        int getId()const{
            return id;
        }
        int getstock()const{
            return stock;
        }
        
        // "Setter"-funksjon for å oppdatere lagerbeholdningen trygt utenfra klassen
        void setstock(int newstock){
            stock = newstock;
        }
        
};

int main(){

    vector<Product> inventory; 

    // Oppgradert: Prøver å åpne den lagrede filen for å hente varelageret
    ifstream filereader("inventory.txt");

    if (filereader.is_open()){
        cout<<" Found saved inventory file! Loading data..."<<endl;

        string line;

        // Leser filen linje for linje
        while (getline(filereader, line)) {
            stringstream ss(line); // Gjør linjen om til en strøm for enklere oppdeling

            // Leser de komma-separerte verdiene (CSV-format)
            string tempname, tempprice, tempid, tempstock;
            getline(ss, tempname,',');
            getline(ss, tempprice,',');
            getline(ss, tempid,',' );
            getline(ss, tempstock);

            // Konverterer tekstbitene fra filen om til riktige datatyper (int og double)
            int finalid = stoi(tempid);
            double finalprice = stod(tempprice);
            int finalstock = stoi(tempstock);

            // Oppretter produkt-objektet og legger det til i listen
            Product loadeditem (tempname, finalprice, finalid, finalstock);
            inventory.push_back(loadeditem);
        }

        filereader.close(); // Lukker filen etter at alt er lastet inn
    }
    else {
        // Hvis filen ikke finnes (første gang programmet kjøres), laster vi inn standardvarer
        cout<<"No saved file found. Loading default starter items..."<<endl;

        Product item("gaming mouse", 599.50, 101, 50);
        Product item2("gaming keyboard", 700, 102, 25);
        Product item3("gaming chair", 2000, 103, 10);
        Product item4("gaming pc",15000, 104, 5);

        inventory.push_back(item); 
        inventory.push_back(item2);
        inventory.push_back(item3); 
        inventory.push_back(item4); 
    }
    
    // Hovedløkken for menyen
    while (true){
        cout<<"Welcome to the AURA store!\n========================="<<endl;
        cout<<" To view stock type 1 and enter\n To exit type 2 and enter"<<endl;
        cout<<" To add a new product type 3 and enter\n To buy a product type 4 and enter\n To restock type 5 and enter"<<endl;
        int userchoice;
        cin>> userchoice;
        system("cls");

        switch (userchoice){
            
            // VALG 1: Vis varelageret (bruker nå getter-funksjoner)
            case 1: {
                for (Product i : inventory){
                    cout<<"Loading inventory: "<< "Product name: "<< i.getname() << " | "<<"Price: "<<i.getprice() <<" | "<<"Stock: "<<  i.getstock() <<" | "<<"ID: "<< i.getId() <<endl;
                }
                system("pause");
                system("cls");
                break; 
            }
            
            // VALG 2: Lagre og avslutt
            case 2: {
                // Oppgradert: Åpner/oppretter filen for å skrive de oppdaterte varene til harddisken
                ofstream saving("inventory.txt");
                
                // Skriver alle produktene til filen separert med komma
                for (Product i : inventory){
                    saving << i.getname() << ","<< i.getprice() << ","<< i.getId()<< ","<< i.getstock() << endl;
                }
                cout<<"Stock saved."<<endl;

                saving.close(); // Lukker og lagrer filen ordentlig

                cout<<"Shutting system off..."<<endl;
                return 0;
            }
            
            // VALG 3: Legg til nytt produkt
            case 3:{
                string tempname;
                double tempprice;
                int tempid;
                int tempstock;
                
                cout<<" Enter product ID: "<<endl;
                cin>> tempid;
                
                cout<<" Enter product name: "<<endl;
                getline(cin >>ws, tempname);

                cout<<" Enter product price "<<endl;
                cin>>tempprice;

                cout<<" Enter product stock size: "<<endl;
                cin>>tempstock;

                // Bruker konstruktøren til å lage det nye produkt-objektet
                Product newitem(tempname, tempprice, tempid, tempstock);
                inventory.push_back(newitem);

                cout<<"Product added succesfully"<<endl;
                system("pause");
                system("cls");
                break;
            }
            
            // VALG 4: Kjøp et produkt (bruker nå getstock og setstock)
            case 4:{
                int targetid;
                int buyquantity;
                bool itemfound = false; 
                
                cout<<"Type the id of the product!"<<endl;
                cin>> targetid;

                for (Product &i : inventory){
                    if (i.getId() == targetid){
                        itemfound = true;
                        break;
                    }
                }
                if (!itemfound){
                    cout<<"Such ID does not exist!"<<endl;
                    system("pause");
                    system("cls");
                } else {
                    cout<<"Now type the amount of products you want to buy"<<endl;
                    cin>> buyquantity; 
                    
                    for (Product &i : inventory){
                        if (i.getId() == targetid){
                            int currentStock = i.getstock(); // Henter nåværende lagerstatus
                            
                            if (buyquantity <= currentStock){
                                int newStock = currentStock - buyquantity;
                                i.setstock(newStock); // Oppdaterer lageret med den nye verdien
                                cout<<"Purchase completed"<<endl;
                                system("pause");
                                system("cls");
                                break;
                            }
                            else {
                                cout<<"We do no thave this amount of "<< i.getname()<<"(s)" <<endl;
                                system("pause");
                                system("cls");
                                break;
                            }
                        }
                    }
                }
                break;
            }
            
            // VALG 5: Fyll på lageret (bruker også getstock og setstock)
            case 5: {
                int targetid;
                int restockquantity;
                bool itemfound = false; 

                cout<<"Write the product id of the item you want to be restocked"<<endl;
                cin >> targetid;

                for (Product &i : inventory){
                    if (i.getId() == targetid){
                        itemfound = true;
                        break;
                    }
                }
                if (!itemfound){
                    cout<<"Such ID does not exist!"<<endl;
                    system("pause");
                    system("cls");
                } else {
                    cout<<"How many units?"<<endl;
                    cin>> restockquantity;

                    if (cin.fail() || restockquantity <= 0)
                    {
                        cout<<"Operation cannot be completed"<<endl; 
                        system("pause");
                        system("cls");
                        cin.clear();
                        cin.ignore();
                        break;
                    }

                    for (Product &i : inventory){
                        if (i.getId() == targetid){
                            int currentStock = i.getstock();
                            int newStock = restockquantity + currentStock;
                            i.setstock(newStock); // Setter den nye, økte lagerbeholdningen
                            
                            cout<<"Restocking done!" << " "<<"Amount of the current product: "<< newStock<<endl;
                            system("pause");
                            system("cls");
                            break;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
