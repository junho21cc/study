package whileloop;

public class Test02 {

	public static void main(String[] args) {
		
		//����1) 1 ~ 10���� ���
		int i = 1;
		while(true) {
			System.out.println("i = "+i);
			if(i==10) {
				break;
			}
			i++;
		}
		i = 1;
		while(i<=10) {
			System.out.println("i = "+i);
			i++;
		}
		
		//����2) 1 ~ 10���� �ݺ��� 5~9 ���
		// ����2) 5, 6, 7, 8, 9
		i = 1;
		while(true) {
			if(i>=5 && i<=9) {
				System.out.print(i+" ");
			}
			if(i==10) {
				break;//break;�� �� ���Ŀ� �ڵ尡 ����������.
			}
			i++;
		}
		System.out.println();
		i = 1;
		while(i<=10) {
			if(i >= 5 && i<=9) {
				System.out.print(i+" ");
			}
			i++;
		}
		System.out.println();
		//����3) 10~1���� �ݺ��� 6~3 �Ųٷ� ���
		// ����3) 6, 5, 4, 3
		i = 10;
		while(true) {
			if(i >= 3 && i<= 6) {
				System.out.print(i+" ");
			}
			if(i == 1) {
				break;
			}
			i--;
		}
		System.out.println();
		i = 10;
		while(i>=1) {
			if(i>=3 && i<=6) {
				System.out.print(i+" ");
			}
			i--;
		}
		System.out.println();
		//����4) 1~10���� �ݺ��� ¦���� ���
		// ����4) 2, 4, 6, 8, 10
		i = 1;
		while(true) {
			if(i % 2 == 0) {
				System.out.print(i+" ");
			}
			if(i == 10) {
				break;
			}
			i++;
		}
		System.out.println();
		i = 1;
		while(i<=10) {
			if(i % 2 == 0) {
				System.out.print(i+" ");
			}
			i++;
		}

	}

}
