package switchcase;

import java.util.Scanner;

public class Test01 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("1~3 ���� �Է� :");
		int num = sc.nextInt();
		
		switch(num) {
		case 1:
			System.out.println("1�� ����");
			break;
		case 2:
			System.out.println("1,2�� ����");
			break;
		case 3:
			System.out.println("3�� ����");
			break;
		default :
			System.out.println("�߸��� ��ȣ �Է� !");	
		}

	}

}
