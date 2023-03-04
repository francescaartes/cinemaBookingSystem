# CINEMA BOOKING SYSTEM

Artes, Francesca Q.
Caravana, Ana Maricris A.
Serdeña, Arzel D.
Toquero, Jacqueline Sophia R.
Villapando, Christelle Denise C.

INTRODUCTION
	
    The Cinema Booking System is a software project that aims to automate the booking process in a cinema. It opts to design and implement three programs using Java, Python, and C++ programming languages with the same output and purpose. The objective of this project is to demonstrate the versatility and functionality of these three programming languages in developing a cinema booking system. The programs developed for this project apply various programming concepts such as decision structures, Boolean logic, repetition structures, functions, input validation, arrays, files, and menus. These concepts are essential in developing a functional and reliable cinema booking system.
	
    The purpose of the Cinema Booking System is to enable users to book seats for their preferred movie, date, and time slot. The program provides a user-friendly interface that allows customers to browse available movies, view their description and genre, and reserve their preferred seats. The booking system is designed to be easy to use and navigate, with clear instructions and options presented to the user.
	
    Java, Python, and C++ were chosen for this project due to their widespread use and popularity in the software development industry. Each of these programming languages has its own unique features and benefits, making them ideal for different types of software development projects. The use of the same source code in all three languages allows for a direct comparison of their strengths and weaknesses in developing the same program.
	
    In conclusion, the Cinema Booking System project aims to demonstrate the versatility and functionality of three popular programming languages, Java, Python, and C++, in developing a cinema booking system. The use of the same source code in all three languages allows for a direct comparison of their strengths and weaknesses in developing the same program. The program applies various programming concepts, such as decision structures, Boolean logic, repetition structures, functions, input validation, arrays, files, and menus, to provide a functional and reliable cinema booking system.

IMPLEMENTATION

In Python:

	The program starts by importing two libraries: "tabulate" and "random". The "tabulate" library is used to print out data in a neat and organized format, while "random" is not used in this program.
	
    Next, the "openpyxl" library is imported to read data from an Excel file named "film_list.xlsx". The data from the first sheet of the Excel file is then stored in a variable named "sheet". The movies are stored in a dictionary named "movies", where the keys are the movie numbers, and the values are another dictionary containing the movie details such as title, description, genre, and price.
	
    The "seats" dictionary stores information about the seats available for each movie. It contains sub-dictionaries for each movie, with keys "A" through "E" representing the different rows of seats, and the values being a list of integers representing the seat numbers available in each row.
	
    The program then defines a function called "dates_movie1()" to allow the user to select a date and time slot for movie 1. This function prints out a table of available dates and prompts the user to enter a number corresponding to their desired date. If the user enters an invalid number, the program will prompt them to enter a valid number. Once the user selects a valid date, the function prints out a table of available time slots for the selected date and prompts the user to enter a number corresponding to their desired time slot. Again, if the user enters an invalid number, the program will prompt them to enter a valid number. Once the user selects a valid time slot, the function returns the selected date and time slot as a tuple. The "view_showings()" function prints out a table of all the movies available and their corresponding numbers.
	
    Finally, the "vs_movie_choice()" function prompts the user to choose a movie number and displays the available dates and time slots for that movie using the "dates_movie1()" function. Once the user selects a valid date and time slot, the program displays the available seats for that movie and prompts the user to choose a seat. If the user enters an invalid seat number or the seat is already taken, the program will prompt the user to enter a valid seat number. Once the user selects a valid seat, the program displays the ticket details and prompts the user to confirm the booking. If the user confirms the booking, the program updates the "seats" dictionary and writes the ticket details to a text file. If the user cancels the booking, the program returns to the main menu.

In Java:

    The program begins by importing the java.util package, which provides the Scanner class for user input, and then defines two static Map objects: "seats" and "movies". The "seats" map is a nested map containing the available seats for each movie, while the "movies" map contains information about the movies, including their title, genre, and price. Both maps are initialized using the HashMap class.
	
    The program initializes the "movies" map using the put() method, which allows the program to add key-value pairs to the map. The keys in the map correspond to the movie numbers (1-5), and the values are nested HashMaps containing the movie title, genre, and price.
    
    The program also initializes the "seats" map using a for loop that iterates over the keys of the "movies" map. For each movie, the program creates a new HashMap object to store the available seats for each row. The available seats for each row are stored as a List of Integers, which are added to the corresponding row in the HashMap. Finally, the row map is added to the "seats" map using the movie number as the key.
	
    The main() method contains a while loop that repeatedly displays a menu of options to the user and waits for input. The user can choose to view the available showings, reserve a ticket for a movie, or exit the program. Depending on the user's input, the program calls the appropriate method: viewMovies() or reserveTicket().
	
    The viewMovies() method displays a formatted list of the available movies and their corresponding details, including the title, genre, and price. It uses a for loop to iterate over the keys of the "movies" map and retrieve the corresponding values using the get() method. The retrieved values are then formatted and printed to the console using the printf() method.
	
    The reserveTicket() method prompts the user to select a movie to book tickets for and then displays the available seats for that movie. It uses the Scanner class to read input from the user and validate the input for the movie number and number of tickets. It then retrieves the available seats for the selected movie from the "seats" map and displays them to the user in a formatted table. The user is prompted to select a seat for each ticket, and the program validates the input and marks the selected seats as unavailable in the "seats" map.

In C++:

    This program is an implementation of a cinema booking system. It has three functions: viewMovies, viewAvailableTickets, and reserveTicket. It includes several data structures like maps and vectors to store and manage information related to movies, seats, and ticket prices.
	
    The program starts with the init function, which initializes the data structures. It creates a map called "movies," which stores movie numbers as keys and a nested map as values. The nested map stores the movie's title and price as key-value pairs. It also creates a map called "seats," which stores movie numbers as keys and a nested map as values. The nested map stores the seat rows as keys and a vector of available seat numbers as values.
	
    The main function runs an infinite loop that displays a menu of options: reserve a ticket, view available movies, or cancel. Depending on the user's input, it calls the respective function.
	
    The viewMovies function prints a table of available movies with their titles and prices. The viewAvailableTickets function prints a table of available seats for each movie. The reserveTicket function prompts the user to select a movie and the number of tickets to book. It then displays the available seats for that movie and prompts the user to select the seats. After the user selects the seats, the function reserves the tickets and updates the seats data structure.


USER MANUAL

Preparation of Program

Python

1.	Install Required Libraries
1.1.	Open command prompt or terminal.
1.2.	Type "pip install tabulate" and press enter.
1.3.	Type "pip install openpyxl" and press enter.

2.	Run the Program
1.4.	Open your Python IDE or editor.
1.5.	Open a new Python file.
1.6.	Copy and paste the code into the new file.
1.7.	Save the file with a .py extension.
1.8.	Run the program by clicking the "Run" button or by typing "python <filename>.py" in the terminal.

Java

1.	Installation
1.1.	Download the CinemaBookingSystem.java file.
1.2.	Open a terminal or command prompt.
1.3.	Navigate to the directory where the CinemaBookingSystem.java file is located.
1.4.	Compile the program by typing "javac CinemaBookingSystem.java" and press enter.
1.5.	Run the program by typing "java CinemaBookingSystem" and press enter.

2.	Run the Program
2.1.	Open the IDE.
2.2.	Create a new Java project.
2.3.	Copy the CinemaBookingSystem.java file into the project folder.
2.4.	Add the CinemaBookingSystem.java file to the project.
2.5.	Compile and run the program.

C++

Preparation of the Program
1.	Open a terminal or command prompt.
1.1.	Clone the repository from GitHub using the following command: git clone https://github.com/chatgpt/cinema-booking-system.git
1.2.	Navigate to the directory where the repository is cloned.
1.3.	Compile the program using the command: g++ main.cpp -o cinema-booking-system
1.4.	Run the program using the command: ./cinema-booking-system


Program Navigation

1.	The program will display a menu with the following options:
1.1.	View Showings
1.2.	Reserve Ticket
1.3.	Exit Menu

2.	View Showings:
2.1.	Select option 1 from the menu to view available movie showings.
2.2.	The program will display a table with movie numbers and titles.
2.3.	Choose a movie by typing the corresponding number and pressing enter.
2.4.	The program will display the details of the movie such as the title, genre, and standard price of the ticket.

3.	Reserve Ticket:
3.1.	Select option 2 from the menu to reserve a movie ticket.
3.2.	The program will display a table with movie numbers and titles.
3.3.	Choose a movie by typing the corresponding number and pressing enter.
3.4.	The program will display the available dates and time slots for the selected movie.
3.5.	Choose a date and time slot by typing the corresponding number and pressing enter.
3.6.	The program will display a seating chart for the selected movie.
3.7.	Choose seats by typing the row and seat number (e.g. A1) and pressing enter.
3.8.	The program will display the selected options, total price, and transaction number.
3.9.	Choose whether to confirm the booking or cancel it by entering Y for yes or N for no.
3.10.	The program will confirm the booking.
3.11.	The program will return to the main menu.

4.	Exit Menu
4.1.	Select option 3 to Exit the Menu
4.2.	The program will end.

CONCLUSION
	
    The Cinema Booking System project has achieved the objective of demonstrating the versatility and functionality of three popular programming languages, Java, Python, and C++, in developing a cinema booking system. By using the same source code in all three languages, the project provides a direct comparison of their strengths and weaknesses in developing the same program. The project has also applied various programming concepts, such as decision structures, Boolean logic, repetition structures, functions, input validation, arrays, files, and menus, to provide a functional and reliable cinema booking system.
	
    The project has made the students more knowledgeable about the three programming languages and their applications in solving advanced programming issues. The students have faced various challenges, such as the complexity of the code, making the code concise, syntax and logic errors, and incorporating all the programming concepts. However, they have overcome these challenges by breaking down the code into manageable chunks, using data structures to store values, adopting good coding practices, and focusing on essential programming concepts.
	
    To enhance the project in the future, the addition of new features such as a cancellation system and user accounts could improve the user experience. The cancellation system would allow customers to cancel their reservations if necessary, freeing up seats for other customers. The user account feature would allow customers to create an account, view their booking history, and make future bookings more efficiently. The rating system would also be an excellent addition, allowing customers to rate and review the movies they have watched, giving other customers an idea of what to expect.
	Implementing these new features would require the incorporation of new programming concepts such as database management, user authentication, and user input validation. Using SQL, the database could store user information, booking history, and movie ratings. User authentication would ensure that only authorized users can access their accounts, and input validation would prevent users from entering invalid data.
	
    In summary, the Cinema Booking System project has achieved its objective of demonstrating the versatility and functionality of three programming languages in developing a cinema booking system. The project has provided the students with valuable experience in coding, problem-solving, and project management. By overcoming the challenges encountered during the project, the students have become more effective in solving advanced programming issues.
