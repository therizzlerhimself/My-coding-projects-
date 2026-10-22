#include <string>
#include <iostream>
#include <vector>

using namespace std;

// Definerer en struktur for å holde på informasjon om hvert produkt
struct Product{
    int id;
    string name;
    double price;
    int stock; 
};

int main(){
    
    // Oppretter en vector (liste) som fungerer som butikkens varelager
    vector<Product> inventory; 
    
    // Legger til noen standard startprodukter i varelageret
    Product item;
    item.id = 67;
    item.name = "gaming keyboard";
    item.price = 599.50;
    item.stock = 50;

    Product item2;
    item2.id = 68;
    item2.name = "gaming mouse";
    item2.price = 499.50;
    item2.stock = 100;

    Product item3;
    item3.id = 69;
    item3.name = "gaming PC";
    item3.price = 15000;
    item3.stock = 20;

    Product item4;
    item4.id = 70;
    item4.name = "gaming chair";
    item4.price = 2000;
    item4.stock = 15;
    
    // Setter startproduktene inn i varelager-listen
    inventory.push_back(item); 
    inventory.push_back(item2);
    inventory.push_back(item3); 
    inventory.push_back(item4); 

    // Hovedløkke som holder programmet i gang helt til brukeren avslutter
    while (true){
        // Skriver ut hovedmenyen til brukeren
        cout<<"Welcome to the AURA store!\n========================="<<endl;
        cout<<" To view stock type 1 and enter\n To exit type 2 and enter"<<endl;
        cout<<" To add a new product type 3 and enter\n To buy a product type 4 and enter\n To restock type 5 and enter"<<endl;
        
        int userchoice;
        cin>> userchoice;
        system("cls"); // Tømmer skjermen for å gjøre det ryddig

        // Håndterer menyvalget til brukeren
        switch (userchoice){
            
            // VALG 1: Vis alle produkter på lager
            case 1: 
                for (Product i : inventory){
                    cout<<"Loading inventory: "<< "Product name: "<< i.name << " | "<<"Price: "<<i.price <<" | "<<"Stock: "<<  i.stock <<" | "<<"ID: "<< i.id <<endl;
                }
                system("pause"); // Venter på at brukeren trykker en tast før programmet går videre
                system("cls");
                break; 

            // VALG 2: Avslutt programmet
            case 2: 
                cout<<"Shutting system off..."<<endl;
                return 0;

            // VALG 3: Legg til et helt nytt produkt i butikken
            case 3:{
                Product newitem;
                
                cout<<" Enter product ID: "<<endl;
                cin>>newitem.id;
                
                cout<<" Enter product name: "<<endl;
                getline(cin >>ws, newitem.name); // 'ws' fjerner unødvendige mellomrom så navnet ikke blir kuttet av

                cout<<" Enter product price "<<endl;
                cin>>newitem.price;

                cout<<" Enter product stock size: "<<endl;
                cin>>newitem.stock;

                inventory.push_back(newitem); // Legger det nye produktet inn i varelager-listen

                cout<<"Product added succesfully"<<endl;
                system("pause");
                system("cls");
                break;
            }

            // VALG 4: Kjøp et produkt (reduser lagerbeholdningen)
            case 4:{
                int targetid;
                int buyquantity;
                bool itemfound = false; 
                
                cout<<"Type the id of the product!"<<endl;
                cin>> targetid;

                // Steg 1: Sjekk om produkt-ID-en faktisk eksisterer
                for (Product &i : inventory){
                    if (i.id == targetid){
                        itemfound = true;
                        break;
                    }
                }
                
                if (!itemfound){
                    cout<<"Such ID does not exist!"<<endl;
                    system("pause");
                    system("cls");
                } else {
                    cout<<"Now type the amount of products you want to buy!"<<endl;
                    cin>> buyquantity; 
                    
                    // Steg 2: Finn produktet igjen og gjennomfør kjøpet hvis det er nok på lager
                    for (Product &i : inventory){
                        if (i.id == targetid){
                            if (buyquantity <= i.stock){
                                i.stock = i.stock - buyquantity; // Trekker fra antall kjøpte varer fra lageret
                                cout<<"Purchase completed"<<endl;
                                system("pause");
                                system("cls");
                                break;
                            }
                            else {
                                cout<<"We do no thave this amount of "<< i.name<<"(s)" <<endl;
                                system("pause");
                                system("cls");
                                break;
                            }
                        }
                    }
                }
                break;
            }

            // VALG 5: Fyll på lageret til et eksisterende produkt
            case 5: {
                int targetid;
                int restockquantity;
                bool itemfound = false; 

                cout<<"Write the product id of the item you want to be restocked"<<endl;
                cin >> targetid;

                // Steg 1: Sjekk om produkt-ID-en eksisterer
                for (Product &i : inventory){
                    if (i.id == targetid){
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

                    // Feilhåndtering hvis man skriver inn ugyldige tall (som negative tall eller tekst)
                    if (cin.fail() || restockquantity <= 0)
                    {
                        cout<<"Operation cannot be completed"<<endl; 
                        system("pause");
                        system("cls");
                        cin.clear();
                        cin.ignore();
                        break;
                    }

                    // Steg 2: Finn produktet og legg de nye enhetene til den eksisterende lagerbeholdningen
                    for (Product &i : inventory){
                        if (i.id == targetid){
                            i.stock = restockquantity + i.stock; 
                            cout<<"Restocking done!" << " "<<"Amount of the current product: "<< i.stock<<endl;
                            system("pause");
                            system("cls");
                            break;
                        }
                    }
                }
            }
        }
    }
}
