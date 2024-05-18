import java.util.*;
import java.util.stream.Stream;

public class Main {
    public static void main(String[] args) {
        /*Chapitre 9: List */
        System.out.println("----------------- Chapitre 9: List -----------------");
        /* ---- Declaration of List that can contain any type of variable ----- */
        List AnyVarType = new ArrayList<>();
        AnyVarType.add("Hello");
        AnyVarType.add(123);
        AnyVarType.add(1.23);
        AnyVarType.add(true);
        System.out.println(AnyVarType);
        /* ---- Just a string list, .get() / .set() / .remove() / .contains() ----- */
        List<String> OnlyStrings = new ArrayList<>(2);
        OnlyStrings.add("Hello");
        OnlyStrings.add("World");
        OnlyStrings.add("!");
        System.out.println(OnlyStrings.get(1));
        OnlyStrings.set(1, "Hafedh");
        System.out.println(OnlyStrings.get(1));
        OnlyStrings.remove("!");
        System.out.println(OnlyStrings.contains("!"));
        /* ---- sout(List) but you need to redifine toString() in the class Personne  ----- */
        List<Personne> Personnes = new ArrayList<Personne>();
        Personne p1 = new Personne("Jendoubi", "Hafedh", 21);
        Personne p2 = new Personne("Jendoubi", "Majdi", 24);
        Personne p3 = new Personne("Yessine", "Jmeai", 19);
        Personnes.add(p1); Personnes.add(p2); Personnes.add(p3);
        System.out.println("Redifinition of toString(): " + Personnes); //You need to add toString() in Personne.java in order to use this
        /* ---- Collections ----- */
        Collections.shuffle(Personnes);
        System.out.println("Shuffle result: " + Personnes);
        Comparator<Personne> NomComparator = new Comparator<Personne>() {
            @Override
            public int compare(Personne o1, Personne o2) {
                return o1.getNom().compareTo(o2.getNom());
            }
        };
        Comparator<Personne> AgeComparator = new Comparator<Personne>(){
            @Override
            public int compare(Personne o1, Personne o2){
                return o1.getAge() - o2.getAge();
            }
        };
        //Collections.sort(Personnes); // This will use just the compareTo()
        System.out.println("Sort() Age result: " + Personnes);
        Collections.sort(Personnes, NomComparator); // This will use tge Comparator compare() above
        System.out.println("Sort() Nom result: " + Personnes);
        Collections.sort(Personnes, NomComparator.thenComparing(AgeComparator));
        System.out.println("Sort() Nom then Age result: " + Personnes);
        /*
            ///////////////////////////////////////////////////////////////////////
            ///////////////////////////////////////////////////////////////////////
         */

        /*Chapitre 10: Set */
        System.out.println("\n\n----------------- Chapitre 10: Set -----------------");
        /* ---- Declaration of different Set subclasses and explain ----- */
        Set myHashSet = new HashSet(); // Accepte any type of object, Ordre changed
        Set myLinkedHashSet = new LinkedHashSet(); //Same as HashSet, but this will remain the order
        Set myTreeSet = new TreeSet(); //Accepte un seul type d'objet, Comparable or Comparator needed here in order for sort
        myHashSet.add("Test"); myHashSet.add(2); myHashSet.add(null); myHashSet.add(true); myHashSet.add(2.43);
        System.out.println("myHashSet: " + myHashSet);
        myTreeSet.add("Hafedh"); myTreeSet.add("Majdi"); myTreeSet.add("Rayen"); myTreeSet.add("Ahlem"); myTreeSet.add("Yessine");
        System.out.println("myTreeSet: " + myTreeSet); //Sort automatique, car String implément the interface comparable
        /* ---- Declaration of Set of strings and trying to parcour it ----- */
        Set<String> myStringSet = new HashSet<String>();
        myStringSet.add("Hello"); myStringSet.add("this"); myStringSet.add("is me.");
        System.out.println(myStringSet); //Set Display example 1
        /* Set Display example 2 */
        for(String s : myStringSet){
            System.out.println(s);
        }
        /* ---- As we can see down below, it accepted the doublons. Cause equals() & hashCode() is not redifined in Personne.java  ----- */
        Set<Personne> myPersons = new HashSet<Personne>();
        myPersons.add(new Personne("Jendoubi", "Slah", 58));
        myPersons.add(new Personne("Jendoubi", "Saloua", 52));
        myPersons.add(new Personne("Klai", "Abdelattif", 55));
        myPersons.add(new Personne("Jendoubi", "Slah", 58)); //If equals() & hachCode() are not implemented, it'll add
        for (Personne myPerson : myPersons) {
            System.out.println(myPerson);
        }
        /* ---- Declaration of TreeSet and using the Comparable already to tree it manually ----- */
        Set<Personne> TreePersons = new TreeSet<Personne>();
        TreePersons.add(new Personne("Ben Romdhane", "Najla", 56));
        TreePersons.add(new Personne("Ben Romdhane", "Khaled", 42));
        TreePersons.add(new Personne("Ben Romdhane", "Khaled", 62));
        TreePersons.add(new Personne("Klai", "Lamia", 50));
        System.out.println("Using the Comparable result: " + TreePersons); //Triée par age, because of compareTo() already declared. The implements of Comparable
        /* Declaring a new TreeSet using the data of an unsorted HashSet and sort it automatically. */
        Set<Personne> treeset = new TreeSet<Personne>(myPersons); //This is a constructeur de copie, It does the tri of a HashSet
        System.out.println("La liste triée est: ");
        System.out.println("Using the constructor de recopie result: " + treeset);
        /* ---- Declaration of TreeSet and using the Comparator to tree it ----- */
        Comparator<Personne> nomComp = new Comparator<Personne>(){
            @Override
            public int compare(Personne p1, Personne p2){
                return p1.getNom().compareTo(p2.getNom());
            }
        };
        Set<Personne> comparatorPersonne = new TreeSet<Personne>(nomComp);
        comparatorPersonne.add(new Personne("Klai", "Rania", 27));
        comparatorPersonne.add(new Personne("Cherni", "Mido", 17));
        comparatorPersonne.add(new Personne("Jmai", "Adem", 17));
        System.out.println("Using the Comparator result: " + comparatorPersonne);
        /*
            ///////////////////////////////////////////////////////////////////////
            ///////////////////////////////////////////////////////////////////////
         */

        /*Chapitre 11: Map */
        System.out.println("\n\n----------------- Chapitre 11: Map -----------------");
        System.out.println("Just read the notepad that I have.");
        /*
            ///////////////////////////////////////////////////////////////////////
            ///////////////////////////////////////////////////////////////////////
         */

        /*Chapitre 12: Interfaces Fonctionnelles & Expression Lambda */
        System.out.println("\n\n----------------- Chapitre 12: Interfaces Fonctionnelles & Expression Lambda -----------------");
        /* ---- Instanciation of a functional interface ----- */
        Functional_Interface interf = new Functional_Interface() {
            @Override
            public int add(int x1, int x2) {
                return x1 + x2;
            }
        };
        System.out.println(interf.add(5, 7));
        /*
            ///////////////////////////////////////////////////////////////////////
            ///////////////////////////////////////////////////////////////////////
         */

        /*Chapitre 13: Stream */
        System.out.println("\n\n----------------- Chapitre 13: Stream -----------------");
        List<Integer> numbers = Arrays.asList(1, 2, 3, 4, 5);
        System.out.println(numbers.stream().filter(v -> v<5).mapToInt(i -> i).sum());

        Optional<String> myOptional = Optional.ofNullable("Hafedh");
        System.out.println(myOptional.get());

        List<String> letters = Arrays.asList("a1", "a2", "b1", "b3", "c1");
        letters.stream()
                .filter(s -> s.startsWith("b"))
                .map(String::toUpperCase)
                .sorted()
                .forEach(System.out::println);
    }
}