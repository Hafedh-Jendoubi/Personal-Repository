import java.text.DecimalFormat;

public class Personne {
    String name;
    int age;
    float salary;
    static int count = 0;

    Personne(){
        name = "";
        age = 0;
        salary = 0f;
    }

    Personne(String name, int age, float salary){
        this.name = name;
        this.age = age;
        this.salary = salary;
    }

    @Override
    public String toString() {
        DecimalFormat df = new DecimalFormat("#.000"); //To show 3 numbers after the decimal
        return "Name: " + name + "\n" + "Age: " + age + "\n" + "Salary: " + df.format(salary) + "\n" + "Count: " + count;
    }

    //just to see how static attribute works
    public void addCount(){
        count++;
    }
}
