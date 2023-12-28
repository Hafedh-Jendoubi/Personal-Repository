public class Personne implements Comparable<Personne> {
    private String nom;
    private int age;

    Personne(){}

    Personne(String nom, int age){
        this.nom = nom;
        this.age = age;
    }

    public String getNom() {
        return nom;
    }

    public void setNom(String nom) {
        this.nom = nom;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public int compareTo(Personne p){
        return (this.age - p.age);
    }

    @Override
    public String toString(){
        return "Personne:\tName: " + nom + "\tAge: " + age + "\n";
    }
}
