import math

#Produkter
Products= {
    "Billett": 135,
    "Popcorn" : 50,
    "Drikker" : 30,
    "Baconsnacks": 40
}

#Variabler som skal brukes senere 
tickets = []
snacks = []
storeOn = True

#While løke som fungerer sæ lenger storeON er True
while storeOn == True: 
    print(f"-----Velkomen på Kino!-----\nBillett pris: {Products['Billett']} kr\n---------------------------")

    #Her skriver du hvor mange billetter du skal ha
    ticketamount = int(input("Hvor mange billetter skal dere kjøpe?: "))

    #og for hvert billett du kjøper skal du skrive navn
    for ticket in range(ticketamount):
        name = input(f"Skriv navn {ticket + 1}: ").capitalize()
        tickets.append(name)
        print(f"Navn: {name} lagt til")

    #Du for billet lista før du kan kjøppe snacks
    print(f"---------------------------------\nBillett liste: {', '.join(tickets)}\n------------------------------------")

    #Du blir spurt hvis du skal kjøpe noe snacks eller drikk
    buysnacks = input("Skal du kjøpe noe drikk eller snacks?(skriv ja eller nei): ").lower()

    #Hvis din svar er nei løkken skal hoppe ut og du skal få kvitteringen
    if buysnacks == "nei":
        break
    #Men hvis du skriver ja, en ny while løkke skal starte
    elif buysnacks == "ja":
        
        while buysnacks == "ja":
            print ("--------Snacks og drikker--------")

            #printer ut liste med produkter uten billett fordi billett er ikke spiselig
            for product, price in Products.items():
                if product == "Billett":
                    continue
                print(f"{product}: {price} kr")
            
            #Spører deg hva du skal kjøpe
            ordersnack = input("Hva skal du kjøpe?(skrive stopp når du er ferdig): ").capitalize()
            #Hvis du skriver Stopp, den avslutter løkka
            if ordersnack == "Stopp":
                storeOn = False #Deaktiverer hoved løkka
                break

            #Hvis din order er i produkter du skal bli spurt om hvor mange av denne produkten du skal ha 
            if ordersnack in Products:
                orderamount = int(input(f"Hvor mange {ordersnack} skal du ha? "))

                #etter det, hvert produkt skal være lagt til 
                for tempsnack in range(orderamount):
                    snacks.append(ordersnack)
                #Også du får bekreftelse om det
                print(f"Lagt til x{orderamount} {ordersnack} ")
            else: #Hvis din produkt er ikke i Produkt dictionary 
                print(f"Vi har ikke {ordersnack}")

#Hvis du har ikke kjøpet drikker den skal anbefalle deg å kjøpe
if snacks.count("Drikker") < ticketamount: #Sjekker hvor mye drikker du kjøpet og sammenligner det med hvor mye billetter du kjøpet
    choice = input("\nEr du sikker at du vil ikke ha noe/nok å drikke? Vi anbefaller at du skal kjøpe en drikke per person (skriv ja eller nei)").lower()
    #Hvis ja den spører deg hvor mange drikk du skal 
    if choice == "ja":
        drinkamount = int(input("Hvor mange drikker skal du ha?"))
        for amount in range(drinkamount):# Legger til hvert drikke
            snacks.append("Drikker")
    else: #Hvis du skriver noe annet
        print("Ingen extra drikker lagt til\n")



#Kvittering
print("-------Kvittering-------")
print(f"Billett liste: {', '.join(tickets)}")

#Kalkulerer billetter total pris 
ticketsprice = Products['Billett'] * len(tickets)

#Gruppe rabatt for 4 eller mer folk 
if len(tickets) >= 4:
    ticketsprice = math.ceil(ticketsprice * 0.85)
    print(f"Billett antall: x{len(tickets)} --- {ticketsprice} kr med grupper rabatt\n")
else:#Uten rabatt
    print(f"Billett antall: x{len(tickets)} --- {ticketsprice} kr\n")

#Snacks pris
snacksprice = 0

#Hvis du har snacks den skal printe det ut i kvitteringen
if snacks:
    print("Snacks og drikker: ")
    for item in set(snacks): #Settet sørger for at en variabel ikke gjentas flere ganger 
        snacksprice += snacks.count(item) * Products[item] #Den legger til prisen av hver produkt 
        print(f"x{snacks.count(item)} {item} --- {snacks.count(item) * Products[item]} kr") #Og her printer hver enkelt type snack med hvor mange det er 
print(f"---------Totalpris: {snacksprice + ticketsprice} kr--------------") #også totalprisen her
