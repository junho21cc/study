package whileloop;

public class Test04 {

	public static void main(String[] args) {
		//�������� - Java�� ���������� �������� �ʴ´�.
		
		//��������
		// - ��� �� �������� �켱������ ���Ǵ� ����
		// - �� ������ �����Ҷ� ������ �����ǰ� �� ������ ������ ������ �Ҹ�ȴ�.
		
		//		if(true) {
		//		int a = 10;
		//		System.out.println(a);
		//	}
		//	System.out.println(a);
		
		//1 ~ 10������ ������ ���� ���ؼ� �������Ѵ�.
		//���� 100�� ������������ �ݺ�Ƚ���� ���ϼ���.
		int sum = 0;
		int cnt = 0;
		
		while(true) {
			int su = (int)(Math.random() * 10)+1;
			
			sum += su;
			cnt++;
			if(sum > 100) {
				break;
			}
		}
		System.out.println(sum);
		System.out.println(cnt);
		sum = 0;
		cnt = 0;
		while(sum <= 100) {
			int su = (int)(Math.random() * 10)+1;
			sum += su;
			cnt ++;
		}
		System.out.println(sum);
		System.out.println(cnt);
		
	}

}
