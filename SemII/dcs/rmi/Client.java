import java.rmi.Naming;

public class Client {
    public static void  main(String ... args) throws Exception {
        ServerInterface o = (ServerInterface) Naming.lookup("//localhost/server");
        int a = Integer.parseInt(args[0]);
        int b = Integer.parseInt(args[1]);
        System.out.println(o.addition(a, b));
        return;
    }
}