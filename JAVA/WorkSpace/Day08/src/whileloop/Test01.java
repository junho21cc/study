package whileloop;

public class Test01 {

	public static void main(String[] args) {
		/*
		 * # 369����[2�ܰ�]
		 * 1. 1~50���� �ݺ��� �Ѵ�.
		 * 2. �� �ȿ��� �ش� ������ 369������ ����� ����Ѵ�.
		 * ��) 1 2 ¦ 4 5 ¦ 7 8 ¦ 10 11 12 ¦ ...
		 */
		int i = 1;
		while(i<=50) {
			int ten = i / 10;
			int one = i % 10;
			int cnt = 0;
			
			if(ten % 3 == 0 && ten != 0) {
				cnt++;
			}
			if(one == 3 || one == 6 || one == 9) {
				cnt++;
			}
			
			if(cnt == 2) {
				System.out.println("¦¦");
			}
			else if(cnt == 1) {
				System.out.println("¦");
			}
			else {
				System.out.println(i);
			}
			
			i++;
		}

	}

}
