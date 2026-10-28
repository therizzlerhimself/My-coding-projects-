#Here we have all the questions with the answers in a dictionary
ordbok = {
    "Hva er hovedstaden I Norge?": "Oslo",
    "Hva er hovedstaden I Frankrike?": "Paris",
    "Hva er hovedstaden I Tyskland?": "Berlin",
    "Hva er hovedstaden I Italia?": "Rome",
    "Hva er hovedstaden I Spania?": "Madrid"
}

print("Velkomen til Hovedstadsquizen!\n")

#Those variables will be used to calculate and display how many times you got it wrong/right
correct = 0
wrong = 0

#This loop will print each question then ask for your answer,
for question, answer in ordbok.items():
    youranswer = input(question).capitalize()
    if youranswer == answer: #if its true then you will get feedback and one point added to correct
        print("Riktig!")
        correct += 1
    else : #If its wrong then you will have a wrong point added 
        print("Feil!")
        wrong += 1
#This prints out your score
print ("\n--------Din score-----------")
print (f"Du har {correct} riktig og {wrong} feil.")