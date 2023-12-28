public class Main {
    public static void main(String[] args) {
        //Declaration des variables:
        Corporation c1 = new Corporation(0, 0);
        Personne p1 = new Personne("Hafedh", 21, 2500.500f);
        Personne p2 = new Personne("Majdi", 24, 3000.900f);
        Personne p3 = new Personne();

        /**
        System.out.println(p1.toString());
        System.out.println(p2.toString());
        System.out.println(p3.toString());
                                                            [-----------------------------------]
        p1.addCount();                                      |TEST IS DONE WITH THIS BLOC OF CODE|
                                                            [-----------------------------------]
        System.out.println(p1.toString());
        System.out.println(p2.toString());
         **/

        c1.addPersonne(p1);
        c1.addPersonne(p2);

        c1.displayCorporation();
    }
}