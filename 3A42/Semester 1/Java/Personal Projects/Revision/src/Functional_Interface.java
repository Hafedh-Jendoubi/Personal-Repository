//@FunctionalInterface is an interface that has only 1 method, and if you will add more it will be an error
//The only way to add more, is add "default" and develop it right there. Like down below!

@FunctionalInterface
public interface Functional_Interface {
    int add(int x1, int x2);
    default int divide(int x1, int x2){
        return x1/x2;
    }

}

//To implement this in another class, you must redifinir the method add(int, int); else it would be a problem
