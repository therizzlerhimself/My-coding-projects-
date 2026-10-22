import math

print("Velkommen til Pizzafest!")

#Denne variabel er brukt til å lagre outputen din
navn_liste = []

#I denne løkken skal outputen din være sjekket 
while True:

    gjest = input("Skriv navn til gjester eller stopp: ")

    #Hvis du skriver stopp den skal stoppe løkken 
    if gjest == "stopp": 
            gjest = " og ".join(navn_liste)
            break

    #Etter løkken sjekker hvis du skrevet stopp eller ikke, den skal legge til navne i listen
    navn_liste.append(gjest)

#Her totalgjester er variabelen som tar alle navn og bruker len til å telle dem
totaltgjester = len(navn_liste)

#her dividerer det en pizza for 4 foll ov hvis det er mindre en 4 for eksempel den oppsummerer med math.ceil
antallpizza = math.ceil(totaltgjester/4)
#Og her du skriver inputten din 
prisen = int(input("Hvor mye koster pizza?: "))
#Totalt pris er prisen for en pizza og antall pizza som må ble kjøpt 
totaltpris = (prisen * antallpizza)


print(f"Gjestene på pizza festen er:\n{gjest}\n{totaltgjester} gjester \nTotal pris {totaltpris} kroner"  )

    
    