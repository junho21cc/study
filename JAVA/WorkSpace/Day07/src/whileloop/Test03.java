package whileloop;

public class Test03 {

	public static void main(String[] args) {
		// ����1) 1~5������ �� ���
		// ���� 1) 15
		int tot = 0;
		int i = 1;
		while(true) {
			tot = tot + i;//tot += i;
			if(i == 5) {
				break;
			}
			i++;
		}
		System.out.println(tot);
		i = 1;
		tot = 0;
		while(i <= 5) {
			tot += i;
			i++;
		}
		System.out.println(tot);
		// ����2) 1~10���� �ݺ��� 3�̸� 7�̻� ���
		// ����2) 1, 2, 7, 8, 9, 10
		i = 1;
		while(true) {
			if(i < 3 || i>=7) {
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
			if(i < 3 || i >= 7) {
				System.out.print(i+ " ");
			}
			i++;
		}
		// ����3) ����2�� ���ǿ� �´� ������ �� ���
		// ����3) 37
		System.out.println();
		tot = 0;
		i = 1;
		while(true) {
			if(i < 3 || i>=7) {
				tot += i;// 1+ 2+ 7+ 8+ 9+ 10
			}
			if(i == 10) {
				break;
			}
			i++;
		}
		System.out.println(tot);
		i = 1;
		tot = 0;
		while(i<=10) {
			if(i<3 || i>=7) {
				tot += i;
			}
			i++;
		}
		System.out.println(tot);
		
		// ����4) ����2�� ���ǿ� �´� ������ ���� ���
		// ����4) 6
		int cnt = 0;
		i = 1;
		while(true) {
			if(i < 3 || i>=7) {
				cnt++;//1���� cnt+=1; cnt =  cnt + 1;
			}
			if(i == 10) {
				break;
			}
			i++;
		}
		System.out.println(cnt);
		i = 1;
		cnt = 0;
		while(i<=10) {
			if(i < 3 || i>=7) {
				cnt++;//1���� cnt+=1; cnt =  cnt + 1;
			}
			i++;
		}
		System.out.println(cnt);
	}

}
