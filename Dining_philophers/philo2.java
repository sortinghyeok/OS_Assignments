package Dining_philosopher;
import java.util.concurrent.Semaphore;

class Philosopher2 extends Thread {
	int id;
	Semaphore lfork, rfork;
	Philosopher2(int id, Semaphore lfork, Semaphore rfork) {
		this.id = id;
		this.lfork = lfork;
		this.rfork = rfork;
}
public void run() {
	try {
		for(int i = 0; i<100; i++) {
			if(id < 4) {
				lfork.acquire();
				rfork.acquire();
			}else {
				rfork.acquire(); // r0
				lfork.acquire(); // r4
			}
			eating();
			lfork.release();
			rfork.release();
			thinking();
		}
}catch (InterruptedException e) { }
}
void eating() {
	System.out.println("[" + id + "] eating");
}
void thinking() {
	System.out.println("[" + id + "] thinking");
}
}

public class philo2 {

	static final int num = 5;
	public static void main(String[] args) throws InterruptedException {
		int i;
		
		Semaphore[] fork = new Semaphore[num];
		for (i=0; i<num; i++)
			fork[i] = new Semaphore(1);
		
		Philosopher2[] phil = new Philosopher2[num];
		for (i=0; i<num; i++)
			phil[i] = new Philosopher2(i, fork[i], fork[(i+1)%num]);
		
		long sx = System.currentTimeMillis();
		for (i=0; i<num; i++)
		{
			phil[i].start();
		}
		for(i = 0; i<num; i++)
			phil[i].join();
		long ex = System.currentTimeMillis();
		System.out.println( (ex - sx) +"ms");
	}
	
}
