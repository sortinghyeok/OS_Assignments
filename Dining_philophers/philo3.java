package Dining_philosopher;
import java.util.concurrent.Semaphore;
class Philosopher3 extends Thread
{
	int id;
	Semaphore lfork;
	Semaphore rfork;
	Philosopher3(int id, Semaphore lfork, Semaphore rfork)
	{
		this.id = id;
		this.lfork = lfork;
		this.rfork = rfork;
	}
	
	public void run()
	{
		try {
			for(int i = 0; i<10000; i++)
			{
				if(this.id % 2 == 0)
				{
					lfork.acquire();
					rfork.acquire();
				}
				else
				{
					rfork.acquire();
					lfork.acquire();
				}
				eating();
				rfork.release();
				lfork.release();
				thinking();

			}
		}catch(InterruptedException e)
		{}
	}
	
	void eating()
	{
		System.out.println("[" + id + "] eating");
	}
	
	void thinking()
	{
		System.out.println("[" + id + "] thinking");
	}
}


public class philo3 {

	static final int num = 5;
	public static void main(String[] args) throws InterruptedException {
		int i;
		Semaphore[] fork = new Semaphore[num];
		for (i=0; i<num; i++)
			fork[i] = new Semaphore(1);
		
		Philosopher3[] phil = new Philosopher3[num];
		for (i=0; i<num; i++)
			phil[i] = new Philosopher3(i, fork[i], fork[(i+1)%num]);
		
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
