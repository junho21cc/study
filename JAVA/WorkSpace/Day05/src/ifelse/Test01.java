package ifelse;

import java.util.Scanner;

public class Test01 {

	public static void main(String[] args) {
		/*
		 * # 369����[1�ܰ�]
		 * 1. �����Է�
		 * 2. �� ���� 369�� ������
		 * 	1) 2���̸�, ¦¦�� ���
		 *  2) 1���̸�, ¦�� ���
		 *  3) 0���̸�, �ش� ���ڸ� ���
		 * ��)
		 * 		33	 : ¦¦
		 * 		16	 : ¦
		 * 		 7	 : 7
		 */
		int count = 0;
		Scanner sc = new Scanner(System.in);
		System.out.print("���� �Է� :");
		int num = sc.nextInt();
		int ten = num / 10;
		int one = num % 10;
		
		if(ten % 3 == 0 && ten != 0) {
			count++;//count = count +1; count+=1;
		}
		if(one == 3 || one == 6 || one == 9) {
			count++;
		}
		
		if(count == 2) {
			System.out.println("¦¦");
		}
		else if(count==1) {
			System.out.println("¦");
		}
		else {
			System.out.println(num);
		}

	}

}
