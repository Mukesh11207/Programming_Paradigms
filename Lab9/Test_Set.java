import java.util.concurrent.atomic.*;

public class Test_Set{
    static AtomicBoolean lock = new AtomicBoolean(false);
    static int counter = 0;

    static void acquire(){
        while(lock.getAndSet(true)){
        }
    }
    static void release(){
        lock.set(false);
    }
    static void work(int id) {
        for (int i = 0; i < 100000; i++) {
            acquire();
            counter++;
            release();
        }

        System.out.println("Thread " + id + " completed");
    }
    public static void main(String[] args) throws InterruptedException{
        Thread t1 = new Thread(() -> work(1));
        Thread t2 = new Thread(() -> work(2));

        t1.start();
        t2.start();

        t1.join();
        t2.join();

        System.out.println("Final counter = " + counter);
    }
}
