public class Main{
    public static void main(String[] args) {
        Dog MyDog = new Dog(20f);

        MyDog.makeSound();
        System.out.println(MyDog.jump());
        System.out.println(Creature.volume);
    }
}