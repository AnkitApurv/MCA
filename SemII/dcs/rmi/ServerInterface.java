import java.rmi.Remote;
import java.rmi.RemoteException;

public interface ServerInterface extends Remote {
    public int addition(int a, int b) throws RemoteException;
}