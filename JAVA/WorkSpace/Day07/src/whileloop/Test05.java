package whileloop;

import java.util.Scanner;

public class Test05 {

	public static void main(String[] args) {
//		���ٿ� ������ �����Ϸ� �մϴ�.
		//		��ǻ�Ϳ��� 1���� 100 ������ ������ �����ϵ��� �ڵ带 ������ ��
		//		����ڰ� ���ڸ� �Է��Ͽ� ������ ���ߵ��� ���α׷����ϼ���
		//
		//		<������ ����>
		//		[   ��  ] ����ڰ� ���亸�� ���� ���� �Է��� ���
		//		[ �ٿ� ] ����ڰ� ���亸�� ���� ���� �Է��� ���
		//		[ ���� ] ����ڰ� ����� ���� ���� �Է��� ���, ���� ����
		//
		//		���� ����� �� �Է��� Ƚ���� ȭ�鿡 ���
		Scanner sc = new Scanner(System.in);
		int com = (int)(Math.random() * 100)+1;
		int cnt = 0;
		int user = 0;
		while(com != user) {//true
			System.out.print("���� �Է� :");
			user = sc.nextInt();
			cnt++;//1����
			
			if(user < com) {
				System.out.println("[ �� ]");
			}
			else if(user > com) {
				System.out.println("[ �ٿ� ]");
			}
			else if(com == user) {
				System.out.println("[ ���� ]");
				System.out.println("�� �Է� Ƚ�� : "+cnt);
				//break;
			}
		}
	}

}
