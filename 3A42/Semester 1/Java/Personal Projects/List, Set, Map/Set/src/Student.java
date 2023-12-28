public class Student {
    private int id;
    private String name;

    public Student(){}

    public Student(int id, String name){
        this.id = id;
        this.name = name;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public String toString(){
        return "Student:\tID: " + id + "\tName: " + name + "\n";
    }

    @Override
    public boolean equals(Object obj){
        if(obj == null) return false;
        if(obj instanceof Student s){
            return id == s.getId() && name.equals(s.getName());
        }
        return false;
    }

    @Override
    public int hashCode(){
        int result = 17;
        result = result * 31 + id;
        result = result * 31 + name.hashCode();
        return result;
    }
}
