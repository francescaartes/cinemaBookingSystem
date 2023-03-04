import java.util.*;


public class CinemaBookingSystem {
    static Map<String, Map<String, List<Integer>>> seats = new HashMap<>();
    static Map<String, Map<String, Object>> movies = new HashMap<>();
    static {
        movies.put("1", new HashMap<String, Object>() {{
            put("title", "Ant-Man And The Wasp: Quantumania");
            put("Genre", "Action/Adventure");
            put("price", 680);
        }});
        movies.put("2", new HashMap<String, Object>() {{
            put("title", "Avatar: The Way Of Water");
            put("Genre", "Action/Adventure");
            put("price", 680);
        }});
        movies.put("3", new HashMap<String, Object>() {{
            put("title", "Sound Of Silence");
            put("Genre", "Action/Adventure");
            put("price", 540);
        }});
        movies.put("4", new HashMap<String, Object>() {{
            put("title", "The First Slam Dunk");
            put("Genre", "Anime");
            put("price", 480);
        }});
        movies.put("5", new HashMap<String, Object>() {{
            put("title", "Oras De Peligro");
            put("Genre", "Drama");
            put("price", 380);
        }});

        for (String movie_num : movies.keySet()) {
            Map<String, List<Integer>> rows = new HashMap<>();
            rows.put("A", Arrays.asList(1, 2, 3, 4, 5));
            rows.put("B", Arrays.asList(1, 2, 3, 4, 5));
            rows.put("C", Arrays.asList(1, 2, 3, 4, 5));
            rows.put("D", Arrays.asList(1, 2, 3, 4, 5));
            rows.put("E", Arrays.asList(1, 2, 3, 4, 5));
            seats.put(movie_num, rows);
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            System.out.println("\nWelcome to Cinema Booking System!");
            System.out.println("1. View Showings");
            System.out.println("2. Reserve Ticket");
            System.out.println("3. Exit Menu");

            System.out.print("Enter choice (1-3): ");
            String choice = sc.nextLine();
            switch (choice) {
                case "1":
                    viewMovies();
                    break;
                case "2":
                    reserveTicket(sc);
                    sc.nextLine();
                    break;
                case "3":
                    System.out.println("\nThank you for using Cinema Booking System!");
                    return;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }
    public static void viewMovies() {
        System.out.printf(" -----------------------------------------------------------------------%n");
        System.out.printf("|                       N O W   S H O W I N G                           |%n");
        System.out.printf(" -----------------------------------------------------------------------%n");
        for (String key : movies.keySet()) {
            String title = (String) movies.get(key).get("title");
            String genre = (String) movies.get(key).get("Genre");
            int price = (int) movies.get(key).get("price");
            System.out.printf("| %-1s | %-35s | %-17s | %-8s|%n", key, title, genre, price);
        }
        
        System.out.printf(" -----------------------------------------------------------------------%n");

   
}

    public static void reserveTicket(Scanner sc) {
        System.out.println("\nPlease select a movie to book tickets for:");
        viewMovies();
        System.out.print("Enter movie number (1-5): ");
        String movie_num = sc.nextLine();
        if (!movies.containsKey(movie_num)) {
            System.out.println("Invalid movie number. Please try again.");
            return;
        }
        String movie_title = (String) movies.get(movie_num).get("title");
        int price = (int) movies.get(movie_num).get("price");
    
        System.out.print("\nEnter number of tickets to book: ");
        int num_tickets = sc.nextInt();
        if (num_tickets <= 0) {
            System.out.println("Invalid number of tickets. Please try again.");
            return;
        }
    
        Map<String, List<Integer>> rows = seats.get(movie_num);
        System.out.println("\nAvailable seats for the movie:");
        System.out.println("----+-----+-----+-----+-----+-----+");
        System.out.println("    |  1  |  2  |  3  |  4  |  5  |");
        System.out.println("====+=====+=====+=====+=====+=====+");
        for (String row : rows.keySet()) {
            System.out.printf("%s   |", row);
            for (int i = 1; i <= 5; i++) {
                System.out.printf("%2s   |", rows.get(row).contains(i) ? i : "  ");
            }
            System.out.println();
            System.out.println("----+-----+-----+-----+-----+-----+");
        }
        List<String> selected_seats = new ArrayList<>();
        for (int i = 1; i <= num_tickets; i++) {
            System.out.printf("\nEnter seat number for ticket %d (e.g. A1): ", i);
            String seat = sc.next().toUpperCase();
            String row = seat.substring(0, 1);
            int col = Integer.parseInt(seat.substring(1));
            if (!rows.containsKey(row) || !rows.get(row).contains(col)) {
                System.out.println("Invalid seat number. Please try again.");
                continue;
            }
            selected_seats.add(seat);
        }

        for (String seat : selected_seats) {
            String row = seat.substring(0, 1);
            int col = Integer.parseInt(seat.substring(1));
            List<Integer> cols = new ArrayList<>(rows.get(row));
            cols.remove(Integer.valueOf(col));
            rows.put(row, cols);
        }
        int total_price = price * num_tickets;

        System.out.printf(" ------------------------------------------------%n");
        System.out.printf("|            You made a reservation for          |%n");
        System.out.printf(" ------------------------------------------------%n");
        System.out.printf("| %-8s | %-35s |%n", "Movie", movie_title);
        System.out.printf("| %-8s | %-35s |%n", "Seat", selected_seats);
        System.out.printf("| %-8s | %-35s |%n", "Price", total_price);
        System.out.printf(" -------------------------------------------------%n");

        System.out.print("\nDo you want to confirm the booking? (Y/N): ");
        String confirm = sc.next().toUpperCase();

        if (confirm.equals("Y")) {
            System.out.println(" ");
            System.out.println("Booking confirmed!");
            System.out.println("Thank you for using Cinema Booking System!");
        } 
        
    }
    
}