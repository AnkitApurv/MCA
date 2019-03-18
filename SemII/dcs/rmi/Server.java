import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

//rmic serverClassName
// -keep switch to save stub source

public class Server extends UnicastRemoteObject implements ServerInterface {
    private static final long serialVersionUID = 1L; //not needed only if stub is being generated manually (pre J2SE 5.0 way)

    public Server() throws RemoteException {
        //https://en.wikipedia.org/wiki/Java_remote_method_invocation#Example
        //https://docs.oracle.com/javase/1.5.0/docs/guide/rmi/relnotes.html
        super(0);   // required to avoid the 'rmic' step
    }

    public int addition(int a, int b) {
        return (a + b);
    }
}