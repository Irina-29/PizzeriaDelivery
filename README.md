# PizzeriaDelivery :pizza:
This is a console application where users can create an account and order pizza.
## How It Works
* This console application uses a register and login system with database file to create a user account 
* If the database text file doesn't exist, the function for creating an account will also create the file
* The data from the text file is saved and ready to be used later, even after the console application has finished and closed
* For the login, process the users' data from the text file is transferred to a linked list where each node represents a user and contains user credentials and details
* The email address and password validation and other operations with user data are made with different linked list functions
* For ordering pizza, the user can add different pizza types in the shopping cart
* The pizza menu was created using a structure which contains the name and the price of the pizzas
* The cart is a linked list which contains the name, the amount and the price of the pizzas and calculates the total
* After adding at least one pizza in the cart, the user has the option to "continue shopping", to "remove a pizza" or to "proceed to checkout"
* The "continue shopping" option takes the user back to the pizza menu
* After the user has removed a pizza from the cart with the "remove a pizza" option, the updated cart is shown and the user has the option to "continue shopping" or to "proceed to checkout"
* If there is only one pizza in the cart and the user wants to remove it, the "proceed to checkout" option takes the user to the pizza menu
* At checkout, the cart and delivery details are shown
* After the delivery has been confirmed, a message will appear and the console application will finish
