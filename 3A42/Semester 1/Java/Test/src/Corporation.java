import java.util.EnumMap;

public class Corporation {
       Personne[] tab;
       int number;
       float totalSalary;

       Corporation(){
           number = 0;
           totalSalary = 0;
       }

       Corporation(int number, float totalSalary){
           tab = new Personne[number];
           this.number = number;
           this.totalSalary = totalSalary;
       }

       public void addPersonne(Personne p){
           tab[number+1] = p;
           number++;
       }

       public void displayCorporation() {
           System.out.println("Corporation Info: \n");
           for(int i=0; i<tab.length-1; i++) {
               System.out.println("Personne n°" + (i+1) + "\n");
               System.out.println(tab[i].toString());
               System.out.println("\n");
           }
       }
}