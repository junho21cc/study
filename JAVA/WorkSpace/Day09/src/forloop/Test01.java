package forloop;

public class Test01 {

	public static void main(String[] args) {
		//�ݺ� 1~1000
		//����1) 9�� ����� ���� �ڸ��� 6�� ù��° ��� ��� ==> �� : 36
		for(int i=1;i<=1000;i++) {
			if(i % 9 == 0 && i % 10 == 6) {
				System.out.println(i);
				break;
			}
		}
		
		//����2) 9�� ����� ���� �ڸ��� 6�� ù��° ��� ��� ==> �� : 63
		for(int i=1;i<=1000;i++) {
			if(i % 9 == 0 && i / 10 == 6) {
				System.out.println(i);
				break;
			}
		}
		int num = 0;
		//����3) 8�� �����  150���� �۰� 150 �� ���� �������� ��� ==> �� : 144
		for(int i=1;i<=1000;i++) {
			if(i % 8 == 0 && i < 150) {
				num = i;
				//System.out.println(num);
			}
		}
		System.out.println(num);
		

	}

}
