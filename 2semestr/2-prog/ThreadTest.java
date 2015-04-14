package my_prog_2;


public class ThreadTest implements  Runnable{
	public double a;
	public double b;
	public double step;
	public double rez;
	IntegrationFunction f;
	
	// инициализация
	ThreadTest(double a, double b, double step,IntegrationFunction f ) {
		this.a = a;
		this.b = b;
		this.step = step;
		this.f = f;
	}
	public void run() {
		f.calc(a,b);
	}
}