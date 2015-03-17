package my_prog;
import java.util.Random;

public class tester { 
	public static void main(String[] args){
		List check_list = new List();
		Random rand = new Random(); 
		for(int i=0;i<100;i++){
			check_list.add(i,rand.nextInt());
		}
		check_list.print();
		
		
	}
	
}
