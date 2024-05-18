import java.util.Objects;

public class Personne implements Comparable<Personne>{
    private String nom;
    private String prenom;
    private int age;

    public Personne(){};

    public Personne(String nom, String prenom, int age){
        this.nom = nom;
        this.prenom = prenom;
        this.age = age;
    }

    public String getNom() {
        return nom;
    }

    public void setNom(String nom) {
        this.nom = nom;
    }

    public String getPrenom() {
        return prenom;
    }

    public void setPrenom(String prenom) {
        this.prenom = prenom;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    @Override
    public String toString(){
        return "Name: " + nom + " / Prenom: " + prenom + " / Age: " + age;
    }

    @Override
    public int compareTo(Personne p1){
        return this.age - p1.getAge();
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Personne personne = (Personne) o;
        return age == personne.age && Objects.equals(nom, personne.nom) && Objects.equals(prenom, personne.prenom);
    }

    @Override
    public int hashCode() {
        int hash = 31;
        hash += age;
        hash += nom.hashCode();
        return hash;
    }
}
