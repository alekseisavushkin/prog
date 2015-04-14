package my_prog_2;

public class ThreadTest implements Runnable {
	private double rez;
	private double a;
	private double b;
	private IntegrationFunction f;
	public static final double STEP = 10e-5;

	public ThreadTest(double a, double b, IntegrationFunction f) {
		this.a = a;
		this.b = b;
		this.f = f;
	}

	public void run() {
		double result;
		double i;
		double konteiner = 0;
		for (i = a; i < b; i = i + STEP) {
			result = f.calc(i) * STEP;
			konteiner = konteiner + result;
			rez = konteiner;
		}
	}

	public double getRez() {
		return rez;
	}
}