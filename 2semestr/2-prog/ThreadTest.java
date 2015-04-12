package my_prog_2;


public class ThreadTest implements IntegrationFunction, Runnable{
	public double a;
	public double b;
	public double step;
	public double rez;
	public IntegrationFunction f;
	
	

	// инициализация
	ThreadTest(double a, double b, double step) {
		this.a = a;
		this.b = b;
		this.step = step;
	}
	
	public void calc(double a, double b) {
		double result = 0;
		double konteiner = 0;
		for (double i = a; i < b; i = i + step) {
			result = i*i*step;
			konteiner = konteiner + result;
			rez = konteiner;}	
		System.out.println(konteiner);
	}

	public void run() {
		f.calc(a,b);
	}
	}