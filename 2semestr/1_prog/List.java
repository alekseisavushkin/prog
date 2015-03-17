package my_prog;

//header - ������-������� ������(��� ListNode), ��� ��������(element = null) ������ 
//prev � header ��������� �� ������ ������� ������, next - �� ���������
//� ����� ������ header ��������� ��� �� ����, size = 0;
public class List {
	ListNode header;
	ListNode tail;
	static int size;

	// ����������� - ��� �� ��� �� �����? ������� ���������� ��� �������� ������
	// �������
	// ���� � ������ ���� �����������, ����� ��� �������� ������� ��
	// ��������������� �������������
	// �����������

	// ����� ����������� ��� ������ (��� ��� �� �����(������������� �������).
	// ��� �������� ������ ������� �� ���������������� �������������.
	public List() {
		header = null;
		tail = null;
		size = 0;
	}

	public void add(int index, int data) {
		ListNode temp = new ListNode();
		temp.next = null;
		temp.element = data; 
		if(header!=null) //���� ������ �� ���� 
		{
			temp.prev=tail; 
			tail.next=temp; 
			tail=temp;
			
		} 
		else//���� ���� 
		{
			temp.prev=null; 
			header=tail=temp;
			
		}
		size++;

	} 
	public void delete(int index){ 
		//������� ������, �� � ������ ���� ��� ��������
		if(index==1){ 
			if(header.next != null){ 
				
				header=header.next;//�������� ��������� �� ��������� �� ������
				header.prev=null; 
				size--;
				
			} 
			if(header.next == null){
				header.next=null; 
				header=null; 
				size--;
				
			}
		}
		
			
		//������� ��������� ������� ������ 
		if(index==size){
			tail=tail.prev;//���������� ����� ����� 
			tail.next=null; 
			size--;
			
			
		}
		//���� ��������� ������� � �������� ������ 
		//temp - ���������, temp2-����� �� �������� ������ 
		if(index>0){
			if(index<size){
		ListNode temp = header; 
		ListNode temp2 = header;  
		for(int i = 0;i<index-1;i++){
			temp=temp.next;}
			temp2 = temp;//���������� ����� ���������� ��������
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
