# STEP: 1 creating a store inventory

#This creates a menu dict which every item has its own smaller dict with its own price and damage
menu = {
    "sword": {"price": 250, "damage": 20, "stock": 3},
    "spellbook": {"price": 450, "damage": 45, "stock": 1},
    "bow": {"price":200, "damage": 35, "stock": 2},
    "flamingarrows": {"price":50, "damage": 10, "stock": 6},
    "shield": {"price": 300, "damage": 5, "stock": 4},
    "spear": {"price": 400, "damage": 30, "stock": 5}, 
}

#STEP 2: Make variables that will be used to store the players order list and his wallet 

#This variable is used to save the players orders
backpack = []
#This will be the players wallet
wallet = 1200

#STEP 3: Welcome the player to the store and show the player what the store has, and give instructions on how to use 

#Welcomes the player
print ("Welcome to the adventure store")
print ("--------------------------------")


#Prints out the menu, it first takes the item, then it takes the stats of that item, then in a print line the whole item and its properties are written
for item, stats in menu.items():
    print (f"{item}: {stats ['price']} gold coins, {stats['damage']} damage, {stats['stock']} left" )

print ("--------------------------------")
print ("\nType in what would you like to buy, then type stop once you are done or out of gold coins")
print ("--------------------------------")
 

#Step 4: Proccesing the order here
while True: 
    #PART 1: If your wallet is empty you dont get to buy more stuff
    if wallet <= 0:
        print("You ran out of gold coins!")
        break

    #Part 2: Get the input
    #This variable will be used to save each item you buy
    print(f"Your wallet: {wallet} gold coins")
    order = input("What weapon would you like to buy?: ").lower()
    print("----------------------------------")


    #PART 3: if you write stop your shopping ends. 
    if order == "stop":
        break

    #PART 4: Checking out
    if order in menu:#Checks if your order even exists in the store
        if menu[order]["price"] <= wallet: #Checks if you can afford it 
            if menu[order]["stock"] > 0: #Checks if its on stock
                wallet -= menu[order]["price"] #Takes money out of your wallet depending on the price of your order
                backpack.append(order)#Takes your order in the shopping cart
                menu[order]["stock"] -= 1 #removes the stock by one 
                print(f"{order} was succesfully added to the cart")
            else: 
                print(f"We dont have {order} anymore")
        else: 
            print("Seems like you cannot afford this item unfortunately")
    else: 
        print (f"Sorry we dont sell {order} around here")


#STEP 5: Printing out your receipt
print ("\n------Receipt-----")
totalprice = 0 #this is for the total price

for order in backpack: #for each item in your backpack
    price = menu[order]["price"] #takes the price of the item
    damage = menu[order]["damage"]#takes the damage of the order
    totalprice += price #adds up on your total price
    print(f"{item}: {price} gold coins, damage: {damage}") #prints out the item price and order and damage
print("-------------------\n")

print(f"{wallet} gold coins left in your wallet")
print (f"Thank you for buying! Your total price is {totalprice} gold coins!")






