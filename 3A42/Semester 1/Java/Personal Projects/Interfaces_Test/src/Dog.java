public class Dog implements Animal{
    private float z;

    public Dog(){
        z = 0f;
    }

    public Dog(float z){
        this.z = z;
    }
    @Override
    public void makeSound() {
        System.out.println("Ho Ho!");
    }

    @Override
    public float jump() {
        return (z + 1.5f);
    }

    @Override
    public void Create(){
        System.out.println("Creature has been created.");
    }
}
