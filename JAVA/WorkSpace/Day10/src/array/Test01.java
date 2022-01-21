package array;

public class Test01 {

	public static void main(String[] args) {
		int[] arr = new int[5];
		//문제1 ) 10부터 50까지 배열에 저장
		//정답1 ) 10 20 30 40 50
//		arr[0] = 10;
//		arr[1] = 20;
//		arr[2] = 30;
//		arr[3] = 40;
//		arr[4] = 50;
		int a = 10;
		//int[] arr = new int[]{10,20,30,40,50};
		for(int i=0;i<arr.length;i++) {
			arr[i] = a;
			System.out.println(arr[i]);
			a+=10;
		}
		
		//문제2 ) 전체 합 출력
		//정답2 ) 150
		int sum = 0;
		//sum = arr[0] + arr[1]+ arr[2]+arr[3]+arr[4];
		for(int i=0;i<arr.length;i++) {
			sum += arr[i];//sum = sum + arr[i]
		}
		System.out.println(sum);
	}

}
