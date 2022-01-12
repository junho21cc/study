package whileloop;

public class Test01 {

	public static void main(String[] args) {
		int i=1;//초기식
		while(true) {//무한반복
			System.out.println("i = "+i);
			if(i == 7) {
				break;//반복문 즉시종료
			}
			i++;//i를 1씩증가
		}
		
		i = 1;//초기식
		while(i <= 7) {//조건식
			System.out.println("i = "+i);
			i++;//증감식
		}

	}

}
