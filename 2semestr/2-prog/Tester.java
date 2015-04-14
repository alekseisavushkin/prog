package my_prog_2;

public class Tester { 
	public static void main(String[] args) {
		int count = 1;
		double answer = 0;
		double a = 0;
		double b = 10;
		double step = 0.0000001;
		Thread t[] = new Thread[count];
		ThreadTest solv [] = new ThreadTest[count];
		CalcFunction f = new CalcFunction();
		for (int i = 0; i < count; i++) {
			solv[i] = new ThreadTest(a + i * (b - a) / count, a + (i + 1)* (b - a) / count, step, f);
			t[i] = new Thread(solv[i]);
			t[i].start();
		}
		for (int i = 0; i < count; i++) {
			try {
				t[i].join();
			} catch (InterruptedException e) {}
		double rez = solv[i].rez;
		answer = answer + rez;
		}
	}
}

