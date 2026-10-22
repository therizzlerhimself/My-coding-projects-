#Menu dict, with product and prices
Menu = {
    "Popcorn": 30,
    "Soda": 25,
    "Chips": 35,
    "Cheese pop": 40
}

#Variable used to save the users products
shoppingcart = []

#Prints out the menu with a for loop, 
print("Welcome to the Kinokiosken")
for product, price in Menu.items():
    print(f"- {product}: {price}kr")

print("\nType the product you want to buy, or type done to end the shopping\n")

#Buying logic
while True:
    order = input("What would you like to buy?\n")
    if order =="done":
        break

    #Checks if the order matches any of the items with a for loop, then it adds it in the shopping cart and lets you know 
    if order in Menu: 
        shoppingcart.append(order)
        print(f"Added {order} to the cart!")
    else: # if your order doesnt match any of the products this will happen
        print("Sorry, we dont have such product! Try again")

totalprice = 0
#Prints out the receipt
print ("---RECEIPT---")
#Does the math, checks the products in the shopping cart, then it takes the price from that certain product and adds it to the total price
for product in shoppingcart: 
    price = Menu[product]
    totalprice += price
    print(f" - {product}: {price} kr")

print(f"Your total price will be {totalprice} kroner\n Thank you for buying!")







