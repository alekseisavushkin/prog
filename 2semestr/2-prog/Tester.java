package my_prog_2;

public class Tester { 
	public static void main(String[] args) {
		int count = 1;
		double answer = 0;
		double a = 0;
		double b = 11;
		double step = 0.0000001;
		Thread t[] = new Thread[count];
		ThreadTest solv [] = new ThreadTest[count];
		for (int i = 0; i < count; i++) {
			solv[i] = new ThreadTest(a + i * (b - a) / count, a + (i + 1)* (b - a) / count, step);
			t[i] = new Thread(new ThreadTest(a + i * (b - a) / count, a + (i + 1) * (b - a) / count, step));
			t[i].start();
		}
		for (int i = 0; i < count; i++) {
			try {
				t[i].join();
			} catch (InterruptedException e) {
				System.out.println("Interrupted!");
			}

			double rez = solv[i].rez;
			answer = answer + rez;
		}

	}


}
