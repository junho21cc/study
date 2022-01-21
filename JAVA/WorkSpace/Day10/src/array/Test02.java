package array;

public class Test02 {

	public static void main(String[] args) {
		int[] arr = new int[5];
		
		int a = 10;
		for(int i=0;i<arr.length;i++) {
			arr[i] = a;
			a+=10;
		}
		// 문제1) 4의 배수만 출력
		// 정답1) 20 40
		for(int i=0;i<5;i++) {
			if(arr[i] % 4 == 0) {
				System.out.println(arr[i]);
			}
		}
		
		// 문제2) 4의 배수의 합 출력
		// 정답2) 60
		int tot = 0;
		for(int i=0;i<5;i++) {
			if(arr[i] % 4 == 0) {
				tot += arr[i];
			}
		}
		System.out.println(tot);
		
		// 문제3) 4의 배수의 개수 출력
		// 정답3) 2
		int cnt = 0;
		for(int i=0;i<5;i++) {
			if(arr[i] % 4 == 0) {
				cnt++;//1증가
			}
		}
		System.out.println(cnt);

	}

}
