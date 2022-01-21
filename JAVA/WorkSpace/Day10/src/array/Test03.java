package array;

public class Test03 {

	public static void main(String[] args) {
//		주사위를 10번 던진 결과를 저장하려고 합니다
//		배열을 이용하여 저장을 구현하시고 아래의 결과를 출력하세요
		int[] arr = new int[10];
		//공간=(int)(Math.random() *개수)+시작수
		for(int i=0;i<arr.length;i++) {
			int su = (int)(Math.random() * 6) + 1;
			//arr[i] = (int)(Math.random() * 6) + 1;
			arr[i] = su;
		}
		
//		[1] 전체 주사위 기록을 출력
		for(int i=0;i<arr.length;i++) {
			System.out.println((i+1)+"번째 : "+arr[i]);
		}
		
//		[2] 짝수 주사위 기록을 출력
		for(int i=0;i<arr.length;i++) {
			if(arr[i] % 2 == 0) {
				System.out.println(i+1+"번째 : "+arr[i]);
			}
		}
		
//		[3] 주사위 값들의 합계 출력
		int tot = 0;
		for(int i=0;i<5;i++) {
			tot += arr[i];
		}
		System.out.println(tot);

	}

}
