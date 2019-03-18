import java.rmi.registry.LocateRegistry;
import java.rmi.Naming;

public class ServerUI{
    public static void main(String ... args) throws Exception {
        int port = 1099;
        LocateRegistry.createRegistry(port); // required to avoid the 'rmiregistry' step
        Server o = new Server();
        Naming.rebind("//localhost/server", o);
        return;
    }
}