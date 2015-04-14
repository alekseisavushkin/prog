package my_prog_2;

public class CalcFunction implements IntegrationFunction {
	public double a;
	public double b;
	public double step;
	public double rez;
	
	public double calc(double a, double b) {
		double result;
		double konteiner = 0;
		double step = 0.0000001;
		for (double i = a; i < b; i = i + step) {
			result = i*i*step;
			konteiner = konteiner + result;
			rez = konteiner;}	
		System.out.print("My result is ");
		System.out.println(konteiner);
		return rez;}
}


