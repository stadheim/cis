// Java
public class Main {
  public static void main(String[] args) {
    // SLETT 
    int minutter = 2;
    int nummer = 1;

    boolean dametoalett = true;
    boolean herretoalett = false;

    if (minutter > 2) {
      herretoalett = false;
    } else {
      if (nummer == 2) {
        herretoalett = false;
      } else if (nummer == 1) {
        herretoalett = true;
      }  else {
        System.out.println("Hva driver du med...");
      }
    }
    System.out.println(herretoalett);
  }
}
