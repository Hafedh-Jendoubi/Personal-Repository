import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;
import java.util.TreeSet;

public class Main {
    public static void main(String[] args) {
        int[] count = {10, 20, 30, 40, 50};
        Set myHashset = new HashSet();

        for(int i=0; i<5; i++){
            myHashset.add(count[i]);
        }
        System.out.println(myHashset + "\n"); //HashSet is not triées

        /* ----------------------------------------------------------------------------------- */

        // Création d'un HashSet de type String pour stocker des éléments uniques.
        Set<String> monHashSet = new HashSet<>();

        // Ajout de trois chaînes de caractères arbitraires dans le HashSet.
        monHashSet.add("1");
        monHashSet.add("2");
        monHashSet.add("3");
        monHashSet.add("1"); // It won't add because HashSet doesn't accept doublons.

        // Création d'un itérateur pour parcourir les éléments du HashSet.
        Iterator<String> it = monHashSet.iterator();

        // Boucle while pour parcourir le HashSet tant qu'il y a des éléments suivants.
        while(it.hasNext()) {
            // Affichage de l'élément suivant dans la console.
            System.out.println(it.next());
        }
        System.out.println("\n");

        /* ----------------------------------------------------------------------------------- */

        Set<Student> Students = new HashSet<>();

        Students.add(new Student(1, "Hafedh"));
        Students.add(new Student(2, "Majdi"));
        Students.add(new Student(1, "Hafedh")); //Implemening the hashCode() and equals() in Student class is the reason it did not accept this

        Iterator<Student> iterator = Students.iterator();
        while(iterator.hasNext()){
            System.out.println(iterator.next());
        }
        System.out.println("\n");

        /* ----------------------------------------------------------------------------------- */

        TreeSet<String> treeset = new TreeSet<>(monHashSet);
        System.out.println(treeset);


    }
}