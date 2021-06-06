package Dining_philosopher;

import java.util.concurrent.Semaphore;
class Philosopher1 extends Thread {
	int id;
	Semaphore lfork, rfork, once;
	Philosopher1(int id, Semaphore lfork, Semaphore rfork, Semaphore once) {
		this.id = id;
		this.lfork = lfork;
		this.rfork = rfork;
		this.once = once;
}
public void run() {
	try {
		for(int i = 0; i<100; i++) {
			
			once.acquire();
			lfork.acquire();
			rfork.acquire();
			once.release();
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

public class philo1 {

	static final int num = 5;
	public static void main(String[] args) throws InterruptedException {
		int i;
	
		Semaphore[] fork = new Semaphore[num];
		for (i=0; i<num; i++)
			fork[i] = new Semaphore(1);
		
		Semaphore once = new Semaphore(1);
		Philosopher1[] phil = new Philosopher1[num];
		for (i=0; i<num; i++)
			phil[i] = new Philosopher1(i, fork[i], fork[(i+1)%num], once);
		
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
