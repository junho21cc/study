package array;

public class Test01 {

	public static void main(String[] args) {
		//참조형변수와 일반변수의 구별법
		//일반변수는 null 초기화가 되지않는다.
		
		//일반변수
//		int a = 0;
//		a = null;
		
		//배열 참조형 변수 선언
		int[] arr = null;//참조형변수
		
		//인스턴스 선언 - new
		arr = new int[3];
		
		System.out.println(arr.length);//배열의 개수를 구해준다.
		
		arr[0] = 1;
		arr[1] = 2;
		arr[2] = 3;
		//arr[3] = 4;
		//System.out.println(arr[3]); - index가 벗어났기때문에 error
		for(int i=0;i<arr.length;i++) {
			System.out.println("arr["+i+"] = "+arr[i]);
		}
		
	}

}
