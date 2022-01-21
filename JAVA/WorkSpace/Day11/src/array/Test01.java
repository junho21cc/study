package array;

public class Test01 {

	public static void main(String[] args) {
		
		//다차원 배열
		// - 배열이 중첩적인 차원을 가지는 배열
		// - 여러개의 배열 공간의 정보를 저장할 수 있는 배열
		
		//2차원배열
		// - 1차원배열의 배열
		
		int[][] arr = null;
		
		// - 인스턴스공간
		// new 자료형[개수][개수];
		// new 자료형[][]{ { 데이터,데이터..}, {데이터,데이터..}, {데이터,데이터..}};
		
		arr = new int[3][3];
		//배열명[세로인덱스][가로인덱스]
		arr[0][1] = 2;
		System.out.println(arr[0][1]);
		arr[1][1] = 5;
		System.out.println(arr[1][1]);
		
		for(int i=0;i<3;i++) {
			for(int j=0;j<3;j++) {
				System.out.print(arr[i][j]+"\t");
			}
			System.out.println();
		}
		
		arr = new int[][] {
			{1,2},
			{3,4,5,6},
			{7,8,9}
		};
		System.out.println(arr[1][2]);
		//System.out.println(arr[0][2]); - 공간이 없으므로 error
		System.out.println(arr[2][2]);
		//arr[0] = new int[2];
		//arr[1] = new int[4];
		//arr[2] = new int[3];
		//System.out.println(arr[0][0]);
		
		for(int i=0;i<arr.length;i++) {//i = 0 // i = 1 // i =2
			//j = 0 , 1 
			//j = 0 , 1 , 2 ,3
			//j = 0 , 1 , 2
			for(int j=0;j<arr[i].length;j++) {
				System.out.print(arr[i][j]+"\t");
				//arr[0][0] arr[0][1]
				//arr[1][0] arr[1][1] arr[1][2] arr[1][3]
				//arr[2][0] arr[2][1] arr[2][2]
			}
			System.out.println();
		}

	}

}
