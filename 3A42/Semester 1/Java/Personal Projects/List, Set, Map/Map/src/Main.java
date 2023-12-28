import java.util.*;

import static java.time.chrono.JapaneseEra.values;

public class Main {
    public static void main(String[] args) {
        Map<String, Integer> studentScores = new HashMap<>();
        studentScores.put("Hafedh", 16);
        studentScores.put("Rayen", 15);
        studentScores.put("Ahlem", 17);

        System.out.println(studentScores.get("Rayen")); //.get(Key) gets the value of the key

        if(studentScores.containsKey("Hafedh"))
            System.out.println("Hafedh existe");
        else
            System.out.println("Hafedh n'existe pas");

        studentScores.remove("Rayen"); //.remove obvious

        System.out.println(studentScores);

        System.out.println("Keys display:");
        Set<String> keys = studentScores.keySet();
        Iterator<String> it = keys.iterator();
        while(it.hasNext()){
            System.out.println(it.next());
        }
        System.out.println("Values display:");
        Collection<Integer> values = studentScores.values();
        for(Integer it2 : values){
            System.out.println(it2);
        }
        System.out.println("Display keys and values at the same time:");
        for(Map.Entry<String, Integer> entry : studentScores.entrySet()){
            System.out.println(entry.getKey() + ": " + entry.getValue());
        }
    }
}