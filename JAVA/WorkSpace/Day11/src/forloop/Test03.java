package forloop;

import java.util.Scanner;

public class Test03 {

	public static void main(String[] args) {
		/*
		 * ���� 1)
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
		 * ���� 2)
		 * ###
		 * ##
		 * #
		 * ���� 3)
		 * @##
		 * @@#
		 * @@@
		 * ���� 4)
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
		//������ �Է¹��� �ٸ�ŭ �ﰢ�� �����
		//ex ) 5
		//*
		//**
		//***
		//****
		//*****
		System.out.print("���� �Է� :");
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
