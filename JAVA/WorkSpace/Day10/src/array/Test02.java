package array;

public class Test02 {

	public static void main(String[] args) {
		int[] arr = new int[5];
		
		int a = 10;
		for(int i=0;i<arr.length;i++) {
			arr[i] = a;
			a+=10;
		}
		// ����1) 4�� ����� ���
		// ����1) 20 40
		for(int i=0;i<5;i++) {
			if(arr[i] % 4 == 0) {
				System.out.println(arr[i]);
			}
		}
		
		// ����2) 4�� ����� �� ���
		// ����2) 60
		int tot = 0;
		for(int i=0;i<5;i++) {
			if(arr[i] % 4 == 0) {
				tot += arr[i];
			}
		}
		System.out.println(tot);
		
		// ����3) 4�� ����� ���� ���
		// ����3) 2
		int cnt = 0;
		for(int i=0;i<5;i++) {
			if(arr[i] % 4 == 0) {
				cnt++;//1����
			}
		}
		System.out.println(cnt);

	}

}
