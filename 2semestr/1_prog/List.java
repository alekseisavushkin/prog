package my_prog;

//header - псевдо-элемент списка(тип ListNode), его значение(element = null) всегда 
//prev у header указывает на первый элемент списка, next - на последний
//в самом начале header указывает сам на себя, size = 0;
public class List {
	ListNode header;
	ListNode tail;
	static int size;

	// конструктор - это же тот же метод? который вызывается при создании нового
	// объекта
	// если у класса есть конструктор, тогда при создании объекта он
	// инициалзируется автоматически
	// конструктор

	// пишем конструктор для класса (это тот же метод(инициализация объекта).
	// При создании нового объекта он инициализируется автоматически.
	public List() {
		header = null;
		tail = null;
		size = 0;
	}

	public void add(int index, int data) {
		ListNode temp = new ListNode();
		temp.next = null;
		temp.element = data; 
		if(header!=null) //если список не пуст 
		{
			temp.prev=tail; 
			tail.next=temp; 
			tail=temp;
			
		} 
		else//если пуст 
		{
			temp.prev=null; 
			header=tail=temp;
			
		}
		size++;

	} 
	public void delete(int index){ 
		//удаляем первый, но в списке есть еще элементы
		if(index==1){ 
			if(header.next != null){ 
				
				header=header.next;//сдвигаем указатель на следующий за первым
				header.prev=null; 
				size--;
				
			} 
			if(header.next == null){
				header.next=null; 
				header=null; 
				size--;
				
			}
		}
		
			
		//удаляем последний элемент списка 
		if(index==size){
			tail=tail.prev;//отодвигаем хвост назад 
			tail.next=null; 
			size--;
			
			
		}
		//если удаляемый элемент в середине списка 
		//temp - удаляемый, temp2-чтобы не потерять данные 
		if(index>0){
			if(index<size){
		ListNode temp = header; 
		ListNode temp2 = header;  
		for(int i = 0;i<index-1;i++){
			temp=temp.next;}
			temp2 = temp;//записываем адрес удаляемого элемента
			temp2.prev.next=temp.next; 
			temp2.next.prev=temp.prev;
		
		size--;
		}
		}
		
		}
		
	
	public void print() {
		if (header == null)
			System.out.println("sorry, there are no elements");
		else {
			ListNode el = new ListNode();
			el = header;
			while (el != null) {
				System.out.print(el.element + " ");
				el = el.next;
			}
		}
	}

	public static void main(String[] args) {
		List newList = new List();
		newList.add(1, 1);
		newList.add(2, 2); 
		newList.add(3, 3);
		newList.add(4, 4);
		newList.add(5, 5); 
		newList.add(6, 6);
		newList.add(7, 7);
		newList.delete(7);
		newList.delete(3);
		newList.print();
		
	}
}
