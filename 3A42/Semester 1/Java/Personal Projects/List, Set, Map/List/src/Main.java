import java.util.Collection;
import java.util.Collections;
import java.util.List;
import java.util.ArrayList;
import java.util.Comparator;

public class Main {
    public static void main(String[] args) {
        //Declaration ArrayList
        List myList = new ArrayList<>();

        //Add Elements
        myList.add("Hafedh");
        myList.add(21);
        myList.add(true);
        //Add same element
        myList.add("Hafedh");

        //Display of ArrayList
        System.out.println(myList);


        List<String> myStrings = new ArrayList<>(2);

        //myStrings.add(12); Can't add 'int'
        myStrings.add("Hafedh");
        myStrings.add("Jendoubi");
        /* It can add a 3rd column even if I set it to just 2.*/ myStrings.add("Ibn Arfa");

        System.out.println("Deuxieme element est: " + myStrings.get(1));
        myStrings.set(2, "Ibn Abi Dhief"); //Change the value of a given index number.
        System.out.println(myStrings);

        //Remove an element from the ArrayList:
        myStrings.remove(0);
        System.out.println(myStrings.contains("Hafedh")); //False, cause we removed the index 0 which has a value of "Hafedh"


        //Using now the Collections class we can sort, tri, recherche, inverse..
        Collections.sort(myStrings); //Tri alphabétique
        System.out.println(myStrings);

        /* ------------------------------------ */ System.out.println("\n"); /* ------------------------------------ */
        /* -------------------------------------------- New Things ------------------------------------------------- */
        /* ------------------------------------ */ System.out.println("\n"); /* ------------------------------------ */

        List<Personne> personnes = new ArrayList<>();
        Personne p1 = new Personne("Slah", 58);
        Personne p2 = new Personne("Hafedh", 21);
        Personne p3 = new Personne("Ahmed", 21);
        Personne p4 = new Personne("Majdi", 24);
        Personne p5 = new Personne("Nada", 16);

        personnes.add(p1);
        personnes.add(p2);
        personnes.add(p3);
        personnes.add(p4);
        personnes.add(p5);

        System.out.println("Personnes table got:");
        System.out.println(personnes);

        //Now we are going to use the sort using the FunctionalInterfaces ageComparator & nomComparator
        Comparator<Personne> ageComparator = new Comparator<Personne>() {
            @Override
            public int compare(Personne p1, Personne p2) {
                return p1.getAge() - p2.getAge();
            }
        };

        Comparator<Personne> nomComparator = new Comparator<Personne>() {
            @Override
            public int compare(Personne p1, Personne p2) {
                return p1.getNom().compareTo(p2.getNom());
            }
        };

        System.out.println("Tri simple, using age cause compareTo redifintion in Personne.java");
        Collections.sort(personnes);
        System.out.println(personnes);

        System.out.println("tri nom first, then age");
        Collections.sort(personnes, nomComparator.thenComparing(ageComparator));
        System.out.println(personnes);

    }
}