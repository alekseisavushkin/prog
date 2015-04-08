package my_prog_2;


public class ThreadTest implements Runnable {
	public double a;
	public double b;
	public double step;
	public double rez;
	double IntegrationFunction;

	// инициализация
	ThreadTest(double a, double b, double step, double IntegrationFunction) {
		this.a = a;
		this.b = b;
		this.step = step;
		this.IntegrationFunction = IntegrationFunction;
	}
	

	public void run() {
		double result = 0;
		double konteiner = 0;
		for (double i = a; i < b; i = i + step) {
			IntegrationFunction = i*i;
			result =  IntegrationFunction * step;
			konteiner = konteiner + result;
			rez = konteiner;
		}
		System.out.println(konteiner);
	}
}