package forloop;

public class Test02 {

	public static void main(String[] args) {
//		�Ʒ��� ������ for���� �̿��Ͽ� ȭ�鿡 ���
//		
//		[1] 2�ڸ� ����
		for(int i=10;i<100;i++) {
			System.out.println(i);
		}
		
//		[2] 1���� 100������ Ȧ��
		for(int i=1;i<=100;i++) {
			if(i % 2 == 1) {
				System.out.println(i);
			}
		}
		
//		[3] �빮�� ���ĺ�
		for(int i=65;i<=90;i++) {
			System.out.println((char)i);
		}
		for(char ch='A';ch<='Z';ch++) {
			System.out.println(ch);
		}
//		[4] 1000���� ���� 3�� ���
		for(int i=1;i<1000;i++) {
			if(i % 3 == 0) {
				System.out.println(i);
			}
		}
		
//		[5] 1000���� ���� 2�� ������	(1, 2, 4, 8, 16, 32, ..., 256, 512)
		for(int i=1;i<1000;i*=2) {//i = i*2
			System.out.println(i);
		}

	}

}
