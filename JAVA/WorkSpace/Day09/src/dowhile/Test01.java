package dowhile;

import java.util.Scanner;

public class Test01 {

	public static void main(String[] args) {
		//do ~ while
		// - ������ �ѹ��� ������ �ؾ��ϸ� �߸��� �����͸� �ɷ����� ����Ѵ�.
		// - ���Ļ� ���ӹ����� ���� ������ �ϰ� ���ǽ��� ���ϴ� �����̴�.
		// - �ݺ����ȿ��� ������� ����� ���ǽĿ��� ���ϱ⿡ ����.
		// - while�̶� �����ϱ� ���ؼ� ���� ���� ;�� �����ش�.
		
		//����
		//do{
		//		���ӹ���;
		//}while(���ǽ�);
		Scanner sc = new Scanner(System.in);
		//10 ~ 20������ ���ڸ� �Է¹����� �ݺ� ����
		int su;
		do {
			System.out.print("10 ~ 20 ���� ���� �Է� :");
			su = sc.nextInt();
		}while(su < 10 || su > 20);
		System.out.println(su);
	}

}
