package forloop;

public class Test01 {

	public static void main(String[] args) {
		//다중 for문
		for(int i=1;i<=3;i++) {//외부 for문 한번돌때
			System.out.println("========="+i+"번째 외부for문 실행===========");
			for(int j=1;j<=3;j++) {//내부for문은 조건식이 true일때까지 반복
				System.out.println("내부 for문 실행");//외부 : 3 내부 : 3 3*3 = 9
			}
			System.out.println("========="+i+"번째 외부for문 종료===========");
		}

	}

}
