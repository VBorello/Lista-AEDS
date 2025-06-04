import java.io.*;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;
import java.util.*;

class Show {
    String showId;
    String type;
    String title;
    String director;
    String cast;
    String country;
    String dateAdded; // string original
    LocalDate date;   // data convertida
    int releaseYear;
    String rating;
    String duration;
    String listedIn;
    String description;

    // Formato do dateAdded: "October 1, 2019"
    private static final DateTimeFormatter formatter = DateTimeFormatter.ofPattern("MMMM d, yyyy", Locale.ENGLISH);

    public Show(String showId, String type, String title, String director, String cast, String country, String dateAdded,
                int releaseYear, String rating, String duration, String listedIn, String description) {
        this.showId = showId;
        this.type = type;
        this.title = title;
        this.director = director;
        this.cast = cast;
        this.country = country;
        this.dateAdded = dateAdded;
        this.releaseYear = releaseYear;
        this.rating = rating;
        this.duration = duration;
        this.listedIn = listedIn;
        this.description = description;

        try {
            this.date = LocalDate.parse(dateAdded, formatter);
        } catch (DateTimeParseException e) {
            this.date = null;
        }
    }

    public void print() {
        System.out.print("=> " + showId + " ## " + title + " ## " + type + " ## ");
        System.out.print(nullOrNaN(director) + " ## ");

        System.out.print("[");
        if (cast != null && !cast.trim().isEmpty()) {
            String[] elenco = cast.split(", ");
            Arrays.sort(elenco);
            for (int i = 0; i < elenco.length; i++) {
                System.out.print(elenco[i]);
                if (i < elenco.length - 1) {
                    System.out.print(", ");
                }
            }
        } else {
            System.out.print("NaN");
        }
        System.out.print("] ## ");

        System.out.print(nullOrNaN(country) + " ## ");

        // Imprime a data no formato original (sem converter para dd/mm/yyyy)
        System.out.print(nullOrNaN(dateAdded) + " ## ");

        System.out.print(releaseYear + " ## ");

        System.out.print(nullOrNaN(rating) + " ## ");
        System.out.print(nullOrNaN(duration) + " ## ");

        System.out.print("[");
        if (listedIn != null && !listedIn.trim().isEmpty()) {
            String[] generos = listedIn.split(", ");
            for (int i = 0; i < generos.length; i++) {
                System.out.print(generos[i]);
                if (i < generos.length - 1) {
                    System.out.print(", ");
                }
            }
        } else {
            System.out.print("NaN");
        }
        System.out.println("] ##");
    }

    private String nullOrNaN(String s) {
        if (s == null || s.trim().isEmpty()) {
            return "NaN";
        }
        return s;
    }


    private String formatarData(String data) {

        if (data == null || data.isEmpty()) {
            return "";
        }
        try {

            Map<String, String> meses = Map.ofEntries(
                    Map.entry("January", "01"), Map.entry("February", "02"), Map.entry("March", "03"),
                    Map.entry("April", "04"), Map.entry("May", "05"), Map.entry("June", "06"),
                    Map.entry("July", "07"), Map.entry("August", "08"), Map.entry("September", "09"),
                    Map.entry("October", "10"), Map.entry("November", "11"), Map.entry("December", "12")
            );

            String[] partes = data.split(" ");
            String dia = partes[1].replace(",", "");

            String mes = meses.get(partes[0]);
            String ano = partes[2];

            if (dia.length() == 1) {
                dia = "0" + dia;
            }

            return dia + "/" + mes + "/" + ano;
        } catch (Exception e) {
            return data;
        }
    }
}

class Node {

    Show show;
    Node prev, next;

    Node(Show show) {
        this.show = show;
    }
}

class DoublyLinkedList {

    Node head, tail;
    static int comparisons = 0;
    static int movements = 0;

    public void insertEnd(Show show) {

        Node node = new Node(show);
        if (head == null) {
            head = tail = node;
        } else {
            tail.next = node;
            node.prev = tail;
            tail = node;
        }
    }

    public void printList() {

        Node temp = head;

        while (temp != null) {
            temp.show.print();
            temp = temp.next;
        }
    }

    private Node partition(Node low, Node high) {
        LocalDate pivotDate = high.show.date;
        String pivotTitle = high.show.title;
        Node i = low.prev;

        for (Node j = low; j != high; j = j.next) {
            comparisons++;
            // Compara datas, trata null como maior para ir ao final
            int cmp;
            if (j.show.date == null && pivotDate == null) {
                cmp = 0;
            } else if (j.show.date == null) {
                cmp = 1;
            } else if (pivotDate == null) {
                cmp = -1;
            } else {
                cmp = j.show.date.compareTo(pivotDate);
            }

            // CORREÇÃO AQUI: usar < 0 para título, não <= 0
            if (cmp < 0 || (cmp == 0 && j.show.title.compareTo(pivotTitle) < 0)) {
                i = (i == null) ? low : i.next;
                swap(i, j);
                movements += 3;
            }
        }
        i = (i == null) ? low : i.next;
        swap(i, high);
        movements += 3;
        return i;
    }

    private void swap(Node a, Node b) {

        Show temp = a.show;
        a.show = b.show;
        b.show = temp;
    }

    public void quickSort(Node low, Node high) {

        if (high != null && low != high && low != high.next) {
            Node p = partition(low, high);

            quickSort(low, p.prev);
            quickSort(p.next, high);
        }
    }
}

class Parser {

    public static Show parseShow(String line) {

        String[] fields = new String[12];
        int fieldIndex = 0;

        boolean inQuotes = false;
        StringBuilder current = new StringBuilder();

        for (int i = 0; i < line.length(); i++) {

            char c = line.charAt(i);

            if (c == '"') {
                inQuotes = !inQuotes;
            } else if (c == ',' && !inQuotes) {
                fields[fieldIndex++] = current.toString().trim();
                current.setLength(0);
            } else {
                current.append(c);
            }
        }

        fields[fieldIndex] = current.toString().trim();

        int releaseYear = fields[7].equals("") ? 0 : Integer.parseInt(fields[7]);
        return new Show(fields[0], fields[1], fields[2], fields[3], fields[4], fields[5],
                fields[6], releaseYear, fields[8], fields[9], fields[10], fields[11]);
    }
}

public class Main {

    public static void main(String[] args) {

        Map<String, Show> showMap = new HashMap<>();

        try (BufferedReader br = new BufferedReader(new FileReader("/tmp/disneyplus.csv"))) {

            String line = br.readLine();

            while ((line = br.readLine()) != null) {
                Show show = Parser.parseShow(line);
                showMap.put(show.showId, show);
            }
        } catch (IOException e) {
            e.printStackTrace();

            return;
        }

        DoublyLinkedList list = new DoublyLinkedList();
        Scanner scanner = new Scanner(System.in);
        String input;

        while (!(input = scanner.nextLine()).equals("FIM")) {
            Show show = showMap.get(input);

            if (show != null) {
                list.insertEnd(show);
            }
        }

        scanner.close();

        long startTime = System.nanoTime();
        list.quickSort(list.head, list.tail);

        long endTime = System.nanoTime();

        list.printList();

        try (BufferedWriter bw = new BufferedWriter(new FileWriter("matricula_quicksort.txt"))) {

            bw.write("Matricula: 123456\n");
            bw.write("Comparações: " + DoublyLinkedList.comparisons + "\n");
            bw.write("Movimentações: " + DoublyLinkedList.movements + "\n");
            bw.write("Tempo de execução: " + (endTime - startTime) / 1e6 + " ms\n");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
