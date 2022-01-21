package forloop;

import java.util.Scanner;

public class Test03 {

	public static void main(String[] args) {
		/*
		 * 문제 1)
		 * #
		 * ##
		 * ###
		 */
		for(int i=1;i<=3;i++) {
			for(int j=0;j<i;j++) {
				System.out.print("#");
			}
			System.out.println();
		}
		/*
		 * 문제 2)
		 * ###
		 * ##
		 * #
		 * 문제 3)
		 * @##
		 * @@#
		 * @@@
		 * 문제 4)
		 *   #
		 *  ###
		 * #####
		 */
		for(int i=0;i<3;i++) {
			for(int j=2;j>=i;j--) {
				System.out.print("#");
			}
			System.out.println();
		}
		for(int i=0;i<3;i++) {
			for(int j=0;j<=i;j++) {
				System.out.print("@");
			}
			for(int j=2;j>i;j--) {
				System.out.print("#");
			}
			System.out.println();
		}
		int n = 1;
		for(int i=0;i<3;i++) {
			for(int j=2;j>i;j--) {
				System.out.print(" ");
			}
			for(int j=0;j<n;j++) {
				System.out.print("#");
			}
			n += 2;
			System.out.println();
		}
		Scanner sc = new Scanner(System.in);
		//정수를 입력받은 줄만큼 삼각형 만들기
		//ex ) 5
		//*
		//**
		//***
		//****
		//*****
		System.out.print("정수 입력 :");
		int su = sc.nextInt();
		for(int i=0;i<su;i++) {
			for(int j=0;j<=i;j++) {
				System.out.print("*");
			}
			System.out.println();
		}
		
		//    *
		//   ***
		//  *****
		// *******
		//*********

	}

}
